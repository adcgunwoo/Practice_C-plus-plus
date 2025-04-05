#include "std_lib_facilities.h"
int word_cnt = 50; //초기 단어의 개수 전역변수로 초기화
double menu_num; //모든 창에서 입력받는 모드넘버
vector<string> word_list = { 
	"drift", "professional", "midnight", "scatter", "relevance", "visit",
	"disaster", "commerce", "coincide", "progress", "shift", "spell",
	"veil", "desk", "gown", "umbrella", "gregarious", "craftsman", "wriggle",
	"score", "deliver", "vote", "dirty", "chain", "road", "charter", "feign",
	"duck", "highway", "add", "van", "mutual", "bang", "table", "venture",
	"deficiency", "depend", "dimension", "holiday", "scrap", "unlike", "coast",
	"command", "base", "recommend", "spit", "corner", "huge", "economic", "sigh"}; //50개의 문자열들을 미리 정의

vector<string> easy_mode; //쉬움 모드 문자열 집합
vector<string> hard_mode; //어려움 모드 문자열 집합
int hard_mode_cnt=0, easy_mode_cnt=0; //각 난이도 문자열 개수

//사용할 함수들 미리 정의
void Start_Screen();
void Manage_List(); 
void Print_Words();
void Add_Word();
void Puzzle_Level();
void Level_Sort(vector<string> &st1, vector<string> &st2);
void Easy_Mode(vector<string> &str);
void Hard_Mode(vector<string> &str);

void Level_Sort(vector<string> &st1, vector<string> &st2)
{
	hard_mode.clear(); // 벡터 초기화
	easy_mode.clear();
	hard_mode_cnt = 0, easy_mode_cnt = 0; //정렬 전 변수 초기화
	for (const string &word : word_list) {
		if (word.length() >= 5) {//단어의 길이가 5개 이상인 문자열, Hard mode
			hard_mode.push_back(word);
			hard_mode_cnt += 1;
		}
		if (word.length() <= 5) {//단어의 길이가 5개 이하인 문자열, Easy mode
			easy_mode.push_back(word);
			easy_mode_cnt += 1;
		}
	}
}
void Hard_Mode(vector<string> &str)
{
	string A, B, ask, answer, result;
	int chance = 1, ok = 0;
	int random_num = randint(hard_mode_cnt-1); //Hard Mode(길이 5이상)중 랜덤한 수를 결정하기 위해 대입
	A = hard_mode[random_num]; //정답이 hard_mode[random_num] 이면, 문자를 섞기 위해 임의의 문자열 대입
	for (int i = 0; i < 4; i++) {
		swap(A[randint(A.length()-1)], A[randint(A.length()-1)]); //랜덤으로 글자 섞기
		B = A; //아래와 같은 검사를 위해 대입
		while (B == hard_mode[random_num]) { //섞었는데도 원래 문자와 같을 때 반복
			swap(A[randint(A.length()-1)], A[randint(A.length()-1)]); //랜덤으로 글자 섞기
			B = A; //반복문의 조건을 충족했는지 확인하기 위한 대입
		}	
	}
	ask = A; //문자를 섞고 퀴즈로 물을 변수에 대입

	cout << "I give you a jumbled word '" << ask << "'." << endl << endl;

	while (chance <= 5) { //기회 5번 카운트
		cout << "[" << chance << "/5] Guess the original word: ";
		cin >> answer;
		if (answer.length() < ask.length()) {
			answer += string(ask.length() - answer.length(), '-'); //정답보다 짧은 문자열 입력시 나머지 부분에 '-'대입
		}
		
		result = ""; //정답, 오답 부분을 알려주기 위한 문자열 초기화
		
		if (hard_mode[random_num] == answer) { //정답 시 문장 출력 후 반복문 탈출
			cout << endl;
			cout << "Congratulation! You got the answer right!" << endl << endl;
			ok = 1; //정답 검사를 위한 수 대입
			break;
		}
		else {
			for (int i = 0; i < A.length(); ++i) {
				if (hard_mode[random_num][i] == answer[i]) { //일일히 입력받은 문자와 정답 문자열이 일치하는지 일일히 검사
					result += hard_mode[random_num][i]; // 맞춘 문자 그대로 출력
				}
				else {
					result += '-'; // 틀린 부분 '-'로 바꿔서 출력
				}
			}
			cout << ">> [" << result << "]" << endl << endl;
		}
		chance++; //못 맞췄을 경우 시도 증가
	}
	if (ok == 1) { //기회안에 정답을 맞췄으므로 별도 출력없이 뒤로가기
		Puzzle_Level();
	}
	else if (ok == 0) { //기회안에 정답을 맞추지 못했으므로, 실패 문장 출력 후 뒤로가기
		cout << "Oops! You failed to solve the puzzle..." << endl;
		cout << "The coorect answer is '" << hard_mode[random_num] << "'." << endl << endl;
		Puzzle_Level();
	}
}
void Easy_Mode(vector<string> &str)
{
	string A, B, ask, answer, result;
	int  chance=1, ok=0,check_cnt=0;
	int random_num = randint(easy_mode_cnt - 1);
	A = easy_mode[random_num];
	for (int i = 0; i < 2; i++) {
		swap(A[randint(A.length()-1)], A[randint(A.length()-1)]); //랜덤으로 글자 섞기
		B = A;
		while (B == easy_mode[random_num]) { //섞었는데도 원래 문자와 같을 때 반복
			swap(A[randint(A.length()-1)], A[randint(A.length()-1)]); //랜덤으로 글자 섞기
			B = A;
		}
	}
	ask = A; //문자를 섞고 퀴즈로 물을 변수에 대입
	
	cout << "I give you a jumbled word '" << ask << "'." << endl << endl;
	
	while (chance <= 3) { //기회 3번 카운트
		cout << "[" << chance << "/3] Guess the original word: ";
		cin >> answer;
		if (answer.length() < ask.length()) {
			answer += string(ask.length() - answer.length(), '-');
		}
		result = "";
		if (easy_mode[random_num] == answer) {
			cout << endl;
			cout << "Congratulation! You got the answer right!" << endl << endl;
			ok = 1;
			break;
		}
		else {
			for (int i = 0; i < A.length(); ++i) {
				if (easy_mode[random_num][i] == answer[i]) {
					result += easy_mode[random_num][i]; // 맞춘 문자 그대로 출력
				}
				else {
					result += '-'; // 틀린 문자 '-'
				}
			}
			cout << ">> [" << result << "]" << endl << endl;
		}
		chance++;
	}
	if (ok == 1) {
		Puzzle_Level();
	}
	else if (ok == 0) {
		cout << "Oops! You failed to solve the puzzle..." << endl;
		cout << "The coorect answer is '" << easy_mode[random_num] << "'." << endl << endl;
		Puzzle_Level();
	}
}
void Puzzle_Level()
{
	Level_Sort(hard_mode,easy_mode); //문제 출제전 알파벳 순으로 정렬
	cout << "[ SOLVE PUZZLE ]" << endl;
	cout << "1. Easy mode" << endl;
	cout << "2. Hard Mode" << endl;
	cout << "3. Return" << endl << endl;
	while (1) { //3이 입력되지 않는 한 반복
		cout << "Choose an option (1-3): ";
		if (cin >> menu_num) {
			if (menu_num == 1) {
				cout << endl;
				Easy_Mode(easy_mode);
				break; //호출 후 함수 자체의 종료를 위해 작
			}
			else if (menu_num == 2) {
				cout << endl;
				Hard_Mode(hard_mode);
				break; //호출 후 함수 자체의 종료를 위해 작성
			}
			else if (menu_num == 3) {
				cout << endl;
				Start_Screen();
				break; //호출 후 함수 자체의 종료를 위해 작성
			}
		}
		else {
			// 잘못된 입력 처리
			cin.clear(); // 오류 상태 초기화
			cin.ignore(10000, '\n'); // 입력 버퍼 비우기
		}
	}
}
void Start_Screen()
{
	cout << "<<< WORD JUMBLE >>>" << endl;
	cout << "1. Manage List" << endl;
	cout << "2. Solve Puzzle" << endl;
	cout << "3. Exit" << endl << endl;
	while (1) { //3이 입력되지 않는 한 반복
		cout << "Choose an option (1-3): ";
		if (cin >> menu_num) {
			if (menu_num == 1) {
				cout << endl;
				Manage_List();
				break; //호출 후 함수 자체의 종료를 위해 작성
			}
			else if (menu_num == 2) {
				cout << endl;
				Puzzle_Level();
				break; //호출 후 함수 자체의 종료를 위해 작성
			}
			else if (menu_num == 3) {
				cout << endl;
				cout << "Good bye!!!" << endl;
				break; //호출 후 함수 자체의 종료를 위해 작성
			}
		}
		else {
			// 잘못된 입력 처리
			cin.clear(); // 오류 상태 초기화
			cin.ignore(10000, '\n'); // 입력 버퍼 비우기
		}
	}
}
void Add_Word()
{	
	bool check=1; //중복 검사를 위한 불
	string new_word;
	cout << "Input a new word: ";
	cin >> new_word;//추가하고 싶은 새로운 단어를 입력
	for (const string &word : word_list) { //vector를 순회하므로 범위기반 반복으로 출력
		if (new_word == word) {
			cout << "The word '" << new_word << "' already exists in the list." << endl << endl;
			check = 0; //중복되었으므로 0 대입
			break; //중복된 경우 더 이상 검사가 필요 없으므로 반복문 탈출
		}
	}
	if (check == 0) { //중복된 단어 추가하지 않고 바로 뒤로가기
		Manage_List();
	}
	else if (check == 1) { //중복되지 않고 값이 1로 변하지 않았기에, 단어 추가
		word_list.push_back(new_word);
		cout << "The word " << "'" << new_word << "' " << "has been succesfully inserted in the list." << endl << endl;
		word_cnt++; //단어가 추가되었으므로 단어의 총 개수 1 증가
		Level_Sort(hard_mode,easy_mode); //추가된 단어를 포함하여 알파벳 순으로 재정렬하기 위한 호출
		Manage_List(); //정렬 끝나고 뒤로가기
	}
}
void Print_Words()
{
	cout << "A total of " << word_cnt << " words are available:" << endl;
	sort(word_list); //알파벳순으로 정렬
	for (const auto& word : word_list) {
		cout << word << endl;
	}//vector를 순회하므로 범위기반 반복으로 출력 
	cout << endl;
	Manage_List();
}
void Manage_List()
{   //초기화면에서 1번을 눌렀을 때 넘어오는 메뉴
	cout << "[ MANAGE LIST ]" << endl;
	cout << "1. Print Words" << endl;
	cout << "2. Add Word" << endl;
	cout << "3. Return" << endl << endl;
	while (1) { //1-3이외에 숫자가 입력되면 반복
		cout << "Choose an option (1-3): ";
		if (cin >> menu_num) {
			if (menu_num == 1) {
				cout << endl;
				Print_Words();
				break;
			}
			else if (menu_num == 2) {
				cout << endl;
				Add_Word();
				break;
			}
			else if (menu_num == 3) {
				cout << endl;
				Start_Screen();
				break;
			}
		}
		else {
			// 잘못된 입력 처리
			cin.clear(); // 오류 상태 초기화
			cin.ignore(10000, '\n'); // 입력 버퍼 비우기
		}
	}
}
int main()
{   //메인함수에서는 초기화면만 구현
	// 다음 단계의 문장 출력과 입력은 각 함수에서 호출을 반복함
	Start_Screen(); //초기화면 출력
	return 0;
}