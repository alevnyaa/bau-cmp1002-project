#ifndef CLASSROOM_H 
#define CLASSROOM_H
#include <string>
#include <vector>
#include "Exam.h"

class Classroom{
  public:
    Classroom();
    Classroom(std::string name, int capacity, std::string class_file);
    std::string DisplaySchedule();

    static std::vector<Classroom> Classrooms;

    static bool Exists(std::string class_name);
    static Classroom Get(std::string class_name);

    static std::string GetFreeClassesForIntervalAndDay(std::string interval, std::string day);
    static std::string GetFreeTimesForClassAndDay(std::string class_name, std::string day);
    static std::string GetFreeDaysForClassAndInterval(std::string class_name, std::string interval);
  private:
    std::string class_name_;
    std::vector<Exam> exams_;
};
#endif
