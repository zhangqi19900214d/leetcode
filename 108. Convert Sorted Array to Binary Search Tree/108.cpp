/*
Given an array where elements are sorted in ascending order, convert it to a height balanced BST.

For this problem, a height-balanced binary tree is defined as a binary tree in which the depth of the two subtrees of every node never differ by more than 1.

Example:

Given the sorted array: [-10,-3,0,5,9],

One possible answer is: [0,-3,9,-10,null,5], which represents the following height balanced BST:

     0
    / \
  -3   9
  /   /
-10  5

*/

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

class Solution {
public:

    void print(TreeNode *root)
    {
        if (root == nullptr) return;
        queue<TreeNode *> q;
        q.push(root);

        while (!q.empty())
        {
            int size = q.size();
            for (int i = 0; i < size; i++)
            {
                auto node = q.front();
                cout << node->val << " ";
                if (node->left != nullptr)
                    q.push(node->left);
                if (node->right != nullptr)
                    q.push(node->right);
                q.pop();
            }
            
            cout << endl;
        }
    }

    TreeNode* sortedArrayToBST(vector<int>& nums, int low, int high)
    {
        //[low, high)

        if (low >= high)
            return nullptr;
        if (high == low + 1)
            return new TreeNode(nums[low]);

        //int mid = (high - low) / 2;
        int mid = low + (high - low) / 2;
        
        auto root = new TreeNode(nums[mid]);
        root->left = this->sortedArrayToBST(nums, low, mid);
        root->right = this->sortedArrayToBST(nums, mid + 1, high);

        return root;
    }

    TreeNode* sortedArrayToBST(vector<int>& nums)
    {
        return this->sortedArrayToBST(nums, 0, nums.size());

        if (nums.size() == 0)
            return nullptr;
        if (nums.size() == 1)
            return new TreeNode(nums[0]);

        int mid = nums.size() / 2;
        cout << mid << endl;

        auto root = new TreeNode(nums[mid]);

        root->left = this->sortedArrayToBST(vector<int>{nums.begin(), nums.begin() + mid});
        root->right = this->sortedArrayToBST(vector<int>{nums.begin() + mid + 1, nums.end()});

        return root;
    }
};

int main()
{
    auto sol = new Solution();
    auto root = sol->sortedArrayToBST(vector<int>{-10, -3, 0, 5, 9});
    sol->print(root);
}