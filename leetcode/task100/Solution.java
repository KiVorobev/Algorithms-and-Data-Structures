package task100;

import java.util.ArrayDeque;
import java.util.Deque;

class Solution {
    public boolean isSameTree(TreeNode p, TreeNode q) {
        Deque<TreeNode> pStack = new ArrayDeque<>();
        Deque<TreeNode> qStack = new ArrayDeque<>();

        TreeNode pCurrent = p;
        TreeNode qCurrent = q;

        while ((pCurrent != null || !pStack.isEmpty()) || (qCurrent != null || !qStack.isEmpty())) {
            while (pCurrent != null || qCurrent != null) {
                if (pCurrent == null || qCurrent == null) return false;
                pStack.push(pCurrent);
                pCurrent = pCurrent.left;
                qStack.push(qCurrent);
                qCurrent = qCurrent.left;
            }
            pCurrent = pStack.pop();
            qCurrent = qStack.pop();
            if (pCurrent.val != qCurrent.val) return false;
            pCurrent = pCurrent.right;
            qCurrent = qCurrent.right;
        }
        return true;
    }
}
