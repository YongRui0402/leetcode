class Solution {
public:
    ListNode* removeNodes(ListNode* head) {
        ListNode* cur = head;
        stack<ListNode*> s;
        while(cur != nullptr) {
            while(!s.empty() && s.top()->val < cur->val) {
                s.pop();
            }
            s.push(cur);
            cur = cur->next;
        }
        ListNode* nex = nullptr;
        while(!s.empty()) {
            cur = s.top();
            s.pop();
            cur->next = nex;
            nex = cur;
        }
        return cur;
    }
};