#include"MyString.h"

int MyString::minLen(const MyString& s) const
{
	if (size < s.size) return size;
	return s.size;
}
int MyString::strLen(const char *s)
{
	int i = 0;
	while (s[i] != '\0')
		i++;
	return i;
}
size_t MyString::Length() const
{
	return size;
}
size_t MyString::Size() const
{
	return size;
}
size_t MyString::Capacity() const
{
	return size + 2;
}
size_t MyString::Max_size() const
{
	return max;
}
char* MyString::sCopy(char *dest, const char *src)
{
	int len = strLen(src);
	dest = new char[len + 2];
	for (int i = 0; i < len; i++)
		dest[i] = src[i];
	dest[len] = '\0';
	return dest;
}
MyString::MyString()
{
	size = 0;
	str = sCopy(str, "");
}
MyString::MyString(int sz)
{
	size = sz;
	str = new char[sz + 2];
	for (int i = 0; i < sz; i++)
		str[i] = '\0';
	str[sz] = '\0';
}
MyString::MyString(const char *s)
{
	int len = strLen(s);
	size = len;
	str = new char[len + 2];
	str = sCopy(str, s);
}
MyString::MyString(const MyString &s)
{
	size = s.size;
	str = new char[size + 2];
	str = sCopy(str, s.str);
}
MyString::~MyString()
{
	size = 0;
	delete[]str;
	str = NULL;
}
bool MyString::check(char c)
{
	for (int i = 0; i < size; i++)
	if (str[i] == c)
		return true;
	return false;
}
istream& operator>>(istream& inDev, MyString &s)
{
	s.size = max;
	int n = 0, i = 0;
	s.str = new char[s.size + 2];
	inDev.getline(s.str, s.size + 2);
	for (int j = 0; j < s.size;j++)
	if (s.str[j] == ' ') i++;
	if (i != 0){
		while (s.str[n]!=' '){
			n++;
		}
		s.size = n;
		s.str[n] = '\0';
	}
	cout << "Chuoi khong chua ki tu khoang trang.\n";
	return inDev;

}
istream& getLine(istream& inDev, MyString& s)
{
	s.size = max;
	int n = 0;
	s.str = new char[s.size + 2];
	inDev.getline(s.str, s.size + 2);
	while (s.str[n] != '\0'){
		n++;
	}
	s.str[n] = '\0';
	s.size = n;
	return inDev;
}
istream& getLine(istream& inDev, MyString& s, char delim)
{
	getLine(cin, s);
	if (s.check(delim) == 1){
		int i = 0;
		while (s[i] != delim)
			i++;
		s[i] = '\0';
	}
	else{
		char c;
		while (1){
			cin >> c;
			if (c == delim)break;
			s.push_Back('\n');
			s.push_Back(c);
		}
	}
	return inDev;
}
ostream& operator<<(ostream& outDev, MyString &s)
{
	outDev << s.str;
	return outDev;
}
char& MyString::operator[](size_t pos)
{
	return str[pos];
}
const char& MyString::operator[](size_t pos)const
{
	return str[pos];
}
char& MyString::At(size_t pos)
{
	return str[pos];
}
const char& MyString::At(size_t pos) const
{
	return str[pos];
}
MyString& MyString::Append(const MyString& s)
{
	*this += s;
	return *this;
}
MyString& MyString::Append(const MyString& s, size_t subpos, size_t sublen)
{
	MyString src = *this;
	*this += src.strCutPos(s, sublen, subpos);
	return *this;
}
MyString& MyString::Append(const char* s)
{
	*this += s;
	return *this;
}
MyString& MyString::Append(const char* s, size_t n)
{
	MyString src = s;
	*this += src.cutBegin(src, n);
	return *this;
}
MyString& MyString::Append(size_t n, char c)
{
	for (int i = 0; i < n; i++)
		push_Back(c);
	return *this;
}
MyString& MyString::Append(iterator first, iterator last)
{
	for (MyString::iterator it = first; it < last; it++)
		*this = *this + (*it);
	return *this;
}
MyString& MyString::Assign(const MyString& s)
{
	*this = s;
	return *this;
}
MyString& MyString::Assign(const MyString& s, size_t subpos, size_t sublen)
{
	*this = strCutPos(s, sublen, subpos);
	return *this;
}
MyString& MyString::Assign(const char* s)
{
	*this = s;
	return *this;
}
MyString& MyString::Assign(const char* s, size_t n)
{
	MyString src = s;
	*this = src.cutBegin(src, n);
	return *this;
}
MyString& MyString::Assign(size_t n, char c)
{
	for (int i = 0; i < n; i++)
		push_Back(c);
	return *this;
}
MyString& MyString::Assign(iterator first, iterator last)
{
	Clear();
	for (MyString::iterator it = first; it < last; it++)
		*this = *this + (*it);
	return *this;
}
char& MyString::Back()
{
	return str[size - 1];
}
const char& MyString::Back() const
{
	return str[size - 1];
}
void MyString::push_Back(char c)
{
	MyString s = *this;
	size = size + 1;
	str = new char[size + 2];
	for (int i = 0; i < s.size; i++)
		str[i] = s[i];
	str[size - 1] = c;
	str[size] = '\0';
}
void MyString::pop_Back()
{
	str[size - 1] = '\0';
	size = size - 1;
}
int MyString::Compare(const MyString& s) const
{
	if (*this > s) return 1;
	if (*this < s)return -1;
	return 0;
}
int MyString::Compare(size_t pos, size_t len, const MyString& s) const
{
	MyString src = *this;
	src = src.strCutPos(src, len, pos);
	if (src == s) return 0;
	if (src < s) return -1;
	return 1;
}
int MyString::Compare(size_t pos, size_t len, const MyString& s, size_t subpos, size_t sublen) const
{
	MyString src1 = *this;
	MyString src2 = s;
	src1 = src1.strCutPos(src1, len, pos);
	src2 = src2.strCutPos(src2, sublen, subpos);
	if (src1 == src2) return 0;
	if (src1 < src2) return -1;
	return 1;
}
int MyString::Compare(const char* s) const
{
	if (*this == s) return 0;
	if (*this>s) return 1;
	return -1;
}
int MyString::Compare(size_t pos, size_t len, const char* s) const
{
	MyString src = *this;
	src = src.strCutPos(src, len, pos);
	if (src == s) return 0;
	if (src < s) return -1;
	return 1;
}
int MyString::Compare(size_t pos, size_t len, const char* s, size_t n) const
{
	MyString src1 = s;
	src1 = src1.strCutPos(src1, n, 0);
	MyString src2 = *this;
	src2 = src2.strCutPos(src2, len, pos);
	if (src1 == src2) return 0;
	if (src2 < src1) return -1;
	return 1;
}
size_t MyString::Copy(char* &s, size_t len, size_t pos) const
{
	MyString src = *this;
	src = src.strCutPos(src, len, pos);
	s = src.sCopy(s, src.str);
	return len;
}
const char* MyString::Data() const
{
	char* s = new char[size + 2];
	s = str;
	return s;
}
const char* MyString::C_str() const
{
	char* s = new char[size + 2];
	s = str;
	return s;
}


MyString& MyString::operator=(const MyString& s)
{
	size = s.size;
	str = sCopy(str, s.str);
	return *this;
}
MyString& MyString::operator=(const char* s)
{
	size = strLen(s);
	str = sCopy(str, s);
	return *this;
}
MyString& MyString::operator=(char c)
{
	size = 1;
	str = new char[size + 1];
	str[0] = c;
	str[size] = '\0';
	return *this;
}
char *MyString::sCat(char *dest, const char *src)
{
	MyString s = dest;
	int n = strLen(dest);
	int len = strLen(dest) + strLen(src);
	dest = new char[len + 2];
	for (int i = 0; i < strLen(s.str); i++)
		dest[i] = s.str[i];
	for (int i = 0; i < strLen(src); i++){
		dest[n] = src[i];
		n++;
	}
	dest[len] = '\0';
	return dest;
}
MyString MyString::operator+(const MyString& s)
{
	MyString src;
	src.size = size + s.size;
	src.str = sCat(str, s.str);
	return src;
}
MyString MyString::operator+(const char* s)
{
	MyString src;
	src = s;
	src = *this + src;
	return src;
}
MyString MyString::operator+(char c)
{
	MyString src = *this;
	src += c;
	return src;
}
MyString& MyString::operator+=(const MyString& s)
{
	*this = *this + s;
	return *this;
}
MyString& MyString::operator+=(const char* s)
{
	MyString src;
	src = s;
	*this += src;
	return *this;
}
MyString& MyString::operator+=(char c)
{
	push_Back(c);
	return *this;
}
bool MyString::Empty() const
{
	if (Length() == 0) return true;
	return false;
}
char& MyString::Front()
{
	return str[0];
}
const char& MyString::Front() const
{
	return str[0];
}
void MyString::Clear()
{
	*this = "";
}
void MyString::swap(MyString& s)
{
	MyString src = *this;
	*this = s;
	s = src;
}
MyString MyString::strCutPos(MyString s, int n, int pos)
{
	if (n + pos > s.size){
		size = s.Length() - pos;
		str = new char[size + 2];
		for (int i = 0; i < size; i++){
			str[i] = s.str[pos];
			pos++;
		}
		str[size] = '\0';
	}
	else{
		size = n;
		str = new char[n + 2];
		for (int i = 0; i < n; i++){
			str[i] = s.str[pos];
			pos++;
		}
		str[n] = '\0';
	}
	return *this;
}
MyString MyString::Erase(size_t n)
{
	cutBegin(*this, n);
	return *this;
}
MyString MyString::Erase(size_t pos, size_t n)
{
	MyString s = *this;
	Clear();
	cutBegin(s, pos);
	*this += s.cutInPos(s, pos + n, s.size);
	return *this;
}
MyString::iterator MyString::Erase(iterator p)
{
	int i = 0;
	for (MyString::iterator it = Begin(); it != p; it++)
		i++;
	*this = Erase(i, 1);
	p++;
	return p;
}
MyString::iterator MyString::Erase(iterator first, iterator last)
{
	int i = 0, j = 0;
	MyString::iterator it;
	for (it = Begin(); it != first; it++)
		i++;
	for (it = first; it != last; it++)
		j++;
	*this = Erase(i, j);
	return last;
}
bool MyString::operator==(const MyString& s) const
{
	if (size != s.size) return false;
	for (int i = 0; i < size; i++)
	if (str[i] != s.str[i])
		return false;
	return true;
}
bool operator==(const char* s, const MyString& src)
{
	if (src == s) return 1;
	return 0;
}

bool operator!=(const char* s, const MyString& src)
{
	if (src == s) return 0;
	return 1;
}
bool operator!=(const MyString& src, const char* s)
{
	if (src == s) return 0;
	return 1;
}
bool MyString::operator!=(MyString& s)
{
	if (s == *this) return false;
	return true;
}
bool MyString::operator<(const MyString& s) const
{
	if (*this == s) return false;
	for (int i = 0; i < minLen(s); i++){
		if (str[i] > s.str[i]) return false;
		if (str[i] < s.str[i]) return true;
	}
	if (size>s.size) return false;
	return true;
}
bool operator<(const char* s, const MyString& src)
{
	if (src > s) return true;
	return false;
}
bool operator>(const char* s, const MyString& src)
{
	if (src<s) return true;
	return false;
}
bool operator<=(const char* s, const MyString& src)
{
	if (s>src) return false;
	return true;
}
bool operator<=(const MyString& src, const char* s)
{
	if (src > s) return false;
	return true;
}
bool operator>=(const char* s, const MyString& src)
{
	if (s<src) return false;
	return true;
}
bool operator>=(const MyString& src, const char* s)
{
	if (src<s) return false;
	return true;
}
bool MyString::operator>(const MyString& s) const
{
	if ((*this == s) || (*this < s)) return false;
	return true;
}
bool MyString::operator<=(MyString& s)
{
	if (*this>s) return false;
	return true;
}
bool MyString::operator>=(MyString& s)
{
	if (*this < s) return false;
	return true;
}
MyString MyString::strCpy(MyString s)
{
	size = s.Length();
	str = sCopy(str, s.str);
	return *this;
}
MyString MyString::strCat(MyString s)
{
	MyString src = *this;
	size = Length() + s.Length();
	str = new char[size + 2];
	*this = src;
	str = sCat(str, s.str);
	return *this;
}
MyString MyString::cutInPos(MyString s, int pos1, int pos2)
{
	size = pos2 - pos1;
	str = new char[size + 2];
	int k = 0;
	for (int i = pos1; i < pos2; i++){
		str[k] = s.str[i];
		k++;
	}
	str[k] = '\0';
	return *this;
}
MyString MyString::cutBegin(MyString s, int n)
{
	if (n>s.size) n = s.size;
	size = n;
	str = new char[n + 2];
	for (int i = 0; i < n; i++)
		str[i] = s.str[i];
	str[n] = '\0';
	return *this;
}
MyString MyString::strTrans(char c)
{
	for (int i = 0; i < size; i++)
		str[i] = c;
	return *this;
}
MyString MyString::strTransASCII(int c)
{
	for (int i = 0; i < size; i++)
		str[i] = (char)c;
	return *this;
}

MyString& MyString::Insert(size_t pos, const MyString& s)
{
	MyString src = *this;
	cutBegin(src, pos);
	*this += s;
	*this += src.cutInPos(src, pos, src.Length());
	return *this;
}
MyString& MyString::Insert(size_t pos, const MyString& s, size_t subpos, size_t sublen)
{
	MyString src = s;
	src = src.strCutPos(src, sublen, subpos);
	Insert(pos, src);
	return *this;
}
MyString& MyString::Insert(size_t pos, const char* s)
{
	MyString src = s;
	Insert(pos, src);
	return *this;
}
MyString& MyString::Insert(size_t pos, const char* s, size_t n)
{
	MyString src = s;
	src = src.Erase(n);
	Insert(pos, src);
	return *this;
}
MyString& MyString::Insert(size_t pos, size_t n, char c)
{
	MyString src = *this;
	src = c;
	for (int i = 0; i < n; i++)
		*this = Insert(pos, src);
	return *this;
}
MyString::iterator MyString::Insert(iterator p, size_t n, char c)
{
	size_t len = 0;
	for (iterator it = Begin(); it != p; it++)
		len++;
	Insert(len, n, c);
	return p;
}
MyString::iterator MyString::Insert(iterator p, char c)
{
	Insert(p, 1, c);
	return p;
}
MyString::iterator MyString::Insert(iterator p, iterator first, iterator last)
{
	MyString src = *this;
	src.Clear();
	for (MyString::iterator it = first; it < last; it++)
		src += (*it);
	size_t len = 0;
	for (iterator it = Begin(); it != p; it++)
		len++;
	Insert(len, src);
	return first;
}
int MyString::strCmp(MyString s1, MyString s2)
{
	if (s1 < s2) return -1;
	if (s1 == s2)return 0;
	return 1;
}
MyString MyString::strUpr()
{
	for (int i = 0; i < size; i++)
	if (str[i] >= 'a'&&str[i] <= 'z')
		str[i] = str[i] - ('a' - 'A');
	return *this;
}
MyString MyString::strLwr()
{
	for (int i = 0; i < size; i++)
	if (str[i] >= 'A'&&str[i] <= 'Z')
		str[i] = str[i] + ('a' - 'A');
	return *this;
}
void MyString::Resize(size_t n)
{
	size = n;
	str[size] = '\0';
}
void MyString::Resize(size_t n, char c)
{
	MyString s = *this;
	str = new char[n + 2];
	*this = s;
	for (int i = 0; i < n - s.size; i++)
		push_Back(c);
}
MyString operator+(const MyString& lhs, const MyString& rhs)
{
	MyString src;
	src = lhs + rhs;
	return src;
}
MyString operator+(const MyString& lhs, const char* rhs)
{
	MyString src;
	src = rhs + lhs;
	return src;
}
MyString operator+(const char* lhs, const MyString& rhs)
{
	MyString src = lhs;
	src = src + rhs;
	return src;
}
MyString operator+(const MyString& lhs, const char rhs)
{
	MyString src;
	src = lhs;
	src.push_Back(rhs);
	return src;
}
MyString operator+(char lhs, const MyString& rhs)
{
	MyString src;
	src = rhs + lhs;
	for (int i = src.Length() - 1; i > 0; i--){
		src[i] = src[i - 1];
	}
	src[0] = lhs;
	return src;
}
MyString::iterator MyString::Begin()
{
	return str;
}
MyString::iterator const MyString::Begin() const
{
	return str;
}
MyString::iterator MyString::End()
{
	return str + size;
}
MyString::iterator const MyString::End() const
{
	return str + size;
}
MyString::iterator const MyString::Cbegin() const
{
	return str;
}
MyString::iterator const  MyString::Cend() const
{
	return str + size;
}
MyString::iterator MyString::Rbegin()
{
	return str - size * 2;
}
MyString::iterator MyString::Rend()
{
	return str - size;
}
size_t MyString::Find(const MyString& s) const
{
	MyString src = *this;
	for (size_t i = 0; i < Length() - s.Length(); i++){
		if (str[i] == s.str[0]){
			src = src.strCutPos(src, s.Length(), i);
			if (src == s) return i;
			src = *this;
		}
	}
	return max;
}
size_t MyString::Find(const MyString& s, size_t pos) const
{
	if (pos > Length() - s.Length()) return max;
	MyString src = *this;
	src = src.cutInPos(src, pos, Length());
	size_t found = src.Find(s);
	if (found != max) return pos + found;
	return max;
}
size_t MyString::Find(const char* s) const
{
	MyString src = s;
	return Find(src);
}
size_t MyString::Find(const char* s, size_t pos) const
{
	MyString src = s;
	return Find(src, pos);
}
size_t MyString::Find(const char* s, size_t pos, size_t n) const
{
	MyString src = s;
	if (pos > Length() - src.Length()) return max;
	src = src.Erase(n);
	MyString src2 = *this;
	src2 = src2.cutInPos(src2, pos, Length());
	if (src2.Length() < src.Length()) return max;
	if (src2.Find(src) != max) return pos + src2.Find(src);
	return max;
}
size_t MyString::Find(char c) const
{
	for (int i = 0; i < Length(); i++)
	if (str[i] == c) return i;
	return max;
}
size_t MyString::Find(char c, size_t pos)const
{
	if (pos>Length()) return max;
	MyString src = *this;
	src = src.cutInPos(src, pos, Length());
	for (int i = 0; i < src.Length(); i++)
	if (src[i] == c) return i + pos;
	return max;
}
MyString MyString::Substr(size_t len) const
{
	MyString src = *this;
	if (len >= Length()) src.Clear();
	else
		src = src.cutInPos(src, len, Length());
	return src;
}
MyString MyString::Substr(size_t pos, size_t len) const
{
	size_t n = len;
	if (n > Length()) n = Length();
	MyString src = *this;
	if (pos > Length()) src.Clear();
	else
		src = src.cutInPos(src, pos, n);
	return src;
}
MyString MyString::Inver()
{
	MyString src = *this;
	int j = 0;
	for (int i = Length() - 1; i >= 0; i--){
		str[j] = src.str[i];
		j++;
	}
	return *this;
}
char* MyString::Inver(char* s)
{
	MyString src = s;
	src = src.Inver();
	s = new char[src.Length() + 2];
	for (int i = 0; i < src.Length(); i++)
		s[i] = src[i];
	s[src.Length()] = '\0';
	return s;
}
size_t MyString::Rfind(const MyString& s) const
{
	MyString src = *this;
	src = src.Inver();
	MyString src2 = s;
	char* src3 = "hg";
	src3 = src2.sCopy(src3, src2.str);
	src3 = src.Inver(src3);
	size_t pos = src.Find(src3);
	if (pos == max) return max;
	return Length() - pos - strlen(src3);
}
MyString& MyString::Replace(size_t pos, size_t len, const MyString& s)
{
	MyString src = *this;
	*this = cutBegin(src, pos);
	*this += s;
	*this += src.cutInPos(src, pos + len, src.Length());
	return *this;
}
MyString& MyString::Replace(iterator i1, iterator i2, const MyString& s)
{
	int pos1 = 0, pos2 = 0;
	for (MyString::iterator it = Begin(); it != i1; it++)
		pos1++;
	for (MyString::iterator it = Begin(); it != i2; it++)
		pos2++;
	Replace(pos1, pos2 - 1, s);
	return *this;
}
size_t MyString::Find_first_not_of(const MyString& s) const
{
	for (int i = 0; i < Length(); i++){
		if (s.Find(str[i]) == max) return i;
	}
	return max;
}
size_t MyString::Find_first_not_of(const MyString& s, size_t pos) const
{
	MyString src = *this;
	src = src.cutInPos(src, pos, Length());
	for (int i = 0; i < src.Length(); i++){
		if (s.Find(src.str[i]) == max) return i + pos;
	}
	return max;
}
size_t MyString::Find_first_not_of(const char* s) const
{
	MyString src = s;
	return Find_first_not_of(src);
}
size_t MyString::Find_first_not_of(const char* s, size_t pos) const
{
	MyString src = s;
	return Find_first_not_of(src, pos);
}
size_t MyString::Find_first_of(const MyString& s) const
{
	for (int i = 0; i < Length(); i++){
		if (s.Find(str[i]) != max) return i;
	}
	return max;
}
size_t MyString::Find_first_of(const MyString& s, size_t pos) const
{
	MyString src = *this;
	src = src.cutInPos(src, pos, Length());
	for (int i = 0; i < src.Length(); i++){
		if (s.Find(src.str[i]) != max) return i + pos;
	}
	return max;
}
size_t MyString::Find_first_of(const char* s) const
{
	MyString src = s;
	return Find_first_of(src);
}
size_t MyString::Find_first_of(const char* s, size_t pos) const
{
	MyString src = s;
	return Find_first_of(src, pos);
}
size_t MyString::Find_last_not_of(const MyString& s) const
{
	MyString src = *this;
	src = src.Inver();
	cout << src << endl;
	for (int i = 0; i < Length(); i++){
		if (s.Find(src.str[i]) == max) return Length() - i - 1;
	}
	return max;
}
size_t MyString::Find_last_not_of(const MyString& s, size_t pos) const
{
	MyString src = *this;
	src = src.Erase(pos + 1);
	return src.Find_last_not_of(s);
}
size_t MyString::Find_last_not_of(const char* s) const
{
	MyString src = s;
	return Find_last_not_of(src);
}
size_t MyString::Find_last_not_of(const char* s, size_t pos) const
{
	MyString src = s;
	return Find_last_not_of(src, pos);
}
size_t MyString::Find_last_of(const MyString& s) const
{
	MyString src = *this;
	src = src.Inver();
	for (int i = 0; i < Length(); i++){
		if (s.Find(src.str[i]) != max) return Length() - i - 1;
	}
	return max;
}
size_t MyString::Find_last_of(const MyString& s, size_t pos) const
{
	MyString src = *this;
	src = src.Erase(pos + 1);
	return src.Find_last_of(s);
}
size_t MyString::Find_last_of(const char* s) const
{
	MyString src = s;
	return Find_last_of(src);
}
size_t MyString::Find_last_of(const char* s, size_t pos) const
{
	MyString src = s;
	return Find_last_of(src, pos);
}