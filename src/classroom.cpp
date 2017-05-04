#include <iostream>
#include "classroom.h"
using namespace std;

vector<shared_ptr<classroom>> classroom::classrooms_ = vector<shared_ptr<classroom> >();
array<array<string, LESSON_NUM>, DAY_NUM> schedule_;
vector<exam> exams_ = vector<exam>();

classroom::classroom(queue<queue<char> > classroom_file){
  cout << "No crash yet" << endl;

  if(classroom_file.empty()){
    cout << "wtf" << endl;
  }

  if(classroom_file.front().empty()){
    cout << "wtf" << endl;
  }
  //why does this line crash?
  queue<char> first_line = classroom_file.front();

  cout << "No crash yet" << endl;

  classroom_file.pop();

  cout << "No crash yet" << endl;

  string classroom_name = "";
  for(int i=0; i<4; i++){
    classroom_name += first_line.front();
    first_line.pop();
  }
  classroom_name = classroom_name;

  cout << "No crash yet" << endl;

  for(int i=0; i<8; i++){
    first_line.pop();
  }

  string capacity_str = "";
  while(!first_line.empty()){
    capacity_str += first_line.front();
    first_line.pop();
  }
  
  capacity_ = stoi(capacity_str);

  classroom_file.pop();

  for(auto day : schedule_){
    for(string hour : day){
      hour = "";
    }
  }

  while(!classroom_file.empty()){
    int schedule_day;
    queue<char> current_line = classroom_file.front();
    classroom_file.pop();
    schedule_day = current_line.front();
    current_line.pop();

    while(!current_line.empty()){
      int schedule_hour = current_line.front();
      current_line.pop();
      schedule_[schedule_day][schedule_hour] = "Class";
    }
  }

  classroom::classrooms_.push_back(shared_ptr<classroom>(this));
}

bool classroom::exists(string classroom_name){
//  for(auto cr: classroom::classrooms_){
//    if((*cr).classroom_name == classroom_name){
//      return true;
//    }
//  }
  return true;
}

//classroom classroom::get(string classroom_name){
//  return classroom();
//}

vector<shared_ptr<classroom> > classroom::get_all(){
  return classroom::classrooms_;
}

string classroom::get_free(string time, string day, int student_number){
  for(auto classroom : classroom::classrooms_){
  }
  return ""; 
}

string classroom::print_free_classrooms_for_starting_time(string starting_time, string day){
  return "";
}

string classroom::print_free_times_for_classroom_and_day(string classroom_name, string day){
  return "";
}

string classroom::print_free_days_for_classroom_and_starting_time(string classroom_name, string starting_time){
  return "";
}

string classroom::get_name(){
  return classroom_name_;
}

string classroom::print_schedule(){
  string prnt_txt = "\t\tMon\tTue\tWed\tThu\tFri\tSat\tSun";
  int cur_hour = 8;
  for(auto time : schedule_){
    prnt_txt += to_string(cur_hour) + ":30-" + to_string(cur_hour+2) + ":20";
    for(string event : time){
      prnt_txt += "\t" + event;
    }
  }
  return "";
}
