package task67;

class Solution {
    public String addBinary(String a, String b) {
        int sum = 0;
        char[] aChars = a.toCharArray();
        char[] bChars = b.toCharArray();
        int maxLength = Math.max(aChars.length, bChars.length);
        char[] result = new char[maxLength];
        boolean extra = false;
        for (int i = 0; i < maxLength; i++) {
            char aVal = '0';
            char bVal = '0';
            if (aChars.length >= i + 1) {
                aVal = aChars[aChars.length - i - 1];
            }
            if (bChars.length >= i + 1) {
                bVal = bChars[bChars.length - i - 1];
            }
            if (aVal == '0' && bVal == '0') {
                if (!extra) {
                    result[maxLength - i - 1] = '0';
                } else {
                    result[maxLength - i - 1] = '1';
                    extra = false;
                }
            } else if (aVal == '1' && bVal == '1') {
                if (!extra) {
                    result[maxLength - i - 1] = '0';
                    extra = true;
                } else {
                    result[maxLength - i - 1] = '1';
                }
            } else {
                if (!extra) {
                    result[maxLength - i - 1] = '1';
                } else {
                    result[maxLength - i - 1] = '0';
                }
            }
        }
        return extra ? '1' + String.valueOf(result) : String.valueOf(result);
    }
}
