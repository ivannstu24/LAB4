// 1 задание
//#include <iostream>
//#include <stdio.h>
//#include <cmath>
// 
//#define E 0.0001
// 
//using namespace std;
// 
//double f(double x) {
//   return sin(x + 1) - x - 1;
//}
// 
//double canonicalForm(double x) {
//   return sin(x + 1) - 1;
//}
// 
//double canonicalFormDer1(double x) {
//   return cos(x + 1); // может быть -1
//}
// 
//double fDer1(double x) {
//   return cos(x + 1) - 1;
//}
// 
//double fDer2(double x) {
//   return -sin(x + 1);
//}
// 
//double halfDivision(double ak, double bk, int k) {
//   printf("|\t%d\t|\t%.3lf\t|\t%.3lf\t|\t%.3lf\t|\n", k, ak, bk, bk - ak);
// 
//   if (k != 0 && abs(bk - ak) <= E) {
//       return (ak + bk) / 2;
//   }
//   k++;
// 
//   double ck = (ak + bk) / 2;
//   if (f(ak) * f(ck) < 0) {
//       return halfDivision(ak, ck, k);
//   } else {
//       return halfDivision(ck, bk, k);
//   }
//}
// 
//double newton(double xk, int k) {
//   double xkNew = xk - (f(xk) / fDer1(xk));
// 
//   printf("|\t%d\t|\t%.3lf\t|\t%.3lf\t|\t%.3lf\t|\n", k, xk, xkNew, xkNew - xk);
// 
//   if (abs(xkNew - xk) < E) {
//       return xkNew;
//   } else {
//       return newton(xkNew, ++k);
//   }
//}
// 
//double simpleIterations(double xk, double q, int k) {
//   double xkNew = canonicalForm(xk);
// 
//   printf("|\t%d\t|\t%.3lf\t|\t%.3lf\t|\t%.3lf\t|\n", k, xk, xkNew, xkNew - xk);
// 
//   if (abs(xkNew - xk) <= E) {
//       return xkNew;
//   } else {
//       return simpleIterations(xkNew, q, ++k);
//   }
//}
// 
//void menu() {
//   cout << "=== MENU ===\n1. The method of half division\n2. Newton method\n3. The method of simple iterations\n4. Menu\n5. Exit\n========\n";
//}
// 
//int main() {
//   double a0, b0;
//   double x0;
//   double x;
//   double q = 0.9;
// 
//   int choice;
// 
//   menu();
//   while (true) {
//       cout << "Choice: ";
//       cin >> choice;
// 
//       switch (choice) {
//       case 1:
//           cout << "a0=";
//           cin >> a0;
//           cout << "b0=";
//           cin >> b0;
// 
//           cout << "|\tN\t|\tan\t|\tbn\t|\tbn-an\t|" << endl;
//           x = halfDivision(a0, b0, 0);
// 
//           cout << "x=" << x << endl;
//           break;
//       case 2:
//           cout << "x0=";
//           cin >> x0;
// 
//           if (f(x0)*fDer2(x0) <= 0) {
//               cout << "x0 not satisfy f(x0)*f''(x0) > 0" << endl;
//               exit(0);
//           }
// 
//           cout << "|\tN\t|\txn\t|\tx(n+1)\t|   x(n+1)-xn\t|" << endl;
//           x = newton(x0, 0);
// 
//           cout << "x=" << x << endl;
//           break;
//       case 3:
//           cout << "x0=";
//           cin >> x0;
// 
//           if (abs(canonicalFormDer1(x0)) <= q && q < 1) {
//               cout << "x0 not satisfy |phi'(x0)|<=q<1" << endl;
//               exit(0);
//           }
// 
//           cout << "|\tN\t|\txn\t|\tx(n+1)\t|   x(n+1)-xn\t|" << endl;
//           x = simpleIterations(x0, q, 0);
// 
//           cout << "x=" << x << endl;
//           break;
//       case 4:
//           menu();
//           break;
//       default:
//           return 0;
//           break;
//       }
//   }
// 
//   return 0;
//}

//// 2 задание
//#include <iostream>
//#include <vector>
//#include <ctime>
//#include <algorithm>
//#include <cctype>
//
//// Функция для проверки, есть ли в числе повторяющиеся цифры
//bool hasRepeatedDigits(int num) {
//    int digit = num % 10;
//    num /= 10;
//    while (num > 0) {
//        if (num % 10 == digit) {
//            return true;
//        }
//        digit = num % 10;
//        num /= 10;
//    }
//    return false;
//}
//
//int main() {
//    srand(time(0));
//    int n = 10; // n должно быть чётным
//    std::vector<int> arr1(n), arr2(n / 2);
//
//    // Заполнение массивов
//    for (int i = 0; i < n; ++i) {
//        arr1[i] = 100 + rand() % 801; // [100, 900]
//    }
//
//    for (int i = 0; i < n / 2; ++i) {
//        arr2[i] = 2 + rand() % 49; // [2, 50]
//    }
//
//    // Вывод чётных элементов массива 1 на нечётных местах и нечётных элементов массива 2 на чётных местах
//    for (int i = 1; i < n; i += 2) {
//        if (arr1[i] % 2 == 0) {
//            std::cout << arr1[i] << " ";
//        }
//    }
//    std::cout << std::endl;
//
//    for (int i = 0; i < n / 2; i += 2) {
//        if (arr2[i] % 2 != 0) {
//            std::cout << arr2[i] << " ";
//        }
//    }
//    std::cout << std::endl;
//
//    // Определение и инициализация массива из k чисел
//    int k = 10;
//    std::vector<int> arr3(k);
//
//    for (int i = 0; i < k; ++i) {
//        int rand1 = arr1[rand() % n];
//        int rand2 = arr2[rand() % (n / 2)];
//        if (rand2 != 0) {
//            arr3[i] = rand1 / rand2;
//        } else {
//            arr3[i] = 0; // или какое-то другое значение по умолчанию
//        }
//    }
//
//    // Определение и инициализация массива случайных символов
//    std::vector<char> arr4(k);
//
//    for (int i = 0; i < k; ++i) {
//        arr4[i] = 'a' + rand() % 26; // случайные буквы
//    }
//
//    // Удаление заглавных букв
//    arr4.erase(std::remove_if(arr4.begin(), arr4.end(), [](char c){ return std::isupper(c); }), arr4.end());
//
//    // Вывод массива символов для проверки
//    for (char c : arr4) {
//        std::cout << c << " ";
//    }
//    std::cout << std::endl;
//
//    // Определение и инициализация массива случайных целых чисел
//    std::vector<int> arr5(k);
//
//    for (int i = 0; i < k; ++i) {
//        arr5[i] = rand() % 301; // случайные числа от 0 до 300
//    }
//
//    // Сортировка массива
//    std::sort(arr5.begin(), arr5.end());
//
//    // Создание нового массива с числами, в которых повторяются цифры
//    std::vector<int> arr6;
//
//    for (int num : arr5) {
//        if (hasRepeatedDigits(num)) {
//            arr6.push_back(num);
//        }
//    }
//
//    // Вывод массива для проверки
//    for (int num : arr6) {
//        std::cout << num << " ";
//    }
//    std::cout << std::endl;
//
//    return 0;
//}



 //задание 3
#include <iostream>
#include <random>
#include <vector>
#include <algorithm>
#include <cmath>
 
using namespace std;
 
ostream& operator<<(ostream& os, const vector<int>& vec) {
   for (auto elem : vec) {
       os << elem << " ";
   }
   return os;
}
 
int getRand(int a, int b) {
   random_device rd;
   mt19937 gen(rd());
   uniform_int_distribution<> dis(a, b);
 
   return dis(gen);
}
 
vector<int> getRandVector(int count, int a, int b) {
   vector<int> result;
 
   for (int i = 0; i < count; i++) {
       result.push_back(getRand(a, b));
   }
 
   return result;
}
 
double getVn(const vector<int>& vec, int index1, int index2) {
   vector<int> uniqueNumbersVec;
 
   for (int j = index1; j < index2; j++) {
       auto it = find(uniqueNumbersVec.begin(), uniqueNumbersVec.end(), vec[j]);
       if (it == uniqueNumbersVec.end()) {
           uniqueNumbersVec.push_back(vec[j]);
       }
   }
   return uniqueNumbersVec.size();
}
 
double getHiSquare(vector<int> vec) {
   double hiSquare = 0;
   int interval = vec.size() / 5;
   int vExp = interval;
   int vn;
 
   int intervalIndex1, intervalIndex2;
   for (int i = 0; i < 5; i++) {
       intervalIndex1 = i * interval;
       intervalIndex2 = i * interval + interval;
       vn = getVn(vec, intervalIndex1, intervalIndex2);
       hiSquare += pow(vn - vExp, 2) / vExp;
   }
   return hiSquare;
}
 
double realMathExp(vector<int> vec) {
   double sum = 0.0;
   for (double value : vec) {
       sum += value;
   }
   return sum / vec.size(); // Среднее арифметическое значений вектора
}
 
double expectedMathExp(int n){
   double sum = 0.0;
   for (int i = 1; i <= n; i++){
       sum += i;
   }
   return sum / n;
}
 
int main() {
   vector<int> vec50 = getRandVector(50, 1, 100);
   vector<int> vec100 = getRandVector(100, 1, 100);
   vector<int> vec1000 = getRandVector(1000, 1, 100);
 
   cout << "vec50 = " << vec50 << endl;
   cout << "hiSquare50 = " << getHiSquare(vec50) << endl;
   cout << "Real Math Expectation = " << realMathExp(vec50) << endl;
   cout << "Expected Math Expectation = " << expectedMathExp(vec50.size()) << endl;
 
   cout << "hiSquare100 = " << getHiSquare(vec100) << endl;
   cout << "Real Math Expectation = " << realMathExp(vec100) << endl;
   cout << "Expected Math Expectation = " << expectedMathExp(vec100.size()) << endl;
 
   cout << "hiSquare1000 = " << getHiSquare(vec1000) << endl;
   cout << "Real Math Expectation = " << realMathExp(vec1000) << endl;
   cout << "Expected Math Expectation = " << expectedMathExp(vec1000.size()) << endl;
 
   return 0;
}




//
//#include <iostream>
//#include <vector>
//#include <random>
//using namespace std;
// 
//// Функция для генерации случайного выбора алгоритма
//bool random_choice() {
//    random_device rd;
//    mt19937 gen(rd());
//    uniform_int_distribution<> dis(0, 1);
//    return dis(gen);
//}
// 
//// Алгоритм А: случайный выбор
//bool algorithm_A(int round_number, const vector<bool>& self_choices, const vector<bool>& enemy_choices) {
//    return random_choice();
//}
// 
//// Алгоритм Б: всегда предательство
//bool algorithm_B(int round_number, const vector<bool>& self_choices, const vector<bool>& enemy_choices) {
//    return false;
//}
// 
//// Алгоритм В: всегда сотрудничество
//bool algorithm_C(int round_number, const vector<bool>& self_choices, const vector<bool>& enemy_choices) {
//    return true;
//}
// 
//// Функция для определения результатов раунда
//pair<int, int> get_round_result(bool algorithm_A_choice, bool algorithm_B_choice) {
//    if (algorithm_A_choice && algorithm_B_choice) {
//        return {24, 24};
//    } else if (!algorithm_A_choice && !algorithm_B_choice) {
//        return {4, 4};
//    } else if (algorithm_A_choice && !algorithm_B_choice) {
//        return {0, 20};
//    } else {
//        return {20, 0};
//    }
//}
// 
//// Функция для запуска игры
//pair<int, int> play_game(bool (*algorithm_A)(int, const vector<bool>&, const vector<bool>&),
//                              bool (*algorithm_B)(int, const vector<bool>&, const vector<bool>&)) {
//    random_device rd;
//    mt19937 gen(rd());
//    uniform_int_distribution<> dis(100, 200);
//    int num_rounds = dis(gen);
//    int algorithm_A_score = 0;
//    int algorithm_B_score = 0;
//    vector<bool> algorithm_A_choices;
//    vector<bool> algorithm_B_choices;
// 
//    for (int round_number = 0; round_number < num_rounds; ++round_number) {
//        bool algorithm_A_choice = algorithm_A(round_number, algorithm_A_choices, algorithm_B_choices);
//        bool algorithm_B_choice = algorithm_B(round_number, algorithm_B_choices, algorithm_A_choices);
// 
//        auto [round_score_A, round_score_B] = get_round_result(algorithm_A_choice, algorithm_B_choice);
//        algorithm_A_score += round_score_A;
//        algorithm_B_score += round_score_B;
// 
//        algorithm_A_choices.push_back(algorithm_A_choice);
//        algorithm_B_choices.push_back(algorithm_B_choice);
//    }
// 
//    return {algorithm_A_score, algorithm_B_score};
//}
// 
//int main() {
//    // Запуск игры с алгоритмами А и B
//    cout<<"1 игра"<<endl;
//    auto [algorithm_A_score, algorithm_B_score] = play_game(algorithm_A, algorithm_B);
//    cout << "Algorithm A score: " << algorithm_A_score << endl;
//    cout << "Algorithm B score: " << algorithm_B_score << endl;
// 
//    // Запуск игры с алгоритмами А и C
//    cout<<"2 игра"<<endl;
//    auto [algorithm_A_score_2, algorithm_C_score] = play_game(algorithm_A, algorithm_C);
//    cout << "Algorithm A score: " << algorithm_A_score_2 << endl;
//    cout << "Algorithm C score: " << algorithm_C_score << endl;
// 
//    // Запуск игры с алгоритмами B и C
//    cout<<"3 игра"<<endl;
//    auto [algorithm_B_score_2, algorithm_C_score_2] = play_game(algorithm_B, algorithm_C);
//    cout << "Algorithm B score: " << algorithm_B_score_2 << endl;
//    cout << "Algorithm C score: " << algorithm_C_score_2 << endl;
// 
//    return 0;
//}


//// задание 5
//#include <iostream>
//#include <unordered_map>
//#include <vector>
//using namespace std;
// 
//vector<int> linear_congruential_generator(int X0, int A, int B, int C) {
//    vector<int> sequence;
//    unordered_map<int, int> seen;
//    int index = 0;
//    int rep_index = -1;
//    while (sequence.size() < 10) {
//        sequence.push_back(X0);
//        if (seen.find(X0) != seen.end()) {
//            if (rep_index == -1 || seen[X0] < rep_index) {
//                rep_index = seen[X0];
//            }
//        } else {
//            seen[X0] = index;
//        }
//        X0 = (A * X0 + B) % C;
//        index++;
//    }
//    return sequence;
//}
// 
//int linear_congruential_index(int X0, int A, int B, int C) {
//    vector<int> sequence;
//    unordered_map<int, int> find;
//    int index = 0;
//    int repeat_index = -1;
//    while (true) {
//        sequence.push_back(X0);
//        if (find.find(X0) != find.end()) {
//            repeat_index = index;
//            break;
//        }
//        find[X0] = index;
//        X0 = (A * X0 + B) % C;
//        index++;
//    }
//    return repeat_index;
//}
// 
//int main() {
//    int X0, A, B, C;
//    cout << "Введите через пробел значения X0, A, B, C: ";
//    cin >> X0 >> A >> B >> C;
// 
//    vector<int> sequenceall = linear_congruential_generator(X0, A, B, C);
//    for (int num : sequenceall) {
//        cout << num << " ";
//    }
//    cout << endl;
// 
//    int repeat_index = linear_congruential_index(X0, A, B, C);
//    cout << repeat_index + 1 << endl;
// 
//    return 0;
//}
