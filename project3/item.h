#ifndef ITEMLIST
#define ITEMLIST
#include <stddef.h>

typedef struct _node
{
	char *data;  //Food Item Name
		struct _node *next;
} node;

typedef struct _itemList
{
	node *head;   //Pointer to first food item for the order (alphabetical)
		int count;  //Number of food items in the order
} itemList;

typedef struct _ordernode
{
	itemList *data;
	char *deliverTo; 
	char *restaurant;
	struct _ordernode *next;
} ordernode;
#define SIZE 50
itemList *createItem();
int insert(char *str,itemList *s);
void printItems(itemList *s);
void * dmalloc(size_t size);
void printorder(ordernode *s);
char * stringcopy(char *s);
#endif
