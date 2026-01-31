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
13    ListNode* sortList(ListNode* head) {
14        if (!head || !head->next)
15            return head;
16
17        ListNode* slow = head;
18        ListNode* fast = head;
19        ListNode* prev = nullptr;
20
21        while (fast && fast->next) {
22            prev = slow;
23            slow = slow->next;
24            fast = fast->next->next;
25        }
26
27        prev->next = nullptr;
28
29        ListNode* l1 = sortList(head);
30        ListNode* l2 = sortList(slow);
31
32        return merge(l1, l2);
33    }
34
35private:
36    ListNode* merge(ListNode* l1, ListNode* l2) {
37        ListNode dummy(0);
38        ListNode* tail = &dummy;
39
40        while (l1 && l2) {
41            if (l1->val < l2->val) {
42                tail->next = l1;
43                l1 = l1->next;
44            } else {
45                tail->next = l2;
46                l2 = l2->next;
47            }
48            tail = tail->next;
49        }
50
51        tail->next = l1 ? l1 : l2;
52        return dummy.next;
53    }
54};