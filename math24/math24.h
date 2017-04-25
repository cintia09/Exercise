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
#include"stackM.h"

using namespace std;

class mathbase
{
	friend class math;
	public:
		mathbase() {}
		mathbase(const int v, const string &s): value(v), str(s) {}
		virtual int evalue(const int) const {return value;}
		//void setstr(string &s) {str = s + str;}

		int value;
		string str;
};

class math
{
	public:
		math():mathp(nullptr) {}
		math(shared_ptr<mathbase> m, string s = "", int n = 1, int in1 = -1, int in2 = -1, int in3 = -1): mathp(m), next(nullptr), number(n), str(s) {index[0] = in1; index[1]=in2; index[2]=in3;}
		int evalue(const int value = 0) const {return mathp->evalue(value);}
		shared_ptr<mathbase> mathp;
		shared_ptr<math> next;
		int index[3];
		int number;
		string str;
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
		int evalue(const int v) const {return (v - value) < 0 ? -1 : (v - value);}
};

class mathpuls: public mathbase
{
	public:
		mathpuls() {}
		mathpuls(const int v, const string &s): mathbase::mathbase(v, s) {}
		int evalue(const int v) const {return v * value;}
};

class mathdev: public mathbase
{
	public:
		mathdev() {}
		mathdev(const int v, const string &s): mathbase::mathbase(v, s) {}
		int evalue(const int v) const {return (v % value) == 0 ? (v / value) : -1;}
};

class mathdoublebase
{
	public:
		mathdoublebase() {}
		mathdoublebase(const string &s, const int n, const int va, const int vb, const int vc): number(n) {index[0] = va; index[1] = vb; index[2] = vc;}
		int search();
		stackM<shared_ptr<math>> mstack;
		int index[3];
		int number;
};

class mathdoubleadd: public mathbase, public mathdoublebase
{
	public:
		mathdoubleadd(const string &s, const int n = 1, const int va = -1, const int vb = -1, const int vc = -1): mathbase::mathbase(-1, s), mathdoublebase::mathdoublebase(s, n, va, vb, vc) {}
		//int search();
		int evalue(const int v) const {int ret; if((ret = search()) != -1) return v + ret; else return ret;}

		//stackM<math> mstack;
		//int index[3];
		//int number;
};

class mathdoubledec: public mathbase, public mathdoublebase
{
	public:
		mathdoubledec(const string &s, const int n = 1, const int va = -1, const int vb = -1, const int vc = -1): mathbase::mathbase(-1, s), mathdoublebase::mathdoublebase(s, n, va, vb, vc) {}
		//int search();
		int evalue(const int v) const {int ret; while (((ret = search()) != -1) && (ret > v)) ; return (ret == -1 ? ret : (v - ret);)}
		
		//stackM<math> mstack;
		//int index[3];
		//int number;
};

class mathdoublepuls: public mathbase, public mathdoublebase
{
	public:
		mathdoublepuls(const string &s, const int n = 1, const int va = -1, const int vb = -1, const int vc = -1): mathbase::mathbase(-1, s), mathdoublebase::mathdoublebase(s, n, va, vb, vc) {}
		//int search();
		int evalue(const int v) const {return search() * v;}
	
		//stackM<math> mstack;
		//int index[3];
		//int number;
};

class mathdoubledev: public mathbase, public mathdoublebase
{
	public:
		mathdoubledev(const string &s, const int n = 1, const int va = -1, const int vb = -1, const int vc = -1): mathbase::mathbase(-1, s), mathdoublebase::mathdoublebase(s, n, va, vb, vc) {}
		//int search();
		int evalue(const int v) const {int ret; while (((ret = search()) != -1) && (v % ret != 0)) ; return (ret == -1 ? ret : (v % ret);)}

		//stackM<math> mstack;
		//int index[3];
		//int number;
};

class maxtren
{
	public:
		maxtren(const int []);
		//vector<vector<math>> vec;     
		math mathp[100];
};



#endif
