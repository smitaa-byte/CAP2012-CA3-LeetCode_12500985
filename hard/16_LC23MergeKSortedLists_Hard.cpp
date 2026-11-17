
class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {

        priority_queue<ListNode*,
            vector<ListNode*>,
            decltype([](ListNode* a, ListNode* b) {
                return a->val > b->val;
            })> pq;

        for (ListNode* node : lists) {
            if (node != NULL) {
                pq.push(node);
            }
        }

        ListNode dummy(0);
        ListNode* tail = &dummy;

        while (!pq.empty()) {
            ListNode* node = pq.top();
            pq.pop();

            tail->next = node;
            tail = tail->next;

            if (node->next != NULL) {
                pq.push(node->next);
            }
        }

        tail->next = NULL;

        return dummy.next;
    }
};
