file(GLOB_RECURSE ALL_SOURCE_FILES src/*.cpp src/*.h)

add_custom_target(
        cppcheck 
        ALL
        COMMAND /opt/homebrew/bin/cppcheck
        --enable=warning,style,performance,portability,unusedFunction
        --inconclusive
        --language=c++
        --std=c++20
        --force
        --verbose
        ${ALL_SOURCE_FILES}
)
