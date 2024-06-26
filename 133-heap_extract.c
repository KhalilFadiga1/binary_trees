#include "binary_trees.h"
#include <stdlib.h>

/**
 * tree_height - Measures the height of a binary tree.
 * @tree: Ptr to the root node of the tree to measure its height.
 * Return: The height or 0 if tree is empty
 */
size_t  tree_height(const heap_t *tree)
{
	size_t height_l = 0;
	size_t height_r = 0;

	if (!tree)
		return (0);
	if (tree->left)
		height_l = 1 + tree_height(tree->left);
	if (tree->right)
		height_r = 1 + tree_height(tree->right);
	if (height_l > height_r)
		return (height_l);
	return (height_r);
}

/**
 * tree_size_h - Measures the sum of heights of a binary tree
 * @tree: Ptr to the root node of the tree to measure the height.
 * Return: Height or 0 if tree is NULL
 */
size_t tree_size_h(const binary_tree_t *tree)
{
	size_t height_l = 0;
	size_t height_r = 0;

	if (!tree)
		return (0);
	if (tree->left)
		height_l = 1 + tree_size_h(tree->left);
	if (tree->right)
		height_r = 1 + tree_size_h(tree->right);
	return (height_l + height_r);
}

/**
 * _preorder - Loop through a binary tree using pre-order traversal
 * @tree: Pointer to the root node of the tree to traverse
 * @node: Last note in loop
 * @height: Tree height
 */
void _preorder(heap_t *tree, heap_t **node, size_t height)
{
	if (!tree)
		return;
	if (!height)
		*node = tree;
	height--;
	_preorder(tree->left, node, height);
	_preorder(tree->right, node, height);
}

/**
 * heapify - Heapifies max binary heap
 * @root: Pointer to binary heap
 */
void heapify(heap_t *root)
{
	int value;
	heap_t *temp1, *temp2;

	if (!root)
		return;
	temp1 = root;
	while (1)
	{
		if (!temp1->left)
			break;
		if (!temp1->right)
			temp2 = temp1->left;
		else
		{
			if (temp1->left->n > temp1->right->n)
				temp2 = temp1->left;
			else
				temp2 = temp1->right;
		}
		if (temp1->n > temp2->n)
			break;
		value = temp1->n;
		temp1->n = temp2->n;
		temp2->n = value;
		temp1 = temp2;
	}
}

/**
 * heap_extract - Extracts the root node from a Max Binary Heap
 * @root: Pointer to the heap root node
 * Return: Extracted node value
 */
int heap_extract(heap_t **root)
{
	int value;
	heap_t *heap_r, *node;

	if (!root || !*root)
		return (0);
	heap_r = *root;
	value = heap_r->n;
	if (!heap_r->left && !heap_r->right)
	{
		*root = NULL;
		free(heap_r);
		return (value);
	}
	_preorder(heap_r, &node, tree_height(heap_r));
	heap_r->n = node->n;
	if (node->parent->right)
		node->parent->right = NULL;
	else
		node->parent->left = NULL;
	free(node);
	heapify(heap_r);
	*root = heap_r;
	return (value);
}
