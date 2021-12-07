#include <stdio.h>

// https://adventofcode.com/2021/day/2

int main()
{
  FILE *fp;
  char buff[32];
  int horizontal = 0; int depth = 0;
  fp = fopen("../input.txt", "r");
  while (fgets(buff, 32, (FILE*)fp) != NULL)
  {
    // check the first char of the line
    switch (buff[0])
    {
    case 'f': // Forward x
      horizontal += buff[8] - '0';
      break;
    case 'u': // Up x
      depth -= buff[3] - '0';
      break;
    case 'd': // Down x
      depth += buff[5] - '0';
      break;
    }
  }
  int result = horizontal * depth;
  printf("result: %d", result);
  fclose(fp);
}