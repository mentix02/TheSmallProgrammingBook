CC = clang++

make:
	${CC} -Wall -I Include -c src/*
	mv *.o build
	${CC} -o run tests.cpp -I Include build/*
