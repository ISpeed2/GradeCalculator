# 📊 Grade Calculator / Калькулятор оценок

Консольное приложение на C++ для учёта и анализа оценок студентов.

## Возможности

- ➕ Добавление студентов и оценок
- 📈 Расчёт среднего балла, GPA
- 📊 Статистика: минимум, максимум, медиана
- 🔤 Конвертация в буквенную систему (A, B, C, D, F)
- 💾 Сохранение и загрузка данных из файла
- 📋 Просмотр списка всех студентов с оценками

## Сборка и запуск

### С помощью CMake

```bash
mkdir build
cd build
cmake ..
cmake --build .
```

### С помощью g++ (MinGW)

```bash
g++ -std=c++17 -o GradeCalculator src/main.cpp src/student.cpp src/gradebook.cpp src/utils.cpp src/filemanager.cpp
./GradeCalculator
```

## Структура проекта

```
├── CMakeLists.txt        # Конфигурация сборки
├── README.md             # Описание проекта
├── .gitignore            # Игнорируемые файлы
└── src/
    ├── main.cpp          # Главный файл, меню
    ├── student.h/.cpp    # Класс Student
    ├── gradebook.h/.cpp  # Класс GradeBook
    ├── utils.h/.cpp      # Вспомогательные функции
    └── filemanager.h/.cpp# Работа с файлами
```

## Автор

Выполнено в рамках учебного задания.
