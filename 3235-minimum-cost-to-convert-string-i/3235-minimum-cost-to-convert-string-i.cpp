#include <vector>
#include <unordered_map>
#include <queue>
#include <climits>
#include <algorithm>

using namespace std;

class Solution {
public:
    // Helper function to perform Dijkstra's algorithm
    vector<long long> dijkstra(char source, const unordered_map<char, vector<pair<char, int>>> &adj) {
        vector<long long> dist(26, LLONG_MAX);
        priority_queue<pair<long long, char>, vector<pair<long long, char>>, greater<pair<long long, char>>> pq;
        pq.push({0, source});
        dist[source - 'a'] = 0;
        
        while (!pq.empty()) {
            long long d = pq.top().first;
            char u = pq.top().second;
            pq.pop();
            
            if (d > dist[u - 'a']) continue;
            
            if (adj.find(u) != adj.end()) {
                for (const auto &neighbor : adj.at(u)) {
                    char v = neighbor.first;
                    int weight = neighbor.second;
                    
                    if (dist[u - 'a'] + weight < dist[v - 'a']) {
                        dist[v - 'a'] = dist[u - 'a'] + weight;
                        pq.push({dist[v - 'a'], v});
                    }
                }
            }
        }
        
        return dist;
    }
    
    long long minimumCost(string source, string target, vector<char>& original, vector<char>& changed, vector<int>& cost) {
        unordered_map<char, vector<pair<char, int>>> adj;
        for (int i = 0; i < original.size(); ++i) {
            adj[original[i]].emplace_back(changed[i], cost[i]);
        }
        
        long long totalCost = 0;
        
        // Set to track unique characters that need to be processed
        unordered_set<char> uniqueChars;
        uniqueChars.insert(source.begin(), source.end());
        uniqueChars.insert(target.begin(), target.end());
        
        // Map to store the shortest paths between characters
        unordered_map<char, vector<long long>> distMap;
        for (char ch : uniqueChars) {
            distMap[ch] = dijkstra(ch, adj);
        }
        
        // Calculate the total minimum cost to convert source to target
        for (size_t i = 0; i < source.length(); ++i) {
            if (source[i] == target[i]) continue;
            long long cost = distMap[source[i]][target[i] - 'a'];
            if (cost == LLONG_MAX) return -1;
            totalCost += cost;
        }
        
        return totalCost;
    }
};

