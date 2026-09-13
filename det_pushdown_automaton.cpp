#include <iostream> // for in-/output of text in console
#include <string>
#include <list>

using namespace std;

// this program is wanted to be a pushdown automaton for palindromes
// deterministic version for learning C++ basics
// language: {a, b}; separator has to be "X"

int main() {
    string status = "q0";  // q0 -> front half, q1 -> back half
    string palindrome = "abXba";  // X as separation of front and back half
    list<char> stack = {};

    for (char i: palindrome)
    {
        if (i == 'X')
        {
            stack.remove('X');
            status = "q1";
        }
        else if (status == "q0")
        {
            stack.push_front(i);
        }
        else if (status == "q1")
        {
            if (stack.empty())
            {
                // stack empty, but letters remaining
                status = "reject";
            }
            else if (stack.front() == i)
            {
                // match with top-level element
                stack.pop_front();
            }
            else
            {
                // mismatch with top-level element
                status = "reject";
            }
        }
    }

    if (status == "reject")
    {
        cout << "Error: Word is not a palindrome" << endl;
    }
    else if (stack.empty())
    {
        cout << "Success: Palindrome" << endl;
    }
    else
    {
        cout << "Error: Word is not a palindrome" << endl;
    }
}
