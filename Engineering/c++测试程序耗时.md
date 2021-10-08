## 背景
通过c++宏来方便的测试程序的耗时

## 实现
```
#include <string>
#include <vector>

#define TS(name) auto t_##name = std::chrono::steady_clock::now()

#define TE(name)                                                                                \
    LOG(TIMER_LOG, VERBOSE, "#Timer_%s: %f ms", #name,                                         \
         std::chrono::duration<double, std::milli>(std::chrono::steady_clock::now() - t_##name) \
             .count())

#endif

```