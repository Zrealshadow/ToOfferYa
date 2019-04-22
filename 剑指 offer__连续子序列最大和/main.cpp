#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Solution {
public:
    int Select_max(int a, int b){
        return a>b?a:b;
    }
    int FindGreatestSumOfSubArray(vector<int> array) {
        int max_res=array[0];
        int sum=array[0];
        for(int i=1;i<array.size();i++){
            sum=Select_max(sum+array[i],array[i]);
            max_res=Select_max(max_res,sum);
        }
        return max_res;
    }
};

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}