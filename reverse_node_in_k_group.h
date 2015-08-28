/****************************************************************
Reverse Nodes in k-Group 
 Given a linked list, reverse the nodes of a linked list k at a time and return its modified list.
If the number of nodes is not a multiple of k then left-out nodes in the end should remain as it is.
You may not alter the values in the nodes, only nodes itself may be changed.
Only constant memory is allowed.
For example,
Given this linked list: 1->2->3->4->5
For k = 2, you should return: 2->1->4->3->5
For k = 3, you should return: 3->2->1->4->5 
*************************************************************/

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
    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode dummy(0);
        dummy.next = head;
        ListNode *pre = &dummy;
        ListNode *curr = head;
        int count = 0;
        while(1)
        {
            count = 0;
            while(curr && count<k) { curr = curr->next;count++;}
            if(count == k)
            {
                ListNode *last = reverse(pre,curr);
                last->next = curr;
                pre = last;
            }
            else
              break;
        }
        return dummy.next;
    }
    
    ListNode *reverse(ListNode *pre,ListNode*end)
    {
        ListNode *last = pre->next;
        ListNode *curr = last->next;
        while(curr!=end)
        {
            last->next = curr->next;
            curr->next = pre->next;
            pre->next = curr;
            curr = last->next;
        }
        return last;
    }
};
