licenses(["notice"])  # Apache 2

load(
    "//bazel:envoy_build_system.bzl",
    "envoy_cc_fuzz_test",
    "envoy_cc_test",
    "envoy_cc_test_binary",
    "envoy_cc_test_library",
    "envoy_package",
    "envoy_proto_library",
    "envoy_select_quiche",
)

envoy_package()

envoy_cc_test(
    name = "http2_platform_test",
    srcs = ["http2_platform_test.cc"],
    external_deps = ["quiche_http2_platform"],
    deps = [
        "//source/extensions/quic_listeners/quiche/platform:flags_impl_lib",
        "//test/test_common:logging_lib",
        "//test/test_common:utility_lib",
        "@com_googlesource_quiche//:http2_platform_reconstruct_object",
        "@com_googlesource_quiche//:http2_test_tools_random",
    ],
)

envoy_cc_test(
    name = "quic_platform_test",
    srcs = ["quic_platform_test.cc"],
    copts = ["-Wno-unused-parameter"],
    data = [
        "//test/extensions/transport_sockets/tls/test_data:certs",
    ],
    external_deps = ["quiche_quic_platform"],
    deps = [
        ":quic_platform_epoll_clock_lib",
        "//source/common/memory:stats_lib",
        "//source/extensions/quic_listeners/quiche/platform:flags_impl_lib",
        "//test/common/stats:stat_test_utility_lib",
        "//test/extensions/transport_sockets/tls:ssl_test_utils",
        "//test/mocks/api:api_mocks",
        "//test/test_common:logging_lib",
        "//test/test_common:threadsafe_singleton_injector_lib",
        "//test/test_common:utility_lib",
        "@com_googlesource_quiche//:epoll_server_lib",
        "@com_googlesource_quiche//:quic_platform_expect_bug",
        "@com_googlesource_quiche//:quic_platform_mock_log",
        "@com_googlesource_quiche//:quic_platform_port_utils",
        "@com_googlesource_quiche//:quic_platform_sleep",
        "@com_googlesource_quiche//:quic_platform_system_event_loop",
        "@com_googlesource_quiche//:quic_platform_test_output",
        "@com_googlesource_quiche//:quic_platform_thread",
    ],
)

envoy_cc_test(
    name = "spdy_platform_test",
    srcs = ["spdy_platform_test.cc"],
    external_deps = ["quiche_spdy_platform"],
    deps = [
        "//source/extensions/quic_listeners/quiche/platform:flags_impl_lib",
        "//test/test_common:logging_lib",
        "//test/test_common:utility_lib",
        "@com_googlesource_quiche//:spdy_platform_test_helpers",
    ],
)

envoy_cc_test_library(
    name = "epoll_server_platform_impl_lib",
    hdrs = [
        "epoll_address_test_utils_impl.h",
        "epoll_bug_impl.h",
        "epoll_expect_bug_impl.h",
        "epoll_export_impl.h",
        "epoll_logging_impl.h",
        "epoll_ptr_util_impl.h",
        "epoll_test_impl.h",
        "epoll_thread_impl.h",
        "epoll_time_impl.h",
    ],
    external_deps = ["abseil_time"],
    deps = [
        ":quic_platform_expect_bug_impl_lib",
        ":quic_platform_thread_impl_lib",
        "//include/envoy/network:address_interface",
        "//source/extensions/quic_listeners/quiche/platform:quic_platform_base_impl_lib",
        "//test/test_common:environment_lib",
    ],
)

envoy_cc_test_library(
    name = "http2_platform_reconstruct_object_impl_lib",
    hdrs = ["http2_reconstruct_object_impl.h"],
)

envoy_cc_test_library(
    name = "quic_platform_epoll_clock_lib",
    srcs = ["quic_epoll_clock.cc"],
    hdrs = ["quic_epoll_clock.h"],
    deps = [
        "@com_googlesource_quiche//:quic_platform",
        "@com_googlesource_quiche//:quic_platform_epoll_lib",
    ],
)

envoy_cc_test_library(
    name = "quic_platform_epoll_impl_lib",
    hdrs = ["quic_epoll_impl.h"],
    deps = ["@com_googlesource_quiche//:epoll_server_lib"],
)

envoy_cc_test_library(
    name = "quic_platform_expect_bug_impl_lib",
    hdrs = ["quic_expect_bug_impl.h"],
    deps = [
        "@com_googlesource_quiche//:quic_platform_base",
        "@com_googlesource_quiche//:quic_platform_mock_log",
    ],
)

envoy_cc_test_library(
    name = "quic_platform_mock_log_impl_lib",
    hdrs = ["quic_mock_log_impl.h"],
    deps = ["@com_googlesource_quiche//:quic_platform_base"],
)

envoy_cc_test_library(
    name = "quic_platform_port_utils_impl_lib",
    srcs = ["quic_port_utils_impl.cc"],
    hdrs = ["quic_port_utils_impl.h"],
    deps = [
        "//source/common/network:utility_lib",
        "//test/test_common:environment_lib",
    ],
)

envoy_cc_test_library(
    name = "quic_platform_sleep_impl_lib",
    hdrs = ["quic_sleep_impl.h"],
    deps = ["@com_googlesource_quiche//:quic_core_time_lib"],
)

envoy_cc_test_library(
    name = "quic_platform_system_event_loop_impl_lib",
    hdrs = ["quic_system_event_loop_impl.h"],
)

envoy_cc_test_library(
    name = "quic_platform_thread_impl_lib",
    hdrs = ["quic_thread_impl.h"],
    deps = [
        "//include/envoy/thread:thread_interface",
        "//source/common/common:assert_lib",
        "//test/test_common:thread_factory_for_test_lib",
    ],
)

envoy_cc_test_library(
    name = "quic_platform_test_impl_lib",
    hdrs = ["quic_test_impl.h"],
    deps = ["//source/common/common:assert_lib"],
)

envoy_cc_test_library(
    name = "quic_platform_test_output_impl_lib",
    srcs = ["quic_test_output_impl.cc"],
    hdrs = ["quic_test_output_impl.h"],
    deps = [
        "//source/common/filesystem:filesystem_lib",
        "@com_googlesource_quiche//:quic_platform_base",
    ],
)

envoy_cc_test_library(
    name = "spdy_platform_test_helpers_impl_lib",
    hdrs = ["spdy_test_helpers_impl.h"],
    deps = [
        ":quic_platform_expect_bug_impl_lib",
    ],
)
