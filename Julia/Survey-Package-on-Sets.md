# A survey on packages implementing geometric/analytic/algebraic sets

## Introduction

A set is a collection of elements where the order doesn't matter (that differs it from an array). Julia has a built in abstract type `AbstractSet{T}` where `T` is the eltype, as well as a concrete type `Set` that implements a finite (and small enough) set, the latter of which is not quite handy for some scientific applications. Therefore, custom set types need to be constructed. In some scenarios, the default interface of `AbstractSet` can be annoying, so implementations can be completely independent. Many of those packages have overlapped features with different implementations, which can confuse users. This article summarises packages that implement custom sets and hopefully can help the readers choose the proper package.

## LazySets.jl

```
LazySet
├─ AbstractAffineMap
│  ├─ AffineMap
│  ├─ ExponentialMap
│  ├─ ExponentialProjectionMap
│  ├─ InverseLinearMap
│  ├─ LinearMap
│  ├─ ResetMap
│  └─ Translation
├─ AbstractPolynomialZonotope
│  ├─ DensePolynomialZonotope
│  ├─ SimpleSparsePolynomialZonotope
│  └─ SparsePolynomialZonotope
├─ Bloating
├─ CachedMinkowskiSumArray
├─ CartesianProduct
├─ CartesianProductArray
├─ Complement
├─ ConvexSet
│  ├─ AbstractCentrallySymmetric
│  │  ├─ AbstractBallp
│  │  │  ├─ Ball2
│  │  │  └─ Ballp
│  │  └─ Ellipsoid
│  ├─ AbstractPolyhedron
│  │  ├─ AbstractPolytope
│  │  │  ├─ AbstractCentrallySymmetricPolytope
│  │  │  │  ├─ AbstractZonotope
│  │  │  │  │  ⋮
│  │  │  │  │
│  │  │  │  └─ Ball1
│  │  │  ├─ AbstractPolygon
│  │  │  │  ├─ AbstractHPolygon
│  │  │  │  │  ⋮
│  │  │  │  │
│  │  │  │  └─ VPolygon
│  │  │  ├─ HPolytope
│  │  │  ├─ Tetrahedron
│  │  │  └─ VPolytope
│  │  ├─ HPolyhedron
│  │  ├─ HalfSpace
│  │  ├─ Hyperplane
│  │  ├─ Line
│  │  ├─ Line2D
│  │  ├─ Star
│  │  └─ Universe
│  ├─ ConvexHull
│  ├─ ConvexHullArray
│  └─ EmptySet
├─ Intersection
├─ IntersectionArray
├─ MinkowskiSum
├─ MinkowskiSumArray
├─ Polygon
├─ QuadraticMap
├─ Rectification
├─ UnionSet
└─ UnionSetArray
```

## Intervals.jl
