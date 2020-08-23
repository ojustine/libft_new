#ifndef MEMORY_MANAGER_INTERNAL_H
# define MEMORY_MANAGER_INTERNAL_H

#include <stdlib.h>

typedef struct				s_memory_block
{
	size_t					capacity;
	size_t					remains;
	struct s_memory_block	*next;
}							t_memory_block;

#endif
