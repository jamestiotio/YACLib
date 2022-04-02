#pragma once

#include <yaclib/config.hpp>

#include <random>
#include <string>

namespace yaclib::detail {

class RandomDevice {
 public:
  using result_type = std::mt19937::result_type;

  static constexpr const result_type kMin = 0;
  static constexpr const result_type kMax = 0xFFFFFFFFU;
  static constexpr const result_type kEntropy = 0;

  RandomDevice();

  explicit RandomDevice(const std::string& /*token*/) : RandomDevice() {
  }

  result_type operator()() noexcept;

  [[nodiscard]] double entropy() const noexcept;

  static constexpr result_type min();

  static constexpr result_type max();

  ~RandomDevice() = default;

  void reset();

  RandomDevice(const RandomDevice&) = delete;

  RandomDevice& operator=(const RandomDevice&) = delete;

 private:
  static constexpr const unsigned kSeed = 1337;
  std::mt19937 _eng;
};

}  // namespace yaclib::detail
