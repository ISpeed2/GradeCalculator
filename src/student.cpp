#include "student.h"
#include <algorithm>
#include <numeric>
#include <sstream>
#include <stdexcept>

Student::Student(const std::string& name) : name_(name) {}

Student::Student(const std::string& name, const std::vector<int>& grades)
    : name_(name), grades_(grades) {}

std::string Student::getName() const {
    return name_;
}

const std::vector<int>& Student::getGrades() const {
    return grades_;
}

int Student::getGradeCount() const {
    return static_cast<int>(grades_.size());
}

void Student::setName(const std::string& name) {
    name_ = name;
}

void Student::addGrade(int grade) {
    if (grade < 0 || grade > 100) {
        throw std::invalid_argument("Оценка должна быть от 0 до 100");
    }
    grades_.push_back(grade);
}

void Student::removeLastGrade() {
    if (!grades_.empty()) {
        grades_.pop_back();
    }
}

void Student::clearGrades() {
    grades_.clear();
}

double Student::getAverage() const {
    if (grades_.empty()) return 0.0;
    double sum = std::accumulate(grades_.begin(), grades_.end(), 0.0);
    return sum / grades_.size();
}

int Student::getMinGrade() const {
    if (grades_.empty()) return 0;
    return *std::min_element(grades_.begin(), grades_.end());
}

int Student::getMaxGrade() const {
    if (grades_.empty()) return 0;
    return *std::max_element(grades_.begin(), grades_.end());
}

double Student::getMedian() const {
    if (grades_.empty()) return 0.0;

    std::vector<int> sorted = grades_;
    std::sort(sorted.begin(), sorted.end());

    size_t n = sorted.size();
    if (n % 2 == 0) {
        return (sorted[n / 2 - 1] + sorted[n / 2]) / 2.0;
    } else {
        return sorted[n / 2];
    }
}

std::string Student::toString() const {
    std::ostringstream oss;
    oss << name_ << " | Оценки: ";
    if (grades_.empty()) {
        oss << "(нет)";
    } else {
        for (size_t i = 0; i < grades_.size(); ++i) {
            if (i > 0) oss << ", ";
            oss << grades_[i];
        }
        oss << " | Средний: " << getAverage();
    }
    return oss.str();
}
