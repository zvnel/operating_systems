#include <stdio.h> // ввод-вывод
#include <stdlib.h> //функции динамического выделения памяти
#include <unistd.h> //системные функции
#include <sys/mman.h> //функции управления памятью
int main() {
    // Получаем размер страницы памяти
    long page_size = sysconf(_SC_PAGESIZE);
    while (1) {
        // Выделяем память размером в 1 страницу
        void *ptr = mmap(NULL, page_size, PROT_READ | PROT_WRITE, MAP_PRIVATE | MAP_ANONYMOUS, -1, 0);
        if (ptr == MAP_FAILED) {
            perror("mmap");
            return 1;
        }
        // Заполняем память нулями
        for (int i = 0; i < page_size; i++) {
            ((char *)ptr)[i] = 0;
        }
        // Не освобождаем память
    }
    return 0;
}
