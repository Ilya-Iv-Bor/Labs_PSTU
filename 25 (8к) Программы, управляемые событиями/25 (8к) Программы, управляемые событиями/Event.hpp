#pragma once
const int evNothing = 0; // Пустое событие
const int evMessage = 100; // Непустое событие
const int cmAdd = 1; // Добавить объект в группу
const int cmRemove = 2; // Удалить объект из группы
const int cmGet = 3; // Вывести имя по индексу
const int cmShow = 4; // Вывести всю группу
const int cmMake = 6; // Создать группу
const int cmQuit = 101; // Выход

struct TEvent {
    int what;
    union {
        int command; // Код команды
            
        struct {
            int message;
            int parameter; // Параметр команды
        };
    };
};
