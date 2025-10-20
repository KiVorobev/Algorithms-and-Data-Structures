package task58;

class Solution {
    public int lengthOfLastWord(String s) {
        String trimStr = s.trim();
        String[] words = trimStr.split(" ");
        return words[words.length - 1].length();
    }
}
