#include "gradebook.h"
#include "filemanager.h"
#include "utils.h"
#include <iostream>
#include <string>

const std::string DATA_FILE = "gradebook.dat";

void showMenu() {
    std::cout << "\n╔══════════════════════════════════════╗\n";
    std::cout << "║     КАЛЬКУЛЯТОР ОЦЕНОК v1.0          ║\n";
    std::cout << "╠══════════════════════════════════════╣\n";
    std::cout << "║  1. Добавить студента                ║\n";
    std::cout << "║  2. Добавить оценку студенту         ║\n";
    std::cout << "║  3. Показать всех студентов           ║\n";
    std::cout << "║  4. Отчёт по студенту                ║\n";
    std::cout << "║  5. Статистика группы                ║\n";
    std::cout << "║  6. Удалить студента                 ║\n";
    std::cout << "║  7. Сохранить данные                 ║\n";
    std::cout << "║  8. Загрузить данные                 ║\n";
    std::cout << "║  0. Выход                            ║\n";
    std::cout << "╚══════════════════════════════════════╝\n";
    std::cout << "Выберите действие: ";
}

void addStudent(GradeBook& book) {
    std::cout << "Введите имя студента: ";
    std::string name;
    std::getline(std::cin, name);
    if (name.empty()) {
        std::cout << "Имя не может быть пустым!\n";
        return;
    }
    book.addStudent(name);
}

void addGrade(GradeBook& book) {
    std::cout << "Введите имя студента: ";
    std::string name;
    std::getline(std::cin, name);

    auto student = book.findStudent(name);
    if (!student.has_value()) {
        std::cout << "Студент \"" << name << "\" не найден!\n";
        return;
    }

    std::cout << "Введите оценку (0–100): ";
    int grade = Utils::readInt();
    if (grade < 0 || grade > 100) {
        std::cout << "Некорректная оценка! Допустимый диапазон: 0–100.\n";
        return;
    }

    try {
        student.value()->addGrade(grade);
        std::cout << "Оценка " << grade << " добавлена студенту \"" << name << "\".\n";
    } catch (const std::exception& e) {
        std::cout << "Ошибка: " << e.what() << "\n";
    }
}

void showReport(GradeBook& book) {
    std::cout << "Введите имя студента: ";
    std::string name;
    std::getline(std::cin, name);
    book.printStudentReport(name);
}

void removeStudent(GradeBook& book) {
    std::cout << "Введите имя студента для удаления: ";
    std::string name;
    std::getline(std::cin, name);

    if (book.removeStudent(name)) {
        std::cout << "Студент \"" << name << "\" удалён.\n";
    } else {
        std::cout << "Студент \"" << name << "\" не найден!\n";
    }
}

void saveData(const GradeBook& book) {
    if (FileManager::save(book, DATA_FILE)) {
        std::cout << "Данные сохранены в файл \"" << DATA_FILE << "\".\n";
    } else {
        std::cout << "Ошибка сохранения!\n";
    }
}

void loadData(GradeBook& book) {
    if (FileManager::load(book, DATA_FILE)) {
        std::cout << "Данные загружены из файла \"" << DATA_FILE << "\".\n";
    } else {
        std::cout << "Ошибка загрузки!\n";
    }
}

int main() {
#ifdef _WIN32
    // Установка кодировки для корректного отображения кириллицы
    std::system("chcp 65001 > nul");
#endif

    GradeBook book;
    bool running = true;

    std::cout << "Добро пожаловать в Калькулятор оценок!\n";

    while (running) {
        showMenu();
        int choice = Utils::readInt();

        switch (choice) {
            case 1: addStudent(book);             break;
            case 2: addGrade(book);               break;
            case 3: book.printAll();              break;
            case 4: showReport(book);             break;
            case 5: book.printGroupStatistics();  break;
            case 6: removeStudent(book);          break;
            case 7: saveData(book);               break;
            case 8: loadData(book);               break;
            case 0:
                std::cout << "До свидания!\n";
                running = false;
                break;
            default:
                std::cout << "Неверный выбор! Попробуйте снова.\n";
                break;
        }
    }

    return 0;
}
