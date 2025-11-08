#include <iostream>
#include <windows.h>
#include <cmath>
#include <string>
#include <fstream>

using namespace std;

void task1();                                                                                      // Задание 1: "Знак числа".
void task2();                                                                                      // Задание 2: "Геометрические фигуры".
void task3();                                                                                      // Задание 3: "Былая слава".
void task4();                                                                                      // Задание 4: "Синусоида".
void task5();                                                                                      // Задание 5: "«Генератор псевдослучайных чисел".
void menu();                                                                                       // Вывод меню выбора заданий.
void pause();                                                                                      // Пауза перед возвратом в меню.

int main() {
    SetConsoleCP(1251);                                                                            // Установка кодировки для корректного отображения русских символов
    SetConsoleOutputCP(1251);
    int Choice;

    while (true) {
        system("cls");                                                                             // Очистка экрана

        menu();                                                                                    // Вывод меню

        cin >> Choice;

        system("cls");                                                                             // Очистка экрана перед выводом задания

        if (Choice == 0) break;

        switch (Choice) {                                                                          // Выбор соответствующего задания
        case 1: task1(); break;
        case 2: task2(); break;
        case 3: task3(); break;
        case 4: task4(); break;
        case 5: task5(); break;
        default:
            cout << "Такого задания не существует." << endl;
            break;
        }

        pause();                                                                                   // Ожидание нажатия клавиши
    }

    cout << "Программа завершена." << endl;
    return 0;
}

void menu() {                                                                                      // Функция вывода меню заданий.
    cout << "===============================" << endl;
    cout << "       ВЫБОР ЗАДАНИЙ N4        " << endl;
    cout << "===============================" << endl << endl;
    cout << "1. Задание «Знак числа»" << endl;
    cout << "2. Задание «Геометрические фигуры»" << endl;
    cout << "3. Задание «Былая слава»" << endl;
    cout << "4. Задание «Синусоида»" << endl;
    cout << "5. Задание ««Генератор чисел»" << endl;
    cout << "0. Выход из программы" << endl << endl;
    cout << "===============================" << endl;
    cout << "Выберите задание: ";
}

void pause() {                                                                                     // Функция паузы с ожиданием пользовательского ввода
    cout << endl << "Нажмите любую клавишу для продолжения...";
    cin.ignore();                                                                                  //Выкидываем \n из буфера.
    cin.get();                                                                                     //Ждем ответ от пользователя.
}
// 1
int sign(double x) {                                                                               // Подпрограмма-функция для определения знака числа
    if (x > 0) return 1;
    if (x < 0) return -1;
    return 0;
}

void task1() {                                                                                     // Задание 1: "Знак числа".
    float num;
    cout << "Введите число: ";
    cin >> num;

    int result = sign(num);
    cout << "Знак числа: " << result << endl;
}
// 2
float rectangle(float length, float width) {                                                       // S прямоугольника
    return length * width;
}

float triangle(float base, float height) {                                                         // S треугольника
    return 0.5 * base * height;
}

float circle(float radius) {                                                                       // S круга
    return 3.14 * radius * radius;
}

void task2() {                                                                                     // Задание 2: "Геометрические фигуры".
    int choice;
    double a, b, r;

    cout << "Выберите фигуру для вычисления площади:" << endl;
    cout << "1 - Прямоугольник" << endl;
    cout << "2 - Треугольник" << endl;
    cout << "3 - Круг" << endl;
    cout << "Ваш выбор: ";
    cin >> choice;

    switch (choice) {
    case 1:
        cout << "Введите длину и ширину прямоугольника: ";
        cin >> a >> b;
        cout << "Площадь прямоугольника: " << rectangle(a, b) << endl;
        break;

    case 2:
        cout << "Введите основание и высоту треугольника: ";
        cin >> a >> b;
        cout << "Площадь треугольника: " << triangle(a, b) << endl;
        break;

    case 3:
        cout << "Введите радиус круга: ";
        cin >> r;
        cout << "Площадь круга: " << circle(r) << endl;
        break;

    default:
        cout << "Напишите число от 1 до 3." << endl;
    }
}
// 3
void drawFlag(int lineNum) {
    if (lineNum < 6) {
        cout << "* * * * * * * * ";
        if (lineNum % 2 == 0) {
            cout << "R R R R R R R R R R R R" << endl;
        }
        else {
            cout << "W W W W W W W W W W W W" << endl;
        }
    }
    else {
        if (lineNum % 2 == 0) {
            cout << "R R R R R R R R R R R R R R R R R R R R" << endl;
        }
        else {
            cout << "W W W W W W W W W W W W W W W W W W W W" << endl;
        }
    }
}

void task3() {                                                                                     // Задание 3: "Былая слава".
    for (int i = 0; i < 13; i++) {
        drawFlag(i);
    }
    cout << endl;
}

void task4() {                                                                                     //Задание 4: "Синусоида"
    const int width = 80;                                                                          // Размеры поля для графика
    const int height = 25;

    char field[height][width];                                                                     // Создаем поле из символов

    for (int y = 0; y < height; y++) {                                                             // Заполняем поле пробелами, чтобы "рисовать" на нем
        for (int x = 0; x < width; x++) {
            field[y][x] = ' ';
        }
    }
                                                                                                   // Рисуем оси координат
    int center_y = height / 2;                                                                     // Центр по вертикали
    int center_x = width / 2;                                                                      // Центр по горизонтали

    for (int x = 0; x < width; x++) {                                                              // Горизонтальная ось x
        field[center_y][x] = '-';
    }

    for (int y = 0; y < height; y++) {                                                             // Вертикальная ось y
        field[y][center_x] = '|';
    }
                                                                                                   // Рисуем график синуса, цикл по всем столбцам
    for (int x_pixel = 0; x_pixel < width; x_pixel++) {                                            // Преобразуем номер столбца в координату x
        double x = -6.28 + x_pixel * (12.56 / 79);                                                 // Интервал от -2п до 2п на 80 столбцов

        double y = sin(x);                                                                         // Вычисляем значение синуса в точке x
                                                                                                   // Преобразуем значение y в номер строки
        int y_pixel = (1 - y) * 12;                                                                // 1-у, для вертикали; *12, чтобы ратсянуть на пол высоты
        
        if (y_pixel >= 0 && y_pixel < height) {                                                    // Если точка попадает на поле - рисуем её
            field[y_pixel][x_pixel] = '*';                                                         // Проверяем чтобы находилась в пределах экрана
        }
    }

    for (int y = 0; y < height; y++) {                                                             // Выводим готовый график
        for (int x = 0; x < width; x++) {
            cout << field[y][x];
        }
        cout << '\n';
    }
}

void task5() {                                                                                     // Задание 5: "«Генератор псевдослучайных чисел".
    int m = 37;                                                                                    // 1 вариант                                                 
    int i = 3; 
    int c = 64;      

    int s_current = 0;                                                                             // Начальное значение

    int count = 10;                                                                                // Количество генерируемых чисел

    cout << "I вариант (m=37, i=3, c=64):" << endl;
    cout << "Последовательность: ";

    for (int i = 0; i < count; i++) {                                                              // Генерируем последовательность для 1 варианта
        int s_next = (m * s_current + i) % c;                                                      //s_{i+1} = (m * s_i + i) mod c
        cout << s_next << " ";
        s_current = s_next;
    }

    cout << endl << endl;

    m = 25173;                                                                                     // 2 вариант
    i = 13849;
    c = 65537;

    s_current = 0;                                                                                 // Сбрасываем начальное значение

    cout << "II вариант (m=25173, i=13849, c=65537):" << endl;
    cout << "Последовательность: ";

    for (int i = 0; i < count; i++) {                                                              // Генерируем последовательность для 2 варианта
        int s_next = (m * s_current + i) % c;
        cout << s_next << " ";
        s_current = s_next;
    }

    cout << endl;
}
