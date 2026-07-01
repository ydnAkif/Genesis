#include <genesis/text/Tokenizer.hpp>

#include <iostream>
#include <vector>
#include <string>

namespace {
    void expect_equal(
        const std::vector<std::string> &actual,
        const std::vector<std::string> &expected,
        const std::string &test_name
    ) {
        if (actual != expected) {
            std::cerr << "[FAILED] " << test_name << '\n';

            std::cerr << "Expected: ";
            for (const auto &token: expected) {
                std::cerr << token << ' ';
            }

            std::cerr << "\nActual: ";
            for (const auto &token: actual) {
                std::cerr << token << ' ';
            }

            std::cerr << '\n';

            std::exit(1);
        }

        std::cout << "[PASSED] " << test_name << '\n';
    }
}

int main() {
    genesis::text::Tokenizer tokenizer;

    expect_equal(
        tokenizer.tokenize("hello world"),
        {"hello", "world"},
        "tokenize simple sentence"
    );

    expect_equal(
        tokenizer.tokenize("hello   world"),
        {"hello", "world"},
        "ignore multiple spaces"
    );

    expect_equal(
        tokenizer.tokenize(""),
        {},
        "empty string returns empty token list"
    );

    const genesis::text::Tokenizer lowercase_tokenizer{
        genesis::text::TokenizerConfig{
            .lowercase = true
        }
    };

    expect_equal(
        lowercase_tokenizer.tokenize("HELLO Genesis"),
        {"hello", "genesis"},
        "lowercase ascii tokens"
    );

    return 0;
}
