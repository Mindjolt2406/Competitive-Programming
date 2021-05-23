from random import *

''' Generate a random array of integers with elements in the range [L, R] '''
def genRandomArray(N, L, R):
	a = [randrange(L,R+1) for _ in xrange(N)]
	return a

''' Generate a random string from characters in the range [A, B]'''
def genRandomString(N, A, B):
	l = genRandomArray(N, ord(A), ord(B))
	s = ''
	for char in l: s += chr(char)
	return s

''' Generate a random permutation of [1, 2 ... N] '''
def genRandomPermutation(N):
	permutation = range(1, N+1)
	shuffle(permutation)
	return permutation

''' Generate a random unweighted tree'''
def genRandomTree(N):
	edges = []
	for u in xrange(2,N+1):
		v = randrange(1,u)
		edges.append([u,v])

	permutation = genRandomPermutation(N)

	for i in xrange(0,N-1):
		u, v = edges[i]
		u = permutation[u-1]
		v = permutation[v-1]
		edges[i] = (u,v)
	return edges

''' Generate a random weighted tree '''
def genRandomWeightedTree(N, L, R):
	weigths = genRandomArray(N-1, L, R)
	tree = genRandomTree(N)
	wtree = []

	for i in xrange(0,N-1):
		u, v, w = tree[i][0], tree[i][1], weigths[i]
		wtree.append((u, v, w))

	return wtree

''' Undirected, no multiedges and no self-loops '''
def genRandomGraph(N, E):
	edges = {}

	if N == 1: return []

	for i in xrange(E):
		u = randrange(1,N+1)
		v = u
		while v == u: v = randrange(1,N+1)

		while (u,v) in edges or (v,u) in edges:
			u = randrange(1,N+1)
			v = u
			while v == u: v = randrange(1,N+1)

		edges[(u,v)] = 1

	ret = []
	for edge in edges: ret.append(edge)

	return ret

''' Undirected, no multiedges, no self-loops, connected '''
def genRandomConnectedGraph(N, E):
	E -= N-1
	tree = genRandomTree(N)
	edges = {}
	for edge in tree:
		edges[edge] = 1

	for i in xrange(E):
		u = randrange(1,N+1)
		v = u
		while v == u: v = randrange(1,N+1)

		while (u,v) in edges or (v,u) in edges:
			u = randrange(1,N+1)
			v = u
			while v == u: v = randrange(1,N+1)

		edges[(u,v)] = 1

	ret = []
	for edge in edges: ret.append(edge)

	return ret

''' Undirected, no multiedges, no self-loops, can be forced to be connected '''
def genRandomWeightedGraph(N, E, L, R, connected = False):
	graph = []
	if not connected:
		graph = genRandomGraph(N, E)
	else:
		graph = genRandomConnectedGraph(N, E)

	weights = genRandomArray(E, L, R)

	wgraph = []
	for i in xrange(E):
		u, v, w = graph[i][0], graph[i][1], weights[i]
		wgraph.append((u,v,w))
	return wgraph

if __name__ == '__main__':
	l = []
	for i in range(20):
		l.append(randint(0,3))
	
	m = l[:]
	m.sort()

	print l
	print m
	mat = [[0]*4 for x in range(4)]
	for i in range(len(l)):
		if(l[i]!=m[i]): mat[l[i]][m[i]]+=1
	
	for i in range(4):
		for j in range(4):
			print mat[i][j],
		print ""

	cnt = 0
	for i in range(4):
		for j in range(4):
			min1 = min(mat[i][j],mat[j][i])
			mat[i][j] -= min1
			mat[j][i] -= min1
			cnt += min1

	print "cnt:",cnt	

	for i in range(4):
		for j in range(4):
			print mat[i][j],
		print ""
	
