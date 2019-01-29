#include <iostream>


/**
 * Definition for singly-linked list.
 **/
 struct ListNode {
     int val;
     ListNode *next;
     ListNode(int x) : val(x), next(NULL) {}
 };

class Solution {
public:
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        if(l1 == nullptr) return l2;
        if(l2 == nullptr) return l1;
        ListNode* result;
        if(l1->val<l2->val) {
            result = new ListNode(l1->val);
            result->next=mergeTwoLists(l1->next,l2);
        }
        else{
            result = new ListNode(l2->val);
            result->next=mergeTwoLists(l1,l2->next);
        }
        return result;

    }
};

template <typename T>
ListNode* create(T a){
    return new ListNode(a);
}

template <typename T,typename... Args>
ListNode* create(T a,Args... args){
    auto l = new ListNode(a);
    l->next= create(args...);
    return l;
}

void print(ListNode* node){
    std::cout<<"[";
    while(node!= nullptr){
        std::cout<<node->val;
        node=node->next;
        if(node!= nullptr) std::cout<<" , ";
    }
    std::cout<<"]"<<std::endl;

}

int main() {
    auto s = Solution();
    auto l1 = create(1,2,3,4,5);
    auto l2 = create(2,2,3,5,6);
    print(s.mergeTwoLists(l1,l2));
    return 0;
}