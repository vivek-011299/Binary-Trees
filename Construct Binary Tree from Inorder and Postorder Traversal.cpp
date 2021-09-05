/*
*
Given two integer arrays inorder and postorder where inorder is the inorder traversal of a binary tree and postorder is the postorder traversal of the same tree, construct and return the binary tree.

 

Example 1:


Input: inorder = [9,3,15,20,7], postorder = [9,15,7,20,3]
Output: [3,9,20,null,null,15,7]
Example 2:

Input: inorder = [-1], postorder = [-1]
Output: [-1]
 

Constraints:

1 <= inorder.length <= 3000
postorder.length == inorder.length
-3000 <= inorder[i], postorder[i] <= 3000
inorder and postorder consist of unique values.
Each value of postorder also appears in inorder.
inorder is guaranteed to be the inorder traversal of the tree.
postorder is guaranteed to be the postorder traversal of the tree.
*/

Solution:-
  
   TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        unordered_map<int,int> mp;
        for(int i=0;i<inorder.size();i++)
        {
            mp[inorder[i]]=i;
        }
        int n=inorder.size();
        TreeNode *root=build(inorder,0,n-1,postorder,0,n-1,mp);
        return root;
    }
    TreeNode *build(vector<int> &inorder,int inStart,int inEnd,vector<int> &postorder,int postStart,int postEnd,unordered_map<int,int> &mp)
    {
        if(inStart>inEnd || postStart>postEnd)
            return NULL;
        TreeNode *root=new TreeNode(postorder[postEnd]);
        int inRoot=mp[root->val];
        int numsOnLeft = inRoot-inStart;
        root->left=build(inorder,inStart,inRoot-1,postorder,postStart,postStart+numsOnLeft-1,mp);
        root->right=build(inorder,inRoot+1,inEnd,postorder,postStart+numsOnLeft,postEnd-1,mp);
        return root;
    } 
