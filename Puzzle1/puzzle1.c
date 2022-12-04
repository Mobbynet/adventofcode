#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>

int findNumOfElf(FILE *fp, int elfCord[]){
	int numOfSpc = 0;
	char ch;
	int wasNbefore = 0;
	int numOfN = 0;
	int i = 0;
	while(fp)
	{
		ch = fgetc(fp);
		printf("%c",ch);
		if(ch == EOF){
				numOfSpc++;
				elfCord[i] = numOfN;
				printf(" %d ", numOfN);
				i++;
				return numOfSpc;
	
		}
		else if(ch == '\n'){	
			if(wasNbefore == 1){
				numOfSpc++;
				elfCord[i] = numOfN;
				printf(" %d ", numOfN);
				i++;
			}
			else {
			wasNbefore = 1;
			numOfN++;
			}
					}
		else
			wasNbefore = 0;
		 } //while
	} //int



int findBiggestSum(FILE *fp, int numOfElf, int elfCord[]){
	int elfNum = 1;
	int sum = 0;
	int biggest_sum = 0;
	int sec_biggest_sum = 0;
	int third_biggest_sum = 0;
	char buff[10];
	int i = 0;
	int n = 1;
	while(fscanf(fp,"%s \n" , buff) != EOF)
	{
		printf("NumRead: %d \n", atoi(buff));
		if(n == elfCord[i])
		{
			sum = sum +atoi(buff);
			printf("TO DZIALA!!!! Sum: %d", sum);
			if(sum > biggest_sum){
				third_biggest_sum = sec_biggest_sum;
				sec_biggest_sum = biggest_sum;
				biggest_sum = sum;
				}
			else if(sum > sec_biggest_sum && sum !=biggest_sum){
				third_biggest_sum = sec_biggest_sum;
				sec_biggest_sum = sum;
			}
			else if(sum > third_biggest_sum && sum != sec_biggest_sum)
				third_biggest_sum = sum;
			
			elfNum++;
			sum = 0;
			i ++;
			n ++;
		} //if
		else
			{
			sum =sum + atoi(buff);	
			printf("Sum: %d \n",sum);
			n ++;	
		}
	} //while
	printf("%d %d %d",biggest_sum, sec_biggest_sum,third_biggest_sum);
	return biggest_sum+sec_biggest_sum+third_biggest_sum;
} //int


int main(){
	FILE *input;
	input = fopen("input.txt", "r");
	printf("Plik Otwarty \n");
	int elfCord[512];
	int numOfElf = findNumOfElf(input, elfCord);
	printf("Num od spaces %d",numOfElf);
	fclose(input);
	input = fopen("input.txt", "r");
	printf("%d,%d,%d,%d,%d \n", elfCord[0],elfCord[1],elfCord[2],elfCord[3],elfCord[4]);
	printf("Plik Otwarty \n");
	printf("Wynik??: %d", findBiggestSum(input, numOfElf, elfCord));
	fclose(input);
}





