/*
Given a binary tree and a leaf node called target. Find the minimum time required to burn the complete binary tree if the target is set on fire. It is known that in 1 second all nodes connected to a given node get burned. That is its left child, right child, and parent.


Example 1:

Input:      
          1
        /   \
      2      3
    /  \      \
   4    5      6
       / \      \
      7   8      9
                   \
                   10
Target Node = 8
Output: 7
Explanation: If leaf with the value 
8 is set on fire. 
After 1 sec: 5 is set on fire.
After 2 sec: 2, 7 are set to fire.
After 3 sec: 4, 1 are set to fire.
After 4 sec: 3 is set to fire.
After 5 sec: 6 is set to fire.
After 6 sec: 9 is set to fire.
After 7 sec: 10 is set to fire.
It takes 7s to burn the complete tree.
Example 2:

Input:      
          1
        /   \
      2      3
    /  \      \
   4    5      7
  /    / 
 8    10
Target Node = 10
Output: 5

Your Task:  
You don't need to read input or print anything. Complete the function minTime() which takes the root of the tree and target as input parameters and returns the minimum time required to burn the complete binary tree if the target is set on fire at the 0th second.


Expected Time Complexity: O(N)
Expected Auxiliary Space: O(height of tree)


Constraints:
1 ≤ N ≤ 104
*/

Solution :-
  
  Node* findnode(Node *root,int start)
{
    queue<Node*> q;
    q.push(root);
    while(q.empty()!=1)
    {
        Node *x=q.front();
        q.pop();
        if(x->data==start)
            return x;
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
  void mark_parents(Node *root,unordered_map<Node *,Node*> &mp)
{
    queue<Node*> q;
    q.push(root);
    while(q.empty()!=1)
    {
        Node*x=q.front();
        q.pop();
        if(x->left)
        {
            mp[x->left]=x;
            q.push(x->left);
        }
        if(x->right)
        {
            mp[x->right] = x;
            q.push(x->right);
        }
    }
}
    int minTime(Node* root, int target) 
    {
    Node *tar=findnode(root,target);
    unordered_map<Node*,Node*> mp;
    mark_parents(root,mp);
    unordered_map<Node*,bool> visited;
    queue<Node *> q;
    q.push(tar);
    visited[tar]=true;
    int time=-1;
    while(q.empty()!=1)
    {
        int n=q.size();
        time++;
        for(int i=0;i<n;i++)
        {
            Node *x=q.front();
            q.pop();
            if(x->left && visited[x->left]==false)
            {
                visited[x->left]=true;
                q.push(x->left);
            }
            if(x->right && visited[x->right]==false)
            {
                visited[x->right]=true;
                q.push(x->right);
            }
            if(mp[x] && visited[mp[x]]==false)
            {
                visited[mp[x]]=true;
                q.push(mp[x]);
            }
        }
        
    }
    return time;
    }
