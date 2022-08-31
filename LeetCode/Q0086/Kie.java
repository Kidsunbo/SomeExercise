
class ListNode {
    int val;
    ListNode next;

    ListNode() {
    }

    ListNode(int val) {
        this.val = val;
    }

    ListNode(int val, ListNode next) {
        this.val = val;
        this.next = next;
    }
}

class Solution {
    public ListNode partition(ListNode head, int x) {
        if(head == null){
            return null;
        }
        var less = new ListNode();
        var lessHead = less;
        var more = new ListNode();
        var moreHead = more;
        while(head != null){
            if(head.val >= x){
                more.next = new ListNode(head.val);
                more = more.next;
            }else{
                less.next = new ListNode(head.val);
                less = less.next;
            }
            head = head.next;
        }
        less.next = moreHead.next;
        return lessHead.next;
    }
}

public class Kie {
    public static void main(String[] args) {
        var s = new Solution();

    }
}