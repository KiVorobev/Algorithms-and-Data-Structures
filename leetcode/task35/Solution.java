package task35;

class Solution {
    public int searchInsert(int[] nums, int target) {
        if (nums.length == 1) {
            if (nums[0] == target || nums[0] > target) return 0;
            else return 1;
        }
        int left = 0;
        int right = nums.length - 1;
        int mid = -1;
        while (left <= right) {
           mid = left + (right - left) / 2;

           if (nums[mid] == target) {
               return mid;
           } else if (nums[mid] < target) {
               left = mid + 1;
           } else {
               right = mid - 1;
           }
        }
        if (nums[mid] > target) return mid;
        else return mid + 1;
    }
}
