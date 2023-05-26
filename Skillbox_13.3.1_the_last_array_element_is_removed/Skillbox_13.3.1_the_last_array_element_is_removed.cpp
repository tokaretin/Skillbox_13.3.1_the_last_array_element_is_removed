/*Задание 1
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

int main() {
    int n;
    std::cout << "Enter the number of robots in the window: ";
    std::cin >> n;

    // Создаем вектор для хранения номеров роботов
    std::vector<int> robots(n);
    
    std::cout << "Enter the robot numbers:" << '\n';
    for (int i = 0; i < n; i++) {
        std::cout << "Enter the number " << i + 1 << " robot: ";
        std::cin >> robots[i];
    }

    int m;
    std::cout << "Enter the number of robot purchases: ";
    std::cin >> m;

    std::cout << "Enter the number of purchased robots:" << '\n';
    for (int i = 0; i < m; i++) {
        int index;
        std::cout << "Enter the number " << i + 1 << " purchased robot: ";
        std::cin >> index;

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
            std::cout << "Wrong index of purchased robot. Skipping purchase." << '\n';
        }
    }

    std::cout << "Remaining robots: ";
    for (int i = 0; i < robots.size(); i++) {
        std::cout << robots[i] << " ";
    }
    std::cout << '\n';

    return 0;
}
