#include <stdio.h>
#define _CRT_SECURE_NO_DEPRECATE
#include <stdlib.h>
#include <locale.h>
#define _USE_MATH_DEFINES
#include <math.h>
#define _CRT_SECURE_NO_WARNINGS


double f(double x);
// Функция вычисления значения f(x) = x^3 - 4x^2 + 2
double f(double x) {
    return pow(x, 3) - 4 * pow(x, 2) + 2;
}

int main() {
    setlocale(LC_ALL, "RUS");
    double a, b, h;  
    int choice;        
    FILE* file;


    printf("Введите начало интервала (a): ");
    scanf("%lf", &a);
    printf("Введите конец интервала (b): ");
    scanf("%lf", &b);
    printf("Введите шаг табуляции: ");
    scanf("%lf", &h);

 
    printf("\nВыберите действие:\n");
    printf("1) Запись в новый файл (перезапись)\n");
    printf("2) Дозапись в существующий файл\n");
    printf("Ваш выбор: ");
    scanf("%d", &choice);


    switch (choice) {
    case 1:
        file = fopen("temp.txt", "w");  
        if (file == NULL) {
            printf("Ошибка создания файла\n");
            return 1;
        }
        printf("Файл temp.txt создан. Результаты будут записаны (перезаписаны).\n");
        break;

    case 2:
        file = fopen("temp.txt", "a");  
        if (file == NULL) {
            printf("Ошибка открытия файла для дозаписи\n");
            return 1;
        }
        printf("Файл temp.txt открыт. Результаты будут добавлены в конец файла.\n");
        break;

    default:
        printf("Неверный выбор!\n");
        return 1;
    }

    // запись в файл
    fprintf(file, "Табулирование функции f(x) = x^3 - 4x^2 + 2\n");
    fprintf(file, "Интервал: [%.2f; %.2f], шаг: %.2f\n", a, b, h);
    fprintf(file, "---------------------------------\n");
    fprintf(file, "x\t\tf(x)\n");
    fprintf(file, "---------------------------------\n");

    for (double x = a; x <= b; x += h) {
        double y = f(x);
        fprintf(file, "%.2f\t\t%.4f\n", x, y);
    }

    fclose(file);
    printf("Результаты табулирования успешно записаны в файл temp.txt\n");
    return 0;
}
/*
#include <stdio.h>
#define _CRT_SECURE_NO_DEPRECATE
#include <stdlib.h>
#include <locale.h>
#define _USE_MATH_DEFINES
#include <math.h>
#define _CRT_SECURE_NO_WARNINGS

int main(void)
{
    setlocale(LC_ALL, "RUS");
    char fname[20] = "number.txt"; // задаём имя файла
    FILE* out;                     // объявляем указатель на файл

    puts("Создание файла"); // выводим сообщение о создании файла

    // Пытаемся открыть файл для записи ("wt" — write text)
    if ((out = fopen(fname, "wt")) == NULL)
    {
        printf("Ошибка открытия файла для записи\n");
        return 0;
    }

fprintf(out, "%d\n", 5); // записываем число 5 в файл

fclose(out);
puts("Файл создан, записано целое число 5");

// добавления "12.56"
out = fopen(fname, "a");
if (out == NULL) {
    printf("Ошибка открытия файла для записи\n");
    return 0;
}

// Записываем вещественное число (12.56) с новой строки
fprintf(out, "%f\n", 12.56);

fclose(out);
puts("Данные успешно записаны в файл number.txt");

return 1;    // завершаем программу успешно
}
*/