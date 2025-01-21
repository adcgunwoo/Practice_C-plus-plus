//메신저를 구현 해보자
//텍스트
//이미지
#include <iostream>
#include <string>
using namespace std;
class Image { //사진을 불러오는 클래스
public:
	operator string() {//형변환 연산자 오버로딩
		return "사진"; //예시로 "사진"이라는 글자를 반환
	}
};
class Message {
public:
	Message(int sendTime, string sendName) {
		this->sendTime = sendTime; //this포인터 헷갈리네
		this->sendName = sendName;
	}
	int GetSendTime()const { return sendTime; }
	string GetSendName() const { return sendName; }
private:
	int sendTime;//보낸 시간
	string sendName;//발신자 이름
};
class TextMessage : public Message { //텍스트 클래스
public:
	TextMessage(int sendTime, string sendName, string text)
		: Message(sendTime, sendName) {//생성자 위임
		this->text = text;
	}
	string GetText()const { return text; }
private:
	string text; //내용
};
class ImageMessage : public Message {
public:
	ImageMessage(int sendTime, string sendName, Image *image)
		:Message(sendTime, sendName) {//생성자 위임
		this->image = image; //얕은 복사(복습하자)
	}
	Image *GetImage() const { return image; }
private:
	Image* image;
	//이미지를 통째로 담으면 클래스 자체의 용량이 커지므로
	//이미지를 직접 저장이 아닌 참조 
	//즉, 포인터의 형태로 저장하는게 이득
};
int main()
{
	//두들 : "안녕"
	//두들 : "강아지 사진"
	Image* p_dogImage = new Image();
	TextMessage* hello = new TextMessage(10, "건우", "안녕");
	ImageMessage* dog = new ImageMessage(20, "두들", p_dogImage);

	cout << "보낸 시간 : " << hello->GetSendTime() << endl;
	cout << "보낸 사람 : " << hello->GetSendName() << endl;
	cout << "내용 : " << hello->GetText() << endl;
	//->는 포인터가 가르키는 값을 의미하는 듯하다 헬로와 도그는 둘다 포인터
	cout << endl;

	cout << "보낸 시간 : " << dog->GetSendTime() << endl;
	cout << "보낸 사람 : " << dog->GetSendName() << endl;
	cout << "내용 : " << (string)*dog->GetImage() << endl;
	//두들 낙서 76강 12분 7초 참고(형변환을 해주었음)
	cout << endl;
	delete hello;
	delete dog;
	delete p_dogImage;
}