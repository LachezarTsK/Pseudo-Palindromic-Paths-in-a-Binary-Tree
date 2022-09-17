
using namespace std;

/*
Struct TreeNode is in-built in the solution file on leetcode.com. 
When running the code on the website, do not include this struct.
 */
struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode* left, TreeNode* right) : val(x), left(left), right(right) {}
};

class Solution {
    
    int numberOfPseudoPalindromicPaths = 0;

public:
    int pseudoPalindromicPaths(TreeNode* root) {
        findNumberOfPseudoPalindromicPaths(root, 0);
        return numberOfPseudoPalindromicPaths;
    }

private:
    void findNumberOfPseudoPalindromicPaths(TreeNode* root, int oddFrequencies) {
        if (root == nullptr) {
            return;
        }

        oddFrequencies = oddFrequencies ^ (1 << root->val);
        if (root->left == nullptr && root->right == nullptr) {
            numberOfPseudoPalindromicPaths += (oddFrequencies & (oddFrequencies - 1)) == 0 ? 1 : 0;
        }

        findNumberOfPseudoPalindromicPaths(root->left, oddFrequencies);
        findNumberOfPseudoPalindromicPaths(root->right, oddFrequencies);
    }
};
