#ifndef CLASSROOM_H 
#define CLASSROOM_H
#include <string>
#include <array>
#include <vector>
#include <memory>
#include <queue>
#include "exam.h"
const int DAY_NUM = 7;
const int LESSON_NUM = 7;

class classroom{
  public:
    classroom(std::vector<std::queue<char> > class_file);

    static bool exists(std::string class_name);
    static classroom get(std::string class_name);

    std::string print_schedule();

    static std::string get_free_classes_for_starting_time(std::string starting_time, std::string day);
    static std::string get_free_times_for_class_and_day(std::string class_name, std::string day);
    static std::string get_free_days_for_class_and_starting_time(std::string class_name, std::string starting_time);
  private:
    static std::vector<std::shared_ptr<classroom>> classrooms_;

    std::string class_name_;
    std::array<std::array<std::string, LESSON_NUM>, DAY_NUM> schedules_;
    std::vector<exam> exams_;
};
#endif
