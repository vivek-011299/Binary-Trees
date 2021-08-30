/*
*
Given the root of a binary tree, return the bottom-up level order traversal of its nodes' values. (i.e., from left to right, level by level from leaf to root).


Given the root of a binary tree, return the bottom-up level order traversal of its nodes' values. (i.e., from left to right, level by level from leaf to root).


Input: root = [3,9,20,null,null,15,7]
Output: [[15,7],[9,20],[3]]
Example 2:

Input: root = [1]
Output: [[1]]
Example 3:

Input: root = []
Output: []

*
*/


Solution :-

 vector<vector<int>> levelOrderBottom(TreeNode* root) {
        vector<vector<int>> ans;
        if(root==NULL)
            return ans;
        vector<int> temp;
        queue<TreeNode *> q;
        q.push(root);
        q.push(NULL);
        while(q.empty()!=1)
        {
            TreeNode *x=q.front();
            q.pop();
            if(x==NULL)
            {
                ans.push_back(temp);
                temp.clear();
                if(q.size()!=0)
                {
                    q.push(NULL);
                }
            }
                else 
                {
                    temp.push_back(x->val);
                    if(x->left) q.push(x->left);
                    if(x->right) q.push(x->right);
                }
            }
        reverse(ans.begin(),ans.end());
        return ans;
    }
 
