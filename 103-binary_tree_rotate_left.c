#include "binary_trees.h"

/**
 * binary_tree_rotate_left - Rotates a binary tree to the left
 * @tree: Ptr to the root node of the tree to rotate.
 * Return: Ptr to the new base node after rotation.
 */
binary_tree_t *binary_tree_rotate_left(binary_tree_t *tree)
{
	binary_tree_t *pivot, *temp;

	if (tree == NULL || tree->right == NULL)
		return (NULL);
	pivot = tree->right;
	temp = pivot->left;
	pivot->left = tree;
	tree->right = temp;
	if (temp != NULL)
		temp->parent = tree;
	temp = tree->parent;
	tree->parent = pivot;
	pivot->parent = temp;
	if (temp != NULL)
	{
		if (temp->left == tree)
			temp->left = pivot;
		else
			temp->right = pivot;
	}
	return (pivot);
}
