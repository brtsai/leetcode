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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) 
    {
        ListNode* toReturn = NULL;
        ListNode* end = NULL;
        int carry = 0;
        
        int v1 = (l1 == NULL)? 0 : l1 -> val;
        int v2 = (l2 == NULL)? 0 : l2 -> val;
        toReturn = new ListNode((v1 + v2 + carry) % 10);
        carry = (v1 + v2 + carry) / 10;
        end = toReturn;
        l1 = l1 -> next;
        l2 = l2 -> next;
        
        while(l1 != NULL || l2 != NULL)
        {
            int v1 = (l1 == NULL)? 0 : l1 -> val;
            int v2 = (l2 == NULL)? 0 : l2 -> val;
            end -> next = new ListNode((v1 + v2 + carry) % 10);
            carry = (v1 + v2 + carry) / 10;
            end = end -> next;
            if(l1 != NULL)
            {
            l1 = l1 -> next;
            }
            if(l2 != NULL)
            {
            l2 = l2 -> next;
            }
        }
        
        if(carry != 0)
        {
            end -> next = new ListNode(carry);
        }
        
        return toReturn;
    }
};
