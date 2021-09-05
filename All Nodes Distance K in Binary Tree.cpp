/*
*
Given the root of a binary tree, the value of a target node target, and an integer k, return an array of the values of all nodes that have a distance k from the target node.

You can return the answer in any order.

 

Example 1:


Input: root = [3,5,1,6,2,0,8,null,null,7,4], target = 5, k = 2
Output: [7,4,1]
Explanation: The nodes that are a distance 2 from the target node (with value 5) have values 7, 4, and 1.
Example 2:

Input: root = [1], target = 1, k = 3
Output: []
 

Constraints:

The number of nodes in the tree is in the range [1, 500].
0 <= Node.val <= 500
All the values Node.val are unique.
target is the value of one of the nodes in the tree.
0 <= k <= 1000
*
*/

Solution :-
  
   void mark_parents(TreeNode *root,unordered_map<TreeNode *,TreeNode *> &mp,TreeNode *target)
    {
        queue<TreeNode *> q;
        q.push(root);
        while(q.empty()!=1)
        {
            TreeNode *x=q.front();
            q.pop();
            if(x->left)
            {
                mp[x->left]=x;
                q.push(x->left);
            }
            if(x->right)
            {
                mp[x->right]=x;
                q.push(x->right);
            }
        }
    }
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        unordered_map<TreeNode *,TreeNode *> mp;
        mark_parents(root,mp,target);
        unordered_map<TreeNode *,bool> visited;
        queue<TreeNode *> q;
        q.push(target);
        visited[target]=1;
        int cur_level=0;
        while(q.empty()!=1)
        {
            int n=q.size();
            if(cur_level==k)
            {
                break;
            }
            cur_level++;
            for(int i=0;i<n;i++)
            {
                TreeNode *x=q.front();
                q.pop();
                if(x->left && visited[x->left]==0)
                {
                    visited[x->left]=1;
                    q.push(x->left);
                }
                if(x->right && visited[x->right]==0)
                {
                    visited[x->right]=1;
                    q.push(x->right);
                }
                if(mp[x]!=NULL && visited[mp[x]]==0)
                {
                    visited[mp[x]]=1;
                    q.push(mp[x]);
                }
            }
        }
        vector<int> ans;
        while(q.empty()!=1)
        {
            ans.push_back(q.front()->val);
            q.pop();
        }
        return ans;
    }
