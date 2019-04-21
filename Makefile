all: MCUDAUM

CUDAUM:
	make -f Makefile.CUDAUM

MCUDAUM:
	make -f Makefile.MCUDAUM

OMPFOR:
	make -f Makefile.OMPFOR

OMPTASK:
	make -f Makefile.OMPTASK

clean:
	make -f Makefile.CUDAUM clean
	make -f Makefile.MCUDAUM clean
	make -f Makefile.OMPFOR clean
	make -f Makefile.OMPTASK clean

