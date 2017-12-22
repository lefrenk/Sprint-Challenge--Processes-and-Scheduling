#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

#define mill 1000000

int main(void)
{
  struct timespec start, end;
  int i;
  long printf_total, write_total, printf_avg, write_avg;
  char * string = "✍️";

  for (i = 0; i < mill; i++)
  {
    clock_gettime(CLOCK_PROCESS_CPUTIME_ID, &start);
    printf("%s", string);
    clock_gettime(CLOCK_PROCESS_CPUTIME_ID, &end);
    printf_total += end.tv_nsec - start.tv_nsec;
  }

  for (i = 0; i < mill; i++)
  {
    clock_gettime(CLOCK_PROCESS_CPUTIME_ID, &start);
    write(0, string, strlen(string));
    clock_gettime(CLOCK_PROCESS_CPUTIME_ID, &end);
    write_total += end.tv_nsec - start.tv_nsec;
  }

  printf_avg = (printf_total / mill);
  write_avg = (write_total / mill);

  printf("\nAverage printf time is: %li ns\nTotal printf time is: %li ns\n", printf_avg, printf_total);
  printf("Average write time is: %li ns\nTotal write time is: %li ns\n", write_avg, write_total);
  printf("On average, printf is %li ns faster\n", write_avg - printf_avg);

  return 0;
}
