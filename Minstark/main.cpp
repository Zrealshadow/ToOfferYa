#include <iostream>
#include <vector>
#include <stack>
#include <string>
using namespace std;
class Solution {
private:
    stack<int> Minstack;
    stack<int> ans;
public:
    void push(int value) {
        if(this->Minstack.empty() or this->Minstack.top()>=value){
            this->Minstack.push(value);
        }
        this->ans.push(value);

    }
    void pop() {
        if(!this->ans.empty() and !this->Minstack.empty()){
            int c=this->ans.top();
            int min=this->Minstack.top();
            if(c==min)
                this->Minstack.pop();
            this->ans.pop();
        }
    }
    int top() {
        return this->ans.top();

    }
    int min() {
        return this->Minstack.top();
    }

    bool  IsPopOrder(vector<int> pushV,vector<int> popV){
        stack<int> t;
        int i_push=0;
        int i_pop=0;
        while(i_push<=pushV.size() and i_pop<pushV.size()){
            if(t.empty()){
                t.push(pushV[i_push]);
                i_push++;
            }

            if(t.top()==popV[i_pop]){
                t.pop();
                i_pop++;
            }
            else{
                t.push(pushV[i_push]);
                i_push++;
            }
        }

        if(i_pop==pushV.size())
            return true;
        else
            return false;
    }
};
void test1(){
    vector<int> pushV={1,2,3,4,5};
    vector<int> popV={4,5,3,2,1};
    Solution *m=new Solution();
    cout<<m->IsPopOrder(pushV,popV)<<endl;
}
void test2(){
    vector<int> pushV={1,2,3,4,5};
    vector<int> popV={4,3,5,1,2};
    Solution *m=new Solution();
    cout<<m->IsPopOrder(pushV,popV)<<endl;
}
int main() {
    test1();
    test2();
    return 0;
}
