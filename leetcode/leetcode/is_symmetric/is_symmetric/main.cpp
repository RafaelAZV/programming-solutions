#include <iostream>
#include <vector>
#include <queue>
#include <cmath>

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

bool verify_level(int current_level, int heap_size){
    return pow(2, current_level) == heap_size;
}

bool isSymmetric(TreeNode *root){

    queue<TreeNode*> heap;
    if(root == NULL) return false;

    heap.push(root->left);
    heap.push(root->right);

    while(!heap.empty()){

        //left
        TreeNode *node1 = heap.front();
        heap.pop();

        //right
        TreeNode *node2 = heap.front();
        heap.pop();

        if(node1 == NULL && node2 == NULL) continue;
        if(node1 == NULL || node2 == NULL) return false;
        if(node1->val != node2->val) return false;

        heap.push(node1->left);
        heap.push(node2->right);
        heap.push(node1->right);
        heap.push(node2->left);
    }

    return true;
}


int main(){

    TreeNode *root = createNewNode(1);
    root->left = createNewNode(2);
    root->right = createNewNode(2);

    root->left->left = NULL;
    root->left->right = createNewNode(3);

    root->right->left = NULL;
    root->right->right = createNewNode(3);

    std::cout << isSymmetric(root);

    return 0;
}
