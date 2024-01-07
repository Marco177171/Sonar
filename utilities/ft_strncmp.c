#include "../sonar.h"

int ft_strncmp(char *str1, char *str2, int n)
{
    int index = -1;
    
    while (str1[++index] && index < n) 
        if (str1[index] != str2[index])
            return (str1[index] - str2[index]);
    return (0);
}