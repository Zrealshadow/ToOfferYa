#include <iostream>
#include <vector>
using namespace std;

int NumberOf1(int n){
//    if(n>=0){
//        int cnt=0;
//        while(n!=0){
//            if(n%2==1){
//                cnt++;
//            }
//            n=n/2;
//        }
//        return cnt;
//    }
//    else{
//        int sum=0;
//        int cnt=0;
//        n=n*-1;
//        while(n!=0){
//            if(n%2==1){
//                cnt++;
//            }
//            sum++;
//            n=n/2;
//        }
//        cnt=sum-cnt+1;
//        return cnt;
//    }
    int count = 0;
    int flag = 1;
    while(flag){
        if(n & flag)
            count++;

        flag = flag << 1;
    }
    return count;

}

void test1(){
    cout<<NumberOf1(22)<<endl;
}
void test2(){
    cout<<NumberOf1(16)<<endl;
}
void test3(){
    cout<<NumberOf1(0)<<endl;
}
void test4(){
    cout<<NumberOf1(-33)<<endl;
}
void test5(){
    cout<<NumberOf1(-16)<<endl;
}
int main() {
    test1();
    test2();
    test3();
    test4();
    test5();
    return 0;
}