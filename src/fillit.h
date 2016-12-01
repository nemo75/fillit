/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thbricqu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/22 17:06:42 by thbricqu          #+#    #+#             */
/*   Updated: 2016/11/24 08:39:18 by thedupuy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H

# include <fcntl.h>
# include <stdlib.h>
# include <unistd.h>
# include <string.h>

# define TRUE 1
# define FALSE 0
# define BUF_SIZE 4096

typedef struct				s_coord
{
	int	x;
	int	y;

}							t_coord;

typedef struct				s_minmax
{
	int	min;
	int	max;
}							t_minmax;

typedef struct				s_tetri
{
	char			c;
	t_coord			t[4];
	t_minmax		mn;
	struct s_tetri	*next;

}							t_tetri;

t_coord						*ft_coord_size(int x, int y);
t_tetri						*ft_create_lst(const char *s, size_t i);
char						*read_file(const char *argv);
int							check_height(const char *s, int a);
int							check_carac(const char *s);
int							check_return(const char *s);
void						ft_fillit(char *ag);
int							ft_sqrt(int nb);
char						**ft_map(int size);
void						ft_print_tab(char **tab, int size);
void						ft_deltab(char **tab, int size);
int							check_tetriminos(const char *s);
void						ft_create_min_max(t_tetri *node);
size_t						ft_count_d(const char *s);
void						*ft_memalloc(size_t size);
void						ft_memdel(void **ap);
void						*ft_memset(void *s, int c, size_t n);
void						ft_putchar(char c);
void						ft_putstr(char const *str);
char						*ft_strnew(size_t size);
void						ft_strclr(char *s);
size_t						ft_strlen(char const *str);
int							cc2(const char *s, int n, size_t p, size_t k);
int							check_pos(const char *s, size_t i);
void						ft_clean_lst(t_tetri **alst);

#endif
