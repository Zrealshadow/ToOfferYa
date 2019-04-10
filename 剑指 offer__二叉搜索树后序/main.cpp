#include <iostream>
#include <vector>
using namespace std;




bool dfs(vector<int> sequence){
    if(sequence.empty())
        return true;
    int root=sequence[sequence.size()-1];
    sequence.pop_back();
    if(sequence.empty())
        return true;
    int split_pos;
    int i=0;
    for( i=0;i<sequence.size();i++){
        if(sequence[i]>root)
        {
            split_pos=i;
            break;
        }
    }
    if(i==sequence.size())
        return true;

    for(i=split_pos;i<sequence.size();i++){
        if(sequence[i]<root)
        {
            return false;
        }
    }

    vector<int> left_sequence(sequence.begin(),sequence.begin()+split_pos);
    vector<int> right_sequence(sequence.begin()+split_pos,sequence.end());
    return dfs(left_sequence) and dfs(right_sequence);
}

bool VerifySquenceOfBST(vector<int> sequence) {
    if(sequence.empty())
        return false;
    else
        return dfs(sequence);
}
void test(){
    vector<int> a={5,7,6,9,11,10,8};
    vector<int> b={7,4,6,5};
    vector<int> c={2,3,5,6,10,7,4};
    vector<int> d={2,7,9,5,11,14,12,10};
    cout<<VerifySquenceOfBST(a)<<endl;
    cout<<VerifySquenceOfBST(b)<<endl;
    cout<<VerifySquenceOfBST(c)<<endl;
    cout<<VerifySquenceOfBST(d)<<endl;
}
int main() {
    test();
    return 0;
}