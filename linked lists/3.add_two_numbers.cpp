/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        if(l1->next==NULL && l1->val==0)
            return l2;
        if(l2->next==NULL && l2->val==0)
            return l1;
        ListNode*head1=l1,*head2=l2,*t,*s;
        int x=0,rem=0,L1=0,L2=0;
        while(l1){
            l1=l1->next;
            L1++;
        }
        l1=head1;
        // head=l2;
        while(l2){
            l2=l2->next;
            L2++;
        }
        l2=head2;

        if(L1 >= L2){
            // head1=l1;
            while(l2){
                x=(l1->val + l2->val + rem) % 10;
                rem=(l1->val + l2->val + rem) / 10;
                l1->val=x;
                s=l1;
                l1=l1->next;
                l2=l2->next;
            }
            while(rem!=0){
                if(l1==NULL){
                    // t=(ListNode*)malloc(sizeof(ListNode));
                    t=new ListNode;
                    t->val=rem;
                    t->next=NULL;
                    s->next=t;
                    break;
                }
                else{
                    x=(l1->val + rem)%10;
                    rem=(l1->val+rem)/10;
                    l1->val=x;
                    s=l1;
                }
                l1=l1->next;
            }
            return head1;
        }
        else{
            // head=l2;
            while(l1){
                x=(l1->val + l2->val + rem) % 10;
                rem=(l1->val + l2->val + rem) / 10;
                l2->val=x;
                s=l2;
                l1=l1->next;
                l2=l2->next;
            }
            while(rem!=0){
                if(l2==NULL){
                    // t=(ListNode*)malloc(sizeof(ListNode));
                    t=new ListNode;
                    t->val=rem;
                    t->next=NULL;
                    s->next=t;
                    break;
                }
                else{
                    x=(l2->val + rem)%10;
                    rem=(l2->val+rem)/10;
                    l2->val=x;
                    s=l2;
                }
                l2=l2->next;
            }
            return head2;
        }
        // return head;
    }
};