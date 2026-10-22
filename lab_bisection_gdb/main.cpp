// Тема: Численные методы.
// Суть: Поиск корня уравнения x^2 - 4 = 0 на отрезке [0, 3] методом бисекции.
// Где баг: Внутри функции findRoot в ветвлении if (f(a) * f(mid) < 0). 
// Знаки перепутаны, из-за чего отрезок сужается не в ту сторону, приводя к бесконечному циклу. 
// При отладке добавьте 'a', 'b' и 'mid' в Watch и следите за их изменением на каждой итерации.

#include <iostream>
#include <cmath>

double f(double x) {
    return x * x - 4.0; // Корень x = 2
}

double findRoot(double a, double b, double eps) {
    double mid = a;
    while ((b - a) > eps) {
        mid = a + (b - a) / 2.0;
        if (f(mid) == 0.0) return mid;
        
        // БАГ: Неверная логика сужения отрезка (перепутаны знаки)
        if (f(a) * f(mid) > 0) {
            a = mid; 
        } else {
            b = mid;
        }
    }
    return mid;
}

int main() {
    double a = 0.0, b = 3.0, eps = 0.0001;
    std::cout << "poisk kornya..." << std::endl;
    double root = findRoot(a, b, eps);
    std::cout << "Root: " << root << std::endl;
    return 0;
}