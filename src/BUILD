

config_setting(
    name = "no_mediapipe_true",
    define_values = { "no_mediapipe": "True" }
)

cc_library(
    name = "opencamocap_common",
    srcs = glob([
        "common/*.cpp",
    ], exclude = ["main.cpp"]),
    hdrs = glob([
        "common/*.hpp",
    ]),
    includes = ["."],
    deps =  [
                "//third_party:opencv",
            ],
    visibility = ["//visibility:public"],
)

cc_library(
    name = "opencamocap_mediapipeface",
    srcs = ["processor/CMediaPipeFace.cpp"],
    hdrs = ["processor/CMediaPipeFace.hpp"],
    deps =  [    
                ":opencamocap_common",
                "//third_party:opencv",
                "//graphs:face_renderer",
                "@com_google_mediapipe//mediapipe/graphs/face_mesh:desktop_live_calculators",
                "@com_google_mediapipe//mediapipe/framework:calculator_framework",
                "@com_google_mediapipe//mediapipe/framework/port:parse_text_proto"
            ],
)

cc_binary(
    name = "main",
    srcs = ["main.cpp"],
    deps = [
        ":opencamocap_common",
        ":opencamocap_mediapipeface",
        "@com_google_absl//absl/flags:flag",
        "@com_google_absl//absl/flags:parse",
        ],
    visibility = ["//visibility:public"],
)