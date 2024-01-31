/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   1068.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yojin <yojin@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/31 14:09:23 by yojin             #+#    #+#             */
/*   Updated: 2024/01/31 14:40:45 by yojin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

using namespace std;

typedef struct tree_node
{
	int	n;
	int	is_leaf;
	int	parent_n;
} node;

void remove_child(node *tree, int count, int num)
{
	for(int i = 0; i < count; i++)
	{
		if (tree[i].parent_n == num)
		{
			tree[i].is_leaf = false;
			remove_child(tree, count, tree[i].n);
		}
	}
}

int main()
{
	node tree[50];
	int	count;
	int	temp;
	int	leaf;

	cin >> count;
	for (int i = 0; i < count; i++)
	{
		cin >> temp;
		tree[i].n = i;
		tree[i].parent_n = temp;
		tree[i].is_leaf = true;
	}
	cin >> temp;
	tree[temp].is_leaf = false;
	remove_child(tree, count, temp);
	for (int i = 0; i < count; i++)
	{
		if (i != temp && tree[i].parent_n != -1)
			tree[tree[i].parent_n].is_leaf = false;
	}
	leaf = 0;
	for (int i = 0; i < count; i++)
	{
		if (tree[i].is_leaf)
			leaf++;
	}
	cout << leaf << endl;
	return (0);
}