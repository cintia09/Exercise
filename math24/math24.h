/*************************************************************************
    > File Name: math24.h
    > Author: WangMing
    > Mail: wangming_ch@126.com
    > Created Time: Sat 22 Apr 2017 03:26:20 PM CST
 ************************************************************************/

#ifndef __MATH24__
#define __MATH24__

#include<iostream>
#include<memory>
#include<vector>
#include<string>
using namespace std;


class mathbase
{
	friend class math;
	public:
		mathbase() {}
		mathbase(const int v, const string &s, int lv = 0, int rv = 0): value(v), str(s), l(lv), r(rv) {}
		virtual int evalue(const int) const {return value;}
		int value;
		string str;
		int l, r;
};

class math
{
	public:
		math(shared_ptr<mathbase> m):mathp(m) {};
		int evalue(const int value = 0) const {return mathp->evalue(value);}
		shared_ptr<mathbase> mathp;
};

class mathdouble: public mathbase
{
	public:
		mathdouble() {}
		mathdouble(const int lv, const int rv, const int v, const string &s):mathbase::mathbase(v, s, lv, rv){}
};

class mathadd: public mathbase
{
	public:
		mathadd() {}
		mathadd(const int v, const string &s):mathbase::mathbase(v, s) {}
		int evalue(const int v) const {return v + value;}
};

class mathdec: public mathbase
{
	public:
		mathdec() {}
		mathdec(const int v, const string &s): mathbase::mathbase(v, s) {}
		int evalue(const int v) const {return v - mathbase::value;}
};

class mathpuls: public mathbase
{
	public:
		mathpuls() {}
		mathpuls(const int v, const string &s): mathbase::mathbase(v, s) {}
		int evalue(const int v) const {return v * mathbase::value;}
};

class mathdev: public mathbase
{
	public:
		mathdev() {}
		mathdev(const int v, const string &s): mathbase::mathbase(v, s) {}
		int evalue(const int v) const {return v / mathbase::value;}
};

class maxtren
{
	public:
		maxtren(const int []);
		vector<vector<math>> vec;                                                                              
};



#endif
