 class Solution {
 public:
     ListNode* detectCycle(ListNode *head)
    {
        if (head == NULL || head->next == NULL)
        {
            return NULL;
        }
    
        ListNode *slow = head, *fast = head;
       while (fast != NULL && fast->next != NULL)
       {
           fast = fast->next->next;
            slow = slow->next;            if (slow == fast)
            {
                 break;
            }
        }
        if (fast == NULL || fast->next == NULL)
         {
             return NULL;
         }
    
        slow = head;
        while (slow != fast)
         {
             slow = slow->next;
             fast = fast->next;
        }
     
         return slow;
     }
 };
//题目分析：当快慢指针相遇时距离环的入口点距离为k，此时让慢指针指向表头，快指针位置不变，快慢指针每次走一步，相遇点就是入口点。证明，可以参考 http://stackoverflow.com/questions/2936213/explain-how-finding-cycle-start-node-in-cycle-linked-list-work ，说的非常详细了。