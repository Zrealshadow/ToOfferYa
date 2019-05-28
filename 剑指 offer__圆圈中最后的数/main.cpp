#include <iostream>
#include <vector>
#include <string>
using namespace std;
struct Node{
    int num;
    Node* next;
    Node* pri;
    Node(int x){
        this->num=x;
        this->next=NULL;
        this->pri=NULL;
    }
};
struct vv{
    int val;
};

class Solution {
public:
    int LastRemaining_Solution(int n, int m)
//    {
//        if(n==0)
//            return -1;
//        if(n==1)
//            return 0;
//        else{
//            return (LastRemaining_Solution(n-1,m)+m)%n;
//        }
//    }
    {
        Node* head;
        Node* tail=new Node(0);
        for(int i=0;i<n;i++){
            Node *p= new Node(i);
            if(i==0){
                head=p;
            }
            p->next=tail->next;
            tail->next=p;
        }
        head->next=tail->next;
        Node *p=head;
        Node *q=tail->next;
        while(q->pri==NULL){
            q->pri=p;
            p=q;
            q=q->next;
        }
        while(head->pri!=head){
            for(int i=0;i<m;i++){
                head=head->pri;
            }
            cout<<head->num<<endl;
            Node *pri=head->pri;
            Node *next=head->next;
            next->pri=pri;
            pri->next=next;
            head=head->pri;
        }
        return head->num;
    }
};
int main() {
    Solution *test=new Solution();

    std::cout << test->LastRemaining_Solution(5,3) << std::endl;
    return 0;
}