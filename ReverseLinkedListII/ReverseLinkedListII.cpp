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
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        if (left == right) return head;
        ListNode* currNode = head;
        int index = 1;
        ListNode* tail1 = nullptr;
        while (index < left) {
            tail1 = currNode;
            currNode = currNode->next;
            ++index;
        }

        ListNode* reverseTail = currNode;

        ListNode* prevNode = nullptr;
        ListNode* nextNode = currNode->next;
        for (int i = 0; i < right - left + 1; ++i) {
            currNode->next = prevNode;
            prevNode = currNode;
            currNode = nextNode;
            if (nextNode != nullptr) nextNode = nextNode->next;
        }
        reverseTail->next = currNode;
        if (left == 1) return prevNode;

        tail1->next = prevNode;
        return head;
    }
};
