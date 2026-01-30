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
17        // Step 1: Split the list into two halves
18        ListNode* slow = head;
19        ListNode* fast = head;
20        ListNode* prev = nullptr;
21
22        while (fast && fast->next) {
23            prev = slow;
24            slow = slow->next;
25            fast = fast->next->next;
26        }
27
28        // Cut the list
29        prev->next = nullptr;
30
31        // Step 2: Sort each half
32        ListNode* l1 = sortList(head);
33        ListNode* l2 = sortList(slow);
34
35        // Step 3: Merge sorted halves
36        return merge(l1, l2);
37    }
38
39private:
40    ListNode* merge(ListNode* l1, ListNode* l2) {
41        ListNode dummy(0);
42        ListNode* tail = &dummy;
43
44        while (l1 && l2) {
45            if (l1->val < l2->val) {
46                tail->next = l1;
47                l1 = l1->next;
48            } else {
49                tail->next = l2;
50                l2 = l2->next;
51            }
52            tail = tail->next;
53        }
54
55        tail->next = l1 ? l1 : l2;
56        return dummy.next;
57    }
58};