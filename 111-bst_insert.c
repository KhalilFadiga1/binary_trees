#include "binary_trees.h"

/**
 * bst_insert - Inserts a value in a Binary Search Tree.
 * @tree: Double ptr to the root node of the insert BST
 * @value: Value of the node to be inserted
 * Return: Ptr to the new node or NULL for failure
 */
bst_t *bst_insert(bst_t **tree, int value)
{
	bst_t *curr, *new;

	if (tree != NULL)
	{
		curr = *tree;
		if (curr == NULL)
		{
			new = binary_tree_node(curr, value);
			if (new == NULL)
				return (NULL);
			return (*tree = new);
		}
		if (value < curr->n) /* Inserting to the left of the BST */
		{
			if (curr->left != NULL)
				return (bst_insert(&curr->left, value));
			new = binary_tree_node(curr, value);
			if (new == NULL)
				return (NULL);
			return (curr->left = new);
		}
		if (value > curr->n) /* Inserting to the right of the BST */
		{
			if (curr->right != NULL)
				return (bst_insert(&curr->right, value));
			new = binary_tree_node(curr, value);
			if (new == NULL)
				return (NULL);
			return (curr->right = new);
		}
	}
	return (NULL);
}
