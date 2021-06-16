targets = main.bin 
CC = g++
C_OPTS =  -g -Wall -Wextra  -Wformat-security -Wshadow -Wconversion -Wlogical-not-parentheses -Wnull-dereference -I./src src/dessert.cpp src/desserts_arr.cpp

all: clean prep compile run

clean:
	rm -rf dist
prep:
	mkdir dist
compile: main.bin test.bin

main.bin: src/main.cpp
	$(CC) $(C_OPTS) $< -o ./dist/$@

test.bin: test/test.cpp
	$(CC) $(C_OPTS) $< -o ./dist/$@
	
test: clean prep compile
	./dist/test.bin 

run: clean prep compile
	./dist/main.bin

doxygen:
	doxygen Doxyfile
format: #TODO

tidy: # TODO


