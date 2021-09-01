/*
Given the root of a binary tree, return the zigzag level order traversal of its nodes' values. (i.e., from left to right, then right to left for the next level and alternate between).


Example 1:


Input: root = [3,9,20,null,null,15,7]
Output: [[3],[20,9],[15,7]]
Example 2:

Input: root = [1]
Output: [[1]]
Example 3:

Input: root = []
Output: []
 

Constraints:

The number of nodes in the tree is in the range [0, 2000].
-100 <= Node.val <= 100
*
*/

Solution :-
  
  vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<int> temp;
        vector<vector<int>> ans;
        if(root==NULL)
            return ans;
        queue<TreeNode *> q;
        q.push(root);
        q.push(NULL);
        bool flag=0;
        while(q.empty()!=1)
        {
            TreeNode *x=q.front();
            q.pop();
            if(x==NULL)
            {
                if(flag==0)
                ans.push_back(temp);
                else
                {
                    reverse(temp.begin(),temp.end());
                    ans.push_back(temp);
                }
                flag=!flag;
                temp.clear();
                if(q.size()!=0)
                {
                    q.push(NULL);
                }
            }
            else
            {
                temp.push_back(x->val);
             if(x->left)
                    q.push(x->left);
            
             if(x->right)
                    q.push(x->right);
            }   
        }
        return ans;
    }
