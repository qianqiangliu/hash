#include <stddef.h>

#include "hash.h"

int main()
{
	int i;
	key_t sample[] = {47, 7, 11, 11, 29, 16, 92, 22, 8, 3, 33};
	chain_t *hash_table[11];

	for (i = 0; i < array_length(hash_table); i++) {
		hash_table[i] = NULL;
	}

	create_hash_table(hash_table, sample, array_length(sample));
	
	print_hash_table(hash_table, array_length(hash_table));

	return 0;
}

