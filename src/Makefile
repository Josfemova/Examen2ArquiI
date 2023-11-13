
CC=gcc
CFLAGS=-O0
COMP_FLAGS=-DSPEC_CPU -DNDEBUG -static

test: 
	$(CC) $(COMP_FLAGS) test.c $(CFLAGS) -o benchmark -lm

i0: $(SOURCES)
	$(CC) $(COMP_FLAGS) intercambio.c $(CFLAGS) -o benchmark -lm -DCASO=0 -DMAX_DATOS=$(DATOS)

i1: $(SOURCES)
	$(CC) $(COMP_FLAGS) intercambio.c $(CFLAGS) -o benchmark -lm -DCASO=1 -DMAX_DATOS=$(DATOS)

f0: $(SOURCES)
	$(CC) $(COMP_FLAGS) fusion.c $(CFLAGS) -o benchmark -lm -DCASO=0 -DMAX_DATOS=$(DATOS)

f1: $(SOURCES)
	$(CC) $(COMP_FLAGS) fusion.c $(CFLAGS) -o benchmark -lm -DCASO=1 -DMAX_DATOS=$(DATOS)


