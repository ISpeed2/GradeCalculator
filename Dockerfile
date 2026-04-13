# Использовать легкий образ Alpine Linux
FROM alpine:latest

# Установка необходимых пакетов для сборки (gcc, g++, make, cmake)
RUN apk add --no-cache build-base cmake

# Установка рабочей директории в контейнере
WORKDIR /app

# Копирование исходного кода проекта в контейнер
COPY . .

# Создание папки build, генерация файлов сборки и компиляция
RUN mkdir build && cd build && cmake .. && make

# Указание команды, которая будет выполняться при старте контейнера
CMD ["./build/GradeCalculator"]
