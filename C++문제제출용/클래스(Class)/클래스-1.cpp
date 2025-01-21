#include <iostream>
using namespace std;
//구조체와 클래스의 차이
//클래스=자료 저장+자료 처리=변수+함수
//클래스(타입):특정한 용도를 수행하기 위한 변수와 함수를 모아 둔 틀(자료형)
//객체(오브젝트):그 틀을 이용하여 찍어낸 개체(변수, 메모리 상의 공간)

//텔리비전 만들기
// 지시자의 종류 : public, private, protected
struct tv {
	//struct와 class의 차이 
	//struct는 private를 안쓰면 public의 속성
	//class는 안 써도 private의 속성을 지님
private:
	bool power;
	int channel;
	int volume;
public:
	void setvolume(int vol) {
		if (vol >= 0 && vol <= 100) {
			volume = vol;
			cout << "볼륨을 " << vol << "으(로) 바꿨습니다." << endl;
		}
	}
	void on() {
		power = true;
		cout << "TV를 켰습니다." << endl;
	}
	void off() {
		power = false;
		cout << "TV를 껐습니다." << endl;
	}
	void setchannel(int cnl) {
		if (cnl >= 1 && cnl <= 99) {
			channel = cnl;
			cout << "채널을 " << cnl << "으(로) 바꿨습니다." << endl;
		}
	}
};

int main()
{
	tv lg;
	cout << "TV 기본 설정입니다." << endl;
	lg.on();
	lg.setchannel(10);
	lg.setvolume(50);
	lg.off();

	return 0;
}
