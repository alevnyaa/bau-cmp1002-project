out.o: main.o Classroom.o Exam.o UserInput.o
	g++ -Wall -o output.o main.o Classroom.o Exam.o UserInput.o

main.o: main.cpp Classroom.h Exam.h UserInput.h
	g++ -Wall -o main.o main.cpp -c

Classroom.o: Classroom.cpp Classroom.h
	g++ -Wall -o Classroom.o Classroom.cpp -c

Exam.o: Exam.cpp Exam.h
	g++ -Wall -o Exam.o Exam.cpp -c

UserInput.o: UserInput.cpp UserInput.h Classroom.h
	g++ -Wall -o UserInput.o UserInput.cpp -c
