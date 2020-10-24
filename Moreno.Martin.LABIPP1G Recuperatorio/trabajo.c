#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include "trabajo.h"
#include "fecha.h"
#include "auto.h"
#include "servicio.h"
int inicializarTrabajo(eTrabajo trabajos[], int tam)
{
    int error = 1;

    if( trabajos != NULL && tam > 0)
    {
        for(int i=0; i < tam; i++)
        {
            trabajos[i].isEmpty = 1;
        }
        error=0;
    }

    return error;
}

void mostrarTrabajo(eTrabajo trabajo, eAuto autos[], int tamA, eServicio servicios[], int tamS)
{
    char descServicio[20];
    char patenteAuto[20];

    if(obtenerDescripcionServicio(servicios, tamS, trabajo.idServicio, descServicio)==0
       && obtenerPatenteAuto(autos, tamA, trabajo.patenteAuto, patenteAuto)==0)
    {
        printf(" %4d  %10s   %10s    %02d/%02d/%d\n",
           trabajo.id,
           patenteAuto,
           descServicio,
           trabajo.fecha.dia,
           trabajo.fecha.mes,
           trabajo.fecha.anio
           );
    }else
    {
        printf("problema al obtener datos\n\n");
    }
}

int mostrarTrabajos(eTrabajo trabajos[], int tamT, eAuto autos[], int tamA, eServicio servicios[], int tamS)
{
    int flag = 0;
    int error = 1;

    if(autos != NULL && tamA >0 && trabajos != NULL && tamT >0 && servicios != NULL && tamS >0)
    {
        //system("cls");
        printf(" id         Nombre     Comida     Fecha\n");
        printf("---------------------------------------\n");

        for(int i= 0; i < tamT; i++)
        {
            if(trabajos[i].isEmpty == 0)
            {
                mostrarTrabajo(trabajos[i], autos, tamA, servicios, tamS);
                flag = 1;
            }

        }
        if( flag == 0)
        {
            printf("       No hay trabajos en la lista\n");
        }
        printf("\n\n");

        error = 0;
    }


    return error;
}

int buscarLibreTrabajo(eTrabajo trabajos[], int tam)
{
    int indice = -1;

    for(int i=0; i < tam; i++)
    {
        if(trabajos[i].isEmpty == 1)
        {
            indice = i;
            break;
        }
    }

    return indice;
}

//int altaAlmuerzo(eAlmuerzo almuerzos[], int tamA, eDeporte sports[], int tamD, ePersona gente[], int tamP, eComida foods[], int tamC, int id)
int altaTrabajo(eTrabajo trabajos[], int tamT, eAuto autos[], int tamA, eServicio servicios[], int tamS, eMarca marcas[], int tamM, eColor colores[], int tamC, int id)
{
    int error = 1;
    int indice;
    int auxIdServicio;
    char auxPatente[7];
    eTrabajo nuevoTrabajo;

    if( trabajos != NULL && tamT > 0 && autos != NULL && tamA > 0 && servicios != NULL && tamS > 0 && id > 0 )
    {
        system("cls");
        printf("***Alta Trbajo***\n\n");

        indice = buscarLibreTrabajo(trabajos, tamT);

        if( indice == -1)
        {
            printf("No hay lugar libre para otro trabajo\n");
        }
        else
        {
            nuevoTrabajo.id=id;
            nuevoTrabajo.isEmpty = 0;

            mostrarAutos(autos, tamA, marcas, colores, tamM, tamC);
            printf("ingrese patente del auto: ");
            fflush(stdin);
            scanf("%c", &auxPatente);
            while( validarPatente(autos, tamA, auxPatente)==0)
            {
                printf("patente invalida. reingrese patente: ");
                scanf("%d", &auxPatente);
            }
            nuevoTrabajo.patenteAuto = auxPatente;

            //gets(nuevaAlmuerzo.nombre);

            mostrarServicios(servicios, tamS);
            printf("ingrese id servicio: ");
            fflush(stdin);
            scanf("%d", &auxIdServicio);
            while( validarIdServicio(servicios, tamS, auxIdServicio)==0)
            {
                printf("id invalido. reingrese id: ");
                scanf("%d", &auxIdServicio);
            }
            nuevoTrabajo.idServicio = auxIdServicio;

            printf("ingrese fecha dd/mm/aaaa: ");
            scanf("%d/%d/%d", &nuevoTrabajo.fecha.dia, &nuevoTrabajo.fecha.mes, &nuevoTrabajo.fecha.anio);

            trabajos[indice] = nuevoTrabajo;
            error = 0;
        }
    }

    return error;
}
