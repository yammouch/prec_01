(defn remove-common [s1 s2]
  (loop [s1 s1, s2 s2]
    (cond (empty? s1) [s1 s2]
          (empty? s2) [s1 s2]
          (= (first s1) (first s2)) (recur (rest s1) (rest s2))
          :else [s1 s2])))

(let [s (read-line)
      t (read-line)
      [s t] (remove-common s t)
      [s t] (remove-common (reverse s) (reverse t))
      [sn tn] (map count [s t])]
  (println (case [sn tn]
             [1 0] "YES"
             [0 1] "YES"
             [1 1] "YES"
             [0 0] "YES"
             "NO")))
  
