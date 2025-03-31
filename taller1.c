// agregar un descuento
// arreglar 3 errores de validacion
#include <stdio.h>
int main()
{
    int id, stock, cantidad, opcion;
    float precio, total_ganancias = 0, ventas = 0, porcentaje_descuento = 0;
    char nombre[30], id_letra;
    int validar, producto_ingresado = 0;

    do
    {
        printf("\nMenu de Opciones:\n");
        printf("1. ingresar datos del producto:\n");
        printf("2. Vender producto\n");
        printf("3. Reabastecer producto\n");
        printf("4. Mostrar informacion del producto\n");
        printf("5. Mostrar total de ganancias\n");
        printf("6. Salir\n");
        printf("Seleccione una opcion: ");
        scanf("%d", &opcion);
        switch (opcion)
        {
        case 1:
            do
            {
                printf("Ingrese el ID del producto (formato: letra seguido de numero positivo): ");
                char input[50];
                validar = scanf("%s", input);
                if (validar == 1 && sscanf(input, "%c%d", &id_letra, &id) == 2 && id > 0 && ((id_letra >= 'A' && id_letra <= 'Z') || (id_letra >= 'a' && id_letra <= 'z')))
                {
                    break;
                }
                else
                {
                    printf("Valor incorrecto, asegurese de ingresar una letra seguida de un numero positivo.\n");
                }
                while (getchar() != '\n')
                    ;
            } while (1);
            while (getchar() != '\n')
                ;
            do
            {
                printf("Ingrese el nombre del producto: ");
                validar = scanf("%s", nombre);
                if (validar != 1)
                {
                    printf("Valor incorrecto, vuelva a intentarlo.\n");
                    while (getchar() != '\n')
                        ;
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
                    while (getchar() != '\n')
                        ;
                    stock = -1;
                }
            } while (validar != 1 || stock < 1);
            do
            {
                printf("Ingrese el precio unitario: ");
                validar = scanf("%f", &precio);
                if (validar != 1 || precio <= 0)
                {
                    printf("Valor incorrecto, el precio debe ser un numero positivo mayor que 0 (ejemplo: 0.1), vuelva a intentarlo.\n");
                    while (getchar() != '\n')
                        ;
                    precio = -1;
                }

            } while (validar != 1 || precio < 0);
            producto_ingresado = 1;
            printf("Producto ingresado con exito.\n");
            break;
            case 2:
            if (producto_ingresado == 0)
            {
                printf("No se ha ingresado ningun producto.\n");
                break;
            }
        
            do {
                printf("Ingrese la cantidad a vender: ");
                validar = scanf("%d", &cantidad);
        
                if (validar != 1 || cantidad < 1) {
                    printf("Error: La cantidad debe ser un numero positivo.\n");
                    while (getchar() != '\n');
                } 
                else if (cantidad > stock) {
                    printf("Error: No hay suficiente stock disponible. Stock actual: %d\n", stock);
                }
            } while (cantidad > stock || validar != 1 || cantidad <= 0);
            do {
                printf("Ingrese el porcentaje de descuento (0-100%): ");
                validar = scanf("%f", &porcentaje_descuento);
        
                if (validar != 1 || porcentaje_descuento < 0 || porcentaje_descuento > 100) {
                    printf("Error: El porcentaje debe estar entre 0 y 100.\n");
                    while (getchar() != '\n');
                }
            } while (validar != 1 || porcentaje_descuento < 0 || porcentaje_descuento > 100);
        
            stock -= cantidad;
            float subtotal = cantidad * precio;
            float descuento = subtotal * (porcentaje_descuento / 100);
            float total_venta = subtotal - descuento;
            total_ganancias += total_venta;
        
            printf("\nVenta realizada con éxito.\n");
            printf("Subtotal: $%.2f\n", subtotal);
            printf("Descuento aplicado: $%.2f\n", descuento);
            printf("Total a pagar: $%.2f\n", total_venta);
            break;        
        case 3:
            if (producto_ingresado == 0)
            {
                printf("No se ha ingresado ningun producto.\n");
                break;
            }
            printf("Ingrese la cantidad a agregar al stock: ");
            scanf("%d", &cantidad);
            if (cantidad < 1)
            {
                printf("Dato invalido, no puede ser 0 vuelva a intentarlo.\n");
            }
            else
            {
                stock += cantidad;
                printf("El stock se ha reabastecido con exito.\n");
            }
            break;

        case 4:
            printf("\nInformacion del producto:\n");
            printf("ID: %d\n", id, id_letra);
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
