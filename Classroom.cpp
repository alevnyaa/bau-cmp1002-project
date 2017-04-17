#include "Classroom.h"
using namespace std;

Classroom::Classroom(){
  return;
}

Classroom::Classroom(string name, int capacity, string class_file){
  return;
}

vector<Classroom> Classroom::classrooms;

bool Classroom::exists(string class_name){
  //for(vector<Classroom>::iterator it = Classrooms.begin(); it != Classrooms.end(); ++it) {
      /* std::cout << *it; ... */
  //  if
  //}else
  for(auto const& classroom: Classroom::classrooms) {
    if(classroom.class_name_ == class_name){
      return true;
    }
  }
  return false;
}

Classroom Classroom::get(string class_name){
  return Classroom();
}

string Classroom::get_free_classes_for_interval_and_day(string interval, string day){
  return "";
}

string Classroom::get_free_times_for_class_and_day(string class_name, string day){
  return "";
}

string Classroom::get_free_days_for_class_and_interval(string class_name, string interval){
  return "";
}

string Classroom::display_schedule(){
  return "";
}
