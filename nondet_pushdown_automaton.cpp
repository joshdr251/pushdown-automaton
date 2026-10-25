
#include <iostream>
#include <string>
#include <list>

//  returns user_input, no # allowed
std::string user_input() {
    while (true) {
        std::string palindrome_input;
        std::cout << "Enter the palindrome you want to check: " << std::endl;
        getline(std::cin, palindrome_input);
        if (palindrome_input.find('#') != std::string::npos) {
            std::cout << "Not allowed to input #" <<  std::endl;
            continue;
        }
        return palindrome_input;
    }
}

// status = q1; true = successfully tested as palindrome
bool q1_validate_and_commit(const std::string& palindrome, std::size_t position, std::list<char> stack) {
    while (position < palindrome.length()) {
        if (stack.front() == palindrome[position]) {
            stack.pop_front();
            ++position;
        }
        else {
            return false;
        }
    }
    return stack.front() == '#';
}

// status = q0; true = one of the three paths is successful
bool q0_iterate(const std::string& palindrome, std::size_t position, std::list<char> stack) {
    bool straight = q1_validate_and_commit(palindrome, position, stack);
    bool odd = false;
    bool further_iteration = false;

    if (position < palindrome.length()) {
        std::list<char> new_stack = stack;
        new_stack.push_front(palindrome[position]);

        odd = q1_validate_and_commit(palindrome, position + 1, stack);
        further_iteration = q0_iterate(palindrome, position + 1, new_stack);
    }
    return straight || odd || further_iteration;
}

// true = input is palindrome, else Error
int main() {
    std::string palindrome_from_user = user_input();
    if (q0_iterate(palindrome_from_user, 0, {'#'})) {
        std::cout << "Success" << std::endl;
    }
    else {
        std::cout << "Error" << std::endl;
    }
}
