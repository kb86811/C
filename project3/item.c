#include "item.h"
#include <ctype.h>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>

// this method is used to compare two strings equality or inequality
int strcmpi(char *s, char *t)
{
	while (*s && tolower(*s) == tolower(*t))
	{
		s++;
		t++;
	}
	return tolower(*s) - tolower(*t);
}
// this method is used to allocate memory and returns pointer to the allocated memoery
void *dmalloc(size_t size)
{
	void *p = malloc(size);
	if (!p)
	{
		printf("memory allocation failed\n");
		exit(1);
	}
	return p;
}
// this is a method used to copy strings returns pointer to the string
char *stringcopy(char *s){
	int size=strlen(s);
	char * temp=(char *)dmalloc((size+1)*sizeof(char));
	temp[0]='i';
	strcpy(temp,s);
	return temp;
}
/* this method allocates memory with a check for successful allocation */
itemList *createItem(){
	itemList * temp = (itemList *) dmalloc(sizeof(itemList));
	temp->head=NULL;
	temp->count=0;
	return temp;
}
// this method is used to insert food item in the order delivery it accepts 
// a string representation of the food and pointer to the item list
int insert (char *str, itemList *s){
	node *temp=s->head; // pointer to the head of the food item
	char *str1=NULL; // char pointer 
	str1= stringcopy(str);// this copies the incoming string into str1 pointer
	
	//this if statment check if the head is empty or not if the head is pointing to NULL 
	//it creates malloc for a new node and sets the str1 to the new nodes data field then sets 
	//the new node data to str1 and sets the item list head to the new node
	if(s->head==NULL){
		node *newnode=NULL;
		newnode =dmalloc(sizeof(node));
		newnode->data=NULL;
		newnode->next=NULL;
		newnode->data=str1;
		s->head=newnode;
		s->count+=1;

	}
//here it compares the head's data filed with the incoming string using string comaprator function
//and if the string comes a head of the head data field. it creates a new node and sets the new node as the head of the item list and then it sets the older node to the 
//next item in the list and incremnt count by one. 
	else if(strcmpi(temp->data,str1)>0){
		node*newnode1=NULL;// pointer to node
		newnode1=dmalloc(sizeof(node)); // memory allocation
		newnode1->data=NULL;//intializes 
		newnode1->next=NULL;//initilizes 
		newnode1->data=str1;//sets the new node's data field to to incoming string
		newnode1->next=s->head;// sets head of the list as the next field to the new node 
		s->head=newnode1;//sets new node as the head of the item list 
		s->count+=1;//count incremented 


	}
	//in this part of the method first since we can have duplicate item in the food item it check for that. Then, iterate over the linked list 
	//until it find a place in the linked list where the string comes a head of the the node. and it creates a new node and insert that node into the linked list.
	else {
		if(strcmpi(temp->data,str1)==0){
			printf("you can't have duplicate food items in the food items\n");
			free(str1);
			return 0;
		}

		while((temp->next!=NULL)&& ((strcmpi(temp->next->data,str1))<0)){
			temp=temp->next;
		}
		//here it check if the strings are equal again
		if(strcmpi(temp->data,str1)==0){
			printf("You can't have duplicate items in the food items\n");
			free(str1);
			return 0;
		}
		//here also it check if the string is equl to the next food item in the link since this part inserts both at the end and in the middle of the node
		if((temp->next != NULL) && (strcmpi(temp->next->data,str1)==0)){
			printf("you can't have duplicate food items in the food items\n");
			free(str1);
			return 0;
		}
		node *newnode2=NULL;//pointer 
		 newnode2=dmalloc(sizeof(node));// allocates memory 
		 newnode2->data=NULL;//initilizes
		 newnode2->next=NULL;//initilies 
		newnode2->data=str1;//sets the data to the new node as str1
		newnode2->next = temp->next;// sets the next field of the new node as the next field of the current node
		temp->next=newnode2;// this sets the current node next node as the new node
		s->count+=1;// incoments counter by one
	}

	return 1;// retuns if node added successfully

}
// this method accepts pointer to an itemList and prints the food item in the linked 
// list one by one freeing the data stored in the food item  as it prints
void printItems(itemList *s){
	node * head=s->head;//pointer to the head
	node *temp;// holder for the next item
	while(head!=NULL){
		printf("food item: %s\n",head->data);
		free(head->data);//frees the head 
		temp=head;// sets temp to the current node
		head=head->next;// moves head to the next item
		free(temp);// frees the node
	}
	printf("\n");


}
//this is the main method that print the orders after the user is done with entering 
//orders.
void printorder(ordernode *s){
	ordernode *root=NULL;// this is pointer to ordernode
		root= s;// sets ordernode to the incoming order node
	ordernode *temp=NULL;//another ordernode pointer 
	printf("\n");
	printf("LIST OF DELIVERIES\n");
	// this while loop prints the resturant name, where to deliver to and the food items on bey one
	// in the linked list until there is no ordernode in the linked list
	while(root !=NULL){
		temp=root;
		printf("Delivery order from  %s has %d food item(s)\n",root->restaurant,root->data->count);
		printItems(root->data);
		free(root->data);//frees the data
		free(root->restaurant);//frees the restaurant field
		printf("Deliver To: %s\n",root->deliverTo);
		printf("\n");
		free(root->deliverTo);//fees deliverTo field
		root=root->next;// moves pointer to the next item
		free(temp);// fees the current ordernode
	}
}
