#include <stdio.h>
#include <stdlib.h>

#define NUM_OF_COLUMNS 9
#define NUM_OF_ROWS 8
#define MAX_STACK_LEN 256



typedef struct{
	int len;
	char stack[MAX_STACK_LEN];

}Stack;

Stack createStack(){
	Stack st;
	st.len = 0;
	for(int i =0; i < MAX_STACK_LEN; i++)
		st.stack[i] = '0';

	return st;
}
Stack fillStack(Stack *st,char *word,int loc){
	int i =0;
	while(i < (NUM_OF_ROWS-loc)){
		st->stack[i] = word[i];
	i++;
	}
	st->len = i;
	return *st;
}
void move1to2(Stack *st1, Stack *st2){
	Stack *tmp1 = (Stack*)(st1);
	Stack *tmp2 = (Stack*)(st2);
	tmp2->stack[tmp2->len + 1] = st1->stack[st1->len];
	tmp1->stack[tmp1->len] = '0';
	tmp2->len = st2->len +1;
	tmp1->len = st1->len - 1;
	st1 = tmp1;
	st2 = tmp2;
}
int main(){
	FILE *input_stack;
	input_stack = fopen("input_stacks.txt","r");
	int location_top_stack[NUM_OF_COLUMNS];
	for(int i = 0; i < NUM_OF_COLUMNS; i++)
		location_top_stack[i] = -1;
	int f_c = 0;
	char buff[4*NUM_OF_COLUMNS];
	char output_b[NUM_OF_COLUMNS][NUM_OF_COLUMNS];
	int row_searched = 0;
	
	while(fgets(buff,4*NUM_OF_COLUMNS,input_stack)!=NULL){
		printf("%s\n",buff);
		for(int i = 0; i < 4*NUM_OF_COLUMNS; i++){
			//printf("%c",buff[4*i-4]);
			if(location_top_stack[i] == -1 && buff[4*i] == '['){
					location_top_stack[i] = row_searched/2;
					//printf("Location found: %d i%d",location_top_stack[i],i);
			}
		}
		/*printf("LOCATIONS");
		for(int i =0; i < NUM_OF_COLUMNS; i++)
			printf(" %d ",location_top_stack[i]);
		printf("\n");*/
	f_c = 0;
	for(int i = 0; i < NUM_OF_COLUMNS; i++)
		if(location_top_stack[i] != -1 && row_searched%2 == 0)
			f_c++;


	printf("Found columns: %d", f_c);	
	if(row_searched%2 == 0  && row_searched<(NUM_OF_ROWS)*2){
		printf("\nR%d",row_searched);
		for(int w =0; w < NUM_OF_COLUMNS;w++)
			if(location_top_stack[w] != -1){
				output_b[row_searched/2][w] = buff[4*w+1];
				//printf("x%d y%d buff%c output:%c\n", row_searched/2,w,buff[4*w+1],output_b[row_searched/2][w]);
				//printf("%c i%d  w: %d locw:%d\n",buff[4*w-3],(NUM_OF_ROWS - (row_searched/2)),w-1,location_top_stack[w-1]);
				//}
			}
			else
				output_b[row_searched/2][w] = '0';
		}
	row_searched++;
	}
	//KONIEC WCZYTYWANIA STACKA ILOSC KODU I CZASU JAKA TO WCHLONELO JEST NIESAMOWITE
	printf("\n");
	/*for(int i=0; i < NUM_OF_COLUMNS;i++){
		for(int j = 0; j < NUM_OF_ROWS; j++)
			printf("%c ",output_b[j][i]);
	printf("\n");
	}*/
	char t_input[NUM_OF_COLUMNS][NUM_OF_COLUMNS+1];
	for(int i = 0;i < NUM_OF_COLUMNS;i++){  //transpose output_b
		for(int j = 0;j< NUM_OF_COLUMNS-1;j++)
			t_input[i][NUM_OF_COLUMNS-j-2] = output_b[j][i];
	t_input[i][NUM_OF_COLUMNS-1] = '\0';
	}
	printf("\n");
	/*for(int i=0; i < NUM_OF_COLUMNS;i++){
		for(int j = 0; j < NUM_OF_COLUMNS; j++)
			printf("%c ",t_input[i][j]);
	printf("\n");
	printf("%s \n", t_input[0]);
	}*/
	fclose(input_stack);
	Stack stacks[NUM_OF_COLUMNS];
	Stack temp;
	for(int i = 0; i < NUM_OF_COLUMNS;i++){
		temp = createStack();
		stacks[i] = fillStack(&temp,t_input[i],location_top_stack[i]);
	}
	for(int i=0; i < NUM_OF_COLUMNS;i++){
		for(int j = 0; j < stacks[i].len; j++)
			printf("%c ",stacks[i].stack[j]);

		printf("  %d",stacks[i].len);
	printf("\n");
	}
	FILE *input_moves;
	input_moves = fopen("input_moves.txt","r");
	char buff_t[128];
	int x_t = 0;
	int y_t = 0;
	int z_t = 0;
	int i_t = 0;
	int tabela[3048];
	for (int i =0;i < 3048; i++)
		tabela[i] = 0;
	while(fscanf(input_moves,"%s %d %s %d %s %d\n",buff_t,&x_t,buff_t,&y_t,buff_t,&z_t) != EOF){
		tabela[i_t] = x_t;
		i_t++;
		tabela[i_t] = y_t;
		i_t++;
		tabela[i_t] = z_t;
		i_t++;
	}
	int a = 0;
	//while(tabela[a] != 0){
	//	printf("%d ",tabela[a]);
	//	a++;
	//}
	//a = 0;
	Stack temp1;
	Stack temp2;
	Stack *tmp1;
	Stack *tmp2;
	while(tabela[a] != 0){
		//printf("|%d::",tabela[a]);
			for(int b =0; b <tabela[a];b++){
				//printf(" %d %d ",tabela[a+1],tabela[a+2]);
				temp1 = stacks[tabela[a+1]-1];
				temp2 = stacks[tabela[a+2]-1];
				tmp1 = &temp1;
				tmp2 = &temp2;
				tmp2->stack[tmp2->len] = tmp1->stack[tmp1->len-1];
				tmp1->stack[tmp1->len] = '0';
				tmp2->len = (tmp2->len + 1);
				tmp1->len = (tmp1->len - 1);
				//printf("tmp1:%c tmp2:%c tmp1len:%d tmp2len:%d \n",tmp1->stack[tmp1->len],tmp2->stack[tmp2->len],tmp1->len,tmp2->len);
				stacks[tabela[a+1]-1] = *tmp1;
				stacks[tabela[a+2]-1] = *tmp2;
				printf("Moved %d to %d. tmp1:%c tmp2:%c tmp1p:%c tmp1len:%d tmp2len:%d \n",tabela[a+1],tabela[a+2],tmp1->stack[tmp1->len],tmp2->stack[tmp2->len],tmp1->stack[tmp1->len-1],tmp1->len,tmp2->len);

			}
		printf("\n");
		a = a + 3;
	}
	printf("\n");
	for(int i=0; i < NUM_OF_COLUMNS;i++){
		for(int j = 0; j < stacks[i].len; j++)
			printf("%c ",stacks[i].stack[j]);
	printf("\n");
	}
	return 0;
}



















