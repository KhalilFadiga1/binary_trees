#include "binary_trees.h"

/**
 * binary_tree_rotate_right - Rotates a binary tree to the left
 * @tree: Ptr to the root node of the tree to rotate.
 * Return: Ptr to the new base node after rotation.
 */
binary_tree_t *binary_tree_rotate_right(binary_tree_t *tree)
{
	binary_tree_t *pivot, *temp;

	if (tree == NULL || tree->left == NULL)
		return (NULL);
	pivot = tree->left;
	temp = pivot->right;
	pivot->right = tree;
	tree->left = temp;
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
