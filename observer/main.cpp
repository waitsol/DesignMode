#include "observer.h"
#include <iostream>

class Base {

};
//c++�������̳�  ���ǽ���̳�һ������ �����ӿ���
class Device :public Base, public Iobserver {

public:
	void run()
	{
		m_observer->addIobserver(shared_ptr<Iobserver>(this));
		
	}
	//�����ô��ʼ����
	Observer *m_observer;
};



int main()
{




}