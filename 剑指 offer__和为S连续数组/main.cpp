#include <iostream>
#include <vector>
#include "algorithm"
#include "climits"
using namespace std;

class Solution {
public:
    vector<vector<int> > FindContinuousSequence(int sum) {
        int r=2,l=1;
        vector<vector<int>> ans;
        while(l<r and l<=sum/2){
            int s=Sumnumbers(l,r);
            if(s==sum){
                ans.push_back(structvector(l,r));
                r++;
            }
            else if(s>sum) l++;
            else r++;
        }
        return ans;
    }

    // 自己的解法 和为S的两个数字
    vector<int> FindNumbersWithSum_MySolution(vector<int> array,int sum) {
        int len=array.size();
        int r=len-1,l=0;
        vector<int> ans;
        int max=INT_MAX;
        int m;
        while(l<=r){
            m=(r+l)/2;
            int v=array[m];
            if(v*2==sum)break;
            else if(v*2>sum)r=m-1;
            else l=m+1;
        }
        r=m;l=m-1;
        while(l>=0 and r<len){
            int s=array[l]+array[r];
            if(s==sum){
                if(ans.empty()){
                    ans.push_back(array[l]);
                    ans.push_back(array[r]);
                }
                else{
                    ans[0]=array[l];
                    ans[1]=array[r];
                }
                r++;
            }
            else if(s>sum) l--;
            else r++;
        }
        return ans;
    }
    // 和为S的两个数字优化
    vector<int> FindNumbersWithSum(vector<int> array,int sum) {
        int r=array.size(),l=0;
        vector<int> ans;
        while(l<r){
            int v=array[l]+array[r];
            if(sum==v){
                ans.push_back(array[l]);
                ans.push_back(array[r]);
                break;
            }
            else if(v>sum)r--;
            else l++;
        }
        return ans;
    }
private:
    int Sumnumbers(int l,int r){
        int sum=0;
        for(int i=l;i<=r;i++){
            sum+=i;
        }
        return sum;
    }

    vector<int> structvector(int l,int r){
        vector<int> a;
        for(int i=l;i<=r;i++){
            a.push_back(i);
        }
        return a;
    }
};
void display(vector<int> a){
    vector<int> ::iterator it=a.begin();
    for(;it!=a.end();it++){
        cout<<(*it)<<" ";
    }
    cout<<endl;
}
void Test(){
    Solution *m=new Solution;
    vector<vector<int>>ans=m->FindContinuousSequence(100);
    vector<vector<int>>::iterator it=ans.begin();
    for(;it!=ans.end();it++){
        vector<int> s=(*it);
        display(s);
    }
}

void Test1(){
    Solution *m=new Solution;
    vector<int> t{1,2,3,4,5,6,7,8,9};
    vector<int> ans=m->FindNumbersWithSum(t,10);
    display(ans);
}
int main() {
//    Test();
    Test1();
    return 0;
}