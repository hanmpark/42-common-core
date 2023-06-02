#include "libft.h"

/* Creates a new string that contains a portion of the original string
* starting at a specified index and with a specified length.
*/
char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*dest;
	int		i;
	int		gap;

	if (!s)
		return (NULL);
	if (*s == 0 || start > ft_strlen(s))
		return (ft_strdup(""));
	gap = ft_strlen(s) - start;
	while ((size_t)gap > len)
		gap--;
	dest = ft_calloc(gap + 1, sizeof(char));
	if (!dest)
		return (NULL);
	i = 0;
	while (i + start < ft_strlen(s) && s[start + i] && i < gap)
	{
		dest[i] = s[start + i];
		i++;
	}
	return (dest);
}
