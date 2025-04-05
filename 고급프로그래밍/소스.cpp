#include "std_lib_facilities.h"
int word_cnt = 50; //�ʱ� �ܾ��� ���� ���������� �ʱ�ȭ
double menu_num; //��� â���� �Է¹޴� ���ѹ�
vector<string> word_list = { 
	"drift", "professional", "midnight", "scatter", "relevance", "visit",
	"disaster", "commerce", "coincide", "progress", "shift", "spell",
	"veil", "desk", "gown", "umbrella", "gregarious", "craftsman", "wriggle",
	"score", "deliver", "vote", "dirty", "chain", "road", "charter", "feign",
	"duck", "highway", "add", "van", "mutual", "bang", "table", "venture",
	"deficiency", "depend", "dimension", "holiday", "scrap", "unlike", "coast",
	"command", "base", "recommend", "spit", "corner", "huge", "economic", "sigh"}; //50���� ���ڿ����� �̸� ����

vector<string> easy_mode; //���� ��� ���ڿ� ����
vector<string> hard_mode; //����� ��� ���ڿ� ����
int hard_mode_cnt=0, easy_mode_cnt=0; //�� ���̵� ���ڿ� ����

//����� �Լ��� �̸� ����
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
	hard_mode.clear(); // ���� �ʱ�ȭ
	easy_mode.clear();
	hard_mode_cnt = 0, easy_mode_cnt = 0; //���� �� ���� �ʱ�ȭ
	for (const string &word : word_list) {
		if (word.length() >= 5) {//�ܾ��� ���̰� 5�� �̻��� ���ڿ�, Hard mode
			hard_mode.push_back(word);
			hard_mode_cnt += 1;
		}
		if (word.length() <= 5) {//�ܾ��� ���̰� 5�� ������ ���ڿ�, Easy mode
			easy_mode.push_back(word);
			easy_mode_cnt += 1;
		}
	}
}
void Hard_Mode(vector<string> &str)
{
	string A, B, ask, answer, result;
	int chance = 1, ok = 0;
	int random_num = randint(hard_mode_cnt-1); //Hard Mode(���� 5�̻�)�� ������ ���� �����ϱ� ���� ����
	A = hard_mode[random_num]; //������ hard_mode[random_num] �̸�, ���ڸ� ���� ���� ������ ���ڿ� ����
	for (int i = 0; i < 4; i++) {
		swap(A[randint(A.length()-1)], A[randint(A.length()-1)]); //�������� ���� ����
		B = A; //�Ʒ��� ���� �˻縦 ���� ����
		while (B == hard_mode[random_num]) { //�����µ��� ���� ���ڿ� ���� �� �ݺ�
			swap(A[randint(A.length()-1)], A[randint(A.length()-1)]); //�������� ���� ����
			B = A; //�ݺ����� ������ �����ߴ��� Ȯ���ϱ� ���� ����
		}	
	}
	ask = A; //���ڸ� ���� ����� ���� ������ ����

	cout << "I give you a jumbled word '" << ask << "'." << endl << endl;

	while (chance <= 5) { //��ȸ 5�� ī��Ʈ
		cout << "[" << chance << "/5] Guess the original word: ";
		cin >> answer;
		if (answer.length() < ask.length()) {
			answer += string(ask.length() - answer.length(), '-'); //���亸�� ª�� ���ڿ� �Է½� ������ �κп� '-'����
		}
		
		result = ""; //����, ���� �κ��� �˷��ֱ� ���� ���ڿ� �ʱ�ȭ
		
		if (hard_mode[random_num] == answer) { //���� �� ���� ��� �� �ݺ��� Ż��
			cout << endl;
			cout << "Congratulation! You got the answer right!" << endl << endl;
			ok = 1; //���� �˻縦 ���� �� ����
			break;
		}
		else {
			for (int i = 0; i < A.length(); ++i) {
				if (hard_mode[random_num][i] == answer[i]) { //������ �Է¹��� ���ڿ� ���� ���ڿ��� ��ġ�ϴ��� ������ �˻�
					result += hard_mode[random_num][i]; // ���� ���� �״�� ���
				}
				else {
					result += '-'; // Ʋ�� �κ� '-'�� �ٲ㼭 ���
				}
			}
			cout << ">> [" << result << "]" << endl << endl;
		}
		chance++; //�� ������ ��� �õ� ����
	}
	if (ok == 1) { //��ȸ�ȿ� ������ �������Ƿ� ���� ��¾��� �ڷΰ���
		Puzzle_Level();
	}
	else if (ok == 0) { //��ȸ�ȿ� ������ ������ �������Ƿ�, ���� ���� ��� �� �ڷΰ���
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
		swap(A[randint(A.length()-1)], A[randint(A.length()-1)]); //�������� ���� ����
		B = A;
		while (B == easy_mode[random_num]) { //�����µ��� ���� ���ڿ� ���� �� �ݺ�
			swap(A[randint(A.length()-1)], A[randint(A.length()-1)]); //�������� ���� ����
			B = A;
		}
	}
	ask = A; //���ڸ� ���� ����� ���� ������ ����
	
	cout << "I give you a jumbled word '" << ask << "'." << endl << endl;
	
	while (chance <= 3) { //��ȸ 3�� ī��Ʈ
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
					result += easy_mode[random_num][i]; // ���� ���� �״�� ���
				}
				else {
					result += '-'; // Ʋ�� ���� '-'
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
	Level_Sort(hard_mode,easy_mode); //���� ������ ���ĺ� ������ ����
	cout << "[ SOLVE PUZZLE ]" << endl;
	cout << "1. Easy mode" << endl;
	cout << "2. Hard Mode" << endl;
	cout << "3. Return" << endl << endl;
	while (1) { //3�� �Էµ��� �ʴ� �� �ݺ�
		cout << "Choose an option (1-3): ";
		if (cin >> menu_num) {
			if (menu_num == 1) {
				cout << endl;
				Easy_Mode(easy_mode);
				break; //ȣ�� �� �Լ� ��ü�� ���Ḧ ���� ��
			}
			else if (menu_num == 2) {
				cout << endl;
				Hard_Mode(hard_mode);
				break; //ȣ�� �� �Լ� ��ü�� ���Ḧ ���� �ۼ�
			}
			else if (menu_num == 3) {
				cout << endl;
				Start_Screen();
				break; //ȣ�� �� �Լ� ��ü�� ���Ḧ ���� �ۼ�
			}
		}
		else {
			// �߸��� �Է� ó��
			cin.clear(); // ���� ���� �ʱ�ȭ
			cin.ignore(10000, '\n'); // �Է� ���� ����
		}
	}
}
void Start_Screen()
{
	cout << "<<< WORD JUMBLE >>>" << endl;
	cout << "1. Manage List" << endl;
	cout << "2. Solve Puzzle" << endl;
	cout << "3. Exit" << endl << endl;
	while (1) { //3�� �Էµ��� �ʴ� �� �ݺ�
		cout << "Choose an option (1-3): ";
		if (cin >> menu_num) {
			if (menu_num == 1) {
				cout << endl;
				Manage_List();
				break; //ȣ�� �� �Լ� ��ü�� ���Ḧ ���� �ۼ�
			}
			else if (menu_num == 2) {
				cout << endl;
				Puzzle_Level();
				break; //ȣ�� �� �Լ� ��ü�� ���Ḧ ���� �ۼ�
			}
			else if (menu_num == 3) {
				cout << endl;
				cout << "Good bye!!!" << endl;
				break; //ȣ�� �� �Լ� ��ü�� ���Ḧ ���� �ۼ�
			}
		}
		else {
			// �߸��� �Է� ó��
			cin.clear(); // ���� ���� �ʱ�ȭ
			cin.ignore(10000, '\n'); // �Է� ���� ����
		}
	}
}
void Add_Word()
{	
	bool check=1; //�ߺ� �˻縦 ���� ��
	string new_word;
	cout << "Input a new word: ";
	cin >> new_word;//�߰��ϰ� ���� ���ο� �ܾ �Է�
	for (const string &word : word_list) { //vector�� ��ȸ�ϹǷ� ������� �ݺ����� ���
		if (new_word == word) {
			cout << "The word '" << new_word << "' already exists in the list." << endl << endl;
			check = 0; //�ߺ��Ǿ����Ƿ� 0 ����
			break; //�ߺ��� ��� �� �̻� �˻簡 �ʿ� �����Ƿ� �ݺ��� Ż��
		}
	}
	if (check == 0) { //�ߺ��� �ܾ� �߰����� �ʰ� �ٷ� �ڷΰ���
		Manage_List();
	}
	else if (check == 1) { //�ߺ����� �ʰ� ���� 1�� ������ �ʾұ⿡, �ܾ� �߰�
		word_list.push_back(new_word);
		cout << "The word " << "'" << new_word << "' " << "has been succesfully inserted in the list." << endl << endl;
		word_cnt++; //�ܾ �߰��Ǿ����Ƿ� �ܾ��� �� ���� 1 ����
		Level_Sort(hard_mode,easy_mode); //�߰��� �ܾ �����Ͽ� ���ĺ� ������ �������ϱ� ���� ȣ��
		Manage_List(); //���� ������ �ڷΰ���
	}
}
void Print_Words()
{
	cout << "A total of " << word_cnt << " words are available:" << endl;
	sort(word_list); //���ĺ������� ����
	for (const auto& word : word_list) {
		cout << word << endl;
	}//vector�� ��ȸ�ϹǷ� ������� �ݺ����� ��� 
	cout << endl;
	Manage_List();
}
void Manage_List()
{   //�ʱ�ȭ�鿡�� 1���� ������ �� �Ѿ���� �޴�
	cout << "[ MANAGE LIST ]" << endl;
	cout << "1. Print Words" << endl;
	cout << "2. Add Word" << endl;
	cout << "3. Return" << endl << endl;
	while (1) { //1-3�̿ܿ� ���ڰ� �ԷµǸ� �ݺ�
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
			// �߸��� �Է� ó��
			cin.clear(); // ���� ���� �ʱ�ȭ
			cin.ignore(10000, '\n'); // �Է� ���� ����
		}
	}
}
int main()
{   //�����Լ������� �ʱ�ȭ�鸸 ����
	// ���� �ܰ��� ���� ��°� �Է��� �� �Լ����� ȣ���� �ݺ���
	Start_Screen(); //�ʱ�ȭ�� ���
	return 0;
}