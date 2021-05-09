load("@bazel_skylib//lib:selects.bzl", "selects")

selects.config_setting_group(
    name = "linux",
    match_any = [
        "@bazel_tools//src/conditions:linux_x86_64",
        "@bazel_tools//src/conditions:linux_s390x",
        "@bazel_tools//src/conditions:linux_ppc64le",
        "@bazel_tools//src/conditions:linux_ppc",
        "@bazel_tools//src/conditions:linux_aarch64",
    ],
    visibility = ["//visibility:public"],
)

alias(
    name = "opencv",
    actual = select({
        "@bazel_tools//src/conditions:darwin": "@macos_opencv//:opencv",
        "@bazel_tools//src/conditions:windows": "@windows_opencv//:opencv",
        ":linux": "@linux_opencv//:opencv",
        "//conditions:default": "@linux_opencv//:opencv",
    }),
    visibility = ["//visibility:public"],
)
