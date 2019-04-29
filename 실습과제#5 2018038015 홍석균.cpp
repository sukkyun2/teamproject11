/* 작성자 : 홍석균
학번 : 2018038015
작성일자 : 4월 19일
과제 : 5주차
*/

#include <iostream>
#include <string>
using namespace std;

class Account
{
protected:
	string _owner;
	string _accountnum;
	int _asset;
public:
	void Initialize();
	void Initialize(string owner, string accountnum, int asset);
	void PrintTitle();
	void PrintData();
	void InputData();
	void ModifyData();
	int GetAsset();
private:
	inline void InputValue(int& ref);
	inline void InputValue(string&ref);
};

int main(int argc, char** argv)
{
	Account acc1, acc2;
	acc1.Initialize();
	acc2.Initialize("홍길동", "1392-192811-29291", 10000000);
	acc1.InputData();
	acc1.PrintTitle();
	acc1.PrintData();
	acc2.PrintData();
	acc1.ModifyData();
	acc1.PrintTitle();
	acc1.PrintData();
	acc2.PrintData();
	system("pause");
}

void Account::Initialize()
{ /*입력 : 없음
  출력 : 없음
  기능 : 멤버변수를 초기화한다.
  */
	_owner = '/0';
	_accountnum = '/0';
	_asset = 0;
}
void Account::Initialize(string owner, string accountnum, int asset)
{ /*입력 : sting형 변수,sting형 변수,int형 변수
  출력 : 없음
  기능 : 멤버변수에 넣을 값(owner,accountnum,asset)을 받고 받은값으로 초기화 해준다.
  */
	_owner = owner;
	_accountnum = accountnum;
	_asset = asset;
}
void Account::PrintTitle()
{ /*입력 : 없음
  출력 : 없음
  기능 : 타이틀바를 출력한다.
  */
	cout << "============================================================\n";
	cout.width(10);
	cout << "통장소유주";
	cout.width(10);
	cout << "통장번호";
	cout.width(10);
	cout << "통장잔액\n" << "============================================================\n";
}
void Account::PrintData()
{
	/*입력 : 없음
	출력 : 없음
	기능 : 멤버변수들을 출력한다.
	*/
	cout.width(10);
	cout << _owner;
	cout.width(10);
	cout << _accountnum;
	cout.width(10);
	cout << _asset << endl;
}
void Account::InputData()
{ /*입력 : 없음
  출력 : 없음
  기능 : 멤버변수들의 데이터를 입력받는다
  */

	cout << "통장소유주 :";
	InputValue(_owner);
	cout << "통장번호 :";
	InputValue(_accountnum);
	cout << "통장금액 :";
	InputValue(_asset);

}
void Account::ModifyData()
{ /*입력 : 없음
  출력 : 없음
  기능 : 멤버변수들의 값을 다시 받아서 입력해준다.
  */
	cout << "수정할 통장 소유주[" << _owner << "] :";
	InputValue(_owner);
	cout << "수정할 통장 번호[" << _accountnum << "] :";
	InputValue(_accountnum);
	cout << "수정할 금액[" << _asset << "] :";
	InputValue(_asset);

}
int Account::GetAsset()
{ /*입력 : 없음
  출력 : _asset
  기능 : _asset을 반환해준다.
  */
	return _asset;
}
inline void Account::InputValue(int& ref)
{    /*입력 : int형 레퍼런스
	 출력 : 없음
	 기능 : int형으로 사용되는 정보를 입력받는다.
	 */
	cin >> ref;
}

inline void Account::InputValue(string&ref)
{     /*입력 : string형 레퍼런스
	  출력 : 없음
	  기능 : 문자열 형식으로 되어있는 정보를 입력받는다
	  */
	getline(cin, ref);
	if (ref.empty())getline(cin, ref);

}

/*
publlic : 해당 클래스, 파생클래스, 클래스 밖에서 모두 접근 가능하다.
protected : 해당 클래스나 파생된 클래스에서의 접근은 가능하지만 클래스 밖에서의 접근은 불가능하다
private : 해당 클래스의 멤버함수에서만 접근이 가능하다

*/

