// Marco Sebastiani

#include "sonar.h"

void	ft_free_user(t_user *user)
{
	if (user->nickname)
		free(user->nickname);
}

void	ft_free_room(t_room *room)
{
	// if (room->name)
	// 	free(room->name);
	// if (room->key)
	// 	free(room->key);
	while (room->next)
	{
		t_room *tmp = room;
		room = room->next;
		free(tmp);
	}
}

void	ft_free_and_exit(t_user *user, t_room *room)
{
	printf("Leaving Sonar...\n");
	ft_free_user(user);
	ft_free_room(room);
	exit(0);
}
