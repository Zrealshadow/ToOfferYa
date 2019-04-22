#include <iostream>
#include <vector>
#include <math.h>
using namespace std;
class Solution {
public:

    int NumberOf1Between1AndN_Solution(int n)
    {
        int sum=0;
        int cnt=1;
        for(int i=1;;i++){
            if(n/pow(10,i-1)<1)break;
            int k=n%own_pow(i);
            int num_pos=n/own_pow(i)*own_pow(i-1)+Select_stage(k,i);
            sum=sum==0?num_pos:sum+num_pos;
        }
        return sum;
    }

private:
    int own_pow(int i){
        return (int)pow(10,i);
    }
    int Select_stage(int k, int i){
        if(k>=2*(pow(10,i-1))-1){
            return own_pow(i-1);
        }
        else if(k<pow(10,i-1)){
            return 0;
        }
        else{
            return k-own_pow(i-1)+1;
        }
    }
};

void test(int c) {
    Solution *test = new Solution;
    int ans = test->NumberOf1Between1AndN_Solution(c);
    cout << ans << endl;
}
int main() {
    test(13);
    return 0;
}