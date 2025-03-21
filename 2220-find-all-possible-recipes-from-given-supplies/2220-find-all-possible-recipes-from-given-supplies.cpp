class Solution {
public:
    vector<string> findAllRecipes(vector<string>& recipes, vector<vector<string>>& ingredients, vector<string>& supplies) {
        unordered_set<string> st(supplies.begin(), supplies.end());
        vector<string> res;
        bool changed = true;

        while (changed) {
            changed = false;
            for (int i = 0; i < recipes.size(); i++) {
                string recipe = recipes[i];
                if (st.find(recipe) != st.end()) continue; 

                bool canMake = true;
                for (string& ing : ingredients[i]) {
                    if (st.find(ing) == st.end()) {
                        canMake = false;
                        break;
                    }
                }

                if (canMake) {
                    st.insert(recipe);
                    res.push_back(recipe);
                    changed = true;
                }
            }
        }
        return res;
    }
};
