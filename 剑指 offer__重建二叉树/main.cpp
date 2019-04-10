#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;
struct TreeNode{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x){
        this->val=x;
        this->right=NULL;
        this->left=NULL;
    }
};

//重建二叉树
void structBinaryTree(TreeNode* &head,vector<int> first_list,vector<int> mid_list){
    if(first_list.size()==0){
        head=NULL;
        return;
    }
    if(head==NULL)
        head=new TreeNode(0);
    int value=first_list[0];
    head->val=value;
    vector<int> ::iterator it=find(mid_list.begin(),mid_list.end(),value);
    vector<int> left_mid_list(mid_list.begin(),it);
    vector<int> right_mid_list(it+1,mid_list.end());
    vector<int> left_first_list(first_list.begin()+1,first_list.begin()+left_mid_list.size()+1);
    vector<int> right_first_list(first_list.begin()+left_mid_list.size()+1,first_list.end());
    structBinaryTree(head->right,right_first_list,right_mid_list);
    structBinaryTree(head->left,left_first_list,left_mid_list);
    return ;
}
TreeNode* reConstructBinaryTree(vector<int> pre,vector<int> vin) {
    TreeNode *head=new TreeNode(0);
    structBinaryTree(head,pre,vin);
    return head;
}

/*---------------------------------*/

bool HasSubtreeIteration(TreeNode *pRoot1,TreeNode *pRoot2){
    bool t_ans=true;
    if(pRoot2==NULL)return true;

    if(pRoot1==NULL)return false;

    if(pRoot1->val==pRoot2->val){
        t_ans=t_ans and HasSubtreeIteration(pRoot1->right,pRoot2->right);
        t_ans=t_ans and HasSubtreeIteration(pRoot1->left,pRoot2->left);
        return t_ans;
    }
    else return false;
}

bool findSubtree(TreeNode *pRoot1, TreeNode *pRoot2){
    //the root value is equal begin to iterate
    bool ans=false;
    if(pRoot1->val==pRoot2->val){
        ans=HasSubtreeIteration(pRoot1,pRoot2);
    }

    if(!ans and pRoot1->left!=NULL){
        ans=findSubtree(pRoot1->left,pRoot2);
    }

    if( ! ans and pRoot1->right!=NULL){
        ans=findSubtree(pRoot1->right,pRoot2);
    }

    return ans;
}

//树的子节点
bool HasSubtree(TreeNode *pRoot1,TreeNode *pRoot2){
    //one of them is NULL point
    if((pRoot1==NULL and pRoot2!=NULL) or (pRoot1!=NULL and pRoot2 == NULL)){
        return false;
    }
    // all of them is NULL point , B is A's subtree
    if(pRoot1==NULL and pRoot2==NULL){
        return true;
    }

    //None of them is  NULL point
    return findSubtree(pRoot1,pRoot2);

}


/*—————————————————————二叉树镜像————————————*/

void Mirror(TreeNode *pRoot){
    if(pRoot==NULL)
        return;
    //exchange left and right child
    TreeNode *temp=pRoot->left;
    pRoot->left=pRoot->right;
    pRoot->right=temp;

    //Recursive look up
    Mirror(pRoot->left);
    Mirror(pRoot->right);
    return;
}

/*---------------打印二叉树—-----------------*/



vector<int> PrintFromTopToBottom(TreeNode* root) {
    queue<TreeNode *> re;
    vector<int> res(0);
    if(root==NULL)
        return res;
    re.push(root);
    while(!re.empty()){
        queue<TreeNode*> temp;
        while(!re.empty()){
            TreeNode* q=re.front();
            re.pop();
//            cout<<q->val;
            res.push_back(q->val);
            temp.push(q);

        }
//        cout<<endl;
        while(!temp.empty()){
            TreeNode *q=temp.front();
            temp.pop();
            if(q->left!=NULL) re.push(q->left);
            if(q->right!=NULL) re.push(q->right);
        }
    }
    return res;
}

/*---------------二叉树路径————————————————————*/

class Solution{
public:
    vector<vector<int>>res;
    vector<int> path;
    void find(TreeNode *root,int sum){
        if(root==NULL)return;
        path.push_back(root->val);
        if(root->right==NULL and root->left==NULL and sum==root->val)
            res.push_back(path);
        else{
            if(root->right!=NULL)
                find(root->right,sum-root->val);
            if(root->left!=NULL)
                find(root->left,sum-root->val);
        }
        path.pop_back();
    }
    static bool cmp(const vector<int> & a, const vector<int> & b){
        return a.size()>b.size();
    }

    vector<vector<int>>FindPath(TreeNode *root, int exceptNumber){
        find(root,exceptNumber);
        sort(res.begin(),res.end(),cmp);
        return res;
    }
};


/*-----------------中序遍历-——————————-------------*/

class Solution1{
public:
    TreeNode * pre=NULL;
    TreeNode *ans=NULL;
    TreeNode* Convert(TreeNode *pRootOfTree){
        ConvertSub(pRootOfTree);
        return ans;
    }

    void ConvertSub(TreeNode *pRoot){
        if(pRoot==NULL)return;
        ConvertSub(pRoot->left);
        if(pre==NULL){
            pre=pRoot;
            ans=pre;
        }
        else{
            pre->right=pRoot;
            pRoot->left=pre;
            pre=pRoot;
        }
        ConvertSub(pRoot->right);
        return;
    }
};


/*----------------测试---------------*/
void test(){
    vector<int> tree1_first_list={1,2,4,5,7,8,3,6};
    vector<int> tree1_mid_list={4,2,7,5,8,1,3,6};
    TreeNode *ptree=reConstructBinaryTree(tree1_first_list,tree1_mid_list);

    vector<int> tree2_first_list={3,6};
    vector<int> tree2_mid_list={3,6};
    TreeNode *stree1=reConstructBinaryTree(tree2_first_list,tree2_mid_list);
    cout<<HasSubtree(ptree,stree1)<<endl;

    vector<int> tree3_first_list={2,4,5,7,8};
    vector<int> tree3_mid_list={4,2,7,5,8};
    TreeNode *stree2=reConstructBinaryTree(tree3_first_list,tree3_mid_list);
    cout<<HasSubtree(ptree,stree2)<<endl;


    vector<int> tree4_first_list={5,6,8};
    vector<int> tree4_mid_list={6,5,8};
    TreeNode *stree3=reConstructBinaryTree(tree4_first_list,tree4_mid_list);
    cout<<HasSubtree(ptree,stree3)<<endl;
    cout<<HasSubtree(NULL,NULL)<<endl;
}

void test2(){
    vector<int> tree_first_list={1,2,4,5,7,8,3,6};
    vector<int> tree_mid_list={4,2,7,5,8,1,3,6};
    TreeNode *ptree=reConstructBinaryTree(tree_first_list,tree_mid_list);
    Mirror(ptree);

}

void test3(){
    vector<int> tree_first_list={1,2,4,5,7,8,3,6};
    vector<int> tree_mid_list={4,2,7,5,8,1,3,6};
    TreeNode *ptree=reConstructBinaryTree(tree_first_list,tree_mid_list);
    vector<int> ans=PrintFromTopToBottom(ptree);
}
int main() {
//    test();
//    test2();
//    test3();
    int ** a = new int * [40];
    int *p;
    int b=3;
    p=&b;
    a[0]=p;
    cout<<*a[0]<<endl;
    delete(a);
    return 0;
}