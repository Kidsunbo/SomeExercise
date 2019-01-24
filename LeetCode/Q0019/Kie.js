/**
 * Definition for singly-linked list.
 * function ListNode(val) {
 *     this.val = val;
 *     this.next = null;
 * }
 */
/**
 * @param {ListNode} head
 * @param {number} n
 * @return {ListNode}
 */

function ListNode(val) {
    this.val = val;
    this.next = null;
}


var removeNthFromEnd = function(head, n) {
    if(head===null) return null;
    let max = n+1;
    let i = 0;
    let arr = new Array(max);
    let hand = head;
    let circle = false;
    while(hand!=null){
        arr[i++]=hand;
        if(i===max){
            i=0;
            circle = true;
        }
        hand = hand.next;
    }
    if(circle){
        arr[i].next = arr[(i + 1)%max].next;
    }
    else {
        if(n===1) return null;
        head = arr[1];
    }
    return head;
};

