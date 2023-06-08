#include <iostream>
#include <vector>
#include <algorithm>

class IntegerSequence {
public:
    virtual std::vector<int> Numbers() = 0;
};
class VectorSequence : public IntegerSequence {
private:
    std::vector<int> numbers_;
public:
    VectorSequence(const std::vector<int>& numbers) : numbers_(numbers) {}
    std::vector<int> Numbers() override {
        return numbers_;
    }
};
class PositiveSequence : public IntegerSequence {
private:
    IntegerSequence* sequence_;
public:
    PositiveSequence(IntegerSequence* sequence) : sequence_(sequence) {}
    std::vector<int> Numbers() override {
        std::vector<int> numbers = sequence_->Numbers();
        numbers.erase(std::remove_if(numbers.begin(), numbers.end(), [](int num) { return num < 0; }), numbers.end());
        return numbers;
    }
};
class EvenSequence : public IntegerSequence {
private:
    IntegerSequence* sequence_;
public:
    EvenSequence(IntegerSequence* sequence) : sequence_(sequence) {}
    std::vector<int> Numbers() override {
        std::vector<int> numbers = sequence_->Numbers();
        numbers.erase(std::remove_if(numbers.begin(), numbers.end(), [](int num) { return num % 2 != 0; }), numbers.end());
        return numbers;
    }
};
class SortedSequence : public IntegerSequence {
private:
    IntegerSequence* sequence_;
public:
    SortedSequence(IntegerSequence* sequence) : sequence_(sequence) {}
    std::vector<int> Numbers() override {
        std::vector<int> numbers = sequence_->Numbers();
        std::sort(numbers.begin(), numbers.end());
        return numbers;
    }
};
int main() {
    std::vector<int> numbers = { 99, -11, 6, 5, -3, 10, 16, -2, 8, 0, -1, -10 };
    IntegerSequence* sequence = new VectorSequence(numbers);
    sequence = new PositiveSequence(sequence);
    sequence = new EvenSequence(sequence);
    sequence = new SortedSequence(sequence);
    std::vector<int> NewSequence = sequence->Numbers();
    std::cout << "old sequence: ";
    for (int i : numbers) {
        std::cout << i << ", ";
    }
    std::cout << std::endl << "new sequence: ";
    for (int i : NewSequence) {
        std::cout << i << ", ";
    }
    std::cout << std::endl;
    delete sequence;
    return 0;
}