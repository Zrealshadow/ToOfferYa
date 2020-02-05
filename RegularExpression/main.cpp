#include <iostream>
#include "RegularMatch.h"
using namespace std;
void T(char * s, char* p);
int main() {
    char *p1="a.a";
    char *p2="ab*ac*a";
    char *p3="aa.a";
    char *p4="ab*a";
    char *p5="a*a";
    char *s="aaa";
    T(s,p1);
    T(s,p2);
    T(s,p3);
    T(s,p4);
    T(s,p5);
    T("aaa","ab*a*c*a");
    T("a",".*");
    T("",".*");


    return 0;
}

void T(char *s, char *p){
    RegularMatch *test=new RegularMatch();
    if(test->match_dp(s,p)) cout<<"true"<<endl;
    else cout<<"false"<<endl;
}