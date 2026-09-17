class Solution:

    def isBipartite(self, graph: list[list[int]]) -> bool:
        n=len(graph)
        color=[-1]*n

        def fn(node,n,col,graph):
            if node>=n :
                return True
            
            for it in graph[node]:
                if color[it]==-1:
                    color[it]=not col
                    if not fn(it,n,not col,graph):
                        return False
                else:
                    if color[it]==col:
                        return False
            return True
        
        for i in range(n):
            if color[i]==-1:
                color[i]=0
                if fn(i,n,0,graph)==False:
                    return False
        return True

            

        