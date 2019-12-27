#ifndef ASM_H
# define ASM_H

# include "../libft/includes/libft.h"
# include "op.h"

#include <sys/stat.h> 
#include <sys/types.h>
#include <fcntl.h>

typedef struct		s_arg
{
	int				type;
	char			*arg;
}					t_arg;

/*
**	inst = instruction
*/

typedef struct		s_inst
{
	int				op;
	t_chr			*labels;
	t_arg			args[3];
}					t_inst;

typedef struct		s_dlist
{
	void			*content;
	size_t			content_size;
	struct s_dlist	*prev;
	struct s_dlist	*next;
}					t_dlist;

typedef struct		s_sfile
{
	char			*name;
	char			*comment;
	t_dlist			*insts;
	t_chr			*sf;
}					t_sfile;


#endif
