/*
 * ExpressionFactory.h
 *
 *  Created on: 2 avr. 2015
 *      Author: scrutch
 */

#ifndef CORE_EXPRESSIONFACTORY_H_
#define CORE_EXPRESSIONFACTORY_H_
#include "UnaryExpressionModel.h"
#include "BinaryExpressionModel.h"
#include "Expression.h"
#include <set>

namespace core {

template <class T>
class ExpressionFactory
{
public:
	ExpressionFactory();
	virtual ~ExpressionFactory(){}
	virtual Expression<T>* Hold(Expression<T>* o);
	virtual UnaryExpressionModel<T>* newUnary(UnaryExpression<T>* ope,Expression<T>* o);
	virtual BinaryExpressionModel<T>* newBinary(BinaryExpression<T>* ope, Expression<T>* l, Expression<T>* r);

private:
	std::set<core::Expression<T>* > memory;
	//Faudrait peut être gérer ça...

};

template <class T>
ExpressionFactory<T>::ExpressionFactory():
memory(memory)
{
}

template <class T>
Expression<T>* ExpressionFactory<T>::Hold(Expression<T>* o){
	memory.insert(o);
	return o;
}

template <class T>
UnaryExpressionModel<T>* ExpressionFactory<T>::newUnary(UnaryExpression<T>* ope, Expression<T>* u){
	return new UnaryExpressionModel<T>(ope,u);
}

template <class T>
BinaryExpressionModel<T>* ExpressionFactory<T>::newBinary(BinaryExpression<T>* ope, Expression<T>* l, Expression<T>* r){
	return new BinaryExpressionModel<T>(ope,l,r);
}

}

#endif /* CORE_EXPRESSIONFACTORY_H_ */
