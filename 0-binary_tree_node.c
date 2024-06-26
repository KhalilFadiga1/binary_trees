#include "binary_trees.h"

/**
 * binary_tree_node - Make a Binary Tree Node
 * @parent: A ptr to the Base Node to be created.
 * @value: Node Value
 * Return: Ptr the new node or NULL for an error
 */
binary_tree_t *binary_tree_node(binary_tree_t *parent, int value)
{
	binary_tree_t *new;

	new = malloc(sizeof(binary_tree_t));
	if (new == NULL)
		return (NULL);
	new->n = value;
	new->parent = parent;
	new->left = NULL;
	new->right = NULL;
	return (new);
}
