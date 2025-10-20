package task66;

class Solution {
    public int[] plusOne(int[] digits) {
        for (int i = digits.length - 1; i >= 0; i--) {
            if (digits[i] < 9) {
                digits[i]++;
                return digits;
            }
            digits[i] = 0;
        }
        digits = new int[digits.length + 1];
        for (int i = 0; i < digits.length; i++) {
            if (i == 0) digits[i] = 1;
            else digits[i] = 0;
        }
        return digits;
    }
}
