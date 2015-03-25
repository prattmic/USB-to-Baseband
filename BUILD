package(default_visibility = ["//visibility:public"])
#
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
    name = "USB-to-Baseband",
    srcs = [
        "main.c",
        "cdcacm.c",
        "dac.c",
        "ring.c",
        "include/cdcacm.h",
        "include/dac.h",
        "include/ring.h",
    ],
    includes = [
        "./include/",
        "./libopencm3/include/",
    ],
    defines = ["STM32F4"],
    copts = [
        "-mfloat-abi=hard",
        "-mfpu=fpv4-sp-d16",
        "-mthumb",
        "-mcpu=cortex-m4",
    ],
    nocopts = "-fPIC",
    linkopts = [
        "-nostartfiles",
        "-static",
        "-mfloat-abi=hard",
        "-mfpu=fpv4-sp-d16",
        "-mthumb",
        "-mcpu=cortex-m4",
        "-TUSB-to-Baseband/stm32f4-discovery.ld", # FIXME
        "-LUSB-to-Baseband/libopencm3/lib", # FIXME
        "-Wl,-Map=/home/prattmic/prog/cubequest/bazel_workspace/USB-to-Baseband/main.map", # FIXME
        "-Wl,--gc-sections",
        "-lopencm3_stm32f4",
        "-Wl,--start-group -lc -lgcc -lnosys -Wl,--end-group",
    ],
    deps = ["//USB-to-Baseband:baseband"]
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

filegroup(
    name = "empty",
    srcs = [],
)

filegroup(
    name = "toolchain",
    srcs = [
        ":cc-compiler-armv7m",
    ],
)

cc_toolchain(
    name = "cc-compiler-armv7m",
    all_files = ":empty",
    compiler_files = ":empty",
    cpu = "armv7m",
    dwp_files = ":empty",
    dynamic_runtime_libs = [":empty"],
    linker_files = ":empty",
    objcopy_files = ":empty",
    static_runtime_libs = [":empty"],
    strip_files = ":empty",
    supports_param_files = 0,
)

cc_toolchain(
    name = "cc-compiler-local",
    all_files = ":empty",
    compiler_files = ":empty",
    cpu = "local",
    dwp_files = ":empty",
    dynamic_runtime_libs = [":empty"],
    linker_files = ":empty",
    objcopy_files = ":empty",
    static_runtime_libs = [":empty"],
    strip_files = ":empty",
    supports_param_files = 0,
)
