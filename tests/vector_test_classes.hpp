#pragma once

#include <string>
#include <iostream>

namespace vector_tests_classes {

//todo Стандартный вектор не создается от класса без конструктора копирования
////! Класс с конструктором по умолчанию
//class DefConstructorClass {
//public:
//    DefConstructorClass(std::string str= "default") :
//            str_(str) {
//    }
//
//    DefConstructorClass(DefConstructorClass &other) = delete;
//
//private:
//    std::string str_;
//};
//
////! Класс без конструктора по умолчанию
//class NoDefConstructorClass {
//public:
//    NoDefConstructorClass(std::string str) :
//            str_(str) {
//    }
//    NoDefConstructorClass(NoDefConstructorClass &other) = delete;
//
//private:
//    std::string str_;
//};

//! Класс с конструктором по умолчанию и конструктором копирования
class CopyConstructorClass {
public:
    CopyConstructorClass(std::string str = "default") :
            str_(str) {
    }

    CopyConstructorClass(const CopyConstructorClass &other) {
        str_ = other.str_;
    }

    friend bool operator ==(const CopyConstructorClass &lhs, const CopyConstructorClass &rhs) {
        return lhs.str_ == rhs.str_;
    }

    ~CopyConstructorClass() {

    }

private:
    std::string str_;
};



//! Класс с исключением в конструкторе копирования
//todo сделать конструктор explicit
class CopyExceptionClass {
public:
    CopyExceptionClass(std::string str = "default") :
            str_(str) {
    }

    CopyExceptionClass(const CopyExceptionClass &other) {
        str_ = other.str_;
        if (str_ == "bye") {
            throw "bye";
        }
    }

    friend bool operator ==(const CopyExceptionClass &lhs, const CopyExceptionClass &rhs) {
        return lhs.str_ == rhs.str_;
    }

private:
    std::string str_;
};

////todo Мой вектор не создается от объекта без стандартного конструктора
////! Класс без конструктора по умолчанию, но с конструктором копирования
//class OnlyCopyConstructorClass {
//public:
//    OnlyCopyConstructorClass(std::string str) :
//            str_(str) {
//    }
//
//    OnlyCopyConstructorClass(const OnlyCopyConstructorClass &other) {
//        str_ = other.str_;
//    }
//
//private:
//    std::string str_;
//};

} //vector_test_classes
