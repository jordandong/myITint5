/*
有k个有序的链表（按照结点的val值升序），请将它们全部合并为一个新的有序的链表。返回合并后链表的头结点。
*/

/*链表结点的定义(请不要在代码中定义该类型)
struct ListNode {
  int val;
  ListNode *next;
};
*/
//lists包含k个链表的头结点,返回合并后链表头结点
ListNode* merge2(ListNode *n1, ListNode *n2){
    if(!n1&&!n2)
        return NULL;
    ListNode *ret = new ListNode();
    ListNode *tmp = ret;
    while(n1&&n2){
        if(n1->val<=n2->val){
            tmp->next = n1;
            n1=n1->next;
        }else{
            tmp->next = n2;
            n2=n2->next;
        }
        tmp=tmp->next;
    }
    if(!n1)
        tmp->next=n2;
    if(!n2)
        tmp->next=n1;
    
    return ret->next;
}

ListNode* merge(vector<ListNode*> &lists) {
    int size = lists.size();
    if(size==0)
        return NULL;
    queue<ListNode*> q;
    for(int i=0; i<size; i++)
        q.push(lists[i]);
    
    while(q.size()>1){
        ListNode *n1 = q.front();
        q.pop();
        ListNode *n2 = q.front();
        q.pop();
        q.push(merge2(n1,n2));
    }
    return q.front();
}
