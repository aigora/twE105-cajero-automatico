#include <stdio.h>
int main()
{
	int t1,t2;
    int s1,s2,ingreso, retirada,p1,p2,p3,p4,cambiopin,pinintroducido,nuevopin,salir;
    printf ("Introduzca la tarjeta\n");
    scanf ("%i",&t1);
    printf ("Introduzca el pin\n");
    scanf("%i",&p1);
	switch (t1) 
		{ 
		case `s`: 
		 printf ("Su saldo actual a dia de hoy es:");
		 break; 
		case `i`:
		 printf ("Escriba la cantidad de dinero que desee ingresar");
		 scanf("%i",&ingreso);
		 break; 
		case `r`;
		 printf ("Escriba la cantidad de dinero que desee retirar:");
		 break; 
		case `c`;
		 printf ("Escriba su pin actual");
		 scanf("%d",&pinintroducido);
		 if (p1=pintroducido)
		  {
			printf ("Introduzca su nuevo pin");
			scanf("%i",&nuevopin);
		  }
	     else
		 {
			printf ("Pin incorrecto,vuelva a intentarlo.");
		 }
		 break;
		case `salir`:
		 printf("No olvide coger su recibo y su tarjeta");
		 break;
	 }
}



