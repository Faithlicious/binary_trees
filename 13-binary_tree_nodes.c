#include "binary_trees.h"
/**
 * binary_tree_nodes - counts the nodes with atleast 1 child
 * @tree: the tree
 * Return: number of leaves
 */
size_t binary_tree_nodes(const binary_tree_t *tree)
{
	size_t count = 0;

	if (tree)
	{
		if (tree->left != NULL || tree->right != NULL)
		{
			count++;
			count += binary_tree_nodes(tree->left);
			count += binary_tree_nodes(tree->right);
		}

	}
	return (count);
}
