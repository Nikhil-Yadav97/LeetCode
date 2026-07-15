class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst,
                          int k) {
        vector<int> price(n, INT_MAX);
        map<int, vector<pair<int, int>>> adj;
        for (auto& it : flights) {
            adj[it[0]].push_back({it[1], it[2]});
        }
        price[src] = 0;
        queue<tuple<int,int>> q;
        q.push({src,0});
        int steps = 0;
        while (!q.empty() && steps <= k) {
            int sz = q.size();

            while (sz--) {
                auto [node,cost] = q.front();
                for (auto& it : adj[node]) {
                    if (price[it.first] > cost + it.second) {
                        price[it.first] = cost + it.second;
                        q.push({it.first,price[it.first]});
                    }
                }
                q.pop();
            }
            steps++;
        }
        return price[dst] == INT_MAX ? -1 : price[dst];
    }
};