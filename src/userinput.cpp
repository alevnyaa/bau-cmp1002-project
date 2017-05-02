#include <iostream>
#include "userinput.h"
#include "classroom.h"
using namespace std;

string userinput::starting_time::get(){
  bool valid_starting_time = false;
  string starting_time;
  while(!valid_starting_time){
    cout << "Please enter the starting time (e.g. 8:30 or 16:30): ";
    cin >> starting_time;
    if(try_parse(starting_time)){
      valid_starting_time = true;
    }
  }
  return starting_time;
}

//todo
bool userinput::starting_time::try_parse(string starting_time){
  return true;
}

string userinput::classroom_name::get(){
  string classroom_name = "";
  bool valid_classroom = false;
  while(!valid_classroom){
    bool valid_classroom_name = false;
    string cur_cr;
    while(!valid_classroom_name){
      cout << "Please enter the classroom name (e.g. D301 or D505): ";
      cin >> cur_cr;
      if(try_parse(cur_cr)){
        valid_classroom_name = true;
        classroom_name = cur_cr;
      }
    }
    if(classroom_name != ""){
      if(classroom::exists(classroom_name)){
        valid_classroom = true;
      }
    }
  }
  return classroom_name;
}

//todo
bool userinput::classroom_name::try_parse(std::string classroom_name){
  return true;
}

string userinput::day::get(){
  bool valid_day = false;
  string day;
  while(!valid_day){
<<<<<<< HEAD
    cout << "Please enter the day (e.g. Mon or Sun or 1 or 7): ";
=======
    cout << "Please enter a day (e.g. Mon or Sun or 1 or 7): ";
>>>>>>> 154803cf73c1d53b107aaa25b3af69eceffa5044
    cin >> day;
    if(try_parse(day)){
      valid_day = true;
    }
  }
  return day;
}

//todo
bool userinput::day::try_parse(string day){
  return true;
}

string userinput::course_name::get(){
  bool valid_course_name = false;
  string course_name;
  while(!valid_course_name){
<<<<<<< HEAD
    cout << "Please enter the course name (e.g. MAT1051 or CMP1004): ";
=======
    cout << "Please enter a course name (e.g. MAT1051 or CMP1004): ";
>>>>>>> 154803cf73c1d53b107aaa25b3af69eceffa5044
    cin >> course_name;
    if(try_parse(course_name)){
      valid_course_name = true;
    }
  }
  return course_name;
}

//todo
bool userinput::course_name::try_parse(string course_name){
  return true;
}

int userinput::get_int(){
  bool valid_int = false;
  int number;
  while(!valid_int){
    string num_str;
    int num;
    cin >> num_str;
    try{
      num = stoi(num_str);
      valid_int = true;
      number = num;
    }catch(invalid_argument){}
  }
  return number;
}
