#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <ctype.h>
#include "item.h"

int main(){
    ordernode *head;// this is pointer to the head of the ordernode
    ordernode *ptr=NULL;
	char buffer1[SIZE];//used to hold responses from the user
	//char buffer2[10];
	char location[SIZE];//location of the resturant
	char restaurant[SIZE];//name of the resturant to deliver to 
	
	int check=1;
	while(check){
	    printf("new delivery order?  (y/n)\n");
	    fgets(buffer1,5,stdin);//response getter
	   // getchar();
		 //chere we check if the reposne is y or  n or something else
	    if( (buffer1[0]!='y' && buffer1[0]!='n')){
	        printf("INVALID ENTRY. TRY AGAIN\n");
	        continue;
	    }
		//here if the anser is 'y' it gets the location of the resturant and where to 
		//deliver continually asks for food item until the 
	    else if(buffer1[0]=='y'){
	        ordernode * neworder=NULL;
			neworder=(ordernode *) dmalloc(sizeof(ordernode));
			neworder->data=NULL;
			neworder->deliverTo=NULL;
			neworder->restaurant=NULL;
			neworder->next=NULL;
	        printf("Enter location of delivery\n");
	        fgets(location,99,stdin);
	        location[strlen(location)-1]='\0';
	        char * locptr = stringcopy(location);
	        neworder->deliverTo=locptr;
	        
	        //printf("%s",location);
	      //fflush(stdin);
	        printf("enter resturant name to pick delivery\n");
	        fgets(restaurant,99,stdin);
	        restaurant[strlen(restaurant)-1]='\0';
	        char * resptr = stringcopy(restaurant);
	        neworder->restaurant=resptr;
	        itemList * item=createItem();
	        char itemname[SIZE];
	        int l=1;
			//this while loop continually asks for food items unitl the user
			//insert nothing
	        while(l){
	            printf("enter food item\n");
	            fflush(stdin);
	            fgets(itemname,49,stdin);
	            if(itemname[0]=='\n'){
	                l=0;
	            }
	            else{
	                itemname[strlen(itemname)-1]='\0';
					
					insert(itemname,item);
	                continue;
	            }
	        }
	        neworder->data=item;
			//this part is where the new order entered will be inserted into the linked list
	        if(ptr==NULL){
	            ptr=neworder;
	            head=neworder;
	        }
	        else{
	            ptr->next=neworder;
	           // printf("%s\n",ptr->deliverTo);
	            ptr=neworder;
	            //printf("%s\n",ptr->deliverTo);
	            
	        }
	    }
	    else {
			//this prints out the orders using the printorder function implemnted in item.c
	         printorder(head); 
	
	break;
	    }
	}



	return 0;
}
