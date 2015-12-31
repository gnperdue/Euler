(ns problem002.core
  (:gen-class))

(defn fibo*
  "lazy seq of fibonnaci numbers - missing the initial 1 1"
  ([] (fibo* 1 1))
  ([a b]
   (let [sum (+ a b)]
     (cons sum (lazy-seq (fibo* b sum))))))

(def fibos (fibo*))
(def filter-max 4000000)

(defn -main
  "project euler problem 2: https://projecteuler.net/problem=2"
  [& args]
  (let [answer (reduce + 0
                       (filter #(= (mod % 2) 0)
                               (take-while #(< % filter-max) fibos)))]
    (println (str "The sum of the even fibonnaci numbers less than "
                  filter-max " is " answer "."))))
