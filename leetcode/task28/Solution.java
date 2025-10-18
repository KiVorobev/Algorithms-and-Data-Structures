package task28;

class Solution {
    public int strStr(String haystack, String needle) {
        int startIndex = -1;
        int innerCount = 0;
        if (haystack.length() < needle.length() || needle.length() == 0) {
            return -1;
        }
        char[] haystackChars = haystack.toCharArray();
        char[] needleChars = needle.toCharArray();
        for (int i = 0; i< haystackChars.length; i++) {
            if (haystackChars[i] == needleChars[innerCount]) {
                if (innerCount == 0) {
                    startIndex = i;
                }
                innerCount++;
            } else {
                if (startIndex != -1) {
                    i = startIndex;
                }
                startIndex = -1;
                innerCount = 0;
            }
            if (innerCount == needle.length()) {
                return startIndex;
            }
        }
        return -1;
    }
}
