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
	return (lefth > righth ? lefth : righth);
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

/**
 * binary_tree_is_balanced - checks if a binary tree is balance
 * @tree: Pointer to the root node of the tree
 * Return: 1 if tree is balanced, 0 otherwise
 */
int binary_tree_is_balanced(const binary_tree_t *tree)
{
	int left_height, right_height;

	if (tree == NULL)
		return (1);
	left_height = l_height(tree->left);
	right_height = l_height(tree->right);

	if (abs(left_height - right_height) > 1)
		return (0);

	return (binary_tree_is_balanced(tree->left) &&
		binary_tree_is_balanced(tree->right));
}
/**
 * binary_tree_is_avl - checks if a binary tree is a valid AVL Tree
 * @tree: tree
 * Return: 1 or 0
 */
int binary_tree_is_avl(const binary_tree_t *tree)
{
	if (!tree)
		return (0);
	if (binary_tree_is_bst(tree) && binary_tree_is_balanced(tree))
	{
		return (1);
	}
	return (0);
}
