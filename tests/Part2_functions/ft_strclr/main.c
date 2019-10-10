/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtoty <jtoty@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/28 12:31:34 by jtoty             #+#    #+#             */
/*   Updated: 2017/03/09 15:52:36 by jtoty            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include "../../../libft.h"

int		main(int argc, const char *argv[])
{
	char	*str;

	alarm(5);
	if (argc == 1)
		return (0);
	if (atoi(argv[1]) == 1)
	{
		str = (char *)malloc(sizeof(*str) * 10);
		if (!str)
			return (0);
		memset(str, 'u', 9);
		str[9] = '\0';
		ft_strclr(str);
		write(1, str, 10);
	}
	return (0);
}
