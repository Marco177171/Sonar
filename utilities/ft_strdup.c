// Marco Sebastiani 2022

#include "../sonar.h"

char	*ft_strdup(char *s1)
{
	size_t	i;
	char	*str;
	size_t	len;

	i = 0;
	len = ft_strlen(s1) + 1;
	str = malloc(sizeof(*s1) * (len));
	if (!str)
	{
		return (NULL);
	}
	if (!s1)
	{
		return (NULL);
	}
	while (s1[i] != '\0')
	{
		str[i] = s1[i];
		i++;
	}
	str[i] = '\0';
	return (str);
}
