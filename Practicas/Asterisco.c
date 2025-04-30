# include <stdio.h>

void ImpRenCaracter(char c, int n){
    int i;
    for( i = 1; i <= n; i++){
        putchar(c);
    }
}

int main(){
    int n = 0;
    puts("Ingrese el num de asteriscos: ");
    scanf("%d", &n);
    
    int n2 = n;
    puts("TRIANGULO 1");
    for(int i = 0; i < n; i++){
        for(int j = 0; j <= i; j++){
            printf("*");
        }
        puts("");
    }
    puts("");
    puts("TRIANGULO 2");
    for(int i = 0; i < n; i++){
        for(int j = n-i-1; j >= 0; j--){
            printf("*");
        }
        puts("");
    }
    puts("");
    puts("TRIANGULO 3");
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            if(j < n-i-1)
                printf(" ");
            else
                printf("*");
        }
        puts("");
    }
    puts("");
    puts("TRIANGULO 4");
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            if(j < i)
                printf(" ");
            else
                printf("*");
        }
        puts("");
    }
    puts("");
    puts("TRIANGULO 5");
    int i = 1;
    for(int j = n; j >= 1; j--){
        ImpRenCaracter(' ', j-1);
        ImpRenCaracter('*', i);
        puts("");
        i++;
    }
    n--;
    for(int j = n; j >= 1; j--){
        ImpRenCaracter(' ', n-j+1);
        ImpRenCaracter('*', j);
        puts("");
    }
    puts("");
    puts("TRIANGULO 6");
    int asteriscos = 1;
    while (asteriscos <= n2) {
        int espacios = (n2 - asteriscos) / 2;
        ImpRenCaracter(' ', espacios);
        ImpRenCaracter('*', asteriscos);
        ImpRenCaracter(' ', espacios);
        puts("");
        asteriscos += 2;
    }
    puts("");
    puts("ROMBO");
    asteriscos = 1;
    while (asteriscos <= n2) {
        int espacios = (n2 - asteriscos) / 2;
        ImpRenCaracter(' ', espacios);
        ImpRenCaracter('*', asteriscos);
        ImpRenCaracter(' ', espacios);
        puts("");
        asteriscos += 2;
    }
    asteriscos = n2-2;
    while(asteriscos >= 1){
        int espacios = (n2 - asteriscos) / 2;
        ImpRenCaracter(' ', espacios);
        ImpRenCaracter('*', asteriscos);
        ImpRenCaracter(' ', espacios);
        puts("");
        asteriscos -= 2;
    }
    return 0;
}

//   *  
//  *** 
// *****
//*******

//   *
//  ***
// *****
//*******

// *****
//  ***
//   *