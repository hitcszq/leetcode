# Definition for singly-linked list.
# class ListNode(object):
#     def __init__(self, x):
#         self.val = x
#         self.next = None

class Solution(object):
    def addTwoNumbers(self, l1, l2):
        """
        :type l1: ListNode
        :type l2: ListNode
        :rtype: ListNode
        """
        start_flag=1
        addflag=0
        sum_head=ListNode(0)
        p=sum_head
        while l1!=None or l2!=None or addflag!=0:
			if start_flag==0:
				p_next=ListNode(0)
				p.next=p_next
				p=p_next
			start_flag=0
			if l1==None and l2!=None:
				p.val=addflag+l2.val
				if p.val>9:
					addflag=1
					p.val=p.val-10
				else:
					addflag=0
				l2=l2.next
				continue
			elif l2==None and l1!=None:
				p.val=addflag+l1.val
				if p.val>9:
					addflag=1
					p.val=p.val-10
				else:
					addflag=0
				l1=l1.next
				continue
			elif l2!=None and l1!=None:
				p.val=addflag+l1.val+l2.val
				if p.val>9:
					addflag=1
					p.val=p.val-10
				else:
					addflag=0
				l1=l1.next
				l2=l2.next
				continue
			else:
			    p.val=1
			    addflag=0
			    
        return sum_head						
		