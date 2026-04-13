#include "filemanager.h"
#include <fstream>
#include <sstream>
#include <iostream>

bool FileManager::save(const GradeBook& gradebook, const std::string& filename) {
    std::ofstream file(filename);
    if (!file.is_open()) {
        std::cerr << "Ошибка: не удалось открыть файл для записи: " << filename << "\n";
        return false;
    }

    for (const auto& student : gradebook.getStudents()) {
        file << "STUDENT:" << student.getName() << "\n";
        file << "GRADES:";
        const auto& grades = student.getGrades();
        for (size_t i = 0; i < grades.size(); ++i) {
            if (i > 0) file << ",";
            file << grades[i];
        }
        file << "\n";
        file << "END\n";
    }

    file.close();
    return true;
}

bool FileManager::load(GradeBook& gradebook, const std::string& filename) {
    std::ifstream file(filename);
    if (!file.is_open()) {
        std::cerr << "Ошибка: не удалось открыть файл для чтения: " << filename << "\n";
        return false;
    }

    std::string line;
    std::string currentName;

    while (std::getline(file, line)) {
        if (line.substr(0, 8) == "STUDENT:") {
            currentName = line.substr(8);
            gradebook.addStudent(currentName);
        }
        else if (line.substr(0, 7) == "GRADES:" && !currentName.empty()) {
            std::string gradesStr = line.substr(7);
            if (!gradesStr.empty()) {
                std::istringstream ss(gradesStr);
                std::string token;
                auto studentOpt = gradebook.findStudent(currentName);
                if (studentOpt.has_value()) {
                    while (std::getline(ss, token, ',')) {
                        try {
                            int grade = std::stoi(token);
                            studentOpt.value()->addGrade(grade);
                        } catch (...) {
                            // Пропускаем некорректные оценки
                        }
                    }
                }
            }
        }
        else if (line == "END") {
            currentName.clear();
        }
    }

    file.close();
    return true;
}
