#include "observer.h"
#include <iostream>

class Base {

};
//c++不建议多继承  但是建议继承一个主类 其他接口类
class Device :public Base, public Iobserver {

public:
	void run()
	{
		m_observer->addIobserver(shared_ptr<Iobserver>(this));
		
	}
	//随便怎么初始化吧
	Observer *m_observer;
};



int main()
{




}