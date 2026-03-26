#pragma once

#include "romanov_r_histogram_stretching/common/include/common.hpp"
#include "task/include/task.hpp"

namespace romanov_r_histogram_stretching {

class RomanovRHistogramStretchingMPI : public BaseTask {
 public:
  static constexpr ppc::task::TypeOfTask GetStaticTypeOfTask() {
    return ppc::task::TypeOfTask::kMPI;
  }
  explicit RomanovRHistogramStretchingMPI(const InType &in);

 private:
  bool ValidationImpl() override;
  bool PreProcessingImpl() override;
  bool RunImpl() override;
  bool PostProcessingImpl() override;
};

}  // namespace romanov_r_histogram_stretching