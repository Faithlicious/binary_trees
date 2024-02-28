#include "binary_trees.h"
/**
 * binary_tree_balance - measures the balance factor of a binary tree
 * @tree: the tree
 * Return: balance factor or 0
 */
int binary_tree_balance(const binary_tree_t *tree)
{
	int lefth, righth;

	if (tree == NULL)
	{
		return (0);
	}
	lefth = l_height(tree->left);
	righth = l_height(tree->right);
	return (lefth - righth);
}


/**
 * l_height - measures the height of a tree
 * @tree: the tree
 * Return: Height or NULL
 */
size_t l_height(const binary_tree_t *tree)
{
	size_t left_height, right_height;

	if (tree == NULL)
		return (0);

	left_height = l_height(tree->left);
	right_height = l_height(tree->right);

	return (left_height > right_height ? left_height + 1 : right_height + 1);
}
