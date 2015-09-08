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
	int pos;
	chain_t *cur;
	chain_t *pre;

	for (i = 0; i < n; i++) {
		pos = h(key[i]);
		cur = hash_search(hash_table[pos], key[i], &pre);
		if (cur == NULL) {
			cur = (chain_t *)malloc(sizeof(chain_t));
			cur->key = key[i];
			cur->next = NULL;
			
			if (pre == NULL) {
				hash_table[pos] = cur;
			} else {
				pre->next = cur;
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
