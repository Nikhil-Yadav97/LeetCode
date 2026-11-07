class Solution {
public:
    vector<int> assignTasks(vector<int>& servers, vector<int>& tasks) {
        int n = servers.size(), m = tasks.size();
        vector<int> ans;
        priority_queue<tuple<int, int>, vector<tuple<int, int>>,
                       greater<tuple<int, int>>>
            free;
        priority_queue<tuple<long long, int, int>,
                       vector<tuple<long long, int, int>>,
                       greater<tuple<long long, int, int>>>
            occupied;
        for (int i = 0; i < n; i++) {
            free.push({servers[i], i});
        }
        long long time=0;
        for (int i = 0; i < m; i++) {
            time=max(time,(long long)i);
            while (!occupied.empty() && get<0>(occupied.top()) <= time) {
                auto [aval, serverno, ind] = occupied.top();
                occupied.pop();
                free.push({serverno, ind});
            }

            if (free.empty()) {
                auto [aval, serverno, ind] = occupied.top();
                occupied.pop();
                time=aval;

                free.push({serverno, ind});

                while (!occupied.empty() && get<0>(occupied.top()) <= time) {
                    auto [t, w, idx] = occupied.top();
                    occupied.pop();
                    free.push({w, idx});
                }
            }

            auto [serverno, ind] = free.top();
            free.pop();

            ans.push_back(ind);
            occupied.push({time+ tasks[i], serverno, ind});
        }
        return ans;
    }
};