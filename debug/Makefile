CC = g++
CFLAGS = -std=c++11 -pthread
EXE = YAWM

all: Wave.o
	$(CC) $(CFLAGS) *.o ../src/main.cpp -o $(EXE)

Wave.o: ../libyawm/Wave.h ../libyawm/Wave.cpp
	@echo "making"
	$(CC) $(CFLAGS) ../libyawm/Wave.cpp -c

.PHONY: clean distclean

clean:
	rm -rf *.o

distclean: clean
	rm -rf $(EXE)
