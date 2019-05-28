#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
    string LeftRotateString(string str, int n) {
        string leftstr;
        string remainstr;
        if(n<str.size()){
            leftstr=str.substr(0,n);
            remainstr=str.substr(n);
//        cout<<leftstr<<endl;
//        cout<<remainstr<<endl;
            return remainstr+leftstr;
        }
      else return str;
    }
};
int main() {
    Solution *k=new Solution;
    cout<<k->LeftRotateString("abcdefASC",3);
    return 0;
}