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
13    ListNode* deleteDuplicates(ListNode* head) {
14        ListNode* temp = head;
15
16        while(temp != NULL && temp->next != NULL) {
17            
18            if(temp->val == temp->next->val){
19                ListNode* curr = temp->next;
20                temp->next = curr->next;
21                delete curr;
22            }else{
23                temp = temp->next;
24            }
25
26        }
27        return head;
28    }
29};