class Solution {
public:
    double maxAverageRatio(vector<vector<int>>& classes, int extraStudents) {
        // Priority queue to maximize the gain of adding extra students
        auto gain = [](double pass, double total) {
            return ((pass + 1) / (total + 1)) - (pass / total);
        };

        priority_queue<pair<double, pair<int, int>>> pq;
        for (auto& clas : classes) {
            int pass = clas[0];
            int total = clas[1];
            pq.push({gain(pass, total), {pass, total}});
        }

        // Distribute the extra students
        while (extraStudents--) {
            auto [currentGain, clas] = pq.top();
            pq.pop();

            int pass = clas.first;
            int total = clas.second;

            // Update the class with an additional student
            pass++;
            total++;
            pq.push({gain(pass, total), {pass, total}});
        }

        // Calculate the final average
        double totalAvg = 0;
        while (!pq.empty()) {
            auto [_, clas] = pq.top();
            pq.pop();
            int pass = clas.first;
            int total = clas.second;
            totalAvg += (double)pass / total;
        }

        return totalAvg / classes.size();
    }
};