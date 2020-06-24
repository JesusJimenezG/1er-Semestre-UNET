#include<stdio.h>
#include<math.h>
#define ANSI_COLOR_RED     "\x1b[31m"
#define ANSI_COLOR_GREEN   "\x1b[32m"
#define ANSI_COLOR_RESET   "\x1b[0m"

int main(){
	
	int op=0;
	
	do{
		printf ("Bienvenido. Ingrese una opcion:\n1)Suma descendente.\n2)Acarreo de en la operacion suma.\n3)Numeros Lychrel.\n5)Salir.\n\nOpcion: ");
		scanf ("%d",&op);
		if(op>0&&op<=5&&op!=4){
			switch(op){
			case 1: system ("cls");
					sumdesc();
					break;
			case 2: system ("cls");
					acarreo();
					break;
			case 3: system ("cls");
					lychrel();
					break;
			case 5: break;
			}	
		}	else{
			system ("cls");
			printf ("Opcion incorrecta. Intente de nuevo.\n");
			system ("pause");
			system("cls");
		}
	}while (op!=5);
	
	return 0;
}

int sumdesc(){
	
	int aux,num,cifras,i,j,suma,n[10],x=1;
	
	printf ("Bienvenido a la descendente de un numero.\n\nSe llama suma descendente de un numero cualquiera a la suma de los numeros resultantes de ir\nquitando de forma reiterada el digito mas significativo de dicho numero. Por ejemplo, si tenemos un\nnumero de 6 digitos, "ANSI_COLOR_RED"ABCDEF"ANSI_COLOR_RESET", entonces la suma descendente sera el resultado de la suma:\n\n\tABCDEF + BCDEF + CDEF + DEF + EF + F\n\nPor ejemplo, la suma descendente del número 4.578 es igual a\n\n\t4.578 + 578 + 78 + 8 = 5.242\n\n");
	system ("pause");
	system ("cls");
	printf ("Ingrese un numero entero entre 1 y 1.000.000.000: ");
	scanf ("%d",&num);
	//cantidad de cifras del numero
	for(cifras=0,aux=num;aux>0;cifras++){
		aux=aux/10;
	}
	//printf ("watch de cifras: %d\n",cifras);
	//getch();
	//suma
	for (i=0,j=cifras-1,aux=num,suma=0;i<cifras;i++,j--){
		if(x%2!=0){
			printf (ANSI_COLOR_RED"%d"ANSI_COLOR_RESET,aux);
			x++;
		}else{
			printf (ANSI_COLOR_GREEN"%d"ANSI_COLOR_RESET,aux);
		}
		if(aux>=10){
			printf (" + ");
			n[i]=aux/pow(10,j);
			suma+=aux;
			aux=aux-(pow(10,j)*n[i]);
		}	else{
			suma+=aux;
		}
	}
	printf (" = "ANSI_COLOR_GREEN"%d"ANSI_COLOR_RESET"\n",suma);
	system("pause");
	system("cls");
	
	return 0;
}

int acarreo(){
	
	int a[100]={0},b[100]={0},cifrasa,cifrasb,acrr=0,aux,i,j,k;
	
	printf ("En la operación suma, el acarreo corresponde al digito que se traspasa de una columna a otra cuando\nla suma de dos digitos excede el número 9. Por ejemplo, si queremos sumar los numeros 27 y 59,\nprimero sumamos la segunda columna (7 + 9) y obtenemos como resultado 6, con un acarreo de 1\nque se traspasa a la columna de la izquierda. Luego sumamos la primera columna (1 + 2 + 5),\nobteniendo como resultado final 86.\n\n\t"ANSI_COLOR_RED"1"ANSI_COLOR_RESET"\t"ANSI_COLOR_RED"acarreo"ANSI_COLOR_RESET"\n\t2 7\t1 sumando\n\t5 9 +\t2 sumando\n\t____\n\t8 6\tSuma.\n\n");
	system ("pause");
	system ("cls");
	printf("Ingrese dos numeros enteros: ");
	scanf("%d%d",&a[0],&b[0]);
	
	//separar numero en cifras
	for(cifrasa=0,i=1;a[0]>0;cifrasa++,i++){
		a[i]=a[0]%10;
		a[0]=a[0]/10;
		//printf ("%d\n%d\n",a[0],a[i]);
		//getch();
	}
	for(cifrasb=0,i=1;b[0]>0;cifrasb++,i++){
		b[i]=b[0]%10;
		b[0]=b[0]/10;
		//printf ("%d\n%d\n",a[0],a[i]);
		//getch();
	}
	//matriz suma
	for(i=0;i<=4;i++){
		if(i==0){
			for(j=cifrasa,k=cifrasb,aux=0;j>0||k>0;j--,k--){
				aux=a[j]+b[k];
				if(aux>=10){
					acrr++;
					aux=aux/10;
					printf(ANSI_COLOR_RED"%d "ANSI_COLOR_RESET,aux);
				}else{
					printf ("  ");
				}
			}
			printf(ANSI_COLOR_RED"\tAcarreo"ANSI_COLOR_RESET);	
			printf("\n");	
			printf("  ");
		}
		if(i==1){
			for(j=cifrasa;j>0;j--){
				printf ("%d ",a[j]);
			}
			if(cifrasa>=cifrasb){
				printf("\t1 Sumando");
			}else{
				for (j=cifrasa;j<=cifrasb;j++){
					printf("  ");
				}
				printf("\t1 Sumando");
			}
			printf ("\n");
			printf(" +");
		}
		if(i==2){
			for(j=cifrasb;j>0;j--){
				printf ("%d ",b[j]);
			}
			if(cifrasb>=cifrasa){
				printf("\t2 Sumando");
			}else{
				for (j=cifrasa;j<=cifrasb;j++){
					printf("  ");
				}
				printf("\t2 Sumando");
			}
			printf ("\n");
		}
		if(i==3){
			for(j=0;j<cifrasa+cifrasb+2;j++){
				printf("_");
			}
			printf ("\n");
			printf("  ");
		}
		if (i==4){
			for(j=cifrasa,k=cifrasb,aux=0;j>0||k>0;j--,k--){
					aux=a[j]+b[k];
					if(aux>=10){
						aux=aux%10;
						printf(ANSI_COLOR_GREEN"%d "ANSI_COLOR_RESET,aux);
					}else{
						printf(ANSI_COLOR_GREEN"%d "ANSI_COLOR_RESET,aux);
					}
				}
			printf(ANSI_COLOR_GREEN"\t  Suma"ANSI_COLOR_RESET);		
		}
	}
	printf ("\n\ncantidad de acarreos en la suma: %d.",acrr);
	printf("\n\n");
	system ("pause");
	system ("cls");
	
	return 0;
}

int lychrel(){
	
	int num,aux,cifras,i,j,cap[10],capicua=0,sumacapicua=0,it=1;
	
	printf ("Numeros de Lychrel. Cuando se aburren, los aficionados a las matematicas se dedican a jugar con\nlos numeros. Eso les lleva, por ejemplo, a tomar cualquier numero, darle la vuelta y sumarlo a si\nmismo, repitiendo el proceso una y otra vez hasta dar con un numero capicua (aquellos que se leen\nigual de izquierda a derecha que de derecha a izquierda).\n");
	printf ("Por ejemplo, para el numero "ANSI_COLOR_RED"91"ANSI_COLOR_RESET" llegamos a un capicua en solo dos pasos:\n\n\t91 + 19 = 110\n\t110 + 011 = 121\t"ANSI_COLOR_RED"numero capicua."ANSI_COLOR_RESET"\n\n");
	printf ("Algunos numeros se resisten a alcanzar un capicua. El 196 es el numero mas pequeno para el que no\nse ha llegado a ninguno, por mas que se ha intentado. Los matematicos no han podido demostrar que,\nefectivamente, no vaya a llegarse a uno. Los numeros con los que, se sospecha, no puede alcanzarse\nun capicua se conocen como numeros de Lychrel.\n");
	system ("pause");
	system ("cls");
	printf("Ingrese un numero entero entre 1 y 100.000: ");
	scanf("%d",&num);
	
	//primera vuelta
	printf("%d + ",num);
		//cifras
		for(cifras=0,aux=num;aux>0;cifras++){
			aux=aux/10;
		}
		
		//alocacion dinamica
		for(i=0,aux=num,j=cifras-1;i<cifras;i++,j--){
			cap[i]=aux/pow(10,j);
			aux=aux-(cap[i]*pow(10,j));
			//printf("%d|",cap[i]);
			//getch();	
		}
		
		//inversa
		for(i=cifras-1,aux=0,j=cifras-1;i>=0;i--,j--){
			aux+=cap[i]*pow(10,j);	
		}
		printf("%d ",aux);
		//capicua
		sumacapicua=num+aux;
		printf("= %d",sumacapicua);
		getch();
		num=sumacapicua;
	
	while(num<1000000000){
		//cifras
		for(cifras=0,aux=num;aux>0;cifras++){
			aux=aux/10;
		}
		
		//alocacion dinamica
		for(i=0,aux=num,j=cifras-1;i<cifras;i++,j--){
			cap[i]=aux/pow(10,j);
			aux=aux-(cap[i]*pow(10,j));
			//printf("%d|",cap[i]);
			//getch();	
		}
		
		//inversa
		for(i=cifras-1,aux=0,j=cifras-1;i>=0;i--,j--){
			aux+=cap[i]*pow(10,j);	
		}
		
		//capicua
		if(num==aux){
			printf ("\t"ANSI_COLOR_GREEN"capicua."ANSI_COLOR_RESET"\n");
			capicua++;
			break;
		}else{
			printf("\n%d + %d ",num,aux);
			sumacapicua=num+aux;
			printf("= %d",sumacapicua);
			getch();
			num=sumacapicua;
			it++;
		}
	}
	if(num>1000000000){
		printf("\t"ANSI_COLOR_RED"Lychrel?"ANSI_COLOR_RESET);
	}else{
		printf(ANSI_COLOR_GREEN"%d"ANSI_COLOR_RESET" iteraciones para hallar el numero "ANSI_COLOR_GREEN"capicua"ANSI_COLOR_RESET": "ANSI_COLOR_GREEN"%d"ANSI_COLOR_RESET,it,num);
	}	
	printf("\n");
	system("pause");
	system("cls");
	return 0;
}
