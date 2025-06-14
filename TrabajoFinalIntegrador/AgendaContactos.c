#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Contacto {
    char nombre[50];
    char telefono[15];
    char email[50];
    struct Contacto* siguiente;
};

struct Contacto* crearContacto(char nombre[], char telefono[], char email[]) {
    struct Contacto* nuevoContacto = (struct Contacto*) malloc(sizeof(struct Contacto));
    strcpy(nuevoContacto->nombre, nombre);
    strcpy(nuevoContacto->telefono, telefono);
    strcpy(nuevoContacto->email, email);
    nuevoContacto->siguiente = NULL;
    return nuevoContacto;
}

void insertarOrdenado(struct Contacto** cabeza, char nombre[], char telefono[], char email[]) {
    struct Contacto* nuevoContacto = crearContacto(nombre, telefono, email);
    struct Contacto* actual = *cabeza;
    if (*cabeza == NULL || strcmp((*cabeza)->nombre, nuevoContacto->nombre) > 0) {
        nuevoContacto->siguiente = *cabeza;
        *cabeza = nuevoContacto;
        return;
    } 
    while (actual->siguiente != NULL && strcmp(actual->siguiente->nombre, nuevoContacto->nombre) < 0) {
        actual = actual->siguiente;
    }
    nuevoContacto->siguiente = actual->siguiente;
    actual->siguiente = nuevoContacto;
}

void mostrarContactos(struct Contacto* cabeza) {
    struct Contacto* actual = cabeza;
    while (actual != NULL) {
        printf("Nombre: %s\n", actual->nombre);
        printf("Telefono: %s\n", actual->telefono);
        printf("Email: %s\n", actual->email);
        printf("-------------------------\n");
        actual = actual->siguiente;
    }
}

void buscarContacto(struct Contacto* cabeza, char nombre[]) {
    struct Contacto* actual = cabeza;
    while (actual != NULL) {
        if (strcmp(actual->nombre, nombre) == 0) {
            printf("Contacto encontrado:\n");
            printf("Nombre: %s\n", actual->nombre);
            printf("Telefono: %s\n", actual->telefono);
            printf("Email: %s\n", actual->email);
        }
        actual = actual->siguiente;
    }
}

void eliminarContacto(struct Contacto** cabeza, char nombre[]) {
    struct Contacto* actual = *cabeza;
    struct Contacto* anterior = NULL;
    while (actual != NULL && strcmp(actual->nombre, nombre) != 0) {
        anterior = actual;
        actual = actual->siguiente;
    }
    if (actual == NULL) {
        printf("Contacto no encontrado.\n");
        return;
    }
    if (anterior == NULL) {
        *cabeza = actual->siguiente;
    } else {
        anterior->siguiente = actual->siguiente;
    }
    free(actual);
    printf("Contacto eliminado.\n");
}

int main() {

    return 0;
}