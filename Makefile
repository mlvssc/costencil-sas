all: CUDAUM

CUDAUM:
	make -f Makefile.CUDAUM

OMPFOR:
	make -f Makefile.OMPFOR

OMPTASK:
	make -f Makefile.OMPTASK

clean:
	make -f Makefile.CUDAUM clean
	make -f Makefile.OMPFOR clean
	make -f Makefile.OMPTASK clean

