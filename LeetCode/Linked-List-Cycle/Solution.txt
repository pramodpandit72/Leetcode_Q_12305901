1/**
2 * Definition for singly-linked list.
3 * struct ListNode {
4 *     int val;
5 *     ListNode *next;
6 *     ListNode(int x) : val(x), next(NULL) {}
7 * };
8 */
9class Solution {
10public:
11    bool hasCycle(ListNode *head) {
12        if(!head || !head->next) return false;
13
14        ListNode* slow = head;
15        ListNode* fast = head;
16
17        while(fast && fast->next) {
18            slow = slow->next;
19            fast = fast->next->next;
20
21            if(slow == fast) return true;
22        }
23        return false;
24    }
25};