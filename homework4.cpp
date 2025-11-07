#include <iostream>
#include <windows.h>
#include <cmath>
#include <string>
#include <fstream>

using namespace std;

void task1();                                                                                      // Задание 1: "Знак числа".
void task2();                                                                                      // Задание 2: "Геометрические фигуры".
void task3();                                                                                      // Задание 3: "Былая слава".
void task4();                                                                                      // Задание 4: "Алгоритм Евклида".
void task5();                                                                                      // Задание 5: "Решето Эратосфена".
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
    cout << "4. Задание «Алгоритм Евклида»" << endl;
    cout << "5. Задание «Решето Эратосфена»" << endl;
    cout << "6. Задание «Файл»" << endl;
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

void task4() {
    const int width = 80;
    const int height = 25;
    const double x_min = -2 * 3.14;
    const double x_max = 2 * 3.14;

    char graph[height][width];

    // Инициализация массива пробелами
    for (int i = 0; i < height; ++i) {
        for (int j = 0; j < width; ++j) {
            graph[i][j] = ' ';
        }
    }

    // Рисование осей
    int zero_y = height / 2;
    int zero_x = width / 2;

    // Ось X
    for (int j = 0; j < width; ++j) {
        graph[zero_y][j] = '-';
    }

    // Ось Y
    for (int i = 0; i < height; ++i) {
        graph[i][zero_x] = '|';
    }

    // Центр координат
    graph[zero_y][zero_x] = '+';

    // Отрисовка синусоиды
    for (int j = 0; j < width; ++j) {
        double x = x_min + j * (x_max - x_min) / (width - 1);
        double y = sin(x);

        int i = static_cast<int>((1 - y) * (height - 1) / 2 + 0.5);

        if (i >= 0 && i < height) {
            graph[i][j] = '*';
        }
    }

    // Вывод графика
    for (int i = 0; i < height; ++i) {
        for (int j = 0; j < width; ++j) {
            cout << graph[i][j];
        }
        cout << '\n';
    }
}


void task5() {                                                                                     // Задание 5: "Решето Эратосфена".
    
}
