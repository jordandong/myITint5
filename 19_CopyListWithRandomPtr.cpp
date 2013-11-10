/*
给定一个单链表，链表除了包含next指针外，还包含一个random指针，该指针指向链表中某个结点。

请复制链表到一个新的链表，random指针需要指向新链表中对应的结点。比如原链表某个结点random指针指向第2个结点，那么新结点的random指针也要指向到新链表的第2个结点。

提示：此题存在空间复杂度O(1)的算法，不需要使用任何额外辅助空间。请不要改变原链表的结构。
*/

/**
链表结点的定义(请不要在代码中定义该类型)
struct ListNode {
    ListNode *next;
    ListNode *random;
};
*/
// 返回复制的新链表头结点
ListNode* copyListWithRandomPtr(ListNode *head) {
    if(!head)
        return NULL;
    
    ListNode *new_head = NULL;;
    ListNode *o_head = head;
    //insert dup next
    while(o_head){
        ListNode *tmp = o_head->next;
        o_head->next = new ListNode();
        o_head->next->next = tmp;
        o_head = tmp;
    }
    //dup random
    o_head = head;
    new_head =  head->next;
    while(o_head){
        o_head->next->random = o_head->random?o_head->random->next:NULL;
        o_head = o_head->next->next;;
    }
    
    //restore
    o_head = head;
    while(o_head){
        ListNode* tmp = o_head->next;
        o_head->next = tmp->next;
        if(tmp->next)
            tmp->next = tmp->next->next;
        o_head = o_head->next;
    }
    
    return new_head;
}
