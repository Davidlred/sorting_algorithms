#include "sort.h"

/**
* insertion_sort_list - sorts a doubly linked list using the Insertion sort alg
* @list: List to order
* Return :
*/
void insertion_sort_list(listint_t **list)
{
	listint_t *node2 = NULL, *node_prev = NULL, *node_next = NULL, *tmp = NULL;
	int flag = 0;

	if (!list || !*list)
		return;

	tmp = *list;

	while (tmp)
	{
		if (tmp->prev != NULL)
		{
			node2 = tmp;
			flag = 0;
			while (node2 && node2->prev->n > node2->n)
			{
				node_prev = node2->prev;
				node_next = node2->next;

				if (node_prev->prev)
					node_prev->prev->next = node2;
				else
				{
					*list = node2;
					flag = 1;
				}
				if (node_next)
					node_next->prev = node_prev;

				node2->prev = node_prev->prev;
				node2->next = aux_prev;
				node_prev->prev = node2;
				node_prev->next = node_next;
				print_list(*list);
				if (flag)
					break;
			}
		}
		tmp = tmp->next;
	}
}
