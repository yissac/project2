#include "Observable.hpp"

Observable::Observable()
{
}

void Observable::registerObserver(Observer* o)
{
	observers.push_back(o);
}

void Observable::unregisterObserver(Observer* o)
{
	observers.remove(o);
}

void Observable::notifyObservers()
{
	std::list <Observer*>::iterator it;
	for (it = observers.begin(); it != observers.end(); it++)
	{
		(*it)->notify();
	}
}
