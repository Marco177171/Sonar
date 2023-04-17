// Marco Sebastiani 2022

#include "sonar.h"

void	ft_init(t_user *user, t_room *room, t_message *message)
{
	user->nickname = NULL;
	user->is_host = 0;
	room->name = NULL;
	room->key = NULL;
	message->content = NULL;
}
