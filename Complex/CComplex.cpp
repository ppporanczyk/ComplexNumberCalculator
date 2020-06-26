#include "pch.h"
#include "CComplex.h"
#include "Complex.h"

CComplex::CComplex() : m_re(0), m_im(0) {}
CComplex::CComplex(double re, double im): m_re(re), m_im(im) {}
CComplex::CComplex(const CComplex& src)  {
	m_re = src.m_re;
	m_im = src.m_im;
}

double CComplex::GetRe() {return m_re;}
double CComplex::GetIm() {return m_im;}
void CComplex::SetRe(double re) {m_re = re;}
void CComplex::SetIm(double im) {m_im = im;}

void CComplex::SetBoth(double re, double im) {
	SetRe(re);
	SetIm(im);
}


CComplex& CComplex::operator+=(CComplex& p) {
	SetRe(GetRe() + p.GetRe());
	SetIm(GetIm() + p.GetIm());
	return *this;
}

CComplex& CComplex::operator-=(CComplex& p) {
	SetRe(GetRe() - p.GetRe());
	SetIm(GetIm() - p.GetIm());
	return *this;
}

CComplex& CComplex::operator*=(CComplex& p) {
	double tempRe = GetRe();
	SetRe(GetRe() * p.GetRe() - GetIm() * p.GetIm());
	SetIm(GetIm() * p.GetRe() + tempRe * p.GetIm());
	return *this;
}

CComplex& CComplex::operator/=(CComplex& p) {
	double a = p.GetRe() * p.GetRe() + p.GetIm() * p.GetIm();
	double tempRe = GetRe();
	SetRe((GetRe() * p.GetRe() + GetIm() * p.GetIm()) / a);
	SetIm((GetIm() * p.GetRe() - tempRe * p.GetIm()) / a);
	return *this;
}

double CComplex::Module() {
	return sqrt(m_re * m_re + m_im * m_im);
}

void CComplex::Coupled() {
	m_im = -m_im;
}

CComplex operator+(CComplex& s,CComplex& p) {
	CComplex temp(s);
	temp += p;
	return temp;
}

CComplex operator-(CComplex& s, CComplex& p) {
	CComplex temp(s);
	temp -= p;
	return temp;
}

CComplex operator*(CComplex& s, CComplex& p) {
	CComplex temp(s);
	temp *= p;
	return temp;
}

CComplex operator/(CComplex& s, CComplex& p) {
	CComplex temp(s);
	temp /= p;
	return temp;
}

BOOL operator==(CComplex& s, CComplex& p) {
	return s.GetRe() == p.GetRe() && s.GetIm() == p.GetIm();
}

BOOL operator!=(CComplex& s, CComplex& p) {
	return s.GetRe() != p.GetRe() || s.GetIm() != p.GetIm(); 
}

std::istream& operator>> (std::istream& s, CComplex& p) {
	s >> p.m_re >> p.m_im;
	return s;
}

std::ostream& operator << (std::ostream& s, CComplex& p) {
	s << "(" << p.GetRe() << "," << p.GetIm() << ")" << std::endl;
	return s;
}


/////////////////CanonComplex

CCanonComplex::CCanonComplex(CComplex& comp)
	:CComplex(comp)
{}

CString CCanonComplex::wypisanie() {
	CString str;
	str.Format(L"%.2f %.2fi", GetRe(), GetIm());
	return str;
}