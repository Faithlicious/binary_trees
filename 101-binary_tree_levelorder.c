#include "binary_trees.h"
/**
 * binary_tree_levelorder - Perform level-order traversal of a binary tree
 * @tree: Pointer to the root node of the tree to traverse
 * @func: Pointer to a function to call for each node
 * Return: nothing
 */
void binary_tree_levelorder(const binary_tree_t *tree, void (*func)(int))
{
	int fore = 0, aft = 0;
	const binary_tree_t **queue;
	const binary_tree_t *current;

	if (tree == NULL || func == NULL)
		return;
	queue = malloc(sizeof(binary_tree_t *) * 1024);
	if (!queue)
		return;

	queue[aft++] = tree;
	while (fore < aft)
	{
		current = queue[fore++];

		func(current->n);
		if (current->left != NULL)
			queue[aft++] = current->left;
		if (current->right != NULL)
			queue[aft++] = current->right;
	}
	free(queue);
}
