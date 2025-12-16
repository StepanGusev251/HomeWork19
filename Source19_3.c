#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <string.h>
#include <math.h>

#define _CRT_SECURE_NO_DEPRECATE
#define _USE_MATH_DEFINES 

#include <stdio.h>
#include <locale.h>

struct Employee {
    char surname[50];      // Фамилия
    char name[50];         // Имя
    char patronymic[50];   // Отчество
    char position[100];    // Должность
    double salary;          // Зарплата
    int birth_day;        // День рождения
    int birth_month;      // Месяц рождения
    int birth_year;       // Год рождения
};

int main(void) {
    setlocale(LC_CTYPE, "RUS");
    struct Employee emp;
    FILE* file;

    printf("Введите фамилию сотрудника: ");
    fgets(emp.surname, sizeof(emp.surname), stdin);

    printf("Введите имя сотрудника: ");
    fgets(emp.name, sizeof(emp.name), stdin);

    printf("Введите отчество сотрудника: ");
    fgets(emp.patronymic, sizeof(emp.patronymic), stdin);

    printf("Введите должность сотрудника: ");
    fgets(emp.position, sizeof(emp.position), stdin);

    printf("Введите зарплату сотрудника: ");
    scanf("%lf", &emp.salary);

    printf("Введите день рождения (1-31): ");
    scanf("%d", &emp.birth_day);

    printf("Введите месяц рождения (1-12): ");
    scanf("%d", &emp.birth_month);

    printf("Введите год рождения: ");
    scanf("%d", &emp.birth_year);

    // Открываем файл для записи
    file = fopen("employees.txt", "wt");
    if (file == NULL) {
        printf("Ошибка открытия файла\n");
        return 1;
    }

    // Записываем данные в файл
    fprintf(file, "Фамилия: %s\n", emp.surname);
    fprintf(file, "Имя: %s\n", emp.name);
    fprintf(file, "Отчество: %s\n", emp.patronymic);
    fprintf(file, "Должность: %s\n", emp.position);
    fprintf(file, "Зарплата: %.2f\n", emp.salary);
    fprintf(file, "Дата рождения: %02d.%02d.%d\n",
        emp.birth_day, emp.birth_month, emp.birth_year);

    // Закрываем файл
    fclose(file);

    printf("Данные успешно записаны в файл 'employees.txt'\n");
    return 0;
}