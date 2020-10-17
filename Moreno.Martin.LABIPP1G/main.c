#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include "marca.h"
#include "color.h"
#include "servicio.h"
#include "auto.h"

#define TAM 10
#define TAM_M 5
#define TAM_C 5
#define TAM_S 4

// estructura principal auto
// varios autos pueden ser del mismo color/marca
// servicio es otro array, TIPO COLOR Y SERVICIO VAN HARDCODEADOS
//PARA AUTO VA ALTA BAJA Y MODIFICACION
//PARA TRABAJO VA ALTA NOMAS
//auto id arranca donde quieras

char menu();

int main()
{
    char seguir = 's';
    char confirma;
    int rta;
    int proximoIdAuto = 1000;
    int proximoIdServicio = 1000;
    eAuto autos[TAM];

    eMarca marcas[TAM_M]=
    {
        {1000, "Renault"},
        {1001, "Fiat"},
        {1002, "Ford"},
        {1003, "Chevrolet"},
        {1004, "Peugeot"},

    };
    eColor colores[TAM_C]=
    {
        {5000, "Negro"},
        {5001, "Blanco"},
        {5002, "Gris"},
        {5003, "Rojo"},
        {5004, "Azul"},
    };
    eServicio lavados[TAM_S]=
    {
        {20000, "Lavado:", 250},
        {20001, "Pulido:", 300},
        {20002, "Encerado:", 400},
        {20003, "Completo:", 600},
    };

    if(inicializarAuto(autos, TAM)==0)
    {
        printf("autos inicializadas con exito\n");
    }
    else
    {
        printf("problema al inicializar\n");
    }

    do
    {
        switch(menu())
        {
        case 'a':

            if(altaAuto(autos, TAM, marcas, TAM_M, colores, TAM_C, proximoIdAuto)==0)
            {
                printf("alta exitosa\n\n");
            }
            else
            {
                printf("problemas con el alta\n\n");
            }

            break;

        case 'b':
            rta = modificarAuto(autos, TAM, marcas, TAM_M, colores, TAM_C);

            if( rta == 0)
            {
                printf("modificacion exitosa\n\n");
            }
            else if(rta ==2)
            {
                printf("modificacion cancelada\n\n");
            }
            else
            {
                printf("se a producido un error en la modificacion\n\n");
            }
            break;

        case 'c':
            rta = bajaAuto(autos, TAM, marcas, TAM_M, colores, TAM_C);

            if( rta == 0)
            {
                printf("Baja exitosa\n\n");
            }
            else if(rta ==2)
            {
                printf("Baja cancelada\n\n");
            }
            else
            {
                printf("se a producido un error en la Baja\n\n");
            }
            break;

        case 'd':
            system("cls");
            ordenarAutosXMarcaPatente(autos, TAM, ASC, ASC);
            mostrarAutos(autos, TAM, marcas, TAM_M, colores, TAM_C);
            break;

        case 'e':
            system("cls");
            mostrarMarcas(marcas, TAM_M);
            break;

        case 'f':
            system("cls");
            mostrarColores(colores, TAM_C);
            break;

        case 'g':
            system("cls");
            mostrarServicios(lavados, TAM_S);
            break;

        case 'h':
            system("cls");
            printf("FALTA\n");
            break;

        case 'i':
            system("cls");
            printf("FALTA\n");
            break;

        case 'z':
            printf("Desea salir?: ");
            fflush(stdin);
            scanf("%c", &confirma);
            confirma = tolower(confirma);
            if(confirma == 's')
            {
                seguir = 'n';
            }
            break;

        }
        system("pause");
    }
    while(seguir == 's');

    return 0;
}

char menu()
{
    char opcion;
    system("cls");

    printf("   Lavadero de Autos   \n\n");
    printf("a Alta Auto\n");
    printf("b Modificar Auto\n");
    printf("c Baja Autos\n");
    printf("d Listar Autos\n");
    printf("e Listar Marcas\n");
    printf("f Listar Colores\n");
    printf("g Listar Servicios\n");
    printf("h Alta trabajo\n");
    printf("i Listar trabajos\n");
    printf("z Salir\n\n");
    printf("Ingrese opcion: ");
    fflush(stdin);
    opcion = tolower(getchar());

    return opcion;
}
