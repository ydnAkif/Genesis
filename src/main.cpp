//
// Created by Akif AYDIN on 28.06.2026.
//

#include <iostream>
#include <genesis/core/Version.hpp>
#include <genesis/text/Tokenizer.hpp>

int main() {
    std::cout << "Genesis "
            << genesis::core::version_major << "."
            << genesis::core::version_minor << "."
            << genesis::core::version_patch
            << '\n';

    const genesis::text::Tokenizer tokenizer{
        genesis::text::TokenizerConfig{
            .lowercase = true
        }
    };


    for (const auto tokens = tokenizer.tokenize("HELLO world FROM Genesis"); const auto &token: tokens) {
        std::cout << token << '\n';
    }
    return 0;
}
