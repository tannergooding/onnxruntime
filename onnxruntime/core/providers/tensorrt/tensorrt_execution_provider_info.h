// Copyright (c) Microsoft Corporation. All rights reserved.
// Licensed under the MIT License.

#pragma once

#include <limits>

#include "core/framework/ortdevice.h"
#include "core/framework/provider_options.h"
#include "core/session/onnxruntime_c_api.h"

namespace onnxruntime {
// Information needed to construct trt execution providers.
struct TensorrtExecutionProviderInfo {
  int device_id{0};
  bool has_user_compute_stream{false};
  void* user_compute_stream{nullptr};
  bool has_trt_options{false};
  int max_partition_iterations{1000};
  int min_subgraph_size{1};
  size_t max_workspace_size{1 << 30};
  bool fp16_enable{false};
  bool int8_enable{false};
  std::string int8_calibration_table_name{""};
  bool int8_use_native_calibration_table{false};
  bool dla_enable{false};
  int dla_core{0};
  bool dump_subgraphs{false};
  bool engine_cache_enable{false};
  std::string engine_cache_path{""};
  bool engine_decryption_enable{false};
  std::string engine_decryption_lib_path{""};
  bool force_sequential_engine_build{false};
  bool context_memory_sharing_enable{false};
  bool layer_norm_fp32_fallback{false};
  bool timing_cache_enable{false};
  bool force_timing_cache{false};
  bool detailed_build_log{false};
  bool build_heuristics_enable{false};
  bool sparsity_enable{false};
  int builder_optimization_level{2};
  int auxiliary_streams{-1};
  std::string tactic_sources{""};

  static TensorrtExecutionProviderInfo FromProviderOptions(const ProviderOptions& options);
  static ProviderOptions ToProviderOptions(const TensorrtExecutionProviderInfo& info);
  static ProviderOptions ToProviderOptions(const OrtTensorRTProviderOptionsV2& info);
};
}  // namespace onnxruntime
