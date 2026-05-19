/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */

struct TreeNode* createNewNode(int val){
    struct TreeNode* node = malloc(sizeof(struct TreeNode));
    node -> val = val;
    node -> left = NULL;
    node -> right = NULL;
    return node;
}
struct TreeNode* buildBST(struct ListNode* tail, struct ListNode* head){
    if(head == tail) return NULL;
    struct ListNode* mid = head;
    struct ListNode* runner = head;

    while(runner != tail && runner->next != tail){
        mid = mid->next;
        runner = runner->next->next;
    }

    struct TreeNode* root = createNewNode(mid->val);
    root->left = buildBST(mid, head);
    root->right = buildBST(tail, mid->next);
    return root;
}
struct TreeNode* sortedListToBST(struct ListNode* head) {
    return buildBST(NULL,head);
}