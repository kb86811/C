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