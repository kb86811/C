#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#define MAX_CHAIN_BYTES  100
//uhdudh
typedef struct _Chain
{
	size_t  Seqlen;  // Number of letters in sequence
	unsigned char seq[MAX_CHAIN_BYTES];
} Chain;

void assigner(char ele, char arr[], int *j){
				unsigned char A = 0;
				unsigned char C= 1;
				unsigned char G = 2;
				unsigned char T = 3;
				int val= *j;
					if(ele==A){
						arr[val]='A';
						*j=val+1;
					}
					else if(ele==C){
						arr[val]='C';
						*j=val+1; //j will be incremented by one
					}
					else if(ele==G){
						arr[val]='G';
						*j=val+1;
					}
					else if(ele==T){
						arr[val]='T';
						*j=val+1;
					}
}

void showMenu() {
	printf("Menu choice                                                               Valid User input choices\n");
	printf("read DNA sequence from a file                                                      '1'\n");
	printf("save the curren sequence to a file                                                 '2'\n");
	printf("print the current sequence                                                         '3'\n");
	printf("splice and insert a sub-sequeunce                                                  '4'\n");
	printf("remove a sub- sequence                                                             '5'\n");
	printf("replace a sub-sequence with anoter sub-sequence                                    '6' \n");
	printf("exit program                                                                       '7'\n");
}



int main(){
	char chrs[400];// this will hold the ATCG sequence that will be decrypted from the binary file
	FILE *inputfile;//incoming input file pointer
	FILE *outputfile;//output file to write to
	Chain dna;//chain strcuts variable
	int optiontracker=0; // this is used to make sure required options are chosen before moving on to the nnext options.
	int userinput;
	int tracker;// this will track the chars inserted and removed from the chrars variable
	//int numofchar;// this will track the number of chracters we inserterd in the char array so we will not where when
	//writing to the binary file to stop writing 
	char buffer[50];// used to get file name
	while(1){
		showMenu();//menu wil be shown
		printf("\nplease choose from the menu above\n");
		scanf("%d",&userinput);
		getchar();
		int size;// this is the size of the sequence i.e the len of array sequence;

		switch(userinput){
			case 1:
			{
				printf("please enter a file name containing DNA sequence in binary\n");
				fgets(buffer,50,stdin);
				buffer[strlen(buffer)-1]='\0';
				inputfile=fopen(buffer,"rb");
				if(inputfile == NULL){
					printf("ERORR WITH OPENING FILE \n\n");
					break;
				}
				//where to put read data, size of the data to read, number of data with this size to read, where to read it from
				//fread returns 1 when reading is successfull.
				if(fread(&dna,sizeof(Chain),1,inputfile)==1){
					printf("inumber of characters is chracters ==%zd \n",dna.Seqlen);
				printf("this is the number of unsigned chrs in the actual seq==%zd\n",strlen(dna.seq));
					optiontracker++;
					fclose(inputfile);
				}

				size =strlen(dna.seq);
				size_t	numofchar = dna.Seqlen;
			printf("number of chracter is %d\n",numofchar);
				//tracker = numofchr % 4;
				int j=0;  //a counter that is used to insert each read symbols to chrs b
				int itracker=-1;
				for(int i=0;i<size;i++){
					unsigned char chr=dna.seq[i];//10101010
					itracker++;
					for(int k=0;k<4;k++){
						unsigned char char1;
						unsigned char char2;
						unsigned char char3;
						unsigned char char4;
						if(k==0){
						 char1=chr>>6;//00000010
						assigner(char1,chrs,&j);
						if(j>=numofchar)
										break;
						}
							else if(k==1){
								 char2=chr>>4;//00001010
								char2=char2 & 3;//00000010
								assigner(char2,chrs,&j);
									if(j>=numofchar)
										break;


						}
							else if (k==2){
								char3 = chr>>2; //10101000
								char3=char3 & 3;
								assigner(char3,chrs,&j);
								if(j>=numofchar)
										break;


						}
							else{
							 char4=chr & 3;
							assigner(char4,chrs,&j);
							if(j>=numofchar)
								break;


						}
						
					}
					printf("j is %d\n",j);
				}
				printf("j==%d\n",j);
				chrs[numofchar]='\0';

				//printf(" len is %s\n %d\n i iterates %d times",chrs,strlen(chrs),itracker);
				break;
			}
			case 2:
				if(optiontracker!=1)
					break;
				printf("enter file name to save the data in the chain strcut\n");
				fgets(buffer,50,stdin);
				buffer[strlen(buffer)-1]='\0';
				outputfile =fopen(buffer,"wb");
				if(outputfile==NULL){
					printf("error with writing to the file please check\n");
					break;
				}
				fwrite(&dna,sizeof(Chain),1,outputfile);
				fclose(outputfile);
				break;


			case 3:
				if(optiontracker!=1){
					break;}
				printf("%s\n",chrs);
				break;
			case 4:
				{
					if(optiontracker!=1){
						break;}
					char subseq[30];
					char pos[20];
					printf("please type the sub sequence you want to insert\n");
					fgets(subseq,29,stdin);
					subseq[strlen(subseq)-1]='\0';
					printf("please type the position you want to insert in the sequence\n");
					fgets(pos,19,stdin);
					pos[strlen(pos)-1]='\0';
					char *p1;
					char *p2;
					char *p3;
					int shift =strlen(pos);
					char newchar[400];//this will hold the isnerted array
					char copychar[400];
					strcpy(copychar,chrs);//copy fron the original array sequence
					p2=copychar;
					p3=copychar;
					int sizet;
					int tr=0;
					while((p1=strstr(p2,pos))){
						char t[2];
						t[0]=*p1;
						*p1='\0';
						if(tr==0){
							strcpy(newchar,p3);}
						else {
							strcat(newchar,p3);}
						tr++;
						sizet = strlen(copychar);
						strcat(newchar,pos);
						strcat(newchar,subseq);
						*p1=t[0];
						p3=p1+strlen(pos);
						p1++;
						p2=p1;
					}
					int y=sizet+strlen(pos);
					int a=strlen(newchar);
					for ( y=y;y<400;y++){
						newchar[a]=copychar[y];
						a++;

					}
					strcpy(chrs,newchar);

					break;}
			case 5:
				{
					if(optiontracker!=1){
						break;}

					char cpycode[400];// array where we will copy from the sequence
					char remchar[30];//buffer for incming argument
					printf("\ninsert a sub sequence to remove  :");
					fgets(remchar, 29,stdin);
					remchar[strlen(remchar)-1]='\0';//sets the last chars to null
					strcpy(cpycode,chrs);//copies the sequence from seqeunce 
					char newchars[400];//buffer wehre we will put the new arrays
					char *ptr1;
					char *ptr2=cpycode;
					//char *ptr3;
					int p=0;
					while((ptr1=strstr(ptr2,remchar))){
						char t[2];
						t[0]=*ptr1;
						*ptr1='\0';
						if(p>0){
							strcat(newchars,ptr2);


							p++;}
						else{
							strcpy(newchars,ptr2);
							p++;}
						ptr2=ptr1;
						*ptr1=t[0];
						ptr1++;
						ptr2=ptr2+strlen(remchar);
					}
					strcat(newchars,ptr2);
					strcpy(chrs,newchars);
					break;}
			case 6:{
				       if(optiontracker!=1){
					       break;}
				       char olseq[400];//to hold the sequence
				       char sub[40];//sequence that will be removed
				       char rep[40];//ssequence that will be inserted in its place
				       printf("please enter sub sequence to delete\n");
				       fgets(sub,39,stdin);
				       sub[strlen(sub)-1]='\0';
				       printf("\nplease enter replacement sequence\n");
				       fgets(rep,39,stdin);
				       rep[strlen(rep)-1]='\0';
				       char seq1[400]; //updated sequence
				       strcpy(olseq,chrs);//copies the orginal array
				       char *p1=olseq;
				       char *p2=olseq;
				       char *p3;
				       int q=0;
				       while((p3=strstr(p2,sub))){
					       char d[2];
					       d[0]=*p3;
					       *p3='\0';
					       if(q>0){
						       strcat(seq1,p1);
						       strcat(seq1,rep);
						       q++;

					       }else{
						       strcpy(seq1,p1);
						       strcat(seq1,rep);
						       q++;
					       }p1=p3+strlen(sub);
					       *p3=d[0];
					       p3=p3+1;
					       p2=p3;
				       }
				       strcat(seq1,p1);
				       strcpy(chrs,seq1);

				       break;
			       }
			case 7:
			       printf("good bye!\n");
			       return 0;
			       exit(0);

		}
	}
}
