#include <iostream>
#include "userinput.h"
#include "classroom.h"
using namespace std;

string userinput::get_interval(){
  bool valid_interval = false;
  string interval;
  while(!valid_interval){
    cout << "Please enter time interval (e.g. 7:30-13:30 or 16:30-18:20): ";
    cin >> interval;
    if(try_parse_interval(interval)){
      valid_interval = true;
    }
  }
  return interval;
}

string userinput::get_class_name(){
  bool valid_classroom = false;
  string class_name;
  while(!valid_classroom){
    cout << "Please enter class name (e.g. D503 or D504): ";
    cin >> class_name;
    if(classroom::exists(class_name)){
      valid_classroom = true;
    }else{
      cout << "No such class exists" << endl;
    }
  }
  return class_name;
}

string userinput::get_day(){
  bool valid_day = false;
  string day;
  while(!valid_day){
    cout << "Please enter day (e.g. Mon or Fri or 1 or 5): ";
    cin >> day;
    if(try_parse_day(day)){
      valid_day = true;
    }
  }
  return day;
}

string userinput::get_time(){
  bool valid_time = false;
  string time;
  while(!valid_time){
    cout << "Please enter exam time (e.g. 14:30 or 16:30): ";
    cin >> time;
    if(try_parse_time(time)){
      valid_time = true;
    }
  }
  return time;
}

string userinput::get_course_name(){
  bool valid_course_name = false;
  string course_name;
  while(!valid_course_name){
    cout << "Please enter exam time (e.g. 14:30 or 16:30): ";
    cin >> course_name;
    if(try_parse_course_name(course_name)){
      valid_course_name = true;
    }
  }
  return course_name;
}

int userinput::get_int(){
  int i;
  cin >> i;
  return i;
}

bool userinput::try_parse_interval(string interval){
  // 7:30-13:30 or 16:30-18:20
  return true;
}

bool userinput::try_parse_class_name(string class_name){
  return true;
}

bool userinput::try_parse_day(string day){
  return true;
}

bool userinput::try_parse_time(string time){
  return true;
}

bool userinput::try_parse_course_name(string course_name){
  return true;
}

