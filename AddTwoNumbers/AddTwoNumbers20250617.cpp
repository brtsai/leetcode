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
        ListNode* solutionHead = nullptr;
        ListNode* solutionTail = nullptr;

        int carry = 0;

        while (l1 != nullptr or l2 != nullptr) {
            int l1Val = 0;
            int l2Val = 0;
            if (l1 != nullptr) {
                l1Val = l1 -> val;
                l1 = l1 -> next;
            }
            if (l2 != nullptr) {
                l2Val = l2->val;
                l2 = l2->next;
            }

            int remainder = (l1Val + l2Val + carry) % 10;
            carry = (l1Val + l2Val + carry) / 10;
            ListNode* newNode = new ListNode(remainder);

            if (solutionTail == nullptr) {
                solutionHead = newNode;
                solutionTail = newNode;
            } else {
                solutionTail -> next = newNode;
                solutionTail = newNode;
            }
        }

        if (carry > 0) {
            solutionTail -> next = new ListNode(carry);
        }

        return solutionHead;
    }
};
