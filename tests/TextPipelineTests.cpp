#include <genesis/text/Tokenizer.hpp>
#include <genesis/text/Vocabulary.hpp>

#include <iostream>
#include <string>
#include <vector>

namespace {
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
    const genesis::text::Tokenizer tokenizer{
        genesis::text::TokenizerConfig{
            .lowercase = true
        }
    };

    const auto tokens = tokenizer.tokenize("Hello world HELLO");

    expect_equal(
        tokens,
        std::vector<std::string>{"hello", "world", "hello"},
        "tokenizer produces lowercase tokens"
    );

    genesis::text::Vocabulary vocabulary;
    vocabulary.learn(tokens);

    const auto ids = vocabulary.encode(tokens);

    expect_equal(
        ids,
        std::vector<genesis::text::Vocabulary::TokenId>{0, 1, 0},
        "vocabulary encodes tokenized text"
    );

    const auto decoded = vocabulary.decode(ids);

    expect_equal(
        decoded,
        tokens,
        "vocabulary decodes ids back to tokens"
    );

    return 0;
}
