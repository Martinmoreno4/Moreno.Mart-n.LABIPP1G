#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include "marca.h"
#include "color.h"
#include "servicio.h"
#include "auto.h"
#include "trabajo.h"

#define TAM 10
#define TAM_M 5
#define TAM_C 5
#define TAM_S 4
#define TAM_T 10

char menu();

int main()
{
    char seguir = 's';
    char confirma;
    int rta;
    int proximoIdAuto = 1000;
    int proximoIdServicio = 1000;
    int proximoIdTrabajo = 1000;
    eAuto autos[TAM];

    eTrabajo trabajos[TAM_T];

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

    proximoIdAuto += hardcodearAutos(autos, TAM, 8);

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
            if(altaTrabajo(trabajos, TAM_T, autos, TAM, lavados, TAM_S, marcas, TAM_M, colores, TAM_C, proximoIdTrabajo)==0)
            {
                printf("alta exitosa\n\n");
            }
            else
            {
                printf("problemas con el alta\n\n");
            }
            break;

        case 'i':
            system("cls");
            mostrarTrabajos(trabajos, TAM_T, autos, TAM, lavados, TAM_S);
            break;

        case 'j':
            system("cls");
            mostrarColorSeleccionado(colores, TAM_C, autos, TAM, marcas, TAM_M);
            break;

        case 'k':
            system("cls");
            mostrarMarcaSeleccionada(colores, TAM_C, autos, TAM, marcas, TAM_M);
            break;

        case 'l':
            system("cls");

            break;

        case 'm':
            system("cls");

            break;

        case 'n':
            system("cls");

            break;

        case 'o':
            system("cls");

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
    printf("j Listar Color seleccionado\n");//
    printf("k Listar marca seleccionado\n");//
    printf("l Mostrar auto mas viejo o viejos\n");
    printf("m Listar autos separados por marca\n");
    printf("n Listar autos por marca y color seleccionado\n");
    printf("o Listar marca mas elegida\n");
    printf("z Salir\n\n");
    printf("Ingrese opcion: ");
    fflush(stdin);
    opcion = tolower(getchar());

    return opcion;
}
