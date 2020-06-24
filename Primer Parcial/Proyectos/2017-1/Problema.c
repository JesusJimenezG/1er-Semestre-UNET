#include <stdio.h>
#include <stdlib.h>
#include <windows.h>

int main(){
	
	int op=0;
	
	do
	{
		printf ("Bienvenido. Ingrese una opcion:\n1)Persistencia multiplicativa.\n2)Numero original.\n4)Salir.\n\nOpcion: ");
		scanf ("%d",&op);
		switch(op){
			case 1: system("cls");
					persmul();
					break;
			case 2: system ("cls");
					orig();
					break;
			case 4: break;
		}	
	}while(op!=4);
	return;
}

int persmul(){
	
	
	int aux[100],aux_sum;
	int a,i,j,k,l,num,caps;
	printf("Bienvenido a la persistencia multiplicativa.\nPor favor, ingrese un numero: ");
	scanf ("%d",&num);
	a=num;				//auxiliar que almacena el numero
	caps=num;			//capsula que almacena el numero
	printf ("\n");
	for (i=0;num>10;i++,a=num){		//bucle que lleva el contador de iteraciones de la persistencia
		for(j=0,aux_sum=1;a>0;j++){	
		
			aux[j] = a % 10;	//Bucle que descompone el numero: el modulo de 10 extrae la unidad, y luego
			a = a / 10;			//la division por diez elimina la unidad. ejemplo: 1234%10=4 || 1234/10=123
			aux_sum *= aux[j];	//el numero 4 queda luego de la coma, pero al ser una variable de tipo entero,
								//no guarda valores luego del decimal
					
		}	do{					//bucle que imprime por pantalla en orden de izquierda a derecha
				j--;
				printf("%d ",aux[j]);
				if(j>0){		//condicion que impide la impresion de un signo (*) extra a la derecha
					printf("* ");
				}
			}while(j>0);
		num = aux_sum;	//asignacion de la multiplicacion a la variable num para que se evalúe la persistencia
		printf("= %d\n",num);
		getch();
		}	
	printf ("La persistencia multiplicativa del numero: %d es: %d\n",caps,i);
	system ("pause");
	system ("cls");
	return 0;
}

int sen(){
	
	
}

int orig(){
	
	int i,cond,num,auxl,auxr,aux_sum;
	
	printf ("Bienvenido.\n\nIngrese un numero entre el 0 y el 99: ");
	scanf ("%d",&num);
	cond=num;
	i=0;
	do{
		printf("%d",num/10);
		SetConsoleTextAttribute(GetStdHandle (STD_OUTPUT_HANDLE),2);
		printf("%d",num%10);
		SetConsoleTextAttribute(GetStdHandle (STD_OUTPUT_HANDLE),7);
		printf("\t||\t");
		auxl = num / 10;
		printf("%d + ",auxl);
		auxr = num % 10;
		SetConsoleTextAttribute(GetStdHandle (STD_OUTPUT_HANDLE),2);
		printf("%d ",auxr);
		SetConsoleTextAttribute(GetStdHandle (STD_OUTPUT_HANDLE),7);
		printf("= ");
		aux_sum = auxl + auxr;
		printf("%d\t||\t",aux_sum);
		num = auxr*10 + aux_sum % 10;
		SetConsoleTextAttribute(GetStdHandle (STD_OUTPUT_HANDLE),2);
		printf("%d\n",num);
		SetConsoleTextAttribute(GetStdHandle (STD_OUTPUT_HANDLE),7);
		getch();
		i++;
	}while(cond!=num);
	
	printf("Para el numero: ");
	SetConsoleTextAttribute(GetStdHandle (STD_OUTPUT_HANDLE),2);
	printf("%d ",cond);
	SetConsoleTextAttribute(GetStdHandle (STD_OUTPUT_HANDLE),7);
	printf("se tomaron ");
	SetConsoleTextAttribute(GetStdHandle (STD_OUTPUT_HANDLE),2);
	printf("%d ",i);
	SetConsoleTextAttribute(GetStdHandle (STD_OUTPUT_HANDLE),7);
	printf("pasos para volver al numero original.\n");
	
	system ("pause");
	system ("cls");
	return 0;
}
