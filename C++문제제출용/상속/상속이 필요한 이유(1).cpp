//�޽����� ���� �غ���
//�ؽ�Ʈ
//�̹���
#include <iostream>
#include <string>
using namespace std;
class Image { //������ �ҷ����� Ŭ����
public:
	operator string() {//����ȯ ������ �����ε�
		return "����"; //���÷� "����"�̶�� ���ڸ� ��ȯ
	}
};
class Message {
public:
	Message(int sendTime, string sendName) {
		this->sendTime = sendTime; //this������ �򰥸���
		this->sendName = sendName;
	}
	int GetSendTime()const { return sendTime; }
	string GetSendName() const { return sendName; }
private:
	int sendTime;//���� �ð�
	string sendName;//�߽��� �̸�
};
class TextMessage : public Message { //�ؽ�Ʈ Ŭ����
public:
	TextMessage(int sendTime, string sendName, string text)
		: Message(sendTime, sendName) {//������ ����
		this->text = text;
	}
	string GetText()const { return text; }
private:
	string text; //����
};
class ImageMessage : public Message {
public:
	ImageMessage(int sendTime, string sendName, Image *image)
		:Message(sendTime, sendName) {//������ ����
		this->image = image; //���� ����(��������)
	}
	Image *GetImage() const { return image; }
private:
	Image* image;
	//�̹����� ��°�� ������ Ŭ���� ��ü�� �뷮�� Ŀ���Ƿ�
	//�̹����� ���� ������ �ƴ� ���� 
	//��, �������� ���·� �����ϴ°� �̵�
};
int main()
{
	//�ε� : "�ȳ�"
	//�ε� : "������ ����"
	Image* p_dogImage = new Image();
	TextMessage* hello = new TextMessage(10, "�ǿ�", "�ȳ�");
	ImageMessage* dog = new ImageMessage(20, "�ε�", p_dogImage);

	cout << "���� �ð� : " << hello->GetSendTime() << endl;
	cout << "���� ��� : " << hello->GetSendName() << endl;
	cout << "���� : " << hello->GetText() << endl;
	//->�� �����Ͱ� ����Ű�� ���� �ǹ��ϴ� ���ϴ� ��ο� ���״� �Ѵ� ������
	cout << endl;

	cout << "���� �ð� : " << dog->GetSendTime() << endl;
	cout << "���� ��� : " << dog->GetSendName() << endl;
	cout << "���� : " << (string)*dog->GetImage() << endl;
	//�ε� ���� 76�� 12�� 7�� ����(����ȯ�� ���־���)
	cout << endl;
	delete hello;
	delete dog;
	delete p_dogImage;
}