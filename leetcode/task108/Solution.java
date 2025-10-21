package task108;

class Solution {
    public TreeNode sortedArrayToBST(int[] nums) {
        int left = 0;
        int right = nums.length - 1;
        return getNode(left, right, nums);
    }

    private TreeNode getNode(int left, int right, int[] nums) {
        if (left > right) return null;
        int mid = left + (right - left) /  2;
        TreeNode node = new TreeNode(nums[mid]);
        node.left = getNode(left, mid - 1, nums);
        node.right = getNode(mid + 1, right, nums);
        return node;
    }
}
