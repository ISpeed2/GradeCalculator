#ifndef GRADEBOOK_H
#define GRADEBOOK_H

#include "student.h"
#include <vector>
#include <string>
#include <optional>

/**
 * @brief Класс журнала оценок — управляет списком студентов.
 */
class GradeBook {
public:
    GradeBook() = default;

    // Управление студентами
    void addStudent(const std::string& name);
    bool removeStudent(const std::string& name);
    std::optional<Student*> findStudent(const std::string& name);
    const std::vector<Student>& getStudents() const;
    int getStudentCount() const;

    // Групповая статистика
    double getGroupAverage() const;
    std::string getBestStudent() const;
    std::string getWorstStudent() const;

    // Вывод
    void printAll() const;
    void printStudentReport(const std::string& name) const;
    void printGroupStatistics() const;

private:
    std::vector<Student> students_;
};

#endif // GRADEBOOK_H
