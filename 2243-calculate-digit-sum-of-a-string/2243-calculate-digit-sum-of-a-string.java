class Solution {
    public String oper(String s, int k) {
        String str = "";
        int sum = 0,groups=0;

        for (int i = 0; i < s.length(); i++) {
            sum += s.charAt(i) - '0';
            if ((i + 1) % k == 0) {
                str += Integer.toString(sum);
                sum = 0;
                groups++;
            }
        }

        if (Math.ceil(s.length() / (float) k) > groups) {
            str += (sum);
        }
        return str.toString();
    }

    public String digitSum(String s, int k) {
        int n = s.length();
        if (n < k)
            return s;

        while (s.length() > k) {
            s = oper(s, k);
        }
        return s;
    }
}