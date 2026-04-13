#ifndef UTILS_H
#define UTILS_H

#include <string>

/**
 * @brief Вспомогательные функции для конвертации оценок.
 */
namespace Utils {
    /**
     * @brief Конвертирует числовую оценку в буквенную (A-F).
     * @param score Числовая оценка (0–100).
     * @return Строка с буквенной оценкой.
     */
    std::string toLetterGrade(double score);

    /**
     * @brief Конвертирует числовую оценку в GPA (шкала 4.0).
     * @param score Числовая оценка (0–100).
     * @return GPA от 0.0 до 4.0.
     */
    double toGPA(double score);

    /**
     * @brief Очищает экран консоли (кроссплатформенно).
     */
    void clearScreen();

    /**
     * @brief Ожидает нажатия клавиши.
     */
    void pause();

    /**
     * @brief Безопасный ввод целого числа.
     * @return Введённое число или -1 при ошибке.
     */
    int readInt();
}

#endif // UTILS_H
