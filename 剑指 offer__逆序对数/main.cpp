#include <iostream>
#include <vector>
#include <string>
#include <queue>

using namespace std;

class Solution{
private:
    long long int incorporateTwoVector(vector<int> &v1,vector<int> &v2){
        vector<int> r_v(0);
        int p1=v1.size()-1;
        int p2=v2.size()-1;
        long long int cnt=0;
        while(1){
            if(p1==-1 and p2==-1){
                break;
            }

            if(p1==-1){
                r_v.push_back(v2[p2]);
                p2--;
                continue;
            }

            if(p2==-1){
                r_v.push_back(v1[p1]);
                p1--;
                continue;
            }

            if(v1[p1]<v2[p2]){
                r_v.push_back(v2[p2]);
                p2--;
            }
            else{
                r_v.push_back(v1[p1]);
                cnt+=p2+1;
                p1--;
            }
        }

        vector<int> v (r_v.rbegin(),r_v.rend());
        v1=v;
        return cnt;
    }
public:
    int InversePairs(vector<int> data) {
        vector<vector<int>> q;
        for (int i = 0; i <data.size(); ++i) {
            vector<int> k;
            k.push_back(data[i]);
            q.push_back(k);
        }
        long long int ans=0;
        while(1){
            if(q.size()==1){
                break;
            }
            int k=q.size()/2;
            vector<vector<int>> tmp;
            for(int i=0;i<k;i++){
                vector<int>v1=q[i*2];
                vector<int>v2=q[i*2+1];
                ans+=incorporateTwoVector(v1,v2);
                tmp.push_back(v1);
            }
            if(q.size()%2==1)tmp.push_back(q[q.size()-1]);
            q.swap(tmp);
        }
        return ans%1000000007;
    }

};
void test(){
    vector<int> v{1,2,3,4,5,6,7,0};
    Solution *m=new Solution;
    cout<<m->InversePairs(v)<<endl;
}
int main() {
    test();
//    vector<int> ori{1,2,3,4,5};
//    vector<int> n{16,7,8};
//    ori.swap(n);
//    for(int i=0;i<ori.size();i++){
//        cout<<ori[i]<<" ";
//    }
//    cout<<endl;
//    for(int i=0;i<n.size();i++){
//        cout<<n[i]<<" ";
//    }
    return 0;
}

/*
 *
看到这个题目，我们的第一反应是顺序扫描整个数组。每扫描到一个数组的时候，逐个比较该数字和它后面的数字的大小。如果后面的数字比它小，则这两个数字就组成了一个逆序对。假设数组中含有n个数字。由于每个数字都要和O(n)这个数字比较，因此这个算法的时间复杂度为O(n^2)。
我们以数组{7,5,6,4}为例来分析统计逆序对的过程。每次扫描到一个数字的时候，我们不拿ta和后面的每一个数字作比较，否则时间复杂度就是O(n^2)，因此我们可以考虑先比较两个相邻的数字。

(a) 把长度为4的数组分解成两个长度为2的子数组；
(b) 把长度为2的数组分解成两个成都为1的子数组；
(c) 把长度为1的子数组 合并、排序并统计逆序对 ；
(d) 把长度为2的子数组合并、排序，并统计逆序对；
在上图（a）和（b）中，我们先把数组分解成两个长度为2的子数组，再把这两个子数组分别拆成两个长度为1的子数组。接下来一边合并相邻的子数组，一边统计逆序对的数目。在第一对长度为1的子数组{7}、{5}中7大于5，因此（7,5）组成一个逆序对。同样在第二对长度为1的子数组{6}、{4}中也有逆序对（6,4）。由于我们已经统计了这两对子数组内部的逆序对，因此需要把这两对子数组 排序 如上图（c）所示， 以免在以后的统计过程中再重复统计。
接下来我们统计两个长度为2的子数组子数组之间的逆序对。合并子数组并统计逆序对的过程如下图如下图所示。
我们先用两个指针分别指向两个子数组的末尾，并每次比较两个指针指向的数字。如果第一个子数组中的数字大于第二个数组中的数字，则构成逆序对，并且逆序对的数目等于第二个子数组中剩余数字的个数，如下图（a）和（c）所示。如果第一个数组的数字小于或等于第二个数组中的数字，则不构成逆序对，如图b所示。每一次比较的时候，我们都把较大的数字从后面往前复制到一个辅助数组中，确保 辅助数组（记为copy） 中的数字是递增排序的。在把较大的数字复制到辅助数组之后，把对应的指针向前移动一位，接下来进行下一轮比较。

过程：先把数组分割成子数组，先统计出子数组内部的逆序对的数目，然后再统计出两个相邻子数组之间的逆序对的数目。在统计逆序对的过程中，还需要对数组进行排序。如果对排序算法很熟悉，我们不难发现这个过程实际上就是归并排序。参考代码如下：
 */