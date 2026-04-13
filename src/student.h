#ifndef STUDENT_H
#define STUDENT_H

#include <string>
#include <vector>

/**
 * @brief Класс, представляющий студента с набором оценок.
 */
class Student {
public:
    Student() = default;
    explicit Student(const std::string& name);
    Student(const std::string& name, const std::vector<int>& grades);

    // Геттеры
    std::string getName() const;
    const std::vector<int>& getGrades() const;
    int getGradeCount() const;

    // Сеттеры
    void setName(const std::string& name);

    // Работа с оценками
    void addGrade(int grade);
    void removeLastGrade();
    void clearGrades();

    // Расчёты
    double getAverage() const;
    int getMinGrade() const;
    int getMaxGrade() const;
    double getMedian() const;

    // Вывод
    std::string toString() const;

private:
    std::string name_;
    std::vector<int> grades_;
};

#endif // STUDENT_H
