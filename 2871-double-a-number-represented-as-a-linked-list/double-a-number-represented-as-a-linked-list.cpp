class Solution {
public:
    ListNode* doubleIt(ListNode* head) {
        ListNode* cur = head;
        // reverse the linked list
        ListNode* prev = nullptr;
        ListNode* next = nullptr;
        while(cur != nullptr){
            next = cur->next;
            cur->next = prev;
            prev = cur;
            cur = next;
        }
        // doubleIt
        cur = prev;
        ListNode* newHead = prev;
        int carry = 0;
        while(cur != nullptr){
            int sum = cur->val * 2 + carry;
            cur->val = sum % 10;
            carry = sum / 10;
            if(carry !=0 && cur->next == nullptr){
                ListNode* newnode = new ListNode(0);
                cur->next = newnode;
            }
            cur = cur->next;
        }
        // reverse the linked list
        cur = newHead;
        prev = nullptr;
        next = nullptr;
        while(cur != nullptr){
            next = cur->next;
            cur->next = prev;
            prev = cur;
            cur = next;
        }
        return prev;
    }
};