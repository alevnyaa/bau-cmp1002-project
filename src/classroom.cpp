#include "classroom.h"
using namespace std;

classroom::classroom(){
  return;
}

classroom::classroom(string name, int capacity, string class_file){
  return;
}

vector<classroom> classroom::classrooms;

bool classroom::exists(string class_name){
  //for(vector<classroom>::iterator it = classrooms.begin(); it != classrooms.end(); ++it) {
      /* std::cout << *it; ... */
  //  if
  //}else
  for(auto const& classroom: classroom::classrooms) {
    if(classroom.class_name_ == class_name){
      return true;
    }
  }
  return false;
}

classroom classroom::get(string class_name){
  return classroom();
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
  return "";
}
