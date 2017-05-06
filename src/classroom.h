#ifndef CLASSROOM_H 
#define CLASSROOM_H
#include <string>
#include <vector>
#include <memory>
#include <queue>
#include <sstream>
#include "exam.h"
#include "constants.h"
class classroom;

typedef std::shared_ptr<classroom> classroom_ptr;

class classroom{
  public:
    static bool exists(std::string classroom_name);
    static classroom_ptr get(std::string classroom_name);
    static classroom_ptr get_free(int time, int day, int student_number);
    static const std::vector<classroom_ptr>& get_all();

    static std::string print_free_classrooms_for_starting_time_and_day(int starting_time, int day);
    static std::string print_free_times_for_classroom_and_day(std::string classroom_name, int day);
    static std::string print_free_days_for_classroom_and_starting_time(std::string classroom_name, int starting_time);

    classroom(std::ifstream& infile);

    std::string get_name();
    int get_capacity();
    std::vector<std::vector<std::string> >& get_schedule();
    std::string print_schedule();
  private:
    static std::vector<classroom_ptr> classrooms_;

    std::string classroom_name_;
    std::vector<std::vector<std::string> > schedule_;
    int capacity_;
    std::vector<exam> exams_;
};
#endif
