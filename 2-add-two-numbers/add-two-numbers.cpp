class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* l3 = new ListNode();
        ListNode** node=&l3;
        int sum = 0;
        while(l1 != nullptr || l2 != nullptr || sum > 0){
            if(l1 != nullptr){
                sum += l1->val;
                l1 = l1->next;
            }
            if(l2 != nullptr){
                sum += l2->val;
                l2 = l2->next;
            }
            (*node) = new ListNode(sum % 10);
            sum /= 10;
            node = &((*node)->next);
        }
        return l3;
    }
};