

#include <exception>
using namespace std;

#pragma once

class InvalidExpressionException : public exception {
public:
	virtual const char* what() const {
		return "Invalid Expression";
	}
};

class DoubleBracketsException : public InvalidExpressionException {
public:
	const char* what() const {
		return "This program does not support brakets within another brackets THANK YOU";
	}
};

class DivisionByZeroException : public exception {
public:
	const char* what() const {
		return "You tried to divied by zero";
	}
};

class UnaryMinusLeftOperandAssignmentException : public exception {
public:
	const char* what() const {
		return "UnaryMinus left operand should remain zero and you technically can't change it";
	}
};

class SomethingWentTerriblyWrongException : public exception {
public:
	const char* what() const {
		return "What possibly could you done to get this error?";
	}
};

class PlaceholderEvaluateCallException : public exception {
public:
	const char* what() const {
		return "Placeholder has no value";
	}
};
