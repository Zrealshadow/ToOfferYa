#include <iostream>
#include <vector>
using namespace std;
struct ListNode{
    int val;
    struct ListNode *next;
    ListNode(int x){
        this->val=x;
        this->next=NULL;
    }
};
ListNode* FindKthToTail(ListNode* pListHead, unsigned int k) {
    ListNode *p=pListHead;
    ListNode *number_k=pListHead;
    int kcnt=k;
    for(;p!=NULL;p=p->next){
        if(kcnt>0){
            kcnt--;
        }
        else{
            number_k=number_k->next;
        }

    }
    return k==0?number_k:NULL;
}


ListNode *ReverseList(ListNode* pHead){
    ListNode *p=pHead;
    ListNode *ans=new ListNode(0);
    for(;p!=NULL;p=p->next){
        ListNode * q=new ListNode(p->val);
        q->next=ans->next;
        ans->next=q;
    }
    return ans->next;
}
ListNode * CreateList(vector<int> array){
    ListNode *head=new ListNode(0);
    for(int i=0;i<array.size();i++){
        ListNode *p=new ListNode(array[i]);
        p->next=head->next;
        head->next=p;
    }
    return head->next;
}

ListNode * Merge(ListNode *pHead1,ListNode *pHead2){
    ListNode *ans=new ListNode(0);
    ListNode *q1=pHead1;
    ListNode *q2=pHead2;
    while(!(q1==NULL and q2==NULL)){
        //比较大小 选择q1
        if(q2==NULL or (q1!=NULL and q2!=NULL and q1->val<q2->val )){
            ListNode *t=new ListNode(q1->val);
            t->next=ans->next;
            ans->next=t;
            q1=q1->next;
        }
        // 选择q2
        else if(q1==NULL or ( q1!=NULL and q2!=NULL and q1->val>=q2->val )){
            ListNode *t = new ListNode(q2->val);
            t->next=ans->next;
            ans->next=t;
            q2=q2->next;
        }
    }

    ListNode *p=ans->next;
    ListNode *re_ans=new ListNode(0);
    for(;p!=NULL;p=p->next){
        ListNode * q=new ListNode(p->val);
        q->next=re_ans->next;
        re_ans->next=q;
    }
    return re_ans->next;
}

void showList(ListNode *phead){
    ListNode *p=phead;
    while(p!=NULL){
        cout<<p->val<<endl;
        p=p->next;
    }
}
void test(){
    vector<int> array={5,4,3,2,1};
    ListNode *pListHead=CreateList(array);
    unsigned int m=1;
    ListNode *ans=FindKthToTail(pListHead,m);
    cout<<ans->val<<endl;
}

void test2(){
    vector <int> array1={19,10,9,5,2};
    vector<int> array2={15,11,10,9,6,3,1};
    ListNode *pHead1=CreateList(array1);
    ListNode *pHead2=CreateList(array2);
    ListNode *ans=Merge(pHead1,pHead2);
    showList(ans);
}

int main() {
    test2();
    return 0;
}