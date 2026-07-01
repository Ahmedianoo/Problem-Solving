#include <iostream>
#include <unordered_set>

using namespace std;

struct ListNode{
    int val; 
    ListNode *next;
    ListNode(int x) : val(x), next(nullptr) {}  
};

// space: O(1) 
bool hasCycle(ListNode *head){
    ListNode *slow = head, *fast = head;

    while(fast && fast->next){
        slow = slow->next;
        fast = fast->next->next;  
              
        if(slow == fast) return true;
    }

    return false;
}

// space: O(n) 
// bool hasCycle(ListNode *head) {
//     unordered_set<ListNode*> visited;
//     ListNode* curr = head;

//     while(curr){
//         if(visited.count(curr)) return true;

//         visited.insert(curr);
//         curr = curr->next;
//     }

//     return false;
// }