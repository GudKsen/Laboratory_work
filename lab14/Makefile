targets = main.bin 
CC = clang
C_OPTS = -std=gnu11 -g -Wall -Wextra  -Wformat-security -Wfloat-equal -Wshadow -Wconversion -Wlogical-not-parentheses -Wnull-dereference -I./src src/lib.c

all: clean prep compile run

clean:
	rm -rf dist
prep:
	mkdir dist
compile: main1.bin main2.bin 
main1.bin: src/task1.c
	$(CC) $(C_OPTS) $< -o ./dist/$@
main2.bin: src/task2.c
	$(CC) $(C_OPTS) $< -o ./dist/$@

	

run: clean prep compile
	./dist/main1.bin
	./dist/main2.bin
	
doxygen:
	doxygen Doxyfile
format: #TODO

tidy: # TODO


