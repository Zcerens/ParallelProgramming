//#include <19050111060.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(int argc, char *argv[]) {
	 // call a function in another file
 // myPrintHelloMake();
  if (argc != 4) {
    printf("Requirements: %s rows cols file_name.txt \n", argv[0]);
    return 1;
  }
  // rows, columns and text file received from the user
  int rows = atoi(argv[1]);
  int cols = atoi(argv[2]);
  char *output_file = argv[3];

  // allocate memory for matrix
  double **matrix = (double **)malloc(rows * sizeof(double *));
  for (int i = 0; i < rows; i++) {
    matrix[i] = (double *)malloc(cols * sizeof(double));
  }
 
 

	// set seed for random number generator
  srand(190501);

	// fill matrix with random values
  for (int i = 0; i < rows; i++) {
    for (int j = 0; j < cols; j++) {
      matrix[i][j] = (double)rand() / RAND_MAX * 99.0 + 1.0;
    }
  }
  
	// printing the matrix to the screen for control
	printf("MATRIX: \n");
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            printf("%.2f ", (matrix)[i][j]);
        }
        printf("\n");
    }
  // allocate memory for vector
  double *vector = (double *)malloc(cols * sizeof(double));

  // fill vector with random values
  for (int i = 0; i < cols; i++) {
    vector[i] = (double)rand() / RAND_MAX * 99.0 + 1.0;
  }

  // perform matrix-vector multiplication
  double *result = (double *)calloc(rows, sizeof(double));
  for (int i = 0; i < rows; i++) {
    for (int j = 0; j < cols; j++) {
      result[i] += matrix[i][j] * vector[j];
    }
  }

  // write result to file
  FILE *f = fopen(output_file, "w");
  for (int i = 0; i < rows; i++) {
    fprintf(f, "%0.2f\n", result[i]);
  }
  fclose(f);

  // free allocated memory with free()
  for (int i = 0; i < rows; i++) {
    free(matrix[i]);
  }
  free(matrix);
  free(vector);
  free(result);

  return 0;
}

