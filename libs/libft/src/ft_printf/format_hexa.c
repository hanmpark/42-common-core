#include "ft_printf.h"

static int	count_hexa(unsigned int nbr)
{
	int	count;

	count = 1;
	while (nbr / 16)
	{
		nbr /= 16;
		count++;
	}
	return (count);
}

static int	count_hexap(unsigned long long nbr)
{
	int	count;

	count = 1;
	while (nbr / 16)
	{
		nbr /= 16;
		count++;
	}
	return (count);
}

char	*format_hexa(const char *hexadecimal, unsigned int nbr)
{
	int		count;
	char	*str;

	count = count_hexa(nbr);
	str = malloc((count + 1) * sizeof(char));
	str[count] = 0;
	while (count-- > 0)
	{
		str[count] = hexadecimal[nbr % 16];
		nbr /= 16;
	}
	return (str);
}

char	*format_pointer(const char *hexadecimal, unsigned long long nbr)
{
	int		count;
	char	*str;

	count = count_hexap(nbr);
	str = malloc((count + 1) * sizeof(char));
	str[count] = 0;
	while (count-- > 0)
	{
		str[count] = hexadecimal[nbr % 16];
		nbr /= 16;
	}
	return (str);
}
