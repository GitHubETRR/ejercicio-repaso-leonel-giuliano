/* Definir una estructura llamada Empleado con los siguientes campos:
 nombre
 edad
 salario */
/* Declarar un vector de tipo Empleado para almacenar la información de hasta 5 emplea-
dos. */
/* ingresarDatos: Permite al usuario ingresar los datos de un empleado.
 procesarDatos: Procesa los datos ingresados para calcular el promedio de salarios y
muestra el nombre del empleado con el salario más alto.
 mostrarDatos: Muestra la información de todos los empleados ingresados.
Los parámetros de recibir y devolver de cada función quedan a su criterio, pero no se
deben utilizar variables globales.
 */
/* Crear un menú interactivo que permita al usuario realizar las siguientes operaciones:
 Ingresar datos de un empleado.
 Procesar y mostrar información relevante de los empleados.
 Salir del programa */

#include <stdio.h>

#define NAME_CANT 99
#define EMP_CANT 5

typedef struct {
    char name[NAME_CANT];
    int age;
    float salary;
}empleado_t;

void ingresarDatos(empleado_t [], int);
void mostrarDatos(empleado_t [], int);
void procesarDatos(empleado_t [], int);

int main(void) {
    empleado_t empleados[EMP_CANT];
    int option, finished = 0, empCantidad = 0;

    printf("--- Menu ---\n");
    printf("1. Ingresar datos de su empleado\n");
    printf("2. Procesar y mostrar informacion relevante\n");
    printf("3. Salir");

    while (!finished) {
        printf("\n\nIngrese su opcion: ");
        scanf(" %d", &option);

        switch (option) {
        case 1:
            if (empCantidad == EMP_CANT) {
                printf("No se pueden ingresar mas de %c empleados", EMP_CANT);

                return 0;
            }

            ingresarDatos(empleados, empCantidad);
            empCantidad++;
            break;
        
        case 2:
            mostrarDatos(empleados, empCantidad);
            break;

        case 3:
            printf("Hasta luego!");
            finished = 1;
            break;

        default:
            printf("Debe insertar una opcion entre 1 a 3");
            break;
        }
    }

    return 0;
}

void ingresarDatos(empleado_t empleados[], int empCantidad) {
    if (empCantidad == EMP_CANT) {
        printf("No es posible insertar mas de %i empleados", EMP_CANT);

        return;
    }

    printf("Inserte el nombre del empleado: ");
    scanf(" %[^\n]%*c", empleados[empCantidad].name);

    printf("Inserte la edad del empleado: ");
    scanf(" %d", &empleados[empCantidad].age);

    printf("Inserte el salario del empleado (en dolares): $");
    scanf(" %f", &empleados[empCantidad].salary);

    printf("\nDatos ingresados correctamente.");
}

void mostrarDatos(empleado_t empleados[], int empCantidad) {
    if (!empCantidad) {
        printf("Todavia no se ha ingresado ningun empleado");
        
        return;
    }

    printf("--- Informacion de Empleados ---\n");

    for (int i = 0; i < empCantidad; i++) {
        printf(
            "%d. Nombre: %s, Edad: %d, Salario: %.2f\n",
            i + 1,
            empleados[i].name,
            empleados[i].age,
            empleados[i].salary
        );
    }

    procesarDatos(empleados, empCantidad);
}

void procesarDatos(empleado_t empleados[], int empCantidad) {
    float salaryProm = 0;
    int iEmpMax = 0;

    for (int i = 0; i < empCantidad; i++) {
        salaryProm += empleados[i].salary;

        if (empleados[iEmpMax].salary < empleados[i].salary) {
            iEmpMax = i;
        }
    }

    salaryProm /= empCantidad;

    printf("\nPromedio de salarios: $%.2f\n", salaryProm);
    printf("Empleado con el salario mas alto: %s", empleados[iEmpMax].name);
}