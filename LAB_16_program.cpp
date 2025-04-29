#include <iostream>
#define SIZE 100

using namespace std;

// Клас "Автобус"
class Bus {
private:
    char destination[20];  // Пункт призначення
    char number[10];       // Номер автобуса
    char time[6];          // Час відправлення у форматі "HH:MM"
    int seats;             // Кількість вільних місць

public:
    // Метод для встановлення значень
    void set(const char* dest, const char* num, const char* t, int s) {
        int i = 0;
        while (dest[i] != '\0') { destination[i] = dest[i]; i++; }
        destination[i] = '\0';

        i = 0;
        while (num[i] != '\0') { number[i] = num[i]; i++; }
        number[i] = '\0';

        i = 0;
        while (t[i] != '\0') { time[i] = t[i]; i++; }
        time[i] = '\0';

        seats = s;
    }

    // Геттери
    const char* get_destination() { return destination; }
    const char* get_time() { return time; }
    int get_seats() { return seats; }

    // Вивід інформації про автобус
    void show() {
        cout << "Автобус " << number << ", пункт призначення: " << destination
            << ", час відправлення: " << time << ", вільних місць: " << seats << endl;
    }

    // Чи є вільні місця
    bool seats_available() {
        return seats > 0;
    }
};

// Функція порівняння часу у форматі "HH:MM"
bool is_later(const char* t1, const char* t2) {
    int h1 = (t1[0] - '0') * 10 + (t1[1] - '0');
    int m1 = (t1[3] - '0') * 10 + (t1[4] - '0');
    int h2 = (t2[0] - '0') * 10 + (t2[1] - '0');
    int m2 = (t2[3] - '0') * 10 + (t2[4] - '0');
    if (h1 != h2) return h1 > h2;
    return m1 > m2;
}

// Функція порівняння рядків (еквівалент strcmp)
bool equals(const char* a, const char* b) {
    int i = 0;
    while (a[i] != '\0' && b[i] != '\0') {
        if (a[i] != b[i]) return false;
        i++;
    }
    return a[i] == b[i];
}

// Головна функція
int main() {

    system("chcp 1251 > nul"); //підключення української мови

    Bus buses[SIZE];
    int n = 3;  // Кількість автобусів

    // Заповнення автобусів
    buses[0].set("Kyiv", "A1", "08:00", 10);
    buses[1].set("Lviv", "B2", "09:30", 0);
    buses[2].set("Kyiv", "C3", "10:15", 5);

    // Заданий пункт призначення і час
    char target[] = "Kyiv";
    char time_check[] = "09:00";

    // (a) Вивід автобусів до заданого пункту
    cout << "\n(а) Список автобусів до пункту \"Kyiv\":\n";
    for (int i = 0; i < n; i++) {
        if (equals(buses[i].get_destination(), target)) {
            buses[i].show();
        }
    }

    // (b) Вивід автобусів до пункту, які відправляються пізніше вказаного часу
    cout << "\n(b) Автобуси до \"Kyiv\", що відправляються після 09:00:\n";
    for (int i = 0; i < n; i++) {
        if (equals(buses[i].get_destination(), target) &&
            is_later(buses[i].get_time(), time_check)) {
            buses[i].show();
        }
    }

    // (c) Автобуси до пункту з вільними місцями
    cout << "\n(c) Автобуси до \"Kyiv\" з вільними місцями:\n";
    for (int i = 0; i < n; i++) {
        if (equals(buses[i].get_destination(), target) &&
            buses[i].seats_available()) {
            buses[i].show();
        }
    }

    return 0;
}
