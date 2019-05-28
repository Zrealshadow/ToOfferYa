#include <iostream>
#include "vector"
#include "string"
using namespace std;
class Solution {
public:
    bool IsContinuous( vector<int> numbers ) {
        if(numbers.empty())
            return false;
        sort(numbers.begin(),numbers.end());
        vector<int> map(15,0);
        int space=0;
        for(int i=0;i<numbers.size();i++){
            map[numbers[i]]++;
        }
        int ff=0;
        for(int i=1;i<map.size();i++){
            if(map[i]>1){
                return false;
            }
            if(map[i]>0){
                if(ff){
                    space+=i-ff-1;
                }
                ff=i;
            }
        }
        return space==map[0] or space ==0 ?true:false;
    }
};
int main() {
    Solution *k=new Solution();
    vector<int> test={0,0,1,3,5};
    std::cout << k->IsContinuous(test) << std::endl;
    return 0;
}