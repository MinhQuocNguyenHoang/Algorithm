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
    int minDepth(TreeNode* root) {
        if (root == nullptr) return 0;

        // Nếu là node lá
        if (root->left == nullptr && root->right == nullptr) {
            return 1;
        }

        // Nếu không có nhánh trái, bắt buộc đi nhánh phải
        if (root->left == nullptr) {
            return 1 + minDepth(root->right);
        }

        // Nếu không có nhánh phải, bắt buộc đi nhánh trái
        if (root->right == nullptr) {
            return 1 + minDepth(root->left);
        }

        // Nếu có đủ 2 nhánh thì lấy nhánh ngắn hơn
        return 1 + min(minDepth(root->left), minDepth(root->right));
    }
};