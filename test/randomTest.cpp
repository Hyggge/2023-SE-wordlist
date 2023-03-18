#include <random>
#include <fstream>
#include "test.h"
using namespace std;

TEST(randomTest, randomTest1) {
    for (int testcases = 0; testcases < 100; ++testcases) {
        int res1 = 0, res2 = 0;
        try {
            random_device rd;
            default_random_engine e(rd());
            uniform_int_distribution<char> lower('a', 'z');
            uniform_int_distribution<char> upper('A', 'Z');
            bernoulli_distribution coin(0.5);
            uniform_int_distribution<int> length(1, 10);
            ofstream fout50("words50.txt");
            int n = 50;
            char word[110];
            for (int i = 0; i < n; ++i) {
                int word_len = length(e);
                for (int j = 0; j < word_len; ++j) {
                    if (coin(e)) word[j] = lower(e);
                    else word[j] = upper(e);
                }
                for (int j = 0; j < word_len; ++j) fout50 << word[j];
                fout50 << endl;
            }
            fout50.close();
            ofstream fout10000("words10000.txt");
            n = 10000 - 26;
            for (int i = 0; i < n; ++i) {
                int word_len = length(e) + 1;
                word[0] = lower(e);
                while (tolower(word[0]) == 'z') {
                    if (coin(e)) word[0] = lower(e);
                    else word[0] = upper(e);
                }
                for (int j = 1; j < word_len; ++j) {
                    if (coin(e)) word[j] = lower(e);
                    else word[j] = upper(e);
                }
                while (tolower(word[word_len - 1]) <= tolower(word[0])) {
                    if (coin(e)) word[word_len - 1] = lower(e);
                    else word[word_len - 1] = upper(e);
                }
                for (int j = 0; j < word_len; ++j) fout10000 << word[j];
                fout10000 << endl;
            }
            for (int i = 0; i < 26; ++i) {
                if (coin(e)) continue;
                int word_len = length(e);
                if (coin(e)) word[0] = char(i + 'a');
                else word[0] = char(i + 'A');
                for (int j = 1; j < word_len - 1; ++j) {
                    if (coin(e)) word[j] = lower(e);
                    else word[j] = upper(e);
                }
                if (word_len > 1) {
                    if (coin(e)) word[word_len - 1] = char(i + 'a');
                    else word[word_len - 1] = char(i + 'A');
                }
                for (int j = 0; j < word_len; ++j) fout10000 << word[j];
                fout10000 << endl;
            }
            fout10000.close();
            std::system(R"(.\bin\WordList.exe -c -r .\words50.txt > .\my.out)");
            // std::cerr << "finished my.out" << std::endl;
            std::system(R"(.\std.exe -c -r .\words50.txt)");
            // std::cerr << "finished std.out" << std::endl;
            // 对比 my.out 和 solution.txt 中的单词总字母数是否相同
            ifstream fin1("my.out");
            ifstream fin2("solution.txt");
            string s1, s2;
            int lens1 = 0, lens2 = 0;
            while (fin1 >> s1) lens1 += (int) s1.length();
            while (fin2 >> s2) lens2 += (int) s2.length();
            fin1.close();
            fin2.close();
            if (lens1 != lens2) {
                std::cerr << "lens1 = " << lens1 << ", lens2 = " << lens2 << std::endl;
                res1 = 1;
            }
            std::system(R"(.\bin\WordList.exe -c -r .\words10000.txt > .\my.out)");
            // std::cerr << "finished my.out" << std::endl;
            std::system(R"(.\std.exe -c .\words10000.txt)");
            // std::cerr << "finished std.out" << std::endl;
            // 对比 my.out 和 solution.txt 中的单词总字母数是否相同
            fin1.open("my.out");
            fin2.open("solution.txt");
            lens1 = 0, lens2 = 0;
            while (fin1 >> s1) lens1 += (int) s1.length();
            while (fin2 >> s2) lens2 += (int) s2.length();
            fin1.close();
            fin2.close();
            if (lens1 != lens2) {
                std::cerr << "lens1 = " << lens1 << ", lens2 = " << lens2 << std::endl;
                res2 = 1;
            }
        } catch (exception &e) {
            FAIL() << "e.what() : " << e.what();
        }
        ASSERT_EQ(res1, 0);
        ASSERT_EQ(res2, 0);
        std::cout << "\033[32m" << "testcases " << testcases << " passed" << "\033[0m" << std::endl;
    }
}