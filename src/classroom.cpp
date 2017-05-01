#include "classroom.h"
using namespace std;

classroom::classroom(){
  return;
}

classroom::classroom(string class_file){
  return;
}

bool classroom::exists(string class_name){
//  for(auto cr: classrooms_){
//    if((*cr).class_name_ == class_name){
//      return true;
//    }
//  }
  return false;
}

classroom classroom::get(string class_name){
  return classroom();
}

void classroom::add_from_file(vector<char> class_file){
//  shared_ptr<classroom> ptr(new classroom(class_file));
//  classrooms_.push_back(ptr);
  return;
}

string classroom::get_free_classes_for_interval_and_day(string interval, string day){
  return "";
}

string classroom::get_free_times_for_class_and_day(string class_name, string day){
  return "";
}

string classroom::get_free_days_for_class_and_interval(string class_name, string interval){
  return "";
}

string classroom::print_schedule(){
  string prnt_txt = "\t\tMon\tTue\tWed\tThu\tFri\tSat\tSun";
  int cur_hour = 8;
  for(array<string, LESSON_NUM> time : schedules_){
    prnt_txt += to_string(cur_hour) + ":30-" + to_string(cur_hour+2) + ":20";
    for(string event : time){
      prnt_txt += "\t" + event;
    }
  }
  return "";
}
