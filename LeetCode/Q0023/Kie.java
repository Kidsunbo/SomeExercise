public class Kie {
    public static void main(String[] args) {
        Solution s = new Solution();
        int[][] a = {{1,2,3},{3,4,5},{4,5,6,7,8},{1}};
        ListNode[] l = create(a);
        s.setL(s.mergeKLists(l));
        System.out.println(s);
    }

    private static ListNode[] create(int[][] a) {
        ListNode[] result = new ListNode[a.length];
        for(int i=0;i<a.length;i++){
            if(a[i].length==0) continue;
            ListNode temp = new ListNode(a[i][0]);
            ListNode head = temp;
            for(int j = 1;j<a[i].length;j++){
                temp.next=new ListNode(a[i][j]);
                temp=temp.next;
            }
            result[i] = head;
        }
        return result;
    }
}

/**
 * Definition for singly-linked list.
 **/
class ListNode {
    int val;
    ListNode next;
    ListNode(int x) { val = x; }
    @Override
    public String toString(){
        ListNode l = this;
        StringBuilder sb = new StringBuilder();
        sb.append("[ ");
        while(l!=null){
            if(l.next==null) {
                sb.append(l.val);
            }
            else {
                sb.append(l.val);
                sb.append(" , ");
            }
            l=l.next;
        }
        sb.append(" ]");
        return sb.toString();
    }
 }

class Solution {
    public ListNode mergeKLists(ListNode[] lists) {
        if(lists.length == 0) return null;
        ListNode result = new ListNode(0);
        for(ListNode i : lists){
            merge2List(result.next,i,result);
        }
        return result.next;
    }

    public void merge2List(ListNode l1, ListNode l2, ListNode result){
        if(l1==null){
            result.next = l2;
            return;
        }
        if(l2==null){
            result.next = l1;
            return;
        }
        if(l1.val<l2.val){
            result.next = new ListNode(l1.val);
            merge2List(l1.next,l2,result.next);
        }
        else {
            result.next = new ListNode(l2.val);
            merge2List(l1,l2.next,result.next);
        }
    }

    private ListNode l;

    public void setL(ListNode l) {
        this.l = l;
    }

    @Override
    public String toString(){
        return l.toString();
    }


}