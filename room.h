#ifndef ROOM_H
#define ROOM_H

typedef struct s_room {
	char	name[64];
	char	key[64];
	struct s_room	*next;
}	t_room;

int add_room(t_room *room, char *name, char *key);
int del_room(t_room *room, char *name);

#endif