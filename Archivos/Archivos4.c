# include <stdio.h>
int main(){
    FILE *al = fopen("MiTexto.txt","r");
    char c;
    int n = 0;
    while((c=fgetc(al)) != EOF){
        fprintf(stdout, "%d %c\n", ++n, c);
    }
    fprintf(stdout,"\n El archivo tiene %d caracteres. \n",n);
    fclose(al);
    return 0;
}