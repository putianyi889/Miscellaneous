# A Survey of Sorting Libraries of Julia

|Method|Input|Output|Algorithm|Disadvantage|
|------|-----|------|---------|----------|
|`Base.minmax`|A|T|network|size and keywords|
|`TupleSort.sort`|T|T|merge|performance|
|`SortingNetworks.swapsort`|A|T|network|size and keywords|

- `A`, `T`, `V` stands for arguments, tuple and vector respectively. A method could be extended to adapt different input types, but here lists the types used by the sorting core. Julia doesn't support returning arguments and methods that want to do that can only return a tuple.
- The "keyword" in disadvantages means the `lt` and `by` keywords supported by `Base.sort`.

## Base.sort

## `TupleSort.sort`
This algorithm takes a tuple as input and outputs a sorted tuple. It uses merge sort and produces many intermediate tuples, so becomes slower for large tuple. The owner has no motivation of using other algorithms. Other performance problems are related to the nature of Julia tuples, as splatting a collection is very slow.

## `SortingNetworks.swapsort`
This algorithm takes arguments as input and outputs a sorted tuple.
