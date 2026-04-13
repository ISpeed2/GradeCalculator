#include "gradebook.h"
#include "utils.h"
#include <iostream>
#include <algorithm>
#include <iomanip>

void GradeBook::addStudent(const std::string& name) {
    // Проверяем, нет ли уже студента с таким именем
    for (const auto& s : students_) {
        if (s.getName() == name) {
            std::cout << "Студент \"" << name << "\" уже существует!\n";
            return;
        }
    }
    students_.emplace_back(name);
    std::cout << "Студент \"" << name << "\" добавлен.\n";
}

bool GradeBook::removeStudent(const std::string& name) {
    auto it = std::remove_if(students_.begin(), students_.end(),
        [&name](const Student& s) { return s.getName() == name; });

    if (it != students_.end()) {
        students_.erase(it, students_.end());
        return true;
    }
    return false;
}

std::optional<Student*> GradeBook::findStudent(const std::string& name) {
    for (auto& s : students_) {
        if (s.getName() == name) {
            return &s;
        }
    }
    return std::nullopt;
}

const std::vector<Student>& GradeBook::getStudents() const {
    return students_;
}

int GradeBook::getStudentCount() const {
    return static_cast<int>(students_.size());
}

double GradeBook::getGroupAverage() const {
    if (students_.empty()) return 0.0;

    double total = 0.0;
    int count = 0;
    for (const auto& s : students_) {
        if (s.getGradeCount() > 0) {
            total += s.getAverage();
            ++count;
        }
    }
    return count > 0 ? total / count : 0.0;
}

std::string GradeBook::getBestStudent() const {
    if (students_.empty()) return "";

    const Student* best = nullptr;
    for (const auto& s : students_) {
        if (s.getGradeCount() > 0) {
            if (!best || s.getAverage() > best->getAverage()) {
                best = &s;
            }
        }
    }
    return best ? best->getName() : "";
}

std::string GradeBook::getWorstStudent() const {
    if (students_.empty()) return "";

    const Student* worst = nullptr;
    for (const auto& s : students_) {
        if (s.getGradeCount() > 0) {
            if (!worst || s.getAverage() < worst->getAverage()) {
                worst = &s;
            }
        }
    }
    return worst ? worst->getName() : "";
}

void GradeBook::printAll() const {
    if (students_.empty()) {
        std::cout << "Журнал пуст.\n";
        return;
    }

    std::cout << "\n========== ЖУРНАЛ ОЦЕНОК ==========\n";
    std::cout << std::left << std::setw(20) << "Имя"
              << std::setw(30) << "Оценки"
              << std::setw(10) << "Средний"
              << std::setw(10) << "Буква" << "\n";
    std::cout << std::string(70, '-') << "\n";

    for (const auto& s : students_) {
        std::string gradesStr;
        for (size_t i = 0; i < s.getGrades().size(); ++i) {
            if (i > 0) gradesStr += ", ";
            gradesStr += std::to_string(s.getGrades()[i]);
        }
        if (gradesStr.empty()) gradesStr = "(нет)";

        double avg = s.getAverage();
        std::cout << std::left << std::setw(20) << s.getName()
                  << std::setw(30) << gradesStr
                  << std::fixed << std::setprecision(1)
                  << std::setw(10) << avg
                  << std::setw(10) << Utils::toLetterGrade(avg) << "\n";
    }
    std::cout << "====================================\n";
}

void GradeBook::printStudentReport(const std::string& name) const {
    for (const auto& s : students_) {
        if (s.getName() == name) {
            std::cout << "\n--- Отчёт по студенту: " << name << " ---\n";
            if (s.getGradeCount() == 0) {
                std::cout << "Оценок пока нет.\n";
                return;
            }
            std::cout << "Количество оценок: " << s.getGradeCount() << "\n";
            std::cout << "Средний балл:      " << std::fixed << std::setprecision(1) << s.getAverage() << "\n";
            std::cout << "Минимум:           " << s.getMinGrade() << "\n";
            std::cout << "Максимум:          " << s.getMaxGrade() << "\n";
            std::cout << "Медиана:           " << s.getMedian() << "\n";
            std::cout << "Буквенная оценка:  " << Utils::toLetterGrade(s.getAverage()) << "\n";
            std::cout << "GPA:               " << std::fixed << std::setprecision(2) << Utils::toGPA(s.getAverage()) << "\n";
            std::cout << "-----------------------------------\n";
            return;
        }
    }
    std::cout << "Студент \"" << name << "\" не найден.\n";
}

void GradeBook::printGroupStatistics() const {
    if (students_.empty()) {
        std::cout << "Журнал пуст.\n";
        return;
    }

    std::cout << "\n======= СТАТИСТИКА ГРУППЫ =======\n";
    std::cout << "Всего студентов:     " << getStudentCount() << "\n";
    std::cout << "Средний балл группы: " << std::fixed << std::setprecision(1)
              << getGroupAverage() << "\n";

    std::string best = getBestStudent();
    std::string worst = getWorstStudent();
    if (!best.empty())
        std::cout << "Лучший студент:      " << best << "\n";
    if (!worst.empty())
        std::cout << "Худший студент:      " << worst << "\n";
    std::cout << "=================================\n";
}
