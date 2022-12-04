#include <stdio.h>
#include <stdlib.h>


const char alphabet[53] = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ";

char findMatchingLetter(char word1[], char word2[]){
	char letter;
	int i = 0;
	int j = 0;
	int score = 0;
	while(word1[i] != '\0')
	{
		j = 0;
		while(word2[j] != '\0'){
			if(word1[i] == word2[j]){
				//printf("Znaleziono litere: %c \n", word2[j]);
				for(int w = 0; w<53; w++)
				{
					if(word1[i] == alphabet[w] && score < w+1){
						score = w + 1;
						letter = word1[i];
						//printf(" %d, %d \n",score,w+1);
						}//if
				}//for
				
				
				//printf(" %c ",letter);	
			}//if
			j++;
		}//while
		i++;
	}//while
	return letter;
}//char


char** getTwoWords(char *word,int sizeOfWord_t){
	int sizeOfnWord = (sizeOfWord_t - 1)/2;
	char ** sub_str = malloc(2 *sizeof(char*));
	for(int i =0; i < 2; ++i){
		sub_str[i] = malloc((sizeOfnWord+1) * sizeof(char));	
	}//for
	for(int j =0;j<sizeOfnWord; ++j){
	sub_str[0][j] = word[j];
	}//for
	for(int w =0;w < sizeOfnWord; ++w){
	sub_str[1][w] = word[w+sizeOfnWord];
	}//for
	 printf("%s\n%s\n", sub_str[0],sub_str[1]);
		 
	return sub_str;
}//char**


char *transformIntoString(char *buff_w, int sizeOfBuff)
{
int i = 0;
while(i < sizeOfBuff)
{
	if(buff_w[i]== '\0')
	{
	int sizeOfWord = i;
	char *word = malloc(sizeOfWord*sizeof(char));
	for(int j=0; j <sizeOfWord;j++)
		{
		 word[j] = buff_w[j];
		}
	return word;
	}
	i++;
}
}
int findWordSize(char *buff_w)
{
int i = 0;
while(i < 512)
{
	if(buff_w[i]== '\0')
	{
	int sizeOfWord = i;
	return sizeOfWord;
	
	}//if
	i++;
}//while
 printf("ERROR:FindWordSize!!!");
 return -1;
}//int
int calcScore(FILE *fp)
{
	int score = 0;
	char *word;
	char **pointers;
	char letter;
	char buff[512];
	while(fscanf(fp,"%s",buff) != EOF)
	{
		word = transformIntoString(buff,512);
		pointers = getTwoWords(word,findWordSize(word));
		letter = findMatchingLetter(pointers[0],pointers[1]);
		for(int i = 0; i<53; i++)
		{
			if(letter == alphabet[i]){
				score = score + i + 1;
				printf(" %d, %d %c \n",score,i+1, letter);
			}
		
		}//for
	}//while
	

	return score;
}//int



int main(){
	char word[] = "abcdugcv";
	char **pointers = getTwoWords(word,sizeof(word));
	printf("%s \n%s \n",pointers[0], pointers[1]);
	char letter = findMatchingLetter(pointers[0],pointers[1]);
	printf("TEGO SZUKASZ %s   %ld  %c \n",word,sizeof(word), letter);
	char test[400];
	test[0] = 'a';
	test[1] = 'b';
	test[2] = 'c';
	test[3] = 'd';
	test[4] = 'e';
	test[5] = 'f';
	test[6] = 'g';
	test[7] = 'h';
	test[8] = 'i';
	test[9] = 'j';
	test[10] = '\0';
	char *nword = transformIntoString(test,sizeof(test));
	printf("%s   %ld\n",test,sizeof(test));
	printf("%s   %ld \n", nword,sizeof(*nword));
	FILE *input;
	input = fopen("input.txt","r");
	int score = calcScore(input);
	printf("Score: %d",score);
	fclose(input);

}//main
