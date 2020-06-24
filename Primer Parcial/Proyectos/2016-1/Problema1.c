/*Desarrolle un programa en Lenguaje C que permita al usuario ejecutar las siguientes opciones:*/
#include <stdio.h>
#include <math.h>
#define CONDICION 10000
#define ANSI_COLOR_RED     "\x1b[31m"
#define ANSI_COLOR_GREEN   "\x1b[32m"
#define ANSI_COLOR_RESET   "\x1b[0m"

int main(){
	
	int dato1, p, opc;
	dato1 = num(p);
	system ("cls");
	
	do{
		printf ("1)Resta y suma de las potencias de P.\n2)Descomposicion de los numeros invictos de P.\n3)Camino de la felicidad hasta P.\n4)Ingresar otro numero.\n5)Salir.");
		printf ("\n\nIngrese el numero de la opcion que desea realizar: ");
		scanf("%d",&opc);
		if(opc<1||opc>5){
			printf("Opcion incorrecta. Intente de nuevo.");
			system("pause");
			system("cls");
		}	else{
			system ("cls");
			switch(opc){
			case 1: 
					uno (dato1);
					system ("pause");
					system ("cls");
					break;
			case 2:	printf("");
					dos (dato1);
					system ("pause");
					system ("cls");
					break;
			case 3:	printf("");
					tres (dato1);
					system ("pause");
					system ("cls");
					break;
			case 4: 
					dato1 = num(p);
					system ("cls");
					break;
			case 5: 
					break;
			}
		}
	}while(opc!=5);
	
	return 0;
}

/* Solicitar al usuario un número entero positivo P menor o igual que 10^4. Si el número ingresado no es
 * correcto mostrar un mensaje de error y solicitar nuevamente el número, hasta que el usuario 
 * introduzca un número válido. (5 ptos.)
 */
int num (int p){
	
	
	do{
		
		printf ("Bienvenido.\nIntroduzca un numero entero positivo menor que %d: ",CONDICION);	//solicitar el valor de P
		scanf ("%d",&p);
		
		if (p<-1 || p>CONDICION){
			printf ("\n\nEl numero ingresado no es correcto. Intente de nuevo.\n\n");	//en caso de que el numero ingresado sea incorrecto, se vuelve a solicitar
			system ("pause");
			system("cls");
			}
			
	}while (p<-1 || p>CONDICION);	//condicion para que el numero ingresado sea mayor que 0(un numero entero positivo) y menos que 10^4(diez mil)
	
	return p;		//devolver el valor solicitado
}

/* Con el valor P dado por el usuario en el paso anterior, calcular la suma de: 
 	P^2 – (P–1)^2 + (P–2)^2 – (P–3)^2 + (P–4)2 – (P–5)^2 + … – (P – n-1)2 + (P – n)^2
 El último término de la suma es igual a 1 o -1 
 Por ejemplo, si el valor de P es igual a 5 se obtiene:
	25 – 16 + 9 – 4 + 1 = 15
 Si el valor de P es igual a 6:
	36 – 25 + 16 – 9 + 4 – 1 = 21 	
*/
int uno (int dat){
	
	int aux1,cond1,cont,i,j,pot,sum,val;
	int op[10000],suma[10000];			//cadena de arreglos
	val = dat;	//asignacion del numero P ingresado a la variable 'val'
	
	printf ("Con el valor P dado por el usuario en el paso anterior, se calcula la suma de:\n\n");
	printf ("\t%d^2 - (%d-1)^2 + (%d-2)^2 - (%d-3)^2 + (%d-4)^2 - (%d-5)^2 + … - (%d - N-1)^2 + (%d - N)^2\n\n",val,val,val,val,val,val,val,val);
	printf ("El ultimo termino de la suma es igual a 1 o -1.\n\n");
	printf ("Por ejemplo, si el valor de P es igual a 5 se obtiene:\n\n");
	printf ("\t25 - 16 + 9 - 4 "ANSI_COLOR_RED"+ 1"ANSI_COLOR_RESET" = "ANSI_COLOR_GREEN"15"ANSI_COLOR_RESET"\n\n");
	printf ("Si el valor de P es igual a 6:\n\n");
	printf ("\t36 - 25 + 16 - 9 + 4 "ANSI_COLOR_RED"- 1"ANSI_COLOR_RESET" = "ANSI_COLOR_GREEN"21"ANSI_COLOR_RESET"\n\n");
	system ("pause");
	system ("cls");
	
	printf ("El valor de la suma de"ANSI_COLOR_GREEN" %d "ANSI_COLOR_RESET"es: \n\n",val);
	pot = pow(val,2);	//potencia del numero P^2
	sum = pot;
	printf("%d - ",pot);
		for (i=0, j=1, cont=1, cond1=0; aux1!=1 && aux1!=-1; i++, j++,cont++, cond1++){	
		/*iteración para aumentar el numero que resta a P (P-n)^2
		  donde 'i' ubica la casilla del arreglo y 'j' el numero que se incrementara en cada iteracion*/
			op[i] = (val - j);				//operacion de resta (P-N)
			op[i] = pow(op[i],2);			//potenciacion de la operacion (P-N)^2
			aux1 = op[i];					//auxiliar de escape
			cond1 = j%2;					//condicion de suma y resta evaluando si un numero es par o impar
			printf ("%d ",op[i]);
				if (aux1!=1){					//dependiendo de si la condicion se cumple o no, se sumará o restará
					if (cond1==0){
						printf("- ");
					}	else{
							printf("+ ");
						}
				}
					if (cond1==0){
						sum = sum + op [i];
					}	else{
							sum = sum - op[i];
						}
			}
		printf ("= %d.\n\n",sum);			//resultado final		
	return 0;
}

/*Determinar si el número P es un número invicto. Un número es invicto cuando al borrar los dígitos 
  que no son primos, nos queda un número que sí lo es. Por ejemplo:
  	9362 se obtiene 32 que no es primo (no es un número invicto)
	1783 se obtiene 73 que si es primo (por lo tanto si es un número invicto)
*/

int dos (int dat){
	
	int aux,dig[10]={0},suma[10]={0},i,j,k,l,p,num,cont=0;
	num = dat;
	
	printf("Determina si el número P es un numero invicto. Un numero es invicto cuando al borrar los digitos que no son primos, nos queda un numero que si lo es.\nPor ejemplo:\n");
	printf("\t9"ANSI_COLOR_RED"3"ANSI_COLOR_RESET"6"ANSI_COLOR_RED"2"ANSI_COLOR_RESET" se obtiene "ANSI_COLOR_RED"32"ANSI_COLOR_RESET" que no es primo (no es un numero invicto)\n\n");
	printf("\t1"ANSI_COLOR_RED"7"ANSI_COLOR_RESET"8"ANSI_COLOR_RED"3"ANSI_COLOR_RESET" se obtiene "ANSI_COLOR_RED"73"ANSI_COLOR_RESET" que si es primo (por lo tanto si es un numero invicto)\n\n");
	system ("pause");
	system ("cls");
	
	//descomposicion
	for(aux=0;num>0;aux++){
		num=num/10;
	}
	//dinamica
	for(i=0,j=aux-1,num=dat;i<aux;i++,j--){
		dig[i]=num/pow(10,j);
		num=num-(dig[i]*pow(10,j));
	}
	//numeros primos
	for(i=0,l=aux-1,p=0,cont=0;i<aux;i++,l--){
		for(j=2,k=1;j<dig[i]&&k!=0;j++){
			k=dig[i]%j;
		}
		if(k==0){
			printf("%d ",dig[i]);
			//getch();
		}else{
			printf(ANSI_COLOR_RED"%d "ANSI_COLOR_RESET,dig[i]);
			suma[cont]=dig[i];
			//printf("watch de contador: %d ",suma[cont]);
			//getch();
			cont++;
		}
	}
	for(i=0,l=cont-1;i<cont;i++,l--){
		//printf("watch de contador: %d ",l);
		//getch();
		p+=suma[i]*pow(10,l);
	}
	printf ("se obtiene %d.\n",p);

	//numero invicto
	for(i=2,k=1;i<p&&k!=0;i++){
		k=p%i;
	}
	if(k==0){
		printf("el numero "ANSI_COLOR_RED"%d"ANSI_COLOR_RESET" no es primo, por lo tanto el numero %d "ANSI_COLOR_RED"no es invicto"ANSI_COLOR_RESET".\n",p,dat);
	}else{
		printf("el numero "ANSI_COLOR_GREEN"%d"ANSI_COLOR_RESET" es primo, por lo tanto el numero %d "ANSI_COLOR_GREEN"es invicto"ANSI_COLOR_RESET".\n",p,dat);
	}
	
	return 0;
}

/*	Un número es “feliz” si al sumar el cuadrado de cada uno de los dígitos que lo conforma y repetir 
este proceso un número finito de veces la suma converge a 1. Para algunos números, la cantidad de 
iteraciones necesarias para que la suma sea 1 puede ser mayor que para otros y a esa cantidad de 
iteraciones se le conoce como la “distancia de la felicidad”. Por ejemplo, para el caso del número 1 
su “distancia de la felicidad” es 0 ya que 1^2 = 1. 
No así para el 23 cuya “distancia de la felicidad” es 3, como se muestra a continuación:
	Número		Proceso			Suma		Iteración
	23			2^2+3^2 		13				1
	13			1^2+3^2			10				2
	10			1^2+0^2			1				3		Distancia de la felicidad

Un número se dice que es “no feliz” cuando está infinitamente lejos de llegar a la felicidad, es decir, 
se queda atrapado en un ciclo y su suma nunca llega a 1. Se puede demostrar que todo número “no 
feliz” se queda atrapado en el ciclo 4, 16, 37, 58, 89, 145, 42, 20, 4, 16, 37… y así para siempre sin 
llegar al 1. Por ejemplo, este es el caso del número 11, el número 20 y el número 89 como se observa
en las siguientes secuencias:
										11
								1^2+1^2=2
									2^2=4
									4^2=16
								1^2+6^2=37
								3^2+7^2=58
								5^2+8^2=89
								8^2+9^2=145
							1^2+4^2+5^2=42
								4^2+2^2=20
								2^2+0^2=4
									4^2=16
										.
										.
										.
Se requiere determinar cuántos números no felices hay entre 1 y P.*/

int tres (int dat){
	int d[4],i,j,cont=0,num,suma=0,conthappy=0,unhappy=0,aux=0,cifras=0;
	num = dat;
	cont = 0;
	
	printf ("Un numero es "ANSI_COLOR_GREEN"'feliz'"ANSI_COLOR_RESET" si al sumar el cuadrado de cada uno de los digitos que lo conforma\ny repetir este proceso un numero finito de veces la suma converge a "ANSI_COLOR_GREEN"1"ANSI_COLOR_RESET".\n");
	printf ("Para algunos numeros, la cantidad de iteraciones necesarias para que la suma sea "ANSI_COLOR_GREEN"1"ANSI_COLOR_RESET" puede\nser mayor que para otros y a esa cantidad de iteraciones se le conoce\ncomo la "ANSI_COLOR_GREEN"'distancia de la felicidad'"ANSI_COLOR_RESET".\nPor ejemplo, para el caso del numero "ANSI_COLOR_GREEN"1"ANSI_COLOR_RESET" su "ANSI_COLOR_GREEN"'distancia de la felicidad'"ANSI_COLOR_RESET" es "ANSI_COLOR_GREEN"0"ANSI_COLOR_RESET" ya que 1^2 = "ANSI_COLOR_GREEN"1"ANSI_COLOR_RESET".\n\n");
	system ("pause");
	system ("cls");
	printf ("El numero es %d\n\n",num);
	
	//camino de la felicidad
	for (i=1,unhappy=0;i<=dat;i++,cont=0){
		aux=i;	num=i;
		do{
			if(num<10){
				suma=0;
				suma+=(aux*aux);
				//printf("%d^2 = %d\n",aux,suma);
				//getch();
				num=suma;
				if(num!=1){
					aux=suma;
					if(num==4){
						unhappy++;
						printf("El camino a la felicidad para el numero "ANSI_COLOR_GREEN"%d"ANSI_COLOR_RESET" es "ANSI_COLOR_RED"infinatemente largo"ANSI_COLOR_RESET".\n",i);
						//getch();
						break;
					}
				}else{
					conthappy++;
				}
			}	else{
					//cantidad de cifras
					//printf("caantidad de cifras del numero: %d",num);
					//getch();
					for(j=0,cifras=0;aux>0;j++){
						aux=aux/10;
						//printf("\ncaantidad de cifras del numero: %d",aux);
						//getch();
						cifras++;
					}
					//printf("=%d\n",cifras);
					//getch();
					aux=num;
					//descomposicion y asignaacion dinamica del numero
					for(j=cifras;j>0;j--){
						d[j]=aux%10;
						aux=aux/10;
					}
					//numero feliz
					for(j=1,suma=0;j<=cifras;j++){
						suma+=(d[j]*d[j]);
						//printf("%d^2 + ",d[j]);
					}
					//printf ("= %d\n",suma);
					//getch();
					num=suma;
						if(num!=1){
							aux=suma;
							if(num==4){
								unhappy++;
								printf("El camino a la felicidad para el numero "ANSI_COLOR_GREEN"%d"ANSI_COLOR_RESET" es "ANSI_COLOR_RED"infinatemente largo"ANSI_COLOR_RESET".\n",i);
								//getch();
								break;
							}
						}else{
							conthappy++;
						}
				}
				if(i>1){
					cont++;	
				}
		}while(num!=1);
		if(num==1){
			printf ("El camino a la felicidad para el numero"ANSI_COLOR_GREEN" %d "ANSI_COLOR_RESET"es: "ANSI_COLOR_GREEN"%d"ANSI_COLOR_RESET"\n",i,cont);
			//getch();	
		}
	}	printf ("\nEn el camino a la felicidad para el numero "ANSI_COLOR_GREEN"%d"ANSI_COLOR_RESET" hay "ANSI_COLOR_RED"%d"ANSI_COLOR_RESET" numeros infelices y "ANSI_COLOR_GREEN"%d"ANSI_COLOR_RESET" numeros felices.\n",dat,unhappy,conthappy);
	
	return 0;
}

