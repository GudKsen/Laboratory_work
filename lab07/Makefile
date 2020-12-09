clean:
	rm -rf dist
prep:
	mkdir dist
compile: prep
	gcc src/task1.c -o dist/main1.bin -g
	
	gcc src/task1-6.c -o dist/main1-6.bin -g
	gcc src/task2-6.c -o dist/main2-6.bin -g
	gcc src/task3-6.c -o dist/main3-6.bin -g
	gcc src/task4-6.c -o dist/main4-6.bin -g
	gcc src/task5-6.c -o dist/main5-6.bin -g
	gcc src/task6-6.c -o dist/main6-6.bin -g
	
	gcc src/task1-5.c -o dist/main1-5.bin -g
	gcc src/task2-5.c -o dist/main2-5.bin -g
	gcc src/task3-5.c -o dist/main3-5.bin -g
	gcc src/task4-5.c -o dist/main4-5.bin -g
	gcc src/task5-5.c -o dist/main5-5.bin -g
	
	
all: 
	clean compile

doxygen:
	doxygen Doxyfile
