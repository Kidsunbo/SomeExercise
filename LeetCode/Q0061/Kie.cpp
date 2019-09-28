#include <iostream>

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

struct ListNode {
    int val;
    ListNode *next;

    ListNode(int x) : val(x), next(NULL) {}
};

// Time 80.03%  Memory 97.62%
class Solution {
public:
    ListNode* rotateRight(ListNode* head, int k) {
        if(head==NULL) return head;
        int length = 1;
        auto last = head;
        while(last->next!=NULL){
            length++;
            last=last->next;
        }

        if(k%length==0) return head;
        last->next=head;
        for(int i = 0;i<length-k%length-1;i++){
            head=head->next;
        }
        auto result = head->next;
        head->next=NULL;
        return result;
    }
};

int main() {
    auto s = Solution();
    s.rotateRight(nullptr,10);
    return 0;
}