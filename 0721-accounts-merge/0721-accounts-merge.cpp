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
    vector<vector<string>> accountsMerge(vector<vector<string>>& accounts) {
        map<string, int> mailtoperson;
        int n = accounts.size();
        Disjoint ds(n);
        for (int i = 0; i < n; i++) {
            for (int j = 1; j < accounts[i].size(); j++) {
                if(mailtoperson.find(accounts[i][j])==mailtoperson.end())
                mailtoperson[accounts[i][j]] = i;
                else{
                ds.rankunion(i,mailtoperson[accounts[i][j]]);
                }
            }
        }

        vector<vector<string>> mails(n);
        for(auto it : mailtoperson){
            int number=it.second;
            string mail=it.first;
            int upar=ds.findupar(number);
            
            mails[upar].push_back(mail);
        }
        vector<vector<string>> ans;
        for(int i=0;i<n;i++){
            if(mails[i].size()==0)
            continue;

            vector<string> temp;
            temp.push_back(accounts[i][0]);
            sort(begin(mails[i]),end(mails[i]));
            for(auto it : mails[i]){
                temp.push_back(it);
            }
            ans.push_back(temp);
        }
        return ans;

        return ans;
    }
};