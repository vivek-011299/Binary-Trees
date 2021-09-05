/*
Given the root of a complete binary tree, return the number of the nodes in the tree.

According to Wikipedia, every level, except possibly the last, is completely filled in a complete binary tree, and all nodes in the last level are as far left as possible. It can have between 1 and 2h nodes inclusive at the last level h.

Design an algorithm that runs in less than O(n) time complexity.

 

Example 1:


Input: root = [1,2,3,4,5,6]
Output: 6
Example 2:

Input: root = []
Output: 0
Example 3:

Input: root = [1]
Output: 1
 

Constraints:

The number of nodes in the tree is in the range [0, 5 * 104].
0 <= Node.val <= 5 * 104
The tree is guaranteed to be complete.
*
*/

Solution :-
  
   int countNodes(TreeNode* root) {
        if(root==NULL)
            return 0;
        int lh=findHeightleft(root);
        int rh=findHeightright(root);
        if(lh==rh)
        {
            return pow(2,lh)-1;
        }
        return 1+countNodes(root->left)+countNodes(root->right); 
    }
    int findHeightleft(TreeNode *node)
    {
        int h=0;
        while(node)
        {
            h++;
            node=node->left;
        }
        return h;
    }
    int findHeightright(TreeNode *node)
    {
        int h=0;
        while(node)
        {
            h++;
            node=node->right;
        }
        return h;
    }
