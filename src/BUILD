
load("@bazel_skylib//rules:common_settings.bzl", "bool_flag")


config_setting(
    name = "no_mediapipe_true",
    define_values = { "no_mediapipe": "True" }
)

cc_library(
    name = "main",
    srcs = ["main.cpp"],
    deps = select({
            ":no_mediapipe_true": [],
            "//conditions:default": [
                "//third_party:opencv",
                "@com_github_glog_glog//:glog",
                "@com_google_mediapipe//mediapipe/calculators/core:pass_through_calculator",
                "@com_google_mediapipe//mediapipe/framework/port:logging",
                "@com_google_mediapipe//mediapipe/framework/port:parse_text_proto",
                "@com_google_mediapipe//mediapipe/framework/port:status",
            ],
        }),
)