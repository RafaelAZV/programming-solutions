#include <iostream>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

TreeNode *createNewNode(int data){

    TreeNode *node = (TreeNode*)malloc(sizeof(TreeNode));
    node->val = data;
    node->left = NULL;
    node->right = NULL;

    return node;
}

int kthSmallestUtil(TreeNode *root, bool &flag, bool &found, int &kth, int &auxiliar, int &answer){

    if(root == NULL){
        flag = true;
        return auxiliar;
    }

    auxiliar = kthSmallestUtil(root->left, flag, found, kth, auxiliar, answer);
    if(flag && !found) auxiliar = auxiliar + 1;
    if(flag && auxiliar == kth){
        if(!found) answer = root->val;
        found = true;
        return auxiliar;
    }
    kthSmallestUtil(root->right, flag, found, kth, auxiliar, answer);
}


int kthSmallest(TreeNode *root, int k){

    bool flag = false;
    bool found = false;
    int auxiliar = 0;
    int answer = 0;

    kthSmallestUtil(root, flag, found, k, auxiliar, answer);

    return answer;
}


int main(){

    TreeNode *root = NULL;

    root = createNewNode(5);
    root->left = createNewNode(3);
    root->right = createNewNode(6);
    root->left->right = createNewNode(4);
    root->left->left = createNewNode(2);
    root->left->left->left = createNewNode(1);

    std::cout << kthSmallest(root, 3);

    return 0;
}
