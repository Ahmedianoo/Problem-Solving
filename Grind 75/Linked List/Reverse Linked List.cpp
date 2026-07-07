#include <iostream>

using namespace std;


struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};
 

// iterative, T: O(n), M: O(1)
ListNode* reverseList(ListNode* head) {
    ListNode* prev = nullptr,* curr = head;

    while(curr){
        ListNode* temp = curr->next;
        curr->next = prev;
        prev = curr;
        curr = temp;
    }

    return prev;
}

// 1.recursive, T: O(n), M: O(n)
// ListNode* reverseList(ListNode* head) {
//     return reverse(nullptr, head);
// }

// ListNode* reverse(ListNode* prev, ListNode* curr){
//     if(!curr) return nullptr;
//     if(!curr->next) {
//         curr->next = prev;
//         return curr;
//     }
//     ListNode* temp = reverse(curr, curr->next);
//     curr->next = prev;
//     return temp;
// }

// 1.recursive, T: O(n), M: O(n)
// ListNode* reverseList(ListNode* head) {
//     if(!head || !head->next) return head;

//     ListNode* newHead = reverseList(head->next);
    
//     head->next->next = head;
//     head->next = nullptr;
    
//     return newHead;
// }