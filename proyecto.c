#include "proyecto.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void) {
    int op;
    int num_med = 0;
    int num_eliminados = 0;
    struct medicina medicinaT[20];
    struct medicina eliminados[20];
    

  do{
    printf("\n--------SISTEMA DE INVENTARIO--------\n");
    printf("1. Agregar medicamiento\n");
    printf("2. Editar inventario\n");
    printf("3. Eliminar medicamentos\n");
    printf("4. Medicamentos existentes\n");
    printf("5. Inventario despachado\n");
    printf("6. Salir\n");
    printf("\t\nSeleccione: ");
    scanf("%d",&op);
    system("clear");

    switch(op){
      case 1:
       crear(medicinaT, num_med);
                num_med++;
      break;

      case 2:
       editar(medicinaT, num_med);
      break;

      case 3:
        eliminar(medicinaT, num_med, eliminados, num_eliminados);
        num_med--;
        num_eliminados++;
      break;

      case 4:
        verInventario(medicinaT, num_med);
      break;
      case 5:
        verEliminados(eliminados, num_eliminados);
      break;

      case 6:
        printf("\nGracias por usar el programa");
      break;
      default:
          printf("Opcion no valida\n");
        break;
    }
  }while(op!=6);
 guardarMedicinas(medicinaT, num_med);
  return 0;
}