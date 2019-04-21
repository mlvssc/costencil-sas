#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <malloc.h>
#include <sys/time.h>
#include <assert.h>
#include <cuda_runtime.h>
#include <list>

#include "mm.h"

#define CERR(cstat) { \
  cudaError_t crc0 = cstat; \
  if ((crc0) != cudaSuccess) {					\
    fprintf(stderr, "[mm(%s:%d)] CUDA ERROR %d\n", __FILE__, __LINE__, (crc0)); \
    exit(1);							\
  }}

int mm_init()
{
  return 0;
}

int mm_gfree(void *gp)
{
  cudaError_t crc;
  crc = cudaFree(gp);
  CERR(crc);
  return 0;
}

void *mm_galloc(size_t size)
{
  void *gp;
  cudaError_t crc;
  crc = cudaMallocManaged(&gp, size, cudaMemAttachGlobal);
  CERR(crc);
  return gp;
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



