; echo aaabbccd | java clojure.main -i [this .clj file]

; Decrement nth element, increment (n-1)th element of a given vector.
; If the last element is 0, the 0 is thrown away.
(defn consume [n v]
  (as-> (update-in v [n] - 1) v
        (if (= (peek v) 0)
          (pop v)
          v)
        (if (< 0 n)
          (update-in v [(- n 1)] + 1)
          v)))

; perm: 同じ文字が隣合わない順列を求める。
; 第1引数:
;  exclude の略。最初の文字の候補からexc回出現するものの内1つを除外する場合を指定。
;  0を指定すると、最初の文字に制約を与えない。
; 第2引数:
;  第n要素はn回出現する文字の数を表す。
;  [n1 n2 n3] は、1回出現する文字が n1 個、2回出現する文字が n2 個、
;  3回出現する文字が n3 個であることを意味する。
;  例えば、文字列"aaaabbccd"に対してこの引数は[1 2 0 1]となる。

; アルゴリズム: 以下、(perm n [n1 n2 n3]) を p(n, [n1, n2, n3]) と表す。
;  (A) p(0, [n1, n2, n3]) を考える。
;   1文字目の選び方は、
;   (1) 3回出現する文字を選ぶ。n3 = 0 の時は 0 通り。
;   (2) 2回出現する文字を選ぶ。n2 = 0 の時は 0 通り。
;   (3) 1回出現する文字を選ぶ。n1 = 0 の時は 0 通り。
;   の3通り。
;   (1):
;    1文字目の選び方は n3 通り。
;    2文字目以降の並べ方は、1文字目に使っていないものを最初に選ぶ。
;    すなわち、最初の文字の候補から残った文字の中で
;    2回出現するものの1つを除外するので、
;    p(2, [n1, n2+1, n3-1]) 通り。
;    結局、n3*p(2, [n1, n2+1, n3-1]) が(1)の場合の数。
;   (2) は同様に n2*p(1, [n1+1, n2-1, n3])、
;   (3) は n1*p(0, [n1-1, n2, n3])
;   となる。従って、
;     p(0, [n1, n2, n3])
;   = n3*p(2, [n1  , n2+1, n3-1])
;   + n2*p(1, [n1+1, n2-1, n3  ])
;   + n1*p(0, [n1-1, n2  , n3  ])
;   が成り立つ。
;  (B) 次に、第1引数が0で無い場合の例としてp(1, [n1, n2, n3])を考える。
;   1文字目の候補から1回のみ出現する文字の1つを除外する。
;    2, 3回出現する文字に関しては、(A-1)(A-2)と同様なので、
;     p(1, [n1, n2, n3])
;   =  n3   *p(2, [n1  , n2+1, n3-1])
;   +  n2   *p(1, [n1+1, n2-1, n3  ])
;   + (n1-1)*p(0, [n1-1, n2  , n3  ])
;   となる。同様に、
;     p(2, [n1, n2, n3])
;   =  n3   *p(2, [n1  , n2+1, n3-1])
;   + (n2-1)*p(1, [n1+1, n2-1, n3  ])
;   +  n1   *p(0, [n1-1, n2  , n3  ])
;     p(3, [n1, n2, n3])
;   = (n3-1)*p(2, [n1  , n2+1, n3-1])
;   +  n2   *p(1, [n1+1, n2-1, n3  ])
;   +  n1   *p(0, [n1-1, n2  , n3  ])
;   となる。
;  (C) 基本ケースとして、p(0, [0, 0, 0]) = 1 である。

; 以下、ループを組む前のスケッチ。

;(defn perm [exc v]
;  (+ (if (= (v 0) 0)
;       0
;       (* (- (v 0) (if (= exc 1) 1 0))
;          (perm 0 (consume 0 v))))
;     (if (= (v 1) 0)
;       0
;       (* (- (v 1) (if (= exc 2) 1 0))
;          (perm 1 (consume 1 v))))
;     (if (= (v 2) 0)
;       0
;       (* (- (v 2) (if (= exc 3) 1 0))
;          (perm 2 (consume 2 v))))
;     (if ...

(def perm-memo)

(defn perm [exc v]
  (if (empty? v)
    (if (= exc 0) 1 0)
    (mod (apply + (map-indexed
                   (fn [i x]
                     (if (= x 0)
                       0
                       (* (- x (if (= exc (+ i 1)) 1 0))
                          (perm-memo i (consume i v)))))
                   v))
         1000000007)))

; 探索ツリーが大きいので、メモ化。
(def perm-memo (memoize perm))

(println
 (perm-memo 0
  (as-> (read-line) x
        (group-by identity x)
        (map (comp count second) x)
        (let [nmax (apply max x)
              v (vec (repeat nmax 0))]
          (reduce (fn [v n] (update-in v [(- n 1)] + 1))
                  v x)))))
