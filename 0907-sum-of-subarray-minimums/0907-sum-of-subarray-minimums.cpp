class Solution {
public:
    int sumSubarrayMins(vector<int>& arr) {
        stack<int> st;
        vector<int> nse(arr.size());
        vector<int> pse(arr.size());

        // Calculate Next Smaller Element (NSE)
        for (int i = arr.size() - 1; i >= 0; i--) {
            while (!st.empty() && arr[st.top()] >= arr[i])
                st.pop();
            nse[i] = st.empty() ? arr.size() : st.top();
            st.push(i);
        }

        // Clear the stack before calculating PSE
        while (!st.empty()) st.pop();

        // Calculate Previous Smaller Element (PSE)
        for (int i = 0; i < arr.size(); i++) {
            while (!st.empty() && arr[st.top()] > arr[i])
                st.pop();
            pse[i] = st.empty() ? -1 : st.top();
            st.push(i);
        }

        // Calculate the total sum of minimums
        long long total = 0;
        const int MOD = 1e9 + 7; // To handle large values
        for (int i = 0; i < arr.size(); i++) {
            long long left = i - pse[i];
            long long right = nse[i] - i;
            total = (total + left * right % MOD * arr[i] % MOD) % MOD;
        }

        return static_cast<int>(total);
    }
};
