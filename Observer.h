#pragma once
#include <vector>
#include <algorithm>

class Observer
{
public:
	virtual void update() = 0;
	virtual ~Observer() {}
};

class Observable
{
protected:
	std::vector<Observer*> observers;

public:
	virtual ~Observable() {}

	void registerObserver(Observer* e)
	{
		this->observers.push_back(e);
	}

	void removeObserver(Observer* e)
	{
		this->observers.erase(std::remove(observers.begin(), observers.end(), e));
	}

	void notify()
	{
		for (auto e : observers)
			e->update();
	}
};