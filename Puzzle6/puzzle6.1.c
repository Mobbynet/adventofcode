#include <stdlib.h>
#include <stdio.h>


const int first_w = 4;


int main(){
	FILE *fp;
	fp = fopen("input.txt","r");
	char buff[4096];
	fscanf(fp,"%s",buff);
	int i =0;
	int j = 0;
	int w = first_w;
	int best_w = first_w;
	int best_i = 0;
	while(i <4095){
		w = 0;
		j = 0;
		while(w == 0){
			w = first_w-j;
			printf("w:%d  ",w);	
			while(buff[i] != buff[i+w] && w >0)
					w--;
				
			printf("%d %d%c\n",i,j,buff[i+w]);
			j++;
			i++;
			if(j==first_w){
				best_i = i;	
				printf("%d",best_i-1);
				return 0;
			}
			
			 
			}		
		
		i=i+w-1;
	}
	fclose(fp);
	return 0;



}

