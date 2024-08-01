MATH_LIB = -lm
STD_LIB = -lc
DEPS = $(MATH_LIB) $(STD_LIB)

run: build exec

build: main.c
	mkdir -p bin
	gcc main.c -o bin/main $(DEPS)

clean: 
	rm -rf bin

exec: build
	./bin/main
