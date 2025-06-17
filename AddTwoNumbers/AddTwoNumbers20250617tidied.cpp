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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* headTracker = new ListNode(0);
        ListNode* tail = headTracker;

        int carry = 0;
        while (l1 or l2 or carry) {
            int sum = (l1? l1 -> val : 0) + (l2? l2 -> val : 0) + carry;
            carry = sum / 10;
            ListNode* newTail = new ListNode(sum % 10);
            tail -> next = newTail;
            tail = newTail;
            l1 = l1 ? l1 -> next : nullptr;
            l2 = l2 ? l2 -> next : nullptr;
        }

        return headTracker -> next;
    }
};
