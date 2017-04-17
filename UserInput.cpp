#include <iostream>
#include "UserInput.h"
#include "Classroom.h"
using namespace std;

string UserInput::GetInterval(){
  bool valid_interval = false;
  string interval;
  while(!valid_interval){
    cout << "Please enter time interval (e.g. 7:30-13:30 or 16:30-18:20): ";
    cin >> interval;
    if(TryParseInterval(interval)){
      valid_interval = true;
    }
  }
  return interval;
}

string UserInput::GetClassName(){
  bool valid_classroom = false;
  string class_name;
  while(!valid_classroom){
    cout << "Please enter class name (e.g. D503 or D504): ";
    cin >> class_name;
    if(Classroom::Exists(class_name)){
      valid_classroom = true;
    }else{
      cout << "No such class exists" << endl;
    }
  }
  return class_name;
}

string UserInput::GetDay(){
  bool valid_day = false;
  string day;
  while(!valid_day){
    cout << "Please enter day (e.g. Mon or Fri or 1 or 5): ";
    cin >> day;
    if(TryParseDay(day)){
      valid_day = true;
    }
  }
  return day;
}

string UserInput::GetTime(){
  bool valid_time = false;
  string time;
  while(!valid_time){
    cout << "Please enter exam time (e.g. 14:30 or 16:30): ";
    cin >> time;
    if(TryParseTime(time)){
      valid_time = true;
    }
  }
  return time;
}

string UserInput::GetCourseName(){
  bool valid_course_name = false;
  string course_name;
  while(!valid_course_name){
    cout << "Please enter exam time (e.g. 14:30 or 16:30): ";
    cin >> course_name;
    if(TryParseCourseName(course_name)){
      valid_course_name = true;
    }
  }
  return course_name;
}

int UserInput::GetInt(){
  int i;
  cin >> i;
  return i;
}

bool UserInput::TryParseInterval(string interval){
  // 7:30-13:30 or 16:30-18:20
  return true;
}

bool UserInput::TryParseClassName(string class_name){
  return true;
}

bool UserInput::TryParseDay(string day){
  return true;
}

bool UserInput::TryParseTime(string time){
  return true;
}

bool UserInput::TryParseCourseName(string course_name){
  return true;
}

