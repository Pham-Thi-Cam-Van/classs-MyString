#include"MyString.h"

void main()
{
	MyString str1;
	cout << "VI DU HAM NHAP VA TAO CHUOI" << endl;
	cout << "Nhap chuoi bang getLine: ";
	getLine(cin, str1);
	MyString str2 = "lap trinh huong doi tuong.";
	MyString str3("Ky thuat lap trinh.");
	cout << "str1: " << str1 << endl << "str2: " << str2 << endl << "str3: " << str3 << endl;
}