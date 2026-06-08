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
    void func(TreeNode* root, int k, priority_queue<int> &pq) {

        if (root == NULL) return;

        if (pq.size() < k) pq.push(root->val);
        else {

            if (root->val < pq.top()) {
                pq.pop();
                pq.push(root->val);
            }
        }

        func(root->left, k, pq);
        func(root->right, k, pq);
    }

public:
    int kthSmallest(TreeNode* root, int k) {
        
        priority_queue<int> max_heap;
        func(root, k, max_heap);

        return max_heap.top();
    }
};
