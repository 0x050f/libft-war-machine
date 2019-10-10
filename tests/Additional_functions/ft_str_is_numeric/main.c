/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtoty <jtoty@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/28 15:27:11 by jtoty             #+#    #+#             */
/*   Updated: 2017/03/09 16:00:16 by jtoty            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <unistd.h>
#include "../../../libft.h"

void	ft_print_result(int n)
{
	if (n)
		write(1, "1", 1);
	else
		write(1, "0", 1);
}

int		main(int argc, const char *argv[])
{
	int		i;
	char	str[] = "loremipsumdolorsitamet";
	int		arg;

	alarm(5);
	if (argc == 1)
		return (0);
	else if ((arg = atoi(argv[1])) == 1)
	{
		i = 0;
		while (i <= 47)
		{
			str[0] = i;
			ft_print_result(ft_str_is_numeric(str));
			i++;
		}
	}
	else if (arg == 2)
	{
		i = '0';
		while (i <= '9')
		{
			str[0] = i;
			ft_print_result(ft_str_is_numeric(str));
			i++;
		}
	}
	else if (arg == 3)
	{
		i = 58;
		while (i <= 64)
		{
			str[0] = i;
			ft_print_result(ft_str_is_numeric(str));
			i++;
		}
	}
	else if (arg == 4)
	{
		i = 'A';
		while (i <= 'Z')
		{
			str[0] = i;
			ft_print_result(ft_str_is_numeric(str));
			i++;
		}
	}
	else if (arg == 5)
	{
		i = 91;
		while (i <= 96)
		{
			str[0] = i;
			ft_print_result(ft_str_is_numeric(str));
			i++;
		}
	}
	else if (arg == 6)
	{
		i = 'a';
		while (i <= 'z')
		{
			str[0] = i;
			ft_print_result(ft_str_is_numeric(str));
			i++;
		}
	}
	else if (arg == 7)
	{
		i = 123;
		while (i <= 127)
		{
			str[0] = i;
			ft_print_result(ft_str_is_numeric(str));
			i++;
		}
	}
	return (0);
}
