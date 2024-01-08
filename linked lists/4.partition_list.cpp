/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* partition(struct ListNode* head, int x){
        if(head==NULL || head->next==NULL)
            return head;

        struct ListNode*p=head,*q=head,*Head,*s1,*s2;
        
        if(head->val < x){
            head=head->next;
            Head=s1=p;
            p->next=NULL;
            p=q=head;
        }
        else{
            while(p && p->val >= x){
                q=p;
                p=p->next;
            }
            if(p!=NULL){
            q->next=p->next;
            Head=s1=p;
            p->next=NULL;
            p=q=head;
            }
            else{
                return head;
            }
        }
        
        if(head->val >= x){
            head=head->next;
            s1->next=p;
            p->next=NULL;
            s2=p;
            p=q=head;
        }
        else{
            while(p && p->val < x){
                q=p;
                p=p->next;
            }
            if(p!=NULL){
            q->next=p->next;
            s1->next=p;
            p->next=NULL;
            s2=p;
            p=q=head;
            }
            else{
                Head->next=head;
                return Head;
            }
        }
        p=q=head;

        while(p){
            q=p;
            p=p->next;
            
            if(q->val<x){
                q->next=s1->next;
                s1->next=q;
                s1=q;
            }
            else{
                q->next=s2->next;
                s2->next=q;
                s2=q;
            }
        }

        return Head;
        // if(p->val<x){
        //     p->next=s1->next;
        //     s1->next=p;
        //     return Head;
        // }
        // else{
        //     p->next=s2->next;
        //     s2->next=p;
        //     return Head;
        // }

}