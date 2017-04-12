#include <iostream>
#include <fstream>
#include <string>
#include "UserInput.h"
#include "Exam.h"
#include "Classroom.h"
using namespace std;

void DisplayMenu(){
  cout << "1. Create Exam" << endl;
  cout << "2. Show schedule for class" << endl;
  cout << "3. List available classes for time and day" << endl;
  cout << "4. List available hours for class at day" << endl;
  cout << "5. List available days for class at time interval" << endl;
  cout << "0. Exit" << endl;
}

void CreateExam(){
  string course_name = UserInput::GetCourseName();
  string day = UserInput::GetDay();
  string time = UserInput::GetTime();
  cout << "Please enter number of students: " << endl;
  int student_number;
  cin >> student_number;
  Exam newExam;
  //assign classes
  
  //write to file
  string toWrite = "Test string\nThis is a test!";
  ofstream out("examout.txt");
  out << toWrite;
  out.close();
}

int main(){
  bool exit = false;
  //iniatialize classrooms from file
  while(!exit){
    DisplayMenu();
    int choice = UserInput::GetInt();
    switch(choice){
      case 1:{
        CreateExam();
      }break;
      case 2:{
        string class_name = UserInput::GetClassName();
        if(Classroom::Exists(class_name)){
          Classroom::Get(class_name).DisplaySchedule();
        }else{
          cout << "There is no such class" << endl;
        }
      }break;
      case 3:{
        string interval = UserInput::GetInterval();
        string day = UserInput::GetDay();
        Classroom::GetFreeClassesForIntervalAndDay(interval, day);
      }break;
      case 4:{
        string class_name = UserInput::GetClassName();
        string day = UserInput::GetDay();
        Classroom::GetFreeTimesForClassAndDay(class_name, day);
      }break;
      case 5:{
        string class_name = UserInput::GetClassName();
        string interval = UserInput::GetInterval();
        Classroom::GetFreeDaysForClassAndInterval(class_name, interval);
      }break;
      case 0:{
        exit = true;
      }break;
      default: 
        cout << "Your input does not match any of the options." << endl;
    }
  }
}
