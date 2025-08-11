#include <stdio.h>
#include <string.h>

#include "encode.h"

char* test_string = "this is a simple test";

int main(int argc, char** argv)
{
  LZ77_encoder encoder;
  encoder.input = test_string;
  encoder.input_start = test_string;
  encoder.input_end = encoder.input_start + strlen(encoder.input);
  encoder.window = (LZ77e_window) {.sbl = 5, .labl = 5};

  encoder.output.items = NULL;
  encoder.output.count = 0;
  encoder.output.capacity = 0;

  LZ77_encode(&encoder);
  return 0;
}
