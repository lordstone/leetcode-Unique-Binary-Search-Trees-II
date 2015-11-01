/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    vector<TreeNode*> generateBT(int start, int end){
        vector<TreeNode*> arr;
        if(start>end){
            TreeNode* tmp = NULL;
            arr.push_back(tmp);
            return arr;
        }
        for(int i = start; i < end + 1; i++){
            vector<TreeNode*> left = generateBT(start, i - 1);
            vector<TreeNode*> right = generateBT(i + 1, end);
            for(auto leftnode: left){
                for(auto rightnode: right){
                    TreeNode* tmp = new TreeNode(i);
                    tmp->left = leftnode;
                    tmp->right = rightnode;
                    arr.push_back(tmp);
                }
            }
        }//end for i
        return arr;
    }

    vector<TreeNode*> generateTrees(int n) {
       return generateBT(1, n);
    }
};
