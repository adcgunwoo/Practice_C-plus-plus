//������(�Ͻ���) ����ȯ (implicit conversion)
//����� ����ȯ (explicit conversion)
#include <iostream> //�� ������� ��Ʈ���� ������ �Ʒ��� ���̰�
#include <string> //�־ �߰���

using namespace std;
class Item {
public:
	Item(int num) :num(num) { //��ȯ �������� ���ҵ� ��
		cout << "Item(int)" << endl;
	}
	Item(string name) : name(name) {
		cout << "Item(string)" << endl;
	}
	Item(int num,string name):num(num),name(name){
		cout << "Item(int, string)" << endl;
	}
	//������ ������ �����ε��� int operator �̷� �������� ����ȯ�� �̷� �����̴�.
	
	//�Ʒ��� int ���� ����ȯ ������ �����ε�
	operator int() const { //���� ������ �����Ƿ� const
		return num;
	}
	//string������ ����ȯ ������ �����ε�
	operator string() const { //to_string �Լ��� ���ڸ� ���ڷ� �ٲ���
		return to_string(num) + " : " + name;
		//string ������� ������� +�� ���ڿ��� ������ ����
	}
	void print() {
		cout << num << " : " << name << endl;
	}
private:
	int num;
	string name;
};
void println(string s) {
	cout << s << endl;
}
void println(int n) {
	cout << n << endl;
}
int main()
{
	Item i1(1);
	Item i2 = Item(2);
	Item i3 = 3;
	i1 = 4; // ������ ��ȯ�� ȣ���� ��
	Item i4 = (Item)4; //����� ����ȯ
	
	Item i5(5);
	i5 = (string)"stone";

	Item i6(1, "grass");
	Item i7 = { 2,"dirt" };
	Item i8{ 3,"wood" };

	int itemNum1 = (int)i8; //����� ����ȯ
	int itemNum2 = i7; //������ ����ȯ
	cout << itemNum1 << endl;
	cout << itemNum2 << endl;

	println((string)i8); //����� ����ȯ
	//println(i8); ������ ����ȯ, ���� �߻� 
	println((int)i8); //������ ����ȯ
}
//explicit�� ����ȯ �����ε��� �ٿ��� 
//����� ����ȯ�� �����ϰ� ��