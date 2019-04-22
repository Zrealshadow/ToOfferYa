#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;
class Solution {
public:
    struct cmp{
        bool operator()(const int &a, const int &b){
            return a>b;
        }
    };
    vector<int> GetLeastNumbers_Solution(vector<int> input, int k) {
        vector<int> result;
        if(k>input.size())return result;
        priority_queue<int,vector<int>,cmp> MinHeap(input.begin(),input.end());

        for(int i=0;i<k;i++){
            int ch=MinHeap.top();
            MinHeap.pop();
            result.push_back(ch);
        }
        return result;
    }
};
int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}