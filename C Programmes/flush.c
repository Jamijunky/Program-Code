#include <stdio.h>

int main() {
    FILE *fp;
    fp = fopen("test.txt", "w");
    fputs("Hello World!", fp);
    fflush(fp); // Ensure data is written to "test.txt"
    fclose(fp);
    printf("Data written to the file successfully.\n");
    return 0;
}