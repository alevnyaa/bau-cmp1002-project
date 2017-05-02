#include <iostream>
#include "userinput.h"
#include "classroom.h"
using namespace std;

string userinput::starting_time::get(){
  bool valid_starting_time = false;
  string starting_time;
  while(!valid_starting_time){
    cout << "Please enter starting time (e.g. 8:30 or 16:30): ";
    cin >> starting_time;
    if(try_parse(starting_time)){
      valid_starting_time = true;
    }
  }
  return parse(starting_time);
}
//have to check for class existence too
string userinput::classroom_name::get(){
  string classroom_name;
  bool valid_classroom = false;
  while(!valid_classroom){
    bool valid_classroom_name = false;
    string classroom_name;
    while(!valid_classroom_name){
      cout << "Please enter a classroom name (e.g. D301 or D505): ";
      cin >> classroom_name;
      if(try_parse(classroom_name)){
        valid_classroom_name = true;
      }
  }
  return parse(classroom_name);
  }
}
//todo
string userinput::day::get(){
  bool valid_day = false;
  string day;
  while(!valid_day){
    cout << "Please enter a classroom name (e.g. D301 or D505): ";
    cin >> day;
    if(try_parse(day)){
      valid_day = true;
    }
  }
  return parse(day);
}

string userinput::course_name::get(){
  bool valid_course_name = false;
  string course_name;
  while(!valid_course_name){
    cout << "Please enter a classroom name (e.g. D301 or D505): ";
    cin >> course_name;
    if(try_parse(course_name)){
      valid_course_name = true;
    }
  }
  return parse(course_name);
}
