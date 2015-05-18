/*
 * MandaniDefuzz.h
 *
 *  Created on: 17 mai 2015
 *      Author: gael
 */

#ifndef FUZZY_MANDANIDEFUZZ_H_
#define FUZZY_MANDANIDEFUZZ_H_

#include "../core/BinaryExpression.h"

/*
 * Ne calcule rien
 *
 */

namespace fuzzy {

	template <class T>
	class MandaniDefuzz : public core::BinaryExpression<T> {
	private:
		T min;
		T max;
		T step;
	public:
		MandaniDefuzz(const T&, const T&, const T&);

		T Evaluate(core::Expression<T>*, core::Expression<T>*) const;

		virtual T defuzz(const typename core::Evaluator<T>::Shape&) const = 0;

	};

	template <class T>
	MandaniDefuzz<T>::MandaniDefuzz(const T& _min, const T& _max, const T& _step):
		min(_min), max(_max), step(_step) {

	}

	template <class T>
	T MandaniDefuzz<T>::Evaluate(core::Expression<T>* l, core::Expression<T>* r) const {
		return defuzz(core::Evaluator<T>::BuildShape(min, max, step, (core::ValueModel<T>*)l,r));

	}

}

#endif /* FUZZY_MANDANIDEFUZZ_H_ */