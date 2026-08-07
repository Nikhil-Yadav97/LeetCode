class Solution {
public:
    int find(int n) {
        string str = to_string(n);
        int product = 1;
        for (int i = 0; i < str.size(); i++) {
            product *= (str[i] - '0');
        }
        return product;
    }
    int smallestNumber(int n, int t) {
        int product = find(n);
        while (product % t != 0) {
            n++;
            product = find(n);
        }
        return n;
    }
};