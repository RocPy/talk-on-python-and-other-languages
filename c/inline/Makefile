.PHONY: clean

all: simple abstract run

%.o: %.cpp
	$(CC) -c -o $@ $< $(CFLAGS)

simple: simple.o
	$(CC) -O3 -o simple simple.o

abstract: abstract.o
	$(CC) -O3 -o abstract abstract.o

run:
	@echo "Python (Simple)"
	@time python simple.py
	@echo
	@echo "Python (Abstract)"
	@time python abstract.py
	@echo
	@echo "C++ (Simple)"
	@time ./simple
	@echo
	@echo "C++ (Abstract)"
	@time ./abstract

clean:
	rm *.o abstract simple
