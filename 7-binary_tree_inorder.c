#include "binary_trees.h"

/**
 * binary_tree_inorder - Using in-order traversal to loop through
 * binary tree
 * @tree: Ptr to the root node of the tree
 * @func: Ptr to the loop function to be call
 */
void binary_tree_inorder(const binary_tree_t *tree, void (*func)(int))
{
	if (tree && func)
	{
		binary_tree_inorder(tree->left, func);
		func(tree->n);
		binary_tree_inorder(tree->right, func);
	}
}
