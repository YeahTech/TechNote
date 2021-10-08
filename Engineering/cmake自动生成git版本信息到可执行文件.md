## 背景
利用cmake自动将git版本信息编译进二进制文件，方便对应可执行文件和code，确定可执行文件版本。

## 实现
在CMakeLists.txt中添加以下代码：
```
find_package(Git QUIET)
if(GIT_FOUND)
  execute_process(
    COMMAND ${GIT_EXECUTABLE} rev-parse --short HEAD
    OUTPUT_VARIABLE GIT_COMMIT_ID
    OUTPUT_STRIP_TRAILING_WHITESPACE
    ERROR_QUIET
    WORKING_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}
  )
endif()
if(GIT_FOUND)
  execute_process(
    COMMAND ${GIT_EXECUTABLE} describe --always --tags
    OUTPUT_VARIABLE GIT_TAG
    OUTPUT_STRIP_TRAILING_WHITESPACE
    ERROR_QUIET
    WORKING_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}
  )
endif()
if(GIT_FOUND)
  execute_process(
    COMMAND ${GIT_EXECUTABLE} rev-parse --abbrev-ref HEAD
    OUTPUT_VARIABLE GIT_BRANCH
    OUTPUT_STRIP_TRAILING_WHITESPACE
    ERROR_QUIET
    WORKING_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}
  )
endif()
add_definitions( -DGIT_COMMIT_ID=\"${GIT_COMMIT_ID}\")
add_definitions( -DGIT_TAG=\"${GIT_TAG}\")
add_definitions( -DGIT_BRANCH=\"${GIT_BRANCH}\")
```
在main.cpp中使用变量：
```
int main(int argc, char **argv) {
    std::cout << "[GIT_COMMIT_ID]: " << GIT_COMMIT_ID << " [GIT_TAG]: " << GIT_TAG
              << " [GIT_BRANCH]: " << GIT_BRANCH << std::endl;
}
```