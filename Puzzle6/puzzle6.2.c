#include <stdlib.h>
#include <stdio.h>


const int first_w = 14;


int main(){
	FILE *fp;
	fp = fopen("input.txt","r");
	char buff[4096];
	fscanf(fp,"%s",buff);
	int duplicate = 0;
	for(int i =0; i < 4096;i++){
		for(int j = 1; j <= 13 && i-j >=0;j++){
			if(buff[i] == buff[i-j])
			{
				duplicate |= 1 <<j;

			}
		}
		if(i > 13 && (duplicate & 0b11111111111111) == 0){
			printf("%d",i+1); 
			return i +1;
		}

		duplicate <<= 1;
	}
	fclose(fp);
	printf("Szukanie nie powiodlo sie :((((");
	return 0;



}

