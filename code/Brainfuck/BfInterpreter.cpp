//This is the brainfuck code interpreter. It receives path to .bf file.

#include <iostream>
#include <fstream>
#include <vector>

void Run(const std::vector<char>& code){
    char cpu[30000];
    int pos = 0;
    std::vector<int> loopStack;
    for (int i = 0; i < code.size(); ++i){
        switch (code[i]){
            case '>':
                ++pos;
                break;
            case '<':
                --pos;
                break;
            case '+':
                ++cpu[pos];
                break;
            case '-':
                --cpu[pos];
                break;
            case '.':
                std::cout << cpu[pos];
                break;
            case ',':
                std::cin >> cpu[pos];
            case '[':
                loopStack.push_back(i);
                break;
            case ']':
                if (cpu[pos]){
                    i = *(loopStack.end() - 1);
                }
                else{
                    loopStack.pop_back();
                }
                break;
            default:
                break;
        }
    }
}

int main(int argc, char* argv[]) {
    if (argc < 2){
        std::cout << "You should enter path to brainfuck file!" << std::endl;
        return 1;
    }
    std::ifstream fin(argv[1]);
    std::vector<char> code;
    char ch;
    while (fin){
        fin.get(ch);
        code.push_back(ch);
    }
    code.pop_back();
    fin.close();
    Run(code);
    std::cout << std::endl;
    return 0;
}