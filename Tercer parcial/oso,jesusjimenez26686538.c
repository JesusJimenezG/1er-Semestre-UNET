#include<stdio.h>
#include<windows.h>
#define UP '\x48'
#define DOWN '\x50'
#define LEFT '\x4b'
#define RIGHT '\x4d'
#define ENTER '\x0D'
#define ANSI_COLOR_RED     "\x1b[31m"
#define ANSI_COLOR_GREEN   "\x1b[32m"
#define ANSI_COLOR_RESET   "\x1b[0m"
#define EXIT '\x81'
#define RESET '\x52'
void menu();
void game();
void fill();
void gotoxy(int x, int y);
void draw(int ronda);
void pos();
void oso(int x, int y);
void end();
//void move();
typedef struct{
	char jugador1[200],jugador2[200];
	int y,x,dy,dx,estado;
	int board[20][20];
	int token;
	int dado;
	int score1,score2;
}resources;
resources res;
int main(){
	
	menu();
	
	return 0;
}
void menu(){

	do{
		printf("Bienvenido El juego del Oso.\n\nIngrese una cuadricula de un minimo 8x8 y un maximo 20x20: ");
		scanf("%d%d",&res.dy,&res.dx);
		if (res.dy==res.dx&&res.dy>7&&res.dy<21){
			system("cls");
			printf("Ingrese el nombre del jugador 1: ");
			scanf("%s",&res.jugador1);
			system("cls");
			printf("Ingrese el nombre del jugador 2: ");
			scanf("%s",&res.jugador2);
			system("cls");
			game();
		}else{
			res.estado=1;
			system("cls");
			printf("no es un cuadrado de dimensiones iguales mayor o igual que 8x8 y menor que 20x20.\n");
			system("pause");
			system("cls");
		}
	}while(res.estado!=0);
}
void game(){
	int aux,ronda=1,cont=1;
	fill();
	srand(time(NULL));
	res.estado=1;
	res.score1=0;	res.score2=0;
	res.dado=rand()%res.dx;
	aux=res.dado;
	printf("Tirada de dados para elegir quien inicia.\nEl jugador "ANSI_COLOR_GREEN"%s"ANSI_COLOR_RESET" saco: %d\n",res.jugador1,res.dado);
	system("pause");
	system("cls");
	res.estado*=-1;
	res.dado=rand()%res.dx;
	printf("Tirada de dados para elegir quien inicia.\n El jugador "ANSI_COLOR_RED"%s"ANSI_COLOR_RESET" saco: %d\n",res.jugador2,res.dado);
	system("pause");
	system("cls");
	if(aux>res.dado){
		res.estado*=-1;
	}else{
		res.estado*=1;
	}
	do{
		do{
			system("cls");
			draw(ronda);
			pos();
			end();
		}while(res.estado!=0);
		ronda++;
	}while(ronda<=3);	
}
void fill(){
	int i,j;
	
	for(i=0;i<res.dy;i++){
		for(j=0;j<res.dx;j++){
			res.board[i][j]=0;
		}
	}
}
void draw(int ronda){
	int i,j,op;
	
	for(i=0;i<res.dy;i++){
		for(j=0;j<res.dx;j++){
			if(res.board[i][j]==0){
				printf(" |",res.board[i][j]);
			}else{
				if(res.board[i][j]==1){
					printf("O|");
				}
				if(res.board[i][j]==2){
					printf("S|");
				}
				if(res.board[i][j]==3){
					printf(ANSI_COLOR_GREEN"O|"ANSI_COLOR_RESET);
				}
				if(res.board[i][j]==4){
					printf(ANSI_COLOR_GREEN"S|"ANSI_COLOR_RESET);
				}
				if(res.board[i][j]==5){
					printf(ANSI_COLOR_RED"O|"ANSI_COLOR_RESET);
				}
				if(res.board[i][j]==6){
					printf(ANSI_COLOR_RED"S|"ANSI_COLOR_RESET);
				}
			}
		}
	printf("\n");
	}
	if(res.estado==1){
		printf ("\nTurno del jugador "ANSI_COLOR_GREEN"%s"ANSI_COLOR_RESET,res.jugador1);	
	}else{
		printf ("\nTurno del jugador "ANSI_COLOR_RED"%s"ANSI_COLOR_RESET,res.jugador2);
	}
	printf("\n\nPuntuacion "ANSI_COLOR_GREEN"%s"ANSI_COLOR_RESET": %d\tPuntuacion "ANSI_COLOR_RED"%s"ANSI_COLOR_RESET": %d",res.jugador1,res.score1,res.jugador2,res.score2);
	printf ("\nRonda %d",ronda);
}
void pos(){
	int x,y,op;
	printf("\nIngrese la posicion(x,y): ");
	scanf("%d%d",&res.x,&res.y);
	x=res.x;	y=res.y;
	printf("\nIngrese una letra(1=O/2=S): ");
	scanf("%d",&res.token);
	if(res.token==1){
		res.board[res.x][res.y]=1;	
	}
	if(res.token==2){
		res.board[res.x][res.y]=2;
	}
	printf("\nDesea ingresar otra palabra?(1=S/0=N): ");
	scanf("%d",&op);
	if(op==1){
		printf("\nIngrese la posicion (x,y): ");
		scanf("%d%d",&res.x,&res.y);
		x=res.x;	y=res.y;
		printf("\nIngrese una letra(1=O/2=S): ");
		scanf("%d",&res.token);
		if(res.token==1){
			res.board[res.x][res.y]=1;	
		}
		if(res.token==2){
			res.board[res.x][res.y]=2;
		}
	}
	oso(x,y);
}
void oso(int x, int y){
	int i,j,ii,jj,cont=0;
	
	for(i=0;i<res.dy;i++){
		for(j=0;j<res.dx;j++){
			if(res.board[i][j]==1||res.board[i][j]==3||res.board[i][j]==5){
				if(res.board[i][j+1]==2||res.board[i][j+1]==4||res.board[i][j+1]==6){
					if(res.board[i][j+2]==1||res.board[i][j+2]==3||res.board[i][j+2]==5){
						if(res.estado==1){
							res.score1+=1;
							res.board[i][j]=3;
							res.board[i][j+1]=4;
							res.board[i][j+2]=3;
							break;
						}else
							res.score2+=1;
							res.board[i][j]=5;
							res.board[i][j+1]=6;
							res.board[i][j+2]=5;
							break;
					}
				}else if(res.board[i][j-1]==2||res.board[i][j-1]==4||res.board[i][j-1]==6){
					if(res.board[i][j-2]==1||res.board[i][j-2]==3||res.board[i][j-2]==5){
						if(res.estado==1){
							res.score1+=1;
							res.board[i][j]=3;
							res.board[i][j-1]=4;
							res.board[i][j-2]=3;
							break;
						}else
							res.score2+=1;
							res.board[i][j]=5;
							res.board[i][j-1]=6;
							res.board[i][j-2]=5;
							break;
					}
				}else if(res.board[i+1][j]==2||res.board[i+1][j]==4||res.board[i+1][j]==6){
					if(res.board[i+2][j]==1||res.board[i+2][j]==3||res.board[i+2][j]==5){
						if(res.estado==1){
							res.score1+=1;
							res.board[i][j]=3;
							res.board[i+1][j]=4;
							res.board[i+2][j]=3;
							break;
						}else
							res.score2+=1;
							res.board[i][j]=5;
							res.board[i+1][j]=6;
							res.board[i+2][j]=5;
							break;
					}
				}else if(res.board[i-1][j]==2||res.board[i-1][j]==4||res.board[i-1][j]==6){
					if(res.board[i-2][j]==1||res.board[i-2][j]==3||res.board[i-2][j]==5){
						if(res.estado==1){
							res.score1+=1;
							res.board[i][j]=3;
							res.board[i-1][j]=4;
							res.board[i-2][j]=3;
							break;
						}else
							res.score2+=1;
							res.board[i][j]=5;
							res.board[i-1][j]=6;
							res.board[i-2][j]=5;
							break;
					}
				}else if(res.board[i+1][j+1]==2||res.board[i+1][j+1]==4||res.board[i+1][j+1]==6){
					if(res.board[i+2][j+2]==1||res.board[i+2][j+2]==3||res.board[i+2][j+2]==5){
						if(res.estado==1){
							res.score1+=1;
							res.board[i][j]=3;
							res.board[i+1][j+1]=4;
							res.board[i+2][j+2]=3;
							break;
						}else
							res.score2+=1;
							res.board[i][j]=5;
							res.board[i+1][j+1]=6;
							res.board[i+2][j+2]=5;
							break;
					}
				}else if(res.board[i+1][j-1]==2||res.board[i+1][j-1]==4||res.board[i+1][j-1]==6){
					if(res.board[i+2][j-2]==1||res.board[i+2][j-2]==3||res.board[i+2][j-2]==5){
						if(res.estado==1){
							res.score1+=1;
							res.board[i][j]=3;
							res.board[i+1][j-1]=4;
							res.board[i+2][j-2]=3;
							break;
						}else
							res.score2+=1;
							res.board[i][j]=5;
							res.board[i+1][j-1]=6;
							res.board[i+2][j-2]=5;
							break;
					}
				}else if(res.board[i-1][j-1]==2||res.board[i-1][j-1]==4||res.board[i-1][j-1]==6){
					if(res.board[i-2][j-2]==1||res.board[i-2][j-2]==3||res.board[i-2][j-2]==5){
						if(res.estado==1){
							res.score1+=1;
							res.board[i][j]=3;
							res.board[i-1][j-1]=4;
							res.board[i-2][j-2]=3;
							break;
						}else
							res.score2+=1;
							res.board[i][j]=5;
							res.board[i-1][j-1]=6;
							res.board[i-2][j-2]=5;
							break;
					}
				}else if(res.board[i-1][j+1]==2||res.board[i-1][j+1]==4||res.board[i-1][j+1]==6){
					if(res.board[i-2][j+2]==1||res.board[i-2][j+2]==3||res.board[i-2][j+2]==5){
						if(res.estado==1){
							res.score1+=1;
							res.board[i][j]=3;
							res.board[i-1][j+1]=4;
							res.board[i-2][j+2]=3;
							break;
						}else
							res.score2+=1;
							res.board[i][j]=5;
							res.board[i-1][j+1]=6;
							res.board[i-2][j+2]=5;
							break;
					}
				}
			}
		}
	}
	res.estado*=-1;
	system("cls");
	
}
void end(){
	int i,j,cont=0;
	for(i=0;i<res.dy;i++){
		for(j=0;j<res.dx;j++){
			if(res.board[i][j]==0){
				cont++;
			}
		}
	}
	if(cont==0){
		res.estado=0;
	}
}
/*void move(){
	int key,placed=0,side=1;
	gotoxy(res.x,res.y);
	do{
		key=getch();
		if (key == UP){
			if(res.y>1){
				res.y-=1;	
			}
		}
		if (key == DOWN){
			if(res.y<res.dy){
				res.y+=1;	
			}
		}
		if (key == LEFT){
			if(res.x>-2){
				res.x-=2;
				side*=1;	
			}
		}
		if (key == RIGHT){
			if(res.x<(res.dx*2)-2){
				res.x+=2;	
				side*=-1;
			}
		}
		if (key == ENTER ){
			res.x-=2;
			res.board[res.y][res.x]=1;	
			
			placed=1;
		}
		gotoxy(res.x,res.y);
	}while(placed!=1);
	
}*/
void gotoxy(int x, int y){	//controlador de movimiento de la consola de windows.
    HANDLE hCon;
    COORD dwPos;
	dwPos.X = x;
    dwPos.Y = y;
    hCon = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleCursorPosition(hCon,dwPos);
}
