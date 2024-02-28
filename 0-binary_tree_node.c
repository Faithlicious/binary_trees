#include "binary_trees.h"
/**
 * binary_tree_node - creates a binary tree nodeinary_tree_node
 * @parent: pointer to the parent node to create
 * @value: value in the node
 *
 * Return: a pointer to the new node
 */
binary_tree_t *binary_tree_node(binary_tree_t *parent, int value)
{
	binary_tree_t *new;

	new = malloc(sizeof(binary_tree_t));
	if (!new)
		return (NULL);

	new->parent = parent;
	new->n = value;
	new->left = NULL;
	new->right = NULL;

	return (new);
}
/**
 * is_bst_util - Helper function to check if a binary tree is a valid BST
 * @tree: Pointer to the root node of the tree
 * @min: Minimum value allowed for nodes in the subtree
 * @max: Maximum value allowed for nodes in the subtree
 * Return: 1 if the subtree rooted at 'tree' is a valid BST, 0 otherwise
 */
int is_bst_util(const binary_tree_t *tree, int min, int max)
{
	if (tree == NULL)
		return (1);

	if (tree->n <= min || tree->n >= max)
		return (0);

	return (is_bst_util(tree->left, min, tree->n) &&
			is_bst_util(tree->right, tree->n, max));
}

/**
 * binary_tree_is_bst - Checks if a binary tree is a valid BST
 * @tree: Pointer to the root node of the tree to check
 * Return: 1 if tree is a valid BST, 0 otherwise
 */
int binary_tree_is_bst(const binary_tree_t *tree)
{
	if (tree == NULL)
		return (0);
	return (is_bst_util(tree, INT_MIN, INT_MAX));
}
