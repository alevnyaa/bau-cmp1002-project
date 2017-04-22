#ifndef CLASSROOM_H 
#define CLASSROOM_H
#include <string>
#include <vector>
#include "exam.h"
class classroom{
  public:
    classroom();
    classroom(std::string name, int capacity, std::string class_file);
    std::string print_schedule();

    static std::vector<classroom> classrooms;

    static bool exists(std::string class_name);
    static classroom get(std::string class_name);

    static std::string get_free_classes_for_interval_and_day(std::string interval, std::string day);
    static std::string get_free_times_for_class_and_day(std::string class_name, std::string day);
    static std::string get_free_days_for_class_and_interval(std::string class_name, std::string interval);
  private:
    std::string class_name_;
    std::vector<exam> exams_;
};
#endif
