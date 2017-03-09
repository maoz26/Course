/// Author: Omer Cofman

#include <limits>
#include "MyExceptions.h"
#pragma once

class Expr {
public:
	virtual int evaluate() = 0;
};

class Placeholder : public Expr {
	int evaluate() {
		throw PlaceholderEvaluateCallException();
		return 0;
	}
};

class OpenBrackets : public Expr {
public:
	int evaluate() {
		return INT_MAX;
	}
};

class CloseBrackets : public Expr {
public:
	int evaluate() {
		return INT_MIN;
	}
};

class Number : public Expr {
public:
	Number(int val) {
		_val = val;
	}
	int evaluate() {
		return _val;
	}
private:
	int _val;
};

class At : public Expr {
public:
	void setVal(int val) {
		_val = val;
	}
	int evaluate() {
		return _val;
	}
private:
	int _val;
};

class BinaryOperator : public Expr {
public:
	virtual void setLeft(Expr* left) {
		_left = left;
	}
	virtual void setRight(Expr* right) {
		_right = right;
	}
protected:
	Expr* _left;
	Expr* _right;
};

class Minus : public BinaryOperator {
public:
	virtual int evaluate() {
		return _left->evaluate() - _right->evaluate();
	}
};

class Addition : public BinaryOperator {
public:
	int evaluate() {
		return _left->evaluate() + _right->evaluate();
	}
};

class Multiplay : public BinaryOperator {
public:
	int evaluate() {
		return _left->evaluate() * _right->evaluate();
	}
};

class Division : public BinaryOperator {
public:
	void setRight(Expr* right) {
		if (right->evaluate() == 0) {
			throw DivisionByZeroException();
		}
		_right = right;
	}
	int evaluate() {
		return _left->evaluate() / _right->evaluate();
	}
};

