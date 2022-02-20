/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tevelyne <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/13 20:00:02 by tevelyne          #+#    #+#             */
/*   Updated: 2021/04/24 14:00:48 by tevelyne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libasm.h"

# define GR   "\x1b[32m"
# define YEL  "\x1B[33m"
# define RES  "\x1b[0m"
# define MAG  "\x1b[35m"
# define CY   "\x1b[36m"

static void	files_for_test(void)
{
	int		fd1;

	fd1 = open("1.txt", O_WRONLY | O_CREAT | O_TRUNC, 0777 );
	close(fd1);
	fd1 = open("2.txt", O_WRONLY | O_CREAT | O_TRUNC, 0777 );
	close(fd1);
	fd1 = open("3.txt", O_WRONLY | O_CREAT | O_TRUNC, 0777 );
	close(fd1);
	fd1 = open("4.txt", O_WRONLY | O_CREAT | O_TRUNC, 0777 );
	close(fd1);
	fd1 = open("5.txt", O_WRONLY | O_CREAT | O_TRUNC, 0000 );
	close(fd1);
	fd1 = open("6.txt", O_WRONLY | O_CREAT | O_TRUNC, 0000 );
	close(fd1);
}


void check_write_read()
{
	int		std_write;
	int		my_write;
	int		std_read;
	int		my_read;
	char	*str;
	int		fd1;
	int		fd2;
	char	buf1[512];
	char	buf2[512];
	char	tmpstr[512];

	bzero(buf1, 512);
	bzero(buf2, 512);
	errno = 0;
	files_for_test();
	write(1, "2\n", 2);
	ft_write(1, "2\n", 2);
	write(1, "Hello world - standard write\n", 30);
	ft_write(1, "Hello world - my write\n", 24);
	write(1, "Hello standard\n", 16);
	ft_write(1, "Hello my write\n", 16);
	str = "The aim of this project is to get familiar with assembly language.\n";
	std_write = write(1, str, strlen(str));
	printf("std_write: %d\n", std_write);
	if(errno)
		printf("errno: %d\n%s\n", errno, strerror(errno));
	my_write = ft_write(1, str, strlen(str));
	printf("My write: %d\n",my_write);
	if(errno)
		printf("errno: %d\n%s\n", errno, strerror(errno));
	printf("\n%s\\=======bad file descriptor=======\\%s\n", GR, RES);
	std_write = write(-8, str, strlen(str));
	printf("std_write: %d\n", std_write);
	if (errno)
	{
		printf("errno: %d\n%s\n", errno, strerror(errno));
		errno = 0;
	}
	my_write = ft_write(-8, str, strlen(str));
	printf("My write: %d\n", my_write);
	if (errno)
	{
		printf("errno: %d\n%s\n", errno, strerror(errno));
		errno = 0;
	}
	fd1 = open("1.txt", O_WRONLY | O_CREAT | O_TRUNC, 0777 );
	fd2 = open("2.txt", O_WRONLY | O_CREAT | O_TRUNC, 0777 );
	std_write = write(fd1, str, strlen(str));
	printf("std_write: %d\n", std_write);
	if (errno)
	{
		printf("errno: %d\n%s\n", errno, strerror(errno));
		errno = 0;
	}
	my_write = ft_write(fd2, str, strlen(str));
	printf("My write: %d\n", my_write);
	if (errno)
	{
		printf("errno: %d\n%s\n", errno, strerror(errno));
		errno = 0;
	}
	close(fd1);
	close(fd2);
	fd1 = open("3.txt", O_WRONLY | O_CREAT | O_TRUNC, 0777 );
	fd2 = open("4.txt", O_WRONLY | O_CREAT | O_TRUNC, 0777 );
	printf("\n%s\\=========write(empty line)=========\\%s\n", GR, RES);
	std_write = write(fd1, "", strlen(""));
	printf("std_write: %d\n", std_write);
	if(errno)
	{
		printf("errno: %d\n%s\n", errno, strerror(errno));
		errno = 0;
	}
	my_write = ft_write(fd2, "", strlen(""));
	printf("My write: %d\n",my_write);
	if(errno)
	{
		printf("errno: %d\n%s\n", errno, strerror(errno));
		errno = 0;
	}
	close(fd1);
	close(fd2);
	fd1 = open("5.txt", O_WRONLY | O_CREAT | O_TRUNC, 0 );
	fd2 = open("6.txt", O_WRONLY | O_CREAT | O_TRUNC, 0 );
	printf ("\n%s\\============zero file descriptor=============\\%s\n", GR, RES);
	std_write = write(fd1, str, strlen(str));
	printf("std_write: %d\n", std_write);
	if (errno)
	{
		printf("errno: %d\n%s\n", errno, strerror(errno));
		errno = 0;
	}
	my_write = ft_write(fd2, str, ft_strlen(str));
	printf ("My write: %d\n", my_write);
	if (errno)
	{
		printf("errno: %d\n%s\n", errno, strerror(errno));
		errno = 0;
	}
	close(fd1);
	close(fd2);
	
	printf ("\n%s\\============READ=============\\%s\n\n", YEL, RES);
	errno = 0;
	fd1 = open("1.txt", O_RDONLY);
	fd2 = open("2.txt", O_RDONLY);

	std_read = read(fd1, buf1, 512);
	printf("std_read: %d\n%s\n", std_read, buf1);
	if (errno)
	{
		printf("errno: %d\n%s\n", errno, strerror(errno));
		errno = 0;
	}
	my_read = ft_read(fd2, buf2, 512);
	printf("my_read = %d\n%s\n", my_read, buf1);
	if (errno)
	{
		printf("errno: %d\n%s\n", errno, strerror(errno));
		errno = 0;
	}
	printf("%s=========bad file descriptor============%s\n", GR, RES);
	std_read = read(-3, buf1, 512);
	printf("std_read: %d\n", std_read);
	if (errno)
	{
		printf("errno: %d\n%s\n", errno, strerror(errno));
		errno = 0;
	}
	my_read = ft_read(-3, buf2, 512);
	printf("my_read = %d\n", my_read);
	if (errno)
	{
		printf("errno: %d:\n%s\n", errno, strerror(errno));
		errno = 0;
	}
	printf("%s=========main buf1 1===========%s\n", GR, RES);
	fd1 = open("main.c", O_RDONLY);
	fd2 = open("main.c", O_RDONLY);
	std_read = read(fd1, buf1, 1);
	printf("std_read = %d\n", std_read);
	if (errno)
	{
		printf("errno: %d\n%s\n", errno, strerror(errno));
		errno = 0;
	}
	my_read = ft_read(fd2, buf2, 1);
	printf("my_read = %d\n", my_read);
	if (errno)
	{
		printf("errno: %d\n%s\n", errno, strerror(errno));
		errno = 0;
	}
	close(fd1);
	close(fd2);
	printf("%s===========main 0 0===========%s\n", GR, RES);
	fd1 = open("main.c", O_RDONLY);
	fd2 = open("main.c", O_RDONLY);
	std_read = read(fd1, 0, 0);
	printf("std_read = %d\n", std_read);
	if (errno)
	{
		printf("errno: %d\n%s\n", errno, strerror(errno));
		errno = 0;
	}
	my_read = ft_read(fd2, 0, 0);
	printf("my_read = %d\n", my_read);
	if (errno)
	{
		printf("errno: %d\n%s\n", errno, strerror(errno));
		errno = 0;
	}
	close(fd1);
	close(fd2);
	memset(tmpstr, 0, 512);	
	printf("\n%sWrite something in console for test standart read:%s\n", MAG, RES);
	printf("%sStandart read console:%s %zd%s", CY, RES, read(0, tmpstr, 512), tmpstr);
	memset(tmpstr, 0, 512);
	printf("%sWrite something in console for test my read:%s\n", MAG, RES);
	printf("%sMy read console:%s %zd%s", CY, RES, ft_read(0, tmpstr, 512), tmpstr);

}

int	main(void)
{
	char	*tmp = "Hello";
	char	*str = "Hello world!";
	char	*empty= "";
	char	copy_str[512];
	int		error;
	char	*stdup_test;
	char	*str_long = "To be, or not to be, that is the question:\nWhether 'tis nobler in the mind to suffer\nThe slings and arrows of outrageous fortune,\nOr to take arms against a sea of troubles\nAnd by opposing end them. To die—to sleep,\nNo more The heart-ache and the thousand natural shocks\nThat flesh is heir to: 'tis a consummation";
	
	printf ("\n%s\\============STRLEN=============\\%s\n", YEL, RES);
	printf("%lu - standard\n", strlen(str));
	printf("%zu - my function\n",ft_strlen(str));
	printf ("%s\\====empty const====\\%s\n", GR, RES);
	printf("%lu - standard\n", strlen(empty));
	printf("%zu - my function\n", ft_strlen(empty));
	printf ("%s\\====long const====\\%s\n", GR, RES);
	printf("%lu - standard\n", strlen(str_long));
	printf("%zu - my function\n", ft_strlen(str_long));
	printf ("%s\\====empty====\\%s\n", GR, RES);
	printf("%lu - standard\n", strlen(""));
	printf("%zu - my function\n\n", ft_strlen(""));

	printf ("\n%s\\============STRCPY=============\\%s\n", YEL, RES);
	printf("%s - standard\n", strcpy(copy_str, str));
	printf("%s - my function\n", ft_strcpy(copy_str, str));
	printf ("%s\\====long str copy====\\%s\n", GR, RES);
	printf("%s		 - standard\n", strcpy(copy_str, str_long));
	printf("%s		 - my function\n",ft_strcpy(copy_str, str_long));
	printf ("%s\\====empty const str copy====\\%s\n", GR, RES);
	printf("|%s| - standard\n", strcpy(copy_str, empty));
	printf("|%s| - my function\n\n", ft_strcpy(copy_str, empty));

	printf ("\n%s\\============STRCMP=============\\%s\n", YEL, RES);
	printf("%d - standard\n", strcmp(copy_str, tmp));
	printf("%d - my function\n", ft_strcmp(copy_str, tmp));
	printf("%d - standard\n", strcmp(tmp, str));
	printf("%d - my function\n", ft_strcmp(tmp, str));
	printf ("%s\\====empty const====\\%s\n", GR, RES);
	printf("%d - standard\n", strcmp(empty, empty));
	printf("%d - my function\n", ft_strcmp(empty, empty));
	printf ("%s\\====empty====\\%s\n", GR, RES);
	printf("%d - standard\n", strcmp("", ""));
	printf("%d - my function\n", ft_strcmp("", ""));
	printf ("%s\\====first const empty====\\%s\n", GR, RES);
	printf("%d - standard\n", strcmp(empty, str));
	printf("%d - my function\n", ft_strcmp(empty, str));
	printf ("%s\\====first empty====\\%s\n", GR, RES);
	printf ("%s\\====second const empty====\\%s\n", GR, RES);
	printf("%d - standard\n", strcmp(str, empty));
	printf("%d - my function\n", ft_strcmp(str, empty));
	printf ("%s\\====const str====\\%s\n", GR, RES);
	printf("%d - standard\n", strcmp(str, str));
	printf("%d - my function\n", ft_strcmp(str, str));

	printf ("\n%s\\============STRDUP=============\\%s\n\n", YEL, RES);
	stdup_test = NULL;

	stdup_test = strdup(str);
	char *new;
	printf ("standart strdup - %s\n", stdup_test);
	free(stdup_test);
	stdup_test = ft_strdup(str);
	printf ("my strdup - %s\n", stdup_test);
	new = ft_strdup("123");
	printf ("my strdup - %s\n", new);
	free(new);
	new = ft_strdup("123");
	printf("standart - %s\n", new);
	stdup_test = strdup("");
	printf ("empty standart\n|%s|\n", stdup_test);
	stdup_test = ft_strdup("");
	printf ("my empty\n|%s|", stdup_test);
 	printf ("\n%s\\======const empty=========\\%s\n", GR, RES);
	stdup_test = strdup(empty);
	printf ("empty standart\n|%s|\n", stdup_test);
	stdup_test = ft_strdup(empty);
	printf ("my empty\n|%s|\n", stdup_test);
	
	printf("\n%s\\========WRITE=======\\%s\n", YEL, RES);
	check_write_read();
	return (0);
}
