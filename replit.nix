{ pkgs }: {
    deps = [
      pkgs.ninja
      pkgs.cmake
      pkgs.llvmPackages_13.clang-unwrapped
      pkgs.cowsay
    ];
}