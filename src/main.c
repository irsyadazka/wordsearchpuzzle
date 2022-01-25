#include "boolean.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>

#define ROW_SIZE 1000
#define COL_SIZE 1000

typedef char ElType;
typedef struct {
    ElType contents[ROW_SIZE][COL_SIZE];
    int rowEff;
    int colEff;
} Matrix;
typedef struct {
    ElType contents[50][50];
    int neff;
} List;

#define ROW(M) (M).rowEff
#define COL(M) (M).colEff
#define ELMT(M, i, j) (M).contents[(i)][(j)]

#define NEFF(L) (L).neff
#define ELMTL(L, i) (L).contents[(i)]

FILE* openFile;
Matrix template;
Matrix result;
List keyword;
int count;
int length;
int kind;
char arr[50];
char reverse[50];
boolean found = false;

void readFile() {
    printf("Masukkan nama file yang diinginkan: ");
    char fileName[50];
    gets(fileName);

    openFile = fopen(fileName, "r");

    char tokenMap = fgetc(openFile);
    char beforeToken = tokenMap;
    ROW(template) = 0; COL(template) = 0;
    int baris = 0; int kolom = 0;
    while (tokenMap != '\n' || beforeToken != '\n') {
        putchar(tokenMap);
        if (tokenMap == '\n') {
            ROW(template)++;
            baris++;
            COL(template) = kolom;
            kolom = 0; 
        }
        if (tokenMap != ' ' && tokenMap != '\n') {
            ELMT(template, baris, kolom) = tokenMap;
            kolom++;
        }
        beforeToken = tokenMap;
        tokenMap = fgetc(openFile);
    }

    printf("\nDaftar keyword yang perlu dicari:\n");
    NEFF(keyword) = 0;
    char line[100];
    while (fgets(line, sizeof(line), openFile)) {
        printf("%s", line);
        strcpy(ELMTL(keyword, NEFF(keyword)), line);
        NEFF(keyword)++;
    }

    for (int i = 0; i < NEFF(keyword)-1; i++) {
        ELMTL(keyword, i)[strlen(ELMTL(keyword, i))-1] = '\0';
    }

    fclose(openFile);
    count = 0;
}

void resultMatrix() {
    ROW(result) = ROW(template);
    COL(result) = COL(template);

    for (int i = 0; i < ROW(result); i++) {
        for (int j = 0; j < COL(result); j++) {
            ELMT(result, i, j) = '-';
        }
    }
}

void printResMatrix() {
    for (int i = 0; i < ROW(result); i++) {
        for (int j = 0; j < COL(result); j++) {
            if (j+1 == COL(result)) {
                printf("%c\n", ELMT(result, i, j));
            } else {
                printf("%c ", ELMT(result, i, j)); 
            }
        }
    }
}

void charArray(int x) {
    length = strlen(ELMTL(keyword, x));
    for (int i = 0; i <= length; i++) {
        arr[i] = ELMTL(keyword, x)[i];
        reverse[i] = ELMTL(keyword, x)[i];
    }
}

void reverseCharArray() {
    char temp;
    int start = 0;
    int end = length-1;
    while (start <= end) {
        temp = reverse[start];
        reverse[start] = reverse[end];
        reverse[end] = temp;
        start++;
        end--;
    }
}

void searchHorizontal(int row, int col) {
    if (col+length > COL(template)) {
        
    } else {
        int iterator = 1;
        int counter = 1;
        boolean same = true;
        while (iterator < length && counter <= length && same) {
            if (ELMT(template, row, col+iterator) != arr[iterator]) {
                count++;
                same = false;
            } else {
                count++;
                counter++;
                iterator++;
            }
        }
        int keepCol = col+iterator;
        found = same;
        if (found) {
            resultMatrix();
            for (int writeCol = col; writeCol < keepCol; writeCol++) {
                ELMT(result, row, writeCol) = ELMT(template, row, writeCol);
            }
            printf("\n");
            printResMatrix();
        }
    }
}

void searchHorizontalReverse(int row, int col) {
    if (col+length > COL(template)) {
        
    } else {
        int iterator = 1;
        int counter = 1;
        boolean same = true;
        while (iterator < length && counter <= length && same) {
            if (ELMT(template, row, col+iterator) != reverse[iterator]) {
                count++;
                same = false;
            } else {
                count++;
                counter++;
                iterator++;
            }
        }
        int keepCol = col+iterator;
        found = same;
        if (found) {
            resultMatrix();
            for (int writeCol = col; writeCol < keepCol; writeCol++) {
                ELMT(result, row, writeCol) = ELMT(template, row, writeCol);
            }
            printf("\n");
            printResMatrix();
        }
    }
}

void searchVertical(int row, int col) {
    if (row+length > ROW(template)) {
        
    } else {
        int iterator = 1;
        int counter = 1;
        boolean same = true;
        while (iterator < length && counter <= length && same) {
            if (ELMT(template, row+iterator, col) != arr[iterator]) {
                count++;
                same = false;
            } else {
                count++;
                counter++;
                iterator++;
            }
        }
        int keepRow = row+iterator;
        found = same;
        if (found) {
            resultMatrix();
            for (int writeRow = row; writeRow < keepRow; writeRow++) {
                ELMT(result, writeRow, col) = ELMT(template, writeRow, col);
            }
            printf("\n");
            printResMatrix();
        }
    }
}

void searchVerticalReverse(int row, int col) {
    if (row+length > ROW(template)) {
        
    } else {
        int iterator = 1;
        int counter = 1;
        boolean same = true;
        while (iterator < length && counter <= length && same) {
            if (ELMT(template, row+iterator, col) != reverse[iterator]) {
                count++;
                same = false;
            } else {
                count++;
                counter++;
                iterator++;
            }
        }
        int keepRow = row+iterator;
        found = same;
        if (found) {
            resultMatrix();
            for (int writeRow = row; writeRow < keepRow; writeRow++) {
                ELMT(result, writeRow, col) = ELMT(template, writeRow, col);
            }
            printf("\n");
            printResMatrix();
        }
    }
}

void searchLTtoRB(int row, int col) {
    if (row+length <= ROW(template) && col+length <= COL(template)) {
        int iterator = 1;
        int counter = 1;
        boolean same = true;
        while (iterator < length && counter <= length && same) {
            if (ELMT(template, row+iterator, col+iterator) != arr[iterator]) {
                count++;
                same = false;
            } else {
                count++;
                counter++;
                iterator++;
            }
        }
        int keepCol = col+iterator;
        int keepRow = row+iterator;
        found = same;
        if (found) {
            resultMatrix();
            int writeRow = row; 
            int writeCol = col;
            while (writeRow < keepRow) {
                ELMT(result, writeRow, writeCol) = ELMT(template, writeRow, writeCol);
                writeRow++;
                writeCol++;
            }
            printf("\n");
            printResMatrix();
        }
    }
}

void searchLTtoRBreverse(int row, int col) {
    if (row+length < ROW(template) && col+length < COL(template)) {
        int iterator = 1;
        int counter = 1;
        boolean same = true;
        while (iterator < length && counter <= length && same) {
            if (ELMT(template, row+iterator, col+iterator) != reverse[iterator]) {
                count++;
                same = false;
            } else {
                count++;
                counter++;
                iterator++;
            }
        }
        int keepCol = col+iterator;
        int keepRow = row+iterator;
        found = same;
        if (found) {
            resultMatrix();
            int writeRow = row; 
            int writeCol = col;
            while (writeRow < keepRow) {
                ELMT(result, writeRow, writeCol) = ELMT(template, writeRow, writeCol);
                writeRow++;
                writeCol++;
            }
            printf("\n");
            printResMatrix();
        }
    }
}

void searchLBtoRT(int row, int col) {
    if (row-length >= -1 && col+length <= COL(template)) {
        int iterator = 1;
        int counter = 1;
        boolean same = true;
        while (iterator < length && counter <= length && same) {
            if (ELMT(template, row-iterator, col+iterator) != arr[iterator]) {
                count++;
                same = false;
            } else {
                count++;
                counter++;
                iterator++;
            }
        }
        int keepCol = col+iterator;
        int keepRow = row-iterator;
        found = same;
        if (found) {
            resultMatrix();
            int writeRow = row; 
            int writeCol = col;
            while (writeCol < keepCol) {
                ELMT(result, writeRow, writeCol) = ELMT(template, writeRow, writeCol);
                writeRow--;
                writeCol++;
            }
            printf("\n");
            printResMatrix();
        }
    }
}

void searchLBtoRTreverse(int row, int col) {
    if (row-length >= -1 && col+length <= COL(template)) {
        int iterator = 1;
        int counter = 1;
        boolean same = true;
        while (iterator < length && counter <= length && same) {
            if (ELMT(template, row-iterator, col+iterator) != reverse[iterator]) {
                count++;
                same = false;
            } else {
                count++;
                counter++;
                iterator++;
            }
        }
        int keepCol = col+iterator;
        int keepRow = row-iterator;
        found = same;
        if (found) {
            resultMatrix();
            int writeRow = row; 
            int writeCol = col;
            while (writeCol < keepCol) {
                ELMT(result, writeRow, writeCol) = ELMT(template, writeRow, writeCol);
                writeRow--;
                writeCol++;
            }
            printf("\n");
            printResMatrix();
        }
    }
}

int main() {
    readFile();
    printf("\n");
    clock_t onset = clock();
    for (int allkeys = 0; allkeys < NEFF(keyword); allkeys++) {
        kind = 1;
        charArray(allkeys);
        reverseCharArray();
        for (int i = 0; i < ROW(template); i++) {
            for (int j = 0; j < COL(template); j++) {
                if (ELMT(template, i, j) != arr[0] && ELMT(template, i, j) != reverse[0]) {
                    count++;
                }
                if (ELMT(template, i, j) == arr[0] || ELMT(template, i, j) == reverse[0]) {
                    searchHorizontal(i, j);
                    if (!found) {
                        searchVertical(i, j);
                    }
                    if (!found) {
                        searchLTtoRB(i, j);
                    }
                    if (!found) {
                        searchLBtoRT(i, j);
                    }
                    if (!found) {
                        searchHorizontalReverse(i, j);
                    }
                    if (!found) {
                        searchVerticalReverse(i, j);
                    }
                    if (!found) {
                        searchLTtoRBreverse(i, j);
                    }
                    if (!found) {
                        searchLBtoRTreverse(i, j);
                    }
                }
            }
        }
    }
    clock_t onfinish = clock();

    printf("\nLama eksekusi program adalah %f ms", (double) onfinish-onset);
    printf("\nJumlah total perbandingan karakter: %d", count);
}