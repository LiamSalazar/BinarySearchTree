# include <stdio.h>

void intercambiar(int *a, int *b){
    int temp = *a;
    *a = *b;
    *b = temp;
}

int partition(int array[], int n){
    int p = array[0];
    int i = 1, d = n-1;
    while (i <= d){
        while((array[i] <= p) && i <=d){i++;}
        while((array[d] > p) && i <=d){d--;}
        if(i < d){intercambiar(array+i, array+d);}
    }
    intercambiar(array, array+d);
    return d;
}

void quicksort(int array[], int n){
    if (n <= 1) return; 
    int pivote = partition(array, n);
    quicksort(array, pivote);
    quicksort(array + pivote + 1, n - pivote - 1);
}

int main() {
    int arr[5] = {5,4,3,2,1};
    

    printf("Arreglo:\n");
    for (int i = 0; i < 5; i++) {
        printf("%d ", arr[i]);
    }
    
    printf("\nArreglo Ordenado:\n");
    
    quicksort(arr, 5);
    for (int i = 0; i < 5; i++) {
        printf("%d ", arr[i]);
    }
    puts("");
    return 0;
}
