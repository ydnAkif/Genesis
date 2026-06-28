#include <genesis/text/Tokenizer.hpp>

#include <sstream>

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

        std::istringstream stream{text};
        std::string token;

        while (stream >> token) {
            if (config_.lowercase) {
                token = to_lower_ascii(token);
            }

            tokens.push_back(token);
        }

        return tokens;
    }
}
