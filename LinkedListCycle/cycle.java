public class Solution {
    public ListNode detectCycle(ListNode head) {
       ListNode slow=head,fast=head,entrance=head;
        int flag=1;
        if(head==null) return null;
        while(slow!=fast || flag==1)
        {
            if(fast.next==null||fast.next.next==null) return null;
            slow=slow.next;
            fast=fast.next.next;
            flag=0;
        }
        while(slow!=entrance)
        {
            slow=slow.next;
            entrance=entrance.next;
        }
        return entrance;
}}
