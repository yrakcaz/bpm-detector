[![CI](https://github.com/yrakcaz/bpm-detector/actions/workflows/ci.yml/badge.svg)](https://github.com/yrakcaz/bpm-detector/actions/workflows/ci.yml)
[![MIT License](https://img.shields.io/github/license/yrakcaz/bpm-detector?color=blue)](./LICENSE)

# bpm-detector

A command-line tool to extract the BPM (Beats Per Minute) from any audio file. Uses libsndfile for audio loading, analyzes energy levels across 4096-sample windows, detects peaks, and normalizes the result to the 70–200 BPM range.

## Requirements

- libsndfile (`libsndfile1-dev`)
- g++ or clang++ with C++11 support

On Debian/Ubuntu:

```
apt install libsndfile1-dev
```

## Build

```
./configure && make
```

Options:

- `--with-debug` — enable debug symbols (`-g3`)
- `--with-clang` — compile with clang++ instead of g++
- `--prefix=DIR` — set install directory (default: `/usr/local`)

## Install

```
make install
```

To uninstall:

```
make uninstall
```

## Usage

```
bpm-detector <song file>
```

The detected BPM is printed to stdout.

