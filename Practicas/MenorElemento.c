# include <stdio.h>

int menorElemento(int array[], int n){
    int menor = 1000;
    for(int i; i < n; i++){
        if(array[i] < menor)
            menor = array[i];
    }
    return menor;
}

int main(){
    int array[5] = {7, 3, 9, 1, 8};
    printf("Menor Elemento: %d\n", menorElemento(array, 5));
    return 0;
}