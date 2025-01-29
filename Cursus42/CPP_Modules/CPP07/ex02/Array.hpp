/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: winniexd <winniexd@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/26 20:44:43 by winniexd          #+#    #+#             */
/*   Updated: 2025/01/29 13:47:38 by winniexd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ARRAY_HPP
#define ARRAY_HPP
#include <iostream>
#include <exception>

template <typename T> class Array {
    private:
        unsigned int arraySize;
        T* array;
    public:
        Array();
        Array(unsigned int n);
        Array(const Array<T> &src);
        ~Array();
        T& operator=(const Array<T> &rhs);
        unsigned int size() const;
        T& operator[](unsigned int n) const;
    class OutOfBoundsException : public std::exception {
        public:
            virtual const char* what() const throw();
        };
};

template<typename T>
Array<T>::Array(): array(new T[0]), arraySize(0) {

}

template<typename T>
Array<T>::Array(unsigned int n) {
    this->array = new T[n];
    this->arraySize = n;
    for (unsigned int i = 0; i < n; i++) {
        this->array[i] = 0;
    }
}

template<typename T>
Array<T>::Array(const Array<T> &src) {
    this->arraySize = src.size();
    this->array = new T[this->arraySize];
    for (unsigned int i = 0; i < this->arraySize; i++) {
        this->array[i] = 0;
    }
}

template<typename T>
Array<T>::~Array() {
    delete [] this->array;
}

template<typename T>
T& Array<T>::operator=(const Array<T> &rhs) {
    this->arraySize = rhs.size();
    this->array = new T[this->arraySize];
    for (unsigned int i = 0; i < this->arraySize; i++) {
        this->array[i] = 0;
    }
    return *this;
}

template<typename T>
T& Array<T>::operator[](unsigned int n) const {
    if (n > this->arraySize - 1)
        throw Array::OutOfBoundsException();
    return this->array[n];
}

template<typename T>
unsigned int Array<T>::size() const {
    return this->arraySize;
}

template<typename T>
const char* Array<T>::OutOfBoundsException::what() const throw() {
    return "Index Out Of Bounds";
}

#endif