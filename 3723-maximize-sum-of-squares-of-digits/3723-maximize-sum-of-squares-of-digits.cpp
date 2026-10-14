class Solution {
public:
    string maxSumOfSquares(int num, int sum) {
        string result = "";
        while (result.size() != num) {
            int val = min(9, sum);
            result += val + '0';
            sum -= val;
        }
        return sum ? "" : result;
    }
};