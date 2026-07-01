//
// Created by Akif AYDIN on 28.06.2026.
//

#pragma once

#include <string>

#include <vector>

#include <genesis/text/TokenizerConfig.hpp>

namespace genesis::text {
    class Tokenizer {
    public:
        explicit Tokenizer(TokenizerConfig config = {});

        [[nodiscard]] std::vector<std::string> tokenize(const std::string &text) const;

    private:
        TokenizerConfig config_;
    };
}
