#include <iostream>
#include "text_table.h"

using namespace utils;
int main(int argc, char **argv) {
    // 表名，全表填充 1
    TextTable table("detection");
    table.padding(1);

    // 表头居中
    table.align(TextTable::Align::Mid);
    table.add("preproc").add("inference").add("postproc").eor();

    // 第一行
    table.align(TextTable::Align::Mid);
    table.add("12").add("4").add("66").eor();

    // 第二行的一部分
    table.align(TextTable::Align::Mid);
    table.add("1.6").add("55");
    // 第二行的尾巴，可以缺数据
    table.eor();

    std::cout << table << std::endl;
}