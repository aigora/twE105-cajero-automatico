#include <stdio.h>
int main()
{
	// sea a sacar efectivo,b ingresar efectivo,c cambiar el pin,d consultar saldo y e salir 
    int a,b,c,d,e;
    int operacion;
    int p,pi,np,cp,intentos=0;
    //sea p el pin de la tarjeta, pi el pin introducido, sea np nuevo pin, sea cp cambio de pin, intentos.
    //he asignado cantidad1 a la cantidad de dinero que desea retirar y cantidad2 a la cantidad de dinero que se desea ingresar.
    int cantidad1,cantidad2; 
	float saldo; 
	printf ("Introduzca la tarjeta\n");
    scanf ("%i",&t1);
    //introduce el pin y en caso de que sea incorrecto tiene 3 oportunidades y sino lo acierta fin del programa.
    {
    do{ 
			printf("Introduzca el pin: "); 
			scanf("%d", &pin); 
			if(pin==pintarjeta) 
			printf("Bienvenido");
			intentos++;  
			}while (intentos<3 && pin!=pintarjeta);
	
	printf("Seleccione si desea sacar efectivo(a),ingresar efectivo(b),cambiar el pin(c),consultar saldo(d) o salir(e)");
	scanf("%i",&operacion)
	
	
	switch (operacion) 
		{ 
		case `a`: 
		     do{ 
					printf("introducir cantidad que desea retirar:"); 
					scanf("%d", &cantidad1); 
					if(cantidad1<=saldo) 
					printf("Procedamos a la retirada.");
					intentos++;  
					}while (intentos<3 && cantidad1>saldo);
		 
		 break; 
		case `b`:
					 printf ("Escriba la cantidad de dinero que desee ingresar");
					 scanf("%i",&cantidad2);
					 printf("Ingreso realizado con exito");
					 saldo=saldo+cantidad2;
					 printf("su nuevo saldo es %.3f",saldo);
		 break; 
		case `c`;
				     do{ 
					printf("Escriba su pin actual"); 
					scanf("%d", &pin); 
					if(pin==pintarjeta) 
						printf("Introduzca su nuevo pin");
						scanf("%d",%np);
						pintarjeta=np;
						printf("Su codigo pin se ha cambiado con exito");
					intentos++;  
					}while (intentos<3 && pin!=pintarjeta);
		 break; 
		case `d`;
					printf ("Su saldo actual a dia de hoy es %.3f",saldo);
		 break;
		case `e`:
		 break;
	 }
}



