/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    bool hasCycle(ListNode *head) {
        std::set<ListNode*> seenNodes;
        while (head != nullptr) {
            if (seenNodes.contains(head)) return true;
            seenNodes.insert(head);
            head = head->next;
        }

        return false;
    }
};
