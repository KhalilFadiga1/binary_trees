#include "binary_trees.h"

/**
 * binary_tree_postorder - Using post-order traversal to loop through
 * binary tree
 * @tree: Ptr to the root node of the tree
 * @func: Ptr to the loop function to be call
 */
void binary_tree_postorder(const binary_tree_t *tree, void (*func)(int))
{
	if (tree && func)
	{
		binary_tree_postorder(tree->left, func);
		binary_tree_postorder(tree->right, func);
		func(tree->n);
	}
}
