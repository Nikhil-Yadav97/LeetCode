class Solution {
    public int minimumSumSubarray(List<Integer> nums, int l, int r) {
        Integer n = nums.size();
        List<Integer> prefix = new ArrayList<>(Collections.nCopies(n, 0));
        prefix.set(0, nums.get(0));
        for (int i = 1; i < n; i++) {
            prefix.set(i, prefix.get(i - 1) + nums.get(i));
        }
        Integer ans = Integer.MAX_VALUE;
        for (int i = 0; i < n; i++) {
            
            for (int j = i + l - 1; j < Math.min(n , i + r); j++) {
                int sum = prefix.get(j);

                if (i > 0) {
                    sum -= prefix.get(i - 1);
                }

                if (sum > 0) {
                    ans = Math.min(ans, sum);
                }
            }
        }
        return ans == Integer.MAX_VALUE ? -1 : ans;
    }
}