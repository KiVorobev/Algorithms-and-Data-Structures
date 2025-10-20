package task70;

class Solution {
    public int climbStairs(int n) {
        if (n < 4) return n;

        int prev2 = 0;
        int prev1 = 1;
        int current = 1;

        for (int i = 0; i < n; i++) {
            current = prev1 + prev2;
            prev2 = prev1;
            prev1 = current;
        }
        return current;
    }
}
