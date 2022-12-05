#include <stdio.h>
#include <stdlib.h>




const char alphabet[53] = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ";


char *findMatchingLetters(char *w1,char *w2){
	char buff[512];
	int i =0;
	int j =0;
	int sizeOfReturnedLetters = 0;
	while(w1[i] != '\0'){
		j = 0;
		while(w2[j] != '\0'){
		 	if(w1[i] == w2[j]){
				buff[sizeOfReturnedLetters] = w1[i];		
			sizeOfReturnedLetters++;
			}
		j ++;	
		}
	i++;
	}
	printf("%d",sizeOfReturnedLetters);
	char *letters = calloc(sizeOfReturnedLetters+1,sizeof(char));
	for(i = 0;i<sizeOfReturnedLetters;i++){
	letters[i] = buff[i];
	}
	letters[sizeOfReturnedLetters] = '\0';
	return letters;

}
char findLetter(char *w2,char *w3){
	int i =0;
	int j =0;
	char letter;
	while(w2[i] != '\0'){
		j=0;
		while(w3[j] !='\0'){
			if(w3[j]==w2[i]){
			letter = w3[j];
			printf("LITERA TO: %c ", letter);
			}
		j++;
		}
	
	i++;
	}	
	return letter;
}





char *transformIntoString(char *buff_w, int sizeOfBuff){
	int i = 0;
	while(i < sizeOfBuff){
	if(buff_w[i]== '\0'){
	int sizeOfWord = i;
	char *word = malloc((sizeOfWord+1)*sizeof(char));
	for(int j=0; j <sizeOfWord;j++){
		 word[j] = buff_w[j];
		}
	word[sizeOfWord] = '\0';
	return word;
	}
	i++;
}
}


int findWordSize(char *buff_w){
	int i = 0;
	while(i < 512){	
	if(buff_w[i]== '\0')
	{
	int sizeOfWord = i+1;
	return sizeOfWord;
	
	}//if
	i++;
}//while
 printf("ERROR:FindWordSize!!!");
 return -1;
}//int


int calcScore(FILE *fp){
	int score = 0;
	char buff[512];
	int i = 0;
	char *word;
	char *word1;
	char *word2;
	char *word3;
	char letter;
	int w1len=0;
	int w2len = 0;
	int w3len = 0;
	while(fscanf(fp,"%s",buff) != EOF){
		word = transformIntoString(buff,512);
		if(i == 0){
			word1 = word;
			w1len = findWordSize(word);
			printf("\nw1len i00 AAAAAAAAAAAA %d\n",w1len);
		}
		else if(i == 1){
			if(findWordSize(word) > w1len || findWordSize(word) == w1len){
				printf("\n%s jest wieksze od %s\n i11",word,word1);
				word2 = word1;
				word1 = word;
				w2len = w1len;
				printf("\nw2len i11: %d\n",w2len);
				w1len = findWordSize(word);
			}
			else
			{
				word2 = word;
				w2len = findWordSize(word);
			}	
		}
		else if(i == 2)
		{
		i = -1;
		if(findWordSize(word) > w1len || findWordSize(word) == w1len){
			printf("\n%s jest wieksze od %s\n i21",word,word1);
			word3 = word2;
			word2 = word1;
			word1 = word;
			w3len = w2len;
		}
		else if(findWordSize(word) > w2len)
		{
		printf("\n%s jest wieksze od %s\n i22",word,word2);
		word3 = word2;
		word2 = word;
		w3len = w2len;
		}
		else if(findWordSize(word) < w2len || findWordSize(word) ==w2len)
		{
		word3 = word;
		w3len = findWordSize(word);
		}
		printf("\n%d %d %d",w1len,w2len,w3len);
		w1len = w2len = w3len = 0;
		printf("\n%s \n%s \n%s \n",word1,word2,word3);
		letter = findLetter(findMatchingLetters(word1,word2),findMatchingLetters(word1,word3));
		printf("LITERA_CALC_SCORE= %c",letter);
			for(int j =0; j<53; j++)
			{
				if(letter == alphabet[j])
					score = score + j + 1;
			}//for
		}//if

		i++;
	}//while
	return score;
}//int


int main(){
	FILE *input;
	input = fopen("input.txt","r");
	int score = calcScore(input);
	printf("Score: %d",score);
	fclose(input);
}//main
