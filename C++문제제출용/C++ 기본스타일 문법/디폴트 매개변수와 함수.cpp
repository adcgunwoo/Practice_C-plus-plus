#include <iostream>
//예시로 아이템을 줍는 게임 코드 만들기
int inven[64] = { 0 };
int score(0);
using namespace std;
void getitem(int itemID, int cnt=1, int sc=0)
{                       
	inven[itemID] += cnt;
	score += sc;
}
//디폴트 매개변수 : 디폴트 값이 없으면 무조건 입력되야함
//따라서 왼쪽에는 무조건 입력받는 값이 오게 해야함
//cnt에 아무 값이 들어오지 않으면(하나만 주으면) 1이 대입
//sc에 아무 값이 들어오지 않으면(점수를 얻지 못하면) 0이 대입
int main()
{
	getitem(6, 5);//6번 아이템 5개 얻음
	getitem(3, 2);
	getitem(3);//3번 아이템 1개
	getitem(11, 34, 7000);//11번 아이템 34개 얻음, 7000점 추가
	
	cout << score<<endl;//점수 출력
	for (int i = 0; i < 16; i++) {
		cout << inven[i] << ' ';//아이템창 출력
	}
	cout << endl;
	
	return 0;
}
