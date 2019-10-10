# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    compil_lib.sh                                      :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jtoty <jtoty@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/01/23 18:26:36 by jtoty             #+#    #+#              #
#    Updated: 2017/04/03 10:35:38 by jtoty            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#!/bin/bash

func_compil_lib()
{
	text="COMPILING LIBFT"
	printf "${COLOR_TITLE}"
	printf "%.s${CHAR_LENGTH}" $(seq 1 ${TITLE_LENGTH})
	printf "\n${CHAR_WIDTH}\033[$(( (${TITLE_LENGTH} - ${#text}) / 2 ))G${text}\033[${TITLE_LENGTH}G${CHAR_WIDTH}\n"
	printf "%.s${CHAR_LENGTH}" $(seq 1 ${TITLE_LENGTH})
	printf "\n\n${DEFAULT}"
	if [ -e ${PATH_LIBFT}/libft.a ]
	then
		rm -f ${PATH_LIBFT}/libft.a
	fi

	text="= Compiling libft "
	printf "\n${text}" >> ${PATH_DEEPTHOUGHT}/deepthought
	printf "%.s=" $(seq 1 $(( 80 - ${#text} ))) >> ${PATH_DEEPTHOUGHT}/deepthought

	if [ "${MAKEFILE_VAR}" == "missing_makefile" ]
	then
		text="Missing Makefile, can't compil library."
		printf "\033[$(( (${TITLE_LENGTH} - ${#text}) / 2 ))G${COLOR_FAIL}${text}${DEFAULT}\n\n"
		printf "\n${text}\n" >> ${PATH_DEEPTHOUGHT}/deepthought
	else
		if [ ${OPT_FULL_MAKEFILE} -eq 1 ]
		then
			printf "make all"
			printf "\033[17Gmake \$(NAME)"
			printf "\033[34Gmake fclean"
			printf "\033[51Gmake re"
			printf "\033[67Gmake clean"
			printf "\033[83Glibft.a\n"
		else
			printf "rule all"
			printf "\033[17Grule \$(NAME)"
			printf "\033[34Grule clean"
			printf "\033[51Grule fclean"
			printf "\033[67Gmake re"
			printf "\033[83Glibft.a\n"
		fi

		if [ ${OPT_FULL_MAKEFILE} -eq 1 ]
		then
			rm -f ${PATH_LIBFT}/ft_*.o
			printf "\n$> make all\n" >> ${PATH_DEEPTHOUGHT}/deepthought
			make --no-print-directory -C ${PATH_LIBFT} all>>${PATH_DEEPTHOUGHT}/deepthought 2>&1
			if [ -z "$(grep -w all ${PATH_LIBFT}/${MAKEFILE_VAR} | tr -d ' ' | tr -d '\t' | cut -d ':' -f 1 | grep -w all)" ]
			then
				printf "${COLOR_FAIL}missing rule${DEFAULT}"
			else
				if [ -e ${PATH_LIBFT}/libft.a ]
				then
					printf "${COLOR_OK}ok${DEFAULT}"
					rm -f ${PATH_LIBFT}/libft.a
				else
					printf "${COLOR_FAIL}fail${DEFAULT}"
				fi
			fi
		else
			if [ -z "$(grep -w all ${PATH_LIBFT}/${MAKEFILE_VAR} | tr -d ' ' | tr -d '\t' | cut -d ':' -f 1 | grep -w all)" ]
			then
				printf "${COLOR_FAIL}not found${DEFAULT}"
			else
				printf "${COLOR_OK}found${DEFAULT}"
			fi
		fi

		if [ ${OPT_FULL_MAKEFILE} -eq 1 ]
		then
			rm -f ${PATH_LIBFT}/ft_*.o
			printf "\n$> make $(grep -w NAME ${PATH_LIBFT}/Makefile | grep = | cut -d '=' -f 2 | tr -d ' ' | tr -d '\t')\n" >> ${PATH_DEEPTHOUGHT}/deepthought
			make --no-print-directory -C ${PATH_LIBFT} $(grep NAME ${PATH_LIBFT}/${MAKEFILE_VAR} | grep = | cut -d '=' -f 2 | tr -d ' ' | tr -d '\t') >>${PATH_DEEPTHOUGHT}/deepthought 2>&1
			if [ -z "$(grep -w '$(NAME)' ${PATH_LIBFT}/${MAKEFILE_VAR} | grep ':' | tr -d ' ' | tr -d '\t' | cut -d ':' -f 1 | grep -w '$(NAME)')" ]
			then
				printf "\033[17G${COLOR_FAIL}missing rule${DEFAULT}"
			else
				if [ -e ${PATH_LIBFT}/libft.a ]
				then
					printf "\033[17G${COLOR_OK}ok${DEFAULT}"
				else
					printf "\033[17G${COLOR_FAIL}fail${DEFAULT}"
					touch ${PATH_LIBFT}/libft.a
				fi
			fi
		else
			if [ -z "$(grep -w '$(NAME)' ${PATH_LIBFT}/${MAKEFILE_VAR} | grep ':' | tr -d ' ' | tr -d '\t' | cut -d ':' -f 1 | grep -w '$(NAME)')" ]
			then
				printf "\033[17G${COLOR_FAIL}not found${DEFAULT}"
			else
				printf "\033[17G${COLOR_OK}found${DEFAULT}"
			fi
		fi

		if [ ${OPT_FULL_MAKEFILE} -eq 1 ]
		then
			printf "\n$> make fclean\n" >> ${PATH_DEEPTHOUGHT}/deepthought
			make --no-print-directory -C ${PATH_LIBFT} fclean >> ${PATH_DEEPTHOUGHT}/deepthought 2>&1
			if [ -z "$(grep -w fclean ${PATH_LIBFT}/${MAKEFILE_VAR} | tr -d ' ' | tr -d '\t' | cut -d ':' -f 1 | grep -w fclean)" ]
			then
				printf "\033[34G${COLOR_FAIL}missing rule${DEFAULT}"
			else
				if [ ! -e ${PATH_LIBFT}/libft.a ] && [ ! -e ${PATH_LIBFT}/ft_*.o ]
				then
					printf "\033[34G${COLOR_OK}ok${DEFAULT}"
					touch ${PATH_LIBFT}/libft.a
				else
					printf "\033[34G${COLOR_FAIL}fail${DEFAULT}"
					rm -f ${PATH_LIBFT}/ft_*.o
					rm -f ${PATH_LIBFT}/libft.a
				fi
			fi
		else
			if [ -z "$(grep -w clean ${PATH_LIBFT}/${MAKEFILE_VAR} | tr -d ' ' | tr -d '\t' | cut -d ':' -f 1 | grep -w clean)" ]
			then
				printf "\033[34G${COLOR_FAIL}not found${DEFAULT}"
			else
				printf "\033[34G${COLOR_OK}found${DEFAULT}"
			fi
		fi

		printf "\n$> make re\n" >> ${PATH_DEEPTHOUGHT}/deepthought
		if [ ${OPT_FULL_MAKEFILE} -eq 1 ]
		then
			make --no-print-directory -C ${PATH_LIBFT} re >> ${PATH_DEEPTHOUGHT}/deepthought 2>&1
			if [ -z "$(grep -w re ${PATH_LIBFT}/${MAKEFILE_VAR} | tr -d ' ' | tr -d '\t' | cut -d ':' -f 1 | grep -w re)" ]
			then
				printf "\033[51G${COLOR_FAIL}missing rule${DEFAULT}"
			else
				if [ -e ${PATH_LIBFT}/libft.a ]
				then
					printf "\033[51G${COLOR_OK}ok${DEFAULT}"
				else
					printf "\033[51G${COLOR_FAIL}fail${DEFAULT}"
				fi
			fi
		else
			if [ -z "$(grep -w fclean ${PATH_LIBFT}/${MAKEFILE_VAR} | tr -d ' ' | tr -d '\t' | cut -d ':' -f 1 | grep -w fclean)" ]
			then
				printf "\033[51G${COLOR_FAIL}not found${DEFAULT}"
			else
				printf "\033[51G${COLOR_OK}found${DEFAULT}"
			fi
		fi

		if [ ${OPT_FULL_MAKEFILE} -eq 1 ]
		then
			printf "\n$> make clean\n" >> ${PATH_DEEPTHOUGHT}/deepthought
			make --no-print-directory -C ${PATH_LIBFT} clean >> ${PATH_DEEPTHOUGHT}/deepthought 2>&1
			if [ -z "$(grep -w clean ${PATH_LIBFT}/${MAKEFILE_VAR} | tr -d ' ' | tr -d '\t' | cut -d ':' -f 1 | grep -w clean)" ]
			then
				printf "\033[67G${COLOR_FAIL}missing rule${DEFAULT}"
			else
				if [ ! -e ${PATH_LIBFT}/ft_*.o ]
				then
					printf "\033[67G${COLOR_OK}ok${DEFAULT}"
				else
					printf "\033[67G${COLOR_FAIL}fail${DEFAULT}"
				fi
			fi
		else
			make --no-print-directory -C ${PATH_LIBFT} re >> ${PATH_DEEPTHOUGHT}/deepthought 2>&1
			if [ -z "$(grep -w re ${PATH_LIBFT}/${MAKEFILE_VAR} | tr -d ' ' | tr -d '\t' | cut -d ':' -f 1 | grep -w re)" ]
			then
				printf "\033[67G${COLOR_FAIL}missing rule${DEFAULT}"
			else
				if [ -e ${PATH_LIBFT}/libft.a ]
				then
					printf "\033[67G${COLOR_OK}ok${DEFAULT}"
				else
					printf "\033[67G${COLOR_FAIL}fail${DEFAULT}"
				fi
			fi
		fi

		printf "\n$> ls -la libft.a\n" >> ${PATH_DEEPTHOUGHT}/deepthought
		ls -la ${PATH_LIBFT}/libft.a >> ${PATH_DEEPTHOUGHT}/deepthought
		if [ -e ${PATH_LIBFT}/libft.a ]
		then 
			printf "\033[83G${COLOR_OK}found\n\n${DEFAULT}"
		else
			printf "\033[83G${COLOR_FAIL}not found\n\n${DEFAULT}"
		fi
	fi
}
