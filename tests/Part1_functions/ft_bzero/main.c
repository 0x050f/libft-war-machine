/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtoty <jtoty@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/28 11:58:52 by jtoty             #+#    #+#             */
/*   Updated: 2017/03/09 15:38:29 by jtoty            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include "../../../libft.h"

int		main(int argc, const char *argv[])
{
	void	*mem;

	alarm(5);
	if (argc == 1 || !(mem = malloc(sizeof(*mem) * 5)))
		return (0);
	if (atoi(argv[1]) == 1)
	{
		memset(mem, 'e', 5);
		ft_bzero(mem, 5);
		write(1, mem, 5);
	}
	else if (atoi(argv[1]) == 2)
	{
		memset(mem, 'e', 5);
		ft_bzero(mem, 0);
		write(1, mem, 5);
	}
	return (0);
}
