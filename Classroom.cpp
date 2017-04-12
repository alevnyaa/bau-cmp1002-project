#include "Classroom.h"
using namespace std;

Classroom::Classroom(){
  return;
}

Classroom::Classroom(string name, int capacity, string class_file){
  return;
}

bool Classroom::Exists(string class_name){
  return true;
}

Classroom Classroom::Get(string class_name){
  return Classroom();
}

string Classroom::GetFreeClassesForIntervalAndDay(string interval, string day){
  return "";
}

string Classroom::GetFreeTimesForClassAndDay(string class_name, string day){
  return "";
}

string Classroom::GetFreeDaysForClassAndInterval(string class_name, string interval){
  return "";
}

string Classroom::DisplaySchedule(){
  return "";
}
