/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obelouch <obelouch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/04 01:07:21 by obelouch          #+#    #+#             */
/*   Updated: 2020/01/27 02:32:59 by obelouch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H
# include <string.h>
# include <unistd.h>
# include <stdlib.h>
# include <limits.h>
# include "structs.h"
# include "ft_printf.h"

# define FREE(x) free(x);x=NULL
# define BUFF_SIZE 1000
# define HASH_C 2

typedef int			t_bool;

/*
**		HASH :			-----------------------------------------------------
*/

void				hash_putintab(char **tab, int size, char *s, int *ind);
int					hash_findid(char **tab, int size, char *s);
int					hash_strtoind(char **tab, int size, char *s);
int					hash_filltab(char **tab, int size, char *s);
void				hash_freetab(char ***tab_hash, int size);
unsigned long		hash_str(char *str);

/*
**		BINARY TREE :	-----------------------------------------------------
*/

t_bt				*bt_create_node(void *item);
void				bt_insert_item(t_bt **root, void *item,
								int (*cmpf)(void *, void *));
t_bt				*bt_search_item(t_bt *root, void *data_ref,
								int (*cmpf)(void *, void *));
void				bt_apply_infix(t_bt *root, void (*applyf)(void *));
void				bt_apply_revinfix(t_bt *root, void (*applyf)(void *));
void				bt_apply_prefix(t_bt *root, void (*applyf)(void *));
void				bt_apply_suffix(t_bt *root, void (*applyf)(void *));
int					bt_size_count(t_bt *root);
int					bt_level_count(t_bt *root);
void				bt_free(t_bt **root, void (*freef)(void **));

/*
**		QUEUE :			-----------------------------------------------------
*/

int					qt_enqueue(t_queue *queue, void *content, size_t size);
int					qt_dequeue(t_queue *queue);
int					qt_front(t_queue queue, void *content);
t_queue				*qt_new_queue(void);
int					qt_isempty(t_queue queue);
void				qt_print(t_queue queue, int type, int sep);
void				qt_free(t_queue *queue);

/*
**		STACK :			-----------------------------------------------------
*/

void				sk_push(t_list **top, void *content, size_t size);
void				sk_pop(t_list **top, void *item);
int					sk_isempty(t_list *top);
void				*sk_top(t_list *top);
void				sk_free(t_list **head);

/*
**		LINKED LIST :	-----------------------------------------------------
*/

t_list				*ft_lstnew(void const *content, size_t content_size);
t_list				*ft_lstnew_sm(void *content, size_t content_size);
void				ft_lstdelone(t_list **alst, void (*del)(void*, size_t));
void				ft_lstdel(t_list **alst, void (*del)(void*, size_t));
void				ft_lstadd(t_list **alst, t_list *new);
void				ft_lstiter(t_list *lst, void (*f)(t_list *elem));
t_list				*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem));
void				ft_lstprint(t_list *head, int type, int sep);
void				ft_lstadd_last(t_list **lst, t_list *node);
void				ft_lstremove(t_list **alst, t_list *place,
								void (*del)(void*, size_t));
void				ft_lstinsert(t_list **alst, t_list *place, t_list *node);
int					ft_lstlen(t_list *lst);

/*
**	DOUBLE LINKED LIST:	-----------------------------------------------------
*/

t_dlist				*dt_lstnew(void const *content, size_t content_size);
t_dlist				*dt_lstnew_sm(void *content, size_t content_size);
void				dt_lstdelone(t_dlist **alst, void (*del)(void*, size_t));
void				dt_lstdel(t_dlist **alst, void (*del)(void*, size_t));
void				dt_lstadd(t_dlist **alst, t_dlist *new);
void				dt_lstiter(t_dlist *lst, void (*f)(t_dlist *elem));
t_dlist				*dt_lstmap(t_dlist *lst, t_dlist *(*f)(t_dlist *elem));
void				dt_lstremove(t_dlist **alst, t_dlist *place,
								void (*del)(void*, size_t));
void				dt_lstinsert(t_dlist **alst, t_dlist *place, t_dlist *node);
void				dt_lstadd_last(t_dlist **lst, t_dlist *node);
int					dt_lstlen(t_dlist *lst);

/*
**	CIRCL DLINKED LIST:	-----------------------------------------------------
*/

t_dlist				*dct_lstnew(const void *content, size_t content_size);
t_dlist				*dct_lstnew_sm(void *content, size_t content_size);
void				dct_lstdel(t_dlist **alst, void (*del)(void*, size_t));
void				dct_lstremove(t_dlist **alst, t_dlist *place,
								void (*del)(void*, size_t));
void				dct_lstadd_last(t_dlist **alst, t_dlist *new);

/*
**	CIRCULAR LIST:		-----------------------------------------------------
*/

t_list				*ct_lstnew(const void *content, size_t content_size);
t_list				*ct_lstnew_sm(void *content, size_t content_size);
void				ct_lstdel(t_list **alst, void (*del)(void*, size_t));
void				ct_lstremove(t_list **alst, t_list *place,
								void (*del)(void*, size_t));
void				ct_lstadd_last(t_list **alst, t_list *new);

/*
**		INT CASE:		-----------------------------------------------------
*/

void				ic_pushnode(t_icase **icase, int value);
void				ic_addnode(t_icase **icase, int value);
char				*ic_joinstr(t_icase **icase, int size);
void				ic_lstdel(t_list **alst);
void				ic_free(t_icase **icase);
void				ic_print(t_icase *icase);
int					ic_size(t_icase *icase);
int					ic_lstfind(t_list *list, t_icase *target);
int					ic_ncmp(t_icase *list1, t_icase *list2, size_t n);
int					ic_cmp(t_icase *list1, t_icase *list2);
t_icase				*ic_copy(t_icase *icase);

/*
**		STR LIST :		-----------------------------------------------------
*/

int					chr_len(t_chr *chr);
void				chr_init(t_chr **chr);
void				chr_free(t_chr **chr);
void				chr_print(t_chr *list);
void				chr_revprint(t_chr *list);
void				chr_addnode(t_chr **list, char *str, int len);
void				chr_addnode_sm(t_chr **list, char *str, int len);
void				chr_pushfront(t_chr **list, char *str, int len);
t_chr				*gnl_nsave_chr(int fd, int nbr_lines);
t_chr				*gnl_save_chr(int fd);

/*
**	PRINT/READ:			-----------------------------------------------------
*/

int					gnl(const int fd, char **line);
int					get_next_line(const int fd, char **line);
void				ft_printhex(int n);
void				ft_putchar(char c);
void				ft_putstr(char const *s);
void				ft_putendl(char const *s);
void				ft_putnbr(int n);
void				ft_putchar_fd(char c, int fd);
void				ft_putstr_fd(char const *s, int fd);
void				ft_putendl_fd(char const *s, int fd);
void				ft_putnbr_fd(int n, int fd);

/*
** CONVERS INT/STR :	-----------------------------------------------------
*/

char				*ft_itoa(long long int n);
char				*ft_ltoa(long int n);
char				*ft_lltoa(long long int n);
char				*ft_itoa_base(long long int val, int base);
char				*ft_ulltoa_base(unsigned long long val, int base);
char				*ft_utoa(size_t n);
char				*ft_ultoa(unsigned long int n);
char				*ft_ulltoa(unsigned long long int n);
char				*ft_utoa_base(size_t val, int base);
int					ft_atoibase(char *str, char *base_from);
int					ft_atoi(const char *str);
long				ft_atol(const char *str);
long				ft_atol_hex(char *str);
char				*ft_poslltoa(long long int n);

/*
**	STRING ARRAY :		-----------------------------------------------------
*/

int					tabstr_len(char **tab);
void				tabstr_free(char ***tab);
void				tabstr_trim(char **tab);
void				tabstr_print(char **tab);
void				tabstr_add(char ***tab, char *elem);
char				*tabstr_join(char **tab, char *sep);
char				*tabstr_njoin(char **tab, int start, int end, char *sep);
char				**tabstr_new(size_t len);
char				**tabstr_copy(char **tab);
char				**tabstr_ncopy(char **tab, int start, int end);

/*
**		INT ARRAY:      -----------------------------------------------------
*/

void				tabint_reset(int *tab, int size, int n);

/*
**		INT MATRIX:     -----------------------------------------------------
*/

void				mxint_print(int **matrix, int size_y, int size_x);
void				mxint_free(int ***tab, int size);

/*
**		POINT  :		-----------------------------------------------------
*/

t_point				pt_new(int y, int x);
void				pt_swap(t_point *p1, t_point *p2);
t_point				pt_linterp(t_point p1, t_point p2, int a, int t);

/*
**		MEMORY :		-----------------------------------------------------
*/

void				*ft_memset(void *b, int c, size_t len);
void				ft_bzero(void *s, size_t n);
void				*ft_memcpy(void *dest, const void *src, size_t n);
void				*ft_memccpy(void *dest, const void *src, int c, size_t n);
void				*ft_memmove(void *dest, const void *src, size_t n);
void				*ft_memchr(const void *s, int c, size_t n);
int					ft_memcmp(const void *s1, const void *s2, size_t n);
void				*ft_memalloc(size_t size);
void				ft_memdel(void **ap);

/*
**						-----------------------------------------------------
*/

int					ft_intlen(int n);
int					ft_isxdigit(int c);
int					ft_isblank(int c);
int					ft_isalpha(int c);
int					ft_isdigit(int c);
int					ft_isalnum(int c);
int					ft_isascii(int c);
int					ft_isprint(int c);
int					ft_toupper(int c);
int					ft_tolower(int c);
int					ft_is_strhex(char *s);
int					ft_is_strdigit(char *s);
int					ft_is_strblank(char *s);
char				*ft_strnew(size_t size);
char				*ft_strcnew(size_t size, char c);
void				ft_strdel(char **as);
void				ft_strclr(char *s);
void				ft_striter(char *s, void (*f)(char *));
void				ft_striteri(char *s, void (*f)(unsigned int, char *));
char				*ft_strmap(char const *s, char (*f)(char));
char				*ft_strmapi(char const *s, char (*f)(unsigned int, char));
int					ft_strequ(char const *s1, char const *s2);
int					ft_strnequ(char const *s1, char const *s2, size_t n);
char				*ft_strsub(char const *s, unsigned int start, size_t len);
char				*ft_strfreejoin(char **s1, char **s2, int fmode);
char				*ft_strnjoin(char *s1, char *s2, size_t len);
char				*ft_strjoin(char const *s1, char const *s2);
char				*ft_strcjoin(char const *s1, char c);
void				ft_trimstr(char **str);
char				*ft_strtrim(char const *s);
char				**ft_strsplit(char const *s, char c);
char				**ft_strsplit_char(char *s, char c);
size_t				ft_strlen(const char *str);
char				*ft_strcpy(char *dest, const char *src);
char				*ft_strncpy(char *dest, const char *src, size_t len);
char				*ft_strcat(char *dest, const char *src);
char				*ft_strncat(char *dest, const char *src, size_t n);
size_t				ft_strlcat(char *dest, const char *src, size_t size);
char				*ft_strstr(const char *str, const char *find);
char				*ft_strnstr(const char *str, const char *find, size_t n);
int					ft_strcmp(const char *s1, const char *s2);
int					ft_strncmp(const char *s1, const char *s2, size_t n);
char				*ft_strchr(const char *s, int c);
char				*ft_strrchr(const char *s, int c);
char				*ft_strpbrk(const char *s1, const char *s2);
char				*ft_strdup(const char *src);
char				*ft_strndup(const char *src, int n);
char				*ft_strlowcase(char *str);
char				*ft_strupcase(char *str);
void				ft_strcombin(char **s1, const char *s2);
void				ft_strccombin(char **s1, char c);
void				ft_swap(int *a, int *b);
char				*ft_strrev(char *str);
void				ft_strswap(char **s1, char **s2);
char				*ft_str_pushback(char *str, char c);
char				*ft_strsum(char *str1, char *str2, int base);
char				*ft_strmult(char *num1, char *num2, int base);
char				*ft_strpower(int base, int exponent, int x);
int					ft_max(int a, int b);
int					ft_min(int a, int b);
int					ft_sqrt(int nb);
int					ft_prime(int nb);
void				ft_epurstr(char **str);
int					ft_ends_with(char *str, char *word);
t_bool				ft_isnumeric_str(char *str);

#endif
