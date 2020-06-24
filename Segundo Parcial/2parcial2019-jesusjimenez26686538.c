#include <stdio.h>
#include <stdlib.h>
#define ANSI_COLOR_RED     "\x1b[31m"
#define ANSI_COLOR_RESET   "\x1b[0m"

int board[][10];
int score=0;
int shoots=0;
void game(int score,int board[][10]);
void draw(int shoots,int score,int tam, int board[tam][tam]);
void fill(int tam, int board[tam][tam]);
int jugada(int score,int tam,int board[tam][tam]);

int main(){
	
	game(score,board);
	
}
void game(int score,int board[][10]){
	int tam=0,tam1=0;
	int play=0;

	while(play==0){
		printf("Ingrese las filas del tablero: ");
		scanf("%d",&tam);
		printf("Ingrese las columnas del tablero: ");
		scanf("%d",&tam1);
		if(tam!=tam1){
			printf ("no es un cuadrado, vuelva a intentarlo.");
			system("pause");
		}	else{
			play++;
		}
		system("cls");
	}	
	
	while(play==1){
	fill(tam,board);
	shoots++;	
	score=jugada(score,tam,board);	
	if(score==100){
		play*=-1;
	}	else{
			system ("cls");
		}
	
	}
}
void fill(int tam, int board[tam][tam]){
	
	int i=0,j=0,mid,loop=0,plus=0;
	
	if(tam%2!=0){ mid=tam/2+1; }
	else{ mid=tam/2; }
	
	while (loop<mid){

	if(loop==0){
		for (i=0;i<tam;i++){
			for (j=0;j<tam;j++){
				if(i>0||j>0||i<tam-1||j<tam-1){
					board[i][j]=plus;
				}
			}
		}
	}	else{
			for (i=loop;i<tam-loop;i++){
				for (j=loop;j<tam-loop;j++){
						board[i][j]=plus;
				}
			}	
		}
	loop++;
	plus+=10;
	}
}		
void draw(int shoots,int score,int tam, int board[tam][tam]){
	
	int i=0,j=0,l=65;
		
	for (i=0;i<tam;i++){
		for (j=0;j<tam;j++){
			if(board[i][j]==5){
				printf (ANSI_COLOR_RED"X"ANSI_COLOR_RESET" |");
			}else{
				if(board[i][j]==0){
					printf("%d |",board[i][j]);
					//getch();	
				}	else{
					printf("%d|",board[i][j]);
					//getch();
					}
			}
		}
	printf("\n");
	}
	printf ("\n\nPuntuacion: %d\n",score);
	if(score>100){
		printf ("\n\nJugada invalidada.\nTire de nuevo.");
		getch();
	}
	printf ("\nCantidad de dardos lanzados: %d\n",shoots);
}
int jugada(int score, int tam,int board[tam][tam]){
	
	int i=0,j=0,aux=0;
	
	srand(time(NULL));
	
	i=rand()%tam;
	j=rand()%tam;
	score+=board[i][j];
	aux=board[i][j];
	if (score>100){
		board[i][j]=5;
		draw(shoots,score,tam,board);
		board[i][j]=aux;
		score-=board[i][j];
		system("cls");
		draw(shoots,score,tam,board);
	}	else{
		board[i][j]=5;
		draw(shoots,score,tam,board);
		}
	system("pause");
	return score;
}
