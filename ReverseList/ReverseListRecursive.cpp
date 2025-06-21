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
private:
    ListNode* recReverseList(ListNode* prevNode, ListNode* currNode) {
        if (currNode == nullptr) return prevNode;

        ListNode* nextNode = currNode->next;
        currNode->next = prevNode;
        return recReverseList(/* prevNode= */ currNode, /* currNode= */ nextNode);
    }
public:
    ListNode* reverseList(ListNode* head) {
        if (head == nullptr) return head;
        ListNode* prevNode = head;
        ListNode* currNode = head->next;
        prevNode->next = nullptr;

        return recReverseList(prevNode, currNode);
    }
};
