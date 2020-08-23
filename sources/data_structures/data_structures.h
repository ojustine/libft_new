#ifndef DATA_STRUCTURES_H
# define DATA_STRUCTURES_H

# include <stdlib.h>

typedef struct		s_node
{
	void			*data;
	size_t			size;
	struct s_node	*next;
} 					t_node;

#endif
