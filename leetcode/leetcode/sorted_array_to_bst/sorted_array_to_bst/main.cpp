#include <iostream>
#include <vector>
#include <math.h>

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

TreeNode *sortedArrayToBSTUtil(TreeNode *root, std::vector<int> nums, int low, int high){

    if(low > high) return NULL;

    int mid = (high + low)/2;

    root = createNewNode(nums[mid]);

    root->left = sortedArrayToBSTUtil(root->left, nums, low, mid - 1);
    root->right = sortedArrayToBSTUtil(root->right, nums, mid + 1, high);

    return root;

}


TreeNode *sortedArrayToBST(std::vector<int>& nums){

    TreeNode *root = NULL;

    if(nums.empty()) return root;
    if(nums.size() == 1) return createNewNode(nums[0]);

    root = sortedArrayToBSTUtil(root, nums, 0, nums.size() - 1);

    return root;

}

int main()
{
    std::vector<int> nums = {-10, -3, 0, 5, 9};
    sortedArrayToBST(nums);
    return 0;
}
