#include "binary_trees.h"

/**
 * array_to_bst - Create a BST from an array.
 * @array: Ptr to the first element of the arrray.
 * @size: Number of array elementss.
 * Return: Ptr to the root node of the BST created, or NULL if fails
 */
bst_t *array_to_bst(int *array, size_t size)
{
	bst_t *tree = NULL;
	size_t x, y;

	if (array == NULL)
		return (NULL);
	for (x = 0; x < size; x++)
	{
		for (y = 0; y < x; y++)
		{
			if (array[y] == array[x])
				break;
		}
		if (y == x)
		{
			if (bst_insert(&tree, array[x]) == NULL)
				return (NULL);
		}
	}
	return (tree);
}
