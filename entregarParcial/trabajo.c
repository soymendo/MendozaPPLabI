



#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <conio.h>
#include "funciones.h"
#include "mascota.h"
#include "dataTrabajo.h"
#include "trabajo.h"






void hardcodearTrabajos(eTrabajo vecTrabajo[],int cantTrabajo)
{
    for(int i=0; i<cantTrabajo; i++)
    {
        vecTrabajo[i].id=idTrabajos[i];
        vecTrabajo[i].idMascota=idMascotasTrabajos[i];
        vecTrabajo[i].idServicio=idServicioTrabajo[i];
        vecTrabajo[i].Fecha.dia=dias[i];
        vecTrabajo[i].Fecha.mes=meses[i];
        vecTrabajo[i].Fecha.anio=anios[i];
        vecTrabajo[i].estado=1;
    }
}




void setearTrabajo(eTrabajo vecTrabajo[],int cantTrabajo,int valor)
{
    for(int i=0;i<cantTrabajo;i++)
    {
        vecTrabajo[i].estado=valor;
    }

}





int encontrarLugarLibreTrabajo(eTrabajo vecTrabajo[],int cantTrabajo)
{
    int i;
    for(i=0; i<cantTrabajo; i++)
        if(vecTrabajo[i].estado==0)
        {
            return i;
            break;
        }

    return -1;
}




int encontrarTrabajoPorId(eTrabajo vecTrabajo[],int cantTrabajo,int id)
{
    int i;
    for(i=0; i<cantTrabajo; i++)
    {
        if(vecTrabajo[i].id==id&&vecTrabajo[i].estado==1)
        {
            return i;
        }
    }
    return -1;

}




void mostrarTrabajo(eTrabajo trab,eServicio VecServicio[],int cantServicio,eMascota vecMascota[],int cantMascota)
{

    int indice;
    int indice2;

    for(int i=0; i<cantMascota; i++)
    {
        if((trab.idMascota== vecMascota[i].id))
        {
            indice = i;
            break;
        }
    }

    for(int j=0; j<cantServicio; j++)
    {
        if((trab.idServicio== VecServicio[j].id ) )
        {
            indice2 = j;
            break;
        }
    }
    printf("%d     %10s     %10s       %.2f  %0d/%0d/%0d \n",trab.id,vecMascota[indice].nombre,VecServicio[indice2].descripcion,VecServicio[indice2].precio,trab.Fecha.dia,trab.Fecha.mes,trab.Fecha.anio );
}



void mostrarTrabajos(eTrabajo vecTrabajo[],int cantTrabajo,eServicio vecServicio[],int cantServicio,eMascota vecMascota[],int cantMascota)
{
    int cont=0;


    printf("****Listado de Trabajos*****\n\n");
    printf("  Id      Nombre Mascota   Servicio    Precio    Fecha\n");
    for(int i=0; i<cantTrabajo; i++)
    {
        if(vecTrabajo[i].estado ==1)// !=0
        {
            mostrarTrabajo(vecTrabajo[i],vecServicio,cantServicio,vecMascota,cantMascota);
            cont++;
        }

    }
    //printf("hay %d Trabajos",cont);

    if(cont==0)
    {
        system("cls");
        printf("\nNo hay Trabajos para mostrar!!");
    }


}



int altaTrabajo(int lastId,eTrabajo vecTrabajo[],int cantTrabajo,eMascota vecMascota[],int cantMascota,eServicio vecServicio[],int cantServicio,eTipo vecTipo[],int cantTipo,eColor vecColor[],int cantColor)
{

    int todoOk=0;

    eTrabajo nuevoTrabajo;
    int indiceLugarLibre;
    int id;

    indiceLugarLibre=encontrarLugarLibreTrabajo(vecTrabajo,cantTrabajo);
    if(indiceLugarLibre==-1)
    {
        printf("No quedan lugares libres\n");
    }
    else
    {
            nuevoTrabajo.id=lastId;
            mostrarMascotas(vecMascota,cantMascota,vecColor,cantColor,vecTipo,cantTipo);
            id=validarEntero("ingrese id de la mascota: ","id en numeros: ",100,1000);

         if(encontrarMascotaPorId(vecMascota,cantMascota,id)==-1)
        {
            printf("la Mascota no existe");
        }
        else
        {
            nuevoTrabajo.idMascota=id;

            mostrarServicios(vecServicio,cantServicio);
            nuevoTrabajo.idServicio=validarEntero("Ingrese servicio: ","servicio en numeros: ",20000,20004);
            nuevoTrabajo.Fecha.dia=validarEntero("ingrese dia: ","dia en numeros: ",1,31);
            nuevoTrabajo.Fecha.mes=validarEntero("ingrese mes: ","mes en numeros :",1,12);
            nuevoTrabajo.Fecha.anio=validarEntero("ingrese anio: ","anio en numeros: ",1900,2020);
            nuevoTrabajo.estado=1;
            vecTrabajo[indiceLugarLibre]=nuevoTrabajo;
            todoOk=1;
        }




    }


    return todoOk;
}



