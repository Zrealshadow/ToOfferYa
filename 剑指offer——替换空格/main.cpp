#include<stdio.h>
#include<vector>
#include<iostream>
using namespace std;
bool find(int target,vector<vector<int> >array){
    vector<vector<int>>::iterator it=array.begin();
    for(;it!=array.end();it++){
        vector<int> x=(*it);
        vector<int>::iterator itt=x.begin();
        for(;itt!=x.end();itt++){
            int xx=(*itt);
            if(xx==target)
                return true;
        }
    }
    return false;
}
void replaceSpace(char *str,int length){
    if (str==NULL and length==0)
        return;
    int ori_len=0;//有字符的长度
    int num_black=0;
    for(int i=0;str[i]!='\0';i++){
        if(str[i]==' ')
            num_black++;
        ori_len++;
    }

    int new_len=ori_len+num_black*2;

    if(new_len>length)
        return;

    int indexOfnew=new_len;
    int indexOfori=ori_len;

    while(indexOfnew>-1 || indexOfori>-1){
        if(str[indexOfori]!=' ') {
            str[indexOfnew] = str[indexOfori];
            indexOfnew--;
            indexOfori--;
        }
        else{
            indexOfori--;
            str[indexOfnew--]='0';
            str[indexOfnew--]='2';
            str[indexOfnew--]='%';
            num_black--;
            if(num_black==0)
                return;
        }
    }
}

int main(){
    char str[50];
    cin.getline(str,20);
    replaceSpace(str,20);
    cout<<str<<endl;
}