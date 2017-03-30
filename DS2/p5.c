#include <stdio.h>
#include <stdlib.h>

typedef int element;
typedef struct _TreeNode
{
	element data;
	struct _TreeNode * left;
	struct _TreeNode * right;
} TreeNode;

TreeNode * createTreeNode(void)
{
	TreeNode * node = (TreeNode*)malloc(sizeof(TreeNode));
	node->left = NULL;
	node->right = NULL;
	return node;
}

void setData(TreeNode * node, element data)
{
	node->data = data;
}

element getData(TreeNode * node)
{
	return node->data;
}

void makeLeftSubTree(TreeNode * main, TreeNode * sub)
{
	if (main->left == NULL) {
		main->left = sub;
		return;
	}
	exit(1);
}

void makeRightSubTree(TreeNode * main, TreeNode * sub)
{
	if (main->right == NULL) {
		main->right = sub;
		return;
	}
	exit(1);
}


TreeNode * getLeftSubTree(TreeNode * node)
{
	return node->left;
}
TreeNode * getRightSubTree(TreeNode * node)
{
	return node->right;
}

int main(void) {
	TreeNode * t1 = createTreeNode();
	TreeNode * t2 = createTreeNode();
	TreeNode * t3 = createTreeNode();
	TreeNode * t4 = createTreeNode();
	setData(t1, 1);
	setData(t2, 2);
	setData(t3, 3);
	setData(t4, 4);
	makeLeftSubTree(t1, t2);
	makeRightSubTree(t1, t3);
	makeLeftSubTree(t2, t4);
	printf("%d \n", getData(getLeftSubTree(t1))); //result: 2
	printf("%d \n", getData(getLeftSubTree(getLeftSubTree(t1)))); //result: 4
	return 0;
}
