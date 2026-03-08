#include <stdio.h>
#include <stdlib.h>
#include <time.h>

/**
 * Задание 1. Вариант 2.
 * Найти числа с максимальной суммой цифр.
 * Студент: Журравкова Анастасия, гр. 11
 */

// Функция для подсчета суммы цифр числа (требование варианта)
int get_sum_digits(int num) {
		int sum = 0;
		num = abs(num);
		while (num > 0) {
				sum += num % 10;
				num /= 10;
		}
		return sum;
}

int main(int argc, char *argv[]) {
		// Получение размерности n через аргументы командной строки
		if (argc < 2) {
				printf("Использование: %s <размер_массива>\n", argv[0]);
				return 1;
		}

		int n = atoi(argv[1]);
		if (n <= 0) {
				printf("Ошибка: введите положительное число.\n");
				return 1;
		}

		int *array = (int*)malloc(n * sizeof(int));
		srand(time(NULL));

		// Генерация и вывод исходного массива
		printf("Исходный массив:\n");
		for (int i = 0; i < n; i++) {
				array[i] = rand() % 1000; // Натуральные числа до 999
				printf("%d ", array[i]);
		}
		printf("\n\n");

		// Поиск максимальной суммы цифр
		int max_sum = 0;
		for (int i = 0; i < n; i++) {
				int current_sum = get_sum_digits(array[i]);
				if (current_sum > max_sum) {
						max_sum = current_sum;
				}
		}

		// Вывод всех чисел с такой суммой
		printf("Максимальная сумма цифр: %d\n", max_sum);
		printf("Числа с такой суммой: ");
		for (int i = 0; i < n; i++) {
				if (get_sum_digits(array[i]) == max_sum) {
						printf("%d ", array[i]);
				}
		}
		printf("\n");

		free(array);
		return 0;
}