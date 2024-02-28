#include "binary_trees.h"
/**
 * binary_tree_depth - measures the depth of a node in a binary tree
 * @tree: the tree
 * Return: depth or 0
 */
size_t binary_tree_depth(const binary_tree_t *tree)
{
	if (!tree || tree->parent == NULL)
		return (0);
	return (1 + binary_tree_depth(tree->parent));
}
