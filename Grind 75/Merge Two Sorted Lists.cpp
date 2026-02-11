#include <iostream>
#include <vector>
#include <unordered_map>


using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
 };

ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
    // first i will create two indexes, i, j
    // through a while loop
    // will hold one index of them and compare it 
    // the smaller one will be added to our new list, and preceeding to the one after it in the same list
    ListNode dummy;
    ListNode* tail = &dummy;
    // it is better to use stack here, you do not need that dummy anymore
    // avoiding special-case handling for the first node


    while(list1 && list2){
        if(list1->val <= list2->val){ // = for stability
            tail->next = list1;
            list1 = list1->next;
        }else{
            tail->next = list2;
            list2 = list2->next;
        }
        tail = tail->next;
    }
    // if(list1){
    //     tail->next = list1;
    // } else if(list2){
    //     tail->next = list2;
    // }
    tail->next = list1 ? list1 : list2; // it will assign reduntant null of the initial lists are empty

    return dummy.next;
  
}


// time: O(n + m), memory: O(1)