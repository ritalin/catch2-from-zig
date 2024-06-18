#include <catch2/catch_session.hpp>
#include <iostream>
#include <fstream>

extern "C" {

auto run_catch2_test() -> int {
    // 標準出力をファイルにリダイレクト
    std::ofstream out("output.txt");
    std::streambuf* coutbuf = std::cout.rdbuf(); // 標準出力のバッファを保存
    std::cout.rdbuf(out.rdbuf()); // 標準出力をリダイレクト

    int argc = 2;
    const char* argv[] = { "your_program_name", "--success" };

    Catch::Session session;

    // Apply the command line arguments
    int returnCode = session.applyCommandLine(argc, argv);
    if (returnCode != 0) { // Indicates a command line error
        std::cout << "Error parsing command line arguments\n";
        return -1;
    }

    // Run the tests and capture the result
    int result = session.run();
    
    std::cout.rdbuf(coutbuf); // 標準出力を元に戻す
    return result;
}

}
