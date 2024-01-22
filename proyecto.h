#include <stdio.h>
#include <stdlib.h>
#include <string.h>

FILE *eliminadosFile;
FILE *archivo;

struct medicina {
    int id;
    char nombre[20];
    float precio;
    int cantidad;
    int lote;
} medicinaT[20];

int medicamentoNumero = 1; 

float totalGlobal = 0.0;  





void guardarMedicinas(struct medicina medicinaT[20], int num_med){
    FILE *archivo;
    archivo = fopen("inventario.txt", "w");

    for(int i = 0; i < num_med-1; i++){
        float total = medicinaT[i].precio * medicinaT[i].cantidad;
        totalGlobal += total;  
        fprintf(archivo, "%d;%s;%d;%d;$%.2f;$%.2f\n", medicinaT[i].id, medicinaT[i].nombre, medicinaT[i].lote, medicinaT[i].cantidad, medicinaT[i].precio, total);
    }
    float totalFinal = medicinaT[num_med-1].precio * medicinaT[num_med-1].cantidad;
    totalGlobal += totalFinal;
    fprintf(archivo, "%d;%s;%d;%d;$%.2f;$%.2f", medicinaT[num_med-1].id, medicinaT[num_med-1].nombre, medicinaT[num_med-1].lote, medicinaT[num_med-1].cantidad, medicinaT[num_med-1].precio, totalFinal);
    fclose(archivo);
}




    
int crear(struct medicina medicinaT[20], int num_medicina) {
    int creado = 0;
    int ultimo_id;
    struct medicina med;
    
    fflush(stdin);

    for(int i = 0; i < num_medicina; i++){
                    ultimo_id = medicinaT[i].id;
                }
    med.id = ultimo_id+1;
    
    printf("NOMBRE: ");
    gets(med.nombre);
    printf("LOTE: ");
    scanf("%d", &med.lote);
    printf("STOCK: ");
    scanf("%d", &med.cantidad);
    printf("PRECIO: ");
    scanf("%f", &med.precio);

    if(num_medicina < 20){
        medicinaT[num_medicina] = med;
            creado = 1;
    }else{
        printf("No se puede crear una nueva medicina.\n");
    }
    return creado;
}

int eliminar(struct medicina medicinaT[20], int num_med, struct medicina eliminados[20], int num_eliminados) {
    int eliminado = 0;
    int id, indice;
    int ultimo_eliminado = num_eliminados;

    printf("Introduzca el codigo de la medicina que quiere eliminar: ");
    scanf("%d", &id);

        for(int i = 0; i < num_med; i++){
            if(medicinaT[i].id == id){
                indice = i;
            }
        }

        FILE *eliminadosFile;
        eliminadosFile = fopen("eliminados.txt", "a");

        fprintf(eliminadosFile, "%d;%s;%d;$d;%.2d\n", medicinaT[indice].id, medicinaT[indice].nombre, medicinaT[indice].lote, medicinaT[indice].cantidad, medicinaT[indice].precio);
        fclose(eliminadosFile);

        eliminados[ultimo_eliminado] = medicinaT[indice];

        for(int j = indice; j < num_med; j++){
            medicinaT[j] = medicinaT[j+1];
            struct medicina aux;
            medicinaT[j+1] = aux;
        }

        eliminado = 1;
    return eliminado;
}


void verInventario(struct medicina medicinaT[20], int num_med) {
    printf("Listando los datos del inventario \n");
    for(int i = 0; i < num_med; i++){
        printf("COD: %d\n", medicinaT[i].id);
        printf("NOMBRE: %s\n", medicinaT[i].nombre);
        printf("CANTIDAD: %d\n", medicinaT[i].cantidad);
        printf("LOTE: %d\n", medicinaT[i].lote);
        printf("PRECIO: $%.2f\n", medicinaT[i].precio);
        printf("\n");
    }
}

void verEliminados(struct medicina eliminados[20], int num_eliminados) {
    printf("Listando los inventarios despachados: \n");

    for(int i = 0; i < num_eliminados; i++){
        printf("COD: %d\n", eliminados[i].id);
        printf("NOMBRE: %s\n", eliminados[i].nombre);
        printf("CANTIDAD: %df\n", eliminados[i].cantidad);
        printf("LOTE: %d\n", eliminados[i].lote);
        printf("PRECIO: $%.2f\n", eliminados[i].precio);
        printf("\n");
    }
}


void editar(struct medicina medicinaT[20], int num_med) {
    int id, indice;
    struct medicina med;

    printf("Ingrese el codigo de la medicina que desea editar: \n");
    scanf("%d", &id);

for(int i = 0; i < num_med; i++){
            if(medicinaT[i].id == id){
                indice = i;
            }
        }

        printf("Ingrese los nuevos datos: \n");
        printf("NOMBRE: ");
    gets(med.nombre);
    printf("LOTE: ");
    scanf("%d", &med.lote);
    printf("STOCK: ");
    scanf("%d", &med.cantidad);
    printf("PRECIO: ");
    scanf("%f", &med.precio);

    medicinaT[indice] = med;
}