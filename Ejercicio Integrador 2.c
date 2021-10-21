#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX 15
#define CMAX 100

/*Definicion de tipo de dato*/

typedef struct 
{
    char nombre [CMAX];
    int edad;
    long int telefono;
}InfoPaciente;
typedef InfoPaciente Lista [MAX];
typedef char TCadena[CMAX];

/*Protocolos de funciones y modulos*/

void CargarLista(Lista a, int *b); 
void AgregarPaciente(Lista a, int *b); 
void EliminarPaciente(Lista a, int *b);
void MostrarPaciente(Lista a, int b);
void ModificarPaciente(Lista a, int b);
void OrdenarLista(Lista a, int b);
void MostrarLista(Lista a, int b);
void BuscarPaciente(Lista a, int *b, int *c, int d);
void scanfString(TCadena s);

/*Cuerpo Principal del programa*/

int main(int argc, char **argv)
{
	int n, eleccion;
	
    Lista l1;

	n = 0;

    printf("__________CARGA DE DATOS DE LO 5 PRIMEROS PACIENTES__________");

    CargarLista(l1, &n);
	
	do
	{        
		
		printf("\n\n__________MENU DE OPCIONES__________");
		
		printf("\n\n1-Agregar paciente nuevo (El maximo de pacientes es 15)");
		printf("\n2-Eliminar paciente dado un nombre");
		printf("\n3-Mostrar un paciente dado un nombre");
		printf("\n4-Modificar dato de paciente dado un nombre");
		printf("\n5-Ordenar lista por edad de forma descendente");
		printf("\n6-Mostrar lista");
		
		printf("\n\nIngrese '7' para salir");
		
		printf("\n\nEleccion: "); scanf("%d", &eleccion);
		
		system("cls");
		
		switch (eleccion)
		{
		case 1:
			if(n != MAX)
			{
				AgregarPaciente(l1, &n);
			}
			else
			{
				printf("La lista esta llena");
			}
            break;
		case 2:
			EliminarPaciente(l1, &n);
            break;
		case 3:
            MostrarPaciente(l1, n);
			break;
		case 4:
			ModificarPaciente(l1, n);
			break;
		case 5:
			OrdenarLista(l1, n);
			break;
		case 6:
			MostrarLista(l1, n);
			break;
		default:
			if(eleccion != 7)
			{
				printf("Debe ingresar una opcion valida");
			}
			break;
		}
	}
	while(eleccion != 7);
	
	return 0;
}

void CargarLista(Lista a, int *b)
{
    int i;
	
    for ( i = 0; i < 5; i++)
    {
		fflush(stdin);
        printf("\nIngrese el nombre del paciente %d : ", i); scanfString(a[i].nombre);
        printf("\nIngrese la edad del paciente %d : ", i); scanf("%d", &a[i].edad);
        printf("\nIngrese el numero de telefono del paciente %d : ", i); scanf("%ld", &a[i].telefono);
    }
	
	*b = 5;
}  

void AgregarPaciente(Lista a, int *b)
{
    int i;

    for ( i = *b; i < *b + 1; i++)
    {
        fflush(stdin);
        printf("\nIngrese el nombre del paciente %d : ", i); scanfString(a[i].nombre);
        printf("\nIngrese la edad del paciente %d : ", i); scanf("%d", &a[i].edad);
        printf("\nIngrese el numero de telefono del paciente %d : ", i); scanf("%ld", &a[i].telefono);
    }
	
	*b += 1;
}

void EliminarPaciente(Lista a, int *b)
{
	int contador,encontro,posicion; 
	
	encontro = 0; 
	posicion = 0; 
	
	BuscarPaciente(a, &encontro, &posicion, *b);

	if(encontro==1){
		for(contador = posicion; contador < *b; contador++){ 
			strcpy(a[contador].nombre, a[contador + 1].nombre);	
		}
		
		printf("\n\nDatos del paciente %d borrados", posicion);
		*b= *b - 1;
	}
	else
	   printf("\n No se encontro ese nombre \n");

}

void MostrarPaciente(Lista a, int b)
{
	int encontro,posicion; 
	
	encontro = 0; 
	posicion = 0; 
	
	BuscarPaciente(a, &encontro, &posicion, b);

	if(encontro==1)
	{
		printf("\n\n________Datos del Paciente %d_________", posicion);
		printf("\n\nEl nombre del paciente es : %s", a[posicion].nombre);
		printf("\nLa edad del paciente es : %d", a[posicion].edad);
		printf("\nEl telefono del paciente es : %ld", a[posicion].telefono);
	}
	else
	   printf("\n No se encontro ese nombre \n");
}

void ModificarPaciente(Lista a, int b)
{
	int encontro,posicion; 
	
	encontro = 0; 
	posicion = 0; 

	BuscarPaciente(a, &encontro, &posicion, b);

	if(encontro==1)
	{
		fflush(stdin);
		printf("\n\n________Datos del Paciente %d_________", posicion);
		printf("\n\nEl nombre del paciente es : %s", a[posicion].nombre);
		printf("\nNuevo Nombre: "); scanfString(a[posicion].nombre);
		printf("\nLa edad del paciente es : %d", a[posicion].edad);
		printf("\nNueva edad: "); scanf("%d", &a[posicion].edad);
		printf("\nEl telefono del paciente es : %ld", a[posicion].telefono);
		printf("\nNuevo telefono: "); scanf("%ld", &a[posicion].telefono);
	}
	else
	   printf("\n No se encontro ese nombre \n");
}

void OrdenarLista(Lista a, int b)
{
    int i, j;
    InfoPaciente aux;
	for(i=0; i<b - 1; i++)
	{
		for(j=i+1; j<b; j++)
		{
			if((a[i].edad) < (a[j].edad))
			{
				aux=a[i];
				a[i] = a[j];
				a[j] = aux;
			}
		}
	}
}

void MostrarLista(Lista a, int b)
{
	int i;
	
	for(i = 0; i < b; i++)
	{
		printf("\n\n________Datos del Paciente %d_________", i);
		printf("\n\nEl nombre del paciente es : %s", a[i].nombre);
		printf("\nLa edad del paciente es : %d", a[i].edad);
		printf("\nEl telefono del paciente es : %ld", a[i].telefono);
		
	}
}

void BuscarPaciente(Lista a, int *b, int *c, int d)
{
	int i;
	char nombre_paciente[CMAX];

	printf("\nIngrese el nombre del paciente: "); 
	fflush(stdin);
	scanfString(nombre_paciente);
	
	for(i=0;i<d;i++){
		if(strcmp(nombre_paciente, a[i].nombre)==0){ 
			*b = 1; 
			*c = i; 
			break; 
		}
	} 
}

void scanfString(TCadena s)
{
	char c;
	int j;
	
	j = 0;
	
	while ( j < CMAX - 1 && (c = getchar()) != EOF && c != '\n')
	{
		s[j] = c;
		j++;
	}
	
	s[j] = '\0';
	
	while (c != EOF && c != '\n')
	{
		c = getchar();
	}
}
