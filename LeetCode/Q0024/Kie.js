/**
 * Definition for singly-linked list.
 */

function ListNode(val) {
    this.val = val;
    this.next = null;
}
/**
 * @param {ListNode} head
 * @return {ListNode}
 */
var swapPairs = function(head) {
    if(head===null) return null;
    if(head.next===null) return head;
    let first = head;
    let second = head.next;
    let temp = head.next.next;
    second.next=first;
    first.next=swapPairs(temp);
    return second;
};

function create(...t){
    if(t.length===0) return null;
    let head = new ListNode();
    let result = head;
    for(let tt of t){
        head.next=new ListNode(tt);
        head = head.next;
    }
    return result.next;

}

function toString(head){
    let arr = [];
    while(head!==null){
        arr.push(head.val);
        head = head.next;
    }
    return arr.join(",");
}

$(document).ready(function () {
    $("#param").keyup(function () {
        let values = $("#param").val().split(",");
        let head = create(...values);

        $("#output").text(toString(swapPairs(head)));
    })

});