/*
Given the root of a binary tree, return the level order traversal of its nodes' values. (i.e., from left to right, level by level).
*
*/

Solution :-

   vector<vector<int>> levelOrder(TreeNode* root) {
       
        queue<TreeNode *> q;
        vector<vector<int>> ans;
        vector<int> temp;
         if(root==NULL)
            return ans;
        q.push(root);
        q.push(NULL);
        while(q.size()!=0)
        {
            TreeNode *x = q.front();
            q.pop();
            if(x==NULL)
            {
                ans.push_back(temp);
                temp.resize(0);
                if(q.empty()!=1)
                q.push(NULL);
            }
            else
            {   
                temp.push_back(x->val);
               if(x->left) q.push(x->left);
                if(x->right) q.push(x->right);
            }  
        }
        return ans;
    }
