#include "str_assign.h"
#include <cstring>

str::str() 
{
  _buf = nullptr;
  _n = 0;
}

str::str(char ch)
{
   _n = 1;
  _buf = new char[_n];
  _buf[0] = ch;
}

str::str(const char* c_str)
{
  _n = strlen(c_str);
  _buf = new char[_n];
  for (int i = 0; i < _n; ++i) 
    _buf[i] = c_str[i];
}
str::str(const str &s)
{
  _n = s._n;
  _buf = new char[_n];
  for (int i = 0; i < _n; ++i) 
    _buf[i] = s._buf[i];
}

str::~str()
{
  if (_buf) 
    delete [] _buf;
  _n = 0;
  _buf = nullptr;
}

void str::print()
{
  for (int i = 0; i < _n; ++i) 
    cout << _buf[i];
  cout << endl;
}

void str::clear()
{
  if (_buf) 
    delete [] _buf;

  _buf = nullptr;
  _n = 0;
}

void str::append(const str & s)
{
  char *p = new char[_n + s._n];

  int i;
  
  for (i = 0; i < _n; ++i) 
    p[i] = _buf[i];
  
  for (int j = 0; j < s._n; ++i,++j) 
    p[i] = s._buf[j];

  if (_buf) 
    delete [] _buf;

  _buf = p;  
  _n = _n + s._n;
}

void swap(str& x, str& y)
{
  char *tmp;
  int ntmp;
  
  tmp = x._buf;
  x._buf = y._buf;
  y._buf = tmp;

  ntmp = x._n;
  x._n = y._n;
  y._n = ntmp;
  
}
str &str:: operator=(const str &d){
	_n=d._n;
	delete []_buf;
	for (int i=0;i<_n;i++)
		_buf[i]=d._buf[i];
	return *this;
}

str str:: operator+(str &s2) const{
	str s3;
	int _newN=this->_n+s2._n;
	char *p=new char[_newN];
	int i;
  
	for (i = 0; i < this->_n; ++i) 
		p[i] = this->_buf[i];
  
	for (int j = 0; j < s2._n; ++i,++j) 
		p[i] = s2._buf[j];

  
	s3._buf = p;  
	s3._n = _newN;
	return s3;
}

ostream &operator<<(ostream &out, const str &d){
	for (int i = 0; i < d._n; ++i) 
		out << d._buf[i];
	return out;
}
istream &operator>>(istream &in, str &d){
	string k;
	in>>k;
	d._n=k.length();
	d._buf=new char[d._n];
	
	for (int i=0;i<d._n;i++)
		d._buf[i]=k[i];
	
	return in;
}




