# Genesis

![C++20](https://img.shields.io/badge/C%2B%2B-20-blue.svg)

![CMake](https://img.shields.io/badge/CMake-3.22+-brightgreen.svg)

![Platform](https://img.shields.io/badge/Platform-Cross--Platform-orange.svg)

![License](https://img.shields.io/badge/License-MIT-green.svg)

> Building a Transformer-based Language Model from Scratch in Modern C++20

Genesis is an educational project whose goal is **not** to compete with existing Large Language Models such as ChatGPT,
Llama or Gemini.

Instead, the purpose of this project is to understand, implement and document every fundamental building block of a
Transformer-based language model from scratch.

Performance is **not** the primary objective.

Understanding the architecture is.

---

# Why Genesis?

Most open-source LLM projects focus on performance.

Genesis focuses on understanding.

Instead of hiding complexity behind machine learning frameworks,

every important component is implemented manually and explained in detail.

The objective is to understand how a Transformer actually works,

one component at a time.

## Philosophy

This project follows a few strict principles:

- Build everything from scratch whenever possible.
- Understand every algorithm before implementing it.
- Prefer clarity to cleverness.
- Keep the architecture modular and extensible.
- Write modern, clean and readable C++20.
- Explain every important design decision.
- Refactor when a better architecture is discovered.
- Learn by building, not by hiding complexity behind frameworks.

---

## What We Will NOT Use

During the core implementation we intentionally avoid high-level machine learning frameworks.

Examples include:

- PyTorch
- TensorFlow
- Hugging Face
- llama.cpp
- ONNX Runtime

External libraries will only be considered if they provide infrastructure rather than machine learning functionality,
and only after understanding the underlying concepts.

---

## Development Environment

| Component      | Value          |
|----------------|----------------|
| Language       | C++20          |
| IDE            | CLion          |
| Compiler       | Clang          |
| Build System   | CMake          |
| Platform       | Cross-platform |
| Initial Target | CPU            |

GPU acceleration (Metal, CUDA, Vulkan, etc.) may be added in later stages.

---

# Roadmap

## Phase 0 — Project Architecture

- [x] CMake project
- [x] Modular folder structure
- [x] Version system
- [x] Basic executable
- [x] Initial Tokenizer
- [ ] Unit testing infrastructure

---

## Phase 1 — Text Processing

- [ ] Tokenizer
- [ ] Vocabulary
- [ ] Token IDs
- [ ] Dataset Loader

---

## Phase 2 — Mathematics

- [ ] Vector
- [ ] Matrix
- [ ] Tensor
- [ ] Linear Algebra Utilities

---

## Phase 3 — Neural Network

- [ ] Embedding
- [ ] Positional Encoding
- [ ] Softmax
- [ ] Layer Normalization
- [ ] Feed Forward Network

---

## Phase 4 — Transformer

- [ ] Self Attention
- [ ] Multi-Head Attention
- [ ] Transformer Block
- [ ] Decoder

---

## Phase 5 — Training

- [ ] Loss Functions
- [ ] Backpropagation
- [ ] Optimizer
- [ ] Gradient Descent
- [ ] Training Loop

---

## Phase 6 — Text Generation

- [ ] Greedy Decoding
- [ ] Temperature Sampling
- [ ] Top-k Sampling
- [ ] Top-p Sampling

---

# Repository Structure

```text
Genesis/
│
├── include/
├── src/
├── tests/
├── CMakeLists.txt
└── README.md
```

---

# Project Status

Current Version: **v0.1.0**

Implemented:

- Basic project architecture
- Version system
- Tokenizer (initial implementation)

---

# Educational Goal

This repository is intentionally developed step by step.

No implementation is considered "magic".

Every algorithm, every mathematical operation and every architectural decision should be understandable by someone
willing to study the source code.

The repository should eventually become a complete educational reference for building a Transformer-based language model
from scratch in modern C++.

The ultimate goal of Genesis is not only to build a language model, but also to document every step of the journey so
that anyone can understand how modern LLMs work internally.

---

# Future Plans

- CPU optimization

- SIMD support

- Multithreading

- Metal backend (Apple Silicon)

- CUDA backend

- Model serialization

- Inference engine

- Quantization

# License

MIT License