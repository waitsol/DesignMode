#include "observer.h"
#include <iostream>
#include <thread>
#include <Windows.h>
using namespace std;
class Base {

};
//c++不建议多继承  但是建议继承一个主类 其他接口类
class Device :public Base, public Iobserver {

public:
	void run()
	{
		
		
	}
	//随便怎么初始化吧
	Observer *m_observer;
	void update(int val)
	{
		cout << val << endl;
	}
};



int main()
{

	shared_ptr<Device> d=shared_ptr<Device>(new Device);
	Observer ob;

	d->m_observer = &ob;
	ob.addIobserver(d);
	thread t([&]() {
		d->run();
		Sleep(2000);
		d.reset();
	});

	while (1)
	{
		ob.doSomething();
		Sleep(1000);
	}

}