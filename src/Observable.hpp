#ifndef OBSERVABLE_HPP
#define OBSERVABLE_HPP

#include <list>
#include "observer.hpp"

class Observable
{
public:
	Observable();
	
	void registerObserver(Observer* o);
	void unregisterObserver(Observer* o);
	void notifyObservers();

private:
	std::list <Observer*> observers;
};

#endif // OBSERVABLE_HPP
