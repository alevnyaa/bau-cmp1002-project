#ifndef CLASSROOM_H 
#define CLASSROOM_H
#include <string>
#include <vector>
#include "Exam.h"

class Classroom{
  public:
    Classroom();
    Classroom(std::string name, int capacity, std::string class_file);
    std::string display_schedule();

    static std::vector<Classroom> classrooms;

    static bool exists(std::string class_name);
    static Classroom get(std::string class_name);

    static std::string get_free_classes_for_interval_and_day(std::string interval, std::string day);
    static std::string get_free_times_for_class_and_day(std::string class_name, std::string day);
    static std::string get_free_days_for_class_and_interval(std::string class_name, std::string interval);
  private:
    std::string class_name_;
    std::vector<Exam> exams_;
};
#endif
