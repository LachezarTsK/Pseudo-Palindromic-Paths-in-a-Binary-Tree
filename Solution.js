
/**
 * @param {TreeNode} root
 * @return {number}
 */
var pseudoPalindromicPaths = function (root) {
    this.numberOfPseudoPalindromicPaths = 0;
    findNumberOfPseudoPalindromicPaths(root, 0);
    return this.numberOfPseudoPalindromicPaths;
};

/**
 * @param {TreeNode} root
 * @param {number} oddFrequencies
 * @return {number}
 */
function findNumberOfPseudoPalindromicPaths(root, oddFrequencies) {
    if (root === null) {
        return;
    }

    oddFrequencies = oddFrequencies ^ (1 << root.val);
    if (root.left === null && root.right === null) {
        this.numberOfPseudoPalindromicPaths += (oddFrequencies & (oddFrequencies - 1)) === 0 ? 1 : 0;
    }

    findNumberOfPseudoPalindromicPaths(root.left, oddFrequencies);
    findNumberOfPseudoPalindromicPaths(root.right, oddFrequencies);
}

/*
 Function TreeNode is in-built in the solution file on leetcode.com. 
 When running the code on the website, do not include this function.
 */
function TreeNode(val, left, right) {
    this.val = (val === undefined ? 0 : val);
    this.left = (left === undefined ? null : left);
    this.right = (right === undefined ? null : right);
}
