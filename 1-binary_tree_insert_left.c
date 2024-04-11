#include "binary_trees.h"

/**
 * binary_tree_insert_left - Inserts left-child node of another in a binary tree.
 * @parent: Ptr to Node to insert left-child node in.
 * @value: New Node Value
 * Return: Ptr to the New Node.
 * 	if parent is empty or an error occurs - NULL
 */
binary_tree_t *binary_tree_insert_left(binary_tree_t *parent, int value)
{
	binary_tree_t *new;

	if (parent == NULL)
		return (NULL);
	new = binary_tree_node(parent, value);
	if (new == NULL)
		return (NULL);
	if (parent->left != NULL)
	{
		new->left = parent->left;
		parent->left->parent = new;
	}
	parent->left = new;
	return (new);
}
