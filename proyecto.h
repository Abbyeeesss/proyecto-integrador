#include <stdio.h>
#include <stdlib.h>
#include <string.h>

FILE *eliminadosFile;
FILE *archivo;

struct medicina {
    int cod;
    char nombre[20];
    float precio;
    int cantidad;
    int lote;
    float totalPrecio;
} medicinaT[20];

int medicamentoNumero = 1; 
int i;



void guardarMedicinas(struct medicina medicinaT[20], int num_med){
    FILE *archivo;
    archivo = fopen("inventario.txt", "w");
    float totalGlobal = 0.0;  

    for(int i = 0; i < num_med-1; i++){
        float total = medicinaT[i].precio * medicinaT[i].cantidad;
        totalGlobal += total;  
        fprintf(archivo, "%d;%s;%d;%d;$%.2f;$%.2f\n", medicinaT[i].cod, medicinaT[i].nombre, medicinaT[i].lote, medicinaT[i].cantidad, medicinaT[i].precio, total);
    }
    float totalFinal = medicinaT[num_med-1].precio * medicinaT[num_med-1].cantidad;
    totalGlobal += totalFinal;
    fprintf(archivo, "%d;%s;%d;%d;$%.2f;$%.2f", medicinaT[num_med-1].cod, medicinaT[num_med-1].nombre, medicinaT[num_med-1].lote, medicinaT[num_med-1].cantidad, medicinaT[num_med-1].precio, totalFinal);
    fclose(archivo);
}




    
int crear(struct medicina medicinaT[20], int num_medicina) {
    int creado = 0;
    int ultimo_id;
    struct medicina med;
    
    fflush(stdin);

    for(int i = 0; i < num_medicina; i++){
                    ultimo_id = medicinaT[i].cod;
                }
    med.cod = ultimo_id+1;
    
    printf("\n\t**INGRESO DE PRODUCTOS**");
    printf("\n----------------------------------------");
    printf("\nIngrese los datos de la medicina:\n");
    printf("\nNOMBRE: ");
    fgets(med.nombre, sizeof(med.nombre), stdin);
    printf("LOTE: ");
    scanf("%d", &med.lote);
    printf("STOCK: ");
    scanf("%d", &med.cantidad);
    printf("PRECIO: $");
    scanf("%f", &med.precio);
    
    if(num_medicina < 20){
        medicinaT[num_medicina] = med;
            creado = 1;
    }else{
        printf("No se puede crear una nueva medicina.\n");
    }
    system("clear");
    return creado;
}





int eliminar(struct medicina medicinaT[20], int num_med, struct medicina eliminados[20], int num_eliminados) {
    int eliminado = 0;
    int cod, indice;
    int ultimo_eliminado = num_eliminados;

    printf("Introduzca el codigo de la medicina que quiere eliminar: ");
    scanf("%d", &cod);

        for(int i = 0; i < num_med; i++){
            if(medicinaT[i].cod == cod){
                indice = i;
            }
        }

        FILE *eliminadosFile;
        eliminadosFile = fopen("eliminados.txt", "a");

        fprintf(eliminadosFile, "%d;%s;%d;$d;%.2d\n", medicinaT[indice].cod, medicinaT[indice].nombre, medicinaT[indice].lote, medicinaT[indice].cantidad, medicinaT[indice].precio);
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
    
    printf("\n\t*PRODUCTOS EXISTENTES EN BODEGA*\n");
    printf("\n-------------------------------------------");
    for(int i = 0; i < num_med; i++){

        medicinaT[i].totalPrecio=medicinaT[i].cantidad*medicinaT[i].precio;

        printf("\nNOMBRE: %s", medicinaT[i].nombre);
        printf("\nCODIGO: %d\n", medicinaT[i].cod);
        printf("\nCANTIDAD: %d\n", medicinaT[i].cantidad);
        printf("\nLOTE: %d\n", medicinaT[i].lote);
        printf("\nPRECIO: $%.2f\n", medicinaT[i].precio);
        printf("\t\t\tTOTAL: %.2f",medicinaT[i].totalPrecio);
        printf("\n-------------------------------------------");

    }
    printf("\n\tDesea regresar al menu anterior?");
             printf("\n1.-SI: ");
             int y;
             scanf("%d",&y);
            if(y == 1) {
    system("clear");
            }
}





void verEliminados(struct medicina eliminados[20], int num_eliminados) {
    printf("\n\t*PRODUCTOS DESPACHADOS EN BODEGA*\n");
    printf("\n-------------------------------------------");
    for(int i = 0; i < num_eliminados; i++){
        printf("\nNOMBRE: %s", eliminados[i].nombre);
        printf("CODIGO: %d\n", eliminados[i].cod);
        printf("CANTIDAD: %df\n", eliminados[i].cantidad);
        printf("\nLOTE: %d\n", eliminados[i].lote);
        printf("\nPRECIO: $%.2f\n", eliminados[i].precio);
        printf("\n-------------------------------------------");
    }
}





void editar(struct medicina medicinaT[20], int num_med) {
    int cod, indice;
    struct medicina med;

    printf("Ingrese el codigo de la medicina que desea editar: \n");
    scanf("%d", &cod);

for(int i = 0; i < num_med; i++){
            if(medicinaT[i].cod == cod){
                indice = i;
            }
        }

    printf("\t**EDITAR MEDICINA**");
    printf("\n-------------------------------");
    printf("Ingrese los nuevos datos: \n");
    fflush(stdin);
    printf("NOMBRE: ");
    fgets(med.nombre, sizeof(med.nombre), stdin);
    printf("LOTE: ");
    scanf("%d", &med.lote);
    printf("STOCK: ");
    scanf("%d", &med.cantidad);
    printf("PRECIO: ");
    scanf("%f", &med.precio);

    medicinaT[indice] = med;
}