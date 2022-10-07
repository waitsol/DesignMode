#include "observer.h"
#include <iostream>
#include <thread>
#include <Windows.h>
using namespace std;
class Base {

};
//c++�������̳�  ���ǽ���̳�һ������ �����ӿ���
class Device :public Base, public Iobserver {

public:
	void run()
	{
		
		
	}
	//�����ô��ʼ����
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