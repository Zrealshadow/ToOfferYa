#include <iostream>
#include "OneToN.h"
using namespace std;
int main() {
    OneToN *test=new OneToN();
    int a,b;
    string k;
//    cin>>k;
    vector<int> n={1,2,3,4,5};
    int d=-1;
//    for(unsigned int i=0;i<n.size();i++){
//        cout<<n[i]<<" ";
//    }
//    cout<<endl;
    vector<int> ans=test->multiply(n);
//    for(unsigned int i=0;i<ans.size();i++){
//        cout<<ans[i]<<" ";
//    }
//    cout<<endl;
    return 0;
}