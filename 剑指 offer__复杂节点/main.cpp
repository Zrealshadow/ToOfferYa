#include <iostream>
#include <vector>
using namespace std;

struct RandomListNode {
    int label;
    struct RandomListNode *next, *random;
    RandomListNode(int x) :
            label(x), next(NULL), random(NULL) {
    }
};

class Solution {
public:
    RandomListNode* Clone(RandomListNode* pHead)
    {
        if(!pHead) return NULL;
        RandomListNode *p=pHead;
        while(p){
            RandomListNode *unit=new RandomListNode(p->label);
            RandomListNode *next_p=p->next;
            unit->next=p->next;
            p->next=unit;
            p=next_p;
        }

        p=pHead;
        while(p){
            RandomListNode *next_p=p->next->next;
            if(p->random){
                p->next->random=p->random->next;
            }

            p=next_p;
        }

        p=pHead;
        RandomListNode * newHead=pHead->next;
        while(p->next){
            RandomListNode *tmp=p->next;
            p->next=tmp->next;
            p=tmp;
        }
        return newHead;

    }

};



int main() {
    int a ,k, *b,*c;
    a=1;
    k=3;
    c=&a;
    b=c;
    cout<<(*b)<<endl;
    c=&k;
    cout<<(*b)<<endl;
    return 0;
}