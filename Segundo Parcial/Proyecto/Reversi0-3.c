#include <stdio.h>
#include <windows.h>
#define UP '\x48'
#define DOWN '\x50'
#define LEFT '\x4b'
#define RIGHT '\x4d'
#define ENTER '\x0D'
#define N 100 

int board [N][N];
int turn=1;
int menu();
void game(int board[N][N]);
void fill (int board[N][N]);
void rollback(int board[N][N],int turn);
void draw (int board[N][N],int turn);
void playable1 (int board[N][N]);
void playable2 (int board[N][N]);
int play1 (int board[N][N],int y, int x);
int play2 (int board[N][N],int y, int x);
int score(int board[N][N]);
int winner(int board[N][N]);

void gotoxy(int x, int y){	//controlador de movimiento de la consola de windows.
    HANDLE hCon;
    COORD dwPos;
	dwPos.X = x;
    dwPos.Y = y;
    hCon = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleCursorPosition(hCon,dwPos);
}

void move (int board[N][N],int turn){	//funcion para definir el movimiento por las flechas de direccion.
	
	int play=1,b,w;
	char key='0';	
	int x=8,y=4,shdwx=0;	//inicializacion de la posicion del cursor en la mitad del tablero.
	gotoxy(x,y);	//lugar del cursor en el tablero en la posicion de x, y.
	
	while (play==1){	
		key = getch();	//capturador de tecla por keyboard
		if (kbhit()){	key = getch();	}	// keyboardhit = tecla presionada y asignada a la variable key
			if (key == 'q'){ menu(); }
			if (key == 'r'){ menu(); }
			if ( key == UP)		{if (y>1&&y<=8){	y-=1;	}	}	//movimiento hacia arriba, decrementando 1 en la posicion de las Y en la matriz (4) en la que inicia el cursor					
			if ( key == DOWN)	{if (y>=1&&y<8){	y+=1;	}	}	//movimiento hacia abajo, aumentando 1 en la posicion de las Y en la matriz (4) en la que inicia el cursor
			if ( key == LEFT)	{if (x>2&&x<=16){	x-=2;	}	}	//movimiento hacia la izquierda, decrementando 2 en la posicion de las X en la matriz (8) en la que inicia el cursor
			if ( key == RIGHT)	{if (x>=1&&x<16){	x+=2;	}	}	//movimiento hacia la derecha, aumentando 2 en la posicion de las X en la matriz (8) en la que inicia el cursor
			if ( key == ENTER){	shdwx=x; switch (x){
									case 2: x=65;	break;
									case 4: x=66;	break;							
									case 6: x=67;	break;							
									case 8: x=68;	break;							
									case 10: x=69;	break;								
									case 12: x=70;	break;			
									case 14: x=71;	break;																		
									case 16: x=72;	break;	}	
				if (turn==1){
					if (board[y][x]==5)	{ board[y][x]=1; system ("cls"); play1(board,y,x); draw(board,turn); x=shdwx; play*=-1;}																							
					else{	printf ("\n\n\nPosicion invalida."); x=shdwx;	}
				}
				if (turn==-1){
					if (board[y][x]==6)	{ board[y][x]=-1; system ("cls"); play2(board,y,x); draw(board,turn); x=shdwx; play*=-1;}																							
					else{	printf ("\n\n\nPosicion invalida."); x=shdwx;	}
				}
			}
			gotoxy(x,y);
		}
}
int winner(int board[N][N]){
	
	int i,j;
	
	for (i=1;i<9;i++){
		for (j=65;j<73;j++){
			if(board[i][j]==0||board[i][j]==5||board[i][j]==6){
				return 0;
			}
		}
	}
	return 1;
}
int score(int board[N][N]){	
	
	int i=0,j=0,scrb=0,scrw=0;
	
	for(i=1;i<9;i++){
		for (j=65;j<73;j++){
			if(board[i][j]==1){
				scrb+=1;
			}
			if (board[i][j]==-1){
				scrw+=1;
			}
		}
	}
	
	printf ("\nFichas negras: %d",scrb);
	printf ("\tFichas blancas: %d",scrw);
	
	if (scrb>scrw){
		return 1;
	}	else{
		return 0;
	}
}
int play2 (int board[N][N],int y, int x){
	
	int i=y,j=x,tok=0,aux,diag=0;

	//Primer bloque
	if(i<5){
		if(j<69){
			while(j<73){ 
				j++;
				if(board[i][j]==-1){
					while(j>x){
						j--;
						board[i][j]=-1;
						draw(board,turn);
					}											
				}
				if(j==x){
					break;
				}	
			}
			i=y;	j=x;									
		}
		if(j>68){	
			while(j>64){ 
				j--;
				if(board[i][j]==-1){
					while(j<x){
						j++;
						board[i][j]=-1;
						draw(board,turn);
					}											
				}
				if(j==x){
					break;
				}	
			}
			i=y;	j=x;								
		}
		while(i<9){ 
			i++;
			if(board[i][j]==-1){
				while(i>y){
					i--;
					board[i][j]=-1;
					draw(board,turn);
				} 											
			}
			if(i==y){
				break;
			}	
		}
		i=y;	j=x;
	}
	//Segundo bloque
	if(i>4){
		if(j<69){
			while(j<73){ 
				j++;
				if(board[i][j]==-1){
					while(j>x){
						j--;
						board[i][j]=-1;
						draw(board,turn);
					}											
				}
				if(j==x){
					break;
				}	
			}
			i=y;	j=x;									
		}
		if(j>68){
			while(j>64){ 
				j--;
				if(board[i][j]==-1){
					while(j<x){
						j++;
						board[i][j]=-1;
						draw(board,turn);
					}
														
				}
				if(j==x){
					break;
				}	
			}
			i=y;	j=x;					
		}
		while(i>0){ 
			i--;
			if(board[i][j]==-1){
				while(i<y){
					i++;
					board[i][j]=-1;
					draw(board,turn);
				}											
			}
			if(i==y){
				break;
			}	
		}
		i=y;	j=x;
	}
	//diagonales
	y++;	x++;
	if (board[y][x]==1){
		while(y<9&&x<73){
			y++;	x++;
			if (board[y][x]==-1){
				y--;	x--;
				while(board[y][x]==1){				
					board[y][x]=-1;
					draw (board,turn);
					y--;	x--;
					diag=1;
				}
			}
			if (diag==1){ break; }
		}		
	}	else{ y=i; x=j; }
	y++;	x--;
	if (board[y][x]==1){
		while(y<9&&x>64){
			y++;	x--;
			if (board[y][x]==-1){
				y--;	x++;
				while(board[y][x]==1){				
					board[y][x]=-1;
					draw (board,turn);
					y--;	x++;
					diag=1;
				}
			}
			if (diag==1){ break; }
		}		
	}	else{ y=i; x=j; }
	y--;	x++;
	if (board[y][x]==1){
		while(y>0&&x<73){
			y--;	x++;
			if (board[y][x]==-1){
				y++;	x--;
				while(board[y][x]==1){				
					board[y][x]=-1;
					draw (board,turn);
					y++;	x--;
					diag=1;
				}
			}
			if (diag==1){ break; }
		}		
	}	else{ y=i; x=j; }
	y--;	x--;
	if (board[y][x]==1){
		while(y>0&&x>64){
			y--;	x--;
			if (board[y][x]==-1){
				y++;	x++;
				while(board[y][x]==1){				
					board[y][x]=-1;
					draw (board,turn);
					y++;	x++;
					diag=1;
				}
			}
			if (diag==1){ break; }
		}		
	}	else{ y=i; x=j; }
	return;	
}
void playable2 (int board[N][N]){
	
	int i,j,x,y,diag;
	
	for (i=1,y=i;i<9;i++,y++){
		for(j=65,x=j;j<73;j++,x++){
			if(board[i][j]==-1){
				while(x<73){
					x++;
					if (board[i][x]==0){
						if (board[i][x-1]==1){
							board[i][x]=6;
							draw(board,turn);
						}
					}
				}
				while(x>64){
					x--;
					if (board[i][x]==0){
						if (board[i][x+1]==1){
							board[i][x]=6;
							draw(board,turn);
						}
					}
				}
				while(y<9){
					y++;
					if (board[y][j]==0){
						if (board[y-1][j]==1){
							board[y][j]=6;
							draw(board,turn);
						}
					}
				}
				while(y>0){
					y--;
					if (board[y][j]==0){
						if (board[y+1][j]==1){
							board[y][j]=6;
							draw(board,turn);
						}
					}
				}
			}
		}
	}
	//diagonales
	for (i=1,y=1;i<9;i++,y++){
		for (j=65,x=65;j<73;j++,x++){
			if (board[i][j]==1){
				y++;	x++;
				if (board[y][x]==-1){
					y=i;	x=j;
					while(board[y][x]==1){
						y--;	x--;
						if (board[y][x]==0){
							board[y][x]=6;
							draw (board,turn);
						}
					}		
				}	else{ y=i; x=j; }
				y++;	x--;
				if (board[y][x]==-1){
					y=i;	x=j;
					while(board[y][x]==1){	
						y--;	x++;
						if (board[y][x]==0){
							board[y][x]=6;
							draw (board,turn);
						}
					}		
				}	else{ y=i; x=j; }
				y--;	x++;
				if (board[y][x]==-1){
					y=i;	x=j;
					while(board[y][x]==1){	
						y++;	x--;
						if (board[y][x]==0){
							board[y][x]=6;
							draw (board,turn);
						}
					}		
				}	else{ y=i; x=j; }
				y--;	x--;
				if (board[y][x]==-1){
					y=i;	x=j;
					while(board[y][x]==1){
						y++;	x++;
						if (board[y][x]==0){
							board[y][x]=6;
							draw (board,turn);
						}
					}		
				}	else{ y=i; x=j; }
			}
		}
	}
}
int play1 (int board[N][N],int y, int x){
	
	int i=y,j=x,tok=0,aux=0,diag=0;
	//int real_y=y, real_x=x;
	
	if(i<5){
		if(j<69){
			//printf ("primer bloque.");
			//getch();
			while(j<73){ 
				//printf ("comprobacion hacia la derecha.");
				//getch();
				j++;
				if(board[i][j]==1){
					while(j>x){
						j--;
						board[i][j]=1;
						draw(board,turn);
					}											
				}
				if(j==x){
					break;
				}	
			}
			i=y;	j=x;									
		}
		if(j>68){
			//printf ("segundo bloque.");
			//getch();
			while(j>64){ 
			//printf ("comprobacion hacia la izquierda.");
			//getch();
				j--;
				if(board[i][j]==1){
					while(j<x){
						j++;
						board[i][j]=1;
						draw(board,turn);
					}											
				}
				if(j==x){
					break;
				}	
			}
			i=y;	j=x;
		}
		while(i<9){ 
			i++;
			if(board[i][j]==1){
				//printf ("comprobacion hacia abajo.");
				//getch();
				while(i>y){
					i--;
					board[i][j]=1;
					draw(board,turn);
				}							
			}
			if(i==y){
				break;
			}	
		}
		i=y;	j=x;
	}
	if(i>4){	
		if(j<69){
			//printf ("tercer bloque.");
			//getch();
			while(j<73){ 
			//printf ("comprobacion hacia la derecha.");
			//getch();
				j++;
				if(board[i][j]==1){
					while(j>x){
						j--;
						board[i][j]=1;
						draw(board,turn);
					}											
				}
				if(j==x){
					break;
				}	
			}
			i=y;	j=x;									
		}
		if(j>68){
			//printf ("cuarto bloque.");
			//getch();
			while(j>64){ 
			//printf ("comprobacion hacia la izquierda.");
			//getch();
				j--;
				if(board[i][j]==1){
					while(j<x){
						j++;
						board[i][j]=1;			
						draw(board,turn);
					}									
				}
				if(j==x){
					break;
				}	
			}
			i=y;	j=x;							
		}
		while(i>0){ 
			i--;
			if(board[i][j]==1){
				//printf ("comprobacion hacia arriba.");
				//getch();
				while(i<y){
					i++;
					board[i][j]=1;					
					draw(board,turn);
				}										
			}
			if(i==y){
				break;
			}	
		}
		i=y;	j=x;
	}
	//diagonales
	y++;	x++;
	if (board[y][x]==-1){
		while(y<9&&x<73){
			y++;	x++;
			if (board[y][x]==1){
				y--;	x--;
				while(board[y][x]==-1){				
					board[y][x]=1;
					draw (board,turn);
					y--;	x--;
					diag=1;
				}
			}
			if (diag==1){ break; }
		}		
	}	else{ y=i; x=j; }
	y++;	x--;
	if (board[y][x]==-1){
		while(y<9&&x>64){
			y++;	x--;
			if (board[y][x]==1){
				y--;	x++;
				while(board[y][x]==-1){				
					board[y][x]=1;
					draw (board,turn);
					y--;	x++;
					diag=1;
				}
			}
			if (diag==1){ break; }
		}		
	}	else{ y=i; x=j; }
	y--;	x++;
	if (board[y][x]==-1){
		while(y>0&&x<73){
			y--;	x++;
			if (board[y][x]==1){
				y++;	x--;
				while(board[y][x]==-1){				
					board[y][x]=1;
					draw (board,turn);
					y++;	x--;
					diag=1;
				}
			}
			if (diag==1){ break; }
		}		
	}	else{ y=i; x=j; }
	y--;	x--;
	if (board[y][x]==-1){
		while(y>0&&x>64){
			y--;	x--;
			if (board[y][x]==1){
				y++;	x++;
				while(board[y][x]==-1){				
					board[y][x]=1;
					draw (board,turn);
					y++;	x++;
					diag=1;
				}
			}
			if (diag==1){ break; }
		}		
	}	else{ y=i; x=j; }
	return;	
}
void playable1 (int board[N][N]){
	
	int i,j,x,y,diag;
	
	for (i=1,y=i;i<9;i++,y++){
		for(j=65,x=j;j<73;j++,x++){
			if(board[i][j]==1){
				while(x<73){
					x++;
					if (board[i][x]==0){
						if (board[i][x-1]==-1){
							board[i][x]=5;
							draw(board,turn);
						}
					}
				}
				while(x>64){
					x--;
					if (board[i][x]==0){
						if (board[i][x+1]==-1){
							board[i][x]=5;
							draw(board,turn);
						}
					}
				}
				while(y<9){
					y++;
					if (board[y][j]==0){
						if (board[y-1][j]==-1){
							board[y][j]=5;
							draw(board,turn);
						}
					}
				}
				while(y>0){
					y--;
					if (board[y][j]==0){
						if (board[y+1][j]==-1){
							board[y][j]=5;
							draw(board,turn);
						}
					}
				}
			}
		}
	}
	//diagonales
	for (i=1,y=1;i<9;i++,y++){
		for (j=65,x=65;j<73;j++,x++){
			if (board[i][j]==-1){
				y++;	x++;
				if (board[y][x]==1){
					y=i;	x=j;
					while(board[y][x]==-1){
						y--;	x--;
						if (board[y][x]==0){
							board[y][x]=5;
							draw (board,turn);
						}
					}		
				}	else{ y=i; x=j; }
				y++;	x--;
				if (board[y][x]==1){
					y=i;	x=j;
					while(board[y][x]==-1){	
						y--;	x++;
						if (board[y][x]==0){
							board[y][x]=5;
							draw (board,turn);
						}
					}		
				}	else{ y=i; x=j; }
				y--;	x++;
				if (board[y][x]==1){
					y=i;	x=j;
					while(board[y][x]==-1){	
						y++;	x--;
						if (board[y][x]==0){
							board[y][x]=5;
							draw (board,turn);
						}
					}		
				}	else{ y=i; x=j; }
				y--;	x--;
				if (board[y][x]==1){
					y=i;	x=j;
					while(board[y][x]==-1){
						y++;	x++;
						if (board[y][x]==0){
							board[y][x]=5;
							draw (board,turn);
						}
					}		
				}	else{ y=i; x=j; }
			}
		}
	}
}
			
void draw (int board[N][N],int turn){
	
	int i,j,l,x,y;
	char black = 'X';
	char white = 'O';
	gotoxy(0,0);
	
	for (y=0,i=0,l=65;y<10;y++,i++,l=65){
		if (y==0||y==9){	printf ("  ");	}							//luego de cumplirse el primer if, el segundo condiciona que y sea menor que 9 para imprimar una cadena del 1 al 8
		if(y<9&&y>0){	printf ("%d ",i);	}
		for (x=0,j=l;x<8;x++,j++){
			if (y==0||y==9){	printf ("%c ",l);	l++;	}	//para la primera posicion, se imprime una cadena ascendente del abecedario
			if (y>0&&y<9){										//luego de la primera fila que contiene el abc se imprime el tablero de 8x8=64
				if (board[i][j]==0)		{	printf(" |");	}
				if (board[i][j]==5)		{	rollback(board,turn); printf(".|");	}
				if (board[i][j]==6)		{	rollback(board,turn); printf(".|");	}
				if (board[i][j]==1)		{	printf ("%c|",black);	}
				if (board[i][j]==-1)	{	printf ("%c|",white);	}																
			}
		}
		if (x>0&&y>0&&y<9)	{	printf ("%d",i);	}			//luego de la primera columna y al final de todas las filas a excepción de la primera, se dibuja otra cadena del 1 al 8
		printf ("\n");
	}
	if (turn==1){
		printf("\nturno del jugador 1.");
	}	else{
		printf("\nturno del jugador 2.");
	}
	printf("\n\nJugador 1.\t\tJugador 2.");
	printf("\nX=fichas negras.\tO=fichas blancas.");
	score(board);
	printf ("\n\nControles: flechas direccionales. Q=Salir. R=Empezar nueva partida.");
	
}
void rollback(int board[N][N],int turn){
	int i,j;
	
	for (i=1;i<9;i++){
		for (j=65;j<73;j++){
			if (turn==1){
				if (board[i][j]==6){
					board[i][j]=0;
				}
			}	else{
				if (board[i][j]==5){
					board[i][j]=0;
				}
			}
		}
	}
}
void fill (int board[N][N]){									//rellena el tablero de ceros indicando que está vacío, también se llena de unos como posiciones usadas
	
	int i, j;
	board [4][68]=1;			//posicion inicial de las fichas
	board [4][69]=-1;
	board [5][68]=-1;
	board [5][69]=1;
	for (i=0;i<11;i++){
		for (j=0;j<11;j++){
			board[i][j] = 0;
		}
	}

}

void game(int board[N][N]){
	
	int state=1;

	fill (board);
	while (state==1){
		draw (board,turn);
		if (turn==1){
			playable1 (board);
		} else{
			playable2 (board);
		}	
		move (board,turn);	turn*=-1;		
		if (winner (board)==1){
			
			if(score(board)==1){
				system ("cls");
				draw (board,turn);
				printf ("\n\nGanan las negras.");
				getch();
			}	else{
				system ("cls");
				draw (board,turn);
				printf ("\n\nGanan las blancas.");
				getch();
			}
			state*=-1;
			printf ("\n");
			system ("pause");
		}
			
	}
}

int menu(){
	
	char exit='0';
	fflush(stdin);
	
	if (kbhit()){	
			exit=getch();
			if(exit=='q'){
				return 0;
			}
		}
		if (kbhit()){
			exit=getch();
			if(exit=='r'){
				game(board);
			}
		}
		game(board);
}
void main (){
	
	menu();
	
}

