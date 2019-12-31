#include "asm.h"

int		main(int ac, char **av)
{
	t_asm	asmbl;
	int		i;

	if (ac == 1)
		exit_usage(av[0]);
	init_asmbl(&asmbl);
	i = save_options(&asmbl, ac, av);
	while (i < ac)
		treate_file(av[i++], &asmbl);			//!!!!!!
	return (EXIT_SUCCESS);
}
