#include "binary_trees.h"
/**
 * binary_tree_size - measures the size of a binary tree
 * @tree: the tree
 * Return: size of the tree or 0
 */
size_t binary_tree_size(const binary_tree_t *tree)
{
	size_t count = 0;

	if (tree)
	{
		count = 1 + binary_tree_size(tree->left);
		count = count + binary_tree_size(tree->right);
	}
	return (count);
}
