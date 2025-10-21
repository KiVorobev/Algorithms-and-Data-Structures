package task111;

class Solution {
    private int minDepth = -1;

    public int minDepth(TreeNode root) {
        goDown(root, 1);
        return minDepth == -1 ? 0 : minDepth;
    }

    private void goDown(TreeNode root, int prevDepth) {
        if (root == null) return;
        if (root.left == null && root.right == null) {
            if (minDepth == -1 || minDepth > prevDepth) minDepth = prevDepth;
            return;
        }
        prevDepth++;
        goDown(root.left, prevDepth);
        goDown(root.right, prevDepth);
    }
}
