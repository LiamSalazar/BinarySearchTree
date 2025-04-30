# include <stdio.h>
int main(){
    FILE *sal = fopen("Prueba.c","w");
    char c;
    int nc = 0;
    while((c=fgetc(stdin))!='@'){
        fputc(c,sal);
        nc++;
    }
    fclose(sal);
    printf("\nCaracteres eb el archivo: %d.\n",nc);
    return 0;
}