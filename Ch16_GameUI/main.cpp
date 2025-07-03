
#include <iostream>
#include <vector>
#include <Windows.h>

using namespace std;

class Color
{
public:
	static const string RESET;
	static const string UNDERLINE;

	static const string BLACK, RED, GREEN, YELLOW, BLUE, MAGENTA, CYAN, WHITE;
	static const string BG_RED, BG_GREEN, BG_YELLOW, BG_BLUE, BG_MAGENTA, BG_CYAN, BG_WHITE;

	static void Print(const string& BG, const string& textColor, const string& message)
	{
		cout << BG << textColor << message << Color::RESET;
	}
};

const string Color::RESET      = "\033[0m";
const string Color::UNDERLINE  = "\033[4m";
const string Color::BLACK      = "\033[30m";
const string Color::RED        = "\033[31m";
const string Color::GREEN      = "\033[32m";
const string Color::YELLOW     = "\033[33m";
const string Color::BLUE       = "\033[34m";
const string Color::MAGENTA    = "\033[35m";
const string Color::CYAN       = "\033[36m";
const string Color::WHITE      = "\033[37m";

const string Color::BG_RED     = "\033[41m";
const string Color::BG_GREEN   = "\033[42m";
const string Color::BG_YELLOW  = "\033[43m";
const string Color::BG_BLUE    = "\033[44m";
const string Color::BG_MAGENTA = "\033[45m";
const string Color::BG_CYAN    = "\033[46m";
const string Color::BG_WHITE   = "\033[47m";

void PrintMenu()
{
	cout << "===== 메뉴 =====" << endl;	
	cout << Color::RED<< "1. "<< Color::RESET << "새로운 게임" << endl;
	cout << "2. " << "불러오기" << endl;
	cout << "3. " << "설정" << endl;
	cout << "4. " << "종료" << endl;
}

void PrintProgressBar(int current, int total, int width = 30)
{
	float progress = (float)current / total;
	int filled = (int)(width * progress);      /////////////////////////

	for (int i = 0;i < filled;i++)
	{
		cout << Color::GREEN << "■";
	}

	for (int i = filled;i < width;i++)
	{
		cout << Color::WHITE << "■";
	}

	cout << Color::RESET <<" " << (int)(progress * 100) << "%";
}

void LoadingAnimation()
{
	cout << "로딩 진행 현황을 그려준다." << endl;
	for (int i = 0;i < 20;i++)
	{
		PrintProgressBar(i, 20);
		cout << endl;
		cout.flush();
		Sleep(100);
	}
	//system("cls");
}

void DrawBox()
{
	cout << Color::BG_CYAN << "+------------+" << Color::RESET<<endl;
	cout << "|            |" << endl;
	cout << "|            |" << endl;
	cout << "|            |" << endl;
	cout << "|            |" << endl;
	cout << "+------------+" << endl;
}

// 30~ 39 글자색, 40~44 배경색
int main()
{
	//cout <<"\033[47m" <<"글자" <<"\033[0m" << endl;
	//cout<<"\033[33m" <<"글자"<< "\033[0m" << endl; 
	//cout<<"\033[4m" <<"글자"<< "\033[0m" << endl;  

	//cout << Color::BG_BLUE << Color::GREEN << "===TITLE===" << Color::RESET << endl;

	//Color::Print(Color::BG_BLUE, Color::GREEN, "===TITLE===");

	PrintMenu();

	for (int i = 0;i < 100;i++)
	{
		PrintProgressBar(i, 100);
	}


}