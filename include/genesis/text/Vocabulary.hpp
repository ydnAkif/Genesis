#pragma once

#include <cstddef>
#include <optional>
#include <string>
#include <unordered_map>
#include <vector>

namespace genesis::text {
    class Vocabulary {
    public:
        using TokenId = std::size_t;

        void learn(const std::vector<std::string> &tokens);

        [[nodiscard]] std::optional<TokenId> id_of(const std::string &token) const;

        [[nodiscard]] std::optional<std::string> token_of(TokenId id) const;

        [[nodiscard]] std::vector<TokenId> encode(const std::vector<std::string> &tokens) const;

        [[nodiscard]] std::vector<std::string> decode(const std::vector<TokenId> &ids) const;

        [[nodiscard]] std::size_t size() const;

    private:
        std::unordered_map<std::string, TokenId> token_to_id_;
        std::vector<std::string> id_to_token_;
    };
}
