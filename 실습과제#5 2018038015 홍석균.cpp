/* �ۼ��� : ȫ����
�й� : 2018038015
�ۼ����� : 4�� 19��
���� : 5����
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
	acc2.Initialize("ȫ�浿", "1392-192811-29291", 10000000);
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
{ /*�Է� : ����
  ��� : ����
  ��� : ��������� �ʱ�ȭ�Ѵ�.
  */
	_owner = '/0';
	_accountnum = '/0';
	_asset = 0;
}
void Account::Initialize(string owner, string accountnum, int asset)
{ /*�Է� : sting�� ����,sting�� ����,int�� ����
  ��� : ����
  ��� : ��������� ���� ��(owner,accountnum,asset)�� �ް� ���������� �ʱ�ȭ ���ش�.
  */
	_owner = owner;
	_accountnum = accountnum;
	_asset = asset;
}
void Account::PrintTitle()
{ /*�Է� : ����
  ��� : ����
  ��� : Ÿ��Ʋ�ٸ� ����Ѵ�.
  */
	cout << "============================================================\n";
	cout.width(10);
	cout << "���������";
	cout.width(10);
	cout << "�����ȣ";
	cout.width(10);
	cout << "�����ܾ�\n" << "============================================================\n";
}
void Account::PrintData()
{
	/*�Է� : ����
	��� : ����
	��� : ����������� ����Ѵ�.
	*/
	cout.width(10);
	cout << _owner;
	cout.width(10);
	cout << _accountnum;
	cout.width(10);
	cout << _asset << endl;
}
void Account::InputData()
{ /*�Է� : ����
  ��� : ����
  ��� : ����������� �����͸� �Է¹޴´�
  */

	cout << "��������� :";
	InputValue(_owner);
	cout << "�����ȣ :";
	InputValue(_accountnum);
	cout << "����ݾ� :";
	InputValue(_asset);

}
void Account::ModifyData()
{ /*�Է� : ����
  ��� : ����
  ��� : ����������� ���� �ٽ� �޾Ƽ� �Է����ش�.
  */
	cout << "������ ���� ������[" << _owner << "] :";
	InputValue(_owner);
	cout << "������ ���� ��ȣ[" << _accountnum << "] :";
	InputValue(_accountnum);
	cout << "������ �ݾ�[" << _asset << "] :";
	InputValue(_asset);

}
int Account::GetAsset()
{ /*�Է� : ����
  ��� : _asset
  ��� : _asset�� ��ȯ���ش�.
  */
	return _asset;
}
inline void Account::InputValue(int& ref)
{    /*�Է� : int�� ���۷���
	 ��� : ����
	 ��� : int������ ���Ǵ� ������ �Է¹޴´�.
	 */
	cin >> ref;
}

inline void Account::InputValue(string&ref)
{     /*�Է� : string�� ���۷���
	  ��� : ����
	  ��� : ���ڿ� �������� �Ǿ��ִ� ������ �Է¹޴´�
	  */
	getline(cin, ref);
	if (ref.empty())getline(cin, ref);

}

/*
publlic : �ش� Ŭ����, �Ļ�Ŭ����, Ŭ���� �ۿ��� ��� ���� �����ϴ�.
protected : �ش� Ŭ������ �Ļ��� Ŭ���������� ������ ���������� Ŭ���� �ۿ����� ������ �Ұ����ϴ�
private : �ش� Ŭ������ ����Լ������� ������ �����ϴ�

*/

