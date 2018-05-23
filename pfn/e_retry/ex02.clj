(defn consume [n v]
  (as-> (update-in v [n] - 1) v
        (if (= (peek v) 0)
          (pop v)
          v)
        (if (< 0 n)
          (update-in v [(- n 1)] + 1)
          v)))

(defn perm [exc v]
  ;(println [exc v])
  (if (empty? v)
    (if (= exc 0) 1 0)
    (apply + (map-indexed
              (fn [i x]
                (if (= x 0)
                  0
                  (mod (* (- x (if (= exc (+ i 1)) 1 0))
                          (perm i (consume i v)))
                       1000000007)))
              v))))

;(defn perm [exc v]
;  (+ (if (= (v 0) 0)
;       0
;       (mod (* (- (v 0) (if (= exc 1) 1 0))
;               (perm 0 (consume 0 v)))
;            1000000007)0
;     (if (= (v 1) 0)
;       0
;       (mod (* (- (v 1) (if (= exc 2) 1 0))
;               (perm 1 (consume 1 v)))
;            1000000007))
;     (if (= (v 2) 0)
;       0
;       (mod (* (- (v 2) (if (= exc 3) 1 0))
;               (perm 2 (consume 2 v)))
;            1000000007))
;     (if ...
