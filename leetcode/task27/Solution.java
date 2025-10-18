package task27;

class Solution {
    public int removeElement(int[] nums, int val) {
        int[] startNums = new int[nums.length];
        int counter = 0;
        for (int i = 0; i < nums.length; i++) {
            int num = nums[i];
            startNums[i] = num;
            if (num != val) {
                nums[counter] = num;
                counter++;
            }
        }
        return counter;
    }
}