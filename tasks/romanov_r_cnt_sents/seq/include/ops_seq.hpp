#pragma once

#include "romanov_r_cnt_sents/common/include/common.hpp"
#include "task/include/task.hpp"

namespace romanov_r_cnt_sents {

class RomanovRCntSentsSEQ : public BaseTask {
 public:
  static constexpr ppc::task::TypeOfTask GetStaticTypeOfTask() {
    return ppc::task::TypeOfTask::kSEQ;
  }
  explicit RomanovRCntSentsSEQ(const InType &in);

 private:
  bool ValidationImpl() override;
  bool PreProcessingImpl() override;
  bool RunImpl() override;
  bool PostProcessingImpl() override;
};

}  // namespace romanov_r_cnt_sents
