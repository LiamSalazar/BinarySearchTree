# include <stdio.h>
# define m 5

int main(){
    int matrix[m][m] = {0};
    for(int i = 0; i < m; i++){
        for(int j = 0; j < m; j++){
            matrix[i][j] = 0;
        }
    }
    int inicio = (m / 2);
    matrix[0][inicio] = 1;
    int c = inicio, r = 0;
    for(int i = 2; i <= m*m; i++){
        r--;
        c++;
        if(r >= 0 && c < m){
            if(matrix[r][c] != 0){
                r += 2;
                c--;
            }
        }else if(r < 0 && c < m){
            r = m-1;
        }else if(c >= m && r >= 0){
            c = 0;
        }else if(r < 0 && c >= m){
            r += 2;
            c--;
        }
        matrix[r][c] = i;
    }
    
    for(int i = 0; i < m; i++){
        for(int j = 0; j < m; j++){
            printf("%d\t", matrix[i][j]);
        }
        puts("");
    }
    return 0;
}