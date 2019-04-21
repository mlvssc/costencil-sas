#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <malloc.h>
#include <sys/time.h>
#include <assert.h>

using namespace std;

#include "mm.h"

int mm_init()
{
  return 0;
}

int mm_gfree(void *gp)
{
  free(gp);
  return 0;
}

void *mm_galloc(size_t size)
{
  return malloc(size);
}


// Make [gp, gp+size) accessible
void *mm_fetch(void *gp, size_t size)
{
  return gp;
}

int mm_flushall()
{
  return 0;
}

int mm_finish()
{
  printf("[mm_finish] nothing is done\n");
  return 0;
}
