#include <iostream>
#include <vector>
#include <stack>
using namespace std;
class Solution
{
public:
    void push(int node) {
        stack1.push(node);
    }

    int pop() {
        int ans;
        if(stack2.empty()){
            // 如果stack2 为空，将stack1 中的压入stack2
            while(!stack1.empty()){
                int temp=stack1.top();
                stack2.push(temp);
                stack1.pop();
            }
            ans=stack2.top();
            stack2.pop();
            return ans;
        }
        else{
            ans=stack2.top();
            stack2.pop();
            return ans;
        }
    }
private:
    stack<int> stack1;
    stack<int> stack2;
};

int main() {
    Solution *p=new Solution();
    int k;
    cin>>k;
    while(k!=0){
        int m;

        if(k==1){
            cin>>m;
            p->push(m);
        }
        else {
            int ans = p->pop();
            cout << ans << endl;
        }
        cin>>k;
    }
    return 0;
}