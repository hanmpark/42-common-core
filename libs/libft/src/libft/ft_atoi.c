#include "libft.h"

/* Converts a string representation of an integer into its corresponding
* integer value.
*/
int	ft_atoi(const char *str)
{
	int	negative;
	int	digit;
	int	i;

	negative = 1;
	digit = 0;
	i = 0;
	while ((str[i] >= 9 && str[i] <= 13) || str[i] == 32)
		i++;
	if (str[i] == '-')
	{
		i++;
		negative = -1;
	}
	else if (str[i] == '+')
		i++;
	while (str[i] >= '0' && str[i] <= '9')
	{
		digit = digit * 10 + (str[i] - '0');
		i++;
	}
	return (digit * negative);
}
