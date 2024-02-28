#include "binary_trees.h"
/**
 * binary_tree_preorder - traverses a tree using pre-order method
 * @tree: tree to go through
 * @func: pointer to function to call for each node gone through
 * Return:nothing
 */
void binary_tree_preorder(const binary_tree_t *tree, void (*func)(int))
{
	if (tree != NULL && func)
	{
		func(tree->n);
		binary_tree_preorder(tree->left, func);
		binary_tree_preorder(tree->right, func);
	}

}
