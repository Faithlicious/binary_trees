#include "binary_trees.h"
/**
 * binary_tree_is_leaf - checks if a node is leaf
 * @node: the node
 * Return: 1 if yes and 0 if no
 */
int binary_tree_is_leaf(const binary_tree_t *node)
{
	if (!node)
		return (0);
	if (node->left == NULL && node->right == NULL)
		return (1);
	else
		return (0);
}
