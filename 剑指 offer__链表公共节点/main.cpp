#include <iostream>
using namespace std;

struct ListNode {
	int val;
	struct ListNode *next;
	ListNode(int x) :
			val(x), next(NULL) {
	}
};

class Solution {
private:
    int findlenghtOflist(ListNode *pHead){
        ListNode *p;
        int len=0;
        for(p=pHead;p!=NULL;p=p->next){
            len++;
        }
        return len;
    }
public:
    ListNode* FindFirstCommonNode( ListNode* pHead1, ListNode* pHead2) {
        int l1=findlenghtOflist(pHead1);
        int l2=findlenghtOflist(pHead2);
        ListNode *p1=pHead1;
        ListNode *p2=pHead2;
        int r=abs(l1-l2);
        ListNode *p=l1>l2?p1:p2;
        for(int i=0;i<r;i++){
            p=p->next;
        }
        l1>l2?p1=p:p2=p;
        while(p1!=p2){
            p1=p1->next;
            p2=p2->next;
        }
        return p1;
    }
};

class Solution1{
public:
    ListNode* FindFirstCommonNode( ListNode* pHead1, ListNode* pHead2) {
        ListNode *p1 = pHead1;
        ListNode *p2 = pHead2;
        while(p1!=p2){
            p1 = (p1==NULL ? pHead2 : p1->next);
            p2 = (p2==NULL ? pHead1 : p2->next);
        }
        return p1;
    }
};


int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}