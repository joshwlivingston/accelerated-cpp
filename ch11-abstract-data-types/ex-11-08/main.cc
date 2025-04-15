#include <iostream>

#include "iterator_input.h"
#include "iterator_forward.h"
#include "iterator_bidirectional.h"

int main()
{
    typedef IteratorInput<double> iit;
    // initialize an empty InputIterator
    iit iit_01;

    // Copy the empty array into a new array
    iit iit_02(iit_01);

    // Create new InputIterator with default value
    double four = 4; // need to allocate before initializing InputIterator
    iit iit_04(four);

    // Create new InputIterator with default values
    double three = 3;
    iit iit_05(three, iit_04);

    // Assign to new array
    iit iit_03 = iit_05;

    // delete that array
    iit_03.~IteratorInput();

    // verify isolated deletion effect, derference, increment
    std::cout << "Should print " << four << ": " << *++iit_05 << std::endl;

    // equality operator
    std::cout << "true expected: " << (iit_05 == iit_05) << std::endl;
    std::cout << "false expected: " << (iit_05 == iit_04) << std::endl;
    std::cout << "false expected: " << (iit_05 == iit_03) << std::endl;

    // inequality operator
    std::cout << "false expected: " << (iit_05 != iit_05) << std::endl;
    std::cout << "true expected: " << (iit_05 != iit_04) << std::endl;
    std::cout << "true expected: " << (iit_05 != iit_03) << std::endl;

    typedef IteratorForward<double> fit;
    // initialize an empty ForwardIterator
    fit fit_01;

    // Copy into new
    fit fit_02(fit_01);

    // create new with defaults
    fit fit_05(three);
    fit fit_04(four, fit_05);

    // reassign the value
    *fit_05 = 5;

    // assign to new array
    fit fit_00 = fit_05;

    // delete that array
    fit_00.~IteratorForward();

    // verify isolated deletion effect, derference, increment
    std::cout << "Should print 5: " << *++fit_04 << std::endl;

    // equality operator
    std::cout << "true expected: " << (fit_05 == fit_05) << std::endl;
    std::cout << "false expected: " << (fit_05 == fit_04) << std::endl;
    std::cout << "false expected: " << (fit_05 == fit_00) << std::endl;

    // inequality operator
    std::cout << "false expected: " << (fit_05 != fit_05) << std::endl;
    std::cout << "true expected: " << (fit_05 != fit_04) << std::endl;
    std::cout << "true expected: " << (fit_05 != fit_00) << std::endl;

    typedef IteratorBidirectional<double> bit;
    // initialize an empty bidirectional iterator
    bit bit_01;

    // copy into new
    bit bit_02(bit_01);

    // create new with defaults
    double seven = 7;
    double five = 5;
    bit bit_04;
    bit bit_05;
    bit bit_06;

    bit_04 = bit(four, bit_05);
    bit_05 = bit(bit_04, five, bit_06);
    bit_06 = bit(bit_05, seven);

    // reassign a value
    const double x = *bit_06;
    std::cout << "Should print 7: " << x << std::endl;
    *bit_06 = 6;

    // assign to new
    bit bit_00 = bit_06;

    // delete
    bit_00.~IteratorBidirectional();

    // verify isolated deletion effect, derference, increment
    std::cout << "Should print 6: " << *++bit_05 << std::endl;

    // decrement
    std::cout << "Should print 4: " << *--bit_05 << std::endl;

    // equality operator
    std::cout << "true expected: " << (bit_06 == bit_06) << std::endl;
    std::cout << "false expected: " << (bit_06 == bit_04) << std::endl;
    std::cout << "false expected: " << (bit_06 == bit_00) << std::endl;

    // inequality operator
    std::cout << "false expected: " << (bit_06 != bit_06) << std::endl;
    std::cout << "true expected: " << (bit_06 != bit_04) << std::endl;
    std::cout << "true expected: " << (bit_06 != bit_00) << std::endl;
}
