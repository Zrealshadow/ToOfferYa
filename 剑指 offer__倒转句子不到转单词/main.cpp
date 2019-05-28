#include <iostream>
#include <string>
#include <vector>
using namespace std;
class Solution {
public:
    string ReverseSentence(string str) {
        vector<string> ans(0);
        int ff=0;
        for(int i=0;i<str.size();i++){
            if(str[i]==' '){
                string word=str.substr(i-ff,ff);
                ans.push_back(" "+word);
                ff=-1;
            }
            ff++;
        }
        ans.push_back(str.substr(str.size()-ff,ff));

        string a;
        vector<string>::reverse_iterator it=ans.rbegin();
        for(;it!=ans.rend();it++){
            a+=(*it);
        }
        return a;
    }
};
int main() {
    Solution *m=new Solution();
    cout<<m->ReverseSentence("I am a Student.");
    return 0;
}