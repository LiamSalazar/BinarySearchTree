#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define ENTRADA "archivo.txt"
#define SALIDA  "salida.txt"

int main() {
    FILE *fentrada, *fsalida;

    // -----------------------------------------------
    // 1. Crear y escribir en el archivo de entrada
    // -----------------------------------------------
    fentrada = fopen(ENTRADA, "w");  // modo escritura
    if (!fentrada) {
        perror("No se pudo crear el archivo de entrada");
        return 1;
    }

    // Escribimos texto de prueba
    fprintf(fentrada, "Hola mundo\nEste es un archivo\nde prueba.");
    fclose(fentrada);  // Siempre cerramos al terminar

    // -----------------------------------------------
    // 2. Leer el archivo carácter por carácter
    // -----------------------------------------------
    fentrada = fopen(ENTRADA, "r");
    if (!fentrada) {
        perror("No se pudo abrir el archivo de entrada");
        return 1;
    }

    printf("Lectura carácter por carácter:\n");
    char c;
    while ((c = fgetc(fentrada)) != EOF) {
        printf("%c", c);
    }
    rewind(fentrada);  // Volvemos al inicio del archivo

    // -----------------------------------------------
    // 3. Leer palabra por palabra
    // -----------------------------------------------
    printf("\n\nLectura palabra por palabra:\n");
    char palabra[100];
    while (fscanf(fentrada, "%s", palabra) != EOF) {
        printf("Palabra: %s\n", palabra);
    }
    rewind(fentrada);

    // -----------------------------------------------
    // 4. Leer línea por línea
    // -----------------------------------------------
    printf("\nLectura línea por línea:\n");
    char linea[200];
    while (fgets(linea, sizeof(linea), fentrada)) {
        printf("Línea: %s", linea);  // fgets incluye el salto de línea
    }

    fclose(fentrada);

    // -----------------------------------------------
    // 5. Escribir salida en otro archivo
    // -----------------------------------------------
    fsalida = fopen(SALIDA, "w");
    if (!fsalida) {
        perror("No se pudo crear el archivo de salida");
        return 1;
    }

    fprintf(fsalida, "Este es el resultado de leer el archivo:\n");
    fprintf(fsalida, "- Total de caracteres: se puede contar en un paso adicional\n");
    fprintf(fsalida, "- Total de palabras: se puede contar igual\n");

    fclose(fsalida);

    printf("\nRevisa '%s' para la salida escrita.\n", SALIDA);
    return 0;
}
