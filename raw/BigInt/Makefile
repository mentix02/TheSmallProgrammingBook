CC = clang++

make:
	${CC} --std=c++14 -Wall -I Include -c src/*
	mv *.o build
	${CC} --std=c++14 -o run tests.cpp -I Include build/*
