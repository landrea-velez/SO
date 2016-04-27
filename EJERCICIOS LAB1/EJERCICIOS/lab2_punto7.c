#include <stdio.h>

float promedio(float valores[], int cantidad) {
    int i;
    float suma = 0.0;

    for (i = 0; i < cantidad; ++i)
        suma += valores[i];

    return suma / (float) cantidad;
}


int main() {
    char nombre[20];
    char cursos[20];
    char *bar = cursos;
    float notas[10];
    int creditos[10];
    char opcion[3];
    int n, i;

    do {
        printf("Ingrese nombre del alumno: ");
        scanf("%s", nombre);

        printf("Cuantos cursos tiene %s? ", nombre);
        scanf("%d", &n);

        for (i = 0; i < n; ++i) {
	    printf("Curso %d: ", i + 1);
            scanf("%s", &cursos[i]);

            printf("Nota %d: ", i + 1);
            scanf("%f", &notas[i]);

            printf("Creditos %d: ", i + 1);
            scanf("%d", &creditos[i]);
        }

        printf("El promedio de %s es %.2f\n", nombre, promedio(notas, n));

        printf("Desea calcular mas promedios (si/no)? ");
        scanf("%s", opcion);

    } while (opcion[0] == 's' || opcion[0] == 'S');

    /* Imprimir resultados en consola. */
    printf("|%25s|%25s|%25s|\n", "Curso", "Materia","Creditos");
    
    for (i = 0; i < n; i++) {
        printf("|%-25s|%-25.2f|%-25d|\n", bar+i,notas[i],creditos[i]);
    }

    return 0;
}
