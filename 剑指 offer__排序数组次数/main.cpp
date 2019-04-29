#include <iostream>
#include <vector>
using namespace std;
class Solution{
private:
public:
    int GetNumberOfK(vector<int> data ,int k) {
        int ans=biSearch(data,k+0.5)-biSearch(data,k-0.5);
        return ans;
    }
    int biSearch(vector<int>data, double k) {
        int r,l,m;
        r=data.size()-1;
        l=0;
        while(r>=l) {
            m=(r+l)/2;
            if(data[m]<k) {
                l=m+1;
            }
            else{
                r=m-1;
            }
        }
        return l;
    }
};
void test(){
    vector<int> k{3,3,3,3,4,5};
    Solution *m=new Solution;
    cout<<m->GetNumberOfK(k,3);
}
int main() {
    test();
    return 0;
}