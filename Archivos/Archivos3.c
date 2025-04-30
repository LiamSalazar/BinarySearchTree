# include <stdio.h>
int main(){
    FILE *ent = fopen("Prueba.c","r");
    FILE *sal = fopen("Salida.c","w");
    char c, pal[20];
    int nc = 0;
    printf("\nPalabras en el archivo\n");
    for(nc=1;nc<=5;nc++){
        fscanf(ent,"%s",pal);
        fprintf(sal,"%s\n",pal);
        fprintf(stdout,"%s\n",pal);
    }
    int i = 0;
    fclose(ent);
    fclose(sal);
    sal = fopen("Salida.c","r");
    char cadena[100];
    while((cadena[i++] = fgetc(sal)) != EOF);
    cadena[i-1] = '\0';
    printf("La cadena salida es: \n%s\nFIN\n", cadena);
    fclose(sal);
    return 0;
}