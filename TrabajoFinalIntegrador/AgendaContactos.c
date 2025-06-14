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
void cambiarContacto (struct Contacto* cabeza, char nombre[]){
    while (cabeza!=NULL)
    {
        if (strcmp(cabeza->nombre, nombre) == 0){
            printf("Nuevo nombre\n");
            scanf("%s",cabeza->nombre);
            printf("Nuevo telefono\n");
            scanf("%s",cabeza->telefono);
            printf("Nuevo Email\n");
            scanf("%s",cabeza->email);
            printf("Contacto modificado\n");
            return;
        }
        cabeza=cabeza->siguiente; 
    }
    printf("Contacto no encontrado\n");
}
void eliminarTodosContactos(struct Contacto* cabeza){
    struct Contacto* temp;
    while (cabeza!=NULL)
    {
        temp=cabeza;
        cabeza = cabeza->siguiente;
        free(temp);
    }
}
void guardarAgenda(struct Contacto* cabeza){
    FILE *archivo =  fopen("Agenda.txt","a");
    while(cabeza != NULL){
        fprintf(archivo,"%s %s %s",cabeza->nombre,cabeza->telefono,cabeza->email);
        cabeza=cabeza->siguiente;
    }
    fclose(archivo);
}
void cargarAgenda(struct Contacto* cabeza){
    FILE *archivo = fopen("Agenda.txt","r");
    if(archivo == NULL){
        return;
    }
    char ch;
    while ((ch = fgetc(archivo)) != EOF) {
        putchar(ch);
    }
}


int main() {

    return 0;
}
