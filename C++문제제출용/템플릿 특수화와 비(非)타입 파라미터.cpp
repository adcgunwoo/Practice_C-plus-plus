//비(非)타입 파라미터
#define CRT_SECRE_NO_WARNINGS
#include <iostream>
#include <string>
using namespace std;
template<typename T, int n> //n은 차원
class Vector { //다차원 벡터
public:
	/*Vector() {
		comp = new T[n]; //배열 할당
	}
	~Vector(){
		delete[] comp;
	}*/
	T GetComp(int i) {//i번째 성분을 리턴
		return comp[i];
	}
	void SetComp(int i, T val) {
		comp[i] = val;
	}
	Vector operator+(const Vector& rhs) {
		Vector res;
		for (int i = 0; i < n; i++) {
			res.comp[i] = this->comp[i] + rhs.comp[i];
			//res.SetComp(i, this->GetComp(i) + rhs.GetComp(i));
		}
		return res;
	}
private:
	//T* comp;
	T comp[n];//벡터의 성분, 배열이 멤버변수면 항상 깊은 복사
};
int main()
{
	Vector<float, 3> v1,v2;
	Vector<float, 2> v4;
	v1.SetComp(0, 2); 
	v1.SetComp(1, 3);
	v1.SetComp(2, 4);

	v2.SetComp(0, 5);
	v2.SetComp(1, 6);
	v2.SetComp(2, 7);

	Vector<float, 3> v3 = v1 + v2;

	cout << v3.GetComp(0) << ", " << v3.GetComp(1) << ", " << v3.GetComp(2) << endl;
}