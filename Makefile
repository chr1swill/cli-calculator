run: build exec

build: main.c
	mkdir -p bin
	gcc main.c -o bin/main

clean: 
	rm -rf bin

exec: build
	./bin/main
