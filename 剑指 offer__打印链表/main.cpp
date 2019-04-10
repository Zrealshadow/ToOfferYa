#include <iostream>
#include <vector>
using namespace std;
struct ListNode{
    int val;
    struct ListNode *next;
    ListNode (int x) {
        this->val=x;
        this->next=NULL;
    }
};

vector<int> printListFromtailTohead(ListNode *head){
    vector<int> ans(0);
    ListNode * p=head;
    while(1){
        if(p==NULL)
            break;
        int k=p->val;
        ans.push_back(k);
        p=p->next;
    }
    vector<int> ans_t(0);
    vector<int>::reverse_iterator it=ans.rbegin();
    for(;it!=ans.rend();it++){
        ans_t.push_back((*it));
    }
    return ans_t;
}
int main() {
    ListNode * head=new ListNode(0);
    head->next=NULL;
    int n;
    cin>>n;
    while(n--){
        int k;
        cin>>k;
        ListNode *p=new ListNode(k);
        p->next=head->next;
        head->next=p;
    }
    vector<int> ans=printListFromtailTohead(head->next);
    vector<int> :: iterator it=ans.begin();
    for(;it!=ans.end();it++){
        cout<<(*it);
    }
    return 0;
}