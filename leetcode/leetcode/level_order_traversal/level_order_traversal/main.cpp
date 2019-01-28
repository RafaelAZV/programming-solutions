#include <iostream>
#include <vector>
#include <queue>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 };

std::vector<std::vector<int> > levelOrder(TreeNode *root){

    std::vector<std::vector<int> > traversal;
    queue<TreeNode *> t_queue;
    TreeNode *current;
    int level = 0;

    if(root == NULL) return traversal;

    t_queue.push(root);

    while(!t_queue.empty()){

        std::vector<int> current_level;
        int level = t_queue.size();

        while(level > 0){
            current = t_queue.front();
            t_queue.pop();

            current_level.push_back(current->val);

            if(current->left != NULL) t_queue.push(current->left);
            if(current->right != NULL) t_queue.push(current->right);
            level--;
        }
        traversal.push_back(current_level);
    }

    return traversal;

}

TreeNode *createNewNode(int data){

    TreeNode *node = (TreeNode*)malloc(sizeof(TreeNode));
    node->val = data;
    node->left = NULL;
    node->right = NULL;

    return node;
}

int main()
{

    TreeNode *root = createNewNode(3);

    root->left = createNewNode(9);
    root->right = createNewNode(20);
    root->right->right = createNewNode(7);
    root->right->left = createNewNode(15);

    levelOrder(root);

    return 0;
}
