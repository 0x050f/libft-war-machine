/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtoty <jtoty@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/28 12:34:47 by jtoty             #+#    #+#             */
/*   Updated: 2017/03/09 15:54:12 by jtoty            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <unistd.h>
#include "../../../libft.h"

int		main(int argc, const char *argv[])
{
	char	*str;
	int		arg;

	alarm(5);
	if (argc == 1)
		return (0);
	else if ((arg = atoi(argv[1])) == 1)
	{
		if (!(str = ft_strnew(30)))
			write(1, "NULL", 4);
		else
			write(1, str, 31);
	}
	else if (arg == 2)
	{
		if (!(str = ft_strnew(0)))
			write(1, "NULL", 4);
		else
			write(1, str, 1);
	}
	return (0);
}
