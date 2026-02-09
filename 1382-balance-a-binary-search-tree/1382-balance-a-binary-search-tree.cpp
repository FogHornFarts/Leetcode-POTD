/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    void inorder(TreeNode* root, vector<int>& sortedVals) {
        if (root == NULL) return;

        inorder(root->left, sortedVals);     
        sortedVals.push_back(root->val);      
        inorder(root->right, sortedVals);     
    }

    TreeNode* buildBalanced(vector<int>& sortedVals, int start, int end) {
        if (start > end) return NULL;

        int mid = (start + end) / 2;          

        TreeNode* root = new TreeNode(sortedVals[mid]);

        root->left = buildBalanced(sortedVals, start, mid - 1);
        root->right = buildBalanced(sortedVals, mid + 1, end);

        return root;
    }
    TreeNode* balanceBST(TreeNode* root) {
        vector<int> sortedVals;
        inorder(root, sortedVals);
        return buildBalanced(sortedVals, 0, sortedVals.size() - 1);
    }
};
