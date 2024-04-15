#include <iostream>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};
 
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
int main(){

    ListNode* l1 = new ListNode(9);
    l1->next = new ListNode(9);
    l1->next->next = new ListNode(9);
    l1->next->next->next = nullptr;
    ListNode* l2 = new ListNode(9);
    l2->next = new ListNode(9);
    l2->next->next = new ListNode(9);
    l2->next->next->next = nullptr;
    Solution sol;
    ListNode* l3 = sol.addTwoNumbers(l1, l2);
    while(l3 != nullptr){
        cout << l3->val << " ";
        l3 = l3->next;
    }
    return 0;
}