#include <stdio.h>
#include <stdlib.h>

#include "hash.h"

#define M	11

static int h(key_t key)
{
	return key % M;
}

static chain_t *hash_search(chain_t *hash, key_t key, chain_t **end)
{
	chain_t *cur = hash;
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

static void print_list(const chain_t *list)
{
	const chain_t *p = list;
	while (p) {
		printf("%d -> ", p->key);
		p = p->next;
	}
	printf("^\n");
}

void print_hash_table(chain_t *hash_table[], int len)
{
	int i;
	for (i = 0; i < len; i++) {
		if (hash_table[i] != NULL) {
			printf("%d: ", i);
			print_list(hash_table[i]);
		}
	}
}
