#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include "auto.h"

int inicializarAuto(eAuto autos[], int tam)
{
    int error = 1;

    if( autos != NULL && tam > 0)
    {
        for(int i=0; i < tam; i++)
        {
            autos[i].isEmpty = 1;
        }
        error=0;
    }

    return error;
}

void mostrarAuto(eAuto unAuto, eMarca marcas[], eColor colores[], int tamM, int tamC)
{
    char descMarca[20];
    char descColor[20];

    if(obtenerDescripcionMarca(marcas, tamM, unAuto.idMarca, descMarca)==0 && obtenerDescripcionColor(colores, tamC, unAuto.idColor, descMarca)==0)
    {
        printf(" %6d  %6s   %s   %s   %d\n",
           unAuto.id,
           unAuto.patente,
           descMarca,
           descColor,
           unAuto.modelo
           );
    }else
    {
        printf("problema al obtener descripcion de la mara y/o el color del auto\n\n");
    }

}

void mostrarAutos(eAuto autos[], int tam, eMarca marcas[], int tamM, eColor colores[], int tamC)
{
    int flag = 0;
    int error = 1;

    if(autos != NULL && tam>0)
    {
        //system("cls");
        printf(" Id   Patente   Marca   Color  Modelo\n");
        printf("-----------------------------------------\n");

        for(int i= 0; i < tam; i++)
        {
            if(autos[i].isEmpty == 0)
            {
                mostrarAuto(autos[i], marcas, colores, tamM, tamC);
                flag = 1;
            }

        }
        if( flag == 0)
        {
            printf("       No hay autos que mostrar\n");
        }
        printf("\n\n");

        error = 0;
    }


    return error;
}

int altaAuto(eAuto autos[], int tam, eMarca marcas[], int tamM, eColor colores[], int tamC, int id)
{
    int error = 1;
    int indice;
    int auxIdMarca;
    int auxIdColor;
    eAuto nuevaAuto;

    if( autos != NULL && tam > 0 && id > 0)
    {
        system("cls");
        printf("***Alta de persona***\n\n");

        indice = buscarLibre(autos, tam);

        if( indice == -1)
        {
            printf("el sistema esta completo\n");
        }
        else
        {
            nuevaAuto.id=id;
            nuevaAuto.isEmpty = 0;
            printf("ingrese id: ");
            fflush(stdin);
            gets(nuevaAuto.id);

            printf("ingrese patente: ");
            fflush(stdin);
            scanf("%d", &nuevaAuto.patente);

            mostrarColores(colores, tamC);
            printf("ingrese id de color: ");
            scanf("%d", &auxIdColor);

            while( validarIdColor(colores, tamC, auxIdColor)==0)
            {
                printf("id invalido. reingrese id color: ");
                scanf("%d", &auxIdColor);
            }
            nuevaAuto.idColor = auxIdColor;

            mostrarMarcas(marcas, tamM);
            printf("ingrese id de marca: ");
            scanf("%d", &auxIdMarca);

            while( validarIdMarca(marcas, tamM, auxIdMarca)==0)
            {
                printf("id invalido. reingrese id marca: ");
                scanf("%d", &auxIdMarca);
            }
            nuevaAuto.idMarca = auxIdMarca;

            autos[indice] = nuevaAuto;
            error = 0;
        }
    }

    return error;
}

int buscarAuto(eAuto autos[], int tam, int patente)
{
    int indice = -1;

    for(int i=0; i < tam; i++)
    {
        if(autos[i].patente == patente && autos[i].isEmpty == 0)
        {
            indice = i;
            break;
        }
    }

    return indice;
}

int bajaAuto(eAuto autos[], int tam, eMarca marcas[], int tamM, eColor colores[], int tamC)
{
    int error = 1;
    int patente;
    int indice;
    char confirma;

    if(autos != NULL && tam > 0)
    {
        system("cls");
        printf("      Baja de auto     \n\n");
        mostrarAutos(autos, tam, marcas, colores, tamM, tamC);
        printf("ingrese la patente: ");
        scanf("&d", &patente);

        indice = buscarAuto(autos, tam, patente);

        if( indice == -1)
        {
            printf("no existe un auto con ese patente\n\n");
        }
        else
        {
            mostrarAuto(autos[indice], marcas, colores, tamM, tamC);
            printf("Confirma borrado: ");
            fflush(stdin);
            scanf("%c", &confirma);
            if(confirma == 's')
            {
                autos[indice].isEmpty = 1;
                error = 0;
            }
            else
            {
                error = 2;
            }
        }
    }
    return error;
}


int buscarLibre(eAuto autos[], int tam)
{
    int indice = -1;

    for(int i=0; i < tam; i++)
    {
        if(autos[i].isEmpty == 1)
        {
            indice = i;
            break;
        }
    }

    return indice;
}

int obtenerDescripcionColor(eColor colores[], int tam, int id, char descripcion)
{
    int error = 1;
    if(colores !=NULL && tam > 0 && id >= 1000 && descripcion!=NULL)
    {
        for(int i=0; i < tam; i++)
        {
            if(colores[i].id == id)
            {
                strcpy(descripcion, colores[i].descripcion);
                error=0;
                break;
            }
        }
    }
    return error;
}

int obtenerDescripcionMarca(eMarca marcas[], int tam, int id, char descripcion)
{
    int error = 1;
    if(marcas !=NULL && tam > 0 && id >= 1000 && descripcion!=NULL)
    {
        for(int i=0; i < tam; i++)
        {
            if(marcas[i].id == id)
            {
                strcpy(descripcion, marcas[i].descripcion);
                error=0;
                break;
            }
        }
    }
    return error;
}

int ordenarAutosXMarcaPatente(eAuto autos[], int tam, int criterioM, int criterioP)
{
    int error = 1;
    eAuto auxAuto;

    if(autos != NULL && tam > 0 && criterioM >= 0 && criterioM <= 1 && criterioP >= 0 && criterioP <= 1)
    {
        for(int i=0; i < tam -1; i++)
        {
            for(int j=i +1; j<tam; j++)
            {
                if( autos[i].idMarca > autos[j].idMarca && criterioM)
                {
                    auxAuto = autos[i];
                    autos[i] = autos[j];
                    autos[j] = auxAuto;
                }
                else if ( autos[i].idMarca < autos[j].idMarca && !criterioM)
                {
                    auxAuto = autos[i];
                    autos[i] = autos[j];
                    autos[j] = auxAuto;
                }
                else if(autos[i].idMarca == autos[j].idMarca && autos[i].patente > autos[j].patente && criterioP)
                {
                    auxAuto = autos[i];
                    autos[i] = autos[j];
                    autos[j] = auxAuto;
                }
                else if(autos[i].idMarca == autos[j].idMarca && autos[i].patente < autos[j].patente && criterioP)
                {
                    auxAuto = autos[i];
                    autos[i] = autos[j];
                    autos[j] = auxAuto;
                }
            }
        }
    error = 0;
    }
    return error;
}

int modificarAuto(eAuto autos[], int tam, eMarca marcas[], int tamM, eColor colores[], int tamC)
{
    int error = 1;
    int patente;
    int indice;
    char confirma;
    eColor nuevoIdColor;
    eAuto nuevoModelo;

    if(autos != NULL && tam > 0)
    {
        system("cls");
        printf("  ***Modificar Auto *** \n\n");
        mostrarAutos(autos, tam, marcas, tamM, colores, tamC);
        printf("ingrese la patente: ");
        scanf("&d", &patente);

        indice = buscarAuto(autos, tam, patente);

        if( indice == -1)
        {
            printf("no existe un auto con esa patente\n\n");
        }
        else
        {
            mostrarAutos(autos, tam, marcas, colores, tamM, tamC);

            printf("\ingese nuevo id de color");

            scanf("%d", &nuevoIdColor.id);

            printf("\ingese nuevo año de modelo");

            scanf("%d", &nuevoModelo.modelo);

            printf("Confirme cambio: ");
            fflush(stdin);
            scanf("%c", &confirma);
            if(confirma == 's')
            {
                autos[indice].idColor = nuevoIdColor.id;
                autos[indice].modelo = nuevoModelo.modelo;
                error = 0;
            }
            else
            {
                error = 2;
            }
        }
    }
    return error;
}
