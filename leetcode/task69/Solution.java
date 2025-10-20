package task69;

class Solution {
    public int mySqrt(int x) {
        if (x == 0 || x == 1) return x;
        int left = 1;
        int right = x;
        int maxResult = 1;
        while (left <= right) {
            int mid = left + (right - left) / 2;

            if ((long) mid * mid == x) {
                return mid;
            }
            if ((long) mid * mid < x) {
                if (mid > maxResult) {
                    maxResult = mid;
                }
                left = mid + 1;
            } else {
                right = mid - 1;
            }
        }
        return maxResult;
    }
}