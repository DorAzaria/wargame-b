//
// Created by dor on 26/05/2020.
//
#include <iostream>
#include "doctest.h"
using namespace  std;
TEST_CASE("one") {
    int i = 0;
    while( i < 100) {
        CHECK(true);
        i++;
    }
}