editor.o: main.o libexameditor.a
	g++ -Wall -o editor.o main.o libexameditor.a -lboost_system -lboost_filesystem

libexameditor.a: classroom.o exam.o userinput.o
	ar rvs libexameditor.a classroom.o exam.o userinput.o

main.o: main.cpp classroom.h exam.h userinput.h
	g++ -Wall -o main.o main.cpp -c

classroom.o: classroom.cpp classroom.h
	g++ -Wall -o classroom.o classroom.cpp -c

exam.o: exam.cpp exam.h
	g++ -Wall -o exam.o exam.cpp -c

userinput.o: userinput.cpp userinput.h classroom.h
	g++ -Wall -o userinput.o userinput.cpp -c

clean: 
	rm editor.o main.o libexameditor.a classroom.o exam.o userinput.o
