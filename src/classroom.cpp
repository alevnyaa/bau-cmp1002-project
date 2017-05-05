#include <iostream>
#include "classroom.h"
using namespace std;

vector<shared_ptr<classroom>> classroom::classrooms_ = vector<shared_ptr<classroom> >();
array<array<string, LESSON_NUM>, DAY_NUM> schedule_;
vector<exam> exams_ = vector<exam>();

classroom::classroom(ifstream& classroom_file){
/*  if(classroom_file.rdbuf()->in_avail() == 0){
    cout << "wtf ss  empty" << endl;
  }
  
  //classroom name
  char* classroom_name_c = new char[4];
  classroom_file.read(classroom_name_c, 4);
  string classroom_name(classroom_name_c, 4);
  delete[] classroom_name_c;

  //space between
  skipwsexceptnewline(classroom_file);

  //capacity keyword
  classroom_file.ignore(8);

  //capacity number
  ostringstream capacity_ss(ostringstream::ate);
  while(!isspace(classroom_file.peek())){
    string s;
    classroom_file >> s;
    capacity_ss << s;
  }

  string capacity_str = capacity_ss.str();
  cout << "Capacity_str is " << capacity_str << endl;
  capacity_ = stoi(capacity_str);
  cout << "Crashed yet? Nope." << endl;

  //skipws until newline
  skipallws(classroom_file);

  //is this necessary?
  for(auto day : schedule_){
    for(string hour : day){
      hour = "<empty>";
    }
  }

  //reading rest of lines to set schedule
  while(classroom_file.rdbuf()->in_avail()){
    //perhaps dec is necessary
    int schedule_day;
    schedule_day = classroom_file.get();
    while(classroom_file.peek() != '\n'){
      skipwsexceptnewline(classroom_file);
      int schedule_time;
      schedule_time = classroom_file.get();
      skipwsexceptnewline(classroom_file);
      schedule_[schedule_day][schedule_time] = "Lesson";
    }
  }

  classrooms_.push_back(shared_ptr<classroom>(this));*/
}

bool classroom::exists(string classroom_name){
//  for(auto cr: classroom::classrooms_){
//    if((*cr).classroom_name == classroom_name){
//      return true;
//    }
//  }
  return true;
}

//todo
classroom& classroom::get(string classroom_name){
  return *classrooms_[0];
}

const vector<shared_ptr<classroom> >& classroom::get_all(){
  return classrooms_;
}

//todo
classroom& classroom::get_free(string time, string day, int student_number){
  for(auto classroom : classrooms_){
  }
  return *classrooms_[0]; 
}

string classroom::print_free_classrooms_for_starting_time_and_day(string starting_time, string day){
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
