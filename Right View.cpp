/*
*
Given the root of a binary tree, imagine yourself standing on the right side of it, return the values of the nodes you can see ordered from top to bottom.

 

Example 1:


Input: root = [1,2,3,null,5,null,4]
Output: [1,3,4]
Example 2:

Input: root = [1,null,3]
Output: [1,3]
Example 3:

Input: root = []
Output: []
 

Constraints:

The number of nodes in the tree is in the range [0, 100].
-100 <= Node.val <= 100
*
*/

Solution :-
  
    vector<int> rightSideView(TreeNode* root) {
        vector<int> ans;
        if(root==NULL)
            return ans;
        queue<TreeNode *> q;
        q.push(root);
        while(q.empty()!=1)
        {
            int n=q.size();
            for(int i=0;i<n;i++)
            {
                TreeNode *x=q.front();
                q.pop();
                if(i==n-1)
                {
                    ans.push_back(x->val);
                }
                if(x->left)
                {
                    q.push(x->left);
                }
                if(x->right)
                {
                    q.push(x->right);
                }
            }
        }
        return ans;
    }
