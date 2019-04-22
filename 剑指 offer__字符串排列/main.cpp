#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;
class Solution {
public:
    vector<string> result;
    vector<string> Permutation(string str) {
        if(str.empty()) return result;
        track_back(str,0);
        sort(result.begin(),result.end(),operater);
        return result;
    }

    void track_back(string str,int pos){
        if(pos==str.size()-1){
            // 回溯到最后一个字母
            if(find(result.begin(),result.end(),str)==result.end())
                result.push_back(str);
        }
        else{
            for(int i=pos;i<str.size();i++){
                swap(str[pos],str[i]);
                track_back(str,pos+1);
                swap(str[pos],str[i]);
            }
        }

    }
private:
    void swap(char & a, char & b){
        char temp=a;
        a=b;
        b=temp;
    }

    static bool operater(const string a, const string b){
        return a<b;
    }


};
int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}