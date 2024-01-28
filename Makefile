CC = gcc
CFLAGS = -Wall
TARGET1 = mains
TARGET2 = maindloop
TARGET3 = maindrec
LIB = libclassloops.a
LIBREC = libclassrec.a
LIBREC_SO = libclassrec.so
LIBLOOP_SO = libclassloops.so
SOURCES1 = main.c basicClassification.c advancedClassificationRecursion.c
SOURCES2 =  main.c basicClassification.c advancedClassificationLoop.c
SOURCES3 =  main.c basicClassification.c advancedClassificationRecursion.c
HEADERS = NumClass.h

all: $(TARGET1) $(TARGET2) $(TARGET3) loops recursives

$(TARGET1): $(SOURCES1) $(HEADERS) $(LIBREC)
	$(CC) $(CFLAGS) -o $(TARGET1) $(SOURCES1) -L. -lclassrec

$(TARGET2): $(SOURCES2) $(HEADERS) $(LIBLOOP_SO)
	$(CC) $(CFLAGS) -o $(TARGET2) $(SOURCES2) -L. -lclassloops

$(TARGET3): $(SOURCES3) $(HEADERS) $(LIBREC_SO)
	$(CC) $(CFLAGS) -o $(TARGET3) $(SOURCES3) -L. -lclassrec

recursives: $(LIBREC)
recursived: $(LIBREC_SO)
loops: $(LIB)
loopd: $(LIBLOOP_SO)

$(LIB): advancedClassificationLoop.o basicClassification.o
	ar rcs $(LIB) advancedClassificationLoop.o basicClassification.o

$(LIBREC): advancedClassificationRecursion.o basicClassification.o
	ar rcs $(LIBREC) advancedClassificationRecursion.o basicClassification.o

$(LIBREC_SO): advancedClassificationRecursion.o basicClassification.o
	$(CC) -shared -o $(LIBREC_SO) advancedClassificationRecursion.o basicClassification.o

$(LIBLOOP_SO): advancedClassificationLoop.o basicClassification.o
	$(CC) -shared -o $(LIBLOOP_SO) advancedClassificationLoop.o basicClassification.o

advancedClassificationLoop.o: advancedClassificationLoop.c $(HEADERS)
	$(CC) $(CFLAGS) -fPIC -c -o advancedClassificationLoop.o advancedClassificationLoop.c

basicClassification.o: basicClassification.c $(HEADERS)
	$(CC) $(CFLAGS) -fPIC -c -o basicClassification.o basicClassification.c

advancedClassificationRecursion.o: advancedClassificationRecursion.c $(HEADERS)
	$(CC) $(CFLAGS) -fPIC -c -o advancedClassificationRecursion.o advancedClassificationRecursion.c

.PHONY: clean

clean:
	rm -f $(TARGET1) $(TARGET2) $(TARGET3) $(LIB) $(LIBREC) $(LIBREC_SO) $(LIBLOOP_SO) advancedClassificationLoop.o advancedClassificationRecursion.o basicClassification.o
