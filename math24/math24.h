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

class maxtren;

class mathbase
{
	friend class math;
	public:
		mathbase() {}
		mathbase(const int v, const string &s): value(v), str(s) {}
		virtual int evalue(const int) {return value;}
		//void setstr(string &s) {str = s + str;}

		int value;
		string str;
		maxtren *max;
};

class math
{
	public:
		math():mathp(nullptr) {}
		math(shared_ptr<mathbase> m, string s = "", int n = 1, int in1 = -1, int in2 = -1, int in3 = -1): mathp(m), next(nullptr), number(n), str(s) {index[0] = in1; index[1]=in2; index[2]=in3;}
		int evalue(const int value = 0) {int get = mathp->evalue(value); /*cout << "math get: " << get << ", number: " << number << ", index: " << index[0] << " " << index[1] << " " << index[2] << endl;*/ return get; }
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
		int evalue(const int v) {int get = v + value; cout << v << " + " << value << " = " << get << endl; return get;}
};

class mathdec: public mathbase
{
	public:
		mathdec() {}
		mathdec(const int v, const string &s): mathbase::mathbase(v, s) {}
		int evalue(const int v) {int get = ((v - value) < 0 ? -1 : (v - value)); cout << v << " - " << value << " = " << get << endl; return get;}
};

class mathpuls: public mathbase
{
	public:
		mathpuls() {}
		mathpuls(const int v, const string &s): mathbase::mathbase(v, s) {}
		int evalue(const int v) {int get = v * value; cout << v << " x " << value << " = " << get << endl; return get;}
};

class mathdev: public mathbase
{
	public:
		mathdev() {}
		mathdev(const int v, const string &s): mathbase::mathbase(v, s) {}
		int evalue(const int v) {int get = ((v % value) == 0 ? (v / value) : -1); cout << v << " / " << value << " = " << get << endl; return get;}
};

class mathdoublebase: public mathbase
{
	public:
		mathdoublebase() {}
		mathdoublebase(const string &s, const int n, const int va, const int vb, const int vc): number(n), mathbase::mathbase(-1, s) {index[0] = va; index[1] = vb; index[2] = vc;}
		int search();
		stackM<pair<shared_ptr<math>, int>> mstack;
		stackM<string> sstack;
		int index[3];
		int number;
		//maxtren *max;
		int node[100];
};

class mathdoubleadd: public mathdoublebase
{
	public:
		mathdoubleadd(const string &s, const int n = 1, const int va = -1, const int vb = -1, const int vc = -1): mathdoublebase::mathdoublebase(s, n, va, vb, vc) {}
		//int search();
		int evalue(const int v) {int ret, get; if((ret = search()) != -1) get = v + ret; else get = ret; cout << str << " search is: " << v << " + " << ret << " = " << get << endl; return get;}

		//stackM<math> mstack;
		//int index[3];
		//int number;
};

class mathdoubledec: public mathdoublebase
{
	public:
		mathdoubledec(const string &s, const int n = 1, const int va = -1, const int vb = -1, const int vc = -1): mathdoublebase::mathdoublebase(s, n, va, vb, vc) {}
		//int search();
		int evalue(const int v) {int ret, get; while (((ret = search()) != -1) && (ret > v)); get = (ret == -1 ? ret : (v - ret)); cout << str << " search is: " << v << " x " << ret << " = " << get << endl; return get;}
		
		//stackM<math> mstack;
		//int index[3];
		//int number;
};

class mathdoublepuls: public mathdoublebase
{
	public:
		mathdoublepuls(const string &s, const int n = 1, const int va = -1, const int vb = -1, const int vc = -1): mathdoublebase::mathdoublebase(s, n, va, vb, vc) {}
		//int search();
		int evalue(const int v) {int ret, get; if((ret = search()) != -1) get = v * ret; else get = ret; cout << str << " search is: " << v << " x " << ret << " = " << get << endl; return get;}
	
		//stackM<math> mstack;
		//int index[3];
		//int number;
};

class mathdoubledev: public mathdoublebase
{
	public:
		mathdoubledev(const string &s, const int n = 1, const int va = -1, const int vb = -1, const int vc = -1): mathdoublebase::mathdoublebase(s, n, va, vb, vc) {}
		//int search();
		int evalue(const int v) {int ret, get; while (((ret = search()) != -1) && (v % ret != 0)) ; get = (ret == -1 ? ret : (v % ret)); cout << str << " search is: " << v << " / " << ret << " = " << get << endl; return get;}

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
