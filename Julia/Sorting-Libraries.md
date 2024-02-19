# A Survey of Sorting Libraries of Julia

|Method|Input|Output|Algorithm|Limitation|
|------|-----|------|---------|----------|
|`TupleSort.sort`|T|T|merge||
|`SortingNetworks.swapsort`|ATV|ATV|network|size|

## Base.sort

## `TupleSort.sort`
`TupleSort.sort` takes a tuple as input and outputs a sorted tuple. It uses merge sort and produces many intermediate tuples, so becomes slower for large tuple. The owner has no motivation of using other algorithms.

## `SortingNetworks.swapsort`
