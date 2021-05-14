load(
    "@com_google_mediapipe//mediapipe/framework/tool:mediapipe_graph.bzl",
    "mediapipe_simple_subgraph",
)

package(default_visibility = ["//visibility:public"])

mediapipe_simple_subgraph(
    name = "face_renderer",
    graph = "face_renderer.pbtxt",
    register_as = "FaceRendererGpuCustom",
    deps = [
        "@com_google_mediapipe//mediapipe/graphs/face_mesh/subgraphs:renderer_calculators",
    ],
)
