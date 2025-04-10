#include "sort.h"

/**
 * selection_sort - Trie un tableau d'entiers avec le tri par sélection
 * @array: le tableau à trier
 * @size: la taille du tableau
 */

void selection_sort(int *array, size_t size)
{
	size_t i, j, plus_petit_indices;
	int temp;

	if (array == NULL || size < 2)
		return;

	for (i = 0; i < size - 1; i++)
	{
		plus_petit_indices = i;

		for (j = i + 1; j < size; j++)
		{
			if (array[j] < array[plus_petit_indices])
				plus_petit_indices = j;
		}

		if (plus_petit_indices != i)
		{
			temp = array[i];
			array[i] = array[plus_petit_indices];
			array[plus_petit_indices] = temp;
			print_array(array, size);
		}
	}
}
