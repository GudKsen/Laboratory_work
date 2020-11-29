/**
 * оголошення функції для множення матриці
*/
int mul_matrix();

/**
 * головна функція = {створення масивів,
                      перетворення матриці на лінійний масив,
                      виклик функції mull_matrix(),
                      перетворення результуючого лінійного масиву на результуючу матрицю}
*/
int main(){
    #define SIZE 4
    int arr[SIZE][SIZE] = { {1, 2, 3, 4}, {1, 2, 3, 4}, {1, 2, 3, 4}, {1, 2, 3, 4} };
    int line_size = SIZE * SIZE;
    int line_arr[line_size];
    int line_result[line_size];
    int result_matrix[SIZE][SIZE];

    for(int  i = 0; i < SIZE; i++){
        for(int j = 0; j < SIZE; j++){
            line_arr[i * SIZE + j] = arr[i][j];
        }
    }
    
    mull_matrix(SIZE, line_arr, line_arr, line_result);

    for(int i = 0; i < SIZE; i++){
        for(int j = 0; j < SIZE; j++){
            result_matrix[i][j] = line_result[i * SIZE + j];
        }
    }
    return 0;
}

/**
 * множення матриць
 * @param size розмір масивів
 * @param line_arr1 перший масив
 * @param line_arr2 другий масив
 * @param line_result результуючий масив
*/
void mull_matrix(int size, int line_arr1[], int line_arr2[], int line_result[]) {
    for(int i = 0; i < size; i++) {
        for(int j = 0; j < size; j++) {
            for(int k = 0; k < size; k++) {
                line_result[i * size + j] += line_arr1[i * size + k] * line_arr2[k * size + j]; 
            }
        }
    }
}
