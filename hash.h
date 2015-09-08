#ifndef _HASH_H_
#define _HASH_H_

#define array_length(a) (sizeof(a) / sizeof(a[0]))

typedef int key_t;
typedef struct node {
	key_t key;
	struct node *next;
} chain_t;

void create_hash_table(chain_t *hash_table[], const key_t *key, int n);
void print_hash_table(chain_t *hash_table[], int len);

#endif	/* _HASH_H_ */
