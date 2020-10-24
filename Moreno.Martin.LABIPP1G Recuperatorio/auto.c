#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include "auto.h"
#include "datastore.h"
#include "marca.h"
#include "color.h"

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
    if(obtenerDescripcionMarca(marcas, tamM, unAuto.idMarca, descMarca)==0 && obtenerDescripcionColor(colores, tamC, unAuto.idColor, descColor)==0)
    {
        printf(" %8d  %6s   %10s   %6s   %4d\n",
           unAuto.id,
           unAuto.patente,
           descMarca,
           descColor,
           unAuto.modelo
           );
    }else
    {
        printf("problema al obtener descripcion de la marca y/o el color del auto\n\n");
    }
}

int mostrarAutos(eAuto autos[], int tam, eMarca marcas[], int tamM, eColor colores[], int tamC)
{
    int flag = 0;
    int error = 1;

    if(autos != NULL && tam>0)
    {

        printf("      Id   Patente        Marca     Color   Modelo\n");
        printf("---------------------------------------------------------------\n");

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
            printf("No hay autos que mostrar\n");
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
        printf("***Alta de Auto***\n\n");

        indice = buscarLibre(autos, tam);

        if( indice == -1)
        {
            printf("el sistema esta completo\n");
        }
        else
        {
            nuevaAuto.id=id;
            nuevaAuto.isEmpty = 0;

            printf("ingrese patente: ");

            gets(nuevaAuto.patente);

            mostrarColores(colores, tamC);
            printf("ingrese id de color: ");
            scanf("%d", &auxIdColor);

            while( validarIdColor(colores, tamC, auxIdColor)==0)
            {
                printf("id invalido. reingrese id color: \n");
                fflush(stdin);
                scanf("%d", &auxIdColor);
            }
            nuevaAuto.idColor = auxIdColor;

            mostrarMarcas(marcas, tamM);
            printf("ingrese id de marca: ");
            fflush(stdin);
            scanf("%d", &auxIdMarca);

            while( validarIdMarca(marcas, tamM, auxIdMarca)==0)
            {
                printf("id invalido. reingrese id marca: ");
                fflush(stdin);
                scanf("%d", &auxIdMarca);
            }
            nuevaAuto.idMarca = auxIdMarca;

            autos[indice] = nuevaAuto;
            error = 0;
        }
    }

    return error;
}

int buscarAuto(eAuto autos[], int tam, char patente[])
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

int obtenerDescripcionMarca(eMarca marcas[], int tam, int id, char descripcion[])
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
    int auxIdColor;
    int auxModelo;
    eAuto nuevoAuto;

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
            mostrarColores(colores, tamC);

            printf("\ingese nuevo id de color");

            scanf("%d", &auxIdColor);
            while( validarIdColor(colores, tamC, auxIdColor)==0)
            {
                printf("id invalida. reingrese id: ");
                scanf("%d", &auxIdColor);
            }

            mostrarAutos(autos, tam, marcas, colores, tamM, tamC);

            printf("\ingese nuevo año de modelo");

            scanf("%d", &auxModelo);
            while( auxModelo<1950 || auxModelo>2020)
            {
                printf("Modelo invalido. reingrese modelo: ");
                scanf("%d", &auxModelo);
            }


            printf("Confirme cambio: ");
            fflush(stdin);
            scanf("%c", &confirma);
            if(confirma == 's')
            {
                autos[indice].idColor = auxIdColor;
                autos[indice].modelo = auxModelo;
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

int validarPatente(eAuto autos[], int tam, char patente[])
{
    int esValido = 0;

    if( autos != NULL && tam >0 )
    {
        for(int i=0; i<tam; i++)
        {
            if(autos[i].patente == patente)
            {
                esValido = 1;
                break;
            }
        }

    }

    return esValido;
}

int obtenerPatenteAuto(eAuto autos[], int tam, int id, char patente[])
{
    int error = 1;
    if(autos !=NULL && tam > 0 && patente!=NULL)
    {
        for(int i=0; i < tam; i++)
        {
            if(autos[i].id == id && autos[i].isEmpty == 0)
            {
                strcpy(patente, autos[i].patente);
                error=0;
                break;
            }
        }
    }
    return error;
}

int hardcodearAutos(eAuto autos[], int tam, int cantidad)
{
    int error = -1;
    if( autos != NULL && tam > 0 && cantidad >= 0 && cantidad <= tam)
    {
        error = 0;
        for(int i=0; i < cantidad; i++)
        {
            autos[i].id = idAutosData[i];
            strcpy(autos[i].patente, patentesData[i]);
            autos[i].idMarca = idMarcasData[i];
            autos[i].idColor = idColoresData[i];
            autos[i].modelo = modelosData[i];
            autos[i].isEmpty = 0;
            error++;
        }
    }
    return error;
}

int mostrarColorSeleccionado(eColor colores[], int tamC, eAuto autos[], int tamA, eMarca marcas[], int tamM)
{
    int error = 1;
    int flag = 0;
    char seguir = 's';
    int idSeleccion=0;
    int idColorNegro = 5000;
    int idColorBlanco = 5001;
    int idColorGris = 5002;
    int idColorRojo = 5003;
    int idColorAzul = 5004;

    mostrarColores(colores, tamC);

    while(seguir == 's')
    {
        printf("ingrese id de color que desea buscar\n\n");
        scanf("%d", &idSeleccion);

        switch(idSeleccion)
        {
        case 5000:
            system("cls");
            printf("Autos de color Negro \n\n");

            for(int i=0; i<tamA; i++)
            {
                if( autos[i].isEmpty == 0 && autos[1].idColor == idColorNegro)
                {
                    mostrarAuto(autos[i], marcas, colores, tamM, tamC);
                    flag = 1;
                }
            }
            if( flag == 0)
            {
                printf("no hay autos de color Negro\n\n");
            }
            break;

        case 5001:
            system("cls");
            printf("Autos de color Blanco \n\n");

            for(int i=0; i<tamA; i++)
            {
                if( autos[i].isEmpty == 0 && autos[1].idColor == idColorBlanco)
                {
                    mostrarAuto(autos[i], marcas, colores, tamM, tamC);
                    flag = 1;
                }
            }
            if( flag == 0)
            {
                printf("no hay autos de color Blanco\n\n");
            }
            break;

        case 5002:
            system("cls");
            printf("Autos de color Gris \n\n");

            for(int i=0; i<tamA; i++)
            {
                if( autos[i].isEmpty == 0 && autos[1].idColor == idColorGris)
                {
                    mostrarAuto(autos[i], marcas, colores, tamM, tamC);
                    flag = 1;
                }
            }
            if( flag == 0)
            {
                printf("no hay autos de color Gris\n\n");
            }
            break;

        case 5003:
            system("cls");
            printf("Autos de color Rojo \n\n");

            for(int i=0; i<tamA; i++)
            {
                if( autos[i].isEmpty == 0 && autos[1].idColor == idColorRojo)
                {
                    mostrarAuto(autos[i], marcas, colores, tamM, tamC);
                    flag = 1;
                }
            }
            if( flag == 0)
            {
                printf("no hay autos de color Rojo\n\n");
            }
            break;

        case 5004:
            system("cls");
            printf("Autos de color Azul\n\n");

            for(int i=0; i<tamA; i++)
            {
                if( autos[i].isEmpty == 0 && autos[1].idColor == idColorAzul)
                {
                    mostrarAuto(autos[i], marcas, colores, tamM, tamC);
                    flag = 1;
                }
            }
            if( flag == 0)
            {
                printf("no hay autos de color Azul\n\n");
            }
            break;

        default:
            printf("id invalido\n\n");
            break;
        }

        printf("desea continuar?\n\n");
        scanf("%c", &seguir);
    }


    return error;
}

int mostrarMarcaSeleccionada(eColor colores[], int tamC, eAuto autos[], int tamA, eMarca marcas[], int tamM)
{
    int error = 1;
    int flag = 0;
    char seguir = 's';
    int idSeleccion=0;
    int idRenault = 1000;
    int idFiat = 1001;
    int idFord = 1002;
    int idChebrolet = 1003;
    int idPeugeot = 1004;

    mostrarMarcas(marcas, tamM);

    while(seguir == 's')
    {
        printf("ingrese id de marca que desea buscar\n\n");
        scanf("%d", &idSeleccion);

        switch(idSeleccion)
        {
        case 5000:
            system("cls");
            printf("Autos marca Renault \n\n");

            for(int i=0; i<tamA; i++)
            {
                if( autos[i].isEmpty == 0 && autos[1].idMarca == idRenault)
                {
                    mostrarAuto(autos[i], marcas, colores, tamM, tamC);
                    flag = 1;
                }
            }
            if( flag == 0)
            {
                printf("no hay autos de marca Renault\n\n");
            }
            break;

        case 5001:
            system("cls");
            printf("Autos de marca Fiat \n\n");

            for(int i=0; i<tamA; i++)
            {
                if( autos[i].isEmpty == 0 && autos[1].idMarca == idFiat)
                {
                    mostrarAuto(autos[i], marcas, colores, tamM, tamC);
                    flag = 1;
                }
            }
            if( flag == 0)
            {
                printf("no hay autos de marca Fiat\n\n");
            }
            break;

        case 5002:
            system("cls");
            printf("Autos de marca Ford \n\n");

            for(int i=0; i<tamA; i++)
            {
                if( autos[i].isEmpty == 0 && autos[1].idMarca == idFord)
                {
                    mostrarAuto(autos[i], marcas, colores, tamM, tamC);
                    flag = 1;
                }
            }
            if( flag == 0)
            {
                printf("no hay autos de marca Ford\n\n");
            }
            break;

        case 5003:
            system("cls");
            printf("Autos de marca Chevrolet \n\n");

            for(int i=0; i<tamA; i++)
            {
                if( autos[i].isEmpty == 0 && autos[1].idMarca == idChebrolet)
                {
                    mostrarAuto(autos[i], marcas, colores, tamM, tamC);
                    flag = 1;
                }
            }
            if( flag == 0)
            {
                printf("no hay autos de marca Chevrolet\n\n");
            }
            break;

        case 5004:
            system("cls");
            printf("Autos de marca Peugeot\n\n");

            for(int i=0; i<tamA; i++)
            {
                if( autos[i].isEmpty == 0 && autos[1].idMarca == idPeugeot)
                {
                    mostrarAuto(autos[i], marcas, colores, tamM, tamC);
                    flag = 1;
                }
            }
            if( flag == 0)
            {
                printf("no hay autos de marca Peugeot\n\n");
            }
            break;

        default:
            printf("id invalido\n\n");
            break;
        }

        printf("desea continuar?\n\n");
        scanf("%c", &seguir);
    }


    return error;
}

/*int listaDeAutosXMarca(eAuto autos[], int tam, eMarca marcas[], int tamM)
{
    int error = 1;
    int idMarca;
    char descMarca[20];
    int flag=0;
    if( autos != NULL && marcas != NULL && tam >0 && tamM > 0)
    {
        system("cls");
        printf("  *** Listado Autos por marca ***\n");
        mostrarMarcas(marcas,  tamM);
        printf("Ingrese id marcas: ");
        scanf("%d", &idDeporte);

        while( validarIdDeporte(sports, tamM, idDeporte)==0)
        {
            printf("id invalido. reingrese id deporte: ");
            scanf("%d", &idDeporte);
        }

        obtenerDescripcionDeporte(sports, tamD, idDeporte, deporte);
        printf("Personas que practican %s:\n", deporte);

        for(int i=0; i < tam; i++)
        {
            if(gente[i].isEmpty == 1 && gente[i].idDeporte == idDeporte)
            {
                mostrarPersona(gente[i], sports, tamD);
                flag = 1;
            }
        }

        if(flag == 0)
        {
            printf("No hay personas que practiquen %s\n\n", deporte);
        }
        printf("\n\n");

        error = 0;
    }

    return error;
}
*/
