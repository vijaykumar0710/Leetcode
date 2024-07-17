class RecentCounter {
public:
    RecentCounter() {}

    int ping(int t) {
        // Add the current ping time
        pings.push(t);
        
        // Remove all pings that are not within the last 3000ms
        while (!pings.empty() && pings.front() < t - 3000) {
            pings.pop();
        }
        
        // Return the number of pings within the last 3000ms
        return pings.size();
    }
    
private:
    queue<int> pings;
};


/**
 * Your RecentCounter object will be instantiated and called as such:
 * RecentCounter* obj = new RecentCounter();
 * int param_1 = obj->ping(t);
 */