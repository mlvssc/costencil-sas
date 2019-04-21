#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <malloc.h>
#include <sys/time.h>
#include <assert.h>
#include <cuda_runtime.h>
#include <list>

#include "mm.h"
#include "cos.h"

#include <omp.h>

#define CERR(cstat) { \
  cudaError_t crc0 = cstat; \
  if ((crc0) != cudaSuccess) {					\
    fprintf(stderr, "[mm(%s:%d)] CUDA ERROR %d\n", __FILE__, __LINE__, (crc0)); \
    exit(1);							\
  }}

int mm_init()
{
  cudaError_t crc;
  /* one GPU per OMP thread */
  char *envstr;
  int ngpu;
  crc = cudaGetDeviceCount(&ngpu);
  CERR(crc);
  
  int nt = -1;
  envstr = getenv("OMP_NUM_THREADS");
  if (envstr != NULL) nt = atoi(envstr);
  
  if (nt < -1 || nt > ngpu) nt = ngpu;
#if VERBOSE >= 10
  printf("[mm_init] %d GPUs (out of %d) are used\n", nt, ngpu);
#endif
  
  assert(ngpu >= 0);
  omp_set_num_threads(nt);
  
#pragma omp parallel
  {
    int tid;
    tid = omp_get_thread_num();
    assert(tid >= 0 && tid < nt);
    crc = cudaSetDevice(tid);
    CERR(crc);
#if VERBOSE >= 10
    printf("[mm_init] start to use GPU %d\n", tid);
#endif
  }
  
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



