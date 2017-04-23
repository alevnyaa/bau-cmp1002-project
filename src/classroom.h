#ifndef CLASSROOM_H 
#define CLASSROOM_H
#include <string>
#include <array>
#include <vector>
#include <memory>
#include "exam.h"
const int DAY_NUM = 7;
const int LESSON_NUM = 7;

class classroom{
  public:
    classroom();
    classroom(std::string class_file);

    static bool exists(std::string class_name);
    static classroom get(std::string class_name);

    static void add_from_file(std::string class_file);

    std::string print_schedule();

    static std::string get_free_classes_for_interval_and_day(std::string interval, std::string day);
    static std::string get_free_times_for_class_and_day(std::string class_name, std::string day);
    static std::string get_free_days_for_class_and_interval(std::string class_name, std::string interval);
  private:
    std::string class_name_;
    std::array<std::array<std::string, LESSON_NUM>, DAY_NUM> schedules_;
    std::vector<exam> exams_;
    static std::vector<std::shared_ptr<classroom>> classrooms_;
};
#endif
