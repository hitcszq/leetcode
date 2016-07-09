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
//��Ŀ������������ָ������ʱ���뻷����ڵ����Ϊk����ʱ����ָ��ָ���ͷ����ָ��λ�ò��䣬����ָ��ÿ����һ���������������ڵ㡣֤�������Բο� http://stackoverflow.com/questions/2936213/explain-how-finding-cycle-start-node-in-cycle-linked-list-work ��˵�ķǳ���ϸ�ˡ�