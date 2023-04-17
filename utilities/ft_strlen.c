// Marco Sebastiani 2022

#include "../sonar.h"

int ft_strlen(char *str)
{
    int index;

    index = 0;
    while (str[index])
        index++;
    return (index);
}
