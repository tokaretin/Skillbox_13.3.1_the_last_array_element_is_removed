﻿/*Задание 1
На витрине стоят несколько роботов, у каждого есть свой номер. Они задаются с клавиатуры 
(сначала вводится число n, потом -- n номеров роботов). Далее вводится число m и после этого -- m 
индексов (от 0 до количества оставшихся роботов на витрине). Когда введён очередной индекс -- 
робота покупают, то есть он покидает витрину, а остальные роботы “группируются”, смещаясь на 
один шаг назад. Необходимо вывести список оставшихся, после всех покупок, роботов.
 
Пример: на витрине стояли роботы {100, 200, 250, 300}. Сначала забрали робота с индексом 1,
то есть с номером 200, осталось {100,250,300}. Потом забрали робота с индексом 1, то есть с 
номером 250, осталось {100,300}

*/
#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n;
    cout << "Введите количество роботов на витрине: ";
    cin >> n;

    // Создаем вектор для хранения номеров роботов
    vector<int> robots(n);
    
    cout << "Введите номера роботов:" << endl;
    for (int i = 0; i < n; i++) {
        cout << "Введите номер " << i + 1 << "-го робота: ";
        cin >> robots[i];
    }

    int m;
    cout << "Введите количество покупок роботов: ";
    cin >> m;

    cout << "Введите номера покупаемых роботов:" << endl;
    for (int i = 0; i < m; i++) {
        int index;
        cout << "Введите номер " << i + 1 << "-го покупаемого робота: ";
        cin >> index;

        // Проверяем, чтобы индекс был в допустимом диапазоне
        if (index >= 0 && index < robots.size()) {
            // Смещаем элементы влево, начиная с индекса index+1
            for (int j = index + 1; j < robots.size(); j++) {
                robots[j - 1] = robots[j];
            }

            // Уменьшаем размер вектора на 1
            robots.resize(robots.size() - 1);
        }
        else {
            cout << "Неверный индекс покупаемого робота. Пропускаем покупку." << endl;
        }
    }

    cout << "Оставшиеся роботы: ";
    for (int i = 0; i < robots.size(); i++) {
        cout << robots[i] << " ";
    }
    cout << endl;

    return 0;
}
