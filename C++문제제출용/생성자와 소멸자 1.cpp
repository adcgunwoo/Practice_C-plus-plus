//������:��ü�� �����ɶ� �ڵ����� ȣ��Ǵ� �Լ�
//�Ҹ���:��ü�� �Ҹ�ɶ� �ڵ����� ȣ��Ǵ� �Լ�
#include <iostream>
using namespace std;
class myclass {
public:
	myclass() {//������, ��ü�� �����Ǹ� �ڵ� ȣ��
		cout << "�����ڰ� ȣ��Ǿ���!" << endl;//���� 3
	}//�����ڸ� ����� ���� �ۼ�������
	 //�ۼ������ʾƵ� ����Ʈ �����ڰ� ������
	~myclass() {//�Ҹ���
		cout << "�Ҹ��ڰ� ȣ��Ǿ���!" << endl;//���� 5
	}
};
//myclass globalobj;
void testlocalobj() {
	cout << "testlocalobj �Լ� ����!" << endl;//���� 2
	myclass localobj;
	cout << "testlocalobj �Լ� ��" << endl;//���� 4 
}
int main()
{
	cout << "main�Լ� ����" << endl;//���� 1
	testlocalobj();
	cout << "main�Լ� ��" << endl;//���� 6
	return 0;
}
/*
main�Լ� ����
testlocalobj �Լ� ����!
�����ڰ� ȣ��Ǿ���!
testlocalobj �Լ� ��
�Ҹ��ڰ� ȣ��Ǿ���!
main�Լ� ��
*/