#include "binary_trees.h"
/**
 * binary_trees_ancestor - checks the lowest common ansector
 * @first: first node
 * @second: second node
 * Return: ancestor node or NULL
 */
binary_tree_t *binary_trees_ancestor(const binary_tree_t *first,
		const binary_tree_t *second)
{
	const binary_tree_t *first_ptr = first;
	const binary_tree_t *second_ptr = second;
	size_t depth_first = 0, depth_second = 0;

	if (!first || !second)
		return (NULL);

	while (first_ptr->parent)
	{
		first_ptr = first_ptr->parent;
		depth_first++;
	}

	while (second_ptr->parent)
	{
		second_ptr = second_ptr->parent;
		depth_second++;
	}

	first_ptr = first;
	second_ptr = second;

	while (depth_first > depth_second)
	{
		first_ptr = first_ptr->parent;
		depth_first--;
	}

	while (depth_second > depth_first)
	{
		second_ptr = second_ptr->parent;
		depth_second--;
	}

	while (first_ptr && second_ptr && first_ptr != second_ptr)
	{
		first_ptr = first_ptr->parent;
		second_ptr = second_ptr->parent;
	}
	return ((first_ptr && second_ptr) ? (binary_tree_t *)first_ptr : NULL);
}
