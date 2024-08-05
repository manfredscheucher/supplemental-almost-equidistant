from sys import argv

if len(argv) != 4:
	print "usage:",argv[0],"[dimension] [enumerate] [encode]"
	print "dimension (integer): dimension to consider"
	print "enumerate (0 or 1) : whether to enumerate all graphs" 
	print "encode (0 or 1)    : whether to print graph6-encoding" 
	exit()

d = int(argv[1])
enumerate_graphs = int(argv[2])
encode = int(argv[3])
assert(d in [2,3,4,5])
assert(enumerate_graphs in [0,1])
assert(encode in [0,1])

if d == 2:
	print "A two-dimensional abstract almost-equidistant graph is a graph"
	print "with independence number at most 2, and without K_4 or K_{2,3}."
	forbidden_subgraph = k2_3 = graphs.CompleteBipartiteGraph(2,3)

if d == 3:
	print "A three-dimensional abstract almost-equidistant graph is a graph"
	print "with independence number at most 2, and without K_5 or K_{3,3}."
	forbidden_subgraph = k3_3 = graphs.CompleteBipartiteGraph(3,3)

if d == 4:
	print "A four-dimensional abstract almost-equidistant graph is a graph"
	print "with independence number at most 2, and without K_6 or K_{1,3,3}."
	forbidden_subgraph = k1_3_3 = graphs.CompleteMultipartiteGraph([1,3,3])

if d == 5:
	print "A five-dimensional abstract almost-equidistant graph is a graph"
	print "with independence number at most 2, and without K_7 or K_{3,3,3}."
	forbidden_subgraph = k3_3_3 = graphs.CompleteMultipartiteGraph([3,3,3])

print "Here follows a list of all such graphs."
print

def extend(g):
	extensions = set()
	n = len(g)
	dmin = min(g.degree()) if n > 0 else 0
	for k in [max(0,n-d-1)..n]: # every vertex has at least n-d-1 neighbors  
		if k > dmin+1: continue # w.l.o.g. the new vertex is of minimum degree
		for s in Subsets(g.vertices(),k):
			h = g.copy(immutable=False)
			h.add_vertex(i);
			for j in s: 
				h.add_edge(i,j)
			if h.complement().is_triangle_free() \
			and h.clique_number() < d+2 \
			and not h.subgraph_search(forbidden_subgraph):
				extensions.add(h.canonical_label().copy(immutable=True))
	return extensions

gr = {0:{Graph(0).copy(immutable=True)}} # initialize empty graph
i = 0
while True:
	i += 1
	if not gr[i-1]: break
	gr[i] = set()
	for g in gr[i-1]:
		gr[i] |= extend(g)

	print len(gr[i]),"abstract almost-equidistant graphs on",i,"vertices:"
	
	if enumerate_graphs:
		for g in gr[i]:
			if encode:
				print g.graph6_string()	
			else:
				print g.vertices(),g.edges(labels=False)
		print
