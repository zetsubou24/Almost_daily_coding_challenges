
class Solution {
     ListNode list= new ListNode(-1);
    public ListNode addTwoNumbers(ListNode l1, ListNode l2) {
        int carry=0;
        int nodeVal=0;
        int sum=0;
       
    while(l1!=null && l2!=null){
        sum=(l1.val+l2.val+carry);
        nodeVal=sum%10;
        add(list,nodeVal);
        carry=sum/10;
        l1=l1.next;
        l2=l2.next;
    }
    while(l1!=null){
        add(list,(carry+l1.val)%10);
         carry=(carry+l1.val)/10;
        l1=l1.next;
       
    }
    while(l2!=null){
        add(list,(carry+l2.val)%10);
         carry=(carry+l2.val)/10;
        l2=l2.next;
       
    }
        
    if(carry>0) add(list,carry);
        
        return this.list.next;
    }
    
    public void add(ListNode list,int num){
        ListNode temp=list;
        while(temp.next!=null) 
            temp=temp.next;
        temp.next=new ListNode(num);
        
    }
