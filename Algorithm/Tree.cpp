#include <iostream>
#include <cstring>
#include<cstdlib>
#include<ctime>
#include <stack>
#include <queue>
using namespace std;

struct TreeNode{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int value) : val(value), left(NULL), right(NULL){}
};

TreeNode* add(int value,TreeNode *root){
    if(root==NULL){
        TreeNode *tmp = new TreeNode(value);
        return tmp;
    }
    if(value < root->val){
        root->left = add(value,root->left);
    }else{
        root->right = add(value,root->right);
    }
    return root;
}

void BFS(TreeNode* root){
    queue<TreeNode*> q;
    q.push(root);
    int val;
    while(!q.empty()){
        TreeNode *data = q.front();
        q.pop();
        cout << data->val << " ";
        if(data->left) q.push(data->left);
        if(data->right) q.push(data->right);
    }
}

void DFS(TreeNode* root){
    stack<TreeNode*> s;
    s.push(root);
    int val;
    while(!s.empty()){
        TreeNode *data = s.top();
        s.pop();
        cout << data->val << " ";
        // **** important 
        if(data->right) s.push(data->right);
        if(data->left) s.push(data->left);
    }
}

void DFS_recursive(TreeNode* root){
    if(root==NULL) return;
    cout << root->val << " ";
    DFS_recursive(root->left);
    DFS_recursive(root->right);
}

void invertTree(TreeNode *root){
    if(root==NULL) return;
    TreeNode *tmp = root->left;
    root->left = root->right;
    root->right = tmp;
    invertTree(root->left);
    invertTree(root->right);
}

int main(){
    TreeNode *myTree = NULL;
    // random element
    srand(time(0)) ;
    int v;
	for(int i=0 ; i<10 ; i++){
        v = rand() % 100;
        myTree = add(v,myTree);
        cout << v << " ";
    }
    cout << endl;
    cout << "BFS : " ; BFS(myTree); cout << endl;
    cout << "DFS : " ; DFS(myTree); cout << endl;
    cout << "DFS_recursive : " ; DFS_recursive(myTree); cout << endl;
    cout << "**** invert tree ****" << endl; invertTree(myTree);
    cout << "BFS : " ; BFS(myTree); cout << endl;
    cout << "DFS : " ; DFS(myTree); cout << endl;
    cout << "DFS_recursive : " ; DFS_recursive(myTree); cout << endl;
    return 0;
}