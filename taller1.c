//agregar un descuento
#include <stdio.h>
int main() {
    int id, stock, cantidad, opcion;
    float precio, total_ganancias = 0, ventas=0, porcentaje_descuento=0;
    char nombre[30];
    int validar;
   
    do {
        printf("\nMenu de Opciones:\n");
        printf("1. ingresar datos del producto:\n");
        printf("2. Vender producto\n");
        printf("3. Reabastecer producto\n");
        printf("4. Mostrar informacion del producto\n");
        printf("5. Mostrar total de ganancias\n");
        printf("6. Salir\n");
        printf("Seleccione una opcion: ");
        scanf("%d", &opcion);
        switch(opcion) {
            case 1:
                do
                {
                    printf("Ingrese el ID del producto: ");
                    validar = scanf("%d", &id);
                    if (validar != 1 || id < 0)
                    {
                        printf("Valor incorrecto, el valor no puede ser negativo.\n");
                        while (getchar() != '\n');
                        id = -1;
                    }
                } while (validar != 1 || id < 0);
                do
                {
                    printf("Ingrese el nombre del producto: ");
                    validar=scanf("%s", nombre);
                    if (validar != 1)
                    {
                        printf("Valor incorrecto, vuelva a intentarlo.\n");
                        while (getchar() != '\n');
                        nombre[0] = '\0';
                    }
                } while (validar != 1);
                do
                {
                    printf("Ingrese el stock disponible: ");
                    validar = scanf("%d", &stock);
                    if (validar != 1 || stock < 1)
                    {
                        printf("Valor incorrecto, el valor no puede ser ni 0 ni valor negativo, vuelva a intenarlo.\n");
                        while (getchar() != '\n');
                        stock = -1;
                    }
                } while (validar != 1 || stock < 1);
                do
                {
                    printf("Ingrese el precio unitario: ");
                    validar = scanf("%f", &precio);
                    if (validar != 1 || precio < 1)
                    {
                        printf("Valor incorrecto, el valor no puede ser ni 0 ni valor negativo, vuelva a intenarlo.\n");
                        while (getchar() != '\n');
                        precio = -1;
                    }

                } while (validar != 1 || precio < 0);
                break;
                case 2:
                    printf("Ingrese la cantidad a vender: ");
                    scanf("%d", &cantidad);
                    if (cantidad > stock)
                    {
                        printf("No hay suficiente stock para realizar la venta.\n");
                    }
                    else
                    {
                        printf("Ingrese el porcentaje de descuento (0-100%): ");
                        scanf("%f", &porcentaje_descuento);
                        if (porcentaje_descuento < 0 || porcentaje_descuento > 100)
                        {
                            printf("El porcentaje de descuento debe estar entre 0 y 100%.\n");
                        }
                        else
                        {
                            stock -= cantidad;
                            ventas = cantidad * precio;
                            float descuento = ventas * (porcentaje_descuento / 100);
                            total_ganancias += ventas - descuento;
                            printf("Venta realizada con exito.\n");
                        }
                    }
                    break;
                case 3:
                    printf("Ingrese la cantidad a agregar al stock: ");
                    scanf("%d", &cantidad);
                    if (cantidad < 0)
                    {
                        printf("Dato invalido, vuelva a intentarlo.\n");
                    }
                    else
                    {
                        stock += cantidad;
                        printf("El stock se ha reabastecido con exito.\n");
                    }
                    break;

                case 4:
                    printf("\nInformacion del producto:\n");
                    printf("ID: %d\n", id);
                    printf("Nombre: %s\n", nombre);
                    printf("Stock disponible: %d\n", stock);
                    printf("Precio unitario: %.2f\n", precio);
                    break;

                case 5:
                    printf("Total de ganancias: $%.2f\n", total_ganancias);
                    break;

                case 6:
                    printf("Saliendo del programa...\n");
                    break;

                default:
                    printf("Opcion invalida. Intente nuevamente.\n");
                }
    } while (opcion != 6);
    return 0;
}