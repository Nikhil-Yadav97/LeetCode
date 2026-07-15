class Disjoint {

public:
    vector<int> rank, parent;
    Disjoint(int n) {
        rank.resize(n, 0);
        parent.resize(n);
        for (int i = 0; i < n; i++) {
            parent[i] = i;
        }
    }

    int findupar(int node) {
        if (node == parent[node])
            return node;
        return parent[node] = findupar(parent[node]);
    }

    bool rankunion(int u, int v) {
        int upar = findupar(u);
        int vpar = findupar(v);
        if (upar == vpar)
            return false;

        if (rank[upar] > rank[vpar]) {
            parent[vpar] = upar;
        } else {
            if (rank[upar] < rank[vpar]) {
                parent[upar] = vpar;
            } else {
                parent[upar] = vpar;
                rank[vpar]++;
            }
        }
        return true;
    }
    int findcomp() {
        int cnt = 0;
        for (int i = 0; i < parent.size(); i++) {
            if (i == parent[i])
                cnt++;
        }
        return cnt;
    }
};
class Solution {
public:
    int removeStones(vector<vector<int>>& stones) {
        Disjoint ds(stones.size());
        int n = stones.size();
        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                if (stones[i][0] == stones[j][0] ||
                    stones[i][1] == stones[j][1]) {
                    ds.rankunion(i, j);
                }
            }
        }
        int component=0;
        for (int i=0;i<n;i++){
            if(i==ds.parent[i])
            component++;
        }
        return n-component;
    }
};