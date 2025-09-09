#include <stdio.h>
#include <stdlib.h>

int main() {
    FILE *fp;
    char filename[20];
    int i;

    for (i = 1; i <= 20; i++) {
        // Create filename like q_1.c, q_2.c, etc.
        sprintf(filename, "q_%d.c", i);

        // Open file in write mode
        fp = fopen(filename, "w");

        if (fp == NULL) {
            printf("Error creating file %s\n", filename);
            return 1; // Exit on error
        }

        fclose(fp); // Close the file
    }

    printf("20 C files created successfully.\n");
    return 0;
}
