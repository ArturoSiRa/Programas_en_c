
#include <stdio.h>
#include <string.h>
struct Moto{
    char cc[20];
};
struct Camion{
    struct {
    char cantascientos [20];
    char cantpue [20]; 
    }datosdelcamion;
};

struct Vehiculo{
    char vim [20];
    char hp [20];
    char tanque [20];
    char cantllantas[20];
    char color[20];
    struct Moto moto;
    struct Camion camion;

};
union Tipovehiculo{
    char Motocicleta[20];
    char Camion [20];
};

int main (){
    struct Vehiculo motos;
    strcpy(motos.moto.cc, "444cc");
    printf("CC de la moto: %s\n", motos.moto.cc);

    struct Vehiculo camiones;
    strcpy(camiones.camion.datosdelcamion.cantascientos,"6");
    strcpy(camiones.camion.datosdelcamion.cantpue, "2");
    
    printf("La cantidad de puertas del camion son:%s\n", camiones.camion.datosdelcamion.cantascientos);
    printf("La cantidad de puertas es de:%s\n ", camiones.camion.datosdelcamion.cantpue);

    return 0;
}

//definir estructuras y uniones
//structVehiculo
//union tipo
//char motocicleta 

//estructura motocicleta
//estructura camion