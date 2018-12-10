#ifndef __MYSTRING_H__
#define __MYSTRING_H__
#include<stdio.h>
#include<iostream>
using namespace std;
#define max 123165024

class MyString
{
private:
	char* str;
	int size;
	int strLen(const char *s); //lấy độ dài chuỗi
public:
	int minLen(const MyString&) const;
	size_t Length() const;
	size_t Size() const;
	size_t Max_size() const;
	char* sCopy(char*, const char*);
	char* sCat(char*, const char*);
	MyString();
	MyString(int);
	MyString(const char*);
	MyString(const MyString&);
	~MyString();
	friend istream& operator>>(istream&, MyString&); //CHUOI KHONG CHUA KI TU KHOANG TRANG
	friend ostream& operator<<(ostream&, MyString&); //xuất chuỗi
	friend istream& getLine(istream& inDev, MyString& s);
	friend istream& getLine(istream& inDev, MyString& s, char delim);
	char& operator[](size_t); //truy xuất tới phần tử thứ i
	typedef char* iterator;
	iterator Begin();
	const iterator Begin() const;
	iterator End();
	const iterator End() const;
	const iterator Cbegin() const;
	const iterator Cend() const;
	iterator Rbegin();
	iterator Rend();
	const char& operator[] (size_t) const;
	char& Front(); //truy xuất đến phần tử đầu chuỗi
	const char& Front() const;
	char& Back(); // truy xuất đến phần tử cuối chuỗi
	const char& Back() const;
	char& At(size_t); //hàm truy xuất tới phần tử thứ i, tương tự []
	const char& At(size_t) const;
	void push_Back(char); // nối 1 ký tự vào cuối chuỗi
	void pop_Back(); //xóa 1 ký tự cuối chuỗi
	MyString& Append(const MyString&); //thêm một chuỗi kí tự vào sau chuỗi kí tự
	MyString& Append(const MyString&, size_t subpos, size_t sublen);
	MyString& Append(const char*);
	MyString& Append(const char*, size_t);
	MyString& Append(size_t, char);
	MyString& Append(iterator first, iterator last);
	MyString& Assign(const MyString&); //gán nội dung cho chuỗi
	MyString& Assign(const MyString&, size_t subpos, size_t sublen);
	MyString& Assign(const char*);
	MyString& Assign(const char*, size_t);
	MyString& Assign(size_t, char);
	MyString& Assign(iterator first, iterator last);
	void Clear();
	int Compare(const MyString&) const;
	int Compare(size_t pos, size_t len, const MyString& s) const;
	int Compare(size_t pos, size_t len, const MyString& s, size_t subpos, size_t sublen) const;
	int Compare(const char*) const;
	int Compare(size_t pos, size_t len, const char*) const;
	int Compare(size_t pos, size_t len, const char* s, size_t n) const;
	size_t Copy(char* &s, size_t len, size_t pos) const;
	const char* Data() const;
	const char* C_str() const;
	MyString& operator=(const MyString&);
	MyString& operator=(const char*); //gán chuỗi cho char*
	MyString& operator=(char);
	MyString operator+(const MyString&); 
	MyString operator+(const char*);
	MyString operator+(char);
	MyString& operator+=(const MyString&); 
	MyString& operator+=(const char*);
	MyString& operator+=(char);
	bool operator==(const MyString&) const;
	bool operator!=(MyString&);
	bool operator<(const MyString&) const;
	bool operator>(const MyString&) const;
	bool operator<=(MyString&);
	bool operator>=(MyString&);
	bool Empty() const;
	MyString Erase(size_t); // cắt lấy n kí tự đầu
	MyString Erase(size_t pos, size_t n); // xóa đi n ký tự bắt đầu tại vị trí pos.
	iterator Erase(iterator p);
	iterator Erase(iterator first, iterator last);
	MyString strCutPos(MyString, int n, int pos); //cắt lấy n kí tự từ vị trí pos
	MyString cutInPos(MyString, int, int); //cắt lấy chuỗi từ vị trí pos1 đến vị trí pos2
	MyString cutBegin(MyString, int); //cắt lấy n kí tự đầu
	MyString strTrans(char); //chuyển kí tự trong chuỗi thành kí tự char c
	MyString strTransASCII(int);  //chuyển kí tự trong chuỗi thành mã ASCII
	MyString& Insert(size_t, const MyString&); //chèn chuỗi vào vị trí pos
	MyString& Insert(size_t pos, const MyString& s, size_t subpos, size_t sublen);
	MyString& Insert(size_t pos, const char* s);
	MyString& Insert(size_t pos, const char* s, size_t n);
	MyString& Insert(size_t pos, size_t n, char c);
	iterator Insert(iterator p, size_t n, char c);
	iterator Insert(iterator p, char c);
	iterator Insert(iterator p, iterator first, iterator last);
	MyString strCpy(MyString); //hàm sao chép chuỗi
	MyString strCat(MyString); //hàm ghép vào cuối chuỗi
	int strCmp(MyString, MyString); //so sánh 2 chuỗi theo thứ tự alphabet
	MyString strUpr(); //đổi ký tự trong chuỗi thành kí tự hoa
	MyString strLwr(); //đổi ký tự trong chuỗi thành kí tự thường
	void Resize(size_t);
	void Resize(size_t, char);
	size_t Capacity() const;
	void swap(MyString&);
	bool check(char c);
	size_t Find(const MyString&) const;
	size_t Find(const MyString&, size_t) const;
	size_t Find(const char*) const;
	size_t Find(const char*, size_t) const;
	size_t Find(const char*, size_t pos, size_t n) const;
	size_t Find(char) const;
	size_t Find(char, size_t) const;
	size_t Rfind(const MyString&) const;
	MyString& Replace(size_t pos, size_t len, const MyString& s);
	MyString& Replace(iterator i1, iterator i2, const MyString& s);
	size_t Find_first_not_of(const MyString& s) const;
	size_t Find_first_not_of(const MyString& s, size_t pos) const;
	size_t Find_first_not_of(const char* s) const;
	size_t Find_first_not_of(const char* s, size_t pos) const;
	size_t Find_first_of(const MyString& s) const;
	size_t Find_first_of(const MyString& s, size_t pos) const;
	size_t Find_first_of(const char* s) const;
	size_t Find_first_of(const char* s, size_t pos) const;
	size_t Find_last_not_of(const MyString& s) const;
	size_t Find_last_not_of(const MyString& s, size_t pos) const;
	size_t Find_last_not_of(const char* s) const;
	size_t Find_last_not_of(const char* s, size_t pos) const;
	size_t Find_last_of(const MyString& s) const;
	size_t Find_last_of(const MyString& s, size_t pos) const;
	size_t Find_last_of(const char* s) const;
	size_t Find_last_of(const char* s, size_t pos) const;
	MyString Substr(size_t) const;
	MyString Substr(size_t pos, size_t len) const;
	MyString Inver();
	char* Inver(char*);
};

bool operator==(const char*, const MyString&);
bool operator!=(const char*, const MyString&);
bool operator!=(const MyString&, const char*);
bool operator<(const char*, const MyString&);
bool operator>(const char*, const MyString&);
bool operator<=(const char*, const MyString&);
bool operator<=(const MyString&, const char*);
bool operator>=(const char*, const MyString&);
bool operator>=(const MyString&, const char*);
MyString operator+(const MyString& lhs, const MyString& rhs);
MyString operator+(const MyString& lhs, const char* rhs);
MyString operator+(const char* lhs, const MyString& rhs);
MyString operator+(const MyString& lhs, char rhs);
MyString operator+(char lhs, const MyString& rhs);
#endif