class Solution {
public:
    void bfs(vector<vector<int>> adj, vector<int>& visited, int ind) {
        queue<int> q;
        q.push(ind);
        visited[ind] = 1;
        while (!q.empty()) {
            int node = q.front();
            q.pop();
            for (auto it : adj[node]) {
                if (visited[it] != 1) {
                    q.push(it);
                    visited[it] = 1;
                }
            }
        }
    }
    int findCircleNum(vector<vector<int>>& isConnected) {
        int n = isConnected.size();
        vector<int> visited(n);
        vector<vector<int>> adj(n);
        for (int i = 0; i < n-1; i++) {
            for (int j = i+1; j < n; j++) {
                if (isConnected[i][j] == 1 && i != j)
                {

                    adj[j].push_back(i);
                    adj[i].push_back(j);
                }
            }
        }

        int cnt = 0;

        for (int i = 0; i < n; i++) {
            if (!visited[i]) {
                cnt++;
                bfs(adj, visited, i);
            }
        }
        return cnt;
    }
};