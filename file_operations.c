#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char* read_file(char* filename) {
  FILE* file = fopen(filename, "r");
  if (!file) {
    fprintf(stderr,"Error: File %s not found\n", filename);
    return NULL;
  }
  long size = 0;
  fseek(file, 0, SEEK_END);
  size = ftell(file);

  // Move back to the beginning of the file
  fseek(file, 0, SEEK_SET);

  char* buffer = (char*) malloc(size + 1);
  if(!buffer) {
    fclose(file);
    return NULL;
  }

  // Read file to buffer
  fread(buffer, sizeof(char), size, file);

  fclose(file); // Close file
  buffer[size+1] = '\0'; // Put null char for ending string

  return buffer;
}
