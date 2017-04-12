#include <iostream>

using namespace std;

namespace UserInput{
  string GetInterval(){
    bool valid_interval = false;
    while(!valid_interval){
      cout << "Please enter time interval (e.g. 7:30-13:30 or 16:30-18:20): ";
      string interval;
      cin >> interval;
      if(TryParseInterval(interval){
        valid_interval = true;
      }
    }
    return interval;
  }

  string GetDay(){
    bool valid_day = false;
    while(!valid_day){
      cout << "Please enter day (e.g. Mon or Fri or 1 or 5): ";
      string day;
      cin >> day;
      if(TryParseDay(day){
        valid_day = true;
      }
    }
    return day;
  }

  string GetClassName(){
    bool valid_classroom = false;
    while(!valid_classroom){
      cout << "Please enter class name (e.g. D503 or D504): ";
      string class_name;
      cin >> class_name;
      if(Classroom.exists(class_name)){
        valid_classroom = true;
      }
    }
    return class_name;
  }
}

void DisplayMenu(){
  cout << "1. Create Exam" << endl;
  cout << "2. Show schedule for class" << endl;
  cout << "3. List available classes for time and day" << endl;
  cout << "4. List available hours for class at day" << endl;
  cout << "5. List available days for class at time interval" << endl;
  cout << "0. Exit" << endl;
}

void CreateExam(){

}

int main(){
  bool exit = false;
  //iniatialize classrooms from file
  while(!exit){
    DisplayMenu();
    string input;
    cin >> input;
    switch(input){
      case "1":
        CreateExam();
        break;
      case "2":
        string class_name = UserInput.GetClassroom();
        if(Classroom.exists(class_name)){
          Classroom.get(class_name).DisplaySchedule();
        }else{
          cout << "There is no such class" << endl;
        }
        break;
      case "3":
        string interval = UserInput.GetInterval();
        string day = UserInput.GetDay();
        Classroom.GetFreeClassesForIntervalAndDate(interval, day);
        break;
      case "4":
        string class_name = UserInput.GetClassroom();
        string day = UserInput.GetDay();
        Classroom.GetFreeHoursForClassAndDay(class_name, day);
        break;
      case "5":
        string class_name = UserInput.GetClassroom();
        string interval = UserInput.GetInterval();
        Classroom.GetFreeDaysForClassAndInterval(class_name, interval);
        break;
      case "0":
        exit = true;
        break;
      default: 
        cout << "Your input does not match any of the options." << endl;
    }
  }
}
