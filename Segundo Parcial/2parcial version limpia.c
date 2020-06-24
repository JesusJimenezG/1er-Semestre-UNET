#include <stdio.h>

int tablero[10][10];
int dardos=0;
int juego(int N,int dardos);
void rellenar(int N,int tablero[N][N]);
void imprimir(int N,int tablero[N][N],int dardos);
int aleatorio(int N,int tablero[N][N]);
int jugadas(int i, int j, int N, int tablero[N][N]);

int aleatorio(int N,int tablero[N][N]){
	
	int i,j,puntaje=0;
	
	srand(time(NULL));
	i=rand()%N;
	j=rand()%N;
	
	tablero[i][j]=1;
	dardos+=1;
	imprimir(N,tablero,dardos);
	rellenar(N,tablero);
	puntaje+=tablero[i][j];
		
	return puntaje;
}

void imprimir(int N, int tablero[N][N],int dardos){
	
	int i,j;
	
	for (i=0;i<N;i++){
		for (j=0;j<N;j++){
			if (tablero[i][j]==0){
				printf ("%d |",tablero[i][j]);
			}	else if (tablero[i][j]==1){
				printf ("X |");
				}	else{
					printf ("%d|",tablero[i][j]);
				}
		}
	printf ("\n");
	}
	printf ("\nCantidad de dardos lanzados: %d",dardos);
	
}

void rellenar(int N, int tablero [N][N]){
	
	int i,j, m,cont=10,vuel=1;
	
	for (i=0;i<N;i++){
		for (j=0;j<N;j++){
			tablero[i][j]=0;
		}
	}
	//matriz dinamica
	do{
		for (i=vuel;i<N-vuel;i++){
				for (j=vuel;j<N-vuel;j++){
					tablero [i][j]=cont;
				}
			}
		cont+=10;
		vuel+=1;
	}while (vuel<N);
	
}

int juego(int N,int dardos){
	
	int puntos=0,aux=0;
	
	rellenar(N,tablero);
	do{		
		puntos=aleatorio(N,tablero);
		aux+=puntos;
		if(aux>100){
			printf("\n\nPuntaje = %d.Jugada invalida, no puede exceder los 100 puntos. Lance de nuevo.",aux);
			getch();
			aux-=puntos;
		}
		printf ("\n\nPuntaje= %d\n",aux);
		system ("pause");
		system ("cls");
	}while (aux!=100);
	printf("Ganaste!!!");
	return 0;
}

int main (){
		
	int N,fil,col;
	
	do{
		printf ("Las dimensiones deben ser iguales NfilasxNcolumnas.\n");
		printf ("Ingrese el numero de filas: ");
		scanf ("%d",&fil);
		printf ("ingrese el numero de columnas: ");
		scanf ("%d",&col);
		if (fil!=col){
			printf ("Las dimensiones no son las de un cuadrado. Intente de nuevo.\n");
			system ("pause");
			system ("cls");
		}	else{
				N=fil;
				system ("cls");
				juego(N,dardos);
			}
	}while (fil!=col);
	
	return 0;
}
