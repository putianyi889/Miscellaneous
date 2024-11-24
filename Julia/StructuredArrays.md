# A List of Structured Arrays in Julia

## Circular Array
Arrays that wrap over edges.
```julia
julia> using CircularArrays

julia> A = CircularArray(rand(2,3))
2×3 CircularArray(::Matrix{Float64}):
 0.389477  0.354793  0.260716
 0.684856  0.564783  0.983001

julia> A[-3:6,10:15]
10×6 CircularArray(::Matrix{Float64}):
 0.389477  0.354793  0.260716  0.389477  0.354793  0.260716
 0.684856  0.564783  0.983001  0.684856  0.564783  0.983001
 0.389477  0.354793  0.260716  0.389477  0.354793  0.260716
 0.684856  0.564783  0.983001  0.684856  0.564783  0.983001
 0.389477  0.354793  0.260716  0.389477  0.354793  0.260716
 0.684856  0.564783  0.983001  0.684856  0.564783  0.983001
 0.389477  0.354793  0.260716  0.389477  0.354793  0.260716
 0.684856  0.564783  0.983001  0.684856  0.564783  0.983001
 0.389477  0.354793  0.260716  0.389477  0.354793  0.260716
 0.684856  0.564783  0.983001  0.684856  0.564783  0.983001
```

## BiDiagonal Matrix
```julia

```

## Diagonal Matrix
```julia

```

## Hermitian Matrix
```julia

```

## LinearAlgebra.Symmetric
```julia

```

## LinearAlgebra.SymTriDiagonal
```julia

```

## LinearAlgebra.TriDiagonal
```julia

```

## ToeplitzMatrices.Circulant
```julia

```

## ToeplitzMatrices.Hankel
```julia

```

## ToeplitzMatrices.LowerTriangularToeplitz
```julia

```

## ToeplitzMatrices.SymmetricToeplitz
```julia

```

## ToeplitzMatrices.Toeplitz
```julia

```

## ToeplitzMatrices.UpperTriangularToeplitz
```julia

```

## Reindexed arrays
```julia
julia> using IndirectArrays

julia> B = rand(1:4,2,2)
2×2 Matrix{Int64}:
 1  1
 4  3

julia> A=rand(4)
4-element Vector{Float64}:
 0.6102492641758752
 0.18893384579624606
 0.70868873382007
 0.0005924983596024003

julia> IndirectArray(B,A)
2×2 IndirectArray{Float64, 2, Int64, Matrix{Int64}, Vector{Float64}}:
 0.610249     0.610249
 0.000592498  0.708689
```
