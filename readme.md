Fibonacci堆比二进制堆（Java优先级队列中使用的数据结构）快得多，因为Dijkstra算法对Fibonacci堆来说需要O（m+n log n）的时间，而对二进制堆来说需要O（m log n）。这意味着对于大型密集图来说，斐波那契堆在最坏情况下会更快。
虽然斐波那契堆在渐进上比二进制堆快，但它们有刻意的大常数系数，而且斐波那契堆的许多基本操作都很耗时。从长远来看，它们会比二进制堆的表现更好，但对于小图来说，常数项可能很大，斐波那契堆实际上更慢。
其次，比较O（M + n log n）和O（m log n）的渐进性）。如果使用的图是稀疏的（即m=O（n）），那么两个渐进执行时间是相同的（O（n log n））。在这种情况下，斐波那契堆没有理论上的优势，二进制堆可能是一个更好的选择。