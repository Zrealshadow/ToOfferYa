#include <iostream>
#include <vector>
using  namespace std;
void minNumberInRotateArray(vector<int> rotateArray){
    int low=0;
    int hei=rotateArray.size()-1;
    int mid=low;
    int ans=mid;
    while(rotateArray[low]>=rotateArray[hei]){
        if(hei-low==1){
            ans=rotateArray[hei];
            break;
        }

        mid=(hei+low)/2;
        //三个全部相等要遍历寻找最小值
        if(rotateArray[low]==rotateArray[mid] and rotateArray[mid]==rotateArray[hei]){
            int res=rotateArray[low];
            for(int i=low;i<=hei;i++){
                if(rotateArray[i]<res){
                    res=rotateArray[i];
                }
            }
            ans=res;
            break;
        }
        if(rotateArray[low]<=rotateArray[mid]){
            //mid 在第一个有序列中
            low=mid;
        }
        else if(rotateArray[mid]<=rotateArray[hei]){
            hei=mid;
        }
    }
    cout<<ans<<endl;
}

void test(){
    vector<int> array1={3,4,5,1,2};
    vector<int> array2={3,4,5,1,1,2};
    vector<int> array3={3,4,5,1,2,2};
    vector<int> array4={1,0,1,1,1,1};
    vector<int> array5={1,2,3,4,5};
    vector<int>  array6={2};
    vector<int> array7={1,1,1,1,1};
    minNumberInRotateArray(array1);
    minNumberInRotateArray(array2);
    minNumberInRotateArray(array3);
    minNumberInRotateArray(array4);
    minNumberInRotateArray(array5);
    minNumberInRotateArray(array6);
    minNumberInRotateArray(array7);

}
int main() {
    test();
}

