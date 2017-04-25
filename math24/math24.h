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

class mathdoubleadd: public mathbase
{
	public:
		mathdoubleadd(const string &s, const int n = 1, const int va = -1, const int vb = -1, const int vc = -1): mathbase::mathbase(-1, s), number(n) {index[0]=va; index[1]=vb;index[2]=vc;}
		int search();
		int evalue(const int v) const {return v + value;}

		stackM<math> mstack;
		int index[3];
		int number;
};

class mathdoubledec: public mathbase
{
	public:
		mathdoubledec(const string &s, const int n = 1, const int va = -1, const int vb = -1, const int vc = -1): mathbase::mathbase(-1, s), number(n) {index[0]=va;index[1]=vb;index[2]=vc;}
		int search();
		int evalue(const int v) const {return (v - value) < 0 ? -1 : (v - value);}
		
		stackM<math> mstack;
		int index[3];
		int number;
};

class mathdoublepuls: public mathbase
{
	public:
		mathdoublepuls(const string &s, const int n = 1, const int va = -1, const int vb = -1, const int vc = -1): mathbase::mathbase(-1, s), number(n) {index[0]=va;index[1]=vb;index[2]=vc;}
		int search();
		int evalue(const int v) const {return v * value;}
	
		stackM<math> mstack;
		int index[3];
		int number;
};

class mathdoubledev: public mathbase
{
	public:
		mathdoubledev(const string &s, const int n = 1, const int va = -1, const int vb = -1, const int vc = -1): mathbase::mathbase(-1, s), number(n) {index[0]=va;index[1]=vb;index[2]=vc;}
		int search();
		int evalue(const int v) const {return (v % value) == 0 ? (v / value) : -1;}

		stackM<math> mstack;
		int index[3];
		int number;
};

class maxtren
{
	public:
		maxtren(const int []);
		//vector<vector<math>> vec;     
		math mathp[100];
};



#endif
