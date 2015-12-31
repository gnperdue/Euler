(ns problem001.core
  (:gen-class))

(defn divisible-by-3-or-5?
  [n]
  (or (= 0 (rem n 3)) (= 0 (rem n 5))))

(def vec-of-nums (take 1000 (iterate inc 0)))   ; 0 - 999

(def euler
  (reduce + (filter divisible-by-3-or-5? vec-of-nums)))

(def list-of-bools (map divisible-by-3-or-5? vec-of-nums))

(defn -main
  "project euler problem 1: https://projecteuler.net/problem=1"
  [& args]
  (println (str "The sum of all the multiples of 3 and 5 below 1000 is "
                euler)))
