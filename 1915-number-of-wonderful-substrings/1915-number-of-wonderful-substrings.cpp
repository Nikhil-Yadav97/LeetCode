class Solution {
public:
    long long wonderfulSubstrings(string word) {
        long long count = 0;
        map<int, long long> mpp;
        int temp = 0;
        mpp[0]=1;
        for (int i = 0; i < word.size(); i++) {
            int ind = word[i] - 'a'+1;
            temp = temp ^ (1 << ind);

            count += mpp[temp];
            for (int j = 1; j <= 10; j++) {
                int newmask = temp ^ (1 << j);
                count += mpp[newmask];
            }
            mpp[temp]++;
        }
        return count;
    }
};