#include <stdio.h>
#include <stdlib.h>

#define M	11
#define array_length(a) (sizeof(a) / sizeof(a[0]))

typedef int key_t;

typedef struct node {
	key_t key;
	struct node *next;
} chain_t;

static int h(key_t key)
{
	return key % M;
}

chain_t *hash_search(chain_t *hash_table, key_t key, chain_t **end)
{
	chain_t *cur = hash_table;
	chain_t *pre = NULL;
	while (cur != NULL && cur->key != key) {
		pre = cur;
		cur = cur->next;
	}
	*end = pre;
	if (cur == NULL)
		return NULL;
	else
		return cur;
}

/**
 * "link method" to solve the collision
 */
void create_hash_table(chain_t *hash_table[], const key_t *key, int n)
{
	int i;
	chain_t *p;
	chain_t *cur;
	chain_t *pre;

	for (i = 0; i < n; i++) {
		cur = hash_search(hash_table[h(key[i])], key[i], &pre);
		if (cur == NULL) {
			p = (chain_t *)malloc(sizeof(chain_t));
			p->key = key[i];
			p->next = NULL;
			
			if (pre == NULL) {
				hash_table[h(key[i])] = p;
			} else {
				pre->next = p;
			}
		}
	}
}

void print_list(const chain_t *list)
{
	const chain_t *p = list;
	while (p) {
		printf("%d -> ", p->key);
		p = p->next;
	}
	printf("^\n");
}

void print_hash(chain_t *hash[], int len)
{
	int i;
	for (i = 0; i < len; i++) {
		if (hash[i] != NULL) {
			printf("%d: ", i);
			print_list(hash[i]);
		}
	}
}

int main()
{
	int i;
	key_t sample[] = {47, 7, 11, 11, 29, 16, 92, 22, 8, 3, 33};
	chain_t *hash_table[11];

	for (i = 0; i < array_length(hash_table); i++) {
		hash_table[i] = NULL;
	}

	create_hash_table(hash_table, sample, array_length(sample));
	
	print_hash(hash_table, array_length(hash_table));

	return 0;
}
