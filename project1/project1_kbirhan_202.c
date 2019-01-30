#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <ctype.h>
#define SIZE 44
const char CHAR[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789 .,;!-'?";


void ShowMenu() {
printf("\n Menu choice                                                  Valid User input choices\n\n");
printf("Enter a random number seed to generate the Tabula Recta         '1'\n");
printf("Enter the Keyword                                               '2'\n");
printf("Enter a message to encrypt                                      '3'\n");
printf("Enter a message to decrypt                                      '4'\n");
printf("Exit the program                                                '5'\n");
}
int getposition(const char *str, const char c)
{
    int retVal = -1;
    char *pos = strchr(str, c);

    if (pos != NULL)
    {
        retVal = pos - str;
    }

    return retVal;
}

void key()
{
    char keywords[21];
    printf("please enter keyword:");
    fgets(keywords,21,stdin);
    printf("%s",keywords);

}


int main ()
{
 char decodedmessage[251];// used by option 3 
char enmess[251];//used to store incoming encrypted message
char encodedmessage[251];//used to return the decrypted message
char keyword[21];
char messages[251];
int  userinput;
char table[SIZE][SIZE];
int check=0;
while(1){
ShowMenu();
scanf(" %d",&userinput);
getchar();
int seed;
char charSet[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789 .,;!-'?";
switch(userinput){
	case 1:
                printf("Please Enter a random number seed:");
                scanf("%d",&seed);
		srandom(seed);
                getchar();
                for (int i=SIZE-1; i>0; i--){
                    char temp;
                    int idx = random()%(i+1);
                    temp = charSet[idx];
                    charSet[idx]=charSet[i];
                    charSet[i]=temp;
                }
                int k,t=0;

                for(int i=0;i<44;i++){
                    k=t;
printf("\n");
                
                    for(int j=0;j<44;j++){
                        if(i==0){
                            table[i][j]=charSet[j];
printf("%c ", table[i][j]);
                        }else{

                            if(k==44){
                                k=0;
                            }
                            table[i][j]=charSet[k];
                            k++;
printf("%c ",table[i][j]);
                          
                        }
                    }
                    t++;
                }
		check++;
                break;
	case 2:
	              printf("\n please enter keyword: ");
                fgets(keyword,20,stdin);
                if(keyword[strlen(keyword)-1]=='\n'){
                    keyword[strlen(keyword)-1]='\0';}
		for(int i=0;i<strlen(keyword);i++){
			keyword[i]=toupper(keyword[i]);
		
}
		check++;
break;               
           
	case 3:
		   if(check !=2){
printf("enter seed and keywords firsit\n");

                    break;}
                
                else {
                    printf("Enter message to encrypt: ");
                    fgets(messages,250,stdin);
                    if(messages[strlen(messages)-1]=='\n')
                        messages[strlen(messages)-1]='\0';
                   for(int i=0;i<strlen(messages);i++){
			messages[i]=toupper(messages[i]);
			}
		int row;
		int col;
		int i=0;
printf("i=%d\n",i);
		int n=0;
		while(i<strlen(messages)){
			if(n==strlen(keyword)){
				n=0;}
			row=getposition(CHAR,keyword[n]);
			col=getposition(CHAR,messages[i]);
			decodedmessage[i]=table[row][col];
//printf("%c  row=%d col=%d\n",table[row][col],row,col);
			i++;
//printf("%d\n",i);
			n++;
//printf("%d\n",j);			
}
		decodedmessage[i]='\0';
		    printf("your encrypted message is(%s)\n",decodedmessage);
break;		
                }
	case 4:
		if(check!=2){
printf("enter seed and keywords first");
			break;}
		else{
printf("please enter encrypted message: ");
fgets(enmess,250,stdin);
if(enmess[strlen(enmess)-1]=='\n'){
	enmess[strlen(enmess)-1]='\0';}
                for(int i=0;i<strlen(enmess);i++){
                        enmess[i]=toupper(enmess[i]);}
printf("uppercase %s\n",enmess);
int l=0;
int m=0;
int row;
printf("enmess len is %d\n",strlen(enmess));
while(l<strlen(enmess)){
 if(m==strlen(keyword)){
m=0;}
row =getposition(CHAR,keyword[m]);
for(int k=0;k<44;k++){
if(table[row][k]==enmess[l]){
printf("%c\n",table[row][k]);
//int pos=getposition(CHAR,table[row][k]);
encodedmessage[l]=CHAR[k];
//printf("%c\n",encodedmessage[l]);
k=44;
}
}
l++;
m++;		
}
printf("plain text message is %s:\n",encodedmessage);
break;}			
	case 5:
	printf("good bye! \n");
	return 0;
	exit(0);
     default:
	printf ("invalid input try again\n");
   }
}
}
