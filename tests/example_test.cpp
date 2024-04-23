
#include <gtest/gtest.h>

#include "example.h"


// TEST(TEST_SUITE, TEST_CASE)

TEST(CPPTemplate, DummyTest)
{
    ASSERT_EQ(dummy_function(), "Hello from dummy_function");
    ASSERT_EQ(2, 2);
}
