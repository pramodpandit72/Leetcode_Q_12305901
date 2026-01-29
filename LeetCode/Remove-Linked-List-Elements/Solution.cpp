1/**
2 * Definition for singly-linked list.
3 * struct ListNode {
4 *     int val;
5 *     ListNode *next;
6 *     ListNode() : val(0), next(nullptr) {}
7 *     ListNode(int x) : val(x), next(nullptr) {}
8 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
9 * };
10 */
11class Solution {
12public:
13    ListNode* removeElements(ListNode* head, int val) {
14
15        while(head != NULL && head->val == val) {
16            ListNode* temp = head;
17            head = head->next;
18            delete temp;
19            // return head;
20        }
21        
22        if(head == NULL) return head;
23
24        ListNode* curr = head;
25        while(curr->next != NULL){
26            if(curr->next->val == val) {
27                ListNode* temp = curr->next;
28                curr->next = temp->next;
29                delete temp;
30            } else {
31                curr = curr->next;
32            }
33        }
34
35        return head;
36    }
37};