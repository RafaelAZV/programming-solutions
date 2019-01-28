#include <iostream>
#include <vector>
#include <stack>

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


void inorderTraversalUtil(TreeNode *root, std::vector<int> &traversal){

    if(root == NULL) return;

    inorderTraversalUtil(root->left, traversal);
    traversal.push_back(root->val);
    inorderTraversalUtil(root->right, traversal);
}

vector<int> inorderTraversal(TreeNode* root) {

    std::vector<int> traversal;
    inorderTraversalUtil(root, traversal);
    return traversal;
}

std::vector<int> inorderTraversalUtilIterative(TreeNode *root){

    stack<TreeNode *> node_stack;
    std::vector<int> traversal;

    if(root == NULL) return traversal;

    node_stack.push(root);
    TreeNode *crawler = root;

    while(!node_stack.empty()){

        while(crawler != NULL){
            node_stack.push(crawler);
            crawler = crawler->left;
        }

        crawler = node_stack.top();
        node_stack.pop();

        traversal.push_back(crawler->val);

        crawler = crawler->right;
    }

    return traversal;
}


int main(){


    return 0;
}
