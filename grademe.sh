# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    grademe.sh                                         :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jtoty <jtoty@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/01/23 18:26:01 by jtoty             #+#    #+#              #
#    Updated: 2021/02/04 07:07:10 by lmartin          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#!/bin/bash

#PATH_TEST=$(dirname $(readlink -f $0))
PATH_TEST="$(cd "$(dirname "$0")" && pwd -P)"

#exec 6>&2 2>/dev/null
exec 2> /dev/null

source "${PATH_TEST}"/srcs/variables.sh

for arg in ${@}
do
	case "${arg}" in
		"--help")			man "${PATH_TEST}"/srcs/help.1
							exit ;;
		"-h")				man "${PATH_TEST}"/srcs/help.1
							exit ;;
		"-d")				DIRECTORY=1 ;;
		"-s")				OPT_NO_SEARCH=1 ;;
		"-m")				OPT_FULL_MAKEFILE=1 ;;
		"-l")				OPT_NO_LIBRARY=1 ;;
		"-c")				OPT_NO_COLOR=1 ;;
		"-f")				OPT_NO_FORBIDDEN=1 ;;
		"-n")				OPT_NO_NORMINETTE=1 ;;
		"-u")				OPT_NO_UPDATE=1 ;;
		"-op1")				OPT_NO_PART2=1
							OPT_NO_BONUS=1
							OPT_NO_ADDITIONAL=1
							CHECK_IN_PART1=0
							CHECK_IN_PART2=0
							CHECK_IN_BONUS=0
							CHECK_IN_ADDITIONAL=0 ;;
		"-op2")				OPT_NO_PART1=1
							OPT_NO_BONUS=1
							OPT_NO_ADDITIONAL=1
							CHECK_IN_PART2=0
							CHECK_IN_PART1=0
							CHECK_IN_BONUS=0
							CHECK_IN_ADDITIONAL=0 ;;
		"-ob")				OPT_NO_PART1=1
							OPT_NO_PART2=1
							OPT_NO_ADDITIONAL=1
							CHECK_IN_BONUS=0
							CHECK_IN_PART2=0
							CHECK_IN_PART1=0
							CHECK_IN_ADDITIONAL=0 ;;
		"-oa")				OPT_NO_PART1=1
							OPT_NO_PART2=1
							OPT_NO_BONUS=1
							CHECK_IN_ADDITIONAL=0
							CHECK_IN_BONUS=0
							CHECK_IN_PART2=0
							CHECK_IN_PART1=0 ;;
		"-p1")				OPT_NO_PART1=1
							CHECK_IN_PART1=0 ;;
		"-p2")				OPT_NO_PART2=1
							CHECK_IN_PART2=0 ;;
		"-b")				OPT_NO_BONUS=1
							CHECK_IN_BONUS=0 ;;
		"-a")				OPT_NO_ADDITIONAL=1
							CHECK_IN_ADDITIONAL=0 ;;
		*ft_*)	for part in ${tab_all_part[*]}
				do
					check_part=$(echo CHECK_IN_${part} | tr '[:lower:]' '[:upper:]' | rev | cut -c 6- | rev)
					if [ ${!check_part} -eq 1 ]
					then
						#opt_part=$(echo OPT_NO_${part} | tr '[:lower:]' '[:upper:]' | rev | cut -c 6- | rev)
						p=0
						activate_part=$(echo ACTIVATE_${part} | tr '[:lower:]' '[:upper:]' | rev | cut -c 6- | rev)
						tab_part=$(echo ${part}[*])
						nb_func=$(echo ${!tab_part} | wc -w)
						while (( p < ${nb_func} ))
						do
							func_name=$(echo ${part}[$p])
							if [ "$(echo ${arg} | sed 's/_bonus//g' | grep -ow $(echo ${!func_name} | cut -d . -f 1 | sed 's/_bonus//g'))" != "" ]
							then
								(( ${part}_activation[$p]=1 ))
								#(( ${opt_part}=1 ))
								#####################
								OPT_NO_PART1=1
								OPT_NO_PART2=1
								OPT_NO_BONUS=1
								OPT_NO_ADDITIONAL=1
								#############################
								(( ${activate_part}=1 ))
								break
							fi
							(( p += 1 ))
						done
					fi
				done ;;
	esac
done

source "${PATH_TEST}"/srcs/colors.sh
source "${PATH_TEST}"/srcs/check_cheat.sh
source "${PATH_TEST}"/srcs/check_compilation.sh
source "${PATH_TEST}"/srcs/check_file.sh
source "${PATH_TEST}"/srcs/check_norme.sh
source "${PATH_TEST}"/srcs/compil_lib.sh
source "${PATH_TEST}"/srcs/diff_test.sh
source "${PATH_TEST}"/srcs/test_function.sh
source "${PATH_TEST}"/srcs/check_update.sh

cd "${PATH_TEST}"

if [ ${OPT_NO_UPDATE} -eq 0 ]
then
	func_check_update
fi

if [ ! -e "${PATH_TEST}"/my_config.sh ]
then
	printf "${BOLD}my_config.sh${DEFAULT} file is not found.\n"
	printf "Creating file...\n"
	if [ -e "${PATH_TEST}"/srcs/config_template.sh ]
	then
		cp "${PATH_TEST}"/srcs/config_template.sh "${PATH_TEST}"/my_config.sh
		printf "File created with success in ${BOLD}${PURPLE}${PATH_TEST}\n${DEFAULT}"
		printf "${RED}${UNDERLINE}Edit my_config.sh file${DEFAULT} with the path of your libft project and launch script.\n"
	else
		printf "Can't create my_config.sh file, try to update or clone again the repository and retry.\n"
		exit
	fi
	exit
fi

source "${PATH_TEST}"/my_config.sh

if [ ${CUSTOM_DIRECTORY} -eq 1 ]
then
	if [ -d "${PATH_TEST}"/dirlibft ]
	then
		rm -rf "${PATH_TEST}"/dirlibft
	fi
	printf "Copying files...\nPlease wait a moment.\n"
	mkdir "${PATH_TEST}"/dirlibft
	mkdir "${PATH_TEST}"/dirlibft/${SRC_DIR}
	mkdir "${PATH_TEST}"/dirlibft/${HEADER_DIR}
	cp "${PATH_LIBFT}"/* "${PATH_TEST}"/dirlibft
	cp "${PATH_LIBFT}"/${SRC_DIR}/*.c "${PATH_TEST}"/dirlibft/${SRC_DIR}
	cp "${PATH_LIBFT}"/${HEADER_DIR}/*.h "${PATH_TEST}"/dirlibft/${HEADER_DIR}
	#find ${PATH_LIBFT} -type f -name "*.[ch]" -print | xargs cp -t ${PATH_TEST}/dirlibft
	PATH_LIBFT="${PATH_TEST}"/dirlibft
#	sleep 1000
fi

for part in ${tab_all_part[*]}
do
	opt_part=$(echo OPT_NO_${part} | tr '[:lower:]' '[:upper:]' | rev | cut -c 6- | rev)
	if [ ${!opt_part} -eq 0 ]
	then
		p=0
		tab_part=$(echo ${part}[*])
		nb_func=$(echo ${!tab_part} | wc -w)
		if [ ${part} != "Additional_func" ]
		then
			while (( p < ${nb_func} ))
			do
				(( ${part}_activation[$p]=1 ))
				(( p += 1 ))
			done
		else
			(( ${opt_part}=1 ))
			while (( p < ${nb_func} ))
			do
				func_name=$(echo ${part}[$p])
				if [ -e ${PATH_LIBFT}/${!func_name} ]
				then
					(( ${part}_activation[$p]=1 ))
					(( ${opt_part}=0 ))
				fi
				(( p += 1 ))
			done
		fi
	fi
done

init_deepthought()
{
	if [ -e "${PATH_DEEPTHOUGHT}"/deepthought ]
	then
		rm -f "${PATH_DEEPTHOUGHT}"/deepthought
	fi
	text="= Host-specific information "
	printf "${text}" >> "${PATH_DEEPTHOUGHT}"/deepthought
	printf "%.s=" $(seq 1 $(( 80 - ${#text} ))) >> "${PATH_DEEPTHOUGHT}"/deepthought
	printf "\n$> hostname; uname -msr\n" >> "${PATH_DEEPTHOUGHT}"/deepthought
	hostname >> "${PATH_DEEPTHOUGHT}"/deepthought
	uname -msr >> "${PATH_DEEPTHOUGHT}"/deepthought
	printf "$> date\n" >> "${PATH_DEEPTHOUGHT}"/deepthought
	date >> "${PATH_DEEPTHOUGHT}"/deepthought
	printf "$> gcc --version\n" >> "${PATH_DEEPTHOUGHT}"/deepthought
	gcc --version >> "${PATH_DEEPTHOUGHT}"/deepthought
	printf "$> clang --version\n" >> "${PATH_DEEPTHOUGHT}"/deepthought
	clang --version >> "${PATH_DEEPTHOUGHT}"/deepthought
}

clear
init_deepthought

if [ -e "${PATH_LIBFT}/Makefile" ]
then
	MAKEFILE_VAR="Makefile"
elif [ -e "${PATH_LIBFT}/makefile" ]
then
	MAKEFILE_VAR="makefile"
else
	MAKEFILE_VAR="missing_makefile"
fi

if [ ${OPT_NO_SEARCH} -eq 0 ]
then
	func_check_file
fi
if [ ${OPT_NO_LIBRARY} -eq 0 ]
then
	func_compil_lib
fi

for part in ${tab_all_part[*]}
do
	opt_part=$(echo OPT_NO_${part} | tr '[:lower:]' '[:upper:]' | rev | cut -c 6- | rev)
	activate_part=$(echo ACTIVATE_${part} | tr '[:lower:]' '[:upper:]' | rev | cut -c 6- | rev)
	if [ ${!opt_part} -eq 0 ]
	then
		(( ${activate_part}=1 ))
	fi
done

if [ -e "${PATH_LIBFT}/${HEADER_DIR}/libft.h" ]
then
	cp "${PATH_LIBFT}/${HEADER_DIR}/libft.h" "${PATH_TEST}"
fi

printf "#include \"libft.h\"\n\nint\tmain(void)\n{\n\treturn (0);\n}" > "${PATH_TEST}"/main_check_cheating.c

for part in ${tab_all_part[*]}
do
	activate_part=$(echo ACTIVATE_${part} | tr '[:lower:]' '[:upper:]' | rev | cut -c 6- | rev)
	if [ ${!activate_part} -eq 1 ]
	then
		text="= ${part}tions "
		printf "\n${text}" >> "${PATH_DEEPTHOUGHT}"/deepthought
		printf "%.s=" $(seq 1 $(( 80 - ${#text} ))) >> "${PATH_DEEPTHOUGHT}"/deepthought
		printf "\n" >> "${PATH_DEEPTHOUGHT}"/deepthought
		test_function $(echo ${part}[*])
	fi
done

if [ -e "${PATH_TEST}"/a.out ]
then
	rm "${PATH_TEST}"/a.out
fi

if [ -e "${PATH_TEST}"/libft.h ]
then
	rm "${PATH_TEST}"/libft.h
fi

if [ -e "${PATH_TEST}"/main_check_cheating.c ]
then
	rm "${PATH_TEST}"/main_check_cheating.c
fi

if [ ${DIRECTORY} -eq 1 ]
then
	if [ -d "${PATH_TEST}"/dirlibft ]
	then
		rm -rf "${PATH_TEST}"/dirlibft
	fi
fi

if [ ${ACTIVATE_PART1} -eq 1 ] || [ ${ACTIVATE_PART2} -eq 1 ] || [ ${ACTIVATE_BONUS} -eq 1 ] || [ ${ACTIVATE_ADDITIONAL} -eq 1 ]
then
	printf "Abort : ${RED}A${DEFAULT} Bus error : ${RED}B${DEFAULT} Segmentation fault : ${RED}S${DEFAULT} Timeout : ${RED}T${DEFAULT} Nothing turned in : ${RED}NTI${DEFAULT}\n"
	printf "\n"
fi
printf "A deepthought file has been generated in ${COLOR_DEEPTHOUGHT_PATH}\"${PATH_DEEPTHOUGHT}\"\n\n${DEFAULT}"
make --no-print-directory -C "${PATH_LIBFT}" fclean > /dev/null

# nuke_it_all
find "${PATH_TEST}" -name 'user_output_test*' -delete
rm -rf "${PATH_TEST}"/dirlibft/
