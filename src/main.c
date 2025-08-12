#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#include "encode.h"

char* get_content_from_file(char* path) {
  FILE* file;
  long length;
  char* content;

  file = fopen(path, "rb");
  if (file == NULL)
  {
    perror("Error reading file");
    return ""; 
  }

  fseek(file, 0, SEEK_END);
  length = ftell(file);
  fseek(file, 0, SEEK_SET);
  content = malloc(length + 1);
  if (content) {
    size_t bytes_read = fread(content, 1, length, file);
    content[bytes_read] = '\0'; 
  }
  else
  {
    fclose(file);
    return ""; 
  }

  fclose(file);

  return content;
}

int main(int argc, char** argv)
{
  if(argc < 2) {
    puts("[ERROR] - please give a file to compress");
    return 1;
  }

  char* content = get_content_from_file(argv[1]);
  if(content == "") {
    puts("[ERROR] - no content found");
    return 1;
  }

  LZ77_encoder encoder;
  encoder.input = content;
  encoder.input_start = content;
  encoder.window = (LZ77e_window) {.sbl = 5, .labl = 5};

  encoder.output.items = NULL;
  encoder.output.count = 0;
  encoder.output.capacity = 0;

  LZ77_encode(&encoder);
  LZ77e_write_outputs(&encoder);

  return 0;
}
