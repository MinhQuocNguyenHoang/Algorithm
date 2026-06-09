/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* partition(ListNode* head, int x) {
        ListNode LessX(0);
        ListNode GreaterX(0);
        
        ListNode *headLess = &LessX;
        ListNode *headGreater = &GreaterX;

        while(head != nullptr){
            if(head->val < x){
                headLess->next = head;
                headLess = headLess->next;
            }
            else{
                headGreater->next = head;
                headGreater = headGreater->next;
            }
            head = head->next;
        }
        headGreater->next = nullptr;
        headLess->next = GreaterX.next;

        return LessX.next;
    }
};