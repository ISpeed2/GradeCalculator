#ifndef FILEMANAGER_H
#define FILEMANAGER_H

#include "gradebook.h"
#include <string>

/**
 * @brief Класс для сохранения и загрузки данных журнала в файл.
 *
 * Формат файла (текстовый):
 *   STUDENT:<имя>
 *   GRADES:<оценка1>,<оценка2>,...
 *   END
 */
class FileManager {
public:
    /**
     * @brief Сохраняет журнал в текстовый файл.
     * @param gradebook Журнал для сохранения.
     * @param filename Имя файла.
     * @return true при успешном сохранении.
     */
    static bool save(const GradeBook& gradebook, const std::string& filename);

    /**
     * @brief Загружает журнал из текстового файла.
     * @param gradebook Журнал, в который загружаются данные.
     * @param filename Имя файла.
     * @return true при успешной загрузке.
     */
    static bool load(GradeBook& gradebook, const std::string& filename);
};

#endif // FILEMANAGER_H
