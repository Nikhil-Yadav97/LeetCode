class Solution {
public:
    vector<int> countServers(int n, vector<vector<int>>& logs, int x, vector<int>& queries) {

        sort(logs.begin(), logs.end(), [](auto &a, auto &b) {
            return a[1] < b[1];
        });

        int m = queries.size();

        // Store query with its original index
        vector<pair<int, int>> q;
        for (int i = 0; i < m; i++) {
            q.push_back({queries[i], i});
        }

        sort(q.begin(), q.end());

        vector<int> freq(n + 1, 0);
        vector<int> ans(m);

        int l = 0, r = 0;
        int activeServers = 0;

        for (auto &[time, idx] : q) {

            int left = time - x;

            // Add logs within the right boundary
            while (r < logs.size() && logs[r][1] <= time) {

                int server = logs[r][0];

                if (freq[server] == 0)
                    activeServers++;

                freq[server]++;
                r++;
            }

            // Remove logs outside the left boundary
            while (l < r && logs[l][1] < left) {

                int server = logs[l][0];

                freq[server]--;

                if (freq[server] == 0)
                    activeServers--;

                l++;
            }

            // Servers with zero requests
            ans[idx] = n - activeServers;
        }

        return ans;
    }
};