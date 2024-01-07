#include "room.h"
#include <stdlib.h>

int add_room(t_room *room, char *name, char *key)
{
    t_room *new = malloc(sizeof(t_room));
    if (!new)
        return 1;
    int i = -1;
    while (name[++i])
        room->name[i] = name[i];
    i = -1;
    while (key[++i])
        room->key[i] = key[i];
    t_room *tmp = room;
    while (tmp->next)
        tmp = tmp->next;
    tmp->next = new;
    return 0;
}