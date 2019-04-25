#include <iostream>
#include <vector>
#include <string>
using namespace std;
class Solution {
public:
    struct dict{
        char ch;
        int pos;
        dict(char x, int y){
            this->ch=x;
            this->pos=y;
        }
    };
    int FirstNotRepeatingChar(string str) {
        vector<struct dict> map;
        vector<int> hash(1000,0);
        for(int i=0;i<str.size();i++){
            char ch=str[i];
            if(hash[ch]==0){
                struct dict m=dict(ch,i);
                map.push_back(m);
            }
            hash[ch]++;
        }
        vector<struct dict>::iterator it=map.begin();
        for(;it!= map.end();it++){
            char ch=(*it).ch;
            int pos=(*it).pos;
            if(hash[ch]==1){
                return pos;
            }
        }
        return -1;
    }
};



int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}