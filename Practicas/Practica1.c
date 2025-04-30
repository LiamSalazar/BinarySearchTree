# include <stdio.h>

void ZZZZ(int *a, int*b){
    int t = *a;
    *a = *b;
    *b = t;
}

int YYYY(int a[], int n){
    int p = 0, i = 1, d = n-1;
    while(i <= d){
        while((a[p] > a[i])&&(i<=d)){
            i++;
        }
        while((a[p] <= a[d])&&(i<=d)){
            d--;
        }
        if(i<d){
            ZZZZ(a+i,a+d);
        }
    }
    ZZZZ(a+i,a+d);
    //ZZZZ(a,a+d);
    return i-1;
}

int main() {
    int arr[5] = {7, 3, 9, 1, 8};
    int pos = YYYY(arr, 5);

    printf("Posición del pivote: %d\n", pos);
    printf("Arreglo:\n");
    for (int i = 0; i < 5; i++) {
        printf("%d ", arr[i]);
    }
    return 0;
}
