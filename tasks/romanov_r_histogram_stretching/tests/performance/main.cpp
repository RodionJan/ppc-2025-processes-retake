#include <gtest/gtest.h>

#include <algorithm>
#include <cstddef>
#include <random>
#include <vector>

#include "romanov_r_histogram_stretching/common/include/common.hpp"
#include "romanov_r_histogram_stretching/mpi/include/ops_mpi.hpp"
#include "romanov_r_histogram_stretching/seq/include/ops_seq.hpp"
#include "util/include/perf_test_util.hpp"

namespace romanov_r_histogram_stretching {

class RomanovRHistogramStretchingPerfTests : public ppc::util::BaseRunPerfTests<InType, OutType> {
 public:
  static constexpr size_t kSize = 10000000;

 protected:
  void SetUp() override {
    input_data_.resize(kSize);

    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<int> dist(50, 200);
    for (size_t i = 0; i < kSize; ++i) {
      input_data_[i] = dist(gen);
    }

    input_data_[0] = 0;
    input_data_[kSize - 1] = 255;
  }

  bool CheckTestOutputData(OutType &output_data) final {
    if (output_data.empty()) {
      return true;
    }

    if (output_data.size() != kSize) {
      return false;
    }

    return std::ranges::all_of(output_data, [](int val) { return val >= 0 && val <= 255; });
  }

  InType GetTestInputData() final {
    return input_data_;
  }

 private:
  std::vector<int> input_data_;
};

TEST_P(RomanovRHistogramStretchingPerfTests, RunPerfModes) {
  ExecuteTest(GetParam());
}

const auto kAllPerfTasks = ppc::util::MakeAllPerfTasks<InType, RomanovRHistogramStretchingMPI,
                                                       RomanovRHistogramStretchingSEQ>(
    PPC_SETTINGS_romanov_r_histogram_stretching);

const auto kGtestValues = ppc::util::TupleToGTestValues(kAllPerfTasks);
const auto kPerfTestName = RomanovRHistogramStretchingPerfTests::CustomPerfTestName;

INSTANTIATE_TEST_SUITE_P(PerfTests, RomanovRHistogramStretchingPerfTests, kGtestValues, kPerfTestName);

}  // namespace romanov_r_histogram_stretching