CC=gcc
CFLAGS=-O0
COMP_FLAGS=-DMAX_DATOS=$(DATOS) -static

test: 
	$(CC) $(COMP_FLAGS) test.c $(CFLAGS) -o benchmark -lm

i0: $(SOURCES)
	$(CC) $(COMP_FLAGS) intercambio.c $(CFLAGS) -o benchmark -lm -DCASO=0

i1: $(SOURCES)
	$(CC) $(COMP_FLAGS) intercambio.c $(CFLAGS) -o benchmark -lm -DCASO=1

f0: $(SOURCES)
	$(CC) $(COMP_FLAGS) fusion.c $(CFLAGS) -o benchmark -lm -DCASO=0

f1: $(SOURCES)
	$(CC) $(COMP_FLAGS) fusion.c $(CFLAGS) -o benchmark -lm -DCASO=1


