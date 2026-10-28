#!/usr/bin/env bash
# SPDX-License-Identifier: GPL-3.0-or-later
# setup.sh --sly2 <SCUS_973.16> [--sly1 <SCUS_971.98>]: put the executables extracted from your own discs into
# work/elf/ after checking their SHA-1, create .venv, download the R5900 binutils into tools/ (pinned SHA-256) and report
# what else is missing. Then `make elf` rebuilds and verifies the executable image.
set -euo pipefail
cd "$(dirname "${BASH_SOURCE[0]}")"

SLY2_SHA1=$(cut -d' ' -f1 config/us/checksum.sha1)
SLY1_SHA1=57dc305db57932ad3f1122966cdb695d2e62a47a

install_executable() {
  local source=$1 name=$2 expected=$3
  [[ -f $source ]] || { echo "error: $source not found" >&2; exit 1; }
  local actual
  actual=$(shasum "$source" | cut -d' ' -f1)
  if [[ $actual != "$expected" ]]; then
    echo "error: $source has sha1 $actual, expected $expected (the USA release)" >&2
    exit 1
  fi
  mkdir -p work/elf
  cp "$source" "work/elf/$name"
  echo "ok: work/elf/$name"
}

while (($#)); do
  case $1 in
    --sly2) install_executable "$2" SCUS_973.16 "$SLY2_SHA1"; shift 2 ;;
    --sly1) install_executable "$2" SCUS_971.98 "$SLY1_SHA1"; shift 2 ;;
    *) echo "usage: $0 --sly2 <SCUS_973.16> [--sly1 <SCUS_971.98>]" >&2; exit 2 ;;
  esac
done

install_binutils() {
  local version=v0.10 archive sha256
  case "$(uname -s)-$(uname -m)" in
    Linux-x86_64) archive=binutils-mips-ps2-decompals-linux-x86-64.tar.gz
                  sha256=9fe31ea3ee1a37536f9f0e2e12c668e7c3cb99e59f5154bd2f1fc4762473094c ;;
    Darwin-arm64) archive=binutils-mips-ps2-decompals-macos-arm64.tar.gz
                  sha256=948cc736e01b2c135168caabfb616f6ed8efe89f1dad1ed8ef1ca74acb1b742c ;;
    *) echo "no prebuilt R5900 binutils for $(uname -sm); use Linux x86-64 (WSL, Docker) or macOS arm64" >&2; exit 1 ;;
  esac
  [[ -x tools/binutils-mips-ps2-decompals/mips-ps2-decompals-as ]] && return
  mkdir -p tools/binutils-mips-ps2-decompals
  curl -fsSL -o "tools/$archive" "https://github.com/decompals/binutils-mips-ps2-decompals/releases/download/$version/$archive"
  echo "$sha256  tools/$archive" | shasum -a 256 -c - || { rm -f "tools/$archive"; exit 1; }
  tar -xzf "tools/$archive" -C tools/binutils-mips-ps2-decompals
  rm -f "tools/$archive"
  echo "ok: tools/binutils-mips-ps2-decompals"
}

install_compiler() {
  local sha256=3b6ae6897229ad005aaf1b0afaa1f3cb46e74b4c21a42e01130c07c0c598067f wibo wibo_sha256
  case "$(uname -s)-$(uname -m)" in
    Linux-x86_64) wibo=wibo-i686; wibo_sha256=2575d3b0a2f408b2c2b0850db56f1af5d005a138394a6774eba77b6708ecc304 ;;
    Darwin-*)     wibo=wibo-macos; wibo_sha256=2b3000ef6a7a490c24ccd71967735ae0005e218922e51806cca1b8d77fd3cf7c ;;
    *) echo "no wibo for $(uname -sm)" >&2; exit 1 ;;
  esac
  if [[ ! -x tools/wibo ]]; then
    curl -fsSL -o tools/wibo "https://github.com/decompals/wibo/releases/download/1.2.0/$wibo"
    echo "$wibo_sha256  tools/wibo" | shasum -a 256 -c - || { rm -f tools/wibo; exit 1; }
    chmod +x tools/wibo
    echo "ok: tools/wibo"
  fi
  if [[ ! -f tools/compilers/ee-gcc2.95.3-136/bin/ee-gcc.exe ]]; then
    mkdir -p tools/compilers/ee-gcc2.95.3-136
    curl -fsSL -o tools/ee-gcc2.95.3-136.tar.gz "https://github.com/decompme/compilers/releases/download/compilers/ee-gcc2.95.3-136.tar.gz"
    echo "$sha256  tools/ee-gcc2.95.3-136.tar.gz" | shasum -a 256 -c - || { rm -f tools/ee-gcc2.95.3-136.tar.gz; exit 1; }
    tar -xzf tools/ee-gcc2.95.3-136.tar.gz -C tools/compilers/ee-gcc2.95.3-136
    rm -f tools/ee-gcc2.95.3-136.tar.gz
    echo "ok: tools/compilers/ee-gcc2.95.3-136"
  fi
}

install_objdiff() {
  local asset sha256
  case "$(uname -s)-$(uname -m)" in
    Linux-x86_64) asset=objdiff-cli-linux-x86_64
                  sha256=e823ae932a56c68dcd86b68d12f2268c953e0c027402162c8a6dfa6a00d65008 ;;
    Darwin-arm64) asset=objdiff-cli-macos-arm64
                  sha256=27dbd79196394c246dde77ef0a6ac855ff6c568069171dd7db0093f39c03ee8d ;;
    *) echo "no prebuilt objdiff-cli for $(uname -sm)" >&2; return 0 ;;
  esac
  [[ -x tools/objdiff/objdiff-cli ]] && return
  mkdir -p tools/objdiff
  curl -fsSL -o tools/objdiff/objdiff-cli "https://github.com/encounter/objdiff/releases/download/v3.8.3/$asset"
  echo "$sha256  tools/objdiff/objdiff-cli" | shasum -a 256 -c - || { rm -f tools/objdiff/objdiff-cli; exit 1; }
  chmod +x tools/objdiff/objdiff-cli
  echo "ok: tools/objdiff/objdiff-cli"
}

if [[ ! -x .venv/bin/python ]]; then
  python3 -m venv .venv
  .venv/bin/pip install -q -r requirements.txt -r requirements-dev.txt
  echo "ok: .venv"
fi
install_binutils
install_compiler
install_objdiff

missing=0
for tool in python3 clang java analyzeHeadless; do
  command -v "$tool" >/dev/null || { echo "missing tool: $tool"; missing=1; }
done
exit $missing
