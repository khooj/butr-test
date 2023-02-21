{
  description = "rust workspace";

  inputs = {
    nixpkgs.url = "github:nixos/nixpkgs/nixpkgs-unstable";
    flake-utils.url = "github:numtide/flake-utils";
    rust-overlay.url = "github:oxalica/rust-overlay";
  };

  outputs = { self, nixpkgs, rust-overlay, flake-utils, ... }:
    let
      myapp = "poe-system";
      rust-version = "1.62.0";
    in
    flake-utils.lib.eachDefaultSystem (system:
      let
        overlays = [ rust-overlay.overlays.default ];
        pkgs = import nixpkgs { inherit system overlays; };
        #pkgsMingw = import pkgs.path { crossSystem = { config = "x86_64-w64-mingw32"; }; };
        lib = pkgs.lib;

        buildInputs = with pkgs; [
          (rust-bin.stable.${rust-version}.default.override {
            extensions =
              [ "rust-src" "llvm-tools-preview" "rust-analysis" ];
            targets = [ "x86_64-pc-windows-gnu" ];
          })
          rust-analyzer
          trunk

          sccache
          sqlite
          postgresql
          mysql
          openssl
          cmake
          zlib
          gnumake
          python3
          jq
          nixos-shell
          git
          crate2nix
          vscodium
          nixpkgs-fmt
          llvmPackages.clang
          pkgsCross.mingwW64.stdenv.cc
          cmake
          nodejs-16_x
          printelf
        ];
        nativeBuildInputs = with pkgs; [
          pkg-config
          dbus
        ];

      in
      rec {
        packages = {};
        devShell = with pkgs;
          mkShell {
            name = "rust";
            inherit nativeBuildInputs buildInputs;
            RUSTFLAGS = (builtins.map (a: ''-L ${a}/lib'') [
              pkgsCross.mingwW64.windows.mingw_w64_pthreads
              pkgsCross.mingwW64.windows.mingw_w64_headers
              # myOpencv
            ]);
            CARGO_TARGET_X86_64_PC_WINDOWS_GNU_RUNNER = "${pkgs.wineWowPackages.stable}/bin/wine64";
            CARGO_BUILD_TARGET = "x86_64-pc-windows-gnu";
            # OPENCV_INCLUDE_PATHS = "${pkgs.pkgsCross.mingwW64.opencv4}/include/opencv4";
            # OPENCV_LINK_PATHS = "${pkgs.pkgsCross.mingwW64.opencv4}/lib";
            # OPENCV_LINK_LIBS = "opencv_imgproc460";
            # OPENCV_DISABLE_PROBES = "pkg_config,vcpkg_cmake,vcpkg";
            #OpenCV_DIR = "${pkgs.pkgsCross.mingwW64.opencv4}/lib/cmake";

            shellHook = ''
              #export PATH=$PATH:$HOME/.cargo/bin
              export LIBCLANG_PATH="${llvmPackages.libclang.lib}/lib"
            '';
          };
      });
}
