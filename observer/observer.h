#ifndef  _observer_h
#define _observer_h
#include <list>
#include <memory>
#include <iostream>
using std::shared_ptr;
using std::weak_ptr;
using std::list;
using std::cout;

using std::endl;
class Iobserver {
public:
	~Iobserver(){}
	virtual void update(int val)
	{

	}
};


class Observer {
public:
	void doSomething()
	{
		//do 


		//notify
		auto iter = m_Iobserverlist.begin();
		while (iter != m_Iobserverlist.end())
		{
			auto obj = (*iter).lock();
			if (obj)
			{
				obj->update(0);
				iter++;
			}
			else {
				cout << "ob==nullptr" << endl;
				iter=m_Iobserverlist.erase(iter);
			}
		}
	}
	void addIobserver(shared_ptr<Iobserver> pob){
	

		m_Iobserverlist.push_back(pob);


	}
private:
	list<weak_ptr< Iobserver>> m_Iobserverlist;
	
};




#endif // ! _observe_h
