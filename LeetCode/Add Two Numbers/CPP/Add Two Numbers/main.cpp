//
//  main.cpp
//  Add Two Numbers
//
//  Created by 孙博 on 2017/6/18.
//  Copyright © 2017年 孙博. All rights reserved.
//https://leetcode.com/problems/add-two-numbers/#/description



//Input: (2 -> 4 -> 3) + (5 -> 6 -> 4)
//Output: 7 -> 0 -> 8


#include <iostream>



struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
    };

class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode head(0),*answer;
        int sum=0;
        answer = &head;
        while(l1!=NULL or l2!=NULL){
            if(l1!=NULL){
                sum += l1->val;
                l1=l1->next;
            }
            if(l2!=NULL){
                sum+=l2->val;
                l2=l2->next;
            }
            
            answer->next = new ListNode(sum%10);
            sum /=10;
            answer=answer->next;
            
            
        }
        if(sum!=0){
            answer->next=new ListNode(1);
        }
        return head.next;
    }
    
};

//Assistant
ListNode* toList(int num){
    ListNode* l1,*head;
    auto n = num % 10;
    l1=new ListNode(n);
    head = l1;
    num = int(num/10);
    
    while (num !=0) {
        n = num % 10;
        num = int(num/10);
        l1->next = new ListNode(n);
        l1 = l1->next;
    }
    return head;
}

int main(int argc, const char * argv[]) {
    // insert code here...
    Solution s;
    auto a = toList(9);
    auto b = toList(991);
    auto c = s.addTwoNumbers(a, b);
    
    while(c != NULL){
        std::cout<<c->val<<"--";
        c=c->next;
    }
    
    
    return 0;
}
