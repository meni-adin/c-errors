
#include <cstdlib>
#include <gmock/gmock.h>

#include "errors.h"

using namespace std;
using namespace testing;

class ErrorsTest : public ::testing::Test {};

#ifdef C_ERRORS_SAFE_MODE
TEST_F(ErrorsTest, InvalidArguments) {
    ASSERT_EQ(errors_getStr(ERR_COUNT), nullptr);
}
#endif  // C_DATABASES_SAFE_MODE

TEST_F(ErrorsTest, GetStr) {
    ASSERT_STREQ(errors_getStr(ERR_MEM_ALLOC), "Memory allocation failed");
}

TEST_F(ErrorsTest, AssertSuccess) {
    errors_assert(SUCCESS);
}

TEST_F(ErrorsTest, AssertFailure) {
    ASSERT_EXIT(errors_assert(ERR_BAD_ARGUMENT),
                ExitedWithCode(ERR_BAD_ARGUMENT),
                "Function called with a bad argument");
}

TEST_F(ErrorsTest, AssertUnknown) {
    ASSERT_EXIT(errors_assert(ERR_COUNT), ExitedWithCode(ERR_COUNT), "unknown error");
}

int main(int argc, char *argv[]) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
