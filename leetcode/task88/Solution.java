package task88;

public class Solution {
    public void merge(int[] nums1, int m, int[] nums2, int n) {
        if (n == 0) return;

        int[] savedNums1 = new int[m];
        for (int i = 0; i < m; i++) {
            savedNums1[i] = nums1[i];
        }

        int idx1 = 0;
        int idx2 = 0;

        while (idx1 < m || idx2 < n) {
            if (idx1 == m || idx2 < n && nums2[idx2] < savedNums1[idx1]) {
                nums1[idx1 + idx2] = nums2[idx2];
                idx2++;
            } else {
                nums1[idx1 + idx2] = savedNums1[idx1];
                idx1++;
            }
        }
    }
}
