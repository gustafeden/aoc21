#include <stdio.h>
int main()
{
  FILE *fp;
  char buff[16];
  int nextInt, lastInt, count;
  fp = fopen("input.txt", "r");
  fgets(buff, 16, (FILE*)fp);
  sscanf(buff, "%d", &nextInt);
  while (fgets(buff, 16, (FILE*)fp) != NULL)
  {
    sscanf(buff, "%d", &nextInt);
    if (lastInt != 0 && nextInt > lastInt) {
      count++;
    }
    lastInt = nextInt;
  }
  printf("%u", count);
  fclose(fp);
}