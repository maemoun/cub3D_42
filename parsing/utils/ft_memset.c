#include "../cub3d.h"

void	*ft_memset(void *b, int c, size_t len)
{
	unsigned char	*pt;
	size_t			i;

	i = 0;
	pt = (unsigned char *)b;
	while (i < len)
	{
		*(pt + i) = (unsigned char)c;
		i++;
	}
	return (b);
}
