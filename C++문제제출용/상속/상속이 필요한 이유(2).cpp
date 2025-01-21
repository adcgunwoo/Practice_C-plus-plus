#include <iostream>
#include <string>
using namespace std;
class Image {
public:
	operator string() {
		return "사진";
	}
};
class Message {
public:
	Message(int sendTime, string sendName)
		: sendTime(sendTime), sendName(sendName) {
	}
	int GetSendTime() const { return sendTime; }
	string GetSendName() const { return sendName; }
	virtual string GetContent() const { return ""; }
private:
	int sendTime;
	string sendName;
};
class TextMessage : public Message {
public:
	TextMessage(int sendTime, string sendName, string text)
		: Message(sendTime, sendName), text(text) {
	}
	string GetText() const { return text; }
	string GetContent() const{ return text; }
private:
	string text;
};
class ImageMessage : public Message {
public:
	ImageMessage(int sendTime, string sendName, Image* image)
		: Message(sendTime, sendName), p_image(image) {
	}
	Image* GetImage() const { return p_image; }
	string GetContent() const { return (string)*p_image; }
private:
	Image* p_image;
};
void printMessage(Message* m) {
	cout << "보낸 시간 : " << m->GetSendTime() << endl;
	cout << "보낸 사람 : " << m->GetSendName() << endl;
	cout << "  내 용   : " << m->GetContent() << endl;
	cout << endl;
}
/*void printMessage(const Message& m) {
	cout << "보낸 시간 : " << m.GetSendTime() << endl;
	cout << "보낸 사람 : " << m.GetSendName() << endl;
	cout << "  내 용   : " << m.GetContent() << endl;
	cout << endl;
}*/
int main() {
	Image* p_dogImage = new Image();

	Message* messages[]{
		new TextMessage(10, "두들", "안녕"),
		new ImageMessage(20, "두들", p_dogImage)
	}; //클래스 배열

	for (Message* m : messages) {
		printMessage(m);
	}

	/*for (int i = 0; i < 4; i++) {
		printMessage(messages[i]);
	}*/

	TextMessage* hello = new TextMessage(10, "두들", "안녕");
	ImageMessage* dog = new ImageMessage(20, "두들", p_dogImage);

	printMessage(hello);
	printMessage(dog);
	
	/*printMessage(*hello);
	printMessage(*dog);*/
	//레퍼런스로도 가능

	delete p_dogImage;
	delete hello;
	delete dog;
}
