# clion_pro_template
这是一个使用CLion写C++项目的模板。
默认是生成库文件，如果你的项目需要完整的可执行文件，那么可以自行改对应的 `add_library` 为 `add_executable` 即可。tests 目录中的 cmake 不需要更改，因为它不是基于库文件的。

* `include` ：头文件目录
* `src` ：源文件目录
* `tests` ：测试文件目录
* `.clang-format` ：本项目的代码格式化风格
* `Doxyfile` ：通过doxygen生成文档的配置文件
* `docs` ：通过doxygen生成文档的输出路径

如果这个模板有用，请点一个🌟吧！