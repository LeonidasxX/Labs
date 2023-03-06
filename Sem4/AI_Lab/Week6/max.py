class Graph:
	def __init__(self):
		self.graph = {}
		self.vertex = 0
		self.vertices = []
		self.matrix = []


	def add_vertex_list_directed(self, v):
		if v in self.graph:
			print("Vertex ", v, " already exists.")
		else:
			self.vertex += 1
			self.graph[v] = []


	def add_edge_list_directed_weight(self, v1, v2):
		if v1 not in self.graph:
			print("Vertex ", v1, " does not exist.")
		elif v2 not in self.graph:
			print("Vertex ", v2, " does not exists.")
		else:
			temp = [v2,v2*v2]
			self.graph[v1].append(temp)
			temp = [v1,v1*v1]
			self.graph[v2].append(temp)


	def display_directed_weight(self):
		print("Displaying Directed Weighted Graph...")
		for i in self.graph:
			if(len(self.graph[i])>1):
				print(i, " -> ", self.graph[i][0])
				print(i, " -> ", self.graph[i][1])
			else:
				print(i, " -> ", self.graph[i][0])
		print(self.graph)

	def hill_climb(self):
		maxima = 0
		for i in self.graph:
			neighbors = self.graph[i]
			neighbors_value = []
			for i in neighbors:
				neighbors_value.append(i[1])
			best_neighbor = max(neighbors_value)
			if maxima<best_neighbor:
				maxima = best_neighbor
		return maxima

graph = Graph()
for i in range(-10,11):
	graph.add_vertex_list_directed(i)

for i in range(-10,10):
	graph.add_edge_list_directed_weight(i, i+1)

maxima = graph.hill_climb()
print("Maxima of the function x**2 is: ",maxima)
