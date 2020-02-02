//
// Created by e1ixir on 2020/2/1.
//

#ifndef OFFER_ONETON_H
#define OFFER_ONETON_H
#include <iostream>
#include <string>
#include <vector>
#include "string.h"
using namespace std;
class OneToN {
public:
    int Sum_Solution(int n);
    int bit_add(int num1,int num2);
    int StrToInt(string str);
    bool duplicate(int numbers[],int length,int *duplication);
    vector<int> multiply(const vector<int>& A);
private:
    void swap(int a,int b);
};


#endif //OFFER_ONETON_H
