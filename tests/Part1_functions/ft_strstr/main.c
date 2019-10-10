/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtoty <jtoty@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/28 12:08:47 by jtoty             #+#    #+#             */
/*   Updated: 2017/03/09 15:48:51 by jtoty            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <unistd.h>
#include <string.h>
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
	const char	*str;
	int			arg;

	alarm(5);
	if (argc == 1)
		return (0);
	else if ((arg = atoi(argv[1])) == 1)
	{
		if (!(str = ft_strstr("lorem ipsum dolor sit amet", "lorem")))
			ft_print_result("NULL");
		else
			ft_print_result(str);
	}
	else if (arg == 2)
	{
		if (!(str = ft_strstr("lorem ipsum dolor sit amet", "ipsum")))
			ft_print_result("NULL");
		else
			ft_print_result(str);
	}
	else if (arg == 3)
	{
		if (!(str = ft_strstr("lorem ipsum dolor sit lorem ipsum dolor", "ipsum")))
			ft_print_result("NULL");
		else
			ft_print_result(str);
	}
	else if (arg == 4)
	{
		if (!(str = ft_strstr("lorem ipsum dolor sit amet", "")))
			ft_print_result("NULL");
		else
			ft_print_result(str);
	}
	else if (arg == 5)
	{
		if (!(str = ft_strstr("lorem ipsum dolor sit amet", "ipsumm")))
			ft_print_result("NULL");
		else
			ft_print_result(str);
	}
	else if (arg == 6)
	{
		if (!(str = ft_strstr("lorem ipsum dolor sit amet", "dol")))
			ft_print_result("NULL");
		else
			ft_print_result(str);
	}
	else if (arg == 7)
	{
		if (!(str = ft_strstr("lorem ipsum dolor sit amet", "consectetur")))
			ft_print_result("NULL");
		else
			ft_print_result(str);
	}
	return (0);
}
