package task94;

import java.util.*;

class Solution {
    public List<Integer> inorderTraversal(TreeNode root) {
        if (root == null) return Collections.emptyList();
        Deque<TreeNode> stack = new ArrayDeque<>();
        List<Integer> result = new LinkedList<>();
        TreeNode current = root;

        while (current != null || !stack.isEmpty()) {
           while (current != null) {
               stack.push(current);
               current = current.left;
           }
           current = stack.pop();
           result.add(current.val);
           current = current.right;
        }
        return result;
    }
}
