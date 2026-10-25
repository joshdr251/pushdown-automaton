
#include <iostream>  // for in-/output of text in console
#include <string>
#include <list>

// this program is wanted to be a pushdown automaton for palindromes
// deterministic version for learning C++ basics
// language: {a, b}; separator has to be "X"

int main() {
    std::string status = "q0";  // q0 -> front half, q1 -> back half
    std::string palindrome = "abXba";  // X as separation of front and back half
    std::list<char> stack = {};

    for (char i: palindrome) {
        if (i == 'X') {
            stack.remove('X');
            status = "q1";
        }
        else if (status == "q0") {
            stack.push_front(i);
        }
        else if (status == "q1") {
            if (stack.empty()) {
                // stack empty, but letters remaining
                status = "reject";
            }
            else if (stack.front() == i) {
                // match with top-level element
                stack.pop_front();
            }
            else {
                // mismatch with top-level element
                status = "reject";
            }
        }
    }

    if (status == "reject") {
        std::cout << "Error: Word is not a palindrome" << std::endl;
    }
    else if (stack.empty()) {
        std::cout << "Success: Palindrome" << std::endl;
    }
    else {
        std::cout << "Error: Word is not a palindrome" << std::endl;
    }
}
