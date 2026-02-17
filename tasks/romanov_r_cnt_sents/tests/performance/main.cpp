#include <gtest/gtest.h>

#include "romanov_r_cnt_sents/common/include/common.hpp"
#include "romanov_r_cnt_sents/mpi/include/ops_mpi.hpp"
#include "romanov_r_cnt_sents/seq/include/ops_seq.hpp"
#include "util/include/perf_test_util.hpp"

namespace romanov_r_cnt_sents {

class RomanovRCntSentsPerfTests : public ppc::util::BaseRunPerfTests<InType, OutType> {
  const int kCount_ = 100;
  InType input_data_{};

  void SetUp() override {
    input_data_ = kCount_;
  }

  bool CheckTestOutputData(OutType &output_data) final {
    return input_data_ == output_data;
  }

  InType GetTestInputData() final {
    return input_data_;
  }
};

TEST_P(RomanovRCntSentsPerfTests, RunPerfModes) {
  ExecuteTest(GetParam());
}

namespace {

const auto kAllPerfTasks =
    ppc::util::MakeAllPerfTasks<InType, RomanovRCntSentsMPI, RomanovRCntSentsSEQ>(PPC_SETTINGS_romanov_r_cnt_sents);

const auto kGtestValues = ppc::util::TupleToGTestValues(kAllPerfTasks);

const auto kPerfTestName = RomanovRCntSentsPerfTests::CustomPerfTestName;

INSTANTIATE_TEST_SUITE_P(RunModeTests, RomanovRCntSentsPerfTests, kGtestValues, kPerfTestName);

}  // namespace

}  // namespace romanov_r_cnt_sents
