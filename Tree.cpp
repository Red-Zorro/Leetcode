#include "Tree.h"
#include <queue>
#include <climits>
#include <iostream>

using namespace std;

TreeNode *buildTree(int arr[], int size){
	TreeNode *root = new TreeNode(arr[0]);
	int cnt=1;
	queue<TreeNode*> q;
	q.push(root);
	while(cnt<size){
		TreeNode *node = q.front();
		bool flag = false;
		q.pop();
		if(arr[cnt]!=INT_MIN){
			node->left = new TreeNode(arr[cnt++]);
			flag = true;
		}
		if(arr[cnt]!=INT_MIN){
			node->right = new TreeNode(arr[cnt++]);
			flag = true;
		}
		if(flag)
			q.push(node);
	}
	return root;
}

void freeTree(TreeNode *root){
	if(root->left!=NULL)
		freeTree(root->left);
	if(root->right!=NULL)
		freeTree(root->right);
	delete root;
}

void printTree(TreeNode *root){
	queue<TreeNode*> q;
	q.push(root);
	while(!q.empty()){
		TreeNode *node = q.front();
		q.pop();
		if(node != NULL){
			cout<<node->val<<" ";
			if(node->left!=NULL||node->right!=NULL){
				q.push(node->left);
				q.push(node->right);
			}
		}
		else
			cout<<"NULL ";
	}
	cout<<endl;
}
