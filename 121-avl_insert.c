#include "binary_trees.h"
void balance(binary_tree_t **tree);
bst_t *search(bst_t *tree, int value);
bst_t *bst_insert(bst_t **tree, int value);

/**
 * avl_insert - insert node into AVL
 * @tree: pointer to root of tree
 * @value: value for inserted node
 *
 * Return: pointer to created node
 */
avl_t *avl_insert(avl_t **tree, int value)
{
	bst_t *new_node = NULL, *parent = NULL;

	if (tree == NULL)
		return (NULL);

	if (*tree == NULL)
	{
		*tree = binary_tree_node(*tree, value);
		return (*tree);
	}

	parent = search(*tree, value);

	if (parent)
	{
		if (value < parent->n)
		{
			if (parent->left != NULL)
				parent = search(parent->left, value);
		}
		else
		{
			if (parent->right != NULL)
				parent = search(parent->right, value);
		}
		new_node = binary_tree_node(parent, value);
	}
	else
	{
		return (NULL);
	}

	if (value < parent->n)
		parent->left = new_node;
	else
		parent->right = new_node;


	balance(tree);

	return (new_node);
}
/**
 * balance - balances tree
 * @tree: pointer to root of tree
 * Return: nothing
 */
void balance(binary_tree_t **tree)
{
	int balance_val;

	if (!tree || !(*tree))
		return;

	balance_val = binary_tree_balance(*tree);

	if (balance_val < -1)
	{
		if (binary_tree_balance((*tree)->right) > 0)
			(*tree)->right = binary_tree_rotate_right((*tree)->right);
		*tree = binary_tree_rotate_left(*tree);
	}
	else if (balance_val > 1)
	{
		if (binary_tree_balance((*tree)->left) < 0)
			(*tree)->left = binary_tree_rotate_left((*tree)->left);
		*tree = binary_tree_rotate_right(*tree);
	}

	if (abs(binary_tree_balance((*tree)->left)) > 1)
		balance(&((*tree)->left));

	if (abs(binary_tree_balance((*tree)->right)) > 1)
		balance(&((*tree)->right));

	if ((*tree)->parent)
		balance(&((*tree)->parent));
}

/**
 * search - searches tree
 * @tree: pointer to root
 * @value: value to add
 * Return: pointer to parent of new node; NULL
 */
bst_t *search(bst_t *tree, int value)
{
	if (!tree)
		return (NULL);

	if (value < tree->n)
	{
		if (tree->left != NULL)
			return (search(tree->left, value));
		else
			return (tree);
	}
	else if (value > tree->n)
	{
		if (tree->right != NULL)
		{
			return (search(tree->right, value));
		}
		else
			return (tree);
	}

	return (NULL);
}
