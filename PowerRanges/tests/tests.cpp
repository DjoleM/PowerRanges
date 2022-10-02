#include "../src/powerRanges.h"

#include <iostream>
#include <cassert>

void testRangeInt();
void testRangeChar();
void testRangeBounds();
void testUnifiedRanges();

int main(int argc, char* argv[]) {
    testRangeInt();
    testRangeChar();
    testRangeBounds();
    testUnifiedRanges();

    char c;
    std::cout << "Hit Enter to exit" << std::endl;
    std::cin >> c;
    return 0;
}

void testRangeInt() {
    std::cout << "Running testRangeInt()...";

    auto rangeSet = powerRanges::range<int>(0, 3);
    std::vector<int> expected{0, 1, 2, 3};

    assert(*rangeSet == expected);

    std::cout << "Passed" << std::endl;
}

void testRangeChar() {
    std::cout << "Running testRangeChar()...";

    auto rangeSet = powerRanges::range<char>('A', 'D');
    std::vector<char> expected{'A', 'B', 'C', 'D'};

    assert(*rangeSet == expected);

    std::cout << "Passed" << std::endl;
}

void testRangeBounds() {
    std::cout << "Running testRangeBounds()...";

    auto rangeBounds = new powerRanges::rangeBounds<char>('q', 'w');
    auto rangeSet = powerRanges::range<char>(rangeBounds);
    std::vector<char> expected{ 'q', 'r', 's', 't', 'u', 'v', 'w' };

    assert(*rangeSet == expected);

    std::cout << "Passed" << std::endl;
}

void testUnifiedRanges() {
    std::cout << "Running testUnifiedRanges()...";

    auto bounds1 = new powerRanges::rangeBounds<char>('A', 'D');
    auto bounds2 = new powerRanges::rangeBounds<char>('0', '4');
    auto bounds3 = new powerRanges::rangeBounds<char>('q', 'w');

    std::vector<powerRanges::rangeBounds<char>*> rangeBounds{ bounds1, bounds2, bounds3 };

    auto rangeSet = powerRanges::unifiedRange<char>(&rangeBounds);
    std::vector<char> expected{ 'A', 'B', 'C', 'D', '0', '1', '2', '3', '4', 'q', 'r', 's', 't', 'u', 'v', 'w' };

    assert(*rangeSet == expected);
    
    std::cout << "Passed" << std::endl;
}