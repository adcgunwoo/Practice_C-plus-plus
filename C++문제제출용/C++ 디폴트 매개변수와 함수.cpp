#include <iostream>
//���÷� �������� �ݴ� ���� �ڵ� �����
int inven[64] = { 0 };
int score(0);
using namespace std;
void getitem(int itemID, int cnt=1, int sc=0)
{                       
	inven[itemID] += cnt;
	score += sc;
}
//����Ʈ �Ű����� : ����Ʈ ���� ������ ������ �ԷµǾ���
//���� ���ʿ��� ������ �Է¹޴� ���� ���� �ؾ���
//cnt�� �ƹ� ���� ������ ������(�ϳ��� ������) 1�� ����
//sc�� �ƹ� ���� ������ ������(������ ���� ���ϸ�) 0�� ����
int main()
{
	getitem(6, 5);//6�� ������ 5�� ����
	getitem(3, 2);
	getitem(3);//3�� ������ 1��
	getitem(11, 34, 7000);//11�� ������ 34�� ����, 7000�� �߰�
	
	cout << score<<endl;//���� ���
	for (int i = 0; i < 16; i++) {
		cout << inven[i] << ' ';//������â ���
	}
	cout << endl;
	
	return 0;
}