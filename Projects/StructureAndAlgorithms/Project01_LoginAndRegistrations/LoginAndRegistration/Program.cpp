#include "iostream"
#include "string"
#include "fstream"

using namespace std;

#define Max 100

typedef struct user {
	string userName;
	string passWord;
}User;

int DisplayMenu()
{
	int option = 0;
	cout << "1. Login" << endl;
	cout << "2.Registration" << endl;
	cout << "Choose: ";
	cin >> option;
	return option;
}
bool CheckFileExisting(string path)
{
	bool is_exist = true;
	fstream data_file;
	data_file.open(path, ios::in);
	bool ret = data_file.fail();
	if (ret == true)
	{
		is_exist = false;
	}
	data_file.close();

	return is_exist;
}
int ReadData(string path, User userList[])
{
	if (CheckFileExisting(path))
	{

		int i = 0;
		fstream fsFile;
		char input[100];
		fsFile.open(path, ios::in);
		if (!fsFile.is_open())    //VS2015 co thể bị lỗi đoạn này, thay thế bằng if (!fsFile.is_open())
		{
			cout << "Cannot read file!";
		}
		else
		{
			while (!fsFile.eof())
			{

				fsFile.getline(input, 100);
				User _user;
				string line = string(input);
				_user.userName = line.substr(0, line.rfind(':'));
				_user.passWord = line.substr(line.rfind(':') + 1);
				userList[i++] = _user;
			}
		}
		fsFile.close();
	}
	return 0;
}
void WriteData(ofstream& userList)
{
	/*int dem = 0;
	userList << "Day so chan tu 1 -> 100 \n";
	for (int a = 1; a <= 100; a++)
	{
	if (a % 2 == 0)
	{
	dem++;
	userList << a;
	if (dem % 5 == 0)
	{
	userList << "\n";
	}
	if (dem % 5 != 0)
	{
	userList << "\t";
	}
	}
	}
	cout << "\n So Chan: " << dem;*/

}

void main()
{
	//Khai báo biến đọc và ghi file
	string path = "Database\\UserList.txt";

	//Khai báo biến toàn cụ cho chương trình.
	int option;
	User arrayUser[Max];
	//Đọc danh sách từ file
	ReadData(path, arrayUser);
	//Chọn chức năng của chương trình.
	//Gọi phương thưc menu
	option = DisplayMenu();
	switch (option)
	{
	case 1:
		cout << arrayUser[0].userName << arrayUser[0].passWord;
		break;
	case 2:
		break;
	default:
		break;
	}
	system("pause");
}