def aStarAlgo(start_node, stop_node):
    open_set = set(start_node)
    closed_set = set()
    g = {}               #store distance from starting node
    parents = {}         # parents contains an adjacency map of all nodes
    #distance of starting node from itself is zero
    g[start_node] = 0
    #start_node is root node i.e it has no parent nodes
    #so start_node is set to its own parent node
    parents[start_node] = start_node
    while len(open_set) > 0:
        n = None
        #node with lowest f() is found
        for v in open_set:
            if n == None or g[v] + heuristic(v) < g[n] + heuristic(n):
                n = v
        if n == stop_node or Graph_nodes[n] == None:
            pass
        else:
            for (m, weight) in get_neighbors(n):
                #nodes 'm' not in first and last set are added to first
                #n is set its parent
                if m not in open_set and m not in closed_set:
                    open_set.add(m)
                    parents[m] = n
                    g[m] = g[n] + weight
                #for each node m,compare its distance from start i.e g(m) to the
                #from start through n node
                else:
                    if g[m] > g[n] + weight:
                        #update g(m)
                        g[m] = g[n] + weight
                        #change parent of m to n
                        parents[m] = n
                        #if m in closed set,remove and add to open
                        if m in closed_set:
                            closed_set.remove(m)
                            open_set.add(m)
        if n == None:
            print('Path does not exist!')
            return None
        
        # if the current node is the stop_node
        # then we begin reconstructin the path from it to the start_node
        if n == stop_node:
            path = []
            while parents[n] != n:
                path.append(n)
                n = parents[n]
            path.append(start_node)
            path.reverse()
            print('Path found: {}'.format(path))
            return path
        # remove n from the open_list, and add it to closed_list
        # because all of his neighbors were inspected
        open_set.remove(n)
        closed_set.add(n)
    print('Path does not exist!')
    return None

#define fuction to return neighbor and its distance
#from the passed node
def get_neighbors(v):
    if v in Graph_nodes:
        return Graph_nodes[v]
    else:
        return None

#for simplicity we ll consider heuristic distances given
#and this function returns heuristic distance for all nodes
def heuristic(n):
    H_dist = {
        'A': 30,
        'B': 40,
        'C': 60,
        'D': 10,
        'E': 35,
        'F': 35,
        'G1': 0,
        'G2': 0,
        'S': 45
    }
    return H_dist[n]

#Describe your graph here
Graph_nodes = {
    'A': [('E', 35)],
    'B': [('F', 3)],
    'C': [('D', 10), ('G2', 0)],
    'D': [('G2',35)],
    'E': [('S', 45), ('G1', 0)],
    'F': [('A', 5), ('C', 5)],
    'G1': [('G2', 0)],
    'G2': [],
    'S': [('A',30),('B',2),('D',10)]
}



# def bfs(visited, graph, node): #function for BFS
#   visited.append(node)
#   queue.append(node)

#   while queue:          # Creating loop to visit each node
#     m = queue.pop(0) 
#     print (m, end = " ") 

#     for neighbour in graph[m]:
#       if neighbour not in visited:
#         visited.append(neighbour)
#         queue.append(neighbour)

# graph = {
#   'A' : ['B','F'],
#   'B' : ['A','C', 'D'],
#   'C' : ['B','D','E'],
#   'D' : ['B','C','E'],
#   'E' : ['C','D','I','J'],
#   'F' : ['A','G','H'],
#   'G' : ['F','I'],
#   'H' : ['F','I'],
#   'I' : ['E','G','H','J'],
#   'J' : []
# }

# visited = [] # List for visited nodes.
# queue = []     #Initialize a queue

# # Driver Code
# print("Following is the Breadth-First Search")
# bfs(visited, graph, 'A')    # function calling
aStarAlgo('S', 'G2')
