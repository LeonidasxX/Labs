class Graph:
    def __init__(self):
        self.adjlist = dict()
        
    def addedge(self, u, v):
        if u in self.adjlist:
            self.adjlist[u].append(v)
        else:
            self.adjlist[u] = [v]
        
        if v in self.adjlist:
            self.adjlist[v].append(u)
        else:
            self.adjlist[v] = [u]


class PQueue:
    def __init__(self):
        self.queue = []
        
    def isEmpty(self):
        return len(self.queue) == 0
    
    def enqueue(self, ele, pri):
        self.queue.append((ele, pri))
    
    def dequeuemin(self):
        if self.isEmpty():
            return None, None
        
        minidx = None
        minpri = None
        for i in range(len(self.queue)):
            ele, pri = self.queue[i]
            
            if minpri == None or pri < minpri:
                minidx = i
                minpri = pri
        
        ele, pri = self.queue.pop(minidx)
        
        return ele, pri
    
    def dequeuemax(self):
        if self.isEmpty():
            return None, None
        
        maxidx = None
        maxpri = None
        for i in range(len(self.queue)):
            ele, pri = self.queue[i]
            
            if maxpri == None or pri > maxpri:
                maxidx = i
                maxpri = pri
        
        ele, pri = self.queue.pop(maxidx)
        
        return ele, pri

def heuristic(n):
    return n**2

def hillclimbsearch(graph, start):
    curr = start
    currheu = heuristic(start)
    
    while True:
        children = graph.adjlist[curr]
        
        q = PQueue()
        for child in children:
            q.enqueue(child, heuristic(child))
            
        child, heu = q.dequeuemin()
        
        if heu < currheu:
            curr = child
            currheu = heu
        else:
            return curr

g = Graph()

for i in range(-9, 11):
    g.addedge(i, i-1)
print("Maximum value: ", hillclimbsearch(g,7))


