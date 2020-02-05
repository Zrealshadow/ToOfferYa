//
// Created by e1ixir on 2020/2/3.
//

#include <cstdlib>
#include "RegularMatch.h"

//回溯法
bool RegularMatch::match(char *str, char *pattern) {
        string s(str);
        string p(pattern);
        return ismatch(s,p);

}

bool RegularMatch::ismatch(string s, string p) {
        if(p.empty()) return s.empty();
        char c1=p[0];
        bool m=s.length()>0 and (c1==s[0] or c1=='.');
        if(p.length()>1 and p[1]=='*'){
            return ismatch(s.substr(0),p.substr(2)) or (m and ismatch(s.substr(1),p.substr(0)));
        }
        else{
            return m and ismatch(s.substr(1),p.substr(1));
        }
}

bool RegularMatch::ori_match(char *str, char *pattern) {
    if(strlen(pattern)<=0) return strlen(str)<=0;
    char c1=pattern[0];
    bool m=strlen(str)>0 and (c1==str[0] or c1=='.');
    if(strlen(pattern)>1 and pattern[1]=='*'){
        return ori_match(str,pattern+2) or (m and ori_match( str+1,pattern));
    }
    else{
        return m and ori_match(str+1,pattern+1);
    }
}

bool RegularMatch::match_dp(char *str, char *pattern) {
    int l= strlen(str);
    int pl=strlen(pattern);
//    vector<bool> *dp=new vector<bool> [l+1];
//    for(unsigned int i=0;i<l;i++){
//        vector<bool> tmp(pl+1, false);
//        dp[i]=tmp;
//    }

    bool **dp=new bool *[pl+5];
    for(unsigned int i=0;i<pl+5;i++){
        dp[i]=new bool [l+1];
    }

    dp[pl][l]=true;

    for(int i=pl;i>=0;i--){//模式串
        for(int j=l;j>=0;j--){//匹配串
            if(i==pl) if(j==l) continue;
            else {
                dp[i][j]=false;
                continue;
            }

            bool m= j!=l and (str[j]==pattern[i] or pattern[i]=='.');

            if(i+1<pl and pattern[i+1]=='*'){
                dp[i][j]= dp[i+2][j] or dp[i][j+1] and m;
            }
            else
                dp[i][j]= m and dp[i+1][j+1];
        }
    }
    bool ans=dp[0][0];

    for(unsigned int i=0;i<l+1;i++){
        delete dp[i];
    }
    delete dp;

    return ans;
}

// Dynamic Programming




