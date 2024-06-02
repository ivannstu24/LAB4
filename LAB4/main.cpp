//// 1 задание в9
//#include <iostream>
//#include <cmath>
//
//#define EPSILON 0.0001 // Задаем точность для методов
//
//using namespace std;
//
//// Функция, корень которой мы ищем
//double func(double x) {
//    return sin(x + 1) - x - 1;
//}
//
//// Каноническая форма для метода простых итераций
//double canonF(double x) {
//    return sin(x + 1) - 1;
//}
//
//// Первая производная канонической формы
//double canonicalFormDer1(double x) {
//    return cos(x + 1); // Производная функции sin(x + 1) - 1
//}
//
//// Первая производная исходной функции
//double DerivateFirst(double x) {
//    return cos(x + 1) - 1;
//}
//
//// Вторая производная исходной функции
//double Derivative2(double x) {
//    return -sin(x + 1);
//}
//
//// Метод половинного деления для нахождения корня
//double halfdell(double ak, double bk, int k) {
//    // Вывод текущего состояния
//    printf("|\t%d\t|\t%.3lf\t|\t%.3lf\t|\t%.3lf\t|\n", k, ak, bk, bk - ak);
//
//    // Проверка условия остановки
//    if (k != 0 && abs(bk - ak) <= EPSILON) {
//        return (ak + bk) / 2;
//    }
//    k++;
//
//    double ck = (ak + bk) / 2;
//    // Рекурсивное продолжение метода половинного деления
//    if (func(ak) * func(ck) < 0) {
//        return halfdell(ak, ck, k);
//    } else {
//        return halfdell(ck, bk, k);
//    }
//}
//
//// Метод Ньютона для нахождения корня
//double Newton(double xk, int k) {
//    double xkNew = xk - (func(xk) / DerivateFirst(xk));
//
//    // Вывод текущего состояния
//    printf("|\t%d\t|\t%.3lf\t|\t%.3lf\t|\t%.3lf\t|\n", k, xk, xkNew, xkNew - xk);
//
//    // Проверка условия остановки
//    if (abs(xkNew - xk) < EPSILON) {
//        return xkNew;
//    } else {
//        return Newton(xkNew, ++k);
//    }
//}
//
//// Метод простых итераций для нахождения корня
//double simpleIter(double xk, double q, int k) {
//    double xkNew = canonF(xk);
//
//    // Вывод текущего состояния
//    printf("|\t%d\t|\t%.3lf\t|\t%.3lf\t|\t%.3lf\t|\n", k, xk, xkNew, xkNew - xk);
//
//    // Проверка условия остановки
//    if (abs(xkNew - xk) <= EPSILON) {
//        return xkNew;
//    } else {
//        return simpleIter(xkNew, q, ++k);
//    }
//}
//
//// Функция для отображения меню выбора метода
//void menu() {
//    cout << "1. Метод половинного деления\n2. Метод Ньютона\n3. Метод простых итераций\n";
//}
//
//// Главная функция
//int main() {
//    double a0, b0; // Интервал для метода половинного деления
//    double x0; // Начальное приближение для методов Ньютона и простых итераций
//    double x; // Переменная для хранения результата
//    double q = 0.9; // Коэффициент сходимости для метода простых итераций
//
//    int choice; // Переменная для хранения выбора пользователя
//
//    menu(); // Вывод меню
//    while (true) {
//        cout << "Ваш выбор: ";
//        cin >> choice;
//
//        switch (choice) {
//            case 1:
//                // Ввод начальных значений для метода половинного деления
//                cout << "a0=";
//                cin >> a0;
//                cout << "b0=";
//                cin >> b0;
//
//                // Заголовок таблицы
//                cout << "|\tN\t|\tan\t|\tbn\t|\tbn-an\t|" << endl;
//                // Вызов метода половинного деления
//                x = halfdell(a0, b0, 0);
//
//                cout << "x=" << x << endl;
//                break;
//            case 2:
//                // Ввод начального значения для метода Ньютона
//                cout << "x0=";
//                cin >> x0;
//
//                // Проверка условия сходимости
//                if (func(x0)*Derivative2(x0) <= 0) {
//                    cout << "x0 not satisfy func(x0)*func''(x0) > 0" << endl;
//                    exit(0);
//                }
//
//                // Заголовок таблицы
//                cout << "|\tN\t|\txn\t|\tx(n+1)\t|   x(n+1)-xn\t|" << endl;
//                // Вызов метода Ньютона
//                x = Newton(x0, 0);
//
//                cout << "x=" << x << endl;
//                break;
//            case 3:
//                // Ввод начального значения для метода простых итераций
//                cout << "x0=";
//                cin >> x0;
//
//                // Проверка условия сходимости
//                if (abs(canonicalFormDer1(x0)) <= q && q < 1) {
//                    cout << "x0 not satisfy |phi'(x0)|<=q<1" << endl;
//                    exit(0);
//                }
//
//                // Заголовок таблицы
//                cout << "|\tN\t|\txn\t|\tx(n+1)\t|   x(n+1)-xn\t|" << endl;
//                // Вызов метода простых итераций
//                x = simpleIter(x0, q, 0);
//
//                cout << "x=" << x << endl;
//                break;
//            case 4:
//                // Показать меню снова
//                menu();
//                break;
//            default:
//                return 0;
//                break;
//        }
//    }
//
//    return 0;
//}


// 2 задание в3
//
//#include <iostream>
//#include <vector>
//#include <cstdlib>
//#include <ctime>
//#include <algorithm>
//
//// Функция для проверки четного числа
//bool isEven(int number) {
//    return number % 2 == 0;
//}
//
//// Функция для проверки нечетного числа
//bool isOdd(int number) {
//    return number % 2 != 0;
//}
//
//// Функция для генерации случайного числа в заданном диапазоне
//int getRandomNumber(int min, int max) {
//    return rand() % (max - min + 1) + min;
//}
//
//int main() {
//    srand(time(0));  // Инициализация генератора случайных чисел
//
//    int n = 10;  // n должно быть четным
//    std::vector<int> array1(n);
//    std::vector<int> array2(n / 2);
//
//    // Инициализация array1 числами из диапазона [100, 900]
//    for(int &num : array1) {
//        num = getRandomNumber(100, 900);
//    }
//
//    // Инициализация array2 числами из диапазона [2, 50]
//    for(int &num : array2) {
//        num = getRandomNumber(2, 50);
//    }
//
//    // Вывод четных элементов array1 на нечетных местах
//    std::cout << "Четные элементы массива 1 на нечетных местах:" << std::endl;
//    for(int i = 1; i < array1.size(); i += 2) {
//        if(isEven(array1[i])) {
//            std::cout << "Index " << i << ": " << array1[i] << std::endl;
//        }
//    }
//
//    // Вывод нечетных элементов array2 на четных местах
//    std::cout << "Нечетные элементы массива 2 на четных местах:" << std::endl;
//    for(int i = 0; i < array2.size(); i += 2) {
//        if(isOdd(array2[i])) {
//            std::cout << "Index " << i << ": " << array2[i] << std::endl;
//        }
//    }
//
//    // Инициализация массива из k чисел, являющимися результатом целочисленного деления случайного элемента из array1 на случайный элемент из array2
//    int k = 10;  // k >= 10
//    std::vector<int> array3(k);
//    for(int &num : array3) {
//        int num1 = array1[getRandomNumber(0, array1.size() - 1)];
//        int num2 = array2[getRandomNumber(0, array2.size() - 1)];
//        num = num1 / num2;
//    }
//
//    // Вывод массива array3
//    std::cout << "Массив 3:" << std::endl;
//    for(const int &num : array3) {
//        std::cout << num << " ";
//    }
//    std::cout << std::endl;
//
//    // Инициализация массива случайных символов
//    std::string charArray = "AbCdEfGhIjKlMnOpQrStUvWxYz";
//    std::cout << "Исходный массив символов: " << charArray << std::endl;
//
//    // Удаление заглавных букв из массива
//    charArray.erase(std::remove_if(charArray.begin(), charArray.end(), [](char c) { return isupper(c); }), charArray.end());
//    std::cout << "Массив символов без заглавных букв: " << charArray << std::endl;
//
//    // Инициализация массива случайных целых чисел в диапазоне [0, 300]
//    std::vector<int> randomArray(20);
//    for(int &num : randomArray) {
//        num = getRandomNumber(0, 300);
//    }
//
//    // Сортировка массива по возрастанию
//    std::sort(randomArray.begin(), randomArray.end());
//
//    // Создание нового массива с элементами, в которых цифры повторяются дважды
//    std::vector<int> repeatedDigitsArray;
//    for(const int &num : randomArray) {
//        std::string numStr = std::to_string(num);
//        bool hasRepeatedDigits = false;
//        for(char c : numStr) {
//            if(std::count(numStr.begin(), numStr.end(), c) > 1) {
//                hasRepeatedDigits = true;
//                break;
//            }
//        }
//        if(hasRepeatedDigits) {
//            repeatedDigitsArray.push_back(num);
//        }
//    }
//
//    // Вывод массива с повторяющимися цифрами
//    std::cout << "Массив с элементами, в которых цифры повторяются дважды:" << std::endl;
//    for(const int &num : repeatedDigitsArray) {
//        std::cout << num << " ";
//    }
//    std::cout << std::endl;
//
//    return 0;
//}

//задание 3 в8
//#include <iostream>
//#include <random>
//#include <vector>
//#include <algorithm>
//#include <cmath>
//
//using namespace std;
//
//ostream& operator<<(ostream& os, const vector<int>& vec) {
//    for (auto elem : vec) {
//        os << elem << " ";
//    }
//    return os;
//}
//
//int generateRandomNumber(int min, int max) {
//    random_device rd;
//    ranlux48 generator(rd());
//    uniform_int_distribution<> distribution(min, max);
//
//    return distribution(generator);
//}
//
//vector<int> createRandomVector(int size, int min, int max) {
//    vector<int> vec;
//    for (int i = 0; i < size; i++) {
//        vec.push_back(generateRandomNumber(min, max));
//    }
//    return vec;
//}
//
//double countUniqueElements(const vector<int>& vec, int start, int end) {
//    vector<int> uniqueElements;
//    for (int i = start; i < end; i++) {
//        if (find(uniqueElements.begin(), uniqueElements.end(), vec[i]) == uniqueElements.end()) {
//            uniqueElements.push_back(vec[i]);
//        }
//    }
//    return uniqueElements.size();
//}
//
//double calculateChiSquare(const vector<int>& vec) {
//    double chiSquare = 0;
//    int intervalSize = vec.size() / 5;
//    int expectedValue = intervalSize;
//    int uniqueCount;
//
//    for (int i = 0; i < 5; i++) {
//        int intervalStart = i * intervalSize;
//        int intervalEnd = intervalStart + intervalSize;
//        uniqueCount = countUniqueElements(vec, intervalStart, intervalEnd);
//        chiSquare += pow(uniqueCount - expectedValue, 2) / expectedValue;
//    }
//    return chiSquare;
//}
//
//double computeMean(const vector<int>& vec) {
//    double sum = 0.0;
//    for (int value : vec) {
//        sum += value;
//    }
//    return sum / vec.size();
//}
//
//double calculateExpectedMean(int n) {
//    double sum = 0.0;
//    for (int i = 1; i <= n; i++) {
//        sum += i;
//    }
//    return sum / n;
//}
//
//int main() {
//    vector<int> vecOf50 = createRandomVector(50, 1, 100);
//    vector<int> vecOf100 = createRandomVector(100, 1, 100);
//    vector<int> vecOf1000 = createRandomVector(1000, 1, 100);
//
//    cout << "Vector 50 = " << vecOf50 << endl;
//    cout << "Chi-Square for 50 elements = " << calculateChiSquare(vecOf50) << endl;
//    cout << "Actual Mean for 50 elements = " << computeMean(vecOf50) << endl;
//    cout << "Expected Mean for 50 elements = " << calculateExpectedMean(vecOf50.size()) << endl;
//
//    cout << "Chi-Square for 100 elements = " << calculateChiSquare(vecOf100) << endl;
//    cout << "Actual Mean for 100 elements = " << computeMean(vecOf100) << endl;
//    cout << "Expected Mean for 100 elements = " << calculateExpectedMean(vecOf100.size()) << endl;
//
//    cout << "Chi-Square for 1000 elements = " << calculateChiSquare(vecOf1000) << endl;
//    cout << "Actual Mean for 1000 elements = " << computeMean(vecOf1000) << endl;
//    cout << "Expected Mean for 1000 elements = " << calculateExpectedMean(vecOf1000.size()) << endl;
//
//    return 0;
//}




//4 задание
//#include <iostream>
//#include <vector>
//#include <random>
//
//using namespace std;
//
//// Функция для генерации случайного выбора (true или false)
//bool random_choice() {
//    random_device rd; // Источник случайности
//    mt19937 gen(rd()); // Генератор случайных чисел
//    uniform_int_distribution<> dis(0, 1); // Распределение от 0 до 1
//    return dis(gen); // Возвращаем случайное значение (0 или 1, что соответствует false или true)
//}
//
//// Алгоритм А: случайный выбор (предательство или сотрудничество)
//bool algorithm_A(int round_number, const vector<bool>& self_choices, const vector<bool>& enemy_choices) {
//    return random_choice(); // Возвращает случайный выбор
//}
//
//// Алгоритм Б: всегда предательство
//bool algorithm_B(int round_number, const vector<bool>& self_choices, const vector<bool>& enemy_choices) {
//    return false; // Всегда предательство (false)
//}
//
//// Алгоритм В: всегда сотрудничество
//bool algorithm_C(int round_number, const vector<bool>& self_choices, const vector<bool>& enemy_choices) {
//    return true; // Всегда сотрудничество (true)
//}
//
//// Функция для определения результатов раунда
//pair<int, int> get_round_result(bool algorithm_A_choice, bool algorithm_B_choice) {
//    // В зависимости от сочетания выборов алгоритмов, возвращаем соответствующие результаты
//    if (algorithm_A_choice && algorithm_B_choice) {
//        return {24, 24}; // Оба сотрудничают
//    } else if (!algorithm_A_choice && !algorithm_B_choice) {
//        return {4, 4}; // Оба предают
//    } else if (algorithm_A_choice && !algorithm_B_choice) {
//        return {0, 20}; // A сотрудничает, B предает
//    } else {
//        return {20, 0}; // A предает, B сотрудничает
//    }
//}
//
//// Функция для запуска игры между двумя алгоритмами
//pair<int, int> play_game(bool (*algorithm_A)(int, const vector<bool>&, const vector<bool>&),
//                         bool (*algorithm_B)(int, const vector<bool>&, const vector<bool>&)) {
//    random_device rd; // Источник случайности
//    mt19937 gen(rd()); // Генератор случайных чисел
//    uniform_int_distribution<> dis(100, 200); // Распределение количества раундов от 100 до 200
//    int num_rounds = dis(gen); // Количество раундов
//    int algorithm_A_score = 0; // Счет алгоритма A
//    int algorithm_B_score = 0; // Счет алгоритма B
//    vector<bool> algorithm_A_choices; // История выборов алгоритма A
//    vector<bool> algorithm_B_choices; // История выборов алгоритма B
//
//    // Цикл по количеству раундов
//    for (int round_number = 0; round_number < num_rounds; ++round_number) {
//        // Получение выборов алгоритмов на текущий раунд
//        bool algorithm_A_choice = algorithm_A(round_number, algorithm_A_choices, algorithm_B_choices);
//        bool algorithm_B_choice = algorithm_B(round_number, algorithm_B_choices, algorithm_A_choices);
//
//        // Получение результатов текущего раунда
//        auto [round_score_A, round_score_B] = get_round_result(algorithm_A_choice, algorithm_B_choice);
//        algorithm_A_score += round_score_A; // Обновление счета A
//        algorithm_B_score += round_score_B; // Обновление счета B
//
//        // Сохранение выборов текущего раунда
//        algorithm_A_choices.push_back(algorithm_A_choice);
//        algorithm_B_choices.push_back(algorithm_B_choice);
//    }
//
//    return {algorithm_A_score, algorithm_B_score}; // Возвращаем итоговые счета
//}
//
//int main() {
//    // Запуск игры с алгоритмами А и B
//    cout << "1 игра" << endl;
//    auto [algorithm_A_score, algorithm_B_score] = play_game(algorithm_A, algorithm_B);
//    cout << "Algorithm A score: " << algorithm_A_score << endl;
//    cout << "Algorithm B score: " << algorithm_B_score << endl;
//
//    // Запуск игры с алгоритмами А и C
//    cout << "2 игра" << endl;
//    auto [algorithm_A_score_2, algorithm_C_score] = play_game(algorithm_A, algorithm_C);
//    cout << "Algorithm A score: " << algorithm_A_score_2 << endl;
//    cout << "Algorithm C score: " << algorithm_C_score << endl;
//
//    // Запуск игры с алгоритмами B и C
//    cout << "3 игра" << endl;
//    auto [algorithm_B_score_2, algorithm_C_score_2] = play_game(algorithm_B, algorithm_C);
//    cout << "Algorithm B score: " << algorithm_B_score_2 << endl;
//    cout << "Algorithm C score: " << algorithm_C_score_2 << endl;
//
//    return 0;
//}

//

// задание 5 // фибоначи
//
//#include <iostream>
//#include <vector>
//
//using namespace std;
//
//// Перегрузка оператора << для вывода содержимого вектора
//template<typename T>
//ostream& operator<<(ostream& os, const vector<T>& vec) {
//    for (auto elem : vec) {
//        os << elem << " "; // Вывод каждого элемента вектора с пробелом
//    }
//    return os;
//}
//
//// Рекурсивная функция для генерации чисел Фибоначчи
//void generateFibonacci(vector<uint64_t>& sequence, int index, int length) {
//    if (index == length) {
//        return; // Если достигнут конец последовательности, прекратить рекурсию
//    }
//
//    if (index == 0 || index == 1) {
//        sequence.push_back(1); // Первые два числа Фибоначчи равны 1
//    } else {
//        sequence.push_back(sequence[index - 1] + sequence[index - 2]); // Последующие числа равны сумме двух предыдущих
//    }
//
//    // Рекурсивный вызов функции для следующего индекса
//    return generateFibonacci(sequence, ++index, length);
//}
//
//// Функция для вычисления нового значения на основе двух предыдущих чисел
//uint64_t calculateNewValue(int offset1, int offset2, int mod, vector<uint64_t> sequence) {
//    return (sequence[sequence.size() - offset1 - 1] + sequence[sequence.size() - offset2 - 1]) % mod;
//    // Возвращает сумму двух чисел по смещениям offset1 и offset2, взятую по модулю mod
//}
//
//int main() {
//    vector<uint64_t> sequence; // Вектор для хранения последовательности чисел Фибоначчи
//    generateFibonacci(sequence, 0, 56); // Генерация первых 56 чисел Фибоначчи
//
//    cout << "Fibonacci sequence: " << sequence << endl; // Вывод последовательности чисел Фибоначчи
//
//    int offset1 = 24, offset2 = 55; // Смещения для вычисления нового значения
//
//    int totalValues, modulus; // Переменные для хранения количества новых значений и модуля
//    cout << "totalValues = ";
//    cin >> totalValues; // Ввод количества новых значений от пользователя
//    cout << "modulus = ";
//    cin >> modulus; // Ввод модуля от пользователя
//
//    for (int i = 0; i < totalValues; i++) {
//        // Вычисление нового значения и добавление его в последовательность
//        int newValue = calculateNewValue(offset1, offset2, modulus, sequence);
//        sequence.push_back(newValue);
//        cout << newValue << endl; // Вывод нового значения
//    }
//
//    return 0;
//}
