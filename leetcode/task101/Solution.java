package task101;

import java.util.ArrayDeque;
import java.util.Deque;

class Solution {
    public boolean isSymmetric(TreeNode root) {
        Deque<TreeNode> leftStack = new ArrayDeque<>();
        Deque<TreeNode> rightStack = new ArrayDeque<>();

        TreeNode leftCurrent = root.left;
        TreeNode rightCurrent = root.right;

        while (leftCurrent != null || rightCurrent != null || !leftStack.isEmpty() || !rightStack.isEmpty()) {
            while (leftCurrent != null || rightCurrent != null) {
                if (leftCurrent ==  null || rightCurrent == null) return false;
                leftStack.push(leftCurrent);
                leftCurrent = leftCurrent.left;
                rightStack.push(rightCurrent);
                rightCurrent = rightCurrent.right;
            }
            leftCurrent = leftStack.pop();
            rightCurrent = rightStack.pop();
            if (leftCurrent.val != rightCurrent.val) return false;
            leftCurrent = leftCurrent.right;
            rightCurrent = rightCurrent.left;
        }
        return true;
    }
}
