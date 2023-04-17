// Marco Sebastiani 2022
// create your Sonar room

#include "sonar.h"

void	ft_create_room(t_room *room, t_user *user, t_message *message)
{
	printf("create new room\n");
	room->name = readline("insert room's name >> ");
	room->key = readline("insert room's pass key >> ");
	ft_setup_server(user, room, message);
}
