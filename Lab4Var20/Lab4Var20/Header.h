#pragma once

// Значение (через указатель) +1
void increment(int*);

// Функция работы со стеком
void incrementStackVariable();

// Функция работы с динамической памятью
void incrementHeapVariable();

// Функция вывода массива целых чисел на экран
void writeArray(int*, int);

// Функция ввода массива целых чисел с клавиатуры
void readArray(int*, int);

// Функция сортировки массивов методом "Сортировка вставки"
void sort(int*, int);

// Функция работы с массивом константой
void sortStackArray(int*, int);

// Функция работы с массивом заполняемым пользователем
void sortArrayPerson();

// Изменение размера массива
void resizeArr(int*, int);