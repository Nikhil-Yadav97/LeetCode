class Solution {
public:
    static int digitsum(int num) {
        int sum = 0;
        while (num) {
            sum += num % 10;
            num = num / 10;
        }
        return sum;
    }
    static bool compare(int a, int b) {
        int d1 = digitsum(a);
        int d2 = digitsum(b);
        if (d1 == d2)
            return a < b;
        return d1 < d2;
    }
    int minSwaps(vector<int>& nums) {
        map<int, int> mpp;
        int n=nums.size();
        for(int i=0;i<n;i++)
        {
            mpp[nums[i]]=i;
        }
        vector<int> arr=nums;
        sort(begin(arr), end(arr), compare);
        int swaps=0;
        for(int i=0;i<n;i++)
        {
            if(arr[i]!=nums[i])
            {
                swaps++;
                int ind=mpp[arr[i]];
                mpp[nums[i]]=ind;
                mpp[arr[i]]=i;
                swap(nums[i],nums[ind]);
                
            }
        }
        return swaps;

    }
};