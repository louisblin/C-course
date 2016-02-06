#include <stdio.h>

int main(int argc, char **argv) {

  if (argc != 2) {
    fprintf(stderr, "%s: <file>", argv[0]);
    return 1;
  }

  // r  | Opens an existing text file for reading purpose.
  // w  | Opens a text file for writing. If it does not exist, then a new file 
  //      is created. Here your program will start writing content from the 
  //      beginning of the file.
  // a  | Opens a text file for writing in appending mode. If it does not exist, 
  //      then a new file is created. Here your program will start appending 
  //      content in the existing file content.
  // r+ | Opens a text file for both reading and writing.
  // w+ | Opens a text file for both reading and writing. It first truncates 
  //      the file to zero length if it exists, otherwise creates a file if it 
  //      does not exist.
  // a+ | Opens a text file for both reading and writing. It creates the file 
  //      if it does not exist. The reading will start from the beginning but 
  //      writing can only be appended.

  FILE* fd = fopen(argv[1], "r");
  if (!fd) {
    fprintf(stderr, "%s: Something went wrong with your file", argv[0]);
    return 1;
  }

  char c;
  while((c = getc(fd)) != EOF) {
    printf("%c", c); 
  }

  fclose(fd);

  return 0;
}
