/*
对一个单链表原地（in-place）排序。即直接对链表结点排序。返回排序后链表的头结点。

链表结点的定义为（请不要在代码中再次定义该结构）：

C/C++
struct ListNode {
    int val;
    ListNode *next;
}
*/




/*function prototype */  
ListNode* SortedMerge(ListNode* a, ListNode* b);  
void FrontBackSplit(ListNode* source, ListNode** frontRef, ListNode** backRef);  
  
/*sorts the linked list by changing next pointers(not data) */  
void MergeSort(ListNode** headRef)  
{  
    ListNode* head = *headRef;  
    ListNode* a;  
    ListNode* b;  
  
    /*base case-- length 0 or 1 */  
    if((head == NULL) || (head->next == NULL))  
    {  
        return;  
    }  
      
    /*Split head into 'a' and 'b' sublists */  
    FrontBackSplit(head, &a, &b);  
  
    /*Recursively sort the sublists */  
    MergeSort(&a);  
    MergeSort(&b);  
  
    /* answer = merge the two sorted lists together */  
    *headRef = SortedMerge(a, b);  
}  
  
ListNode* SortedMerge(ListNode* a, ListNode* b)  
{  
    ListNode* result = NULL;  
  
    /* Base cases */  
    if(a == NULL)  
        return (b);  
    else if(b == NULL)  
        return (a);  
  
    /* Pick either a or b recur */  
    if(a->val <= b->val)  
    {  
        result = a;  
        result->next = SortedMerge(a->next, b);  
    }  
    else  
    {  
        result = b;  
        result->next = SortedMerge(a, b->next);     
    }  
    return (result);  
}  
  
/* UTILITY FUNCTIONS */  
/* Split the nodes of the given list into front and back halves, 
    and return the two lists using the references parameters. 
    If the length is odd, the extra node shold go in the front list. 
    Uses the fast/slow pointer strategy. */  
void FrontBackSplit(ListNode* source, ListNode** frontRef, ListNode** backRef)  
{  
    ListNode* fast;  
    ListNode* slow;  
  
    if(source == NULL || source->next == NULL)  
    {  
        *frontRef = source;  
        *backRef = NULL;  
    }  
    else  
    {  
        slow = source;  
        fast = source->next;  
  
        /* Advance 'fast' two nodes, and advance 'slow' one node */   
        while(fast != NULL)  
        {  
            fast = fast->next;  
            if( fast != NULL )  
            {  
                slow = slow->next;  
                fast = fast->next;  
            }  
        }  
  
        *frontRef = source;  
        *backRef = slow->next;  
        slow->next = NULL;  
    }  
}   

ListNode* sortLinkList(ListNode *head) {
    MergeSort(&head);
    return head;
}
