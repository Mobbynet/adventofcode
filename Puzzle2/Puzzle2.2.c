#include <stdio.h>

int calcScore(FILE *fp)
{
char opponent;	
char you;
int score = 0;
int opp_score = 0;
while(fscanf(fp,"%c %c\n",&opponent,&you) != EOF)
	{	
	 printf("%c,%c \n",opponent,you);
	/* switch(you){
		case'X': //rock
			score =score + 1;
			if(opponent =='A'){ //rock
				score = score +3;
			        opp_score = opp_score +3;	
				}
			else if(opponent =='B'){ //paper
				opp_score = opp_score +6; 
				}
			else if(opponent =='C'){ //scicorrs
				score = score + 6;
			}
			
			break;
		case'Y': //paper 
			score = score + 2;
			if(opponent =='B'){ //paper
				score = score +3;
			        opp_score = opp_score +3;	
				}
			else if(opponent =='C'){ //scicorrs
				opp_score = opp_score +6; 
				}
			else if(opponent =='A'){ //rock
				score = score + 6;
			}
			
			break;
		case'Z': //scicorrs
			score = score + 3;
			if(opponent =='C'){ //scicorrs
				score = score +3;
			        opp_score = opp_score +3;	
				}
			else if(opponent =='A'){ //rock
				opp_score = opp_score +6; 
				}
			else if(opponent =='B'){ //paper
				score = score + 6;
			}
			
			break;
	 }//switch*/
	switch(opponent){
		case'A': //rock X:scisscors Y: rock Z: paper
			switch(you){
				case'X':
				score = score + 3;
				break;
				case'Y':
				score = score + 1 + 3;
				break;
				case'Z':
				score = score + 2 + 6;
				break;
			
			}
			break;
		case'B': //paper X:rock Y:paper Z:scisscors
			opp_score = opp_score + 2;
			switch(you){
				case'X':
				score = score + 1;
				break;
				case'Y':
				score = score + 2 + 3;
				break;
				case'Z':
				score = score + 3 + 6;
				break;
			
			}
			break;
		case'C': //sciscorss X:paper Y:sciscorss Z:rock
			opp_score = opp_score + 3;
			switch(you){
				case'X':
				score = score + 2;
				break;
				case'Y':
				score = score + 3 + 3;
				break;
				case'Z':
				score = score + 1 + 6;
				break;
			
			}
			break;
		}//switch

	
	
	}//while
	return score;
}//int





int main()
{
	FILE *input;
	input = fopen("input.txt","r");
	int score = calcScore(input);
	printf("Score: %d", score);
	fclose(input);

}






