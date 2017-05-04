#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <queue>
#include <boost/filesystem.hpp>
#include "userinput.h"
#include "exam.h"
#include "classroom.h"
using namespace std;

//look at stackoverflow question
//change multiple layer queues into string streams
//work on sending by reference instead of copy

//std::ifstream in("myfile");
//
//std::stringstream buffer;
//buffer << in.rdbuf();
//
//std::string contents(buffer.str());

void display_menu(){
  cout << "1. Create Exam" << endl;
  cout << "2. Show schedule for classroom" << endl;
  cout << "3. List available classrooms for time and day" << endl;
  cout << "4. List available hours for classroom at day" << endl;
  cout << "5. List available days for classroom at starting time" << endl;
  cout << "0. Exit" << endl;
}

using boost::filesystem::directory_entry;
using boost::filesystem::directory_iterator;
using boost::filesystem::path;

int initialize_classrooms(){
  path p = "files/classrooms/";
  //files of lines of queues of chars
  //vector of vector of queue of char
  vector<queue<queue<char> > > classroom_files;
  if(exists(p)){
    for (directory_entry& x : directory_iterator(p)){
      queue<queue<char> > cur_file;

      ifstream file(x.path().filename().string());
      
      queue<char> cur_line;
      char ch;
      while (file >> noskipws >> ch) {
        if(!isspace(ch)){
          cur_line.push(ch);
        }else if(ch == '\n'){
          cur_file.push(cur_line);
          cur_line = queue<char>();
        }
      }
      classroom_files.push_back(cur_file); 
      cur_file = queue<queue<char> >();
      file.close();
    }
  }else{
    cout << "Classroom files are missing!" << endl;
    return 1;
  }
  cout << "Got all the way to classroom creation" << endl;
  int i = 1;
  for(auto cf : classroom_files){
    cout << "Number of loops: " << i << endl;
    i++;
    shared_ptr<classroom> cr = shared_ptr<classroom>(new classroom(cf));
  }
  cout << "Got past the classroom creation" << endl;
  return 0;
}

void create_exam(){
  string course_name = userinput::course_name::get();
  string day = userinput::day::get();
  string time = userinput::starting_time::get();
  cout << "Please enter number of students: ";
  int student_number;
  cin >> student_number;

  string classroom_name = classroom::get_free(day, time, student_number);
  exam new_exam(course_name, classroom_name, day, time, student_number);
  ofstream out("exam.txt");
  out << new_exam.print();
  out.close();
  cout << "Exam created! See exam.txt" << endl;
}

int main(){
  if(initialize_classrooms()==1){
    cout << "Can't find classroom setup texts in \"files/\" directory to initialize classrooms" << endl;
    cout << "Terminating..." << endl;
    return 1; 
  };
  vector<shared_ptr<classroom> > classrooms = classroom::get_all();
  for(auto cr : classrooms){
    cout << cr->get_name() << endl; 
  }
}

/*int main(){
  if(initialize_classrooms()==1){
    cout << "Can't find classroom setup texts in \"files/\" directory to initialize classrooms" << endl;
    cout << "Terminating..." << endl;
    return 1; 
  };
  bool exit = false;
  while(!exit){
    display_menu();
    cout << "Waiting for input: ";
    int choice = userinput::get_int();
    switch(choice){
      case 1:{
        create_exam();
      }break;
      case 2:{
        string classroom_name = userinput::classroom_name::get();
        if(classroom::exists(classroom_name)){
          //classroom::get(classroom_name).print_schedule();
        }else{
          cout << "There is no such classroom" << endl;
        }
      }break;
      case 3:{
        string starting_time = userinput::starting_time::get();
        string day = userinput::day::get();
        classroom::get_free_classrooms_for_starting_time(starting_time, day);
      }break;
      case 4:{
        string classroom_name = userinput::classroom_name::get();
        string day = userinput::day::get();
        classroom::get_free_times_for_classroom_and_day(classroom_name, day);
      }break;
      case 5:{
        string classroom_name = userinput::classroom_name::get();
        string starting_time = userinput::starting_time::get();
        classroom::get_free_days_for_classroom_and_starting_time(classroom_name, starting_time);
      }break;
      case 0:{
        exit = true;
      }break;
      default: 
        cout << "Your input does not match any operation" << endl;
    }
  }
}*/
