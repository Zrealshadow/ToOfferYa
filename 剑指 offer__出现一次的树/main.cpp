#include <iostream>
#include <vector>
#include <string>
using namespace std;
class Solution {
public:
    void FindNumsAppearOnce(vector<int> data,int &num1,int &num2) {
        unsigned int ans=0;
        vector<int> ::iterator it = data.begin();
        for(;it!=data.end();it++){
            int k=(*it);
            ans=ans^k;
        }
        int pos;
        for(int i=0;;i++){
            if(IsBit(ans,i)==1)
            {
                pos=i;
                break;
            }
        }
        int a=0;
        int b=0;
        for(it=data.begin();it!=data.end();it++){
            int k=(*it);
            if(IsBit(k,pos)==1){
              a=a^k;
            }
            else{
                b=b^k;
            }
        }
        num1=a;
        num2=b;
    }
private:
    bool IsBit(int num,int index){
        num=num>>index;
        return (num&1);
    }
};

void Test(){
    Solution *m=new Solution;
    vector<int> t{10,10,9,9,15,0};
    int num1,num2;
    m->FindNumsAppearOnce(t,num1,num2);
    cout<<(num1)<<endl<<(num2)<<endl;
}
int main() {
    Test();
    return 0;
}