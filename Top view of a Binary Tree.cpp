/*
*
Given below is a binary tree. The task is to print the top view of binary tree. Top view of a binary tree is the set of nodes visible when the tree is viewed from the top. For the given below tree

       1
    /     \
   2       3
  /  \    /   \
4    5  6   7

Top view will be: 4 2 1 3 7
Note: Return nodes from leftmost node to rightmost node.

Example 1:

Input:
      1
   /    \
  2      3
Output: 2 1 3
Example 2:

Input:
       10
    /      \
  20        30
 /   \    /    \
40   60  90    100
Output: 40 20 10 30 100
Your Task:
Since this is a function problem. You don't have to take input.
Just complete the function topView() that takes root node as parameter and returns a list of nodes visible from the top view from left to right.
Print endline after end of printing the top view.

Expected Time Complexity: O(N)
Expected Auxiliary Space: O(N).

Constraints:
1 ≤ N ≤ 105
1 ≤ Node Data ≤ 105

Note:The Input/Ouput format and Example given are used for system's internal purpose, and should be used by a user for Expected Output only.
As it is a function problem, hence a user should not read any input from stdin/console. The task is to complete the function specified, and not to write the full code.
*
*/

Solution :-
  
   vector<int> topView(Node *root)
    {
        queue<pair<Node *,int>> q;
        vector<int> ans;
        if(root==NULL)
        return ans;
        map<int,Node *> mp;
        q.push({root,0});
        while(q.empty()!=1)
        {
            auto p=q.front();
            q.pop();
            Node *x=p.first;
            int a=p.second;
            if(mp.find(a)==mp.end())                      // This is the only line change in bottom view..
            {
                mp[a]=x;
            }
            if(x->left)
            {
                q.push({x->left,a-1});
            }
            if(x->right)
            {
                q.push({x->right,a+1});
            }
        }
        for(auto it:mp)
        {
            ans.push_back(it.second->data);
        }
        return ans;
    }