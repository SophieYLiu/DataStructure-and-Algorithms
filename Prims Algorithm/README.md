# Prims-Algorithm
Include graph basics and find minimum spanning tree using prim's algorithm, written in C++ 

Initilization:
prompt for start point v
Unseen{ALL-v}, Seen{v}
Bridges{}: a set of edges of type Edge
list all edges of type E (pair p(a,b), weight w): A={x, y...}   ---make size of A is n + 1 (A[n] is for the min)
   if unoriented: flip pair and list edge again
 
(REPEAT)until Unseen==empt&&Seen=={All}

start from v, V.adjc:return a set of adjc edges of type Edge{x, y..}, += Bridges
heapify the Bridges by the weight
v=Bridges[0].p.second,
returnt the Bridges[0]--(.p.second: remove from Unseen & add in Seen), add Bridges[0] to MST and remove it from Bridges, or return it

