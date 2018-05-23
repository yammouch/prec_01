(defn add-nodup [v x]
  (let [v (remove (partial = x) v)]
    (cons x v)))

(let [q (read-string (read-line))]
  (loop [i 0 v []]
    (if (< i q)
      (let [v (as-> (read-line) y
                    (read-string y)
                    (add-nodup v y)
                    (take 5 y))]
        (println (apply str (interpose " " v)))
        (recur (+ 1 i) v)
        ))))
