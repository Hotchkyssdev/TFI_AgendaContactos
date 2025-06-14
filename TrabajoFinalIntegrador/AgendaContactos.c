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
    while (cabeza != NULL) {
        if (strcmp(cabeza->nombre, nombre) == 0){
            printf("Nuevo nombre: ");
            scanf("%s",cabeza->nombre);
            printf("\n");
            printf("Nuevo telefono: ");
            scanf("%s",cabeza->telefono);
            printf("\n");
            printf("Nuevo Email: ");
            scanf("%s",cabeza->email);
            printf("\n");
            printf("Contacto modificado\n");
            return;
        }
        cabeza = cabeza->siguiente; 
    }
    printf("Contacto no encontrado\n");
}

void liberarAgenda(struct Contacto* cabeza){
    struct Contacto* temp;
    while (cabeza != NULL) {
        temp = cabeza;
        cabeza = cabeza->siguiente;
        free(temp);
    }
}

void guardarAgenda(struct Contacto* cabeza){
    FILE *archivo =  fopen("agenda.txt", "w");
    while(cabeza != NULL){
        fprintf(archivo,"%s | %s | %s\n", cabeza->nombre, cabeza->telefono, cabeza->email);
        cabeza = cabeza->siguiente;
    }
    fclose(archivo);
}

void cargarAgenda(struct Contacto** cabeza){
    FILE *archivo = fopen("agenda.txt", "r");
    char linea[150], nombre[50], telefono[15], email[50];
    char* token = strtok(linea, "|");

    if (archivo == NULL){
        return;
    }

    while (fgets(linea, sizeof(linea), archivo)) {
        linea[strcspn(linea, "\n")] = 0;
        strcpy(nombre, token);
        token = strtok(NULL, "|");
        strcpy(telefono, token);
        token = strtok(NULL, "|");
        strcpy(email, token);
        token = strtok(NULL, "|");
        insertarOrdenado(cabeza, nombre, telefono, email);
    }
    fclose(archivo);
}

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