#include <stdio.h>
#include <stdlib.h>

int main()
{
  FILE *sourceFile, *destFile;
  char sourcePath[100], destPath[100];
  char ch;
  printf("Enter source file path: ");
  scanf("%s", sourcePath);
  printf("Enter destination file path: ");
  scanf("%s", destPath);

  sourceFile = fopen(sourcePath, "r");
  if (sourceFile == NULL)
  {
    printf("Failed to open source file.\n");
    exit(1);
  }

  destFile = fopen(destPath, "w");
  if (destFile == NULL)
  {
    printf("Failed to open destination file.\n");
    fclose(sourceFile);
    exit(1);
  }
  while ((ch = fgetc(sourceFile)) != EOF)
  {
    fputc(ch, destFile);
  }

  fclose(sourceFile);
  fclose(destFile);

  printf("Files copied successfully.\n");
  return 0;
}