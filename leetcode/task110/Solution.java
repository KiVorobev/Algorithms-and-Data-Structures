package task110;

class Solution {
    public boolean isBalanced(TreeNode root) {
        return height(root) != -1;
    }

    private int height(TreeNode root) {
        if (root == null) return 0;
        int leftDepth = height(root.left);
        if (leftDepth == -1) return -1;
        int rightDepth = height(root.right);
        if (rightDepth == -1) return -1;
        if (rightDepth - leftDepth < -1 || rightDepth-leftDepth > 1) return -1;
        return Math.max(leftDepth, rightDepth) + 1;
    }
}
