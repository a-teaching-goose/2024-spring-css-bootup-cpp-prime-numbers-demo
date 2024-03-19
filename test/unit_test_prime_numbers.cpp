#include "gtest/gtest.h"
#include "util.h"
#include "prime_numbers/prime_numbers.h"

template<typename T>
void ASSERT_ARRAY_EQUAL(T *ArrayA, T *ArrayB, T size) {
    for (int i = 0; i < size; i++) {
        ASSERT_EQ(ArrayA[i], ArrayB[i]);
    }
}

TEST(prime_number, valid_inputs) {
    int input[12] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};

    int expects[10][10] = {
            {2},
            {2, 3},
            {2, 3, 5},
            {2, 3, 5, 7},
            {2, 3, 5, 7, 11},
            {2, 3, 5, 7, 11, 13},
            {2, 3, 5, 7, 11, 13, 17},
            {2, 3, 5, 7, 11, 13, 17, 19},
            {2, 3, 5, 7, 11, 13, 17, 19, 23},
            {2, 3, 5, 7, 11, 13, 17, 19, 23, 29},
    };

    for (int i = 0; i < 10; i++) {
        int *actual = get_primes(input[i]);
        ASSERT_ARRAY_EQUAL<int>(expects[i], actual, i + 1);
    }
}

TEST(prime_number, invalid_inputs) {
    for (int i = -1; i < 1; i++) {
        ASSERT_EQ(nullptr, get_primes(i));
    }
}
