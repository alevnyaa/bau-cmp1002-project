#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <queue>
#include <boost/filesystem.hpp>
#include "userinput.h"
#include "exam.h"
#include "classroom.h"
using namespace std;

void display_menu(){
  cout << "1. Create Exam" << endl;
  cout << "2. Show schedule for class" << endl;
  cout << "3. List available classes for time and day" << endl;
  cout << "4. List available hours for class at day" << endl;
  cout << "5. List available days for class at starting time" << endl;
  cout << "0. Exit" << endl;
}

using boost::filesystem::directory_entry;
using boost::filesystem::directory_iterator;
using boost::filesystem::path;

int initialize_classes(){
  path p = "files/classrooms/";
  //files of lines of queues of chars
  //vector of vector of queue of char
  vector<vector<queue<char> > > class_files;
  if(exists(p)){
    for (directory_entry& x : directory_iterator(p)){
      vector<queue<char> > cur_file;

      ifstream file(x.path().filename().string());
      
      queue<char> cur_line;
      char ch;
      while (file >> noskipws >> ch) {
        if(!isspace(ch)){
          cur_line.push(ch);
        }else if(ch == '\n'){
          cur_file.push_back(cur_line);
          cur_line = queue<char>();
        }
      }
      class_files.push_back(cur_file); 
      cur_file = vector<queue<char> >();
      file.close();
    }
  }else{
    cout << "Classroom files are missing!" << endl;
    return 1;
  }
  for(auto cf : class_files){
    new classroom(cf);
  }
  return 0;
}

void create_exam(){
  string course_name = userinput::course_name::get();
  string classroom_name = userinput::classroom_name::get();
  string day = userinput::day::get();
  string time = userinput::starting_time::get();
  cout << "Please enter number of student: ";
  int student_number;
  cin >> student_number;
  exam new_exam(course_name, classroom_name, day, time, student_number);
  string exam_out = "Test string\nThis is a test!";
  ofstream out("examout.txt");
  out << exam_out;
  out.close();
}

int main(){
  if(initialize_classes()==1){
    cout << "Can't find classroom setup texts in \"files/\" directory to initialize classrooms" << endl;
    cout << "Terminating..." << endl;
    return 1; 
  };
  bool exit = false;
  while(!exit){
    display_menu();
    int choice = userinput::get_int();
    switch(choice){
      case 1:{
        create_exam();
      }break;
      case 2:{
        string classroom_name = userinput::classroom_name::get();
        if(classroom::exists(classroom_name)){
          //classroom::get(classroom_name).print_schedule();
        }else{
          cout << "There is no such class" << endl;
        }
      }break;
      case 3:{
        string starting_time = userinput::starting_time::get();
        string day = userinput::day::get();
        classroom::get_free_classes_for_starting_time(starting_time, day);
      }break;
      case 4:{
        string classroom_name = userinput::classroom_name::get();
        string day = userinput::day::get();
        classroom::get_free_times_for_class_and_day(classroom_name, day);
      }break;
      case 5:{
        string classroom_name = userinput::classroom_name::get();
        string starting_time = userinput::starting_time::get();
        classroom::get_free_days_for_class_and_starting_time(classroom_name, starting_time);
      }break;
      case 0:{
        exit = true;
      }break;
      default: 
        cout << "Your input does not match any operation" << endl;
    }
  }
}
