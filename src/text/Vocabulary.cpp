#include <genesis/text/Vocabulary.hpp>

#include <stdexcept>

namespace genesis::text {
    void Vocabulary::learn(const std::vector<std::string> &tokens) {
        for (const auto &token: tokens) {
            if (token_to_id_.contains(token)) {
                continue;
            }

            const TokenId id = id_to_token_.size();

            token_to_id_[token] = id;
            id_to_token_.push_back(token);
        }
    }

    std::optional<Vocabulary::TokenId> Vocabulary::id_of(const std::string &token) const {
        const auto iterator = token_to_id_.find(token);

        if (iterator == token_to_id_.end()) {
            return std::nullopt;
        }

        return iterator->second;
    }

    std::optional<std::string> Vocabulary::token_of(TokenId id) const {
        if (id >= id_to_token_.size()) {
            return std::nullopt;
        }

        return id_to_token_[id];
    }

    std::vector<Vocabulary::TokenId> Vocabulary::encode(const std::vector<std::string> &tokens) const {
        std::vector<TokenId> ids;
        ids.reserve(tokens.size());

        for (const auto &token: tokens) {
            const auto id = id_of(token);

            if (!id.has_value()) {
                throw std::runtime_error{"Unknown token: " + token};
            }

            ids.push_back(id.value());
        }

        return ids;
    }

    std::vector<std::string> Vocabulary::decode(const std::vector<TokenId> &ids) const {
        std::vector<std::string> tokens;
        tokens.reserve(ids.size());

        for (const auto id: ids) {
            const auto token = token_of(id);

            if (!token.has_value()) {
                throw std::runtime_error{"Unknown token id"};
            }

            tokens.push_back(token.value());
        }

        return tokens;
    }

    std::size_t Vocabulary::size() const {
        return id_to_token_.size();
    }
}
