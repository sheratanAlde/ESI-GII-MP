#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "ficheros.h"
#include "comun.h"
#define __USE_XOPEN

/*Cabecera: int buscar_viaje(char* id, Viajes* lista, int elementos)
Precondicion: id del viaje a buscar la posición en el array, array y numero de elementos
Poscondicion: Devuelve el número que ha introducido el usuario, si no lo encuentra devuelve -1*/

int buscar_viaje(char *id, Viajes *lista, int elementos) {
    int posicion = -1, exisVia = 0, i = 0;

    while (i < elementos && exisVia == 0) { //Buscamos el id del viaje si existe
        if (!strncmp(id, lista[i].Id_viaje, TAM_ID_VIA)) {
            exisVia = 1; //Si hay una concidencia guardamos y salimos
            posicion = i;
        }
        i++;
    }

    return posicion;
}

/*Cabecera: void publicar_viaje(Viajes* v, int* elementos, char* viaje)
Precondición: Recibe cadenas de carácteres de un viaje.
Postcondición: Permite al ususario publicar un nuevo viaje.*/

void *publicar_viaje(Viajes *v, int *elementos, char *viaje){
    char *Id_viaje, *Id_mat, *F_inic, *H_inic, *H_fin, *Plazas_libre, *Sentido, *Importe, *Estado;
    int i, n;
    
    if () {
        for (i = 0; i < n; i++) {
            /*Obtenemos espacio en memoria suficiente para la dimension maxima de cada cadena*/
            Id_viaje = (char *) malloc(TAM_ID_VIA + 1 * sizeof (char));
            Id_mat = (char *) malloc(TAM_ID_VEI + 1 * sizeof (char));
            F_inic = (char *) malloc(TAM_FIN_VIA + 1 * sizeof (char));
            H_inic = (char *) malloc(TAM_HIN_VIA + 1 * sizeof (char));
            H_fin = (char *) malloc(TAM_HFI_VIA + 1 * sizeof (char));
            Plazas_libre = (char *) malloc(TAM_PLA_VEI + 1 * sizeof (char));
            Sentido = (char *) malloc(TAM_SEN_VIA + 1 * sizeof (char));
            Importe = (char *) malloc(TAM_IMP_VIA + 1 * sizeof (char));
            Estado = (char *) malloc(TAM_EST_VIA + 1 * sizeof (char));

            /*Mostramos informacion que se le solicita al usuario y la recogemos*/
            Id_mat = leer_campo(TAM_ID_VEI, "Inserte la matricula del vehiculo: \n");
            F_inic = leer_campo(TAM_FIN_VIA, "Inserte la fecha en la que se producira el viaje: \n");
            H_inic = leer_campo(TAM_HIN_VIA, "Inserte la hora a la que se iniciara el viaje: \n");
            H_fin = leer_campo(TAM_HFI_VIA, "Inserte la hora a la que finalizará el viaje: \n");
            Sentido = leer_campo(TAM_SEN_VIA, "Inserte el sentido en el que ira el viaje (ida o vuelta): \n");
            Importe = leer_campo(TAM_IMP_VIA, "Inserte el importe del viaje: \n");
            Estado = leer_campo(TAM_EST_VIA, "Inserte el estado del viaje (abierto, cerrado, iniciado, finalizado o anulado): \n");

            /*Obtenemos memoria para un nuevo elemento*/
            v = (Viajes *) realloc(v, (*elementos + 1) * sizeof (Viajes));

            /*Guardamos la informacionrecogida y generada en el nuevo elemento*/
            sprintf(Id_viaje, "%06d", *elementos + 1);
            v[*elementos].Id_mat = Id_mat;
            v[*elementos].F_inic = F_inic;
            v[*elementos].H_inic = H_inic;
            v[*elementos].H_fin = H_fin;
            v[*elementos].Sentido = Sentido;
            v[*elementos].Importe = Importe;
            v[*elementos].Estado = Estado;
            (*elementos)++;
        }
    } else {
        printf("ERROR: No tiene ningún vehículo matriculado.");
    }
}

/*Cabecera: void eliminar_viaje(Viajess* lista, int* elemento)
 Precondicion: lista de viajes y numero de elementos 
 Poscondicion: modifica a borrado un viaje*/

void eliminar_viaje(Viajes *lista, int *elementos) {
    char *id;
    int pos;

    printf("\n\nBorrado de un viaje:\n\n");
    
    /*Solicitamos el id del viaje*/
    id = leer_campo(TAM_ID_VIA, "Introduce el id del viaje"); 
    
    pos = buscar_viaje(id, lista, *elementos);
    
    lista[pos].Eliminado = "Si";
    printf("El viaje ha sido eliminado con exito.");
}

/*Cabecera: void modificar_viaje(Viajes* viaje)
Precondición: recibe un puntero a viaje.
Postcondición: Permite al usuario modificar un viaje previamente creado por el mismo.*/

void modificar_viaje(Viajes *viaje){
    Viajes v;
    int o;
        
    do {
        printf("Indique la seccion que desea modificar:\n1.- El id del viaje.\n2.- La matricula del vehiculo.\n3.- La fecha del viaje.\n4.- La hora de inicio del viaje.\n5.- La hora de finalización del viaje.\n6.- El numero de plazas libres del viaje.\n7.- El sentido del viaje.\n8.- El importe del viaje.\n9.- El estado del viaje.\n0.- Salir");
        scanf("%d", &o);
    } while (o<0 || o>9);
    
    switch(o){
        case 1:
            v.Id_viaje = leer_campo(TAM_ID_VIA, "Id del viaje");
            scanf("%s", v.Id_viaje);
            break;
        case 2:
            v.Id_mat = leer_campo(TAM_ID_VEI, "Matricula del vehiculo");
            scanf("%s", v.Id_mat);
            break;
        case 3:
            v.F_inic = leer_campo(TAM_FIN_VIA, "Hora de inicio");
            scanf("%s", v.F_inic);
            break;
        case 4:
            v.H_inic = leer_campo(TAM_HIN_VIA, "Hora de finalizacion");
            scanf("%s", v.H_inic);
            break;
        case 5:
            v.H_fin = leer_campo(TAM_HFI_VIA, "Hora de finalizacion");
            scanf("%s", v.H_fin);
            break;
        case 6:
            v.Plazas_libre = leer_campo(TAM_PLA_VEI, "Plazas libres");
            scanf("%s", v.Plazas_libre);
            break;
        case 7:
            v.Sentido = leer_campo(TAM_SEN_VIA, "Sentido del viaje");
            scanf("%s", v.Sentido);
            break;
        case 8:
            v.Importe = leer_campo(TAM_IMP_VIA, "Importe del viaje");
            scanf("%s", v.Importe);
            break;
        case 9:
            v.Estado = leer_campo(TAM_EST_VIA, "Estado del viaje");
            scanf("%s", v.Estado);
            break;
    }
}

/*Cabecera: void listar_viaje(Viajes* viaje, int* elementos)
Precondición: Recibe un puntero a viaje y un puntero a entero.
Postcondición: Permite al usuario visualizar una lista de todos los viajes que se encuentran en el sistema.*/

void listar_viaje(Viajes* viaje, int *elementos){
    int i;
    Viajes v;
    
    printf("Id del viaje - Matricula del vehiculo - Fecha de inicio - Hora de inicio - Hora de finalizacion - Numero de plazas libres - Sentido del viaje - Importe - Estado del viaje");
    for(i=0; i<elementos; i++) {
        if(strcmp(v[i].Eliminado, (char *) "No"){
            printf("%d: %s - %s - %s - %s - %s - %s - %s - %s - %s", i+1, v[i].Id_viaje, v[i].Id_mat, v[i].F_inic, v[i].H_inic, v[i].H_fin, v[i].Plazas_libre, v[i].Sentido, v[i].Importe, v[i].Estado);
    
        }
    }
}

/*Cabecera: void autoFinalizarViajes(Viajes* lista, int elementos)
 Precondición: Recibe un puntero a viaje y un entero
 Postcondición: Finaliza un viaje una vez pasada una hora de su hora de finalización*/

void autoFinalizarViajes(Viajes *lista, int elementos){
    int indice;
    struct tm fecha, hora, *actual;
    time_t tiempo;
    
    tiempo = time(NULL);
    actual = localtime(&tiempo);
    
    for(indice = 0; indice < elementos; indice++){
        if(!strcmp(lista[indice].Estado,(char *)"Iniciado") || !strcmp(lista[indice].Estado,(char *)"Cerrado") || !strcmp(lista[indice].Estado,(char *)"Abierto")){
            strptime(lista[indice].F_inic, "%d/%m/%Y", &fecha);
            strptime(lista[indice].H_fin, "%H:%M", &hora);

            if(fecha.tm_year+1900 - actual->tm_year > 0 || fecha.tm_mday - actual->tm_mday > 0 || fecha.tm_mon+1 - actual->tm_mon+1 > 0 || hora.tm_hour+1 - actual->tm_hour >= 0){
               printf("\nViajes Finalizado %s\n",lista[indice].Id_viaje);
               lista[indice].Estado = "Finalizado";
            }
        }
    }
}
