package task67;

class AnotherSolution {
    public String addBinary(String a, String b) {
        StringBuilder result = new StringBuilder();
        int aIndex = a.length() - 1;
        int bIndex = b.length() - 1;
        int carry = 0;

        while (aIndex >= 0 || bIndex >= 0 || carry != 0) {
            int aBit = (aIndex >= 0) ? a.charAt(aIndex) - '0' : 0;
            int bBit = (aIndex >= 0) ? b.charAt(bIndex) - '0' : 0;
            int sum = aBit + bBit + carry;
            result.append(sum % 2);
            carry = sum / 2;
            aIndex--;
            bIndex--;
        }
        return result.reverse().toString();
    }
}
