//
// Created by Akif AYDIN on 28.06.2026.
//

#include <genesis/text/Tokenizer.hpp>

#include <cctype>

namespace genesis::text {
    namespace {
        char to_lower_ascii(const char character) {
            return static_cast<char>(
                std::tolower(static_cast<unsigned char>(character))
            );
        }

        std::string to_lower_ascii(std::string text) {
            for (char &character: text) {
                character = to_lower_ascii(character);
            }

            return text;
        }
    }

    Tokenizer::Tokenizer(const TokenizerConfig config)
        : config_{config} {
    }

    std::vector<std::string> Tokenizer::tokenize(const std::string &text) const {
        std::vector<std::string> tokens;
        std::string token;

        const auto flush_token = [&]() {
            if (token.empty()) {
                return;
            }

            if (config_.lowercase) {
                token = to_lower_ascii(token);
            }

            tokens.push_back(token);
            token.clear();
        };

        for (const char character: text) {
            const auto unsigned_character = static_cast<unsigned char>(character);

            if (std::isspace(unsigned_character)) {
                flush_token();
                continue;
            }

            if (config_.split_punctuation && std::ispunct(unsigned_character)) {
                flush_token();
                tokens.emplace_back(1, character);
                continue;
            }

            token.push_back(character);
        }

        flush_token();

        return tokens;
    }
}
