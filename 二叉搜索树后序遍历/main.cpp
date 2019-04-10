#include <iostream>
#include <vector>
using namespace std;

bool VerifySquenceOfBST(vector<int> sequence) {
    int root=sequence[sequence.size()-1];
    sequence.pop_back();
    if(sequence.empty())
        return true;
    int split_pos;
    for(int i=0;i<sequence.size();i++){
        if(sequence[i]>root)
        {
            split_pos=i;
            break;
        }
    }
    if(i==sequence.size())
        return true;

    for(int i=split_pos;i<sequence.size();i++){
        if(sequence[i]<root)
        {
            return false;
        }
    }

    vector<int> left_sequence(sequence.begin(),sequence.begin()+split_pos);
    vector<int> right_sequence(sequence.begin()+split_pos,sequence.end());
    return VerifySquenceOfBST(left_sequence) and VerifySquenceOfBST(right_sequence);
}
void test(){
    vector<int> a={5,7,6,9,11,10,8};
    vector<int> b={7,4,6,5};
    cout<<VerifySquenceOfBST(a)<<endl<<VerifySquenceOfBST(b)<<endl;
}
int main() {
    test()
    return 0;
}