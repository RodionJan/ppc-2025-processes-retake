#pragma once

#include <tuple>
#include <vector>

#include "task/include/task.hpp"

namespace romanov_r_histogram_stretching {

using InType = std::vector<int>;
using OutType = std::vector<int>;
using TestType = std::tuple<int, InType, OutType>;
using BaseTask = ppc::task::Task<InType, OutType>;

}  // namespace romanov_r_histogram_stretching