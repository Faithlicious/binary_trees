#include "binary_trees.h"

bst_t *successor(bst_t *root);

/**
 * bst_remove - removes a node from a BST
 * @root: pointer to the root node
 * @value: value to remove
 * Return: pointer to the new root node
 */

bst_t *bst_remove(bst_t *root, int value)
{
	bst_t *new = NULL;

	if (root == NULL)
		return (root);

	if (root->n > value)
		root->left = bst_remove(root->left, value);
	else if (root->n < value)
		root->right = bst_remove(root->right, value);
	else if (root->n == value)
	{
		if ((root->left == NULL) && (root->right == NULL))
		{
			free(root);
			return (NULL);
		}
		if (root->left == NULL)
		{
			new = root->right;
			if (root->parent)
			{
				if (root->parent->left == root)
					root->parent->left = new;
				else
					root->parent->right = new;
			}
			new->parent = root->parent;
			free(root);
			return (new);
		}
		else if (root->right == NULL)
		{
			new = root->left;
			if (root->parent)
			{
				if (root->parent->left == root)
					root->parent->left = new;
				else
					root->parent->right = new;
			}
			new->parent = root->parent;
			free(root);
			return (new);
		}
		else
		{
			new = successor(root->right);
			root->n = new->n;
			root->right = bst_remove(root->right, new->n);
		}
	}
	return (root);
}

/**
 * successor - searches for in-order successor
 * @root: pointer to root node
 * Return: pointer to in-order successor
 */

bst_t *successor(bst_t *root)
{
	bst_t *current = root;

	while ((current) && (current->left))
		current = current->left;
	return (current);
}
