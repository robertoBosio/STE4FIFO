#pragma once
#include "hls_stream.h"
#include "ap_int.h"
#include <array>
#include <cstddef>

template <typename T, size_t CH_PAR, size_t W_PAR, size_t DEPTH,
          size_t BATCH = 1,
          size_t RATE_II = DEPTH>
void mm2s(std::array<std::array<T, CH_PAR>, W_PAR> in_data[DEPTH],
          hls::stream<std::array<T, CH_PAR>> out_stream[W_PAR]) {
  static_assert(RATE_II > 0, "RATE_II must be greater than zero");
  static_assert(DEPTH <= RATE_II,
                "MM2S throttling only supports rates up to one word per cycle");

  constexpr size_t TOTAL_WORDS = DEPTH * BATCH;
  constexpr size_t TOTAL_CYCLES =
      (TOTAL_WORDS * RATE_II + DEPTH - 1) / DEPTH;

  size_t acc = 0;
  size_t sent = 0;

  for (size_t cycle = 0; cycle < TOTAL_CYCLES; cycle++) {
#pragma HLS PIPELINE II=1
    acc += DEPTH;

    if (acc >= RATE_II) {
      acc -= RATE_II;
      size_t d = sent % DEPTH;

      for (size_t w = 0; w < W_PAR; w++) {
        out_stream[w].write(in_data[d][w]);
      }

      sent++;
    }
  }
}

template <typename T, size_t CH_PAR, size_t W_PAR, size_t DEPTH, size_t BATCH = 1>
void s2mm(hls::stream<std::array<T, CH_PAR>> in_stream[W_PAR],
          std::array<std::array<T, CH_PAR>, W_PAR> out_data[DEPTH]) {
  for (size_t batch = 0; batch < BATCH; batch++) {
    for (size_t d = 0; d < DEPTH; d++) {
      for (size_t w = 0; w < W_PAR; w++) {
        out_data[d][w] = in_stream[w].read();
      }
    }
  }
}
