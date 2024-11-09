#include <stdio.h>

// Function to convert the matrix to tuple form
void convertToTuple(int matrix[10][10], int tuple[10][3], int rows, int cols) {
    int k = 1;
    tuple[0][0] = rows;
    tuple[0][1] = cols;
    tuple[0][2] = 0;

    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            if (matrix[i][j] != 0) {
                tuple[k][0] = i;
                tuple[k][1] = j;
                tuple[k][2] = matrix[i][j];
                k++;
                tuple[0][2]++;
            }
        }
    }
}

// Function to display the matrix in tuple form
void displayTuple(int tuple[10][3]) {
    printf("\nRow\tColumn\tValue\n");
    for (int i = 0; i <= tuple[0][2]; i++) {
        printf("%d\t%d\t%d\n", tuple[i][0], tuple[i][1], tuple[i][2]);
    }
}

// Function to find the transpose of a matrix in tuple form
void transpose(int tuple[10][3], int transTuple[10][3]) {
    int k = 1;
    transTuple[0][0] = tuple[0][1];
    transTuple[0][1] = tuple[0][0];
    transTuple[0][2] = tuple[0][2];

    for (int i = 0; i < tuple[0][1]; i++) {
        for (int j = 1; j <= tuple[0][2]; j++) {
            if (tuple[j][1] == i) {
                transTuple[k][0] = tuple[j][1];
                transTuple[k][1] = tuple[j][0];
                transTuple[k][2] = tuple[j][2];
                k++;
            }
        }
    }
}

// Function to find the sum of two matrices in tuple form
void sumOfMatrices(int tuple1[10][3], int tuple2[10][3], int result[10][3]) {
    if (tuple1[0][0] != tuple2[0][0] || tuple1[0][1] != tuple2[0][1]) {
        printf("Matrices cannot be added.\n");
        return;
    }

    int k = 1, i = 1, j = 1;
    result[0][0] = tuple1[0][0];
    result[0][1] = tuple1[0][1];
    result[0][2] = 0;

    while (i <= tuple1[0][2] && j <= tuple2[0][2]) {
        if (tuple1[i][0] < tuple2[j][0] || 
            (tuple1[i][0] == tuple2[j][0] && tuple1[i][1] < tuple2[j][1])) {
            result[k][0] = tuple1[i][0];
            result[k][1] = tuple1[i][1];
            result[k][2] = tuple1[i][2];
            i++;
        } else if (tuple1[i][0] > tuple2[j][0] || 
                   (tuple1[i][0] == tuple2[j][0] && tuple1[i][1] > tuple2[j][1])) {
            result[k][0] = tuple2[j][0];
            result[k][1] = tuple2[j][1];
            result[k][2] = tuple2[j][2];
            j++;
        } else {
            result[k][0] = tuple1[i][0];
            result[k][1] = tuple1[i][1];
            result[k][2] = tuple1[i][2] + tuple2[j][2];
            i++;
            j++;
        }
        k++;
        result[0][2]++;
    }

    while (i <= tuple1[0][2]) {
        result[k][0] = tuple1[i][0];
        result[k][1] = tuple1[i][1];
        result[k][2] = tuple1[i][2];
        i++;
        k++;
        result[0][2]++;
    }

    while (j <= tuple2[0][2]) {
        result[k][0] = tuple2[j][0];
        result[k][1] = tuple2[j][1];
        result[k][2] = tuple2[j][2];
        j++;
        k++;
        result[0][2]++;
    }
}

// Main function
int main() {
    int matrix1[10][10], matrix2[10][10], tuple1[10][3], tuple2[10][3], transTuple[10][3], sumTuple[10][3];
    int rows, cols, choice;

    // Input matrix dimensions
    printf("Enter number of rows and columns for the matrices: ");
    scanf("%d%d", &rows, &cols);

    // Input first matrix
    printf("Enter elements of the first matrix:\n");
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            scanf("%d", &matrix1[i][j]);
        }
    }

    // Input second matrix
    printf("Enter elements of the second matrix:\n");
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            scanf("%d", &matrix2[i][j]);
        }
    }

    do {
        // Menu
        printf("\nMenu:\n");
        printf("1. Convert matrices to tuple form\n");
        printf("2. Display matrices in tuple form\n");
        printf("3. Transpose of the first matrix in tuple form\n");
        printf("4. Sum of the matrices in tuple form\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                convertToTuple(matrix1, tuple1, rows, cols);
                convertToTuple(matrix2, tuple2, rows, cols);
                printf("Matrices converted to tuple form successfully.\n");
                break;
            case 2:
                printf("First matrix in tuple form:\n");
                displayTuple(tuple1);
                printf("Second matrix in tuple form:\n");
                displayTuple(tuple2);
                break;
            case 3:
                transpose(tuple1, transTuple);
                printf("Transpose of the first matrix:\n");
                displayTuple(transTuple);
                break;
            case 4:
                sumOfMatrices(tuple1, tuple2, sumTuple);
                printf("Sum of the matrices in tuple form:\n");
                displayTuple(sumTuple);
                break;
            case 5:
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    } while (choice != 5);

    return 0;
}