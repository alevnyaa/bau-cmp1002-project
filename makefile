CC := g++ -Wall -std=c++11
TARGET := bin/exameditor
LIB := -lboost_system -lboost_filesystem

SOURCES := $(shell find src -type f -name *.cpp)
OBJECTS := $(patsubst src/%,build/%,$(SOURCES:.cpp=.o))

$(TARGET): build/main.o build/libexameditor.a
	mkdir -p bin
	$(CC) -o $(TARGET) build/main.o build/libexameditor.a $(LIB)

build/libexameditor.a: build/classroom.o build/exam.o build/userinput.o
	mkdir -p build
	ar rvs build/libexameditor.a $^

build/main.o: src/main.cpp
	mkdir -p build
	$(CC) -o $@ $< -c

build/%.o: src/%.cpp src/%.h
	mkdir -p build
	$(CC) -o $@ $< -c

clean: 
	rm -r bin build
	
#build/classroom.o: src/classroom.cpp src/classroom.h
#	$(CC) -o $@ $< -c

#build/exam.o: src/exam.cpp src/exam.h
#	$(CC) -o $@ $< -c

#build/userinput.o: src/userinput.cpp src/userinput.h
#	$(CC) -o $@ $< -c
