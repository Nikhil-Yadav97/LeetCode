class Solution {
public:
    bool check(int n, map<int, int> mpp) {
        while (n) {
            int digit = n % 10;
            if (mpp.find(digit) != mpp.end()) {
                mpp[digit]--;
                if (mpp[digit] == 0)
                    mpp.erase(digit);
            } else {
                return false;
            }
            n = n / 10;
        }
        return true;
    }
    int totalNumbers(vector<int>& digits) {
        int cnt = 0;
        map<int, int> mpp;
        for (int i = 0; i < digits.size(); i++) {
            mpp[digits[i]]++;
        }
        vector<int> ans;
        ;
        for (int i = 100; i <= 999; i++) {
            if (i % 2 == 0 && check(i, mpp))
                cnt++;
        }
        return cnt;
    }
}

;