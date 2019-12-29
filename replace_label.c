#include "./includes/asm.h"

static int	calcul_label_val_pos(t_list *begin, t_inst *label_pos)
{
	t_inst	*tmp;
	int		bytes;

	bytes = 0;
	while (begin)
	{
		tmp = (t_inst*)begin->content;
		if (tmp == label_pos)
			break ;
		bytes += tmp->nbr_bytes;
		begin = begin->next;
	}
	return (bytes);
}

static int	calcul_label_val_neg(t_list *begin, t_inst *inst)
{
	t_inst	*tmp;
	int		bytes;

	bytes = 0;
	while (begin)
	{
		tmp = (t_inst*)begin->content;
		if (tmp == inst)
			break ;
		bytes -= tmp->nbr_bytes;
		begin = begin->next;
	}
	return (bytes);
}

static int	calcul_label_value(t_list *begin, t_inst *inst, t_inst *label_pos, int sign)
{
	if (sign == 1)
		return (calcul_label_val_pos(begin, label_pos));
	return (calcul_label_val_neg(begin, inst));
}

int			replace_label(t_list *list_insts, t_inst *inst, t_inst *label_pos)
{
	t_list	*curr;
	t_list	*begin;
	t_inst	*tmp;
	int		sign;

	sign = 0;
	curr = list_insts;
	while (curr)
	{
		tmp = (t_inst*)curr->content;
		if (tmp == inst)
		{
			begin = curr;
			sign = 1;
			break ;
		}
		if (tmp == label_pos)
		{
			begin = curr;
			sign = -1;
			break ;
		}
		curr = curr->next;
	}
	return (calcul_label_value(begin, inst, label_pos, sign));
}
