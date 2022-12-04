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
	 switch(you){
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
	 }//switch
	switch(opponent){
		case'A':
			opp_score =opp_score + 1;
			break;
		case'B':
			opp_score = opp_score + 2;
			break;
		case'C':
			opp_score = opp_score + 3;
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






