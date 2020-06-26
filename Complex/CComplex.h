#pragma once

#include <iostream>

class CComplex
{
private:
	double m_re;
	double m_im;

public:
	CComplex();
	CComplex(double re, double im);
	CComplex(const CComplex &src);

	double GetRe();
	double GetIm();
	void SetRe(double re);
	void SetIm(double im);
	
	void SetBoth(double re, double im);


	CComplex& operator+=(CComplex& p);
	CComplex& operator-=(CComplex& p);
	CComplex& operator*=(CComplex& p);
	CComplex& operator/=(CComplex& p);

	double CComplex::Module();
	void CComplex::Coupled();

	friend CComplex operator+(CComplex& s, CComplex& p);
	friend CComplex operator-(CComplex& s, CComplex& p);
	friend CComplex operator*(CComplex& s, CComplex& p);
	friend CComplex operator/(CComplex& s, CComplex& p);

	friend BOOL operator==(CComplex& s, CComplex& p);
	friend BOOL operator!=(CComplex& s, CComplex& p);

	friend std::istream& operator>> (std::istream& s, CComplex& p);
	friend std::ostream& operator << (std::ostream& s, CComplex& p);

};

class CCanonComplex : public CComplex {
public:
	CCanonComplex(CComplex& comp);
	CString wypisanie();
};
