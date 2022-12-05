#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

int *getNumbers(char *pair){
/****************************
 * pair = (x-x,x-x\)
 * *************************/
	char tmp[3] = "00";
	int i = 0;
	int p_i = 0;
	int n11 = 0;
	int n12 = 0;
	int n21 = 0;
	int n22 = 0;
	while(pair[i] != '-'){	
			tmp[i] = pair[i];
			i++;
	}
	if(i == 1)
		n11=tmp[0]-'0';
	else
		n11 = atoi(tmp);
	p_i = i+1;
	i = 0;
	tmp[0] = '0';
	tmp[1] = '0';
	while(pair[p_i+i] != ','){
		tmp[i] = pair[p_i+i];
		i++;
	}
	if(i == 1)
		n12=tmp[0] - '0';
	else{
		n12 = atoi(tmp);
	}

	p_i =p_i+ i+1;
	tmp[0] = '0';
	tmp[1] = '0';
	i = 0;
	while(pair[p_i+i] != '-'){	
			tmp[i] = pair[p_i+i];
			i++;
	}	
	if(i == 1){
		n21=tmp[0] - '0';
	}
	else{
		n21 = atoi(tmp);
	}
	p_i = p_i + i + 1;
	i = 0;
	tmp[0] = '0';
	tmp[1] = '0';
	while(pair[p_i+i] != '\0'){
		tmp[i] = pair[p_i+i];
		i++;
	}
	if(i == 1)
		n22=tmp[0] - '0';
	else
		n22 = atoi(tmp);
		
	int *numbers = calloc(4,sizeof(int));
	numbers[0] = n11;
	numbers[1] = n12;
	numbers[2] = n21;
	numbers[3] = n22;
	return numbers;
}

int checkOverleaps(int *num){
	int x = num[0];
	int y = num[1];
	int x_t = num[2];
	int y_t = num[3];
	if(y < x_t || x > y_t){
		return 0;
}
	else
		return 1;

}


int main(){
	FILE *input;
	input = fopen("input.txt","r");
	char buff[32];
	int score = 0;
	while(fscanf(input,"%s",buff) != EOF){
		score = score + checkOverleaps(getNumbers(buff));
	}
	printf("Score: %d \n",score);
	fclose(input);



}
