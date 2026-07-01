#include <genesis/text/Vocabulary.hpp>

#include <cstdlib>
#include <iostream>
#include <string>
#include <vector>

namespace {
    void expect_true(bool condition, const std::string &test_name) {
        if (!condition) {
            std::cerr << "[FAILED] " << test_name << '\n';
            std::exit(1);
        }

        std::cout << "[PASSED] " << test_name << '\n';
    }

    template<typename T>
    void expect_equal(const T &actual, const T &expected, const std::string &test_name) {
        if (actual != expected) {
            std::cerr << "[FAILED] " << test_name << '\n';
            std::exit(1);
        }

        std::cout << "[PASSED] " << test_name << '\n';
    }
}

int main() {
    genesis::text::Vocabulary vocabulary;

    const std::vector<std::string> tokens{
        "hello",
        "world",
        "hello"
    };

    vocabulary.learn(tokens);

    expect_equal(
        vocabulary.size(),
        static_cast<std::size_t>(2),
        "learn unique tokens"
    );

    expect_true(
        vocabulary.id_of("hello").has_value(),
        "known token has id"
    );

    expect_true(
        !vocabulary.id_of("unknown").has_value(),
        "unknown token has no id"
    );

    const auto encoded = vocabulary.encode(tokens);

    expect_equal(
        encoded,
        std::vector<genesis::text::Vocabulary::TokenId>{0, 1, 0},
        "encode tokens"
    );

    const auto decoded = vocabulary.decode(encoded);

    expect_equal(
        decoded,
        tokens,
        "decode token ids"
    );

    return 0;
}
