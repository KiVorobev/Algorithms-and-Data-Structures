package task112;

public class Solution {
    public boolean hasPathSum(TreeNode root, int targetSum) {
        if (root == null) return false;
        return hasPathSum(root, targetSum, 0);
    }

    private boolean hasPathSum(TreeNode node, int targetSum, int prevSum) {
        if (node == null) return false;
        prevSum = prevSum + node.val;
        if (node.left == null && node.right == null) {
            return prevSum == targetSum;
        }
        return hasPathSum(node.left, targetSum, prevSum) || hasPathSum(node.right, targetSum, prevSum);
    }
}
