# Homepage of almost-equidistant sets

This website contains a program and supplementary data that were used in the proofs of some of the results in

*   _Almost-equidistant sets_ (M. Balko, A. Pór, M. Scheucher, K. Swanepoel, and P. Valtr), in preparation (2017).

## Abstract

For a positive integer $d$, a set of points in the $d$-dimensional Euclidean space is called almost-equidistant if for any three points from the set, some two are at unit distance. Let $f(d)$ denote the largest size of an almost-equidistant set in the $d$-space.

It is known that $f(2)=7$, $f(3)=10$, and that the extremal almost-equidistant sets are unique. We give independent, computer-assisted proofs of these statements. It is also known that $f(5) \ge 16$. We further show that $12\leq f(4)\leq 13$, $f(6)\geq 18$, $f(7)\geq 20$, and $f(9)\geq f(8)\geq 24$. Up to dimension $4$, our work is based on a computer search, and in dimensions $6$ to $9$, we give constructions based on the construction for $d=5$.

For every dimension $d \ge 3$, we give an example of an almost-equidistant set of $2d+4$ points in the $d$-space and we prove the asymptotic upper bound $f(d) \le O(d^{3/2})$.

## Results

The following text files contain all $n$-vertex abstract almost-equidistant graphs in $\mathbb{R}^d$ for $d = 2, 3, 4$. The graphs are encoded with the graph6 representation ([graph6-encoded](http://doc.sagemath.org/html/en/reference/graphs/sage/graphs/graph.html#sage.graphs.graph.Graph.graph6_string)).

*   [All abstract almost-equidistant graphs in $\mathbb{R}^2$](data/all_graphs_d2.zip) (3 KB),
*   [All abstract almost-equidistant graphs in $\mathbb{R}^3$](data/all_graphs_d3.zip) (5 KB),
*   [All abstract almost-equidistant graphs in $\mathbb{R}^4$](data/all_graphs_d4.zip) (46 KB).

For dimension $d=5$, we provide

*   [all minimal abstract almost-equidistant graphs in $\mathbb{R}^5$](data/min_graphs_d5.zip) (163 KB) and
*   [all abstract almost-equidistant graphs in $\mathbb{R}^5$ for up to $n=12$ vertices](data/all_graphs_d5_up_n_12.zip) (5.5 MB).

All abstract almost-equidistant graphs in $\mathbb{R}^5$ for $n=13,14,15$ vertices are available upon request. We remark that we did not filter our result file for $n=15$ for duplicates, and therefore, some graphs might be isomorphic.  
For dimension $d=6$, we provide

*   [all minimal abstract almost-equidistant graphs in $\mathbb{R}^6$ for up to $n=19$ vertices](data/min_graphs_d6_up_n_19.zip) (18 MB).
*   [all abstract almost-equidistant graphs in $\mathbb{R}^6$ for up to $n=12$ vertices](data/all_graphs_d6_up_n_12.zip) (3.4 MB).
*   [some minimal abstract almost-equidistant graphs in $\mathbb{R}^6$ on $n=25$ vertices](data/some_graphs_d6_n25.g6).

All abstract almost-equidistant graphs in $\mathbb{R}^6$ for $n=13$ vertices are available upon request.

## Our Sage program

The program generates all $n$-vertex abstract almost-equidistant graphs in $\mathbb{R}^d$ for $d \in \{2,3,4\}$ and for $d=5$ and some sufficiently small values of $n$ (see the paper for definitions). The source code of the program is available [here](data/program.sage) and can be executed using [SageMath](http://www.sagemath.org/). The program asks for three parameters. The first parameter defines the dimension, which is either 2, 3, 4, 5, or 6. The second parameter should be set to 1 if all graphs should be enumerated or 0 if the graphs should only be counted. The third parameter should be set to 1 if the graphs should be printed with [graph6-encoding](http://doc.sagemath.org/html/en/reference/graphs/sage/graphs/graph.html#sage.graphs.graph.Graph.graph6_string) or 0 if the edge list should be printed.  
The following command gives an illustration how to use the program:

$ sage program.sage 3 1 1
A three-dimensional abstract almost-equidistant graph is a graph
with independence number at most 2, and without $K_5$ or $K_{3,3}$.
Here follows a list of all such graphs.

```
1 abstract almost-equidistant graphs on 1 vertices:
graphs written to file: graphs3_1.g6
2 abstract almost-equidistant graphs on 2 vertices:
graphs written to file: graphs3_2.g6
3 abstract almost-equidistant graphs on 3 vertices:
graphs written to file: graphs3_3.g6
7 abstract almost-equidistant graphs on 4 vertices:
graphs written to file: graphs3_4.g6
13 abstract almost-equidistant graphs on 5 vertices:
graphs written to file: graphs3_5.g6
29 abstract almost-equidistant graphs on 6 vertices:
graphs written to file: graphs3_6.g6
50 abstract almost-equidistant graphs on 7 vertices:
graphs written to file: graphs3_7.g6
69 abstract almost-equidistant graphs on 8 vertices:
graphs written to file: graphs3_8.g6
35 abstract almost-equidistant graphs on 9 vertices:
graphs written to file: graphs3_9.g6
7 abstract almost-equidistant graphs on 10 vertices:
graphs written to file: graphs3_10.g6
1 abstract almost-equidistant graphs on 11 vertices:
graphs written to file: graphs3_11.g6
0 abstract almost-equidistant graphs on 12 vertices:
graphs written to file: graphs3_12.g6
```

To enumerate all abstract almost-equidistant graphs for a given dimension $d$, we start with a single vertex and repeatedly add a new vertex and go through all possibilities of joining the new vertex to the old vertices. For each possibility of adding edges, we check if the resulting graph contains one of the two forbidden subgraphs and that its complement does not contain a triangle. We use two tricks to speed this up. First, when adding a vertex, we can assume that the newly inserted vertex has minimum degree in the extended graph. Secondly, we only have to go through all possibilities of adding at least $n-d-1$ new edges, where $n$ is the number of vertices before extending the graph. This is because the degree of the newly added vertex has to be at least $n-d-1$, since the complement of an abstract almost-equilateral graph $G$ is triangle-free, hence the non-neighbours of each vertex induce a clique in $G$, which has at most $d+1$ vertices.

### Filter minimal graphs

We also provide our Sage program for testing the minimality of a given graph. For each edge, the program attempts to remove it and checks whether the complement is still triangle-free. If no edge can be removed, we know that the given graphs is minimal. The source code is available [here](data/filter_minimal_graphs.sage).  
The following command gives an illustration how to use the program:

```$ sage filter_minimal_graphs.sage graphs3_10.g6 ```

It shows that 4 of 7 graphs are minimal.

## Our C++ - program (in combination with triangleramsey and/or MTF)

Unfortunetly, our Sage program was not able to compute all graphs for $d=5$ and large $n$ in reasonable time. Thus, we made use of the tools [triangleramsey](http://caagt.ugent.be/triangleramsey) and [MTF](http://caagt.ugent.be/mtf/) to enumerate all maximal triangle-free graphs, which do not contain $K_{d+2}$ in their complement -- so-called "Ramsey(3,d+2)-graphs". We then tested whether the complement of such a graph is a (minimal) almost equidistant-graph in dimension $d$. To do this in reasonable time, we wrote a short C++ program ( [code for dimension 5](data/testvalid_d5.cpp), [code for dimension 6](data/testvalid_d6.cpp) ) which simply tests the a graph for the forbidden subgraphs. For information how to build and use triangleramsey, and also on the "multicode" file-format (*.mc), we refer to the [homepage of triangleramsey](http://caagt.ugent.be/triangleramsey/). When triangleramsey is compiled according to the instructions, the following bash command can be used (in unix/linux, using pipes) to enumerate all minimal almost-equidistant graphs on $n=20$ vertices for dimension $d=5$:

```$ ./triangleramsey-1.0/triangleramsey 20 | ./testvalid_d5 output20.mc```

Here triangleramsey produces all minimal triangle-free graphs and our testvalid_d5 program filters graphs, whose complement is an almost-equidistant graphs for dimension $d=5$.  
To speed up the computations with in triangleramsey, the parameters "ramsey" and the "write_all_ramseygraphs" can be used to only enumerate Ramsey(3,d+2)-graphs. The following command gives an illustration how to enumerate all Ramsey(3,8)-graphs on 19 vertices using triangleramsey.

```$ ./triangleramsey-1.0/triangleramsey 19 ramsey K8.mc write_all_ramseygraphs```

Similarly, the [MTF program](http://caagt.ugent.be/mtf/) can be used to enumerate minimal triangle-free graphs. The following command gives an illustrataion how to enumerate all Ramsey(3,8)-graphs on 19 vertices using MTF.

```$ ./mtf n 19 ramsey_kn 8```

However, as mentioned on the MTF website, triangleramsey is recommended over MTF.