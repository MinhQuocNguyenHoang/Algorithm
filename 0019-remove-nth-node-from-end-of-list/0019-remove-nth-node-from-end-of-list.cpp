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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* fast = head;
        ListNode* slow = head;

        // fast đi trước n bước
        for (int i = 0; i < n; i++) {
            fast = fast->next;
        }

        // Nếu xóa node đầu tiên
        if (fast == nullptr) {
            return head->next;
        }

        // Cùng di chuyển
        while (fast->next != nullptr) {
            fast = fast->next;
            slow = slow->next;
        }

        // Xóa node thứ n từ cuối
        slow->next = slow->next->next;

        return head;
    }
};