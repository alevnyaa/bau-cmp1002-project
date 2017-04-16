#include <iostream>
#include <fstream>
#include <string>
#include <boost/filesystem.hpp>
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

using boost::filesystem::directory_entry;
using boost::filesystem::directory_iterator;
using boost::filesystem::path;

int InitializeClasses(){
  path p = "src/";
  vector<string> class_files;
  if(exists(p)){
    for (directory_entry& x : directory_iterator(p)){
      string cur_file;
      ifstream file(x.path().filename().string());
      while(getline(file, cur_file));
      class_files.push_back(cur_file); 
    }
  }else{
    return 1;
  }
return 0;
//work with class_files here
//to actually initialize the classrooms
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
  //in order to assign classes you have to decide what kind of
  //array you want to keep the classroom schedule in
  //perhaps a 2d bool array will do
  //but actually setting up interface ClassEvent
  //and adding Exams and Classes to it to fill it
  //and having nulls might work, not sure how well C++ handles nulls
  //write to file
  string exam_out = "Test string\nThis is a test!";
  ofstream out("examout.txt");
  out << exam_out;
  out.close();
}

int main(){
  if(InitializeClasses()==1){
    cout << "src/ directory and thus the classroom files are missing" << endl;
    cout << "Terminating..." << endl;
    return 1; 
  };
  bool exit = false;
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
