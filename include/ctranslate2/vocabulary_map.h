#pragma once

#include <set>
#include <unordered_map>
#include <string>
#include <vector>

#include "vocabulary.h"

namespace ctranslate2 {

  // This class loads a vocabulary mapping model, a text file associating n-grams
  // with list of possible target candidates:
  //
  //    <n-gram> \t candidate1 candidate2 ... candidateN
  //
  // and provides methods to map input tokens to possible target tokens.
  class VocabularyMap {
  public:
    VocabularyMap(const std::string& map_path, const Vocabulary& vocabulary);

    bool empty() const;

    std::vector<size_t>
    get_candidates(const std::vector<std::vector<std::string>>& batch_tokens,
                   const size_t multiple_of = 16) const;

  private:
    const size_t _vocabulary_size;
    std::set<size_t> _fixed_candidates;
    std::vector<std::unordered_map<std::string, std::vector<size_t>>> _map_rules;
  };

}
