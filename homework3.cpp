#include <iostream>
#include <windows.h>
#include <cmath>
#include <string>
#include <fstream>
using namespace std;

void task1();                                                                                      // Задание 1: "Копирование файла".
void task2();                                                                                      // Задание 2: "Фильтр".
void task3();                                                                                      // Задание 3: "Сортировка букв".
void task4();                                                                                      // Задание 4: "Алгоритм Евклида".
void task5();                                                                                      // Задание 5: "Решето Эратосфена".
void task6();                                                                                      // Задание 6: "Файл".
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

void menu() {                                                                                      // Функция вывода меню заданий.
    cout << "===============================" << endl;
    cout << "       ВЫБОР ЗАДАНИЙ N3        " << endl;
    cout << "===============================" << endl << endl;
    cout << "1. Задание «Копирование файла»" << endl;
    cout << "2. Задание «Фильтр»" << endl;
    cout << "3. Задание «Сортировка букв»" << endl;
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

void task1() {                                                                                     // Задание 1: "Копирование файла".
    ofstream fout("HW3_Task1.txt");                                                                // Создаем объект fout и записываем текст
    fout << "УНБО-04-25 Борзенков Н.С.";
    fout.close();

    ifstream fin("HW3_Task1.txt");                                                                 // Создаем объект fin для чтения.
    string line;                                                                                   // Переменная для хранения строки.
    while (getline(fin, line)) {                                                                   // Читаем строку и выводим.
        cout << line << endl;
    }
    fin.close();
}

void task2() {                                                                                     // Задание 2: "Фильтр".
    ofstream fout("HW3_Task2.txt");                                                                // Создаем объект fout и записываем текст.
    fout << "q1w23er456tyQ78we99rty0";
    fout.close();

    ifstream fin("HW3_Task2.txt");
    string line;
    getline(fin, line);
    cout << "Поиск цифр / чисел в следующей строке: " << line << endl;
    fin.close();

    fin.open("HW3_Task2.txt");
    char c;

    cout << "Найденные цифры / числа: ";

    while (fin.get(c)) {
        if (c >= '0' && c <= '9') {                                                                // Проверка на цифру.
            cout << c;

            char next_c;                                                                           // Считываем следующие цифры, для числа.
            while (fin.get(next_c) && next_c >= '0' && next_c <= '9') {                            // Проверка на цифру.
                cout << next_c;
            }

            cout << " ";

        }
    }
}


void task3() {                                                                                     // Задание 3: "Сортировка букв".
    char str[] = "qwertyuiopasdfghjklzxcvbnmqwer";                                                 // Массив 30 элементов (+1 \n)
    int n = 30;                                                                                    // Исключаем \n

    for (int i = 0; i < n - 1; i++) {                                                              // Пузырьковая сортировка. Проход, больший элементв конец.
        for (int j = 0; j < n - i - 1; j++) {                                                      // Сравниваем элементы.
            if (str[j] > str[j + 1]) {                                                             // Меняем местами.
                char temp = str[j];
                str[j] = str[j + 1];
                str[j + 1] = temp;
            }
        }
    }

    cout << "Отсортированная строка: " << str << endl;
}

void task4() {                                                                                     // Задание 4: "Алгоритм Евклида".
    int a, b;

    cout << "Введите первое число: ";                                                              // Ввод чисел.
    cin >> a;
    cout << "Введите второе число: ";
    cin >> b;

    int a1 = a, b1 = b;                                                                            // Дублируем для первого и второго метода.
    int temp_a = a, temp_b = b;

    cout << "\nМетод деления:" << endl;                                                            // Способ 1: Алгоритм Евклида с делением.
    while (temp_b != 0) {
        int remainder = temp_a % temp_b;                                                           // Вычисляем остаток от деления temp_a на temp_b
        cout << temp_a << " % " << temp_b << " = " << remainder << endl;
        temp_a = temp_b;                                                                           // Присваиваем temp_a -> temp_b
        temp_b = remainder;                                                                        // Присваиваем temp_b -> remainder
    }
    cout << "НОД методом деления: " << temp_a << endl;

    cout << "\nМетод вычитания:" << endl;                                                          // Способ 2: Алгоритм Евклида с вычитанием.
    while (a1 != b1) {                                                                             // Цикл продолжается пока a1 и b1 не станут равными.
        if (a1 > b1) {
            cout << a1 << " - " << b1 << " = " << (a1 - b1) << endl;
            a1 = a1 - b1;
        }
        else {
            cout << b1 << " - " << a1 << " = " << (b1 - a1) << endl;
            b1 = b1 - a1;
        }
    }
    cout << "НОД методом вычитания: " << a1 << endl;
}

void task5() {                                                                                     // Задание 5: "Решето Эратосфена".
    int n;
    cout << "Введите число: ";
    cin >> n;

    bool p[1000];                                                                                  // Создаем массив для отметки простых чисел.
    for (int i = 0; i < 1000; i++) {
        p[i] = false;                                                                              // Все элементы как false.
    }

    for (int i = 2; i <= n; i++) {                                                                 // Все числа считаем простыми (кроме 0 и 1).
        p[i] = true;
    }

    for (int i = 2; i <= n; i++) {                                                                 // Решето Эратосфена.
        if (p[i]) {                                                                                // Если i - прстое
            for (int j = i * 2; j <= n; j += i) {                                                  // Вычеркиваем, начинаем с первого, переходим к следующему кратному.
                p[j] = false;                                                                      // Помечаем составное.
            }
        }
    }

    cout << "Простые числа: ";
    for (int i = 2; i <= n; i++) {                                                                 // Перебираем все числа от 2 до n и выводим только те,
        if (p[i]) {                                                                                // которые остались помеченными как простые (p[i] = true).
            cout << i << " ";
        }
    }
    cout << endl;
}

void task6() {                                                                                     // Задание 6: "Файл".
    ofstream fout("HW3_Task6.txt");                                                                // Создаем файл и записываем в него 10 готовых чисел.
    fout << "123 43 2 5678 45 3 8 9 0 11";
    fout.close();

    cout << "Числа: 123 43 2 5678 45 3 8 9 0 11" << endl;

    ifstream fin("HW3_Task6.txt");                                                                 // Открываем файл заново для чтения и находим сумму чисел.
    int number;
    int sum = 0;

    while (fin >> number) {
        sum += number;
    }
    fin.close();

    cout << "Сумма чисел: " << sum << endl;
}
