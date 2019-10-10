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
	const char	*str;
	int			arg;

	if (argc == 1)
		return (0);
	else if ((arg = atoi(argv[1])) == 1)
	{
		if (!(str = ft_strcasestr("lorEm ipsum dolor sit amet", "loRem")))
			ft_print_result("NULL");
		else
			ft_print_result(str);
	}
	else if (arg == 2)
	{
		if (!(str = ft_strcasestr("lorem iPsum dolor sit amet", "iPSum")))
			ft_print_result("NULL");
		else
			ft_print_result(str);
	}
	else if (arg == 3)
	{
		if (!(str = ft_strcasestr("lorem iPSum dolor sit lorem ipsum dolor", "ipsum")))
			ft_print_result("NULL");
		else
			ft_print_result(str);
	}
	else if (arg == 4)
	{
		if (!(str = ft_strcasestr("lorem ipsum dolor sit amet", "")))
			ft_print_result("NULL");
		else
			ft_print_result(str);
	}
	else if (arg == 5)
	{
		if (!(str = ft_strcasestr("lorem ipsum dolor sit amet", "ipSUmm")))
			ft_print_result("NULL");
		else
			ft_print_result(str);
	}
	else if (arg == 6)
	{
		if (!(str = ft_strcasestr("lorem ipsum dolor sit amet", "dOl")))
			ft_print_result("NULL");
		else
			ft_print_result(str);
	}
	else if (arg == 7)
	{
		if (!(str = ft_strcasestr("lorem ipsum dolor sit amet", "consECtetur")))
			ft_print_result("NULL");
		else
			ft_print_result(str);
	}
	return (0);
}
