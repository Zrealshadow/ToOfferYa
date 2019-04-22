#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Solution {
public:
    int MoreThanHalfNum_Solution(vector<int> numbers) {
        int size=numbers.size();
        int count=1;
        int c=numbers[0];
        for(int i=1;i<size;i++){
            if(numbers[i]==c) count++;
            else count--;
            if(count==0){
                c=numbers[i];
                count=1;
            }
        }
        count=0;
        for(int i=0;i<size;i++){
            if(numbers[i]==c)count++;
        }
        if(count*2>size)return c;
        else return 0;
    }
};


int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}