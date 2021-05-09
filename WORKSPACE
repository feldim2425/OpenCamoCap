workspace(name = "opencamocap")


load("@bazel_tools//tools/build_defs/repo:http.bzl", "http_archive")
http_archive(
    name = "bazel_skylib",
    urls = [
        "https://github.com/bazelbuild/bazel-skylib/releases/download/1.0.3/bazel-skylib-1.0.3.tar.gz",
        "https://mirror.bazel.build/github.com/bazelbuild/bazel-skylib/releases/download/1.0.3/bazel-skylib-1.0.3.tar.gz",
    ],
    sha256 = "1c531376ac7e5a180e0237938a2536de0c54d93f5c278634818e0efc952dd56c",
)
load("@bazel_skylib//:workspace.bzl", "bazel_skylib_workspace")
bazel_skylib_workspace()

load("@bazel_skylib//lib:versions.bzl", "versions")
versions.check(minimum_bazel_version = "3.7.2")


http_archive(
    name = "rules_pkg",
    url = "https://github.com/bazelbuild/rules_pkg/releases/download/0.3.0/rules_pkg-0.3.0.tar.gz",
    sha256 = "6b5969a7acd7b60c02f816773b06fcf32fbe8ba0c7919ccdc2df4f8fb923804a",
)
http_archive(
   name = "rules_foreign_cc",
   strip_prefix = "rules_foreign_cc-0.2.0",
   sha256 = "e60cfd0a8426fa4f5fd2156e768493ca62b87d125cb35e94c44e79a3f0d8635f",
   url = "https://github.com/bazelbuild/rules_foreign_cc/archive/0.2.0.zip",
)

load("@rules_pkg//:deps.bzl", "rules_pkg_dependencies")
rules_pkg_dependencies()

load("@rules_foreign_cc//foreign_cc:repositories.bzl", "rules_foreign_cc_dependencies")

# This sets up some common toolchains for building targets. For more details, please see
# https://github.com/bazelbuild/rules_foreign_cc/tree/main/docs#rules_foreign_cc_dependencies
rules_foreign_cc_dependencies()



new_local_repository(
    name = "linux_opencv",
    build_file = "@//third_party:opencv_linux.BUILD",
    path = "/usr",
)

new_local_repository(
    name = "macos_opencv",
    build_file = "@//third_party:opencv_macos.BUILD",
    path = "/usr/local/opt/opencv@3",
)

new_local_repository(
    name = "windows_opencv",
    build_file = "@//third_party:opencv_windows.BUILD",
    path = "C:\\opencv\\build",
)




http_archive(
    name = "com_google_mediapipe",
    sha256 = "157d13882da323f5cf00cfabadf491bbb071d3ed62e328caec93e392f767df9f",
    strip_prefix = "mediapipe-0.8.3.2",
    urls = ["https://github.com/google/mediapipe/archive/0.8.3.2.tar.gz"],
)

# gflags needed by glog
http_archive(
    name = "com_github_gflags_gflags",
    strip_prefix = "gflags-2.2.2",
    sha256 = "19713a36c9f32b33df59d1c79b4958434cb005b5b47dc5400a7a4b078111d9b5",
    url = "https://github.com/gflags/gflags/archive/v2.2.2.zip",
)


# 2020-08-21
http_archive(
    name = "com_github_glog_glog",
    strip_prefix = "glog-0.4.0",
    #sha256 = "58c9b3b6aaa4dd8b836c0fd8f65d0f941441fb95e27212c5eeb9979cfd3592ab",
    urls = [
        "https://github.com/google/glog/archive/refs/tags/v0.4.0.tar.gz",
    ],
)

# Tensorflow repo should always go after the other external dependencies.
# 2021-03-25
_TENSORFLOW_GIT_COMMIT = "c67f68021824410ebe9f18513b8856ac1c6d4887"
_TENSORFLOW_SHA256= "fd07d0b39422dc435e268c5e53b2646a8b4b1e3151b87837b43f86068faae87f"
http_archive(
    name = "org_tensorflow",
    urls = [
      "https://github.com/tensorflow/tensorflow/archive/%s.tar.gz" % _TENSORFLOW_GIT_COMMIT,
    ],
    patches = [
        "@com_google_mediapipe//third_party:org_tensorflow_compatibility_fixes.diff",
        "@com_google_mediapipe//third_party:org_tensorflow_objc_cxx17.diff",
    ],
    patch_args = [
        "-p1",
    ],
    strip_prefix = "tensorflow-%s" % _TENSORFLOW_GIT_COMMIT,
    sha256 = _TENSORFLOW_SHA256,
)

load("@org_tensorflow//tensorflow:workspace3.bzl", "tf_workspace3")
tf_workspace3()
load("@org_tensorflow//tensorflow:workspace2.bzl", "tf_workspace2")
tf_workspace2()
