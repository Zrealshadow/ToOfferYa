//
// Created by e1ixir on 2020/2/1.
//

#include "OneToN.h"

void OneToN::swap(int a, int b) {
    int tmp=a;
    a=b;
    b=tmp;
}
// 短路递归 利用&& 进行短路
int OneToN::Sum_Solution(int n) {
    int ret = n;
    n && (ret += Sum_Solution(n-1));
    return ret;
}

int OneToN::bit_add(int num1, int num2) {
    int n1,n2;
    //该位需进位
    n1=(num1&num2)<<1;

    //无进位,相加为一
    n2=num1^num2;
//    return n1==0? n2:bit_add(n1,n2);
    if(n1==0)return n2;
    else return bit_add(n1,n2);
}

int OneToN::StrToInt(string str) {
    int f=1;
    if(str[0]=='-')f=-1;\
    long long int res=0;
    for(int i= (str[0]=='+' or str[0]=='-')?1:0;i<str.size();i++){
        if(str[i]>'9' or str[i]<'0') {
            return 0;
        }
        res=(res<<1)+(res<<3)+(str[i]&0xf);
    }

    return (res*f>INT32_MAX or res*f<INT32_MIN)?0:res*f;
}

bool OneToN::duplicate(int numbers[], int length, int *duplication) {
    int *hash=new int[length+5]{};
//    for(int i=0;i<length+5;i++){
//        hash[i]=-1;
//        cout<<hash[i];
//    }
//    cout<<endl;

    //initial array =[k,0,0,0,0] int *hash=new int [length+5]{k};
    //initial array = [0,0,0,0] int *hash=new int [length+5]();
    for(unsigned int i=0;i<length;i++){
        int hi=numbers[i];
//        cout<<i<<" : "<<hi<<" : "<<hash[hi]<<endl;
        if(hash[hi]==0)
            hash[hi]=i+1;
        else {
//            std::cout<<numbers[i]<<std::endl;
            *duplication=numbers[i];
            return true;
        }
    }
    return false;
}

vector<int> OneToN::multiply(const vector<int> &A) {
    vector<int> b;
    b.push_back(1);
    for (unsigned int i = 0; i < A.size() - 1; i++) {
        int tmp = b[b.size() - 1] * A[i];
        b.push_back(tmp);
    }
    int t = 1;
    for (int i = A.size() - 1; i >= 0; i--) {
        b[i] *= t;
        t *= A[i];
    }
    return b;
}
