#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "contacto.h"

int main() {
    struct Contacto* agenda = NULL;
    int opcion;
    char nombre[50], telefono[15], email[50];

    cargarAgenda(&agenda);

    do {
        printf("Menu de Agenda de Contactos:\n");
        printf("1. Insertar contacto\n");
        printf("2. Mostrar contactos\n");
        printf("3. Buscar contacto\n");
        printf("4. Eliminar contacto\n");
        printf("5. Modificar contacto\n");
        printf("6. Guardar agenda\n");
        printf("7. Salir\n");
        printf("Seleccione una opcion: ");
        scanf("%d", &opcion);

        switch (opcion) {
            case 1:
                printf("\nIngrese nombre: ");
                scanf("%s", nombre);
                printf("Ingrese telefono: ");
                scanf("%s", telefono);
                printf("Ingrese email: ");
                scanf("%s", email);
                insertarOrdenado(&agenda, nombre, telefono, email);
                printf("Contacto insertado.\n");
                break;
            case 2:
                printf("\nContactos en la agenda:\n");
                mostrarContactos(agenda);
                break;
            case 3:
                printf("\nIngrese nombre a buscar: ");
                scanf("%s", nombre);
                buscarContacto(agenda, nombre);
                break;
            case 4:
                printf("\nIngrese nombre a eliminar: ");
                scanf("%s", nombre);
                eliminarContacto(&agenda, nombre);
                break;
            case 5:
                printf("\nIngrese nombre a modificar: ");
                scanf("%s", nombre);
                cambiarContacto(agenda, nombre);
                break;
            case 6:
                guardarAgenda(agenda);
                printf("\nAgenda guardada.\n");
                break;
            case 7:
                printf("\nSaliendo del programa.\n");
                break;
            default:
                printf("\nOpcion no valida. Intente de nuevo.\n");
                break;
        }
    } while (opcion != 7);;

    liberarAgenda(agenda);
    return 0;
}