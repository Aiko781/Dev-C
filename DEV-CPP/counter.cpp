#include <iostream>

class Counter {
    public:
        virtual void reset() = 0;
        virtual void operator++() = 0;
        virtual void operator()() = 0;
};

class IntCounter : Counter
{
    private:
        int value;
    public:
        IntCounter(int value): value(value) {};
        void reset() override {value = 0;};
        void operator++() override {value++;};
        void operator()() override {std::cout << "value :" << value << "\n";};
};

class charCounter: Counter {
    private:
        char value;
    public:
        charCounter(char value): value(value) {};
        void reset() override {value = 'a';};
        void operator++() override {
            if (value == 'z') {
                value = 'a';
            }
            else {
                value++;
            }
        };
        void operator()() override {std::cout << "value :" << value << "\n";};
};

int main() {
    auto int_counter = IntCounter(0);
    for (size_t i = 0; i < 10; i++) {
        int_counter();
        ++int_counter;
    }
    auto char_counter = charCounter('z');
    for (size_t i = 0; i < 10; i++) {
        char_counter();
        ++char_counter;
    }
    int_counter();
    int_counter.reset();
    
    char_counter();
    char_counter.reset();
};