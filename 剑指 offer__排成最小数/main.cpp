#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

class Solution {
public:
    string PrintMinNumber(vector<int> numbers) {
        sort(numbers.begin(),numbers.end(),cmp);
        vector<int> ::iterator it=numbers.begin();
        string ans;
        for(;it!=numbers.end();it++){
            int ch=*it;
            ans+=to_string(ch);
        }
        return ans;
    }

private:
    static bool cmp(int a, int b){
        string ab=to_string(a)+to_string(b);
        string ba=to_string(b)+to_string(a);
        if(ab>ba){
            return false;
        }
        else{
            return true;
        }
    }
};

void test(){
    vector<int> in1={1,3,15,66,51,12};
    vector<int> in2={1,2,3,4,5};
    Solution *m=new Solution;
    cout<<m->PrintMinNumber(in1)<<endl;
    cout<<m->PrintMinNumber(in2)<<endl;
}

int main() {
//    test();
    test2();
    return 0;
}