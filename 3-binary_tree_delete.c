#include "binary_trees.h"

/**
 * binary_tree_delete - Remove a binary tree.
 * @tree: Ptr to the root node of the tree to be remove
 */
void binary_tree_delete(binary_tree_t *tree)
{
	if (tree != NULL)
	{
		binary_tree_delete(tree->left);
		binary_tree_delete(tree->right);
		free(tree);
	}
}
