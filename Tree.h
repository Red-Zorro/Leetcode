#include <cstdlib>

struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

TreeNode *buildTree(int[], int);
void freeTree(TreeNode *);
void printTree(TreeNode *);


