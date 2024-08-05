from sys import argv

f = open(argv[1])
f2 = open(argv[1]+".ming","w")

ct = 0
all = 0
for g in f.readlines():
	all += 1
	G = Graph(g)
	assert(not G.has_loops())
	assert(not G.multiple_edges())
	G = Graph(G,loops=False,multiedges=False)
	assert(G.complement().is_triangle_free())

	invalid = False
	for e in G.edges(labels=False):
		G.delete_edge(e)
		if G.complement().is_triangle_free():
			invalid = True
			break
		G.add_edge(e)

	if not invalid:
		f2.write(g)
		ct += 1

print ct,"of",all,"graphs are minimal."
