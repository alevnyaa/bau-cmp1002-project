#include <iostream>
#include "userinput.h"
#include "classroom.h"
#include "constants.h"
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

//todo is very different from rest, perhaps a restructure?
bool userinput::starting_time::try_parse(string starting_time){
  string hour_boilerplate;

  if(starting_time.length() == 5){
    hour_boilerplate = starting_time.substr(2, 3);
  }else if(starting_time.length() == 4){
    hour_boilerplate = starting_time.substr(1, 3);
  }else{
    return false;
  }
  
  if( hour_boilerplate[0] != ':'
      || hour_boilerplate[1] != '3'
      || hour_boilerplate[2] != '0'){
    return false;
  }

  if(starting_time.length() == 5){
    if(!isdigit(starting_time[0])
        || !isdigit(starting_time[1])){
      return false;
    }
  }else{
    if(!isdigit(starting_time[0])){
      return false;
    }
  }

  int cur_hour = 8;
  int hours[LESSON_NUM];
  for(int i=0; i<LESSON_NUM; i++){
    hours[i] = cur_hour;
    cur_hour += 2;
  }

  int hour_value;
  if(starting_time.length() == 5){
     hour_value = stoi(starting_time.substr(0,2));
  }else{
     hour_value = stoi(starting_time.substr(0,1));
  }

  for(int hour : hours){
    if(hour_value == hour){
      return true;
    }
  }

  return false;
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

//todo make it work by dynamically looking at classrooms_ in classroom or directory
bool userinput::classroom_name::try_parse(string classroom_name){
  bool valid_classroom_name = true;
  for(auto & c: classroom_name) c = toupper(c);
    if(classroom_name != "D301" 
        && classroom_name != "D302"
        && classroom_name != "D303"
        && classroom_name != "D304"
        && classroom_name != "D306"
        && classroom_name != "D308"
        && classroom_name != "D501"
        && classroom_name != "D502"
        && classroom_name != "D504"
        && classroom_name != "D505"
        && classroom_name != "D506"){
      valid_classroom_name = false;
    }
  return valid_classroom_name;
}

string userinput::day::get(){
  bool valid_day = false;
  string day;
  while(!valid_day){
    cout << "Please enter the day (e.g. Mon or Sun or 1 or 7): ";
    cin >> day;
    if(try_parse(day)){
      valid_day = true;
    }
  }
  return day;
}

//todo work with array of options instead of && chain
bool userinput::day::try_parse(string day){
  bool valid_day = true;
  for (auto & c: day) c = toupper(c);
  if(day != "MON"
      && day != "TUE"
      && day != "WED"
      && day != "THU"
      && day != "FRI"
      && day != "SAT"
      && day != "SUN"
      && day != "1"
      && day != "2"
      && day != "3"
      && day != "4"
      && day != "5"
      && day != "6"
      && day != "7") 
  	valid_day = false;
  return valid_day;
}

string userinput::course_name::get(){
  bool valid_course_name = false;
  string course_name;
  while(!valid_course_name){
    cout << "Please enter the course name (e.g. MAT1051 or CMP1004): ";
    cin >> course_name;
    if(try_parse(course_name)){
      valid_course_name = true;
    }
  }
  return course_name;
}

//todo work with utf8 instead of ascii
bool userinput::course_name::try_parse(string course_name){
  bool valid_course_name = true;
  for (auto & z: course_name) z = toupper (z);
  for ( int i = 0 ; i<3; i++){
    if(!(course_name[i] < 91 && course_name[i] > 64)){
     valid_course_name = false;
    }
  }
  for (int i = 3; i<7; i++){
    if(!(course_name[i]< 58 && course_name[i]> 47)){
      valid_course_name = false;
    }
  }
  return valid_course_name;
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
