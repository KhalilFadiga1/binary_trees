#include "binary_trees.h"

/**
 * binary_tree_depth - Calculate the depth of the binary tree
 * @tree: Ptr to the root node of the tree to measure
 * Return: The depth of the tree or 0 if the tree is NULL
 */
size_t binary_tree_depth(const binary_tree_t *tree)
{
	return ((tree && tree->parent) ? 1 + binary_tree_depth(tree->parent) : 0);
}
