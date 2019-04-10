#include <iostream>
#include <vector>
using namespace std;
double Power(double base, int exp){
    int thresh=0;
    thresh= exp%2==0?exp/2:(exp-1)/2;
    double ans=base;
    for(int i=1;i<=thresh;i++){
        ans=ans*ans;
    }
    if(exp%2!=1)
        ans=ans*base;

    return ans;

}

void test1(){
    cout<<Power(1.0,10)<<endl;
    cout<<Power(0.0,5)<<endl;
    cout<<Power(1.0,0)<<endl;
    cout<<Power(1.2,5)<<endl;
    cout<<Power(2.0,-1)<<endl;
}
int main() {
    test1();
    return 0;
}