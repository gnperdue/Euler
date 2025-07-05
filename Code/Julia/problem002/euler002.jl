# problem 2 - https://projecteuler.net/problem=2
#= pseudo code - "vibe code input", pair programming with an LLM since
I don't know Julia...

We want to sum a large number of even-valued terms from the Fibonacci
sequence. One strategy for solving this problem might be:
1. Write a generator that produces terms in the Fibonacci sequence. It
   probably needs a starting point. So, for example `fib(1,2)` should
   return a generator that produces 1,2,3,5,8,13,21,34,etc.
2. We need a filter function that keeps only even values - ideally it
   consumes a generator and returns a generator.
3. Finally, we sum the second generator acting on the first.
=#

# Define a Fibonacci iterator type
struct Fibonacci
    a::Int
    b::Int
    limit::Int
end

Base.IteratorSize(::Type{Fibonacci}) = Base.SizeUnknown()

#=
# Define how to iterate over Fibonacci
Base.iterate(f::Fibonacci) = begin
    println("iterate: a = ", f.a)
    (f.a, (f.b, f.a + f.b, f.limit))
end

Base.iterate(f::Fibonacci, _) = begin
    println("iterate (cont): a = ", f.a)
    a < limit ? (a, (b, a + b, limit)) : nothing
end
=#

Base.iterate(f::Fibonacci) = (f.a, (f.b, f.a + f.b, f.limit))
Base.iterate(::Fibonacci, (a, b, limit)) =
    a < limit ? (a, (b, a + b, limit)) : nothing


function main()
    cut_off = 4_000_000

    # Instantiate the generator starting at 1, 2
    fib = Fibonacci(1, 2, cut_off)
    # compute the sum
    result = sum(x for x in fib if x % 2 == 0)

    println(result)
end

main()