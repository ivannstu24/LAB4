"""
# 1 задание
import math

EPSILON = 0.0001  # Задаем точность для методов

# Функция, корень которой мы ищем
def func(x):
    return math.sin(x + 1) - x - 1

# Каноническая форма для метода простых итераций
def canonF(x):
    return math.sin(x + 1) - 1

# Первая производная канонической формы
def canonicalFormDer1(x):
    return math.cos(x + 1)

# Первая производная исходной функции
def DerivateFirst(x):
    return math.cos(x + 1) - 1

# Вторая производная исходной функции
def Derivative2(x):
    return -math.sin(x + 1)

# Метод половинного деления для нахождения корня
def halfdell(ak, bk, k):
    print(f"|\t{k}\t|\t{ak:.3f}\t|\t{bk:.3f}\t|\t{bk - ak:.3f}\t|")
    if k != 0 and abs(bk - ak) <= EPSILON:
        return (ak + bk) / 2
    k += 1
    ck = (ak + bk) / 2
    if func(ak) * func(ck) < 0:
        return halfdell(ak, ck, k)
    else:
        return halfdell(ck, bk, k)

# Метод Ньютона для нахождения корня
def Newton(xk, k):
    xkNew = xk - (func(xk) / DerivateFirst(xk))
    print(f"|\t{k}\t|\t{xk:.3f}\t|\t{xkNew:.3f}\t|\t{xkNew - xk:.3f}\t|")
    if abs(xkNew - xk) < EPSILON:
        return xkNew
    else:
        return Newton(xkNew, k + 1)

# Метод простых итераций для нахождения корня
def simpleIter(xk, q, k):
    xkNew = canonF(xk)
    print(f"|\t{k}\t|\t{xk:.3f}\t|\t{xkNew:.3f}\t|\t{xkNew - xk:.3f}\t|")
    if abs(xkNew - xk) <= EPSILON:
        return xkNew
    else:
        return simpleIter(xkNew, q, k + 1)

# Функция для отображения меню выбора метода
def menu():
    print("1. Метод половинного деления\n2. Метод Ньютона\n3. Метод простых итераций\n4. Показать меню снова\n")

def main():
    menu()  # Вывод меню

    while True:
        choice = int(input("Ваш выбор: "))
        if choice == 1:
            a0 = float(input("a0="))
            b0 = float(input("b0="))
            print("|\tN\t|\tan\t|\tbn\t|\tbn-an\t|")
            x = halfdell(a0, b0, 0)
            print(f"x={x}")
        elif choice == 2:
            x0 = float(input("x0="))
            if func(x0) * Derivative2(x0) <= 0:
                print("x0 not satisfy func(x0)*func''(x0) > 0")
                exit(0)
            print("|\tN\t|\txn\t|\tx(n+1)\t|   x(n+1)-xn\t|")
            x = Newton(x0, 0)
            print(f"x={x}")
        elif choice == 3:
            x0 = float(input("x0="))
            q = 0.9  # Коэффициент сходимости для метода простых итераций
            if abs(canonicalFormDer1(x0)) >= q or q >= 1:
                print("x0 not satisfy |phi'(x0)|<=q<1")
                exit(0)
            print("|\tN\t|\txn\t|\tx(n+1)\t|   x(n+1)-xn\t|")
            x = simpleIter(x0, q, 0)
            print(f"x={x}")
        elif choice == 4:
            menu()
        else:
            break

if __name__ == "__main__":
    main()
"""
"""
# 2 задание
import random
import string

# Функция для проверки четного числа
def is_even(number):
    return number % 2 == 0

# Функция для проверки нечетного числа
def is_odd(number):
    return number % 2 != 0

# Функция для генерации случайного числа в заданном диапазоне
def get_random_number(min_val, max_val):
    return random.randint(min_val, max_val)

def main():
    random.seed()  # Инициализация генератора случайных чисел

    n = 10  # n должно быть четным
    array1 = [get_random_number(100, 900) for _ in range(n)]
    array2 = [get_random_number(2, 50) for _ in range(n // 2)]

    # Вывод четных элементов array1 на нечетных местах
    print("Четные элементы массива 1 на нечетных местах:")
    for i in range(1, len(array1), 2):
        if is_even(array1[i]):
            print(f"Index {i}: {array1[i]}")

    # Вывод нечетных элементов array2 на четных местах
    print("Нечетные элементы массива 2 на четных местах:")
    for i in range(0, len(array2), 2):
        if is_odd(array2[i]):
            print(f"Index {i}: {array2[i]}")

    # Инициализация массива из k чисел, являющимися результатом целочисленного деления случайного элемента из array1 на случайный элемент из array2
    k = 10  # k >= 10
    array3 = [array1[get_random_number(0, len(array1) - 1)] // array2[get_random_number(0, len(array2) - 1)] for _ in range(k)]

    # Вывод массива array3
    print("Массив 3:")
    print(" ".join(map(str, array3)))

    # Инициализация массива случайных символов
    char_array = list("AbCdEfGhIjKlMnOpQrStUvWxYz")
    print("Исходный массив символов:", "".join(char_array))

    # Удаление заглавных букв из массива
    char_array = [c for c in char_array if not c.isupper()]
    print("Массив символов без заглавных букв:", "".join(char_array))

    # Инициализация массива случайных целых чисел в диапазоне [0, 300]
    random_array = [get_random_number(0, 300) for _ in range(20)]

    # Сортировка массива по возрастанию
    random_array.sort()

    # Создание нового массива с элементами, в которых цифры повторяются дважды
    repeated_digits_array = []
    for num in random_array:
        num_str = str(num)
        if any(num_str.count(c) > 1 for c in num_str):
            repeated_digits_array.append(num)

    # Вывод массива с повторяющимися цифрами
    print("Массив с элементами, в которых цифры повторяются дважды:")
    print(" ".join(map(str, repeated_digits_array)))

if __name__ == "__main__":
    main()
"""
