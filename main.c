/*
* Programa: Examen Cotecnova
* Autor: Carlos Londoño
* Fecha: 17 de Febrero 2017
*/
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void menu(char *, int *,int*);
void realizar_examen(char *, int *);
int validacion(int *);
void calificar_examen(int *, int *);
void repetir_examen(char *,int *, int *);
void anular_examen();
void salir();

int main()//FUNCION PRINCIPAL
{
    char nombre[30];
    int estado = 0; //0 => verdadero y 1 => falso
    char *pnombre = nombre;
    int *pestado = &estado;
    srand(time(NULL));
    int prueba = rand() % 5;
    int *pprueba = &prueba;
    printf("Bienvenido a Examenes Cotecnova \n");
    printf("Por favor ingrese su nombre para continuar \n");
    scanf("%s", nombre);
    menu(pnombre, pestado,pprueba);
    return 0;
}

void menu(char *pnombre, int *pestado,int *pprueba)//FUNCION MENU
{
    int opcion;
    printf("nombre %s\n", pnombre);
    printf("***** MENU *****\n");printf("\n");
    printf("1. Realizar Examen \n");
    printf("2. Calificar Examen \n");
    printf("3. Repetir Examen \n");
    printf("4. Anular Examen \n");
    printf("0. Salir \n");printf("\n");
    printf("***** FIN MENU *****\n");

    printf("\nMarque el numero de la opcion que desea ejecutar \n");
    printf("Opcion: ");
    scanf("%d", &opcion);printf("\n");

    printf("valor ingresado: %d \n", opcion);
    printf("Haz seleccionado: ");
    switch(opcion)//EJECUCION DEL MENU
    {
        case 1: printf("1. Realizar Examen\n");
                realizar_examen(pnombre, pestado);
            break;
        case 2: printf("2. Calificar Examen\n");
                calificar_examen(pestado,pprueba);
            break;
        case 3: printf("3. Repetir Examen\n");
                repetir_examen(pnombre,pestado,pprueba);
            break;
        case 4:
                anular_examen(pestado);
            break;
        case 0: printf("0. Salir\n");
                salir();
            break;
        default: printf("Una opcion invalida, por favor intentelo de nuevo.\n");
    }getch();
system("cls");
menu(pnombre, pestado, pprueba);
}

void realizar_examen(char *pnombre, int *pestado)//FUNCION REALIZAR EXAMEN
{
    int estado;
    printf("***** REALIZAR EXAMEN *****\n");
    estado = validacion(pestado);
    if(estado == 0)
        {   *pestado = 1;//printf("%s",pnombre);
            printf("Examen realizado con exito \n");
        }else{  printf("***** ERROR *****\n");
                printf("El examen ya ha sido realizado, no se permite volverlo a presentar, por favor vaya al menu y seleccione calificar\n");
             }
    printf("\n");
}

int validacion(int *pestado)//FUNCION DE VALIDACION
{
    return *pestado;
}

void calificar_examen(int *pestado, int *pprueba)//FUNCION CALIFICAR EXAMEN
{
    int verificar;
    verificar=validacion(pestado);
    printf("***** CALIFICAR EXAMEN *****\n");
    if(verificar == 1)
        {   printf("Examen calificado con exito \n");printf("\nCalificacion: %d",*pprueba);printf("/5\n");
        }else{  printf("***** ERROR *****\n");
                printf("No se pueden mostrar resultados del examen porque no se ha realizado el examen, por favor vaya al menu y seleccione calificar\n");
             }
    printf("\n");
    printf("\n");
}

void repetir_examen(char *pnombre,int *pestado, int *pprueba)//FUNCION REPETIR EXAMEN
{
    printf("***** REPETIR EXAMEN *****\n");
    printf("\n");

    int comprobar;
    comprobar = validacion(pestado);
    if(comprobar == 1)
        {   if (*pprueba <=4)
                {
                    *pestado = 0;
                    system("cls");
                    *pprueba = rand() % 5;
                    printf("***** REPITIENDO EXAMEN *****\n");
                    realizar_examen(pnombre,pestado);
                }

        }else{  printf("***** ERROR *****\n");
                printf("No se permite volverlo a presentar si la calificacion es mayor a 4 o no ha presentado el examen, por favor vaya al menu y seleccione Realiar examen\n");
             }
    printf("\n");
}
void anular_examen(int *pestado)//FUNCION ANULAR EXAMEN
{
    printf("\n***** ANULAR EXAMEN *****\n");
    *pestado=0;
    printf("\nExamen anulado correctamente.\n");
    getch();
    system("cls");
    main();
    printf("\n");
}

void salir()//FUNCION SALIR DEL MENU
{
    printf("***** SALIR *****\n");
    printf("\n");
exit(0);
}
