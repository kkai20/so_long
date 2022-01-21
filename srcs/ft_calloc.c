#include "so_long.h"

void	*ft_calloc(size_t number, size_t size)
{
	void	*p;
	size_t	heap;

	heap = number * size;
	if (heap == 0)
		heap = 1;
	p = malloc(heap);
	if (p == NULL)
	{
		printf("%s", "malloc error");
		exit(0);
	}
	ft_bzero(p, heap);
	return (p);
}
