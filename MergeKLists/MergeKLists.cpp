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
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        ListNode* head = nullptr;
        ListNode* tail = nullptr;

        while(true) {
            bool shouldBreak = true;
            int currMin = 0;

            for (std::vector<ListNode*>::iterator itor = lists.begin(); itor != lists.end(); ++itor) {
                ListNode* curr = *itor;
                if (curr == nullptr) continue;
                int currVal = curr->val;
                if (shouldBreak or currVal < currMin) {
                    currMin = currVal;
                }
                shouldBreak = false;
            }
            if (shouldBreak) break;

            for (std::vector<ListNode*>::iterator itor = lists.begin(); itor != lists.end(); ++itor) {
                ListNode* curr = *itor;
                if (curr == nullptr) continue;
                int currVal = curr->val;
                if (currVal != currMin) continue;

                *itor = curr->next;
                if (head == nullptr) {
                    head = curr;
                    tail = curr;
                } else {
                    tail->next = curr;
                    tail = curr;
                }
            }
        }
        
        if (head == nullptr) return nullptr;

        tail->next = nullptr;
        return head;
    }
};
