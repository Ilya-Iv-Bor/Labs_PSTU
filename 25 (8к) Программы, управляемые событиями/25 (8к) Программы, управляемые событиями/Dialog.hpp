#include "Vector.hpp"
#include "Event.hpp"

class Dialog: public Vector {
protected:
    int endState;

public:
    Dialog();
    virtual ~Dialog();
    
    virtual void getEvent (TEvent& event); // Получить событие
    virtual int execute();  // Главный цикл обработки событий
    virtual void handleEvent (TEvent& event); // Обработчик
    virtual void clearEvent (TEvent& event); // Очистить событие
    int valid(); // Проверка атрибута EndState
    void endExecute(); // Обработка события «конец работы»
};
