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
11    ListNode *detectCycle(ListNode *head) {
12        if(!head || !head->next) return NULL;
13
14        ListNode* slow = head;
15        ListNode* fast = head;
16
17        while(fast && fast->next) {
18            slow = slow->next;
19            fast = fast->next->next;
20
21            if(slow == fast) {
22                ListNode* entry = head;
23                while(entry != slow) {
24                    entry = entry->next;
25                    slow = slow->next;
26                 }
27                 return entry;
28            }
29        }
30        return NULL;
31    }
32};