// Marco Sebastiani

#include "sonar.h"

void	ft_choose_nickname(t_user *user)
{
	user->nickname = readline("insert you nickname >> ");
	if (user->nickname[0] != '\0' && user->nickname[0] != ' ')
	{
		printf("nickname successfully created\n");
		return ;
	}
	else
	{
		printf("error: nickname empty. Retry\n");
		ft_choose_nickname(user);
	}
}
