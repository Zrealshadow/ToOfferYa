//
// Created by e1ixir on 2020/2/3.
//

#ifndef REGULAREXPRESSION_REGULARMATCH_H
#define REGULAREXPRESSION_REGULARMATCH_H

#include <iostream>
#include <string>
#include <vector>


using namespace std;
class RegularMatch {
    bool ismatch(string s,string p);
public:
    bool match(char *str, char *pattern);
    bool ori_match(char *str,char *pattern);
    bool match_dp(char *str,char *pattern);
};


#endif //REGULAREXPRESSION_REGULARMATCH_H
