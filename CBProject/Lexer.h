
#include <string>
#include <vector>
#include <regex>
#include <iostream>
#include <stack>
#include <map>
#include "Exper.h"
#include "Parser.h"
#include "MyExceptions.h"
using namespace std;

#pragma once

class Lexer {
public:
	void setExpr(string expr) {
		if (isInputOk(expr)) {
			_expr = expr;
		}
		else {
			throw InvalidExpressionException();
		}
	}
	int getExpr(int at) {
		return _parser.getExpr(at)->evaluate();
	}
	void tokenize() {
		vector<regex> regvec = getRegvec();
		vector<string> strvec;
		regex_token_iterator<string::iterator> rend;
		vector<regex_token_iterator<string::iterator>> rtivec;
		// set iterators
		for (int i = 0; i < regvec.size(); i++) {
			rtivec.push_back(regex_token_iterator<string::iterator>(_expr.begin(), _expr.end(), regvec[i]));
		}
		// find expressions
		for (int i = 0; i < rtivec.size(); i++) {
			while (rtivec[i] != rend) {
				strvec.push_back(*rtivec[i]++);
			}
		}
		// oreder expressions
		int offset;
		map<int, string> exmap;
		string clone = _expr, replacement;
		for (int i = 0; i < strvec.size(); i++) {
			offset = clone.find_first_of(strvec[i]);
			replacement = "";
			for (int j = 0; j < strvec[i].length(); j++) {
				replacement += "_";
			}
			clone = clone.replace(offset, strvec[i].length(), replacement);
			exmap.insert(pair<int, string>(offset, strvec[i]));
		}

		for (map<int, string>::iterator it = exmap.begin(); it != exmap.end(); it++) {
			_stokenvec.push_back(it->second);
		}

		callParser();
	}
	vector<regex> getRegvec() {
		vector<regex> regvec;
		regvec.push_back(regex("[0-9]+"));		// 0 CONSTANT
		regvec.push_back(regex("[+*/\-]"));		// 1 OPERATION
		regvec.push_back(regex("@"));			// 2 AT
		regvec.push_back(regex("[()]"));		// 3 BRACKETS
		return regvec;
	}
	void callParser() {
		vector<regex> regvec = getRegvec();
		// 0 CONSTANT
		// 1 OPERATION
		// 2 AT
		// 3 BRACKETS
		for (vector<string>::iterator s = _stokenvec.begin(); s != _stokenvec.end(); s++) {
			for (int i = 0; i < regvec.size(); i++) {
				if (regex_match(*s, regvec[i])) {
					switch (i) {
					case 0:
						_parser.processConst(stoi(*s));
						break;
					case 1:
						_parser.processOperator(*s);
						break;
					case 2:
						_parser.processAt();
						break;
					case 3:
						_parser.processBrackets(*s == "(");
						break;
					default:
						throw SomethingWentTerriblyWrongException();
					}
				}
			}
		}
	}
	bool isInputOk(string expr) {
		string s, last;
		stack<string> sstck;

		// check for white spaces
		for each (char c in expr) {
			s = c;
			if (regex_match(s, regex("[ \n\t]"))) {
				throw std::exception();
			}
		}

		// check for brackets balance and correct usage in expr
		for each (char c in expr) {
			s = c;
			if (s == "(") {
				if (!sstck.empty()) {
					throw DoubleBracketsException();
				}
				sstck.push(s);
				continue;
			}
			if (!sstck.empty()) {
				if (s == "(") {
					throw DoubleBracketsException();
				}
				if (s == ")") {
					sstck.pop();
					continue;
				}
			}
		}

		if (!sstck.empty()) {
			return false;
		}

		// if we got here it means that the brackets in expr are balanced
		// check for correct unary minus usage in expr
		for each (char c in expr) {
			s = c;
			if (regex_match(s, regex("[@0-9]"))) {
				sstck.push(s);
				continue;
			}
			if (s == "(") {
				sstck.push(s);
				continue;
			}
			if (s == ")") {
				if (!sstck.empty()) {
					if (sstck.top() == "(") {
						sstck.pop();
					}
				}
			}
			if (s == "-") {
				if (!sstck.empty()) {
					if (sstck.top() == "(") {
						sstck.pop();
					}
					else if (sstck.top() == "-") {
						throw std::exception();
					}
					else if (regex_match(sstck.top(), regex("[@0-9]"))) {
						sstck.pop();
						continue;
					}
				}
				else {
					throw std::exception();
				}
			}
		}

		while (!sstck.empty()) {
			if (sstck.top() != ")" && !regex_match(sstck.top(), regex("[@0-9]"))) {
				return false;
			}
			sstck.pop();
		}

		return true;
	}
	void setParser(Parser &parser) {
		// used only for testing
		_parser = parser;
	}
	vector<string> getStokenvec() {
		return _stokenvec;
	}
private:
	vector<string> _stokenvec;
	string _expr;
	Parser _parser;
};