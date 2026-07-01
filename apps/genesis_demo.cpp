#include <iostream>

#include <genesis/text/Tokenizer.hpp>
#include <genesis/text/Vocabulary.hpp>

int main() {
    genesis::text::Tokenizer tokenizer{
        genesis::text::TokenizerConfig{
            .lowercase = true
        }
    };

    auto tokens = tokenizer.tokenize("Hello World Hello");

    genesis::text::Vocabulary vocabulary;

    vocabulary.learn(tokens);

    auto ids = vocabulary.encode(tokens);

    std::cout << "Tokens\n";

    for (const auto &token: tokens)
        std::cout << token << '\n';

    std::cout << "\nIds\n";

    for (auto id: ids)
        std::cout << id << '\n';
}
