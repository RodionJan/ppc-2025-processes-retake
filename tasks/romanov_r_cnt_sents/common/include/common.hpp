#pragma once

#include <string>
#include <tuple>

#include "task/include/task.hpp"

namespace romanov_r_cnt_sents {

using InType = int;
using OutType = int;
using TestType = std::tuple<int, std::string>;
using BaseTask = ppc::task::Task<InType, OutType>;

}  // namespace romanov_r_cnt_sents
