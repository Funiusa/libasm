/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libasm.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tevelyne <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/13 19:59:08 by tevelyne          #+#    #+#             */
/*   Updated: 2021/04/13 19:59:24 by tevelyne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBASM_H
# define LIBASM_H

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <errno.h>
#include <fcntl.h>

size_t		ft_strlen(char *str);
char	*ft_strcpy(char *destination, const char *source);
int		ft_strcmp(const char *string1, const char *string2);
ssize_t	ft_write(int fd, const void *buffer, unsigned int nbyte);
ssize_t	ft_read(int fd, void *buffer, size_t nbyte);
char	*ft_strdup(const char *src);

#endif
