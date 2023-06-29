#include<iostream>
void insertColumn(int** arr, int numRows, int numCols, int colPos, int* colData) {
    int** tmpArr = new int* [numRows];
    for (int i = 0; i < numRows; i++) {
        tmpArr[i] = new int[numCols + 1];
    }

    for (int i = 0; i < numRows; i++) {
        int j = 0;
        for (; j < colPos; j++) {
            tmpArr[i][j] = arr[i][j];
        }
        tmpArr[i][j] = colData[i];
        for (; j < numCols; j++) {
            tmpArr[i][j + 1] = arr[i][j];
        }
    }

    for (int i = 0; i < numRows; i++) {
        for (int j = 0; j < numCols + 1; j++) {
            arr[i][j] = tmpArr[i][j];
        }
    }

    for (int i = 0; i < numRows; i++) {
        delete[] tmpArr[i];
    }
    delete[] tmpArr;
}
void deleteColumn(int** arr, int numRows, int numCols, int colNum) {
    int** tmpArr = new int* [numRows];
    for (int i = 0; i < numRows; i++) {
        tmpArr[i] = new int[numCols - 1];
    }

    for (int i = 0; i < numRows; i++) {
        int j = 0;
        for (; j < colNum; j++) {
            tmpArr[i][j] = arr[i][j];
        }
        for (; j < numCols - 1; j++) {
            tmpArr[i][j] = arr[i][j + 1];
        }
    }

    for (int i = 0; i < numRows; i++) {
        for (int j = 0; j < numCols - 1; j++) {
            arr[i][j] = tmpArr[i][j];
        }
    }
    
    for (int i = 0; i < numRows; i++) {
        delete[] tmpArr[i];
    }
    delete[] tmpArr;
}
void cyclicShift(int** arr, int M, int N, int shiftRows, int shiftCols, bool shiftRight) {
    if (shiftRows != 0) {
        int shiftRow = shiftRows % M; 
        if (shiftRow < 0) {
            shiftRow += M;
        }
        for (int i = 0; i < M; i++) {
            int* tmpRow = new int[N];
            if (shiftRight) {
                for (int j = 0; j < N; j++) {
                    tmpRow[j] = arr[i][(j + (N - shiftRow)) % N]; 
                }
            }
            else {
                for (int j = 0; j < N; j++) {
                    tmpRow[(j + shiftRow) % N] = arr[i][j]; 
                }
            }
            for (int j = 0; j < N; j++) {
                arr[i][j] = tmpRow[j];
            }
            delete[] tmpRow; 
        }
    }


    if (shiftCols != 0) {
        int shiftCol = shiftCols % N; 
        if (shiftCol < 0) { 
            shiftCol += N;
        }
        for (int j = 0; j < N; j++) {
            int* tmpCol = new int[M]; 
            if (shiftRight) {
                for (int i = 0; i < M; i++) {
                    tmpCol[i] = arr[(i + (M - shiftCol)) % M][j];
                }
            }
            else {
                for (int i = 0; i < M; i++) {
                    tmpCol[(i + shiftCol) % M] = arr[i][j];
                }
            }
            for (int i = 0; i < M; i++) {
                arr[i][j] = tmpCol[i]; 
            }
            delete[] tmpCol;
        }
    }
}

