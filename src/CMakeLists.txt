include(FetchContent)

FetchContent_Declare(
  googletest
  GIT_REPOSITORY https://github.com/google/googletest.git
  GIT_TAG        release-1.11.0
)
FetchContent_MakeAvailable(googletest)

FetchContent_Declare(ApprovalTests
        GIT_REPOSITORY https://github.com/approvals/ApprovalTests.cpp.git
        GIT_TAG master)

FetchContent_MakeAvailable(ApprovalTests)

add_library(GTest::GTest INTERFACE IMPORTED)
target_link_libraries(GTest::GTest INTERFACE gtest_main)

add_executable(${PROJECT_NAME}_test geometry_tests.cpp main.cpp)

target_include_directories(${PROJECT_NAME}_test PRIVATE /opt/homebrew/include)
target_link_libraries(${PROJECT_NAME}_test PRIVATE ApprovalTests::ApprovalTests GTest::GTest)
  
#add_test(yanl_gtests matrix_test)

