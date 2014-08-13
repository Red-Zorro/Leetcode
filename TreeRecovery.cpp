#include "Tree.h"
#include <algorithm>

using namespace std;

class Solution {
private:
	TreeNode *s1, *s2, *pre;
	void traverse(TreeNode *root){
		if(root == NULL)
			return;  
        traverse(root->left);  
        if(pre&& pre->val > root->val)  
        {  
            if(s1==NULL)
				s1=pre, s2=root;  
            else
				s2=root;  
        }  
        pre=root;  
        traverse(root->right); 
	}
public:
    void recoverTree(TreeNode *root) {
        if(root == NULL)
			return;  
        s1=s2=pre=NULL;  
        traverse(root);  
        swap(s1->val,s2->val);
    }
};
