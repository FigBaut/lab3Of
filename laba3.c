#include <stdio.h>
#include <math.h>

void z1() {
    int d, m;
    printf("\n--- Задача 1 ---\n");
    printf("Введите день и месяц: ");
    scanf("%d %d", &d, &m);

    if (m < 1 || m > 12 || d < 1 || d > 31) {
        printf("Неверная дата\n");
        return;
    }

    int max_d = 31;
    if (m == 4 || m == 6 || m == 9 || m == 11) {
        max_d = 30;
    } else if (m == 2) {
        max_d = 28;
    }

    if (d <= max_d) {
        printf("Дата верная: %02d.%02d\n", d, m);
    } else {
        printf("Неверная дата, в этом месяце %d дней\n", max_d);
    }
}

void z2() {
    char c;
    printf("\n--- Задача 2 ---\n");
    printf("Вводите символы (Enter для завершения):\n");
    while (getchar() != '\n'); 

    while ((c = getchar()) != '\n') {
        if ((c >= 'A' && c <= 'Z') || (c >= 'a' && c <= 'z')) {
            printf("%c - буква\n", c);
        } else if (c >= '0' && c <= '9') {
            printf("%c - цифра\n", c);
        }
    }
}

void z3() {
    double x, y, z;
    printf("\n--- Задача 3 ---\n");
    printf("Введите x, y, z: ");
    scanf("%lf %lf %lf", &x, &y, &z);

    double max = x;
    if (y > max) max = y;
    if (z > max) max = z;

    double min = x;
    if (y < min) min = y;
    if (z < min) min = z;

    if (min == 0) {
        printf("Ошибка: деление на ноль (min = 0)\n");
        return;
    }

    double znam = sin(2 * x) + max / min;
    if (fabs(znam) < 0.000001) {
        printf("Ошибка: знаменатель равен нулю\n");
        return;
    }

    double u = (max * max - pow(2, x) * min) / znam;
    printf("u = %.4lf\n", u);
}

double ploshad(double x1, double y1, double x2, double y2, double x3, double y3) {
    return 0.5 * fabs((x1 - x3) * (y2 - y3) - (x2 - x3) * (y1 - y3));
}

void z4() {
    double x, y, x1, y1, x2, y2, x3, y3;
    printf("\n--- Задача 4 ---\n");
    printf("Координаты точки (x y): ");
    scanf("%lf %lf", &x, &y);
    printf("Координаты вершин треугольника (x1 y1 x2 y2 x3 y3): ");
    scanf("%lf %lf %lf %lf %lf %lf", &x1, &y1, &x2, &y2, &x3, &y3);

    double s = ploshad(x1, y1, x2, y2, x3, y3);
    if (s < 0.000001) {
        printf("Это не треугольник\n");
        return;
    }

    double s1 = ploshad(x, y, x2, y2, x3, y3);
    double s2 = ploshad(x1, y1, x, y, x3, y3);
    double s3 = ploshad(x1, y1, x2, y2, x, y);

    if (fabs(s - (s1 + s2 + s3)) < 0.000001) {
        printf("Точка внутри треугольника\n");
    } else {
        printf("Точка снаружи треугольника\n");
    }
}

void z5() {
    double a, b, c;
    printf("\n--- Задача 5 ---\n");
    printf("Введите три положительных числа: ");
    scanf("%lf %lf %lf", &a, &b, &c);

    if (a <= 0 || b <= 0 || c <= 0) {
        printf("Числа должны быть больше нуля\n");
        return;
    }

    int arifm = fabs((b - a) - (c - b)) < 0.000001;
    int geom = fabs((b / a) - (c / b)) < 0.000001;

    if (arifm) printf("Арифметическая прогрессия, d = %.3lf\n", b - a);
    if (geom) printf("Геометрическая прогрессия, q = %.3lf\n", b / a);
    if (!arifm && !geom) printf("Не прогрессия\n");
}

void z6() {
    double a, b;
    printf("\n--- Задача 6 ---\n");
    printf("Введите два разных числа a и b: ");
    scanf("%lf %lf", &a, &b);

    if (a == b) {
        printf("Числа не должны быть равны\n");
        return;
    }

    double pol = (a + b) / 2.0;
    double udv = 2.0 * a * b;

    if (a < b) {
        a = pol;
        b = udv;
    } else {
        b = pol;
        a = udv;
    }
    printf("Результат: a = %.3lf, b = %.3lf\n", a, b);
}

void z7() {
    double m, n;
    printf("\n--- Задача 7 ---\n");
    printf("Введите вес двух пакетов: ");
    scanf("%lf %lf", &m, &n);

    if (m < 0 || n < 0) {
        printf("Вес не может быть отрицательным\n");
        return;
    }

    if (m == n) {
        printf("Пакеты весят одинаково: %.2lf кг\n", m);
    } else if (m > n) {
        printf("Первый тяжелее: %.2lf кг\n", m);
    } else {
        printf("Второй тяжелее: %.2lf кг\n", n);
    }
}

void z8() {
    double t;
    printf("\n--- Задача 8 ---\n");
    printf("Введите время t в минутах (от 0 до 60): ");
    scanf("%lf", &t);

    if (t < 0 || t >= 60) {
        printf("Некорректное время\n");
        return;
    }

    double ost = fmod(t, 5.0);
    if (ost < 3.0) {
        printf("Горит зеленый\n");
    } else {
        printf("Горит красный\n");
    }
}

int kolvo(int a, int b, int x, int y) {
    int k1 = (a / x) * (b / y);
    int k2 = (a / y) * (b / x);
    if (k1 > k2) return k1;
    return k2;
}

void z9() {
    int a, b, c, d, e;
    printf("\n--- Задача 9 ---\n");
    printf("Размеры стола a и b (a > b): ");
    scanf("%d %d", &a, &b);
    if (a <= b || b <= 0) {
        printf("Ошибка: нужно чтобы a > b > 0\n");
        return;
    }

    printf("Размеры кости c, d, e (c > d > e): ");
    scanf("%d %d %d", &c, &d, &e);
    if (c <= d || d <= e || e <= 0) {
        printf("Ошибка: нужно чтобы c > d > e > 0\n");
        return;
    }

    int v1 = kolvo(a, b, c, d);
    int v2 = kolvo(a, b, c, e);
    int v3 = kolvo(a, b, d, e);

    int max = v1;
    int gran = 1;
    if (v2 > max) { max = v2; gran = 2; }
    if (v3 > max) { max = v3; gran = 3; }

    printf("Максимум костей: %d ", max);
    if (gran == 1) printf("(грань %d x %d)\n", c, d);
    else if (gran == 2) printf("(грань %d x %d)\n", c, e);
    else printf("(грань %d x %d)\n", d, e);
}

void z10() {
    int n;
    printf("\n--- Задача 10 ---\n");
    printf("Введите трехзначное число: ");
    scanf("%d", &n);

    if (n < 0) n = -n;
    if (n < 100 || n > 999) {
        printf("Число не трехзначное\n");
        return;
    }

    int c1 = n / 100;
    int c2 = (n / 10) % 10;
    int c3 = n % 10;

    if (c1 == c2 && c2 == c3) {
        printf("а) Все цифры одинаковые\n");
    } else {
        printf("а) Не все цифры одинаковые\n");
    }

    if (c1 == c2 || c1 == c3 || c2 == c3) {
        printf("б) Есть одинаковые цифры\n");
    } else {
        printf("б) Все цифры разные\n");
    }
}

int main() {
    int menu = -1;
    while (menu != 0) {
        printf("\n=== Лабораторная работа 3 ===\n");
        printf("1. Проверка даты\n");
        printf("2. Буквы и цифры\n");
        printf("3. Вычисление формулы u\n");
        printf("4. Точка и треугольник\n");
        printf("5. Прогрессии\n");
        printf("6. Замена a и b\n");
        printf("7. Пакеты риса\n");
        printf("8. Светофор\n");
        printf("9. Домино на столе\n");
        printf("10. Цифры числа\n");
        printf("11. Запустить все по очереди\n");
        printf("0. Выход\n");
        printf("Номер задания: ");
        
        if (scanf("%d", &menu) != 1) {
            printf("Ошибка ввода\n");
            break;
        }

        switch (menu) {
            case 1: z1(); break;
            case 2: z2(); break;
            case 3: z3(); break;
            case 4: z4(); break;
            case 5: z5(); break;
            case 6: z6(); break;
            case 7: z7(); break;
            case 8: z8(); break;
            case 9: z9(); break;
            case 10: z10(); break;
            case 11:
                z1(); z2(); z3(); z4(); z5();
                z6(); z7(); z8(); z9(); z10();
                break;
            case 0: printf("Выход из программы\n"); break;
            default: printf("Нет такого пункта\n");
        }
    }
    return 0;
}
