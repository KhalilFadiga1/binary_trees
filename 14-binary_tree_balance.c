#include "binary_trees.h"

/**
 * binary_tree_height - Calculate binary tree height.
 * @tree: Ptr to the base node of the tree to measure its height
 * Return: 0 for empty tree or 1 for successful measuring
 */
size_t binary_tree_height(const binary_tree_t *tree)
{
	if (tree)
	{
		size_t l = 0, r = 0;

		l = tree->left ? 1 + binary_tree_height(tree->left) : 0;
		r = tree->right ? 1 + binary_tree_height(tree->right) : 0;
		return ((l > r) ? l : r);
	}
	return (0);
}

/**
 * binary_tree_balance - Measures the balance factor of a binary tree
 * @tree: Ptr to base node of the tree
 * Return: Balance factor of the tree or NULL if the tree is empty
 */
int binary_tree_balance(const binary_tree_t *tree)
{
	if (tree)
		return (binary_tree_height(tree->left) - binary_tree_height(tree->right));
	return (0);
}
