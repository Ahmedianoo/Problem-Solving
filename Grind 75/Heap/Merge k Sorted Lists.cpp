#include <iostream>
#include <vector>
#include <queue>

using namespace std;


struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

// min-heap solution
// time: O(n * log(k)), space: O(1)
struct Compare{
    bool operator()(ListNode* a, ListNode* b){
        return a->val > b->val;
    }
};

ListNode* mergeKLists(vector<ListNode*>& lists) {
    if(lists.size() == 0) return {};

    priority_queue<ListNode*, vector<ListNode*>, Compare> pq;

    for(ListNode* list : lists){
        if(list) pq.push(list);
    }

    ListNode dummy;
    ListNode* tail = &dummy;

    while(!pq.empty()){
        ListNode* node = pq.top();
        pq.pop();

        if(node->next) pq.push(node->next);

        tail->next = node;
        tail = tail->next;
    }

    return dummy.next;
}

// merge sort solution
// time: O(n * log(k)), space: O(1)
ListNode* mergeKLists(vector<ListNode*>& lists) {
    if(lists.size() == 0) return {};


    while (lists.size() > 1) {

        vector<ListNode*> mergedLists;

        for (int i = 0; i < lists.size(); i += 2) {

            ListNode* l1 = lists[i];

            ListNode* l2 = nullptr;

            if (i + 1 < lists.size())
                l2 = lists[i + 1];

            mergedLists.push_back(
                mergeTwoLists(l1, l2)
            );
        }

        lists = mergedLists;
    }

    return lists[0];
}

ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
    ListNode dummy;
    ListNode* tail = &dummy;

    while(list1 && list2){
        if(list1->val <= list2->val){
            tail->next = list1;
            list1 = list1->next;
        }else{
            tail->next = list2;
            list2 = list2->next;
        }
        tail = tail->next;
    }

    tail->next = list1 ? list1 : list2;

    return dummy.next;
}