#include "../sonar.h"

static size_t find_size(char const *str, char c)
{
    size_t size = 0;

    while (str && *str) {
        if (*str == c) {
            ++size;
            while (str && *str && *str == c)
                ++str;
        } else {
            ++str;
        }
    }
    return ++size;
}

static size_t find_length(char const *str, char c) {
    size_t len = 0;
    while (str && str[len] && str[len] != c && str[len] != '\n') {
        len++;
    }
    return len;
}

char **ft_split(char const *str, char c)
{
    if (!str) {
        return NULL;
    }
    
    size_t size = find_size(str, c);
    char **ret = (char **)malloc(sizeof(char *) * size + 1);
    if (!ret) {
        return NULL;
    }
    size_t i = 0;
    int j = 0;
    while (i < size) {
        while (str[j] == c) {
            j++;
        }
        size_t str_length = find_length(&str[j], c);
        ret[i] = malloc(sizeof(char) * str_length + 1);
        if (!ret[i]) {
            return NULL;
        }
        int k = 0;
        while (str[j] != c) {
            ret[i][k] = str[j]; 
            j++;
            k++;
        }
        ++i;
    }
    ret[i] = NULL;
    return ret;
}