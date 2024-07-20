class Solution {
public:
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        unordered_set<int> visited;
        queue<int> qu;
        qu.push(0);
        visited.insert(0);
        while(!qu.empty()){
            int curr=qu.front();
            qu.pop();
            for(int neighbour:rooms[curr]){
                if(visited.count(neighbour)==0){
                    qu.push(neighbour);
                    visited.insert(neighbour);
                }
            }
        }
        return visited.size()==rooms.size();
    }
};