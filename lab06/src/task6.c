int main(){
    #define N 4
    int arr[N][N] = {{1,2,3,4},{3,7,5,3},{4,5,3,2},{8,6,4,6}};
    int res[N][N]={0};
    for(int i = 0; i < N; i++) {
        for( int j = 0; j < N; j++) {
            for(int k = 0; k < N; k++) {
                res[i][j] += arr[i][k] * arr[k][j];
            }
        }
    }
    return 0;
}