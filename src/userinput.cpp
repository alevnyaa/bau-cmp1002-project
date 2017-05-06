#include <iostream>
#include "userinput.h"
#include "classroom.h"
#include "constants.h"

int userinput::starting_time::get(){
  bool valid_starting_time = false;
  std::string starting_time_str;
  while(!valid_starting_time){
    std::cout << "Please enter the starting time (e.g. 8:30 or 16:30): ";
    std::cin >> starting_time_str;
    if(try_parse(starting_time_str)){
      valid_starting_time = true;
    }
  }
  int starting_time;
  if(starting_time_str.length() == 4){
    starting_time = 0;
    // math would be((starting_time_str[0] - '0') - 8) / 2;
  }else{
    starting_time = (stoi(starting_time_str.substr(0.2)) - 8) / 2;
  }
  if(DEBUG) std::cout << "Starting time str: " << starting_time_str << " Int: " << starting_time << std::endl;
  return starting_time;
}

//todo is very different from rest, perhaps a restructure?
bool userinput::starting_time::try_parse(std::string starting_time){
  std::string hour_boilerplate;

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

std::string userinput::classroom_name::get(){
  std::string classroom_name;
  bool valid_classroom_name = false;
  while(!valid_classroom_name){
    std::cout << "Please enter the classroom name (e.g. D301 or D505): ";
    std::cin >> classroom_name;
    for(auto & c: classroom_name) c = toupper(c);
    if(try_parse(classroom_name)){
      valid_classroom_name = true;
    }
  }
  return classroom_name;
}

bool userinput::classroom_name::try_parse(std::string classroom_name){
  bool valid_classroom_name = false;
  if(classroom::exists(classroom_name)){
    valid_classroom_name = true;    
  }else{
    std::cout << "This classroom does not exist" << std::endl;
  }

  return valid_classroom_name;
}

int userinput::day::get(){
  bool valid_day = false;
  std::string day_str;
  while(!valid_day){
    std::cout << "Please enter the day (e.g. Mon or Sun or 1 or 7): ";
    std::cin >> day_str;
    if(try_parse(day_str)){
      valid_day = true;
    }
  }
  int day;
  if(day_str.length() == 1){
    day = day_str[0] - '0' - 1;
  }else{
    for(auto & c: day_str) c = toupper(c);
    if(day_str == "MON"){
      day = 0; 
    }else if(day_str == "TUE"){
      day = 1;   
    }else if(day_str == "WED"){
      day = 2;
    }else if(day_str == "THU"){
      day = 3;
    }else if(day_str == "FRI"){
      day = 4;
    }else if(day_str == "SAT"){
      day = 5;
    }else if(day_str == "SUN"){
      day = 6;
    }
  }
  if(DEBUG) std::cout << "DEBUG: Returning day num " << day << std::endl;
  return day;
}

//todo work with array of options instead of && chain
bool userinput::day::try_parse(std::string day){
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

std::string userinput::course_name::get(){
  bool valid_course_name = false;
  std::string course_name;
  while(!valid_course_name){
    std::cout << "Please enter the course name (e.g. MAT1051 or CMP1004): ";
    std::cin >> course_name;
    if(try_parse(course_name)){
      valid_course_name = true;
    }
  }
  return course_name;
}

//todo work with utf8 instead of ascii
bool userinput::course_name::try_parse(std::string course_name){
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
    std::string num_str;
    int num;
    std::cin >> num_str;
    try{
      num = stoi(num_str);
      valid_int = true;
      number = num;
    //catch statement empty?
    }catch(std::invalid_argument){}
  }
  return number;
}
