/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhumfrey <mhumfrey@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/13 21:25:05 by mhumfrey          #+#    #+#             */
/*   Updated: 2021/03/20 06:34:52 by mhumfrey         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <stdio.h>
#include <fcntl.h>

size_t ft_strlen(const char *s);
ssize_t ft_write(int fd, const void *buf, size_t nbyte);
ssize_t ft_read(int fd, void *buf, size_t nbyte);
char *ft_strcpy(char *dst, const char *src);
char *ft_strdup(const char *s1);
int ft_strcmp(const char *s1, const char *s2);

void clear_buffer(char *buffer, int size)
{
	int i = 0;
	while (i < size)
		buffer[i++] = 0;
}

int main()
{
    printf ("1 function:\n\n");
    /*========================>strlen<========================*/
    printf ("|========================>strlen<========================|\n");
    printf ("| my strlen:  %lu                                         |\n", ft_strlen("line for the test"));
    printf ("| lib strlen: %lu                                         |\n", strlen("line for the test"));
    printf ("| my strlen:  %lu                                          |\n", ft_strlen(""));
    printf ("| lib strlen: %lu                                          |\n", strlen(""));
    printf ("| my strlen:  %lu                                          |\n", ft_strlen("1"));
    printf ("| lib strlen: %lu                                          |\n", strlen("1"));
    printf ("|========================>strlen<========================|\n\n");
    /*========================>strlen<========================*/

    printf ("2 function:\n\n");
    /*========================>write<========================*/
    size_t i;
    printf ("|========================>write<========================|\n");
   	i = ft_write(1, "| line for the test                                     |\n", 58);
	i = write(1, "| line for the test                                     |\n", 58);
	printf("| my return: %lu                                         |\n", i);
	printf("| lib return: %lu                                        |\n", i);
    printf ("|========================>write<========================|\n\n");
    /*========================>write<========================*/

    printf ("3 function:\n\n");
    /*========================>read<========================*/
    printf ("|========================>read<========================|\n");
	int fd = open("main.c", O_RDONLY);
	char buff1[891];
	int ret = 1;
	printf("%-20s: \n", "header main.c | lib ");
	ret = read(fd, buff1, 890);
	buff1[ret] = 0;
	printf("[return : %d]\n%s\n", ret, buff1);
	printf("\n");
	close(fd);
	fd = open("main.c", O_RDONLY);
	clear_buffer(buff1, 891);
	printf("%-20s: \n", "header main.c | my ");
	ret = ft_read(fd, buff1, 890);
	buff1[ret] = 0;
	printf("[return : %d]\n%s\n", ret, buff1);
	printf("\n");
	clear_buffer(buff1, 891);
	close(fd);
    printf ("|========================>read<========================|\n\n");
    /*========================>read<========================*/

    printf ("4 function:\n\n");
    /*========================>strdup<========================*/
    printf ("|========================>strdup<========================|\n");
	char *hello = "Hello world !";
	char *save;
	char *save2;

	printf("%-20s: \"%s\"                    |\n", "| char *", hello);
	save = strdup(hello);
	printf("%-20s: \"%s\"                    |\n", "| lib", save);
	free(save);
	save = NULL;
	save2 = ft_strdup(hello);
	printf("%-20s: \"%s\"                    |\n", "| my ", save2);
	free(save2);
	save2 = NULL;
    printf ("|========================>strdup<========================|\n\n");
    /*========================>strdup<========================*/

    printf ("5 function:\n\n");
    /*========================>strcpy<========================*/
	char buffer[30];
	char *empty = "";
	char *alphabet = "abcdefghijklmnopqrstuvwxyz";

    printf ("|========================>strcpy<========================|\n");
	printf("%-20s: \"%s\"                                 |\n", "| char []", empty);
	printf("%-20s: buffer[50]                         |\n", "| copy to");
	printf("%-20s: \"%s\"                                 |\n", "| lib", strcpy(buffer, empty));
	clear_buffer(buffer, 30);
	printf("%-20s: \"%s\"                                 |\n", "| my ", ft_strcpy(buffer, empty));
	clear_buffer(buffer, 30);
	printf("%-20s: \"%s\"                    |\n", "| char []", hello);
	printf("%-20s: buffer[50]                         |\n", "| copy to");
	printf("%-20s: \"%s\"                    |\n", "| lib", strcpy(buffer, hello));
	clear_buffer(buffer, 30);
	printf("%-20s: \"%s\"                                 |\n", "| my ", ft_strcpy(buffer, hello));
	clear_buffer(buffer, 30);
	printf("%-20s: \"%s\"       |\n", "| char []", alphabet);
	printf("%-20s: buffer[50]                         |\n", "| copy to");
	printf("%-20s: \"%s\"       |\n", "| lib", strcpy(buffer, alphabet));
	clear_buffer(buffer, 30);
	printf("%-20s: \"%s\"                                 |\n", "| my ", ft_strcpy(buffer, alphabet));
	clear_buffer(buffer, 30);
    printf ("|========================>strcpy<========================|\n\n");
    /*========================>strcpy<========================*/

    printf ("6 function:\n\n");
    /*========================>strncmp<========================*/
    printf ("|========================>strncmp<========================|\n");
	char *hello1 = "Hello human !";
	char *hello2 = "Hello world !";

	printf("%-20s: \"%s\"                     |\n", "| char *", hello);
	printf("%-20s: \"%s\"                     |\n", "| compared to", hello1);
	printf("%-20s: \"%d\"                                |\n", "| lib", strcmp(hello, hello1));
	printf("%-20s: \"%d\"                                |\n", "| my", ft_strcmp(hello, hello1));
	printf("%-20s: \"%s\"                     |\n", "| char *", hello);
	printf("%-20s: \"%s\"                     |\n", "| compared to", hello2);
	printf("%-20s: \"%d\"                                 |\n", "| lib", strcmp(hello, hello2));
	printf("%-20s: \"%d\"                                 |\n", "| my", ft_strcmp(hello, hello2));
	printf("%-20s: \"%s\"                     |\n", "| char *", hello2);
	printf("%-20s: \"%s\"                                  |\n", "| compared to", empty);
	printf("%-20s: \"%d\"                                |\n", "| lib", strcmp(hello2, empty));
	printf("%-20s: \"%d\"                                |\n", "| my", ft_strcmp(hello2, empty));
    printf ("|========================>strncmp<========================|\n");
    /*========================>strncmp<========================*/

    return (0);
}