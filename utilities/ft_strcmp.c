// Marco Sebastiani 2022

#include "../sonar.h"

int ft_strcmp(char *str1, char *str2)
{
    int index;

    index = 0;
    while (str1[index++])
        if (str1[index] != str2[index])
            return (str1[index] - str2[index]);
    return (0);
}