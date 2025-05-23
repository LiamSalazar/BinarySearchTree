# include <stdio.h>

void busquedaLineal(int a[], int n, int objetivo){
    for(int i = 0; i < n; i++){
        if(a[i] == objetivo)
            printf("El elemento %d está en la posición %d\n", objetivo, i+1);
    }
}

void busquedaBinaria(int a[], int n, int objetivo){
    int l = 0;
    int r = n-1;
    while(l < r){
        int centro = (l + r) / 2;
        if(a[centro] == objetivo){
            printf("El elemento %d está en el arreglo en el índice %d\n", objetivo, centro);
            break;
        }
        else if(a[centro] < objetivo)
            l = centro + 1;
        else if(a[centro] > objetivo)
            r = centro -1;
    }
}

int main(){
    int a[5] = {1,2,3,4,5};
    int objetivo = 3;
    puts("Busqueda Lineal");
    busquedaLineal(a, 5, objetivo);
    puts("Busqueda Binaria");
    busquedaBinaria(a, 5, objetivo);
    return 0;
}