(defn padding-minus-a [a yofs xofs]
  (as-> a a
        (if (< xofs 0)
          (map #(concat (repeat (- xofs) ".") %) a)
          a)
        (if (< yofs 0)
          (concat (reduce #(repeat %2 %1) "."
                          [(count (first a)) (- yofs)])
                  a))))

(defn padding-minus-b [b yofs xofs]
  (as-> b b
        (if (> xofs 0)
          (map #(concat (repeat xofs ".") %) b)
          b)
        (if (> yofs 0)
          (concat (reduce #(repeat %2 %1) "."
                          [(count (first a)) yofs])
                  b))))

(defn padding-plus [a b]
  (let [[cxa cxb] (map (comp count first) [a b])
        cxd (Math/abs (- cxa cxb))
        [cya cyb] (map count [a b])
        cyd (Math/abs (- cya cyb))
        [a b] (if (< cxa cxb)
                [(map #(concat (repeat "." cxd) %) a) b]
                [a (map #(concat (repeat "." cxd) %) b)])
    (if (< cya cyb)
      [(concat a (reduce #(repeat %2 %1) "." [(count (first a)) cyd]) b]
      [a (concat b (reduce #(repeat %2 %1) "." [(count (first b)) cyd])]
      )))
 
; パーツ b を [yofs xofs] だけずらしてパーツ a に重ねる。
(defn add-parts [a b yofs xofs]
  (let [a (padding-minus-a a yofs xofs) ; a を - 座標方向に拡張
        b (padding-minus-b b yofs xofs) ; b を - 座標方向に拡張
        [a b] (padding-plus a b) ; a, b を + 座標方向に拡張し、大きさを揃える
        ]
    ; a, b どちらとも "#" のセルがあったら nil を返し、終了。
    ; パーツを重ねられるなら、重ねたあとの "#", "." の行列を返す。
    ))

; メインルーチン
; - 文字列を読む
; - パーツ A, B, C から空の行、列を削除
; - B の位置、向きを変えながら、A に重ねる。 --- (1)
; - (1) で得られたそれぞれに対し、C の向き、位置を重ねる。 --- (2)
; - (1), (2) のループの中で、最小の面積を保持しておく。最後にそれを出力。
