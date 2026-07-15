class Disjoint {
    vector<int> rank, parent;

public:
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
    int findcomp(){
        int cnt=0;
        for(int i=0;i<parent.size();i++){
            if(i==parent[i])
            cnt++;
        }
        return cnt;
    }
};
class Solution {
public:
    int makeConnected(int n, vector<vector<int>>& connections) {
        Disjoint d(n);
        int available = connections.size();
        int extra = 0;
        for (auto& it : connections) {
            if (!d.rankunion(it[0], it[1]))
                extra++;
        }
       int components= d.findcomp();
       return components-1 > extra ? -1 : components-1 ;
    }
};