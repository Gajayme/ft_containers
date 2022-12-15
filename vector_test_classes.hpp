#pragma once

namespace vector_tests_classes {

class DefConstructorClass {
public:
    DefConstructorClass(int num = 10) :
            num_(num) {
    }

    DefConstructorClass(DefConstructorClass &other) = delete;

private:
    int num_;
};

class NoConstructorClass {
public:
    NoDefConstructorClass(int num) :
            num_(num) {
    }
    NoDefConstructorClass(NoDefConstructorClass &other) = delete;

private:
    int num_;
};

class CopyConstructorClass {
public:
    CopyConstructorClass(int num = 10) :
            num_(num) {
    }
    CopyConstructorClass(CopyConstructorClass &other) = delete;

private:
    int num_;
};

} //vector_test_classes
