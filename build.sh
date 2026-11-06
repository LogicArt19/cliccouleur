#!/usr/bin/env bash
# Compile ClicCouleur.exe pour Windows (x64) depuis Linux, avec clang + lld.
# Usage : ./build.sh [numero_de_version]
set -euo pipefail
VERSION="${1:-0}"
DLLTOOL="$(command -v llvm-dlltool || ls /usr/lib/llvm-*/bin/llvm-dlltool | tail -1)"
mkdir -p out
for def in build/*.def; do
  "$DLLTOOL" -m i386:x86-64 -d "$def" -l "out/$(basename "$def" .def).lib"
done
clang --target=x86_64-pc-windows-msvc -O2 -ffreestanding -fno-builtin -fno-stack-protector -Wall \
  -DVERSION="$VERSION" -c src/cliccouleur.c -o out/cliccouleur.obj
lld-link /nologo /subsystem:windows /entry:demarrer /nodefaultlib /out:out/ClicCouleur.exe \
  out/cliccouleur.obj out/*.lib
echo "$VERSION" > out/version.txt
echo "OK : out/ClicCouleur.exe (version $VERSION)"
