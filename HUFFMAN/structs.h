#include <stdio.h>
#include <stdlib.h>

#define MAX 256
typedef struct node node;
typedef struct priority_queue priority_queue;
typedef struct element element;
typedef struct hash_table hash_table;
typedef struct binary_tree binary_tree;

struct node {
    void* item;
    int priority;
    node *next;
    node *left;
    node *right;
};

struct priority_queue {
    node *head;
};

struct element {
    int key;
    char string[100];
};

struct hash_table {
    element *table[50];
};

struct binary_tree {
    node* node_bt;
    binary_tree *left;
    binary_tree *right;
};

/*
 * fila
 */
 
priority_queue *create_priority_queue()
{
    priority_queue *new_priority_queue;
    new_priority_queue  = (priority_queue*) malloc(sizeof(priority_queue));
    new_priority_queue -> head = NULL;
    
    return new_priority_queue;
}


int is_empty_queue(priority_queue *pq) {
    if(pq->head==NULL){
        return 1;
    }else{
        return 0;
    }
}

void enqueue(priority_queue *pq, void* i, int p)
{
    node *new_node = (node*) malloc(sizeof(node));
    new_node->item = i;
    new_node->priority = p;
    
    if ((is_empty_queue(pq)) || (p > pq->head->priority)) {
        new_node->next = pq->head;
        pq->head = new_node;
    } else {
        node *current = pq->head;
        
        while ((current->next != NULL) && (current->next->priority > p)) {
            current = current->next;
        }

        new_node->next = current->next;
        current->next = new_node;
    }
}

node* dequeue(priority_queue *pq)
{
    if (is_empty_queue(pq)) {
        printf("Priority Queue underflow");
        return NULL; 
    } else {
        node *node = pq->head;
        pq->head = pq->head->next;
        node->next = NULL;
        return node;
    }
}

void print_priority_queue(priority_queue *pq)
{
    node* current = pq->head;
    
    while(current!=NULL){
        printf("%c ", *(unsigned char*)current->item);
        current = current->next;
    }
}

/*
* hash
*/

hash_table* create_hash_table()
{
    hash_table *new_hash_table =
(hash_table*) malloc(sizeof(hash_table));
    int i;
  
    for (i = 0; i < MAX; i++) {
        new_hash_table->table[i] = NULL;
    }

    return new_hash_table;
}

void put(hash_table *ht, int key, char *bit, void *item)
{
    int i;
    int h = *(unsigned char*) item;
    element *new_element = (element*) malloc(sizeof(element));
    new_element->key = key;

    for(i=0; i<key; i++) {
        new_element->string[i] = bit[i];
    }
    
    ht->table[h] = new_element;
}

void print_hash(hash_table *ht)
{
    int i, j;
    
    for(i=0; i<MAX; i++){
        if(ht->table[i]!=NULL){
            printf("%d: ", i);
        }
        
        for(j=0; j<ht->table[i]->key; j++){
            printf("%c ", ht->table[i]->string[j]);
        }
        printf("\n");
    }
}
/*
* arvore
*/

int is_empty_bt(binary_tree *bt){
    if(bt==NULL){
        return 1;
    }else{
        return 0;
    }
}

binary_tree* create_empty_binary_tree()
{
    return NULL;
}

binary_tree* create_binary_tree(
node *node_bt, binary_tree *left, binary_tree *right)
{
    binary_tree *new_binary_tree = (binary_tree*) malloc(sizeof(binary_tree));
    new_binary_tree->node_bt = node_bt;
    new_binary_tree->left = left;
    new_binary_tree->right = right;

    return new_binary_tree;
}

void print_in_order(binary_tree *bt)
{
    if (!is_empty_bt(bt)) {
        print_in_order(bt->left);
        printf("%d\n",bt->node_bt->priority);
        print_in_order(bt->right);
    }
}

void print_pre_order(binary_tree *bt)
{
    if (!is_empty_bt(bt)) {
        printf("%d\n",bt->node_bt->priority);
        print_pre_order(bt->left);
        print_pre_order(bt->right);
    }
}

void print_post_order(binary_tree *bt)
{
    if (!is_empty_bt(bt)) {
        print_post_order(bt->left);
        print_post_order(bt->right);
        printf("%d\n",bt->node_bt->priority);
    }
}

binary_tree* search(binary_tree *bt, node* node_bt)
{
    if ((bt == NULL) || (bt->node_bt->item = node_bt->item)) {
        return bt;
    } else if (bt->node_bt->item > node_bt->item) {
        return search(bt->left, node_bt->item);
    } else {
        return search(bt->right, node_bt->item);
    }
}

binary_tree* add(binary_tree *bt, node* node_bt)
{
    if (bt == NULL) {
        bt = create_binary_tree(node_bt, NULL, NULL);
    } else if (bt->node_bt->item > node_bt->item) {
        bt->left = add(bt->left, node_bt);
    } else {
        bt->right = add(bt->right, node_bt);
    }

    return bt;
}


int main() {
    return 0;
}
