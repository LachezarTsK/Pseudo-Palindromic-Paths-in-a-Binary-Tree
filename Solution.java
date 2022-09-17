
public class Solution {

    int numberOfPseudoPalindromicPaths = 0;

    public int pseudoPalindromicPaths(TreeNode root) {
        findNumberOfPseudoPalindromicPaths(root, 0);
        return numberOfPseudoPalindromicPaths;
    }

    private void findNumberOfPseudoPalindromicPaths(TreeNode root, int oddFrequencies) {
        if (root == null) {
            return;
        }

        oddFrequencies = oddFrequencies ^ (1 << root.val);
        if (root.left == null && root.right == null) {
            numberOfPseudoPalindromicPaths += (oddFrequencies & (oddFrequencies - 1)) == 0 ? 1 : 0;
        }

        findNumberOfPseudoPalindromicPaths(root.left, oddFrequencies);
        findNumberOfPseudoPalindromicPaths(root.right, oddFrequencies);
    }
}

/*
Class TreeNode is in-built in the solution file on leetcode.com. 
When running the code on the website, do not include this class.
 */
class TreeNode {

    int val;
    TreeNode left;
    TreeNode right;

    TreeNode() {}

    TreeNode(int val) {
        this.val = val;
    }

    TreeNode(int val, TreeNode left, TreeNode right) {
        this.val = val;
        this.left = left;
        this.right = right;
    }
}
