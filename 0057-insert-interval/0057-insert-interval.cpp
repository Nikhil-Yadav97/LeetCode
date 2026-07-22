class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
       vector<vector<int>> ans;
       int i=0,n=intervals.size();
       for(i=0;i<n;i++){
        int st=intervals[i][0];
        int ed=intervals[i][1];
        if(st<newInterval[0]&&ed<newInterval[0]){
            ans.push_back(intervals[i]);
        }else{
            break;
        }
       }

       while (i < n && intervals[i][0] <= newInterval[1]) {
            newInterval[0] = min(newInterval[0], intervals[i][0]);
            newInterval[1] = max(newInterval[1], intervals[i][1]);
            i++;
        }
        ans.push_back(newInterval);
        for(i;i<n;i++){
            ans.push_back(intervals[i]);
        }



       return ans;  
    }
};