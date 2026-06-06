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
private:
    pair<int, int> f(TreeNode* root) {

        if (root == NULL) return {0, 0};

        if (root->right == NULL && root->left == NULL) return {1, 0};

        pair<int, int> left = f(root->left);
        pair<int, int> right = f(root->right);

        int dia = left.first + right.first;

        return {
            max(left.first, right.first) + 1, 
            max(dia, max(left.second, right.second))
        };
    }
public:
    int diameterOfBinaryTree(TreeNode* root) {
        return f(root).second;
    }
};
