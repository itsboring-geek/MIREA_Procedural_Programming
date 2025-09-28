#include <iostream>
#include <windows.h>
#include <cmath>
#include <string>
using namespace std;

void task1();                                                                                      // Задание 1: "Разветвление".
void task2();                                                                                      // Задание 2: "Функция".
void task3();                                                                                      // Задание 3: "Порядок".
void task4();                                                                                      // Задание 4: "Табуляция".
void task5();                                                                                      // Задание 5: "Заем".
void task6();                                                                                      // Задание 6: "Ссуда".
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
        case 6: task6(); break;
        default:
            cout << "Такого задания не существует." << endl;
            break;
        }

        pause();                                                                                   // Ожидание нажатия клавиши
    }

    cout << "Программа завершена." << endl;
    return 0;
}

void menu() {                                                                                      // Функция вывода меню заданий
    cout << "===============================" << endl;
    cout << "       ВЫБОР ЗАДАНИЙ N2        " << endl;
    cout << "===============================" << endl << endl;
    cout << "1. Задание «Разветвление»" << endl;
    cout << "2. Задание «Функция»" << endl;
    cout << "3. Задание «Порядок»" << endl;
    cout << "4. Задание «Табуляция»" << endl;
    cout << "5. Задание «Заем»" << endl;
    cout << "6. Задание «Ссуда»" << endl;
    cout << "0. Выход из программы" << endl << endl;
    cout << "===============================" << endl;
    cout << "Выберите задание: ";
}

void pause() {                                                                                     // Функция паузы с ожиданием пользовательского ввода
    cout << endl << "Нажмите любую клавишу для продолжения...";
    cin.ignore();                                                                                  //Выкидываем \n из буфера.
    cin.get();                                                                                     //Ждем ответ от пользователя.
}

void task1() {                                                                                     // Задание 1: "Разветвление".
    float x, a, w;

    cout << "Введите x: ";
    cin >> x;
    cout << "Введите a: ";
    cin >> a;

    if (abs(x) < 1.0) {                                                                            // Для |x| < 1
        if (x == 0) {
            cout << "Решение: x = 0, логарифм не определен." << endl;
        }
        else {
            w = a * log(abs(x));
            cout << "w = " << w << endl;
        }
    }
    else {
        if (a - x * x < 0) {                                                                       // Для |x| >= 1
            cout << "Решение: подкоренное выражение отрицательное." << endl;
        }
        else {
            w = sqrt(a - x * x);
            cout << "Решение: w = " << w << endl;
        }
    }
}

void task2() {                                                                                     // Задание 2: "Функция".
    float x, y, b, z;

    cout << "Введите x: ";
    cin >> x;
    cout << "Введите y: ";
    cin >> y;
    cout << "Введите b: ";
    cin >> b;

    if (b - y <= 0) {
        cout << "Решение: аргумент логарифма должен быть положительным!" << endl;
        return;
    }

    if (b - x <= 0) {
        cout << "Решение: подкоренное выражение должно быть положительным!" << endl;
        return;
    }

    z = log(b - y) * sqrt(b - x);
    cout << "Решение: z = " << z << endl;
}

void task3() {                                                                                     // Задание 3: "Порядок".
    int N;

    cout << "Введите число N: ";
    cin >> N;

    cout << "Печать 10-ти последовательных натуральных чисел, начиная с " << N << ":" << endl;              
    for (int i = 0; i < 10; i++) {                                                                 // Повторяем 10 раз
        cout << N + i;                                                                             // Берем число N и прибавляем i
        if (i < 9) cout << ", ";                                                                   // Если это не последнее число, ставим запятую
    }
    cout << endl;
}

void task4() {                                                                                     // Задание 4: "Табуляция".
    float x, y;

    cout << "x\t\ty" << endl;
    cout << "------------------------" << endl;

    for (x = -4; x <= 4; x += 0.5) {
        if (x == 1) {                                                                              //При x = 1 знаменатель (x - 1) становится равен 0
            cout << x << "\t\tНе определена" << endl;
        }
        else {
            y = (x * x - 2 * x + 2) / (x - 1);
            cout << x << "\t\t" << y << endl;
        }
    }
}

void task5() {                                                                                     // Задание 5: "Заем".
    float S, p, n;

    cout << "Введите сумму займа S: ";
    cin >> S;
    if (S <= 0) {
        cout << "Ошибка: Сумма займа должна быть положительной." << endl;
        return;
    }

    cout << "Введите годовую процентную ставку p: ";
    cin >> p;
    if (p < 0) {
        cout << "Ошибка: Процентная ставка должна быть положительной." << endl;
        return;
    }

    cout << "Введите срок займа в годах n: ";
    cin >> n;
    if (n <= 0) {
        cout << "Ошибка: Срок займа должен быть положительным." << endl;
        return;
    }

    float r = p / 100;
    float denominator_part = pow(1 + r, n) - 1;                                                   // Часть знаменателя

    if (denominator_part == 0) {                                                                   // Если r = 0 (нулевая процентная ставка)
        float m = S / (12 * n);
        cout << "Ежемесячный платеж m: " << m << endl;
    }
    else {
        float numerator = S * r * pow(1 + r, n);
        float denominator = 12 * (pow(1 + r, n) - 1);
        float m = numerator / denominator;

        cout << "Ежемесячный платеж m: " << m << endl;
    }
}

void task6() {                                                                                     // Задание 6: "Ссуда".
    float S, m, p;
    int n;

    cout << "Введите сумму займа S: ";
    cin >> S;
    if (S <= 0) {
        cout << "Ошибка: Сумма займа должна быть положительной." << endl;
        return;
    }

    cout << "Введите месячную выплату m: ";
    cin >> m;
    if (m <= 0) {
        cout << "Ошибка: Месячная выплата должна быть положительной." << endl;
        return;
    }

    cout << "Введите срок займа в годах n: ";
    cin >> n;
    if (n <= 0) {
        cout << "Ошибка: Срок займа должен быть положительным." << endl;
        return;
    }

    for (p = 0.01; p <= 100; p += 0.1) {                                                           // Перебираем возможные проценты от 0.01% до 100%
        float r = p / 100;
        float numerator = S * r * pow(1 + r, n);
        float denominator = 12 * (pow(1 + r, n) - 1);
        float calculated_m = numerator / denominator;

        if (abs(calculated_m - m) < 1) {                                                           // Если рассчитанный платеж отличается
            cout << "Процент p: " << p << "%" << endl;                                             // от заданного менее чем на 1 рубль,
            break;                                                                                 // считаем что нашли подходящую ставку
        }
    }
}