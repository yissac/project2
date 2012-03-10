#ifndef OBSERVABLE_HPP
#define OBSERVABLE_HPP

#include "observer.hpp"
#include "list"

class Observable
{
public:
    Observable();

    void registerObserver(Observer* o);
    void unresgisterObserver(Observer* o);
    void notifyObservers();
    void notifyObservers(int,NotificationType);

    private:
    std::list<Observer*> observers;

};

#endif // OBSERVABLE_HPP
