# There must be a better way to do this
cc_library(
    name = "util",
    hdrs = [
        "include/container.h",
        "include/types.h",
    ],
    includes = ["./include/"],
)

cc_library(
    name = "convolution",
    srcs = ["convolution.c"],
    hdrs = ["include/convolution.h"],
    includes = ["./include/"],
)

cc_library(
    name = "baseband",
    srcs = [
        "sample.c",
        "symbol.c",
    ],
    hdrs = [
        "include/iq.h",
        "include/sample.h",
        "include/symbol.h",
    ],
    includes = ["./include/"],
    deps = [
        "//USB-to-Baseband:convolution",
        "//USB-to-Baseband:util",
    ]
)

cc_binary(
    name = "convolutiontest",
    srcs = ["hosttest/convolutiontest.c"],
    deps = ["//USB-to-Baseband:convolution"]
)

cc_binary(
    name = "streamtest",
    srcs = ["hosttest/streamtest.c"],
    deps = ["//USB-to-Baseband:baseband"]
)
