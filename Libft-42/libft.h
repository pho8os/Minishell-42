/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yettabaa <yettabaa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/19 13:46:23 by absaid            #+#    #+#             */
/*   Updated: 2023/04/07 07:53:57 by yettabaa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <stdio.h>
# include <stdlib.h>
# include <stddef.h>
# include <unistd.h>
# include <string.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1
# endif
typedef struct s_env
{
	char			*variable;
	char			*value;
	int print;
	struct s_env	*prev;
	struct s_env	*next;
}	t_env;

int		ft_isalnum(int c);
int		ft_isalpha(int c);
int		ft_isdigit(int c);
int	ft_strlen(const char *str);
void	*ft_memmove(void *dst, const void *src, size_t len);
char	*ft_itoa(int n);
char	*ft_strjoin(const char *s1, const char *s2);
char	*_strjoin(const char *s1, const char *s2);
char	*ft_strjoin_sp(char const *s1, char const *s2, char c);
char	*ft_strchr(const char *s, int c);
void	*ft_memchr(const void *s, int c, size_t n);
int		ft_strcmp(const char *s1, const char *s2);
int		ft_strncmp(const char *s1, const char *s2, size_t n);
int		ft_memcmp(const void *s1, const void *s2, size_t n);
int		ft_atoi(const char *str);
char	*ft_strdup(const char *src);
char	*ft_substr(char const *s, unsigned int start, size_t len);
char	*ft_strstr(char *str, char *to_find);
char	*ft_strtrim(char const *s1, char const *set);
char	**ft_split(char const *s, char c);
void	ft_putchar_fd(char c, int fd);
void	ft_putendl_fd(const char *s, int fd);
void	ft_putstr_fd(const char *s, int fd);
char	*get_next_line(int fd);
t_env	*newenv(char *variable, char *value, int prenv);
void	ft_lstadd_front(t_env **lst, t_env *new);
void	addbenv(t_env **lst, t_env *new);
int		ft_lstsize(t_env *lst);
t_env	*ft_lstlast(t_env *lst);
void	ft_lstclear(t_env **lst);
void delone_env(t_env **env);
t_env *ft_lstchr(t_env *lst, const char *variable);

#endif
