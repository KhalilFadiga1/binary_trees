#include "binary_trees.h"

/**
 * binary_tree_is_root - Checks if a node is a root of a binary tree
 * @node: Ptr to node to check
 * Return: 1 if a node is a root or otherwise 0
 */
int binary_tree_is_root(const binary_tree_t *node)
{
	if (node == NULL || node->parent != NULL)
		return (0);
	return (1);
}
