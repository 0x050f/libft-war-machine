/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtoty <jtoty@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/28 15:28:20 by jtoty             #+#    #+#             */
/*   Updated: 2017/03/09 16:01:45 by jtoty            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <unistd.h>
#include "../../../libft.h"

void	ft_print_result(char const *s)
{
	int		len;

	len = 0;
	while (s[len])
		len++;
	write(1, s, len);
}

int		main(int argc, const char *argv[])
{
	int		arg;

	alarm(5);
	if (argc == 1)
		return (0);
	else if ((arg = atoi(argv[1])) == 1)
	{
		char	str[] ="LOREM IPSUM DOLOR SIT AMET";
		ft_print_result(ft_strlowcase(str));
	}
	else if (arg == 2)
	{
		char	str[] =" \n\tlorem 4ipSum DOLOR s\nit aMeT ";
		ft_print_result(ft_strlowcase(str));
	}
	else if (arg == 3)
	{
		char	str[] ="HeY ! 42mots quArAnte-deux; cinquante+et+un";
		ft_print_result(ft_strlowcase(str));
	}
	return (0);
}
