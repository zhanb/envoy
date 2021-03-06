licenses(["notice"])  # Apache 2

load(
    "//bazel:envoy_build_system.bzl",
    "envoy_cc_test",
    "envoy_cc_test_binary",
    "envoy_cc_test_library",
    "envoy_package",
)

envoy_package()

envoy_cc_test(
    name = "heap_stat_data_test",
    srcs = ["heap_stat_data_test.cc"],
    deps = [
        "//source/common/stats:fake_symbol_table_lib",
        "//source/common/stats:heap_stat_data_lib",
        "//test/test_common:logging_lib",
    ],
)

envoy_cc_test(
    name = "isolated_store_impl_test",
    srcs = ["isolated_store_impl_test.cc"],
    deps = [
        "//source/common/stats:isolated_store_lib",
    ],
)

envoy_cc_test(
    name = "metric_impl_test",
    srcs = ["metric_impl_test.cc"],
    deps = [
        "//source/common/stats:fake_symbol_table_lib",
        "//source/common/stats:heap_stat_data_lib",
        "//test/test_common:logging_lib",
    ],
)

envoy_cc_test(
    name = "source_impl_test",
    srcs = ["source_impl_test.cc"],
    deps = [
        "//source/common/stats:source_impl_lib",
        "//test/mocks/stats:stats_mocks",
    ],
)

envoy_cc_test(
    name = "stat_merger_test",
    srcs = ["stat_merger_test.cc"],
    deps = [
        "//source/common/stats:isolated_store_lib",
        "//source/common/stats:stat_merger_lib",
    ],
)

envoy_cc_test_library(
    name = "stat_test_utility_lib",
    srcs = ["stat_test_utility.cc"],
    hdrs = ["stat_test_utility.h"],
    external_deps = [
        "abseil_strings",
    ],
    deps = ["//source/common/memory:stats_lib"],
)

envoy_cc_test(
    name = "stats_matcher_impl_test",
    srcs = ["stats_matcher_impl_test.cc"],
    deps = [
        "//source/common/stats:stats_matcher_lib",
        "//test/test_common:utility_lib",
    ],
)

envoy_cc_test(
    name = "symbol_table_impl_test",
    srcs = ["symbol_table_impl_test.cc"],
    deps = [
        ":stat_test_utility_lib",
        "//source/common/common:mutex_tracer_lib",
        "//source/common/memory:stats_lib",
        "//source/common/stats:fake_symbol_table_lib",
        "//source/common/stats:symbol_table_lib",
        "//test/mocks/stats:stats_mocks",
        "//test/test_common:logging_lib",
        "//test/test_common:utility_lib",
    ],
)

envoy_cc_test_binary(
    name = "symbol_table_speed_test",
    srcs = ["symbol_table_speed_test.cc"],
    external_deps = [
        "abseil_strings",
        "benchmark",
    ],
    deps = [
        ":stat_test_utility_lib",
        "//source/common/memory:stats_lib",
        "//source/common/stats:symbol_table_lib",
        "//test/mocks/stats:stats_mocks",
        "//test/test_common:logging_lib",
        "//test/test_common:utility_lib",
    ],
)

envoy_cc_test(
    name = "tag_extractor_impl_test",
    srcs = ["tag_extractor_impl_test.cc"],
    deps = [
        "//source/common/stats:tag_extractor_lib",
        "//source/common/stats:tag_producer_lib",
        "//test/test_common:utility_lib",
    ],
)

envoy_cc_test(
    name = "tag_producer_impl_test",
    srcs = ["tag_producer_impl_test.cc"],
    deps = [
        "//source/common/stats:tag_producer_lib",
        "//test/test_common:utility_lib",
    ],
)

envoy_cc_test(
    name = "thread_local_store_test",
    srcs = ["thread_local_store_test.cc"],
    deps = [
        ":stat_test_utility_lib",
        "//source/common/memory:stats_lib",
        "//source/common/stats:stats_matcher_lib",
        "//source/common/stats:symbol_table_lib",
        "//source/common/stats:thread_local_store_lib",
        "//test/mocks/event:event_mocks",
        "//test/mocks/server:server_mocks",
        "//test/mocks/stats:stats_mocks",
        "//test/mocks/thread_local:thread_local_mocks",
        "//test/test_common:logging_lib",
        "//test/test_common:utility_lib",
        "@envoy_api//envoy/config/metrics/v2:stats_cc",
    ],
)

envoy_cc_test_binary(
    name = "thread_local_store_speed_test",
    srcs = ["thread_local_store_speed_test.cc"],
    external_deps = [
        "abseil_strings",
        "benchmark",
    ],
    deps = [
        ":stat_test_utility_lib",
        "//source/common/common:thread_lib",
        "//source/common/event:dispatcher_lib",
        "//source/common/stats:thread_local_store_lib",
        "//source/common/thread_local:thread_local_lib",
        "//test/test_common:simulated_time_system_lib",
        "//test/test_common:test_time_lib",
        "//test/test_common:utility_lib",
    ],
)
