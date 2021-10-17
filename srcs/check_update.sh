# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    check_update.sh                                    :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jtoty <jtoty@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/01/23 18:26:27 by jtoty             #+#    #+#              #
#    Updated: 2017/01/23 18:26:28 by jtoty            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#!/bin/bash

func_check_update()
{
	printf "Checking for updates...\n"
	if [ "$(git fetch --all 2>&1 | grep fatal)" == "" ]
	then
		LOCAL_BRANCH=$(git branch | awk '$0 ~ /^\*/ {print $2; exit}')
		if [ "$(git diff "refs/remotes/origin/${LOCAL_BRANCH}")" != "" ]
		then
			LOCAL=`git show-ref | grep "refs/heads/${LOCAL_BRANCH}" | cut -d " " -f 1`
			REMOTE=`git ls-remote 2>/dev/null | grep refs/heads/${LOCAL_BRANCH} | cut -f 1`
			LOCAL_VERSION=$(git log --oneline 2>/dev/null | awk 'END {print NR}')
			REMOTE_VERSION=$(git log --oneline "refs/remotes/origin/${LOCAL_BRANCH}" | awk 'END {print NR}')
			if [ "${REMOTE}" != "${LOCAL}" -a "${REMOTE}" != "" -a "${LOCAL_VERSION}" -lt "${REMOTE_VERSION}" ]
			then
				printf "${RED}A new version is available.\n"
				printf "${DEFAULT}Do you want to update ? [y/n]\n"
				CHANGELOG=1
			else
				printf "${RED}Changes are made locally.\n"
				printf "${DEFAULT}Do you want to restore the original version ? [y/n]\n"
				CHANGELOG=0
			fi
			read line
			if [ "$line" == Y -o "$line" == y ]
				then
					git reset --hard origin/master > /dev/null
					if [ ${CHANGELOG} -eq 1 ]
					then
						printf "${GREEN}\nUpdate done\n${DEFAULT}"
						printf "\nChangelog\n"
						if [ "$(awk 'BEGIN {p=0}{if ($1 ~ /^~/){p+=1};if (p == 1) {print}}' "${PATH_TEST}"/changelog | awk 'END {if ($0 != "") {print}}')" == "" ]
						then
							head -n $(($(awk 'BEGIN {p=0}{if ($1 ~ /^~/){p+=1};if (p == 1) {print}}' "${PATH_TEST}"/changelog | wc -l) - 1)) "${PATH_TEST}"/changelog
						else
							head -n $(awk 'BEGIN {p=0}{if ($1 ~ /^~/){p+=1};if (p == 1) {print}}' "${PATH_TEST}"/changelog | wc -l) "${PATH_TEST}"/changelog
						fi
					else
						printf "${GREEN}\nThe original version has been restored.\n${DEFAULT}"
					fi
					printf "\nPlease relaunch script.\n"
					exit
			fi
		else
			printf "No updates available.\n\n"
		fi
	else
		printf "${RED}Failed to check update.\n\n"
	fi
}
