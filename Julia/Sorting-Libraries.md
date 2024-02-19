# A Survey of Sorting Libraries of Julia

|Method|Input|Output|Algorithm|Disadvantage|
|------|-----|------|---------|----------|
|`Base.minmax`|A|T|network|size and keywords|
|`Base.sort!`|V|V|hybrid||
|`TupleSort.sort`|T|T|merge|performance|
|`SortingNetworks.swapsort`|A|T|network|size and keywords|
|`StaticArrays`|T|T|hybrid||

- `A`, `T`, `V` stands for arguments, tuple and vector respectively. A method could be extended to adapt different input types, but here lists the types used by the sorting core. Julia doesn't support returning arguments and methods that want to do that can only return a tuple.
- The "keyword" in disadvantages means the `lt` and `by` keywords supported by `Base.sort`.

## Benchmarks

## Method overview

### Base.sort

### `TupleSort.sort`
This algorithm takes a tuple as input and outputs a sorted tuple. It uses merge sorting and produces many intermediate tuples, so becomes slower for large tuple. [The owner has no motivation of using other algorithms](https://github.com/Jutho/TupleTools.jl/issues/20#issuecomment-1951482632). Other performance problems are related to the nature of Julia tuples, as splatting a collection is very slow.

### `SortingNetworks.swapsort` @0.3.2
This algorithm takes arguments as input and outputs a sorted tuple. It uses network sorting. The sorter is borrowed from [SorterHunter](https://github.com/bertdobbelaere/SorterHunter), a C++ package. SorterHunter has been updated to 64 arguments, but SortingNetworks.jl only has 25. It also doesn't support `lt` and `by` keywords. Overwriting `SortingNetworks.min_max` method could sometimes be a workaround.

The future work is to make a macro to generate codes from the results of SorterHunter. The results are in json files.
