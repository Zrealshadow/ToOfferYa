#include <iostream>
#include <vector>
using namespace std;
void reOrderArray(vector<int> &array) {
    vector<int> sup(0);
    vector<int> odd_vector(0);
    for(int i=0;i<array.size();i++){
        if(array[i]%2==0){
            sup.push_back(array[i]);
        }
        else{
            odd_vector.push_back(array[i]);
        }
    }
    odd_vector.insert(odd_vector.end(),sup.begin(),sup.end());
    array.assign(odd_vector.begin(),odd_vector.end());
}
int main() {

    return 0;
}