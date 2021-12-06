#include <stdio.h>

static inline void shift(int *arr) {
  arr[0] = arr[1]; arr[1] = arr[2]; arr[2] = 0;
}

static inline int sum(int *arr) {
  return arr[0] + arr[1] + arr[2];
}

int main()
{
  FILE *fp;
  char buff[16];
  int ints[3] = {0};
  register int lastSum, nextSum, count = 0;

  fp = fopen("input.txt", "r");
  // populate the first 3 values
  for (size_t i = 0; i < 3; i++)
  {
    fgets(buff, 16, (FILE*)fp);
    sscanf(buff, "%d", &ints[i]);
  }
  // set the first lastSum
  lastSum = sum(ints);
  // shift
  shift(ints);
  // run main loop
  while (fgets(buff, 16, (FILE*)fp) != NULL)
  {
    // read into last array buffer
    sscanf(buff, "%d", &ints[2]);
    // set next sum
    nextSum = sum(ints);
    // if new sum is larger than last sum inc counter.
    if (nextSum > lastSum) { count++; }
    // set this sum as last sum
    lastSum = nextSum;
    // shift
    shift(ints);
  }
  printf("count: %d", count);
  fclose(fp);
}