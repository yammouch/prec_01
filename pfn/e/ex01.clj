(defn perm [ns]
  (loop [l 0, p 1, [n :as ns] ns]
    ; l �����ڂ܂ŕ��ׂ��B
    (cond (empty? ns) (mod p 1000000007)

          (< (+ l 1) n) 0

          :else
          ; l �����̊Ԃ܂��͒[�� n ������z�u����B
          (recur (+ l n)
                 (apply / (apply * p (take n (iterate dec (+ l 1))))
                          (range 1 (+ n 1)))
                 (rest ns)))))

(let [s (read-line)
      g (group-by identity s)
      ns-char (map (fn [[_ x]] (count x)) g)]
  (println (perm (sort ns-char))))
  
