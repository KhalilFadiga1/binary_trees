#include "binary_trees.h"

/**
 * bst_search - Searches for a value in a BST
 * @tree: Ptr to the root node of the to search.
 * @value: Value to search for in the BST.
 * Return: NUll if the tree is empty or the value is not found or else
 * return ptr to the node containing the value
 */
bst_t *bst_search(const bst_t *tree, int value)
{
	if (tree != NULL)
	{
		if (tree->n == value)
			return ((bst_t *)tree);
		if (tree->n > value)
			return (bst_search(tree->left, value));
		return (bst_search(tree->right, value));
	}
	return (NULL);
}
