
#include <stack>
#include <vector>
#include "Exper.h"
using namespace std;

#pragma once

class Parser {
public:
	void processConst(int val) {
		_evec.push_back(new Number(val));
	}
	void processOperator(string op) {
		switch (op[0]) {
		case '+':
			_evec.push_back(new Addition());
			break;
		case '*':
			_evec.push_back(new Multiplay());
			break;
		case '/':
			_evec.push_back(new Division());
			break;
		case '-':
			_evec.push_back(new Minus());
			break;
		default:
			throw SomethingWentTerriblyWrongException();
		}
	}
	void processBrackets(bool flag) {
		if (flag) {
			_evec.push_back(new OpenBrackets());
		}
		else {
			_evec.push_back(new CloseBrackets());
		}
	}
	void processAt() {
		_evec.push_back(new At());
	}
	virtual Expr* Parser::getExpr(int at) {
		return getExpr(at, 0, _evec);	// A patchy patch
	}
	Expr* getExpr(int at, int value, vector<Expr*> evec) {
		vector<vector<Expr*>> emat(2);
		vector<Expr*> bvec;
		BinaryOperator* ob;
		// search for brackets
		for (auto i = evec.begin(); i != evec.end(); i++) {
			if (dynamic_cast<OpenBrackets*>(*i) != NULL) {
				for (auto j = (i + 1); dynamic_cast<CloseBrackets*>(*j) == NULL; j++) {
					bvec.push_back(*j);
				}
				evec.erase(i + 1, i + 2 + bvec.size());
				*i = getExpr(at, value, bvec);
				bvec.clear();
			}
		}
		// search for low priority operators
		for (auto i = evec.begin(); i != evec.end(); i++) {
			ob = dynamic_cast<BinaryOperator*>(*i);
			if (ob != NULL) {
				if (dynamic_cast<Addition*>(ob) != NULL || dynamic_cast<Minus*>(ob) != NULL) {
					*i = new Placeholder();
					int k = 0;
					for (auto j = evec.begin(); j != evec.end(); j++) {
						if (dynamic_cast<Placeholder*>(*j) != NULL) {
							k++;
							j++;
						}
						emat[k].push_back(*j);
					}
					if (!emat[0].empty()) {
						ob->setLeft(getExpr(at, value, emat[0]));
					}
					else {
						// "UnaryMinus"
						emat[0].push_back(new Number(0));
						ob->setLeft(getExpr(at, value, emat[0]));
					}
					ob->setRight(getExpr(at, value, emat[1]));
					emat.clear();
					value = ob->evaluate();
					return new Number(value);
				}
			}
		}
		// search for high priority operators
		for (auto i = evec.begin(); i != evec.end(); i++) {
			ob = dynamic_cast<BinaryOperator*>(*i);
			if (ob != NULL) {
				if (dynamic_cast<Multiplay*>(ob) != NULL || dynamic_cast<Division*>(ob) != NULL) {
					*i = new Placeholder();
					int k = 0;
					for (auto j = evec.begin(); j != evec.end(); j++) {
						if (dynamic_cast<Placeholder*>(*j) != NULL) {
							k++;
							j++;
						}
						emat[k].push_back(*j);
					}
					ob->setLeft(getExpr(at, value, emat[0]));
					ob->setRight(getExpr(at, value, emat[1]));
					emat.clear();
					value = ob->evaluate();
					return new Number(value);
				}
			}
		}
		// search for numbers and @
		for (auto i = evec.begin(); i != evec.end(); i++) {
			Number* n = dynamic_cast<Number*>(*i);
			if (n != NULL) {
				return n;
			}
			At* a = dynamic_cast<At*>(*i);
			if (a != NULL) {
				return new Number(at);
			}
		}
	}
private:
	vector<Expr*> _evec;
};

