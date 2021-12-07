// power consumption

// generate two new binary numbers
// gamma rate and the epsilon rate
// The power consumption can then be found
// by multiplying the gamma rate by the epsilon rate.

// Considering only the first bit of each number.
// Since the most common bit is 1, the first bit of the gamma rate is 1.

// 12 bits

#include <stdio.h>

// https://adventofcode.com/2021/day/3

int main()
{
  FILE *fp;
  char buff[16];
  int bits[12] = {0};
  fp = fopen("input.txt", "r");
  while (fgets(buff, 16, (FILE*)fp) != NULL)
  {
    for (int i = 0; i < 12; i++) {
      // buff[i] - '0' = either 0 or 1
      if (buff[i] - '0' == 0) {
        bits[i] += 1;
      } else {
        bits[i] -= 1;
      }
    }
  }
  // 0000 0000 0000
  int gamma = 0; int epsilon = 0;
  for (int i = 0; i < 12; i++) {
    if (bits[i] > 0) {
      // most common 1
      gamma += 1 << 1;
    } else {
      // most common 0
    }
    printf("%d:%d ", i, bits[i]);
  }

  // printf("result: %d", result);
  fclose(fp);
}