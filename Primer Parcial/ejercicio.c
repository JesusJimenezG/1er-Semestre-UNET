#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main (){
	
	int opc;
	

	do {
		printf ("1) vertices de un cuadrado.\n2) sumatoria.\n3) secuencia fibonacci.\n4) velas de cumpleanos.\n5) salir.\n");
		printf ("ingrese una opcion: ");
		scanf ("%d",&opc);
			if(opc>5||opc<1){
				printf ("opcion incorrecta. Intente de nuevo.\n\n");
				system ("pause");
				system ("cls");
		}	else {
				switch (opc){
					case 1: system ("cls");
							cuadrado();
							system ("pause");
							system ("cls");
							break;
					case 2: system ("cls");
							sumatoria();
							system ("pause");
							system ("cls");
							break;
					case 3: system ("cls");
							fibo();
							system ("pause");
							system ("cls");
							break;
					case 4: system ("cls");
							velas();
							system ("pause");
							system ("cls");
							break;
					case 5: break;
				}
			}
		}while (opc != 5);
	return 0;
}

int cuadrado(){
	
	int x1, x2,x3,x4,y1, y2,y3,y4,sumx,sumy,d1,d2,d3,d4;
	
	printf ("ingrese los puntos de a (x1,y1): ");
	scanf ("%d%d",&x1,&y1);
	printf ("ingrese los puntos en b (x2,y2): ");
	scanf ("%d%d",&x2,&y2);
	printf ("ingrese los puntos de c (x3,y3): ");
	scanf ("%d%d",&x3,&y3);
	printf ("ingrese los puntos en d (x4,y4): ");
	scanf ("%d%d",&x4,&y4);
	printf ("\n\n");
	
	sumx= (x2-x1);
	sumy= (y2-y1);
	sumx=pow(sumx,2);
	sumy=pow(sumy,2);
	d1=sqrt(sumx+sumy);
	
	sumx= (x3-x2);
	sumy= (y3-y2);
	sumx=pow(sumx,2);
	sumy=pow(sumy,2);
	d2=sqrt(sumx+sumy);
	
	sumx= (x4-x3);
	sumy= (y4-y3);
	sumx=pow(sumx,2);
	sumy=pow(sumy,2);
	d3=sqrt(sumx+sumy);
	
	sumx= (x4-x1);
	sumy= (y4-y1);
	sumx=pow(sumx,2);
	sumy=pow(sumy,2);
	d4=sqrt(sumx+sumy);
	
	
	if (d1==d2&&d3==d4){
		printf ("los vertices son de un cuadrado.\n");
		getch ();
	}	else{
		printf ("los vertices no son de un cuadrado.\n");
		getch ();
	}

	
}

int sumatoria(){		//no terminado
	double a,b,c,i,x,tot;

	for (i=0,x=5,tot=0;i<=20;i++,x++){	
		a = pow(i,2);
		b = x + pow(x,3);
		c = a + x * b;
		a = i * c;
			if (tot==0){
				tot+= a;
			}	else{
					tot+=tot;
				}
		}while (x<25);
	//}
	printf ("el valor de h = %.0f",tot);
	getch();
	
	return 0;
}

int fibo(){
	
	int i,b,c,n,sec;
	
	printf ("Ingrese la cantidad de veces que quiere que se realice la secuencia de Fibonacci: ");
	scanf ("%d",&n);
	printf ("\n\nSecuencia: ");
	for (i=1,b=-1,c=1; i<=n; i++){
		sec = b + c;
		printf ("%d",sec);
			if (i<n){
				printf (", ");
			}
		b = c;
		c = sec;		
		}
		
	printf (".\n\n");
	
	return 0;
}

int velas(){
	
	int edad, cont, vel[100], opc,i,j=1,k,may;
	
	printf ("Ingrese la altura de cada vela. Cuando haya terminado de ingresar el tamano de cada una de las velas, presione 0.\n\n");
	do{
		printf ("Ingrese la altura de la vela %d: ",j);
		scanf("%d",&opc);
		vel[j]=opc;
		j++;
	}while (opc!=0);
	system ("cls");
	
	for (cont=0,i=1; i<j; i++){
		may = vel[i];
		for (k=1;k<j;k++){
			if (vel[k]>may){
				may = vel[k];
			}	
		}
			if(vel[i]!=0){
				if(vel[i]==may){
					cont++;
				}
				printf ("la altura de la vela %d es de: %d\n",i,vel[i]);
				edad = i;
			}
	}
	printf ("\n\n");
	printf ("Velas a apagar: %d de %dcm\n",cont,may);
	printf ("Edad de la cumpleanera: %d\n",edad);
	
	return 0;
}
