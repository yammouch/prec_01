(let [l (read-line)]
  (doseq [n (range 1 (+ (count l) 1))]
    (println (apply str (take n l)))
    ))
