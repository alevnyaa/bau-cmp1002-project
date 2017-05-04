#ifndef CLASSROOM_H 
#define CLASSROOM_H
#include <string>
#include <array>
#include <vector>
#include <memory>
#include <queue>
#include <sstream>
#include "exam.h"
#include "constants.h"

class classroom{
  public:
    classroom(const std::stringstream& classroom_file);

    static bool exists(std::string classroom_name);
    static classroom get(std::string classroom_name);
    static std::vector<std::shared_ptr<classroom> > get_all();

    std::string get_name();
    std::string print_schedule();

    void skipallws(std::stringstream& ss);
    void skipwsexceptnewline(std::stringstream& ss);

    static std::string get_free(std::string time, std::string day, int student_number);

    static std::string print_free_classrooms_for_starting_time(std::string starting_time, std::string day);
    static std::string print_free_times_for_classroom_and_day(std::string classroom_name, std::string day);
    static std::string print_free_days_for_classroom_and_starting_time(std::string classroom_name, std::string starting_time);
  private:
    static std::vector<std::shared_ptr<classroom>> classrooms_;

    std::string classroom_name_;
    std::array<std::array<std::string, LESSON_NUM>, DAY_NUM> schedule_;
    int capacity_;
    std::vector<exam> exams_;
};
#endif
