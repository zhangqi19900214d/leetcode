/*
One way to serialize a binary tree is to use pre-order traversal. When we encounter a non-null node, we record the node's value. If it is a null node, we record using a sentinel value such as #.

     _9_
    /   \
   3     2
  / \   / \
 4   1  #  6
/ \ / \   / \
# # # #   # #
For example, the above binary tree can be serialized to the string "9,3,4,#,#,1,#,#,2,#,6,#,#", where # represents a null node.

Given a string of comma separated values, verify whether it is a correct preorder traversal serialization of a binary tree. Find an algorithm without reconstructing the tree.

Each comma separated value in the string must be either an integer or a character '#' representing null pointer.

You may assume that the input format is always valid, for example it could never contain two consecutive commas such as "1,,3".

Example 1:

Input: "9,3,4,#,#,1,#,#,2,#,6,#,#"
Output: true
Example 2:

Input: "1,#"
Output: false
Example 3:

Input: "9,#,#,1"
Output: false
*/

#include <string>
#include <iostream>

using namespace std;

class Solution 
{
public:
    bool isValidSerialization(string preorder)
    {
        if (preorder.size() == 0)
        {
            return true;
        }

        //cout << preorder << endl;

        string leaf_feature = ",#,#";
        size_t pos = preorder.find(leaf_feature);

        while (pos != string::npos)
        {
            if (pos == 0 || preorder[pos - 1] == '#')
            {
                return false;
            }
            
            int end = pos-1;
            while (end >0 && preorder[end] >= '0' && preorder[end] <= '9')
            {
                end--;
            }

            preorder = preorder.substr(0, end) + ",#" + preorder.substr(pos + leaf_feature.size(), string::npos);
            //cout << preorder << endl;
            pos = preorder.find(leaf_feature);
        }
        return preorder == ",#";
    }
};

int main()
{
    auto sol = new Solution();
    cout << sol->isValidSerialization("1,#,#,#,#") << endl;
    cout << sol->isValidSerialization("9,#,92,#,#") << endl;
    cout << sol->isValidSerialization("91,13,14,#,#,10") << endl;
    cout << sol->isValidSerialization("9,3,4,#,#,1,#,#,2,#,6,#,#") << endl;
}