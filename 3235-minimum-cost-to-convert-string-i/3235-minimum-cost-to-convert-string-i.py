import heapq
from collections import defaultdict
import math

class Solution:
    def dijkstra(self, source, adj, costMatrix):
        # Priority queue to store (cost, character)
        pq = [(0, source)]
        # Dictionary to store the minimum cost to reach each node
        min_cost = {source: 0}
        
        while pq:
            d, adjChar = heapq.heappop(pq)
            
            if d > min_cost.get(adjChar, float('inf')):
                continue
            
            for neighbor, cost in adj[adjChar]:
                new_cost = d + cost
                if new_cost < min_cost.get(neighbor, float('inf')):
                    min_cost[neighbor] = new_cost
                    heapq.heappush(pq, (new_cost, neighbor))
        
        # Update the costMatrix with the results from Dijkstra
        for char in min_cost:
            costMatrix[ord(source) - ord('a')][ord(char) - ord('a')] = min_cost[char]
    
    def minimumCost(self, source, target, original, changed, cost):
        # Create adjacency list from the original and changed lists
        adj = defaultdict(list)
        for u, v, w in zip(original, changed, cost):
            adj[u].append((v, w))
        
        # Initialize the cost matrix with infinity
        costMatrix = [[float('inf')] * 26 for _ in range(26)]
        
        # Run Dijkstra for each unique character in the source string
        for ch in set(source):
            self.dijkstra(ch, adj, costMatrix)
        
        # Compute the total cost to convert source to target
        total_cost = 0
        for sc, tc in zip(source, target):
            if sc == tc:
                continue
            if costMatrix[ord(sc) - ord('a')][ord(tc) - ord('a')] == float('inf'):
                return -1
            total_cost += costMatrix[ord(sc) - ord('a')][ord(tc) - ord('a')]
        
        return total_cost
