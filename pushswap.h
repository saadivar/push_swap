/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pushswap.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sel-biyy <sel-biyy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/22 21:03:00 by sel-biyy          #+#    #+#             */
/*   Updated: 2023/01/09 02:46:05 by sel-biyy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSHSWAP_H
# define PUSHSWAP_H

# include "bonus/get_next_line.h"
# include "stdio.h"
# include "unistd.h"
# include <stdarg.h>
# include <stdlib.h>

typedef struct t_list
{
	int				content;
	struct t_list	*next;

}					t_list;
typedef struct t_help
{
	int				ref;
	int				start;
	int				end;
	int				args;
}					t_help;
void				sb(t_list **a, t_list **b);
void				sa(t_list **a, t_list **b);
void				ss(t_list **a, t_list **b);
void				pa(t_list **a, t_list **b);
t_list				*ft_lstnew(int content);
void				ft_lstadd_back(t_list **lst, t_list *new);
void				ft_lstadd_front(t_list **lst, t_list *new);
char				**ft_split(char const *s, char c);
char				*ft_substr(char const *s, unsigned int start, size_t len);
t_list				*ft_lstlast(t_list *lst);
int					ft_atoi(char *str);
int					ft_isdigit(int c);
size_t				ft_strlen(const char *s);
char				*ft_strdup(const char *src);
int					ft_printf(const char *s, ...);
int					adress(unsigned long n, char *base);
int					nbr(long n, char *base);
int					ft_putstr(char *s);
int					ft_putchar(char c);
int					ft_lstsize(t_list *lst);
void				rb(t_list **a, t_list **b);
void				rrb(t_list **a, t_list **b);
void				ra(t_list **a, t_list **b);
int					sorted(int *alldigit, int args);
void				algo5first(t_list **a, t_list **b, int *arr);
void				algo5second(t_list **a, t_list **b, int args, int *arr);
void				algo5(t_list **a, t_list **b, int args, int *arr);
void				checkdouble(int ac, int *p);
int					*array(int ac, char **av, int *args);
void				check(int args, int *alldigit, t_list **a, t_list **b);
int					smallindex(t_list **a, t_list **b, int *alldigit);
int					smallindex1(t_list **a, t_list **b, int *alldigit);
void				algo3(t_list **a, t_list **b);
void				pb(t_list **a, t_list **b);
void				rra(t_list **a, t_list **b);
int					posemax(t_list **b, int *arr, int arg);
void				rrr(t_list **a, t_list **b);
void				rr(t_list **a, t_list **b);
void				writer(void);
void				from_a_to_b(t_list **a, t_list **b, int args,
						int *alldigit);
void				indexation(t_list **a);
int					poseacct(t_list **a, int nb);

#endif