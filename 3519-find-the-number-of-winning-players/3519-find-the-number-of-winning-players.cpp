class Solution {
public:
    int winningPlayerCount(int n, vector<vector<int>>& pick) {
        unordered_map<int,unordered_map<int, int>> player_picks;

    for (const auto& p : pick) {
        int player = p[0];
        int color = p[1];

        if (player_picks.find(player) == player_picks.end()) {
            player_picks[player] = {};
        }

        if (player_picks[player].find(color) == player_picks[player].end()) {
            player_picks[player][color] = 0;
        }

        player_picks[player][color]++;
    }

    int winners = 0;

    for (const auto& player : player_picks) {
        int max_picks = 0;
        for (const auto& picks : player.second) {
            max_picks = max(max_picks, picks.second);
        }

        if (max_picks > player.first) {
            winners++;
        }
    }

    return winners;
}
};