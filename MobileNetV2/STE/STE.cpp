/*
* This file was automatically generated using csnake v0.4.0.
*
* This file should not be edited directly, any changes will be
* overwritten next time the script is run.
*
* Source code for csnake is available at:
* https://gitlab.com/andrejr/csnake
*
* csnake is also available on PyPI, at :
* https://pypi.org/project/csnake
*/
#include "ap_int.h"
#include "hls_stream.h"
#include "hls_vector.h"
#include "ap_axi_sdata.h"
#include <chrono>
#include <cstdlib>
#include "StreamingUpsample.hpp"
#include "StreamingAveragePool.hpp"
#include "StreamingConstMul.hpp"
#include "StreamingDepthwiseConv.hpp"
#include "StreamingPad.hpp"
#include "StreamingReshape.hpp"
#include "StreamingMaxPool.hpp"
#include "StreamingSoftmax.hpp"
#include "StreamingGlobalAveragePool.hpp"
#include "StreamingConv.hpp"
#include "StreamingMul.hpp"
#include "DequantQuant.hpp"
#include "TensorDuplicator.hpp"
#include "StreamingConcat.hpp"
#include "StreamingWindowSelector.hpp"
#include "StreamingLUT.hpp"
#include "StreamingSplit.hpp"
#include "StreamingReLU.hpp"
#include "StreamToNHWC.hpp"
#include "StreamingMemory.hpp"
#include "StreamingAdd.hpp"
#include "NHWCToStream.hpp"
#include "BandwidthAdjust.hpp"
#include "YoloAttention/SplitReshape.hpp"
#include "YoloAttention/VPMatMul.hpp"
#include "YoloAttention/QKMatMul.hpp"
#include "YoloAttention/Transpose.hpp"
#include "utils/CSDFG_utils.hpp"
#include "utils/DMA_utils.hpp"
#include <fstream>
#include <iostream>
#include <unordered_map>
void mobilenet_v2(void)
{
    auto start_time = std::chrono::high_resolution_clock::now();
    NHWCToStream <
        ap_axiu<128, 0, 0, 0>,  // TInputStruct
        ap_uint<128>,  // TInput
        std::array<ap_int<8>, 3>,  // TOutputStruct
        ap_int<8>,  // TOutput
        DequantQuantEqual<ap_int<8>>,  // Quantizer
        16,  // DATA_PER_WORD
        224,  // HEIGHT
        224,  // WIDTH
        3,  // CH
        2,  // OUT_W_PAR
        3  // OUT_CH_PAR
    > NHWCToStream_0;
    NHWCToStream_0.step_init(1);
    NHWCToStream <
        ap_axiu<128, 0, 0, 0>,  // TInputStruct
        ap_uint<128>,  // TInput
        std::array<ap_uint<32>, 1>,  // TOutputStruct
        ap_uint<32>,  // TOutput
        DequantQuantEqual<ap_uint<32>>,  // Quantizer
        4,  // DATA_PER_WORD
        1,  // HEIGHT
        1,  // WIDTH
        876302,  // CH
        1,  // OUT_W_PAR
        1  // OUT_CH_PAR
    > NHWCToStream_1;
    NHWCToStream_1.step_init(1);
    StreamingWindowSelector <
        std::array<ap_int<8>, 3>,  // TWord
        224,  // IN_HEIGHT
        224,  // IN_WIDTH
        3,  // IN_CH
        3,  // FH
        3,  // FW
        2,  // STRIDE_H
        2,  // STRIDE_W
        1,  // DILATION_H
        1,  // DILATION_W
        1,  // PAD_T
        1,  // PAD_L
        1,  // PAD_B
        1,  // PAD_R
        2,  // POS_H
        4,  // POS_W
        2,  // W_PAR
        3  // CH_PAR
    > StreamingLineBuffer_0_pixel_0;
    StreamingLineBuffer_0_pixel_0.step_init(2, 1);
    StreamingWindowSelector <
        std::array<ap_int<8>, 3>,  // TWord
        224,  // IN_HEIGHT
        224,  // IN_WIDTH
        3,  // IN_CH
        3,  // FH
        3,  // FW
        2,  // STRIDE_H
        2,  // STRIDE_W
        1,  // DILATION_H
        1,  // DILATION_W
        1,  // PAD_T
        1,  // PAD_L
        1,  // PAD_B
        1,  // PAD_R
        2,  // POS_H
        3,  // POS_W
        2,  // W_PAR
        3  // CH_PAR
    > StreamingLineBuffer_0_pixel_1;
    StreamingLineBuffer_0_pixel_1.step_init(2, 1);
    StreamingMemory <
        std::array<ap_uint<32>, 1>,  // TInput
        ap_int<8>,  // TOutput
        std::array<ap_int<8>, 3>,  // TOutputStruct
        4,  // DATA_PER_WORD
        876086,  // DATA_TO_SHIFT
        6272,  // TIMES
        864,  // WORDS
        9,  // ARRAY_PAR
        3  // WORD_PAR
    > StreamingMemory_0;
    StreamingMemory_0.step_init(1);
    StreamingWindowSelector <
        std::array<ap_int<8>, 3>,  // TWord
        224,  // IN_HEIGHT
        224,  // IN_WIDTH
        3,  // IN_CH
        3,  // FH
        3,  // FW
        2,  // STRIDE_H
        2,  // STRIDE_W
        1,  // DILATION_H
        1,  // DILATION_W
        1,  // PAD_T
        1,  // PAD_L
        1,  // PAD_B
        1,  // PAD_R
        2,  // POS_H
        2,  // POS_W
        2,  // W_PAR
        3  // CH_PAR
    > StreamingLineBuffer_0_pixel_2;
    StreamingLineBuffer_0_pixel_2.step_init(2, 2);
    StreamingWindowSelector <
        std::array<ap_int<8>, 3>,  // TWord
        224,  // IN_HEIGHT
        224,  // IN_WIDTH
        3,  // IN_CH
        3,  // FH
        3,  // FW
        2,  // STRIDE_H
        2,  // STRIDE_W
        1,  // DILATION_H
        1,  // DILATION_W
        1,  // PAD_T
        1,  // PAD_L
        1,  // PAD_B
        1,  // PAD_R
        2,  // POS_H
        1,  // POS_W
        2,  // W_PAR
        3  // CH_PAR
    > StreamingLineBuffer_0_pixel_3;
    StreamingLineBuffer_0_pixel_3.step_init(2, 2);
    StreamingMemory <
        std::array<ap_uint<32>, 1>,  // TInput
        ap_int<14>,  // TOutput
        std::array<ap_int<14>, 1>,  // TOutputStruct
        2,  // DATA_PER_WORD
        876070,  // DATA_TO_SHIFT
        6272,  // TIMES
        32,  // WORDS
        1,  // ARRAY_PAR
        1  // WORD_PAR
    > StreamingMemory_1;
    StreamingMemory_1.step_init(1);
    StreamingWindowSelector <
        std::array<ap_int<8>, 3>,  // TWord
        224,  // IN_HEIGHT
        224,  // IN_WIDTH
        3,  // IN_CH
        3,  // FH
        3,  // FW
        2,  // STRIDE_H
        2,  // STRIDE_W
        1,  // DILATION_H
        1,  // DILATION_W
        1,  // PAD_T
        1,  // PAD_L
        1,  // PAD_B
        1,  // PAD_R
        2,  // POS_H
        0,  // POS_W
        2,  // W_PAR
        3  // CH_PAR
    > StreamingLineBuffer_0_pixel_4;
    StreamingLineBuffer_0_pixel_4.step_init(2, 2);
    StreamingWindowSelector <
        std::array<ap_int<8>, 3>,  // TWord
        224,  // IN_HEIGHT
        224,  // IN_WIDTH
        3,  // IN_CH
        3,  // FH
        3,  // FW
        2,  // STRIDE_H
        2,  // STRIDE_W
        1,  // DILATION_H
        1,  // DILATION_W
        1,  // PAD_T
        1,  // PAD_L
        1,  // PAD_B
        1,  // PAD_R
        1,  // POS_H
        3,  // POS_W
        2,  // W_PAR
        3  // CH_PAR
    > StreamingLineBuffer_0_pixel_6;
    StreamingLineBuffer_0_pixel_6.step_init(2, 111);
    StreamingMemory <
        std::array<ap_uint<32>, 1>,  // TInput
        ap_int<8>,  // TOutput
        std::array<ap_int<8>, 1>,  // TOutputStruct
        4,  // DATA_PER_WORD
        875998,  // DATA_TO_SHIFT
        6272,  // TIMES
        288,  // WORDS
        9,  // ARRAY_PAR
        1  // WORD_PAR
    > StreamingMemory_2;
    StreamingMemory_2.step_init(1);
    StreamingWindowSelector <
        std::array<ap_int<8>, 3>,  // TWord
        224,  // IN_HEIGHT
        224,  // IN_WIDTH
        3,  // IN_CH
        3,  // FH
        3,  // FW
        2,  // STRIDE_H
        2,  // STRIDE_W
        1,  // DILATION_H
        1,  // DILATION_W
        1,  // PAD_T
        1,  // PAD_L
        1,  // PAD_B
        1,  // PAD_R
        1,  // POS_H
        4,  // POS_W
        2,  // W_PAR
        3  // CH_PAR
    > StreamingLineBuffer_0_pixel_5;
    StreamingLineBuffer_0_pixel_5.step_init(2, 112);
    StreamingWindowSelector <
        std::array<ap_int<8>, 3>,  // TWord
        224,  // IN_HEIGHT
        224,  // IN_WIDTH
        3,  // IN_CH
        3,  // FH
        3,  // FW
        2,  // STRIDE_H
        2,  // STRIDE_W
        1,  // DILATION_H
        1,  // DILATION_W
        1,  // PAD_T
        1,  // PAD_L
        1,  // PAD_B
        1,  // PAD_R
        1,  // POS_H
        1,  // POS_W
        2,  // W_PAR
        3  // CH_PAR
    > StreamingLineBuffer_0_pixel_8;
    StreamingLineBuffer_0_pixel_8.step_init(2, 2);
    StreamingMemory <
        std::array<ap_uint<32>, 1>,  // TInput
        ap_int<14>,  // TOutput
        std::array<ap_int<14>, 1>,  // TOutputStruct
        2,  // DATA_PER_WORD
        875982,  // DATA_TO_SHIFT
        6272,  // TIMES
        32,  // WORDS
        1,  // ARRAY_PAR
        1  // WORD_PAR
    > StreamingMemory_3;
    StreamingMemory_3.step_init(1);
    StreamingWindowSelector <
        std::array<ap_int<8>, 3>,  // TWord
        224,  // IN_HEIGHT
        224,  // IN_WIDTH
        3,  // IN_CH
        3,  // FH
        3,  // FW
        2,  // STRIDE_H
        2,  // STRIDE_W
        1,  // DILATION_H
        1,  // DILATION_W
        1,  // PAD_T
        1,  // PAD_L
        1,  // PAD_B
        1,  // PAD_R
        1,  // POS_H
        2,  // POS_W
        2,  // W_PAR
        3  // CH_PAR
    > StreamingLineBuffer_0_pixel_7;
    StreamingLineBuffer_0_pixel_7.step_init(2, 2);
    StreamingWindowSelector <
        std::array<ap_int<8>, 3>,  // TWord
        224,  // IN_HEIGHT
        224,  // IN_WIDTH
        3,  // IN_CH
        3,  // FH
        3,  // FW
        2,  // STRIDE_H
        2,  // STRIDE_W
        1,  // DILATION_H
        1,  // DILATION_W
        1,  // PAD_T
        1,  // PAD_L
        1,  // PAD_B
        1,  // PAD_R
        0,  // POS_H
        3,  // POS_W
        2,  // W_PAR
        3  // CH_PAR
    > StreamingLineBuffer_0_pixel_11;
    StreamingLineBuffer_0_pixel_11.step_init(2, 111);
    StreamingMemory <
        std::array<ap_uint<32>, 1>,  // TInput
        ap_int<8>,  // TOutput
        std::array<ap_int<8>, 16>,  // TOutputStruct
        4,  // DATA_PER_WORD
        875854,  // DATA_TO_SHIFT
        6272,  // TIMES
        512,  // WORDS
        1,  // ARRAY_PAR
        16  // WORD_PAR
    > StreamingMemory_4;
    StreamingMemory_4.step_init(1);
    StreamingWindowSelector <
        std::array<ap_int<8>, 3>,  // TWord
        224,  // IN_HEIGHT
        224,  // IN_WIDTH
        3,  // IN_CH
        3,  // FH
        3,  // FW
        2,  // STRIDE_H
        2,  // STRIDE_W
        1,  // DILATION_H
        1,  // DILATION_W
        1,  // PAD_T
        1,  // PAD_L
        1,  // PAD_B
        1,  // PAD_R
        1,  // POS_H
        0,  // POS_W
        2,  // W_PAR
        3  // CH_PAR
    > StreamingLineBuffer_0_pixel_9;
    StreamingLineBuffer_0_pixel_9.step_init(2, 2);
    StreamingWindowSelector <
        std::array<ap_int<8>, 3>,  // TWord
        224,  // IN_HEIGHT
        224,  // IN_WIDTH
        3,  // IN_CH
        3,  // FH
        3,  // FW
        2,  // STRIDE_H
        2,  // STRIDE_W
        1,  // DILATION_H
        1,  // DILATION_W
        1,  // PAD_T
        1,  // PAD_L
        1,  // PAD_B
        1,  // PAD_R
        0,  // POS_H
        1,  // POS_W
        2,  // W_PAR
        3  // CH_PAR
    > StreamingLineBuffer_0_pixel_13;
    StreamingLineBuffer_0_pixel_13.step_init(1, 2);
    StreamingMemory <
        std::array<ap_uint<32>, 1>,  // TInput
        ap_int<15>,  // TOutput
        std::array<ap_int<15>, 2>,  // TOutputStruct
        2,  // DATA_PER_WORD
        875846,  // DATA_TO_SHIFT
        6272,  // TIMES
        16,  // WORDS
        1,  // ARRAY_PAR
        2  // WORD_PAR
    > StreamingMemory_5;
    StreamingMemory_5.step_init(1);
    StreamingWindowSelector <
        std::array<ap_int<8>, 3>,  // TWord
        224,  // IN_HEIGHT
        224,  // IN_WIDTH
        3,  // IN_CH
        3,  // FH
        3,  // FW
        2,  // STRIDE_H
        2,  // STRIDE_W
        1,  // DILATION_H
        1,  // DILATION_W
        1,  // PAD_T
        1,  // PAD_L
        1,  // PAD_B
        1,  // PAD_R
        0,  // POS_H
        4,  // POS_W
        2,  // W_PAR
        3  // CH_PAR
    > StreamingLineBuffer_0_pixel_10;
    StreamingLineBuffer_0_pixel_10.step_init(2, 112);
    StreamingMemory <
        std::array<ap_uint<32>, 1>,  // TInput
        ap_int<8>,  // TOutput
        std::array<ap_int<8>, 48>,  // TOutputStruct
        4,  // DATA_PER_WORD
        875462,  // DATA_TO_SHIFT
        6272,  // TIMES
        1536,  // WORDS
        1,  // ARRAY_PAR
        48  // WORD_PAR
    > StreamingMemory_6;
    StreamingMemory_6.step_init(1);
    StreamingWindowSelector <
        std::array<ap_int<8>, 3>,  // TWord
        224,  // IN_HEIGHT
        224,  // IN_WIDTH
        3,  // IN_CH
        3,  // FH
        3,  // FW
        2,  // STRIDE_H
        2,  // STRIDE_W
        1,  // DILATION_H
        1,  // DILATION_W
        1,  // PAD_T
        1,  // PAD_L
        1,  // PAD_B
        1,  // PAD_R
        0,  // POS_H
        2,  // POS_W
        2,  // W_PAR
        3  // CH_PAR
    > StreamingLineBuffer_0_pixel_12;
    StreamingLineBuffer_0_pixel_12.step_init(2, 2);
    StreamingMemory <
        std::array<ap_uint<32>, 1>,  // TInput
        ap_int<14>,  // TOutput
        std::array<ap_int<14>, 3>,  // TOutputStruct
        2,  // DATA_PER_WORD
        875414,  // DATA_TO_SHIFT
        6272,  // TIMES
        96,  // WORDS
        1,  // ARRAY_PAR
        3  // WORD_PAR
    > StreamingMemory_7;
    StreamingMemory_7.step_init(1);
    StreamingWindowSelector <
        std::array<ap_int<8>, 3>,  // TWord
        224,  // IN_HEIGHT
        224,  // IN_WIDTH
        3,  // IN_CH
        3,  // FH
        3,  // FW
        2,  // STRIDE_H
        2,  // STRIDE_W
        1,  // DILATION_H
        1,  // DILATION_W
        1,  // PAD_T
        1,  // PAD_L
        1,  // PAD_B
        1,  // PAD_R
        0,  // POS_H
        0,  // POS_W
        2,  // W_PAR
        3  // CH_PAR
    > StreamingLineBuffer_0_pixel_14;
    StreamingLineBuffer_0_pixel_14.step_init(1, 2);
    StreamingMemory <
        std::array<ap_uint<32>, 1>,  // TInput
        ap_int<8>,  // TOutput
        std::array<ap_int<8>, 3>,  // TOutputStruct
        4,  // DATA_PER_WORD
        875198,  // DATA_TO_SHIFT
        1568,  // TIMES
        864,  // WORDS
        9,  // ARRAY_PAR
        3  // WORD_PAR
    > StreamingMemory_8;
    StreamingMemory_8.step_init(1);
    StreamingPad <
        std::array<ap_int<8>, 3>,  // TWord
        ap_int<8>,  // TData
        224,  // IN_HEIGHT
        224,  // IN_WIDTH
        3,  // IN_CH
        3,  // FH
        3,  // FW
        2,  // STRIDE_H
        2,  // STRIDE_W
        1,  // DILATION_H
        1,  // DILATION_W
        1,  // PAD_T
        1,  // PAD_L
        1,  // PAD_B
        1,  // PAD_R
        2,  // W_PAR
        3,  // CH_PAR
        0  // PAD_VALUE
    > StreamingLineBuffer_0_pad;
    StreamingLineBuffer_0_pad.step_init(2);
    StreamingMemory <
        std::array<ap_uint<32>, 1>,  // TInput
        ap_int<15>,  // TOutput
        std::array<ap_int<15>, 3>,  // TOutputStruct
        2,  // DATA_PER_WORD
        875150,  // DATA_TO_SHIFT
        1568,  // TIMES
        96,  // WORDS
        1,  // ARRAY_PAR
        3  // WORD_PAR
    > StreamingMemory_9;
    StreamingMemory_9.step_init(1);
    StreamingConv <
        std::array<ap_int<8>, 3>,  // TInputWord
        ap_int<8>,  // TInput
        std::array<ap_int<8>, 3>,  // TWeightWord
        ap_int<8>,  // TWeight
        std::array<ap_int<14>, 1>,  // TBiasWord
        ap_int<14>,  // TBias
        std::array<ap_uint<8>, 1>,  // TOutputWord
        ap_uint<8>,  // TOutput
        ap_int<22>,  // TSum
        ap_int<21>,  // TPartialSum
        ReLU<ap_int<22>>,  // Activation
        DequantQuantPo2<7, ap_int<22>, ap_uint<8>>,  // Quantizer
        32,  // OUT_CH
        3,  // IN_CH
        112,  // OUT_HEIGHT
        112,  // OUT_WIDTH
        1,  // GROUP
        3,  // FH
        3,  // FW
        2,  // STRIDE_H
        2,  // STRIDE_W
        3,  // IN_CH_PAR
        1,  // OUT_CH_PAR
        2  // W_PAR
    > StreamingConv_0;
    StreamingConv_0.step_init(11);
    StreamingMemory <
        std::array<ap_uint<32>, 1>,  // TInput
        ap_int<8>,  // TOutput
        std::array<ap_int<8>, 9>,  // TOutputStruct
        4,  // DATA_PER_WORD
        874574,  // DATA_TO_SHIFT
        784,  // TIMES
        2304,  // WORDS
        1,  // ARRAY_PAR
        9  // WORD_PAR
    > StreamingMemory_10;
    StreamingMemory_10.step_init(1);
    StreamingWindowSelector <
        std::array<ap_uint<8>, 1>,  // TWord
        112,  // IN_HEIGHT
        112,  // IN_WIDTH
        32,  // IN_CH
        3,  // FH
        3,  // FW
        1,  // STRIDE_H
        1,  // STRIDE_W
        1,  // DILATION_H
        1,  // DILATION_W
        1,  // PAD_T
        1,  // PAD_L
        1,  // PAD_B
        1,  // PAD_R
        2,  // POS_H
        3,  // POS_W
        2,  // W_PAR
        1  // CH_PAR
    > StreamingLineBuffer_1_pixel_0;
    StreamingLineBuffer_1_pixel_0.step_init(2, 1);
    StreamingWindowSelector <
        std::array<ap_uint<8>, 1>,  // TWord
        112,  // IN_HEIGHT
        112,  // IN_WIDTH
        32,  // IN_CH
        3,  // FH
        3,  // FW
        1,  // STRIDE_H
        1,  // STRIDE_W
        1,  // DILATION_H
        1,  // DILATION_W
        1,  // PAD_T
        1,  // PAD_L
        1,  // PAD_B
        1,  // PAD_R
        2,  // POS_H
        2,  // POS_W
        2,  // W_PAR
        1  // CH_PAR
    > StreamingLineBuffer_1_pixel_1;
    StreamingLineBuffer_1_pixel_1.step_init(2, 1);
    StreamingMemory <
        std::array<ap_uint<32>, 1>,  // TInput
        ap_int<15>,  // TOutput
        std::array<ap_int<15>, 3>,  // TOutputStruct
        2,  // DATA_PER_WORD
        874562,  // DATA_TO_SHIFT
        784,  // TIMES
        24,  // WORDS
        1,  // ARRAY_PAR
        3  // WORD_PAR
    > StreamingMemory_11;
    StreamingMemory_11.step_init(1);
    StreamingWindowSelector <
        std::array<ap_uint<8>, 1>,  // TWord
        112,  // IN_HEIGHT
        112,  // IN_WIDTH
        32,  // IN_CH
        3,  // FH
        3,  // FW
        1,  // STRIDE_H
        1,  // STRIDE_W
        1,  // DILATION_H
        1,  // DILATION_W
        1,  // PAD_T
        1,  // PAD_L
        1,  // PAD_B
        1,  // PAD_R
        2,  // POS_H
        1,  // POS_W
        2,  // W_PAR
        1  // CH_PAR
    > StreamingLineBuffer_1_pixel_2;
    StreamingLineBuffer_1_pixel_2.step_init(2, 33);
    StreamingWindowSelector <
        std::array<ap_uint<8>, 1>,  // TWord
        112,  // IN_HEIGHT
        112,  // IN_WIDTH
        32,  // IN_CH
        3,  // FH
        3,  // FW
        1,  // STRIDE_H
        1,  // STRIDE_W
        1,  // DILATION_H
        1,  // DILATION_W
        1,  // PAD_T
        1,  // PAD_L
        1,  // PAD_B
        1,  // PAD_R
        2,  // POS_H
        0,  // POS_W
        2,  // W_PAR
        1  // CH_PAR
    > StreamingLineBuffer_1_pixel_3;
    StreamingLineBuffer_1_pixel_3.step_init(2, 33);
    StreamingMemory <
        std::array<ap_uint<32>, 1>,  // TInput
        ap_int<8>,  // TOutput
        std::array<ap_int<8>, 16>,  // TOutputStruct
        4,  // DATA_PER_WORD
        873698,  // DATA_TO_SHIFT
        784,  // TIMES
        3456,  // WORDS
        1,  // ARRAY_PAR
        16  // WORD_PAR
    > StreamingMemory_12;
    StreamingMemory_12.step_init(1);
    StreamingWindowSelector <
        std::array<ap_uint<8>, 1>,  // TWord
        112,  // IN_HEIGHT
        112,  // IN_WIDTH
        32,  // IN_CH
        3,  // FH
        3,  // FW
        1,  // STRIDE_H
        1,  // STRIDE_W
        1,  // DILATION_H
        1,  // DILATION_W
        1,  // PAD_T
        1,  // PAD_L
        1,  // PAD_B
        1,  // PAD_R
        1,  // POS_H
        3,  // POS_W
        2,  // W_PAR
        1  // CH_PAR
    > StreamingLineBuffer_1_pixel_4;
    StreamingLineBuffer_1_pixel_4.step_init(2, 1761);
    StreamingWindowSelector <
        std::array<ap_uint<8>, 1>,  // TWord
        112,  // IN_HEIGHT
        112,  // IN_WIDTH
        32,  // IN_CH
        3,  // FH
        3,  // FW
        1,  // STRIDE_H
        1,  // STRIDE_W
        1,  // DILATION_H
        1,  // DILATION_W
        1,  // PAD_T
        1,  // PAD_L
        1,  // PAD_B
        1,  // PAD_R
        1,  // POS_H
        2,  // POS_W
        2,  // W_PAR
        1  // CH_PAR
    > StreamingLineBuffer_1_pixel_5;
    StreamingLineBuffer_1_pixel_5.step_init(1, 1761);
    StreamingMemory <
        std::array<ap_uint<32>, 1>,  // TInput
        ap_int<14>,  // TOutput
        std::array<ap_int<14>, 2>,  // TOutputStruct
        2,  // DATA_PER_WORD
        873626,  // DATA_TO_SHIFT
        784,  // TIMES
        144,  // WORDS
        1,  // ARRAY_PAR
        2  // WORD_PAR
    > StreamingMemory_13;
    StreamingMemory_13.step_init(1);
    StreamingWindowSelector <
        std::array<ap_uint<8>, 1>,  // TWord
        112,  // IN_HEIGHT
        112,  // IN_WIDTH
        32,  // IN_CH
        3,  // FH
        3,  // FW
        1,  // STRIDE_H
        1,  // STRIDE_W
        1,  // DILATION_H
        1,  // DILATION_W
        1,  // PAD_T
        1,  // PAD_L
        1,  // PAD_B
        1,  // PAD_R
        1,  // POS_H
        1,  // POS_W
        2,  // W_PAR
        1  // CH_PAR
    > StreamingLineBuffer_1_pixel_6;
    StreamingLineBuffer_1_pixel_6.step_init(1, 33);
    StreamingWindowSelector <
        std::array<ap_uint<8>, 1>,  // TWord
        112,  // IN_HEIGHT
        112,  // IN_WIDTH
        32,  // IN_CH
        3,  // FH
        3,  // FW
        1,  // STRIDE_H
        1,  // STRIDE_W
        1,  // DILATION_H
        1,  // DILATION_W
        1,  // PAD_T
        1,  // PAD_L
        1,  // PAD_B
        1,  // PAD_R
        1,  // POS_H
        0,  // POS_W
        2,  // W_PAR
        1  // CH_PAR
    > StreamingLineBuffer_1_pixel_7;
    StreamingLineBuffer_1_pixel_7.step_init(2, 33);
    StreamingMemory <
        std::array<ap_uint<32>, 1>,  // TInput
        ap_int<8>,  // TOutput
        std::array<ap_int<8>, 2>,  // TOutputStruct
        4,  // DATA_PER_WORD
        873302,  // DATA_TO_SHIFT
        1568,  // TIMES
        1296,  // WORDS
        9,  // ARRAY_PAR
        2  // WORD_PAR
    > StreamingMemory_14;
    StreamingMemory_14.step_init(1);
    StreamingWindowSelector <
        std::array<ap_uint<8>, 1>,  // TWord
        112,  // IN_HEIGHT
        112,  // IN_WIDTH
        32,  // IN_CH
        3,  // FH
        3,  // FW
        1,  // STRIDE_H
        1,  // STRIDE_W
        1,  // DILATION_H
        1,  // DILATION_W
        1,  // PAD_T
        1,  // PAD_L
        1,  // PAD_B
        1,  // PAD_R
        0,  // POS_H
        3,  // POS_W
        2,  // W_PAR
        1  // CH_PAR
    > StreamingLineBuffer_1_pixel_8;
    StreamingLineBuffer_1_pixel_8.step_init(2, 1761);
    StreamingWindowSelector <
        std::array<ap_uint<8>, 1>,  // TWord
        112,  // IN_HEIGHT
        112,  // IN_WIDTH
        32,  // IN_CH
        3,  // FH
        3,  // FW
        1,  // STRIDE_H
        1,  // STRIDE_W
        1,  // DILATION_H
        1,  // DILATION_W
        1,  // PAD_T
        1,  // PAD_L
        1,  // PAD_B
        1,  // PAD_R
        0,  // POS_H
        2,  // POS_W
        2,  // W_PAR
        1  // CH_PAR
    > StreamingLineBuffer_1_pixel_9;
    StreamingLineBuffer_1_pixel_9.step_init(2, 1761);
    StreamingMemory <
        std::array<ap_uint<32>, 1>,  // TInput
        ap_int<14>,  // TOutput
        std::array<ap_int<14>, 2>,  // TOutputStruct
        2,  // DATA_PER_WORD
        873230,  // DATA_TO_SHIFT
        1568,  // TIMES
        144,  // WORDS
        1,  // ARRAY_PAR
        2  // WORD_PAR
    > StreamingMemory_15;
    StreamingMemory_15.step_init(1);
    StreamingWindowSelector <
        std::array<ap_uint<8>, 1>,  // TWord
        112,  // IN_HEIGHT
        112,  // IN_WIDTH
        32,  // IN_CH
        3,  // FH
        3,  // FW
        1,  // STRIDE_H
        1,  // STRIDE_W
        1,  // DILATION_H
        1,  // DILATION_W
        1,  // PAD_T
        1,  // PAD_L
        1,  // PAD_B
        1,  // PAD_R
        0,  // POS_H
        1,  // POS_W
        2,  // W_PAR
        1  // CH_PAR
    > StreamingLineBuffer_1_pixel_10;
    StreamingLineBuffer_1_pixel_10.step_init(1, 33);
    StreamingWindowSelector <
        std::array<ap_uint<8>, 1>,  // TWord
        112,  // IN_HEIGHT
        112,  // IN_WIDTH
        32,  // IN_CH
        3,  // FH
        3,  // FW
        1,  // STRIDE_H
        1,  // STRIDE_W
        1,  // DILATION_H
        1,  // DILATION_W
        1,  // PAD_T
        1,  // PAD_L
        1,  // PAD_B
        1,  // PAD_R
        0,  // POS_H
        0,  // POS_W
        2,  // W_PAR
        1  // CH_PAR
    > StreamingLineBuffer_1_pixel_11;
    StreamingLineBuffer_1_pixel_11.step_init(1, 33);
    StreamingMemory <
        std::array<ap_uint<32>, 1>,  // TInput
        ap_int<8>,  // TOutput
        std::array<ap_int<8>, 27>,  // TOutputStruct
        4,  // DATA_PER_WORD
        872366,  // DATA_TO_SHIFT
        1568,  // TIMES
        3456,  // WORDS
        1,  // ARRAY_PAR
        27  // WORD_PAR
    > StreamingMemory_16;
    StreamingMemory_16.step_init(1);
    StreamingPad <
        std::array<ap_uint<8>, 1>,  // TWord
        ap_uint<8>,  // TData
        112,  // IN_HEIGHT
        112,  // IN_WIDTH
        32,  // IN_CH
        3,  // FH
        3,  // FW
        1,  // STRIDE_H
        1,  // STRIDE_W
        1,  // DILATION_H
        1,  // DILATION_W
        1,  // PAD_T
        1,  // PAD_L
        1,  // PAD_B
        1,  // PAD_R
        2,  // W_PAR
        1,  // CH_PAR
        0  // PAD_VALUE
    > StreamingLineBuffer_1_pad;
    StreamingLineBuffer_1_pad.step_init(3);
    StreamingMemory <
        std::array<ap_uint<32>, 1>,  // TInput
        ap_int<15>,  // TOutput
        std::array<ap_int<15>, 3>,  // TOutputStruct
        2,  // DATA_PER_WORD
        872354,  // DATA_TO_SHIFT
        1568,  // TIMES
        24,  // WORDS
        1,  // ARRAY_PAR
        3  // WORD_PAR
    > StreamingMemory_17;
    StreamingMemory_17.step_init(1);
    StreamingDepthwiseConv <
        std::array<ap_uint<8>, 1>,  // TInputStruct
        ap_uint<8>,  // TInput
        std::array<ap_int<8>, 1>,  // TWeightStruct
        ap_int<8>,  // TWeight
        std::array<ap_int<14>, 1>,  // TBiasStruct
        ap_int<14>,  // TBias
        std::array<ap_uint<8>, 1>,  // TOutputStruct
        ap_uint<8>,  // TOutput
        ap_int<21>,  // TSum
        ap_int<20>,  // TPartialSum
        ReLU<ap_int<21>>,  // Activation
        DequantQuantPo2<6, ap_int<21>, ap_uint<8>>,  // Quantizer
        32,  // OUT_CH
        32,  // IN_CH
        112,  // IN_HEIGHT
        112,  // IN_WIDTH
        3,  // FH
        3,  // FW
        1,  // STRIDE_H
        1,  // STRIDE_W
        1,  // CH_PAR
        2  // W_PAR
    > StreamingDepthwiseConv_0;
    StreamingDepthwiseConv_0.step_init(8);
    StreamingMemory <
        std::array<ap_uint<32>, 1>,  // TInput
        ap_int<8>,  // TOutput
        std::array<ap_int<8>, 16>,  // TOutputStruct
        4,  // DATA_PER_WORD
        871490,  // DATA_TO_SHIFT
        784,  // TIMES
        3456,  // WORDS
        1,  // ARRAY_PAR
        16  // WORD_PAR
    > StreamingMemory_18;
    StreamingMemory_18.step_init(1);
    BandwidthAdjustIncreaseChannels <
        std::array<ap_uint<8>, 1>,  // TInputStruct
        ap_uint<8>,  // TInput
        std::array<ap_uint<8>, 8>,  // TOutputStruct
        ap_uint<8>,  // TOutput
        DequantQuantEqual<ap_uint<8>>,  // Quantizer
        112,  // IN_HEIGHT
        112,  // IN_WIDTH
        32,  // IN_CH
        2,  // IN_W_PAR
        2,  // OUT_W_PAR
        1,  // IN_CH_PAR
        8  // OUT_CH_PAR
    > BandwidthAdjustIncreaseChannels_0;
    BandwidthAdjustIncreaseChannels_0.step_init(2);
    StreamingMemory <
        std::array<ap_uint<32>, 1>,  // TInput
        ap_int<13>,  // TOutput
        std::array<ap_int<13>, 2>,  // TOutputStruct
        2,  // DATA_PER_WORD
        871418,  // DATA_TO_SHIFT
        784,  // TIMES
        144,  // WORDS
        1,  // ARRAY_PAR
        2  // WORD_PAR
    > StreamingMemory_19;
    StreamingMemory_19.step_init(1);
    StreamingWindowSelector <
        std::array<ap_uint<8>, 8>,  // TWord
        112,  // IN_HEIGHT
        112,  // IN_WIDTH
        32,  // IN_CH
        1,  // FH
        1,  // FW
        1,  // STRIDE_H
        1,  // STRIDE_W
        1,  // DILATION_H
        1,  // DILATION_W
        0,  // PAD_T
        0,  // PAD_L
        0,  // PAD_B
        0,  // PAD_R
        0,  // POS_H
        1,  // POS_W
        2,  // W_PAR
        8  // CH_PAR
    > StreamingLineBuffer_2_pixel_0;
    StreamingLineBuffer_2_pixel_0.step_init(1, 1);
    StreamingWindowSelector <
        std::array<ap_uint<8>, 8>,  // TWord
        112,  // IN_HEIGHT
        112,  // IN_WIDTH
        32,  // IN_CH
        1,  // FH
        1,  // FW
        1,  // STRIDE_H
        1,  // STRIDE_W
        1,  // DILATION_H
        1,  // DILATION_W
        0,  // PAD_T
        0,  // PAD_L
        0,  // PAD_B
        0,  // PAD_R
        0,  // POS_H
        0,  // POS_W
        2,  // W_PAR
        8  // CH_PAR
    > StreamingLineBuffer_2_pixel_1;
    StreamingLineBuffer_2_pixel_1.step_init(1, 1);
    StreamingMemory <
        std::array<ap_uint<32>, 1>,  // TInput
        ap_int<8>,  // TOutput
        std::array<ap_int<8>, 2>,  // TOutputStruct
        4,  // DATA_PER_WORD
        871094,  // DATA_TO_SHIFT
        392,  // TIMES
        1296,  // WORDS
        9,  // ARRAY_PAR
        2  // WORD_PAR
    > StreamingMemory_20;
    StreamingMemory_20.step_init(1);
    StreamingConv <
        std::array<ap_uint<8>, 8>,  // TInputWord
        ap_uint<8>,  // TInput
        std::array<ap_int<8>, 16>,  // TWeightWord
        ap_int<8>,  // TWeight
        std::array<ap_int<15>, 2>,  // TBiasWord
        ap_int<15>,  // TBias
        std::array<ap_int<8>, 2>,  // TOutputWord
        ap_int<8>,  // TOutput
        ap_int<24>,  // TSum
        ap_int<23>,  // TPartialSum
        DequantQuantEqual<ap_int<24>>,  // Activation
        DequantQuantPo2<8, ap_int<24>, ap_int<8>>,  // Quantizer
        16,  // OUT_CH
        32,  // IN_CH
        112,  // OUT_HEIGHT
        112,  // OUT_WIDTH
        1,  // GROUP
        1,  // FH
        1,  // FW
        1,  // STRIDE_H
        1,  // STRIDE_W
        8,  // IN_CH_PAR
        2,  // OUT_CH_PAR
        2  // W_PAR
    > StreamingConv_1;
    StreamingConv_1.step_init(9);
    StreamingMemory <
        std::array<ap_uint<32>, 1>,  // TInput
        ap_int<15>,  // TOutput
        std::array<ap_int<15>, 2>,  // TOutputStruct
        2,  // DATA_PER_WORD
        871022,  // DATA_TO_SHIFT
        392,  // TIMES
        144,  // WORDS
        1,  // ARRAY_PAR
        2  // WORD_PAR
    > StreamingMemory_21;
    StreamingMemory_21.step_init(1);
    BandwidthAdjustIncreaseChannels <
        std::array<ap_int<8>, 2>,  // TInputStruct
        ap_int<8>,  // TInput
        std::array<ap_int<8>, 16>,  // TOutputStruct
        ap_int<8>,  // TOutput
        DequantQuantEqual<ap_int<8>>,  // Quantizer
        112,  // IN_HEIGHT
        112,  // IN_WIDTH
        16,  // IN_CH
        2,  // IN_W_PAR
        2,  // OUT_W_PAR
        2,  // IN_CH_PAR
        16  // OUT_CH_PAR
    > BandwidthAdjustIncreaseChannels_1;
    BandwidthAdjustIncreaseChannels_1.step_init(2);
    StreamingMemory <
        std::array<ap_uint<32>, 1>,  // TInput
        ap_int<8>,  // TOutput
        std::array<ap_int<8>, 9>,  // TOutputStruct
        4,  // DATA_PER_WORD
        869870,  // DATA_TO_SHIFT
        392,  // TIMES
        4608,  // WORDS
        1,  // ARRAY_PAR
        9  // WORD_PAR
    > StreamingMemory_22;
    StreamingMemory_22.step_init(1);
    StreamingWindowSelector <
        std::array<ap_int<8>, 16>,  // TWord
        112,  // IN_HEIGHT
        112,  // IN_WIDTH
        16,  // IN_CH
        1,  // FH
        1,  // FW
        1,  // STRIDE_H
        1,  // STRIDE_W
        1,  // DILATION_H
        1,  // DILATION_W
        0,  // PAD_T
        0,  // PAD_L
        0,  // PAD_B
        0,  // PAD_R
        0,  // POS_H
        1,  // POS_W
        2,  // W_PAR
        16  // CH_PAR
    > StreamingLineBuffer_3_pixel_0;
    StreamingLineBuffer_3_pixel_0.step_init(1, 1);
    StreamingWindowSelector <
        std::array<ap_int<8>, 16>,  // TWord
        112,  // IN_HEIGHT
        112,  // IN_WIDTH
        16,  // IN_CH
        1,  // FH
        1,  // FW
        1,  // STRIDE_H
        1,  // STRIDE_W
        1,  // DILATION_H
        1,  // DILATION_W
        0,  // PAD_T
        0,  // PAD_L
        0,  // PAD_B
        0,  // PAD_R
        0,  // POS_H
        0,  // POS_W
        2,  // W_PAR
        16  // CH_PAR
    > StreamingLineBuffer_3_pixel_1;
    StreamingLineBuffer_3_pixel_1.step_init(1, 1);
    StreamingMemory <
        std::array<ap_uint<32>, 1>,  // TInput
        ap_int<15>,  // TOutput
        std::array<ap_int<15>, 1>,  // TOutputStruct
        2,  // DATA_PER_WORD
        869854,  // DATA_TO_SHIFT
        392,  // TIMES
        32,  // WORDS
        1,  // ARRAY_PAR
        1  // WORD_PAR
    > StreamingMemory_23;
    StreamingMemory_23.step_init(1);
    StreamingConv <
        std::array<ap_int<8>, 16>,  // TInputWord
        ap_int<8>,  // TInput
        std::array<ap_int<8>, 48>,  // TWeightWord
        ap_int<8>,  // TWeight
        std::array<ap_int<14>, 3>,  // TBiasWord
        ap_int<14>,  // TBias
        std::array<ap_uint<8>, 3>,  // TOutputWord
        ap_uint<8>,  // TOutput
        ap_int<22>,  // TSum
        ap_int<21>,  // TPartialSum
        ReLU<ap_int<22>>,  // Activation
        DequantQuantPo2<6, ap_int<22>, ap_uint<8>>,  // Quantizer
        96,  // OUT_CH
        16,  // IN_CH
        112,  // OUT_HEIGHT
        112,  // OUT_WIDTH
        1,  // GROUP
        1,  // FH
        1,  // FW
        1,  // STRIDE_H
        1,  // STRIDE_W
        16,  // IN_CH_PAR
        3,  // OUT_CH_PAR
        2  // W_PAR
    > StreamingConv_2;
    StreamingConv_2.step_init(10);
    StreamingMemory <
        std::array<ap_uint<32>, 1>,  // TInput
        ap_int<8>,  // TOutput
        std::array<ap_int<8>, 12>,  // TOutputStruct
        4,  // DATA_PER_WORD
        868318,  // DATA_TO_SHIFT
        392,  // TIMES
        6144,  // WORDS
        1,  // ARRAY_PAR
        12  // WORD_PAR
    > StreamingMemory_24;
    StreamingMemory_24.step_init(1);
    StreamingWindowSelector <
        std::array<ap_uint<8>, 3>,  // TWord
        112,  // IN_HEIGHT
        112,  // IN_WIDTH
        96,  // IN_CH
        3,  // FH
        3,  // FW
        2,  // STRIDE_H
        2,  // STRIDE_W
        1,  // DILATION_H
        1,  // DILATION_W
        1,  // PAD_T
        1,  // PAD_L
        1,  // PAD_B
        1,  // PAD_R
        2,  // POS_H
        4,  // POS_W
        2,  // W_PAR
        3  // CH_PAR
    > StreamingLineBuffer_4_pixel_0;
    StreamingLineBuffer_4_pixel_0.step_init(2, 1);
    StreamingWindowSelector <
        std::array<ap_uint<8>, 3>,  // TWord
        112,  // IN_HEIGHT
        112,  // IN_WIDTH
        96,  // IN_CH
        3,  // FH
        3,  // FW
        2,  // STRIDE_H
        2,  // STRIDE_W
        1,  // DILATION_H
        1,  // DILATION_W
        1,  // PAD_T
        1,  // PAD_L
        1,  // PAD_B
        1,  // PAD_R
        2,  // POS_H
        3,  // POS_W
        2,  // W_PAR
        3  // CH_PAR
    > StreamingLineBuffer_4_pixel_1;
    StreamingLineBuffer_4_pixel_1.step_init(2, 1);
    StreamingMemory <
        std::array<ap_uint<32>, 1>,  // TInput
        ap_int<15>,  // TOutput
        std::array<ap_int<15>, 3>,  // TOutputStruct
        2,  // DATA_PER_WORD
        868222,  // DATA_TO_SHIFT
        392,  // TIMES
        192,  // WORDS
        1,  // ARRAY_PAR
        3  // WORD_PAR
    > StreamingMemory_25;
    StreamingMemory_25.step_init(1);
    StreamingWindowSelector <
        std::array<ap_uint<8>, 3>,  // TWord
        112,  // IN_HEIGHT
        112,  // IN_WIDTH
        96,  // IN_CH
        3,  // FH
        3,  // FW
        2,  // STRIDE_H
        2,  // STRIDE_W
        1,  // DILATION_H
        1,  // DILATION_W
        1,  // PAD_T
        1,  // PAD_L
        1,  // PAD_B
        1,  // PAD_R
        2,  // POS_H
        2,  // POS_W
        2,  // W_PAR
        3  // CH_PAR
    > StreamingLineBuffer_4_pixel_2;
    StreamingLineBuffer_4_pixel_2.step_init(2, 33);
    StreamingWindowSelector <
        std::array<ap_uint<8>, 3>,  // TWord
        112,  // IN_HEIGHT
        112,  // IN_WIDTH
        96,  // IN_CH
        3,  // FH
        3,  // FW
        2,  // STRIDE_H
        2,  // STRIDE_W
        1,  // DILATION_H
        1,  // DILATION_W
        1,  // PAD_T
        1,  // PAD_L
        1,  // PAD_B
        1,  // PAD_R
        2,  // POS_H
        1,  // POS_W
        2,  // W_PAR
        3  // CH_PAR
    > StreamingLineBuffer_4_pixel_3;
    StreamingLineBuffer_4_pixel_3.step_init(2, 33);
    StreamingMemory <
        std::array<ap_uint<32>, 1>,  // TInput
        ap_int<8>,  // TOutput
        std::array<ap_int<8>, 1>,  // TOutputStruct
        4,  // DATA_PER_WORD
        867790,  // DATA_TO_SHIFT
        392,  // TIMES
        1728,  // WORDS
        9,  // ARRAY_PAR
        1  // WORD_PAR
    > StreamingMemory_26;
    StreamingMemory_26.step_init(1);
    StreamingWindowSelector <
        std::array<ap_uint<8>, 3>,  // TWord
        112,  // IN_HEIGHT
        112,  // IN_WIDTH
        96,  // IN_CH
        3,  // FH
        3,  // FW
        2,  // STRIDE_H
        2,  // STRIDE_W
        1,  // DILATION_H
        1,  // DILATION_W
        1,  // PAD_T
        1,  // PAD_L
        1,  // PAD_B
        1,  // PAD_R
        2,  // POS_H
        0,  // POS_W
        2,  // W_PAR
        3  // CH_PAR
    > StreamingLineBuffer_4_pixel_4;
    StreamingLineBuffer_4_pixel_4.step_init(2, 33);
    StreamingWindowSelector <
        std::array<ap_uint<8>, 3>,  // TWord
        112,  // IN_HEIGHT
        112,  // IN_WIDTH
        96,  // IN_CH
        3,  // FH
        3,  // FW
        2,  // STRIDE_H
        2,  // STRIDE_W
        1,  // DILATION_H
        1,  // DILATION_W
        1,  // PAD_T
        1,  // PAD_L
        1,  // PAD_B
        1,  // PAD_R
        1,  // POS_H
        3,  // POS_W
        2,  // W_PAR
        3  // CH_PAR
    > StreamingLineBuffer_4_pixel_6;
    StreamingLineBuffer_4_pixel_6.step_init(2, 1729);
    StreamingMemory <
        std::array<ap_uint<32>, 1>,  // TInput
        ap_int<14>,  // TOutput
        std::array<ap_int<14>, 1>,  // TOutputStruct
        2,  // DATA_PER_WORD
        867694,  // DATA_TO_SHIFT
        392,  // TIMES
        192,  // WORDS
        1,  // ARRAY_PAR
        1  // WORD_PAR
    > StreamingMemory_27;
    StreamingMemory_27.step_init(1);
    StreamingWindowSelector <
        std::array<ap_uint<8>, 3>,  // TWord
        112,  // IN_HEIGHT
        112,  // IN_WIDTH
        96,  // IN_CH
        3,  // FH
        3,  // FW
        2,  // STRIDE_H
        2,  // STRIDE_W
        1,  // DILATION_H
        1,  // DILATION_W
        1,  // PAD_T
        1,  // PAD_L
        1,  // PAD_B
        1,  // PAD_R
        1,  // POS_H
        4,  // POS_W
        2,  // W_PAR
        3  // CH_PAR
    > StreamingLineBuffer_4_pixel_5;
    StreamingLineBuffer_4_pixel_5.step_init(2, 1761);
    StreamingWindowSelector <
        std::array<ap_uint<8>, 3>,  // TWord
        112,  // IN_HEIGHT
        112,  // IN_WIDTH
        96,  // IN_CH
        3,  // FH
        3,  // FW
        2,  // STRIDE_H
        2,  // STRIDE_W
        1,  // DILATION_H
        1,  // DILATION_W
        1,  // PAD_T
        1,  // PAD_L
        1,  // PAD_B
        1,  // PAD_R
        1,  // POS_H
        1,  // POS_W
        2,  // W_PAR
        3  // CH_PAR
    > StreamingLineBuffer_4_pixel_8;
    StreamingLineBuffer_4_pixel_8.step_init(2, 33);
    StreamingMemory <
        std::array<ap_uint<32>, 1>,  // TInput
        ap_int<8>,  // TOutput
        std::array<ap_int<8>, 12>,  // TOutputStruct
        4,  // DATA_PER_WORD
        866158,  // DATA_TO_SHIFT
        392,  // TIMES
        6144,  // WORDS
        1,  // ARRAY_PAR
        12  // WORD_PAR
    > StreamingMemory_28;
    StreamingMemory_28.step_init(1);
    StreamingWindowSelector <
        std::array<ap_uint<8>, 3>,  // TWord
        112,  // IN_HEIGHT
        112,  // IN_WIDTH
        96,  // IN_CH
        3,  // FH
        3,  // FW
        2,  // STRIDE_H
        2,  // STRIDE_W
        1,  // DILATION_H
        1,  // DILATION_W
        1,  // PAD_T
        1,  // PAD_L
        1,  // PAD_B
        1,  // PAD_R
        1,  // POS_H
        2,  // POS_W
        2,  // W_PAR
        3  // CH_PAR
    > StreamingLineBuffer_4_pixel_7;
    StreamingLineBuffer_4_pixel_7.step_init(2, 33);
    StreamingWindowSelector <
        std::array<ap_uint<8>, 3>,  // TWord
        112,  // IN_HEIGHT
        112,  // IN_WIDTH
        96,  // IN_CH
        3,  // FH
        3,  // FW
        2,  // STRIDE_H
        2,  // STRIDE_W
        1,  // DILATION_H
        1,  // DILATION_W
        1,  // PAD_T
        1,  // PAD_L
        1,  // PAD_B
        1,  // PAD_R
        0,  // POS_H
        3,  // POS_W
        2,  // W_PAR
        3  // CH_PAR
    > StreamingLineBuffer_4_pixel_11;
    StreamingLineBuffer_4_pixel_11.step_init(2, 1729);
    StreamingMemory <
        std::array<ap_uint<32>, 1>,  // TInput
        ap_int<15>,  // TOutput
        std::array<ap_int<15>, 4>,  // TOutputStruct
        2,  // DATA_PER_WORD
        866142,  // DATA_TO_SHIFT
        392,  // TIMES
        32,  // WORDS
        1,  // ARRAY_PAR
        4  // WORD_PAR
    > StreamingMemory_29;
    StreamingMemory_29.step_init(1);
    StreamingWindowSelector <
        std::array<ap_uint<8>, 3>,  // TWord
        112,  // IN_HEIGHT
        112,  // IN_WIDTH
        96,  // IN_CH
        3,  // FH
        3,  // FW
        2,  // STRIDE_H
        2,  // STRIDE_W
        1,  // DILATION_H
        1,  // DILATION_W
        1,  // PAD_T
        1,  // PAD_L
        1,  // PAD_B
        1,  // PAD_R
        1,  // POS_H
        0,  // POS_W
        2,  // W_PAR
        3  // CH_PAR
    > StreamingLineBuffer_4_pixel_9;
    StreamingLineBuffer_4_pixel_9.step_init(2, 33);
    StreamingWindowSelector <
        std::array<ap_uint<8>, 3>,  // TWord
        112,  // IN_HEIGHT
        112,  // IN_WIDTH
        96,  // IN_CH
        3,  // FH
        3,  // FW
        2,  // STRIDE_H
        2,  // STRIDE_W
        1,  // DILATION_H
        1,  // DILATION_W
        1,  // PAD_T
        1,  // PAD_L
        1,  // PAD_B
        1,  // PAD_R
        0,  // POS_H
        1,  // POS_W
        2,  // W_PAR
        3  // CH_PAR
    > StreamingLineBuffer_4_pixel_13;
    StreamingLineBuffer_4_pixel_13.step_init(1, 33);
    StreamingMemory <
        std::array<ap_uint<32>, 1>,  // TInput
        ap_int<8>,  // TOutput
        std::array<ap_int<8>, 12>,  // TOutputStruct
        4,  // DATA_PER_WORD
        864606,  // DATA_TO_SHIFT
        392,  // TIMES
        6144,  // WORDS
        1,  // ARRAY_PAR
        12  // WORD_PAR
    > StreamingMemory_30;
    StreamingMemory_30.step_init(1);
    StreamingWindowSelector <
        std::array<ap_uint<8>, 3>,  // TWord
        112,  // IN_HEIGHT
        112,  // IN_WIDTH
        96,  // IN_CH
        3,  // FH
        3,  // FW
        2,  // STRIDE_H
        2,  // STRIDE_W
        1,  // DILATION_H
        1,  // DILATION_W
        1,  // PAD_T
        1,  // PAD_L
        1,  // PAD_B
        1,  // PAD_R
        0,  // POS_H
        4,  // POS_W
        2,  // W_PAR
        3  // CH_PAR
    > StreamingLineBuffer_4_pixel_10;
    StreamingLineBuffer_4_pixel_10.step_init(2, 1761);
    StreamingMemory <
        std::array<ap_uint<32>, 1>,  // TInput
        ap_int<15>,  // TOutput
        std::array<ap_int<15>, 3>,  // TOutputStruct
        2,  // DATA_PER_WORD
        864510,  // DATA_TO_SHIFT
        392,  // TIMES
        192,  // WORDS
        1,  // ARRAY_PAR
        3  // WORD_PAR
    > StreamingMemory_31;
    StreamingMemory_31.step_init(1);
    StreamingWindowSelector <
        std::array<ap_uint<8>, 3>,  // TWord
        112,  // IN_HEIGHT
        112,  // IN_WIDTH
        96,  // IN_CH
        3,  // FH
        3,  // FW
        2,  // STRIDE_H
        2,  // STRIDE_W
        1,  // DILATION_H
        1,  // DILATION_W
        1,  // PAD_T
        1,  // PAD_L
        1,  // PAD_B
        1,  // PAD_R
        0,  // POS_H
        2,  // POS_W
        2,  // W_PAR
        3  // CH_PAR
    > StreamingLineBuffer_4_pixel_12;
    StreamingLineBuffer_4_pixel_12.step_init(2, 33);
    StreamingMemory <
        std::array<ap_uint<32>, 1>,  // TInput
        ap_int<8>,  // TOutput
        std::array<ap_int<8>, 1>,  // TOutputStruct
        4,  // DATA_PER_WORD
        864078,  // DATA_TO_SHIFT
        392,  // TIMES
        1728,  // WORDS
        9,  // ARRAY_PAR
        1  // WORD_PAR
    > StreamingMemory_32;
    StreamingMemory_32.step_init(1);
    StreamingWindowSelector <
        std::array<ap_uint<8>, 3>,  // TWord
        112,  // IN_HEIGHT
        112,  // IN_WIDTH
        96,  // IN_CH
        3,  // FH
        3,  // FW
        2,  // STRIDE_H
        2,  // STRIDE_W
        1,  // DILATION_H
        1,  // DILATION_W
        1,  // PAD_T
        1,  // PAD_L
        1,  // PAD_B
        1,  // PAD_R
        0,  // POS_H
        0,  // POS_W
        2,  // W_PAR
        3  // CH_PAR
    > StreamingLineBuffer_4_pixel_14;
    StreamingLineBuffer_4_pixel_14.step_init(1, 33);
    StreamingMemory <
        std::array<ap_uint<32>, 1>,  // TInput
        ap_int<14>,  // TOutput
        std::array<ap_int<14>, 1>,  // TOutputStruct
        2,  // DATA_PER_WORD
        863982,  // DATA_TO_SHIFT
        392,  // TIMES
        192,  // WORDS
        1,  // ARRAY_PAR
        1  // WORD_PAR
    > StreamingMemory_33;
    StreamingMemory_33.step_init(1);
    StreamingPad <
        std::array<ap_uint<8>, 3>,  // TWord
        ap_uint<8>,  // TData
        112,  // IN_HEIGHT
        112,  // IN_WIDTH
        96,  // IN_CH
        3,  // FH
        3,  // FW
        2,  // STRIDE_H
        2,  // STRIDE_W
        1,  // DILATION_H
        1,  // DILATION_W
        1,  // PAD_T
        1,  // PAD_L
        1,  // PAD_B
        1,  // PAD_R
        2,  // W_PAR
        3,  // CH_PAR
        0  // PAD_VALUE
    > StreamingLineBuffer_4_pad;
    StreamingLineBuffer_4_pad.step_init(3);
    StreamingMemory <
        std::array<ap_uint<32>, 1>,  // TInput
        ap_int<8>,  // TOutput
        std::array<ap_int<8>, 12>,  // TOutputStruct
        4,  // DATA_PER_WORD
        862446,  // DATA_TO_SHIFT
        392,  // TIMES
        6144,  // WORDS
        1,  // ARRAY_PAR
        12  // WORD_PAR
    > StreamingMemory_34;
    StreamingMemory_34.step_init(1);
    StreamingDepthwiseConv <
        std::array<ap_uint<8>, 3>,  // TInputStruct
        ap_uint<8>,  // TInput
        std::array<ap_int<8>, 3>,  // TWeightStruct
        ap_int<8>,  // TWeight
        std::array<ap_int<15>, 3>,  // TBiasStruct
        ap_int<15>,  // TBias
        std::array<ap_uint<8>, 3>,  // TOutputStruct
        ap_uint<8>,  // TOutput
        ap_int<21>,  // TSum
        ap_int<20>,  // TPartialSum
        ReLU<ap_int<21>>,  // Activation
        DequantQuantPo2<7, ap_int<21>, ap_uint<8>>,  // Quantizer
        96,  // OUT_CH
        96,  // IN_CH
        56,  // IN_HEIGHT
        56,  // IN_WIDTH
        3,  // FH
        3,  // FW
        2,  // STRIDE_H
        2,  // STRIDE_W
        3,  // CH_PAR
        2  // W_PAR
    > StreamingDepthwiseConv_1;
    StreamingDepthwiseConv_1.step_init(8);
    StreamingMemory <
        std::array<ap_uint<32>, 1>,  // TInput
        ap_int<16>,  // TOutput
        std::array<ap_int<16>, 4>,  // TOutputStruct
        2,  // DATA_PER_WORD
        862430,  // DATA_TO_SHIFT
        392,  // TIMES
        32,  // WORDS
        1,  // ARRAY_PAR
        4  // WORD_PAR
    > StreamingMemory_35;
    StreamingMemory_35.step_init(1);
    BandwidthAdjustIncreaseStreams <
        std::array<ap_uint<8>, 3>,  // TInputStruct
        ap_uint<8>,  // TInput
        std::array<ap_uint<8>, 3>,  // TOutputStruct
        ap_uint<8>,  // TOutput
        DequantQuantEqual<ap_uint<8>>,  // Quantizer
        56,  // IN_HEIGHT
        56,  // IN_WIDTH
        96,  // IN_CH
        2,  // IN_W_PAR
        4,  // OUT_W_PAR
        3,  // IN_CH_PAR
        3  // OUT_CH_PAR
    > BandwidthAdjustIncreaseStreams_0;
    BandwidthAdjustIncreaseStreams_0.step_init(1);
    StreamingMemory <
        std::array<ap_uint<32>, 1>,  // TInput
        ap_int<8>,  // TOutput
        std::array<ap_int<8>, 12>,  // TOutputStruct
        4,  // DATA_PER_WORD
        860894,  // DATA_TO_SHIFT
        392,  // TIMES
        6144,  // WORDS
        1,  // ARRAY_PAR
        12  // WORD_PAR
    > StreamingMemory_36;
    StreamingMemory_36.step_init(1);
    StreamingWindowSelector <
        std::array<ap_uint<8>, 3>,  // TWord
        56,  // IN_HEIGHT
        56,  // IN_WIDTH
        96,  // IN_CH
        1,  // FH
        1,  // FW
        1,  // STRIDE_H
        1,  // STRIDE_W
        1,  // DILATION_H
        1,  // DILATION_W
        0,  // PAD_T
        0,  // PAD_L
        0,  // PAD_B
        0,  // PAD_R
        0,  // POS_H
        3,  // POS_W
        4,  // W_PAR
        3  // CH_PAR
    > StreamingLineBuffer_5_pixel_0;
    StreamingLineBuffer_5_pixel_0.step_init(1, 1);
    StreamingWindowSelector <
        std::array<ap_uint<8>, 3>,  // TWord
        56,  // IN_HEIGHT
        56,  // IN_WIDTH
        96,  // IN_CH
        1,  // FH
        1,  // FW
        1,  // STRIDE_H
        1,  // STRIDE_W
        1,  // DILATION_H
        1,  // DILATION_W
        0,  // PAD_T
        0,  // PAD_L
        0,  // PAD_B
        0,  // PAD_R
        0,  // POS_H
        2,  // POS_W
        4,  // W_PAR
        3  // CH_PAR
    > StreamingLineBuffer_5_pixel_1;
    StreamingLineBuffer_5_pixel_1.step_init(1, 1);
    StreamingWindowSelector <
        std::array<ap_uint<8>, 3>,  // TWord
        56,  // IN_HEIGHT
        56,  // IN_WIDTH
        96,  // IN_CH
        1,  // FH
        1,  // FW
        1,  // STRIDE_H
        1,  // STRIDE_W
        1,  // DILATION_H
        1,  // DILATION_W
        0,  // PAD_T
        0,  // PAD_L
        0,  // PAD_B
        0,  // PAD_R
        0,  // POS_H
        1,  // POS_W
        4,  // W_PAR
        3  // CH_PAR
    > StreamingLineBuffer_5_pixel_2;
    StreamingLineBuffer_5_pixel_2.step_init(1, 1);
    StreamingWindowSelector <
        std::array<ap_uint<8>, 3>,  // TWord
        56,  // IN_HEIGHT
        56,  // IN_WIDTH
        96,  // IN_CH
        1,  // FH
        1,  // FW
        1,  // STRIDE_H
        1,  // STRIDE_W
        1,  // DILATION_H
        1,  // DILATION_W
        0,  // PAD_T
        0,  // PAD_L
        0,  // PAD_B
        0,  // PAD_R
        0,  // POS_H
        0,  // POS_W
        4,  // W_PAR
        3  // CH_PAR
    > StreamingLineBuffer_5_pixel_3;
    StreamingLineBuffer_5_pixel_3.step_init(1, 1);
    StreamingMemory <
        std::array<ap_uint<32>, 1>,  // TInput
        ap_int<14>,  // TOutput
        std::array<ap_int<14>, 3>,  // TOutputStruct
        2,  // DATA_PER_WORD
        860798,  // DATA_TO_SHIFT
        392,  // TIMES
        192,  // WORDS
        1,  // ARRAY_PAR
        3  // WORD_PAR
    > StreamingMemory_37;
    StreamingMemory_37.step_init(1);
    StreamingConv <
        std::array<ap_uint<8>, 3>,  // TInputWord
        ap_uint<8>,  // TInput
        std::array<ap_int<8>, 9>,  // TWeightWord
        ap_int<8>,  // TWeight
        std::array<ap_int<15>, 3>,  // TBiasWord
        ap_int<15>,  // TBias
        std::array<ap_int<8>, 3>,  // TOutputWord
        ap_int<8>,  // TOutput
        ap_int<25>,  // TSum
        ap_int<24>,  // TPartialSum
        DequantQuantEqual<ap_int<25>>,  // Activation
        DequantQuantPo2<8, ap_int<25>, ap_int<8>>,  // Quantizer
        24,  // OUT_CH
        96,  // IN_CH
        56,  // OUT_HEIGHT
        56,  // OUT_WIDTH
        1,  // GROUP
        1,  // FH
        1,  // FW
        1,  // STRIDE_H
        1,  // STRIDE_W
        3,  // IN_CH_PAR
        3,  // OUT_CH_PAR
        4  // W_PAR
    > StreamingConv_3;
    StreamingConv_3.step_init(9);
    StreamingMemory <
        std::array<ap_uint<32>, 1>,  // TInput
        ap_int<8>,  // TOutput
        std::array<ap_int<8>, 1>,  // TOutputStruct
        4,  // DATA_PER_WORD
        860366,  // DATA_TO_SHIFT
        196,  // TIMES
        1728,  // WORDS
        9,  // ARRAY_PAR
        1  // WORD_PAR
    > StreamingMemory_38;
    StreamingMemory_38.step_init(1);
    TensorDuplicator <
        std::array<ap_int<8>, 3>,  // TWord
        56,  // IN_HEIGHT
        56,  // IN_WIDTH
        24,  // IN_CH
        3,  // CH_PAR
        4  // W_PAR
    > TensorDuplicator_0;
    TensorDuplicator_0.step_init(1);
    StreamingMemory <
        std::array<ap_uint<32>, 1>,  // TInput
        ap_int<15>,  // TOutput
        std::array<ap_int<15>, 1>,  // TOutputStruct
        2,  // DATA_PER_WORD
        860270,  // DATA_TO_SHIFT
        196,  // TIMES
        192,  // WORDS
        1,  // ARRAY_PAR
        1  // WORD_PAR
    > StreamingMemory_39;
    StreamingMemory_39.step_init(1);
    BandwidthAdjustDecreaseChannels <
        std::array<ap_int<8>, 3>,  // TInputStruct
        ap_int<8>,  // TInput
        std::array<ap_int<8>, 1>,  // TOutputStruct
        ap_int<8>,  // TOutput
        DequantQuantEqual<ap_int<8>>,  // Quantizer
        56,  // IN_HEIGHT
        56,  // IN_WIDTH
        24,  // IN_CH
        4,  // IN_W_PAR
        4,  // OUT_W_PAR
        3,  // IN_CH_PAR
        1  // OUT_CH_PAR
    > BandwidthAdjustDecreaseChannels_0;
    BandwidthAdjustDecreaseChannels_0.step_init(2);
    BandwidthAdjustDecreaseStreams <
        std::array<ap_int<8>, 3>,  // TInputStruct
        ap_int<8>,  // TInput
        std::array<ap_int<8>, 3>,  // TOutputStruct
        ap_int<8>,  // TOutput
        DequantQuantEqual<ap_int<8>>,  // Quantizer
        56,  // IN_HEIGHT
        56,  // IN_WIDTH
        24,  // IN_CH
        4,  // IN_W_PAR
        2,  // OUT_W_PAR
        3,  // IN_CH_PAR
        3  // OUT_CH_PAR
    > BandwidthAdjustDecreaseStreams_0;
    BandwidthAdjustDecreaseStreams_0.step_init(2);
    StreamingMemory <
        std::array<ap_uint<32>, 1>,  // TInput
        ap_int<8>,  // TOutput
        std::array<ap_int<8>, 12>,  // TOutputStruct
        4,  // DATA_PER_WORD
        857198,  // DATA_TO_SHIFT
        196,  // TIMES
        12288,  // WORDS
        1,  // ARRAY_PAR
        12  // WORD_PAR
    > StreamingMemory_40;
    StreamingMemory_40.step_init(1);
    BandwidthAdjustIncreaseChannels <
        std::array<ap_int<8>, 1>,  // TInputStruct
        ap_int<8>,  // TInput
        std::array<ap_int<8>, 8>,  // TOutputStruct
        ap_int<8>,  // TOutput
        DequantQuantEqual<ap_int<8>>,  // Quantizer
        56,  // IN_HEIGHT
        56,  // IN_WIDTH
        24,  // IN_CH
        4,  // IN_W_PAR
        4,  // OUT_W_PAR
        1,  // IN_CH_PAR
        8  // OUT_CH_PAR
    > BandwidthAdjustIncreaseChannels_2;
    BandwidthAdjustIncreaseChannels_2.step_init(2);
    StreamingMemory <
        std::array<ap_uint<32>, 1>,  // TInput
        ap_int<16>,  // TOutput
        std::array<ap_int<16>, 4>,  // TOutputStruct
        2,  // DATA_PER_WORD
        857166,  // DATA_TO_SHIFT
        196,  // TIMES
        64,  // WORDS
        1,  // ARRAY_PAR
        4  // WORD_PAR
    > StreamingMemory_41;
    StreamingMemory_41.step_init(1);
    StreamingWindowSelector <
        std::array<ap_int<8>, 8>,  // TWord
        56,  // IN_HEIGHT
        56,  // IN_WIDTH
        24,  // IN_CH
        1,  // FH
        1,  // FW
        1,  // STRIDE_H
        1,  // STRIDE_W
        1,  // DILATION_H
        1,  // DILATION_W
        0,  // PAD_T
        0,  // PAD_L
        0,  // PAD_B
        0,  // PAD_R
        0,  // POS_H
        3,  // POS_W
        4,  // W_PAR
        8  // CH_PAR
    > StreamingLineBuffer_6_pixel_0;
    StreamingLineBuffer_6_pixel_0.step_init(1, 1);
    StreamingWindowSelector <
        std::array<ap_int<8>, 8>,  // TWord
        56,  // IN_HEIGHT
        56,  // IN_WIDTH
        24,  // IN_CH
        1,  // FH
        1,  // FW
        1,  // STRIDE_H
        1,  // STRIDE_W
        1,  // DILATION_H
        1,  // DILATION_W
        0,  // PAD_T
        0,  // PAD_L
        0,  // PAD_B
        0,  // PAD_R
        0,  // POS_H
        2,  // POS_W
        4,  // W_PAR
        8  // CH_PAR
    > StreamingLineBuffer_6_pixel_1;
    StreamingLineBuffer_6_pixel_1.step_init(1, 1);
    StreamingWindowSelector <
        std::array<ap_int<8>, 8>,  // TWord
        56,  // IN_HEIGHT
        56,  // IN_WIDTH
        24,  // IN_CH
        1,  // FH
        1,  // FW
        1,  // STRIDE_H
        1,  // STRIDE_W
        1,  // DILATION_H
        1,  // DILATION_W
        0,  // PAD_T
        0,  // PAD_L
        0,  // PAD_B
        0,  // PAD_R
        0,  // POS_H
        1,  // POS_W
        4,  // W_PAR
        8  // CH_PAR
    > StreamingLineBuffer_6_pixel_2;
    StreamingLineBuffer_6_pixel_2.step_init(1, 1);
    StreamingWindowSelector <
        std::array<ap_int<8>, 8>,  // TWord
        56,  // IN_HEIGHT
        56,  // IN_WIDTH
        24,  // IN_CH
        1,  // FH
        1,  // FW
        1,  // STRIDE_H
        1,  // STRIDE_W
        1,  // DILATION_H
        1,  // DILATION_W
        0,  // PAD_T
        0,  // PAD_L
        0,  // PAD_B
        0,  // PAD_R
        0,  // POS_H
        0,  // POS_W
        4,  // W_PAR
        8  // CH_PAR
    > StreamingLineBuffer_6_pixel_3;
    StreamingLineBuffer_6_pixel_3.step_init(1, 1);
    StreamingMemory <
        std::array<ap_uint<32>, 1>,  // TInput
        ap_int<8>,  // TOutput
        std::array<ap_int<8>, 12>,  // TOutputStruct
        4,  // DATA_PER_WORD
        851022,  // DATA_TO_SHIFT
        98,  // TIMES
        24576,  // WORDS
        1,  // ARRAY_PAR
        12  // WORD_PAR
    > StreamingMemory_42;
    StreamingMemory_42.step_init(1);
    StreamingConv <
        std::array<ap_int<8>, 8>,  // TInputWord
        ap_int<8>,  // TInput
        std::array<ap_int<8>, 16>,  // TWeightWord
        ap_int<8>,  // TWeight
        std::array<ap_int<14>, 2>,  // TBiasWord
        ap_int<14>,  // TBias
        std::array<ap_uint<8>, 2>,  // TOutputWord
        ap_uint<8>,  // TOutput
        ap_int<22>,  // TSum
        ap_int<21>,  // TPartialSum
        ReLU<ap_int<22>>,  // Activation
        DequantQuantPo2<7, ap_int<22>, ap_uint<8>>,  // Quantizer
        144,  // OUT_CH
        24,  // IN_CH
        56,  // OUT_HEIGHT
        56,  // OUT_WIDTH
        1,  // GROUP
        1,  // FH
        1,  // FW
        1,  // STRIDE_H
        1,  // STRIDE_W
        8,  // IN_CH_PAR
        2,  // OUT_CH_PAR
        4  // W_PAR
    > StreamingConv_4;
    StreamingConv_4.step_init(10);
    StreamingMemory <
        std::array<ap_uint<32>, 1>,  // TInput
        ap_int<16>,  // TOutput
        std::array<ap_int<16>, 3>,  // TOutputStruct
        2,  // DATA_PER_WORD
        850830,  // DATA_TO_SHIFT
        98,  // TIMES
        384,  // WORDS
        1,  // ARRAY_PAR
        3  // WORD_PAR
    > StreamingMemory_43;
    StreamingMemory_43.step_init(1);
    BandwidthAdjustDecreaseStreams <
        std::array<ap_uint<8>, 2>,  // TInputStruct
        ap_uint<8>,  // TInput
        std::array<ap_uint<8>, 2>,  // TOutputStruct
        ap_uint<8>,  // TOutput
        DequantQuantEqual<ap_uint<8>>,  // Quantizer
        56,  // IN_HEIGHT
        56,  // IN_WIDTH
        144,  // IN_CH
        4,  // IN_W_PAR
        2,  // OUT_W_PAR
        2,  // IN_CH_PAR
        2  // OUT_CH_PAR
    > BandwidthAdjustDecreaseStreams_1;
    BandwidthAdjustDecreaseStreams_1.step_init(2);
    StreamingMemory <
        std::array<ap_uint<32>, 1>,  // TInput
        ap_int<8>,  // TOutput
        std::array<ap_int<8>, 1>,  // TOutputStruct
        4,  // DATA_PER_WORD
        849966,  // DATA_TO_SHIFT
        98,  // TIMES
        3456,  // WORDS
        9,  // ARRAY_PAR
        1  // WORD_PAR
    > StreamingMemory_44;
    StreamingMemory_44.step_init(1);
    StreamingWindowSelector <
        std::array<ap_uint<8>, 2>,  // TWord
        56,  // IN_HEIGHT
        56,  // IN_WIDTH
        144,  // IN_CH
        3,  // FH
        3,  // FW
        1,  // STRIDE_H
        1,  // STRIDE_W
        1,  // DILATION_H
        1,  // DILATION_W
        1,  // PAD_T
        1,  // PAD_L
        1,  // PAD_B
        1,  // PAD_R
        2,  // POS_H
        3,  // POS_W
        2,  // W_PAR
        2  // CH_PAR
    > StreamingLineBuffer_7_pixel_0;
    StreamingLineBuffer_7_pixel_0.step_init(2, 1);
    StreamingWindowSelector <
        std::array<ap_uint<8>, 2>,  // TWord
        56,  // IN_HEIGHT
        56,  // IN_WIDTH
        144,  // IN_CH
        3,  // FH
        3,  // FW
        1,  // STRIDE_H
        1,  // STRIDE_W
        1,  // DILATION_H
        1,  // DILATION_W
        1,  // PAD_T
        1,  // PAD_L
        1,  // PAD_B
        1,  // PAD_R
        2,  // POS_H
        2,  // POS_W
        2,  // W_PAR
        2  // CH_PAR
    > StreamingLineBuffer_7_pixel_1;
    StreamingLineBuffer_7_pixel_1.step_init(2, 1);
    StreamingMemory <
        std::array<ap_uint<32>, 1>,  // TInput
        ap_int<14>,  // TOutput
        std::array<ap_int<14>, 1>,  // TOutputStruct
        2,  // DATA_PER_WORD
        849774,  // DATA_TO_SHIFT
        98,  // TIMES
        384,  // WORDS
        1,  // ARRAY_PAR
        1  // WORD_PAR
    > StreamingMemory_45;
    StreamingMemory_45.step_init(1);
    StreamingWindowSelector <
        std::array<ap_uint<8>, 2>,  // TWord
        56,  // IN_HEIGHT
        56,  // IN_WIDTH
        144,  // IN_CH
        3,  // FH
        3,  // FW
        1,  // STRIDE_H
        1,  // STRIDE_W
        1,  // DILATION_H
        1,  // DILATION_W
        1,  // PAD_T
        1,  // PAD_L
        1,  // PAD_B
        1,  // PAD_R
        2,  // POS_H
        1,  // POS_W
        2,  // W_PAR
        2  // CH_PAR
    > StreamingLineBuffer_7_pixel_2;
    StreamingLineBuffer_7_pixel_2.step_init(2, 73);
    StreamingWindowSelector <
        std::array<ap_uint<8>, 2>,  // TWord
        56,  // IN_HEIGHT
        56,  // IN_WIDTH
        144,  // IN_CH
        3,  // FH
        3,  // FW
        1,  // STRIDE_H
        1,  // STRIDE_W
        1,  // DILATION_H
        1,  // DILATION_W
        1,  // PAD_T
        1,  // PAD_L
        1,  // PAD_B
        1,  // PAD_R
        2,  // POS_H
        0,  // POS_W
        2,  // W_PAR
        2  // CH_PAR
    > StreamingLineBuffer_7_pixel_3;
    StreamingLineBuffer_7_pixel_3.step_init(2, 73);
    StreamingMemory <
        std::array<ap_uint<32>, 1>,  // TInput
        ap_int<8>,  // TOutput
        std::array<ap_int<8>, 12>,  // TOutputStruct
        4,  // DATA_PER_WORD
        843630,  // DATA_TO_SHIFT
        98,  // TIMES
        24576,  // WORDS
        1,  // ARRAY_PAR
        12  // WORD_PAR
    > StreamingMemory_46;
    StreamingMemory_46.step_init(1);
    StreamingWindowSelector <
        std::array<ap_uint<8>, 2>,  // TWord
        56,  // IN_HEIGHT
        56,  // IN_WIDTH
        144,  // IN_CH
        3,  // FH
        3,  // FW
        1,  // STRIDE_H
        1,  // STRIDE_W
        1,  // DILATION_H
        1,  // DILATION_W
        1,  // PAD_T
        1,  // PAD_L
        1,  // PAD_B
        1,  // PAD_R
        1,  // POS_H
        3,  // POS_W
        2,  // W_PAR
        2  // CH_PAR
    > StreamingLineBuffer_7_pixel_4;
    StreamingLineBuffer_7_pixel_4.step_init(2, 1945);
    StreamingWindowSelector <
        std::array<ap_uint<8>, 2>,  // TWord
        56,  // IN_HEIGHT
        56,  // IN_WIDTH
        144,  // IN_CH
        3,  // FH
        3,  // FW
        1,  // STRIDE_H
        1,  // STRIDE_W
        1,  // DILATION_H
        1,  // DILATION_W
        1,  // PAD_T
        1,  // PAD_L
        1,  // PAD_B
        1,  // PAD_R
        1,  // POS_H
        2,  // POS_W
        2,  // W_PAR
        2  // CH_PAR
    > StreamingLineBuffer_7_pixel_5;
    StreamingLineBuffer_7_pixel_5.step_init(1, 1945);
    StreamingMemory <
        std::array<ap_uint<32>, 1>,  // TInput
        ap_int<16>,  // TOutput
        std::array<ap_int<16>, 4>,  // TOutputStruct
        2,  // DATA_PER_WORD
        843598,  // DATA_TO_SHIFT
        98,  // TIMES
        64,  // WORDS
        1,  // ARRAY_PAR
        4  // WORD_PAR
    > StreamingMemory_47;
    StreamingMemory_47.step_init(1);
    StreamingWindowSelector <
        std::array<ap_uint<8>, 2>,  // TWord
        56,  // IN_HEIGHT
        56,  // IN_WIDTH
        144,  // IN_CH
        3,  // FH
        3,  // FW
        1,  // STRIDE_H
        1,  // STRIDE_W
        1,  // DILATION_H
        1,  // DILATION_W
        1,  // PAD_T
        1,  // PAD_L
        1,  // PAD_B
        1,  // PAD_R
        1,  // POS_H
        1,  // POS_W
        2,  // W_PAR
        2  // CH_PAR
    > StreamingLineBuffer_7_pixel_6;
    StreamingLineBuffer_7_pixel_6.step_init(1, 73);
    StreamingWindowSelector <
        std::array<ap_uint<8>, 2>,  // TWord
        56,  // IN_HEIGHT
        56,  // IN_WIDTH
        144,  // IN_CH
        3,  // FH
        3,  // FW
        1,  // STRIDE_H
        1,  // STRIDE_W
        1,  // DILATION_H
        1,  // DILATION_W
        1,  // PAD_T
        1,  // PAD_L
        1,  // PAD_B
        1,  // PAD_R
        1,  // POS_H
        0,  // POS_W
        2,  // W_PAR
        2  // CH_PAR
    > StreamingLineBuffer_7_pixel_7;
    StreamingLineBuffer_7_pixel_7.step_init(2, 73);
    StreamingMemory <
        std::array<ap_uint<32>, 1>,  // TInput
        ap_int<8>,  // TOutput
        std::array<ap_int<8>, 12>,  // TOutputStruct
        4,  // DATA_PER_WORD
        837454,  // DATA_TO_SHIFT
        98,  // TIMES
        24576,  // WORDS
        1,  // ARRAY_PAR
        12  // WORD_PAR
    > StreamingMemory_48;
    StreamingMemory_48.step_init(1);
    StreamingWindowSelector <
        std::array<ap_uint<8>, 2>,  // TWord
        56,  // IN_HEIGHT
        56,  // IN_WIDTH
        144,  // IN_CH
        3,  // FH
        3,  // FW
        1,  // STRIDE_H
        1,  // STRIDE_W
        1,  // DILATION_H
        1,  // DILATION_W
        1,  // PAD_T
        1,  // PAD_L
        1,  // PAD_B
        1,  // PAD_R
        0,  // POS_H
        3,  // POS_W
        2,  // W_PAR
        2  // CH_PAR
    > StreamingLineBuffer_7_pixel_8;
    StreamingLineBuffer_7_pixel_8.step_init(2, 1945);
    StreamingWindowSelector <
        std::array<ap_uint<8>, 2>,  // TWord
        56,  // IN_HEIGHT
        56,  // IN_WIDTH
        144,  // IN_CH
        3,  // FH
        3,  // FW
        1,  // STRIDE_H
        1,  // STRIDE_W
        1,  // DILATION_H
        1,  // DILATION_W
        1,  // PAD_T
        1,  // PAD_L
        1,  // PAD_B
        1,  // PAD_R
        0,  // POS_H
        2,  // POS_W
        2,  // W_PAR
        2  // CH_PAR
    > StreamingLineBuffer_7_pixel_9;
    StreamingLineBuffer_7_pixel_9.step_init(2, 1945);
    StreamingMemory <
        std::array<ap_uint<32>, 1>,  // TInput
        ap_int<16>,  // TOutput
        std::array<ap_int<16>, 3>,  // TOutputStruct
        2,  // DATA_PER_WORD
        837262,  // DATA_TO_SHIFT
        98,  // TIMES
        384,  // WORDS
        1,  // ARRAY_PAR
        3  // WORD_PAR
    > StreamingMemory_49;
    StreamingMemory_49.step_init(1);
    StreamingWindowSelector <
        std::array<ap_uint<8>, 2>,  // TWord
        56,  // IN_HEIGHT
        56,  // IN_WIDTH
        144,  // IN_CH
        3,  // FH
        3,  // FW
        1,  // STRIDE_H
        1,  // STRIDE_W
        1,  // DILATION_H
        1,  // DILATION_W
        1,  // PAD_T
        1,  // PAD_L
        1,  // PAD_B
        1,  // PAD_R
        0,  // POS_H
        1,  // POS_W
        2,  // W_PAR
        2  // CH_PAR
    > StreamingLineBuffer_7_pixel_10;
    StreamingLineBuffer_7_pixel_10.step_init(1, 73);
    StreamingWindowSelector <
        std::array<ap_uint<8>, 2>,  // TWord
        56,  // IN_HEIGHT
        56,  // IN_WIDTH
        144,  // IN_CH
        3,  // FH
        3,  // FW
        1,  // STRIDE_H
        1,  // STRIDE_W
        1,  // DILATION_H
        1,  // DILATION_W
        1,  // PAD_T
        1,  // PAD_L
        1,  // PAD_B
        1,  // PAD_R
        0,  // POS_H
        0,  // POS_W
        2,  // W_PAR
        2  // CH_PAR
    > StreamingLineBuffer_7_pixel_11;
    StreamingLineBuffer_7_pixel_11.step_init(1, 73);
    StreamingMemory <
        std::array<ap_uint<32>, 1>,  // TInput
        ap_int<8>,  // TOutput
        std::array<ap_int<8>, 1>,  // TOutputStruct
        4,  // DATA_PER_WORD
        836398,  // DATA_TO_SHIFT
        98,  // TIMES
        3456,  // WORDS
        9,  // ARRAY_PAR
        1  // WORD_PAR
    > StreamingMemory_50;
    StreamingMemory_50.step_init(1);
    StreamingPad <
        std::array<ap_uint<8>, 2>,  // TWord
        ap_uint<8>,  // TData
        56,  // IN_HEIGHT
        56,  // IN_WIDTH
        144,  // IN_CH
        3,  // FH
        3,  // FW
        1,  // STRIDE_H
        1,  // STRIDE_W
        1,  // DILATION_H
        1,  // DILATION_W
        1,  // PAD_T
        1,  // PAD_L
        1,  // PAD_B
        1,  // PAD_R
        2,  // W_PAR
        2,  // CH_PAR
        0  // PAD_VALUE
    > StreamingLineBuffer_7_pad;
    StreamingLineBuffer_7_pad.step_init(3);
    StreamingMemory <
        std::array<ap_uint<32>, 1>,  // TInput
        ap_int<14>,  // TOutput
        std::array<ap_int<14>, 1>,  // TOutputStruct
        2,  // DATA_PER_WORD
        836206,  // DATA_TO_SHIFT
        98,  // TIMES
        384,  // WORDS
        1,  // ARRAY_PAR
        1  // WORD_PAR
    > StreamingMemory_51;
    StreamingMemory_51.step_init(1);
    StreamingDepthwiseConv <
        std::array<ap_uint<8>, 2>,  // TInputStruct
        ap_uint<8>,  // TInput
        std::array<ap_int<8>, 2>,  // TWeightStruct
        ap_int<8>,  // TWeight
        std::array<ap_int<14>, 2>,  // TBiasStruct
        ap_int<14>,  // TBias
        std::array<ap_uint<8>, 2>,  // TOutputStruct
        ap_uint<8>,  // TOutput
        ap_int<21>,  // TSum
        ap_int<20>,  // TPartialSum
        ReLU<ap_int<21>>,  // Activation
        DequantQuantPo2<5, ap_int<21>, ap_uint<8>>,  // Quantizer
        144,  // OUT_CH
        144,  // IN_CH
        56,  // IN_HEIGHT
        56,  // IN_WIDTH
        3,  // FH
        3,  // FW
        1,  // STRIDE_H
        1,  // STRIDE_W
        2,  // CH_PAR
        2  // W_PAR
    > StreamingDepthwiseConv_2;
    StreamingDepthwiseConv_2.step_init(8);
    StreamingMemory <
        std::array<ap_uint<32>, 1>,  // TInput
        ap_int<8>,  // TOutput
        std::array<ap_int<8>, 12>,  // TOutputStruct
        4,  // DATA_PER_WORD
        830062,  // DATA_TO_SHIFT
        98,  // TIMES
        24576,  // WORDS
        1,  // ARRAY_PAR
        12  // WORD_PAR
    > StreamingMemory_52;
    StreamingMemory_52.step_init(1);
    BandwidthAdjustIncreaseChannels <
        std::array<ap_uint<8>, 2>,  // TInputStruct
        ap_uint<8>,  // TInput
        std::array<ap_uint<8>, 18>,  // TOutputStruct
        ap_uint<8>,  // TOutput
        DequantQuantEqual<ap_uint<8>>,  // Quantizer
        56,  // IN_HEIGHT
        56,  // IN_WIDTH
        144,  // IN_CH
        2,  // IN_W_PAR
        2,  // OUT_W_PAR
        2,  // IN_CH_PAR
        18  // OUT_CH_PAR
    > BandwidthAdjustIncreaseChannels_3;
    BandwidthAdjustIncreaseChannels_3.step_init(2);
    StreamingMemory <
        std::array<ap_uint<32>, 1>,  // TInput
        ap_int<15>,  // TOutput
        std::array<ap_int<15>, 4>,  // TOutputStruct
        2,  // DATA_PER_WORD
        830030,  // DATA_TO_SHIFT
        98,  // TIMES
        64,  // WORDS
        1,  // ARRAY_PAR
        4  // WORD_PAR
    > StreamingMemory_53;
    StreamingMemory_53.step_init(1);
    BandwidthAdjustDecreaseChannels <
        std::array<ap_uint<8>, 18>,  // TInputStruct
        ap_uint<8>,  // TInput
        std::array<ap_uint<8>, 9>,  // TOutputStruct
        ap_uint<8>,  // TOutput
        DequantQuantEqual<ap_uint<8>>,  // Quantizer
        56,  // IN_HEIGHT
        56,  // IN_WIDTH
        144,  // IN_CH
        2,  // IN_W_PAR
        2,  // OUT_W_PAR
        18,  // IN_CH_PAR
        9  // OUT_CH_PAR
    > BandwidthAdjustDecreaseChannels_1;
    BandwidthAdjustDecreaseChannels_1.step_init(2);
    StreamingMemory <
        std::array<ap_uint<32>, 1>,  // TInput
        ap_int<8>,  // TOutput
        std::array<ap_int<8>, 12>,  // TOutputStruct
        4,  // DATA_PER_WORD
        823886,  // DATA_TO_SHIFT
        98,  // TIMES
        24576,  // WORDS
        1,  // ARRAY_PAR
        12  // WORD_PAR
    > StreamingMemory_54;
    StreamingMemory_54.step_init(1);
    StreamingWindowSelector <
        std::array<ap_uint<8>, 9>,  // TWord
        56,  // IN_HEIGHT
        56,  // IN_WIDTH
        144,  // IN_CH
        1,  // FH
        1,  // FW
        1,  // STRIDE_H
        1,  // STRIDE_W
        1,  // DILATION_H
        1,  // DILATION_W
        0,  // PAD_T
        0,  // PAD_L
        0,  // PAD_B
        0,  // PAD_R
        0,  // POS_H
        1,  // POS_W
        2,  // W_PAR
        9  // CH_PAR
    > StreamingLineBuffer_8_pixel_0;
    StreamingLineBuffer_8_pixel_0.step_init(1, 1);
    StreamingWindowSelector <
        std::array<ap_uint<8>, 9>,  // TWord
        56,  // IN_HEIGHT
        56,  // IN_WIDTH
        144,  // IN_CH
        1,  // FH
        1,  // FW
        1,  // STRIDE_H
        1,  // STRIDE_W
        1,  // DILATION_H
        1,  // DILATION_W
        0,  // PAD_T
        0,  // PAD_L
        0,  // PAD_B
        0,  // PAD_R
        0,  // POS_H
        0,  // POS_W
        2,  // W_PAR
        9  // CH_PAR
    > StreamingLineBuffer_8_pixel_1;
    StreamingLineBuffer_8_pixel_1.step_init(1, 1);
    StreamingMemory <
        std::array<ap_uint<32>, 1>,  // TInput
        ap_int<14>,  // TOutput
        std::array<ap_int<14>, 3>,  // TOutputStruct
        2,  // DATA_PER_WORD
        823694,  // DATA_TO_SHIFT
        98,  // TIMES
        384,  // WORDS
        1,  // ARRAY_PAR
        3  // WORD_PAR
    > StreamingMemory_55;
    StreamingMemory_55.step_init(1);
    StreamingConv <
        std::array<ap_uint<8>, 9>,  // TInputWord
        ap_uint<8>,  // TInput
        std::array<ap_int<8>, 27>,  // TWeightWord
        ap_int<8>,  // TWeight
        std::array<ap_int<15>, 3>,  // TBiasWord
        ap_int<15>,  // TBias
        std::array<ap_int<8>, 3>,  // TOutputWord
        ap_int<8>,  // TOutput
        ap_int<26>,  // TSum
        ap_int<25>,  // TPartialSum
        DequantQuantEqual<ap_int<26>>,  // Activation
        DequantQuantPo2<9, ap_int<26>, ap_int<8>>,  // Quantizer
        24,  // OUT_CH
        144,  // IN_CH
        56,  // OUT_HEIGHT
        56,  // OUT_WIDTH
        1,  // GROUP
        1,  // FH
        1,  // FW
        1,  // STRIDE_H
        1,  // STRIDE_W
        9,  // IN_CH_PAR
        3,  // OUT_CH_PAR
        2  // W_PAR
    > StreamingConv_5;
    StreamingConv_5.step_init(10);
    StreamingMemory <
        std::array<ap_uint<32>, 1>,  // TInput
        ap_int<8>,  // TOutput
        std::array<ap_int<8>, 1>,  // TOutputStruct
        4,  // DATA_PER_WORD
        822830,  // DATA_TO_SHIFT
        98,  // TIMES
        3456,  // WORDS
        9,  // ARRAY_PAR
        1  // WORD_PAR
    > StreamingMemory_56;
    StreamingMemory_56.step_init(1);
    StreamingAdd <
        std::array<ap_int<8>, 3>,  // TInputWordA
        ap_int<8>,  // TInputA
        std::array<ap_int<8>, 3>,  // TInputWordB
        ap_int<8>,  // TInputB
        std::array<ap_int<8>, 3>,  // TOutputWord
        ap_int<8>,  // TOutput
        ap_int<9>,  // TAcc
        DequantQuantEqual<ap_int<9>>,  // Activation
        DequantQuantPo2<0, ap_int<9>, ap_int<8>>,  // Quantizer
        DequantQuantEqual<ap_int<8>>,  // AlignA
        DequantQuantEqual<ap_int<8>>,  // AlignB
        56,  // IN_HEIGHT
        56,  // IN_WIDTH
        24,  // IN_CH
        2,  // W_PAR
        3  // CH_PAR
    > StreamingAdd_0;
    StreamingAdd_0.step_init(2);
    StreamingMemory <
        std::array<ap_uint<32>, 1>,  // TInput
        ap_int<14>,  // TOutput
        std::array<ap_int<14>, 1>,  // TOutputStruct
        2,  // DATA_PER_WORD
        822638,  // DATA_TO_SHIFT
        98,  // TIMES
        384,  // WORDS
        1,  // ARRAY_PAR
        1  // WORD_PAR
    > StreamingMemory_57;
    StreamingMemory_57.step_init(1);
    BandwidthAdjustDecreaseChannels <
        std::array<ap_int<8>, 3>,  // TInputStruct
        ap_int<8>,  // TInput
        std::array<ap_int<8>, 1>,  // TOutputStruct
        ap_int<8>,  // TOutput
        DequantQuantEqual<ap_int<8>>,  // Quantizer
        56,  // IN_HEIGHT
        56,  // IN_WIDTH
        24,  // IN_CH
        2,  // IN_W_PAR
        2,  // OUT_W_PAR
        3,  // IN_CH_PAR
        1  // OUT_CH_PAR
    > BandwidthAdjustDecreaseChannels_2;
    BandwidthAdjustDecreaseChannels_2.step_init(2);
    StreamingMemory <
        std::array<ap_uint<32>, 1>,  // TInput
        ap_int<8>,  // TOutput
        std::array<ap_int<8>, 12>,  // TOutputStruct
        4,  // DATA_PER_WORD
        816494,  // DATA_TO_SHIFT
        98,  // TIMES
        24576,  // WORDS
        1,  // ARRAY_PAR
        12  // WORD_PAR
    > StreamingMemory_58;
    StreamingMemory_58.step_init(1);
    BandwidthAdjustIncreaseChannels <
        std::array<ap_int<8>, 1>,  // TInputStruct
        ap_int<8>,  // TInput
        std::array<ap_int<8>, 8>,  // TOutputStruct
        ap_int<8>,  // TOutput
        DequantQuantEqual<ap_int<8>>,  // Quantizer
        56,  // IN_HEIGHT
        56,  // IN_WIDTH
        24,  // IN_CH
        2,  // IN_W_PAR
        2,  // OUT_W_PAR
        1,  // IN_CH_PAR
        8  // OUT_CH_PAR
    > BandwidthAdjustIncreaseChannels_4;
    BandwidthAdjustIncreaseChannels_4.step_init(2);
    StreamingMemory <
        std::array<ap_uint<32>, 1>,  // TInput
        ap_int<15>,  // TOutput
        std::array<ap_int<15>, 4>,  // TOutputStruct
        2,  // DATA_PER_WORD
        816462,  // DATA_TO_SHIFT
        98,  // TIMES
        64,  // WORDS
        1,  // ARRAY_PAR
        4  // WORD_PAR
    > StreamingMemory_59;
    StreamingMemory_59.step_init(1);
    BandwidthAdjustIncreaseStreams <
        std::array<ap_int<8>, 8>,  // TInputStruct
        ap_int<8>,  // TInput
        std::array<ap_int<8>, 8>,  // TOutputStruct
        ap_int<8>,  // TOutput
        DequantQuantEqual<ap_int<8>>,  // Quantizer
        56,  // IN_HEIGHT
        56,  // IN_WIDTH
        24,  // IN_CH
        2,  // IN_W_PAR
        4,  // OUT_W_PAR
        8,  // IN_CH_PAR
        8  // OUT_CH_PAR
    > BandwidthAdjustIncreaseStreams_1;
    BandwidthAdjustIncreaseStreams_1.step_init(1);
    StreamingMemory <
        std::array<ap_uint<32>, 1>,  // TInput
        ap_int<8>,  // TOutput
        std::array<ap_int<8>, 12>,  // TOutputStruct
        4,  // DATA_PER_WORD
        810318,  // DATA_TO_SHIFT
        98,  // TIMES
        24576,  // WORDS
        1,  // ARRAY_PAR
        12  // WORD_PAR
    > StreamingMemory_60;
    StreamingMemory_60.step_init(1);
    StreamingWindowSelector <
        std::array<ap_int<8>, 8>,  // TWord
        56,  // IN_HEIGHT
        56,  // IN_WIDTH
        24,  // IN_CH
        1,  // FH
        1,  // FW
        1,  // STRIDE_H
        1,  // STRIDE_W
        1,  // DILATION_H
        1,  // DILATION_W
        0,  // PAD_T
        0,  // PAD_L
        0,  // PAD_B
        0,  // PAD_R
        0,  // POS_H
        3,  // POS_W
        4,  // W_PAR
        8  // CH_PAR
    > StreamingLineBuffer_9_pixel_0;
    StreamingLineBuffer_9_pixel_0.step_init(1, 1);
    StreamingWindowSelector <
        std::array<ap_int<8>, 8>,  // TWord
        56,  // IN_HEIGHT
        56,  // IN_WIDTH
        24,  // IN_CH
        1,  // FH
        1,  // FW
        1,  // STRIDE_H
        1,  // STRIDE_W
        1,  // DILATION_H
        1,  // DILATION_W
        0,  // PAD_T
        0,  // PAD_L
        0,  // PAD_B
        0,  // PAD_R
        0,  // POS_H
        2,  // POS_W
        4,  // W_PAR
        8  // CH_PAR
    > StreamingLineBuffer_9_pixel_1;
    StreamingLineBuffer_9_pixel_1.step_init(1, 1);
    StreamingWindowSelector <
        std::array<ap_int<8>, 8>,  // TWord
        56,  // IN_HEIGHT
        56,  // IN_WIDTH
        24,  // IN_CH
        1,  // FH
        1,  // FW
        1,  // STRIDE_H
        1,  // STRIDE_W
        1,  // DILATION_H
        1,  // DILATION_W
        0,  // PAD_T
        0,  // PAD_L
        0,  // PAD_B
        0,  // PAD_R
        0,  // POS_H
        1,  // POS_W
        4,  // W_PAR
        8  // CH_PAR
    > StreamingLineBuffer_9_pixel_2;
    StreamingLineBuffer_9_pixel_2.step_init(1, 1);
    StreamingWindowSelector <
        std::array<ap_int<8>, 8>,  // TWord
        56,  // IN_HEIGHT
        56,  // IN_WIDTH
        24,  // IN_CH
        1,  // FH
        1,  // FW
        1,  // STRIDE_H
        1,  // STRIDE_W
        1,  // DILATION_H
        1,  // DILATION_W
        0,  // PAD_T
        0,  // PAD_L
        0,  // PAD_B
        0,  // PAD_R
        0,  // POS_H
        0,  // POS_W
        4,  // W_PAR
        8  // CH_PAR
    > StreamingLineBuffer_9_pixel_3;
    StreamingLineBuffer_9_pixel_3.step_init(1, 1);
    StreamingMemory <
        std::array<ap_uint<32>, 1>,  // TInput
        ap_int<14>,  // TOutput
        std::array<ap_int<14>, 3>,  // TOutputStruct
        2,  // DATA_PER_WORD
        810126,  // DATA_TO_SHIFT
        98,  // TIMES
        384,  // WORDS
        1,  // ARRAY_PAR
        3  // WORD_PAR
    > StreamingMemory_61;
    StreamingMemory_61.step_init(1);
    StreamingConv <
        std::array<ap_int<8>, 8>,  // TInputWord
        ap_int<8>,  // TInput
        std::array<ap_int<8>, 16>,  // TWeightWord
        ap_int<8>,  // TWeight
        std::array<ap_int<13>, 2>,  // TBiasWord
        ap_int<13>,  // TBias
        std::array<ap_uint<8>, 2>,  // TOutputWord
        ap_uint<8>,  // TOutput
        ap_int<22>,  // TSum
        ap_int<21>,  // TPartialSum
        ReLU<ap_int<22>>,  // Activation
        DequantQuantPo2<6, ap_int<22>, ap_uint<8>>,  // Quantizer
        144,  // OUT_CH
        24,  // IN_CH
        56,  // OUT_HEIGHT
        56,  // OUT_WIDTH
        1,  // GROUP
        1,  // FH
        1,  // FW
        1,  // STRIDE_H
        1,  // STRIDE_W
        8,  // IN_CH_PAR
        2,  // OUT_CH_PAR
        4  // W_PAR
    > StreamingConv_6;
    StreamingConv_6.step_init(10);
    StreamingMemory <
        std::array<ap_uint<32>, 1>,  // TInput
        ap_int<8>,  // TOutput
        std::array<ap_int<8>, 1>,  // TOutputStruct
        4,  // DATA_PER_WORD
        809262,  // DATA_TO_SHIFT
        98,  // TIMES
        3456,  // WORDS
        9,  // ARRAY_PAR
        1  // WORD_PAR
    > StreamingMemory_62;
    StreamingMemory_62.step_init(1);
    BandwidthAdjustDecreaseStreams <
        std::array<ap_uint<8>, 2>,  // TInputStruct
        ap_uint<8>,  // TInput
        std::array<ap_uint<8>, 2>,  // TOutputStruct
        ap_uint<8>,  // TOutput
        DequantQuantEqual<ap_uint<8>>,  // Quantizer
        56,  // IN_HEIGHT
        56,  // IN_WIDTH
        144,  // IN_CH
        4,  // IN_W_PAR
        2,  // OUT_W_PAR
        2,  // IN_CH_PAR
        2  // OUT_CH_PAR
    > BandwidthAdjustDecreaseStreams_2;
    BandwidthAdjustDecreaseStreams_2.step_init(2);
    StreamingMemory <
        std::array<ap_uint<32>, 1>,  // TInput
        ap_int<15>,  // TOutput
        std::array<ap_int<15>, 1>,  // TOutputStruct
        2,  // DATA_PER_WORD
        809070,  // DATA_TO_SHIFT
        98,  // TIMES
        384,  // WORDS
        1,  // ARRAY_PAR
        1  // WORD_PAR
    > StreamingMemory_63;
    StreamingMemory_63.step_init(1);
    StreamingWindowSelector <
        std::array<ap_uint<8>, 2>,  // TWord
        56,  // IN_HEIGHT
        56,  // IN_WIDTH
        144,  // IN_CH
        3,  // FH
        3,  // FW
        2,  // STRIDE_H
        2,  // STRIDE_W
        1,  // DILATION_H
        1,  // DILATION_W
        1,  // PAD_T
        1,  // PAD_L
        1,  // PAD_B
        1,  // PAD_R
        2,  // POS_H
        4,  // POS_W
        2,  // W_PAR
        2  // CH_PAR
    > StreamingLineBuffer_10_pixel_0;
    StreamingLineBuffer_10_pixel_0.step_init(2, 1);
    StreamingWindowSelector <
        std::array<ap_uint<8>, 2>,  // TWord
        56,  // IN_HEIGHT
        56,  // IN_WIDTH
        144,  // IN_CH
        3,  // FH
        3,  // FW
        2,  // STRIDE_H
        2,  // STRIDE_W
        1,  // DILATION_H
        1,  // DILATION_W
        1,  // PAD_T
        1,  // PAD_L
        1,  // PAD_B
        1,  // PAD_R
        2,  // POS_H
        3,  // POS_W
        2,  // W_PAR
        2  // CH_PAR
    > StreamingLineBuffer_10_pixel_1;
    StreamingLineBuffer_10_pixel_1.step_init(2, 1);
    StreamingMemory <
        std::array<ap_uint<32>, 1>,  // TInput
        ap_int<8>,  // TOutput
        std::array<ap_int<8>, 18>,  // TOutputStruct
        4,  // DATA_PER_WORD
        799854,  // DATA_TO_SHIFT
        98,  // TIMES
        36864,  // WORDS
        1,  // ARRAY_PAR
        18  // WORD_PAR
    > StreamingMemory_64;
    StreamingMemory_64.step_init(1);
    StreamingWindowSelector <
        std::array<ap_uint<8>, 2>,  // TWord
        56,  // IN_HEIGHT
        56,  // IN_WIDTH
        144,  // IN_CH
        3,  // FH
        3,  // FW
        2,  // STRIDE_H
        2,  // STRIDE_W
        1,  // DILATION_H
        1,  // DILATION_W
        1,  // PAD_T
        1,  // PAD_L
        1,  // PAD_B
        1,  // PAD_R
        2,  // POS_H
        2,  // POS_W
        2,  // W_PAR
        2  // CH_PAR
    > StreamingLineBuffer_10_pixel_2;
    StreamingLineBuffer_10_pixel_2.step_init(2, 73);
    StreamingWindowSelector <
        std::array<ap_uint<8>, 2>,  // TWord
        56,  // IN_HEIGHT
        56,  // IN_WIDTH
        144,  // IN_CH
        3,  // FH
        3,  // FW
        2,  // STRIDE_H
        2,  // STRIDE_W
        1,  // DILATION_H
        1,  // DILATION_W
        1,  // PAD_T
        1,  // PAD_L
        1,  // PAD_B
        1,  // PAD_R
        2,  // POS_H
        1,  // POS_W
        2,  // W_PAR
        2  // CH_PAR
    > StreamingLineBuffer_10_pixel_3;
    StreamingLineBuffer_10_pixel_3.step_init(2, 73);
    StreamingMemory <
        std::array<ap_uint<32>, 1>,  // TInput
        ap_int<16>,  // TOutput
        std::array<ap_int<16>, 3>,  // TOutputStruct
        2,  // DATA_PER_WORD
        799806,  // DATA_TO_SHIFT
        98,  // TIMES
        96,  // WORDS
        1,  // ARRAY_PAR
        3  // WORD_PAR
    > StreamingMemory_65;
    StreamingMemory_65.step_init(1);
    StreamingWindowSelector <
        std::array<ap_uint<8>, 2>,  // TWord
        56,  // IN_HEIGHT
        56,  // IN_WIDTH
        144,  // IN_CH
        3,  // FH
        3,  // FW
        2,  // STRIDE_H
        2,  // STRIDE_W
        1,  // DILATION_H
        1,  // DILATION_W
        1,  // PAD_T
        1,  // PAD_L
        1,  // PAD_B
        1,  // PAD_R
        2,  // POS_H
        0,  // POS_W
        2,  // W_PAR
        2  // CH_PAR
    > StreamingLineBuffer_10_pixel_4;
    StreamingLineBuffer_10_pixel_4.step_init(2, 73);
    StreamingWindowSelector <
        std::array<ap_uint<8>, 2>,  // TWord
        56,  // IN_HEIGHT
        56,  // IN_WIDTH
        144,  // IN_CH
        3,  // FH
        3,  // FW
        2,  // STRIDE_H
        2,  // STRIDE_W
        1,  // DILATION_H
        1,  // DILATION_W
        1,  // PAD_T
        1,  // PAD_L
        1,  // PAD_B
        1,  // PAD_R
        1,  // POS_H
        3,  // POS_W
        2,  // W_PAR
        2  // CH_PAR
    > StreamingLineBuffer_10_pixel_6;
    StreamingLineBuffer_10_pixel_6.step_init(2, 1873);
    StreamingMemory <
        std::array<ap_uint<32>, 1>,  // TInput
        ap_int<8>,  // TOutput
        std::array<ap_int<8>, 64>,  // TOutputStruct
        4,  // DATA_PER_WORD
        785982,  // DATA_TO_SHIFT
        196,  // TIMES
        55296,  // WORDS
        1,  // ARRAY_PAR
        64  // WORD_PAR
    > StreamingMemory_66;
    StreamingMemory_66.step_init(1);
    StreamingWindowSelector <
        std::array<ap_uint<8>, 2>,  // TWord
        56,  // IN_HEIGHT
        56,  // IN_WIDTH
        144,  // IN_CH
        3,  // FH
        3,  // FW
        2,  // STRIDE_H
        2,  // STRIDE_W
        1,  // DILATION_H
        1,  // DILATION_W
        1,  // PAD_T
        1,  // PAD_L
        1,  // PAD_B
        1,  // PAD_R
        1,  // POS_H
        4,  // POS_W
        2,  // W_PAR
        2  // CH_PAR
    > StreamingLineBuffer_10_pixel_5;
    StreamingLineBuffer_10_pixel_5.step_init(2, 1945);
    StreamingWindowSelector <
        std::array<ap_uint<8>, 2>,  // TWord
        56,  // IN_HEIGHT
        56,  // IN_WIDTH
        144,  // IN_CH
        3,  // FH
        3,  // FW
        2,  // STRIDE_H
        2,  // STRIDE_W
        1,  // DILATION_H
        1,  // DILATION_W
        1,  // PAD_T
        1,  // PAD_L
        1,  // PAD_B
        1,  // PAD_R
        1,  // POS_H
        1,  // POS_W
        2,  // W_PAR
        2  // CH_PAR
    > StreamingLineBuffer_10_pixel_8;
    StreamingLineBuffer_10_pixel_8.step_init(2, 73);
    StreamingMemory <
        std::array<ap_uint<32>, 1>,  // TInput
        ap_int<14>,  // TOutput
        std::array<ap_int<14>, 2>,  // TOutputStruct
        2,  // DATA_PER_WORD
        785694,  // DATA_TO_SHIFT
        196,  // TIMES
        576,  // WORDS
        1,  // ARRAY_PAR
        2  // WORD_PAR
    > StreamingMemory_67;
    StreamingMemory_67.step_init(1);
    StreamingWindowSelector <
        std::array<ap_uint<8>, 2>,  // TWord
        56,  // IN_HEIGHT
        56,  // IN_WIDTH
        144,  // IN_CH
        3,  // FH
        3,  // FW
        2,  // STRIDE_H
        2,  // STRIDE_W
        1,  // DILATION_H
        1,  // DILATION_W
        1,  // PAD_T
        1,  // PAD_L
        1,  // PAD_B
        1,  // PAD_R
        1,  // POS_H
        2,  // POS_W
        2,  // W_PAR
        2  // CH_PAR
    > StreamingLineBuffer_10_pixel_7;
    StreamingLineBuffer_10_pixel_7.step_init(2, 73);
    StreamingWindowSelector <
        std::array<ap_uint<8>, 2>,  // TWord
        56,  // IN_HEIGHT
        56,  // IN_WIDTH
        144,  // IN_CH
        3,  // FH
        3,  // FW
        2,  // STRIDE_H
        2,  // STRIDE_W
        1,  // DILATION_H
        1,  // DILATION_W
        1,  // PAD_T
        1,  // PAD_L
        1,  // PAD_B
        1,  // PAD_R
        0,  // POS_H
        3,  // POS_W
        2,  // W_PAR
        2  // CH_PAR
    > StreamingLineBuffer_10_pixel_11;
    StreamingLineBuffer_10_pixel_11.step_init(2, 1873);
    StreamingMemory <
        std::array<ap_uint<32>, 1>,  // TInput
        ap_int<8>,  // TOutput
        std::array<ap_int<8>, 1>,  // TOutputStruct
        4,  // DATA_PER_WORD
        784398,  // DATA_TO_SHIFT
        196,  // TIMES
        5184,  // WORDS
        9,  // ARRAY_PAR
        1  // WORD_PAR
    > StreamingMemory_68;
    StreamingMemory_68.step_init(1);
    StreamingWindowSelector <
        std::array<ap_uint<8>, 2>,  // TWord
        56,  // IN_HEIGHT
        56,  // IN_WIDTH
        144,  // IN_CH
        3,  // FH
        3,  // FW
        2,  // STRIDE_H
        2,  // STRIDE_W
        1,  // DILATION_H
        1,  // DILATION_W
        1,  // PAD_T
        1,  // PAD_L
        1,  // PAD_B
        1,  // PAD_R
        1,  // POS_H
        0,  // POS_W
        2,  // W_PAR
        2  // CH_PAR
    > StreamingLineBuffer_10_pixel_9;
    StreamingLineBuffer_10_pixel_9.step_init(2, 73);
    StreamingWindowSelector <
        std::array<ap_uint<8>, 2>,  // TWord
        56,  // IN_HEIGHT
        56,  // IN_WIDTH
        144,  // IN_CH
        3,  // FH
        3,  // FW
        2,  // STRIDE_H
        2,  // STRIDE_W
        1,  // DILATION_H
        1,  // DILATION_W
        1,  // PAD_T
        1,  // PAD_L
        1,  // PAD_B
        1,  // PAD_R
        0,  // POS_H
        1,  // POS_W
        2,  // W_PAR
        2  // CH_PAR
    > StreamingLineBuffer_10_pixel_13;
    StreamingLineBuffer_10_pixel_13.step_init(1, 73);
    StreamingMemory <
        std::array<ap_uint<32>, 1>,  // TInput
        ap_int<15>,  // TOutput
        std::array<ap_int<15>, 1>,  // TOutputStruct
        2,  // DATA_PER_WORD
        784110,  // DATA_TO_SHIFT
        196,  // TIMES
        576,  // WORDS
        1,  // ARRAY_PAR
        1  // WORD_PAR
    > StreamingMemory_69;
    StreamingMemory_69.step_init(1);
    StreamingWindowSelector <
        std::array<ap_uint<8>, 2>,  // TWord
        56,  // IN_HEIGHT
        56,  // IN_WIDTH
        144,  // IN_CH
        3,  // FH
        3,  // FW
        2,  // STRIDE_H
        2,  // STRIDE_W
        1,  // DILATION_H
        1,  // DILATION_W
        1,  // PAD_T
        1,  // PAD_L
        1,  // PAD_B
        1,  // PAD_R
        0,  // POS_H
        4,  // POS_W
        2,  // W_PAR
        2  // CH_PAR
    > StreamingLineBuffer_10_pixel_10;
    StreamingLineBuffer_10_pixel_10.step_init(2, 1945);
    StreamingMemory <
        std::array<ap_uint<32>, 1>,  // TInput
        ap_int<8>,  // TOutput
        std::array<ap_int<8>, 27>,  // TOutputStruct
        4,  // DATA_PER_WORD
        770286,  // DATA_TO_SHIFT
        98,  // TIMES
        55296,  // WORDS
        1,  // ARRAY_PAR
        27  // WORD_PAR
    > StreamingMemory_70;
    StreamingMemory_70.step_init(1);
    StreamingWindowSelector <
        std::array<ap_uint<8>, 2>,  // TWord
        56,  // IN_HEIGHT
        56,  // IN_WIDTH
        144,  // IN_CH
        3,  // FH
        3,  // FW
        2,  // STRIDE_H
        2,  // STRIDE_W
        1,  // DILATION_H
        1,  // DILATION_W
        1,  // PAD_T
        1,  // PAD_L
        1,  // PAD_B
        1,  // PAD_R
        0,  // POS_H
        2,  // POS_W
        2,  // W_PAR
        2  // CH_PAR
    > StreamingLineBuffer_10_pixel_12;
    StreamingLineBuffer_10_pixel_12.step_init(2, 73);
    StreamingMemory <
        std::array<ap_uint<32>, 1>,  // TInput
        ap_int<15>,  // TOutput
        std::array<ap_int<15>, 3>,  // TOutputStruct
        2,  // DATA_PER_WORD
        770238,  // DATA_TO_SHIFT
        98,  // TIMES
        96,  // WORDS
        1,  // ARRAY_PAR
        3  // WORD_PAR
    > StreamingMemory_71;
    StreamingMemory_71.step_init(1);
    StreamingWindowSelector <
        std::array<ap_uint<8>, 2>,  // TWord
        56,  // IN_HEIGHT
        56,  // IN_WIDTH
        144,  // IN_CH
        3,  // FH
        3,  // FW
        2,  // STRIDE_H
        2,  // STRIDE_W
        1,  // DILATION_H
        1,  // DILATION_W
        1,  // PAD_T
        1,  // PAD_L
        1,  // PAD_B
        1,  // PAD_R
        0,  // POS_H
        0,  // POS_W
        2,  // W_PAR
        2  // CH_PAR
    > StreamingLineBuffer_10_pixel_14;
    StreamingLineBuffer_10_pixel_14.step_init(1, 73);
    StreamingMemory <
        std::array<ap_uint<32>, 1>,  // TInput
        ap_int<8>,  // TOutput
        std::array<ap_int<8>, 64>,  // TOutputStruct
        4,  // DATA_PER_WORD
        756414,  // DATA_TO_SHIFT
        196,  // TIMES
        55296,  // WORDS
        1,  // ARRAY_PAR
        64  // WORD_PAR
    > StreamingMemory_72;
    StreamingMemory_72.step_init(1);
    StreamingPad <
        std::array<ap_uint<8>, 2>,  // TWord
        ap_uint<8>,  // TData
        56,  // IN_HEIGHT
        56,  // IN_WIDTH
        144,  // IN_CH
        3,  // FH
        3,  // FW
        2,  // STRIDE_H
        2,  // STRIDE_W
        1,  // DILATION_H
        1,  // DILATION_W
        1,  // PAD_T
        1,  // PAD_L
        1,  // PAD_B
        1,  // PAD_R
        2,  // W_PAR
        2,  // CH_PAR
        0  // PAD_VALUE
    > StreamingLineBuffer_10_pad;
    StreamingLineBuffer_10_pad.step_init(3);
    StreamingMemory <
        std::array<ap_uint<32>, 1>,  // TInput
        ap_int<15>,  // TOutput
        std::array<ap_int<15>, 4>,  // TOutputStruct
        2,  // DATA_PER_WORD
        756126,  // DATA_TO_SHIFT
        196,  // TIMES
        576,  // WORDS
        1,  // ARRAY_PAR
        4  // WORD_PAR
    > StreamingMemory_73;
    StreamingMemory_73.step_init(1);
    StreamingDepthwiseConv <
        std::array<ap_uint<8>, 2>,  // TInputStruct
        ap_uint<8>,  // TInput
        std::array<ap_int<8>, 2>,  // TWeightStruct
        ap_int<8>,  // TWeight
        std::array<ap_int<15>, 2>,  // TBiasStruct
        ap_int<15>,  // TBias
        std::array<ap_uint<8>, 2>,  // TOutputStruct
        ap_uint<8>,  // TOutput
        ap_int<21>,  // TSum
        ap_int<20>,  // TPartialSum
        ReLU<ap_int<21>>,  // Activation
        DequantQuantPo2<7, ap_int<21>, ap_uint<8>>,  // Quantizer
        144,  // OUT_CH
        144,  // IN_CH
        28,  // IN_HEIGHT
        28,  // IN_WIDTH
        3,  // FH
        3,  // FW
        2,  // STRIDE_H
        2,  // STRIDE_W
        2,  // CH_PAR
        2  // W_PAR
    > StreamingDepthwiseConv_3;
    StreamingDepthwiseConv_3.step_init(8);
    StreamingMemory <
        std::array<ap_uint<32>, 1>,  // TInput
        ap_int<8>,  // TOutput
        std::array<ap_int<8>, 1>,  // TOutputStruct
        4,  // DATA_PER_WORD
        754830,  // DATA_TO_SHIFT
        196,  // TIMES
        5184,  // WORDS
        9,  // ARRAY_PAR
        1  // WORD_PAR
    > StreamingMemory_74;
    StreamingMemory_74.step_init(1);
    BandwidthAdjustDecreaseChannels <
        std::array<ap_uint<8>, 2>,  // TInputStruct
        ap_uint<8>,  // TInput
        std::array<ap_uint<8>, 1>,  // TOutputStruct
        ap_uint<8>,  // TOutput
        DequantQuantEqual<ap_uint<8>>,  // Quantizer
        28,  // IN_HEIGHT
        28,  // IN_WIDTH
        144,  // IN_CH
        2,  // IN_W_PAR
        2,  // OUT_W_PAR
        2,  // IN_CH_PAR
        1  // OUT_CH_PAR
    > BandwidthAdjustDecreaseChannels_3;
    BandwidthAdjustDecreaseChannels_3.step_init(2);
    StreamingMemory <
        std::array<ap_uint<32>, 1>,  // TInput
        ap_int<15>,  // TOutput
        std::array<ap_int<15>, 1>,  // TOutputStruct
        2,  // DATA_PER_WORD
        754542,  // DATA_TO_SHIFT
        196,  // TIMES
        576,  // WORDS
        1,  // ARRAY_PAR
        1  // WORD_PAR
    > StreamingMemory_75;
    StreamingMemory_75.step_init(1);
    BandwidthAdjustIncreaseChannels <
        std::array<ap_uint<8>, 1>,  // TInputStruct
        ap_uint<8>,  // TInput
        std::array<ap_uint<8>, 9>,  // TOutputStruct
        ap_uint<8>,  // TOutput
        DequantQuantEqual<ap_uint<8>>,  // Quantizer
        28,  // IN_HEIGHT
        28,  // IN_WIDTH
        144,  // IN_CH
        2,  // IN_W_PAR
        2,  // OUT_W_PAR
        1,  // IN_CH_PAR
        9  // OUT_CH_PAR
    > BandwidthAdjustIncreaseChannels_5;
    BandwidthAdjustIncreaseChannels_5.step_init(2);
    StreamingMemory <
        std::array<ap_uint<32>, 1>,  // TInput
        ap_int<8>,  // TOutput
        std::array<ap_int<8>, 27>,  // TOutputStruct
        4,  // DATA_PER_WORD
        740718,  // DATA_TO_SHIFT
        98,  // TIMES
        55296,  // WORDS
        1,  // ARRAY_PAR
        27  // WORD_PAR
    > StreamingMemory_76;
    StreamingMemory_76.step_init(1);
    StreamingWindowSelector <
        std::array<ap_uint<8>, 9>,  // TWord
        28,  // IN_HEIGHT
        28,  // IN_WIDTH
        144,  // IN_CH
        1,  // FH
        1,  // FW
        1,  // STRIDE_H
        1,  // STRIDE_W
        1,  // DILATION_H
        1,  // DILATION_W
        0,  // PAD_T
        0,  // PAD_L
        0,  // PAD_B
        0,  // PAD_R
        0,  // POS_H
        1,  // POS_W
        2,  // W_PAR
        9  // CH_PAR
    > StreamingLineBuffer_11_pixel_0;
    StreamingLineBuffer_11_pixel_0.step_init(1, 1);
    StreamingWindowSelector <
        std::array<ap_uint<8>, 9>,  // TWord
        28,  // IN_HEIGHT
        28,  // IN_WIDTH
        144,  // IN_CH
        1,  // FH
        1,  // FW
        1,  // STRIDE_H
        1,  // STRIDE_W
        1,  // DILATION_H
        1,  // DILATION_W
        0,  // PAD_T
        0,  // PAD_L
        0,  // PAD_B
        0,  // PAD_R
        0,  // POS_H
        0,  // POS_W
        2,  // W_PAR
        9  // CH_PAR
    > StreamingLineBuffer_11_pixel_1;
    StreamingLineBuffer_11_pixel_1.step_init(1, 1);
    StreamingMemory <
        std::array<ap_uint<32>, 1>,  // TInput
        ap_int<15>,  // TOutput
        std::array<ap_int<15>, 3>,  // TOutputStruct
        2,  // DATA_PER_WORD
        740670,  // DATA_TO_SHIFT
        98,  // TIMES
        96,  // WORDS
        1,  // ARRAY_PAR
        3  // WORD_PAR
    > StreamingMemory_77;
    StreamingMemory_77.step_init(1);
    StreamingConv <
        std::array<ap_uint<8>, 9>,  // TInputWord
        ap_uint<8>,  // TInput
        std::array<ap_int<8>, 9>,  // TWeightWord
        ap_int<8>,  // TWeight
        std::array<ap_int<15>, 1>,  // TBiasWord
        ap_int<15>,  // TBias
        std::array<ap_int<8>, 1>,  // TOutputWord
        ap_int<8>,  // TOutput
        ap_int<26>,  // TSum
        ap_int<25>,  // TPartialSum
        DequantQuantEqual<ap_int<26>>,  // Activation
        DequantQuantPo2<7, ap_int<26>, ap_int<8>>,  // Quantizer
        32,  // OUT_CH
        144,  // IN_CH
        28,  // OUT_HEIGHT
        28,  // OUT_WIDTH
        1,  // GROUP
        1,  // FH
        1,  // FW
        1,  // STRIDE_H
        1,  // STRIDE_W
        9,  // IN_CH_PAR
        1,  // OUT_CH_PAR
        2  // W_PAR
    > StreamingConv_7;
    StreamingConv_7.step_init(10);
    StreamingMemory <
        std::array<ap_uint<32>, 1>,  // TInput
        ap_int<8>,  // TOutput
        std::array<ap_int<8>, 64>,  // TOutputStruct
        4,  // DATA_PER_WORD
        726846,  // DATA_TO_SHIFT
        196,  // TIMES
        55296,  // WORDS
        1,  // ARRAY_PAR
        64  // WORD_PAR
    > StreamingMemory_78;
    StreamingMemory_78.step_init(1);
    TensorDuplicator <
        std::array<ap_int<8>, 1>,  // TWord
        28,  // IN_HEIGHT
        28,  // IN_WIDTH
        32,  // IN_CH
        1,  // CH_PAR
        2  // W_PAR
    > TensorDuplicator_1;
    TensorDuplicator_1.step_init(1);
    StreamingMemory <
        std::array<ap_uint<32>, 1>,  // TInput
        ap_int<14>,  // TOutput
        std::array<ap_int<14>, 4>,  // TOutputStruct
        2,  // DATA_PER_WORD
        726558,  // DATA_TO_SHIFT
        196,  // TIMES
        576,  // WORDS
        1,  // ARRAY_PAR
        4  // WORD_PAR
    > StreamingMemory_79;
    StreamingMemory_79.step_init(1);
    BandwidthAdjustIncreaseChannels <
        std::array<ap_int<8>, 1>,  // TInputStruct
        ap_int<8>,  // TInput
        std::array<ap_int<8>, 4>,  // TOutputStruct
        ap_int<8>,  // TOutput
        DequantQuantEqual<ap_int<8>>,  // Quantizer
        28,  // IN_HEIGHT
        28,  // IN_WIDTH
        32,  // IN_CH
        2,  // IN_W_PAR
        2,  // OUT_W_PAR
        1,  // IN_CH_PAR
        4  // OUT_CH_PAR
    > BandwidthAdjustIncreaseChannels_6;
    BandwidthAdjustIncreaseChannels_6.step_init(2);
    BandwidthAdjustIncreaseChannels <
        std::array<ap_int<8>, 1>,  // TInputStruct
        ap_int<8>,  // TInput
        std::array<ap_int<8>, 4>,  // TOutputStruct
        ap_int<8>,  // TOutput
        DequantQuantEqual<ap_int<8>>,  // Quantizer
        28,  // IN_HEIGHT
        28,  // IN_WIDTH
        32,  // IN_CH
        2,  // IN_W_PAR
        2,  // OUT_W_PAR
        1,  // IN_CH_PAR
        4  // OUT_CH_PAR
    > BandwidthAdjustIncreaseChannels_7;
    BandwidthAdjustIncreaseChannels_7.step_init(2);
    StreamingMemory <
        std::array<ap_uint<32>, 1>,  // TInput
        ap_int<8>,  // TOutput
        std::array<ap_int<8>, 1>,  // TOutputStruct
        4,  // DATA_PER_WORD
        725262,  // DATA_TO_SHIFT
        49,  // TIMES
        5184,  // WORDS
        9,  // ARRAY_PAR
        1  // WORD_PAR
    > StreamingMemory_80;
    StreamingMemory_80.step_init(1);
    StreamingWindowSelector <
        std::array<ap_int<8>, 4>,  // TWord
        28,  // IN_HEIGHT
        28,  // IN_WIDTH
        32,  // IN_CH
        1,  // FH
        1,  // FW
        1,  // STRIDE_H
        1,  // STRIDE_W
        1,  // DILATION_H
        1,  // DILATION_W
        0,  // PAD_T
        0,  // PAD_L
        0,  // PAD_B
        0,  // PAD_R
        0,  // POS_H
        1,  // POS_W
        2,  // W_PAR
        4  // CH_PAR
    > StreamingLineBuffer_12_pixel_0;
    StreamingLineBuffer_12_pixel_0.step_init(1, 1);
    StreamingWindowSelector <
        std::array<ap_int<8>, 4>,  // TWord
        28,  // IN_HEIGHT
        28,  // IN_WIDTH
        32,  // IN_CH
        1,  // FH
        1,  // FW
        1,  // STRIDE_H
        1,  // STRIDE_W
        1,  // DILATION_H
        1,  // DILATION_W
        0,  // PAD_T
        0,  // PAD_L
        0,  // PAD_B
        0,  // PAD_R
        0,  // POS_H
        0,  // POS_W
        2,  // W_PAR
        4  // CH_PAR
    > StreamingLineBuffer_12_pixel_1;
    StreamingLineBuffer_12_pixel_1.step_init(1, 1);
    StreamingMemory <
        std::array<ap_uint<32>, 1>,  // TInput
        ap_int<15>,  // TOutput
        std::array<ap_int<15>, 1>,  // TOutputStruct
        2,  // DATA_PER_WORD
        724974,  // DATA_TO_SHIFT
        49,  // TIMES
        576,  // WORDS
        1,  // ARRAY_PAR
        1  // WORD_PAR
    > StreamingMemory_81;
    StreamingMemory_81.step_init(1);
    StreamingConv <
        std::array<ap_int<8>, 4>,  // TInputWord
        ap_int<8>,  // TInput
        std::array<ap_int<8>, 12>,  // TWeightWord
        ap_int<8>,  // TWeight
        std::array<ap_int<15>, 3>,  // TBiasWord
        ap_int<15>,  // TBias
        std::array<ap_uint<8>, 3>,  // TOutputWord
        ap_uint<8>,  // TOutput
        ap_int<23>,  // TSum
        ap_int<22>,  // TPartialSum
        ReLU<ap_int<23>>,  // Activation
        DequantQuantPo2<7, ap_int<23>, ap_uint<8>>,  // Quantizer
        192,  // OUT_CH
        32,  // IN_CH
        28,  // OUT_HEIGHT
        28,  // OUT_WIDTH
        1,  // GROUP
        1,  // FH
        1,  // FW
        1,  // STRIDE_H
        1,  // STRIDE_W
        4,  // IN_CH_PAR
        3,  // OUT_CH_PAR
        2  // W_PAR
    > StreamingConv_8;
    StreamingConv_8.step_init(9);
    StreamingMemory <
        std::array<ap_uint<32>, 1>,  // TInput
        ap_int<8>,  // TOutput
        std::array<ap_int<8>, 24>,  // TOutputStruct
        4,  // DATA_PER_WORD
        701934,  // DATA_TO_SHIFT
        49,  // TIMES
        92160,  // WORDS
        1,  // ARRAY_PAR
        24  // WORD_PAR
    > StreamingMemory_82;
    StreamingMemory_82.step_init(1);
    BandwidthAdjustDecreaseChannels <
        std::array<ap_uint<8>, 3>,  // TInputStruct
        ap_uint<8>,  // TInput
        std::array<ap_uint<8>, 1>,  // TOutputStruct
        ap_uint<8>,  // TOutput
        DequantQuantEqual<ap_uint<8>>,  // Quantizer
        28,  // IN_HEIGHT
        28,  // IN_WIDTH
        192,  // IN_CH
        2,  // IN_W_PAR
        2,  // OUT_W_PAR
        3,  // IN_CH_PAR
        1  // OUT_CH_PAR
    > BandwidthAdjustDecreaseChannels_4;
    BandwidthAdjustDecreaseChannels_4.step_init(2);
    StreamingMemory <
        std::array<ap_uint<32>, 1>,  // TInput
        ap_int<15>,  // TOutput
        std::array<ap_int<15>, 4>,  // TOutputStruct
        2,  // DATA_PER_WORD
        701854,  // DATA_TO_SHIFT
        49,  // TIMES
        160,  // WORDS
        1,  // ARRAY_PAR
        4  // WORD_PAR
    > StreamingMemory_83;
    StreamingMemory_83.step_init(1);
    StreamingWindowSelector <
        std::array<ap_uint<8>, 1>,  // TWord
        28,  // IN_HEIGHT
        28,  // IN_WIDTH
        192,  // IN_CH
        3,  // FH
        3,  // FW
        1,  // STRIDE_H
        1,  // STRIDE_W
        1,  // DILATION_H
        1,  // DILATION_W
        1,  // PAD_T
        1,  // PAD_L
        1,  // PAD_B
        1,  // PAD_R
        2,  // POS_H
        3,  // POS_W
        2,  // W_PAR
        1  // CH_PAR
    > StreamingLineBuffer_13_pixel_0;
    StreamingLineBuffer_13_pixel_0.step_init(2, 1);
    StreamingWindowSelector <
        std::array<ap_uint<8>, 1>,  // TWord
        28,  // IN_HEIGHT
        28,  // IN_WIDTH
        192,  // IN_CH
        3,  // FH
        3,  // FW
        1,  // STRIDE_H
        1,  // STRIDE_W
        1,  // DILATION_H
        1,  // DILATION_W
        1,  // PAD_T
        1,  // PAD_L
        1,  // PAD_B
        1,  // PAD_R
        2,  // POS_H
        2,  // POS_W
        2,  // W_PAR
        1  // CH_PAR
    > StreamingLineBuffer_13_pixel_1;
    StreamingLineBuffer_13_pixel_1.step_init(2, 1);
    StreamingMemory <
        std::array<ap_uint<32>, 1>,  // TInput
        ap_int<8>,  // TOutput
        std::array<ap_int<8>, 40>,  // TOutputStruct
        4,  // DATA_PER_WORD
        663454,  // DATA_TO_SHIFT
        49,  // TIMES
        153600,  // WORDS
        1,  // ARRAY_PAR
        40  // WORD_PAR
    > StreamingMemory_84;
    StreamingMemory_84.step_init(1);
    StreamingWindowSelector <
        std::array<ap_uint<8>, 1>,  // TWord
        28,  // IN_HEIGHT
        28,  // IN_WIDTH
        192,  // IN_CH
        3,  // FH
        3,  // FW
        1,  // STRIDE_H
        1,  // STRIDE_W
        1,  // DILATION_H
        1,  // DILATION_W
        1,  // PAD_T
        1,  // PAD_L
        1,  // PAD_B
        1,  // PAD_R
        2,  // POS_H
        1,  // POS_W
        2,  // W_PAR
        1  // CH_PAR
    > StreamingLineBuffer_13_pixel_2;
    StreamingLineBuffer_13_pixel_2.step_init(2, 193);
    StreamingWindowSelector <
        std::array<ap_uint<8>, 1>,  // TWord
        28,  // IN_HEIGHT
        28,  // IN_WIDTH
        192,  // IN_CH
        3,  // FH
        3,  // FW
        1,  // STRIDE_H
        1,  // STRIDE_W
        1,  // DILATION_H
        1,  // DILATION_W
        1,  // PAD_T
        1,  // PAD_L
        1,  // PAD_B
        1,  // PAD_R
        2,  // POS_H
        0,  // POS_W
        2,  // W_PAR
        1  // CH_PAR
    > StreamingLineBuffer_13_pixel_3;
    StreamingLineBuffer_13_pixel_3.step_init(2, 193);
    StreamingMemory <
        std::array<ap_uint<32>, 1>,  // TInput
        ap_int<15>,  // TOutput
        std::array<ap_int<15>, 4>,  // TOutputStruct
        2,  // DATA_PER_WORD
        662974,  // DATA_TO_SHIFT
        49,  // TIMES
        960,  // WORDS
        1,  // ARRAY_PAR
        4  // WORD_PAR
    > StreamingMemory_85;
    StreamingMemory_85.step_init(1);
    StreamingWindowSelector <
        std::array<ap_uint<8>, 1>,  // TWord
        28,  // IN_HEIGHT
        28,  // IN_WIDTH
        192,  // IN_CH
        3,  // FH
        3,  // FW
        1,  // STRIDE_H
        1,  // STRIDE_W
        1,  // DILATION_H
        1,  // DILATION_W
        1,  // PAD_T
        1,  // PAD_L
        1,  // PAD_B
        1,  // PAD_R
        1,  // POS_H
        3,  // POS_W
        2,  // W_PAR
        1  // CH_PAR
    > StreamingLineBuffer_13_pixel_4;
    StreamingLineBuffer_13_pixel_4.step_init(2, 2497);
    StreamingWindowSelector <
        std::array<ap_uint<8>, 1>,  // TWord
        28,  // IN_HEIGHT
        28,  // IN_WIDTH
        192,  // IN_CH
        3,  // FH
        3,  // FW
        1,  // STRIDE_H
        1,  // STRIDE_W
        1,  // DILATION_H
        1,  // DILATION_W
        1,  // PAD_T
        1,  // PAD_L
        1,  // PAD_B
        1,  // PAD_R
        1,  // POS_H
        2,  // POS_W
        2,  // W_PAR
        1  // CH_PAR
    > StreamingLineBuffer_13_pixel_5;
    StreamingLineBuffer_13_pixel_5.step_init(1, 2497);
    StreamingMemory <
        std::array<ap_uint<32>, 1>,  // TInput
        ap_int<8>,  // TOutput
        std::array<ap_int<8>, 1>,  // TOutputStruct
        4,  // DATA_PER_WORD
        660814,  // DATA_TO_SHIFT
        49,  // TIMES
        8640,  // WORDS
        9,  // ARRAY_PAR
        1  // WORD_PAR
    > StreamingMemory_86;
    StreamingMemory_86.step_init(1);
    StreamingWindowSelector <
        std::array<ap_uint<8>, 1>,  // TWord
        28,  // IN_HEIGHT
        28,  // IN_WIDTH
        192,  // IN_CH
        3,  // FH
        3,  // FW
        1,  // STRIDE_H
        1,  // STRIDE_W
        1,  // DILATION_H
        1,  // DILATION_W
        1,  // PAD_T
        1,  // PAD_L
        1,  // PAD_B
        1,  // PAD_R
        1,  // POS_H
        1,  // POS_W
        2,  // W_PAR
        1  // CH_PAR
    > StreamingLineBuffer_13_pixel_6;
    StreamingLineBuffer_13_pixel_6.step_init(1, 193);
    StreamingWindowSelector <
        std::array<ap_uint<8>, 1>,  // TWord
        28,  // IN_HEIGHT
        28,  // IN_WIDTH
        192,  // IN_CH
        3,  // FH
        3,  // FW
        1,  // STRIDE_H
        1,  // STRIDE_W
        1,  // DILATION_H
        1,  // DILATION_W
        1,  // PAD_T
        1,  // PAD_L
        1,  // PAD_B
        1,  // PAD_R
        1,  // POS_H
        0,  // POS_W
        2,  // W_PAR
        1  // CH_PAR
    > StreamingLineBuffer_13_pixel_7;
    StreamingLineBuffer_13_pixel_7.step_init(2, 193);
    StreamingMemory <
        std::array<ap_uint<32>, 1>,  // TInput
        ap_int<15>,  // TOutput
        std::array<ap_int<15>, 1>,  // TOutputStruct
        2,  // DATA_PER_WORD
        660334,  // DATA_TO_SHIFT
        49,  // TIMES
        960,  // WORDS
        1,  // ARRAY_PAR
        1  // WORD_PAR
    > StreamingMemory_87;
    StreamingMemory_87.step_init(1);
    StreamingWindowSelector <
        std::array<ap_uint<8>, 1>,  // TWord
        28,  // IN_HEIGHT
        28,  // IN_WIDTH
        192,  // IN_CH
        3,  // FH
        3,  // FW
        1,  // STRIDE_H
        1,  // STRIDE_W
        1,  // DILATION_H
        1,  // DILATION_W
        1,  // PAD_T
        1,  // PAD_L
        1,  // PAD_B
        1,  // PAD_R
        0,  // POS_H
        3,  // POS_W
        2,  // W_PAR
        1  // CH_PAR
    > StreamingLineBuffer_13_pixel_8;
    StreamingLineBuffer_13_pixel_8.step_init(2, 2497);
    StreamingWindowSelector <
        std::array<ap_uint<8>, 1>,  // TWord
        28,  // IN_HEIGHT
        28,  // IN_WIDTH
        192,  // IN_CH
        3,  // FH
        3,  // FW
        1,  // STRIDE_H
        1,  // STRIDE_W
        1,  // DILATION_H
        1,  // DILATION_W
        1,  // PAD_T
        1,  // PAD_L
        1,  // PAD_B
        1,  // PAD_R
        0,  // POS_H
        2,  // POS_W
        2,  // W_PAR
        1  // CH_PAR
    > StreamingLineBuffer_13_pixel_9;
    StreamingLineBuffer_13_pixel_9.step_init(2, 2497);
    StreamingMemory <
        std::array<ap_uint<32>, 1>,  // TInput
        ap_int<8>,  // TOutput
        std::array<ap_int<8>, 40>,  // TOutputStruct
        4,  // DATA_PER_WORD
        621934,  // DATA_TO_SHIFT
        49,  // TIMES
        153600,  // WORDS
        1,  // ARRAY_PAR
        40  // WORD_PAR
    > StreamingMemory_88;
    StreamingMemory_88.step_init(1);
    StreamingWindowSelector <
        std::array<ap_uint<8>, 1>,  // TWord
        28,  // IN_HEIGHT
        28,  // IN_WIDTH
        192,  // IN_CH
        3,  // FH
        3,  // FW
        1,  // STRIDE_H
        1,  // STRIDE_W
        1,  // DILATION_H
        1,  // DILATION_W
        1,  // PAD_T
        1,  // PAD_L
        1,  // PAD_B
        1,  // PAD_R
        0,  // POS_H
        1,  // POS_W
        2,  // W_PAR
        1  // CH_PAR
    > StreamingLineBuffer_13_pixel_10;
    StreamingLineBuffer_13_pixel_10.step_init(1, 193);
    StreamingWindowSelector <
        std::array<ap_uint<8>, 1>,  // TWord
        28,  // IN_HEIGHT
        28,  // IN_WIDTH
        192,  // IN_CH
        3,  // FH
        3,  // FW
        1,  // STRIDE_H
        1,  // STRIDE_W
        1,  // DILATION_H
        1,  // DILATION_W
        1,  // PAD_T
        1,  // PAD_L
        1,  // PAD_B
        1,  // PAD_R
        0,  // POS_H
        0,  // POS_W
        2,  // W_PAR
        1  // CH_PAR
    > StreamingLineBuffer_13_pixel_11;
    StreamingLineBuffer_13_pixel_11.step_init(1, 193);
    StreamingMemory <
        std::array<ap_uint<32>, 1>,  // TInput
        ap_int<16>,  // TOutput
        std::array<ap_int<16>, 2>,  // TOutputStruct
        2,  // DATA_PER_WORD
        621854,  // DATA_TO_SHIFT
        49,  // TIMES
        160,  // WORDS
        1,  // ARRAY_PAR
        2  // WORD_PAR
    > StreamingMemory_89;
    StreamingMemory_89.step_init(1);
    StreamingPad <
        std::array<ap_uint<8>, 1>,  // TWord
        ap_uint<8>,  // TData
        28,  // IN_HEIGHT
        28,  // IN_WIDTH
        192,  // IN_CH
        3,  // FH
        3,  // FW
        1,  // STRIDE_H
        1,  // STRIDE_W
        1,  // DILATION_H
        1,  // DILATION_W
        1,  // PAD_T
        1,  // PAD_L
        1,  // PAD_B
        1,  // PAD_R
        2,  // W_PAR
        1,  // CH_PAR
        0  // PAD_VALUE
    > StreamingLineBuffer_13_pad;
    StreamingLineBuffer_13_pad.step_init(3);
    StreamingMemory <
        std::array<ap_uint<32>, 1>,  // TInput
        ap_int<8>,  // TOutput
        std::array<ap_int<8>, 40>,  // TOutputStruct
        4,  // DATA_PER_WORD
        583454,  // DATA_TO_SHIFT
        49,  // TIMES
        153600,  // WORDS
        1,  // ARRAY_PAR
        40  // WORD_PAR
    > StreamingMemory_90;
    StreamingMemory_90.step_init(1);
    StreamingDepthwiseConv <
        std::array<ap_uint<8>, 1>,  // TInputStruct
        ap_uint<8>,  // TInput
        std::array<ap_int<8>, 1>,  // TWeightStruct
        ap_int<8>,  // TWeight
        std::array<ap_int<14>, 1>,  // TBiasStruct
        ap_int<14>,  // TBias
        std::array<ap_uint<8>, 1>,  // TOutputStruct
        ap_uint<8>,  // TOutput
        ap_int<21>,  // TSum
        ap_int<20>,  // TPartialSum
        ReLU<ap_int<21>>,  // Activation
        DequantQuantPo2<6, ap_int<21>, ap_uint<8>>,  // Quantizer
        192,  // OUT_CH
        192,  // IN_CH
        28,  // IN_HEIGHT
        28,  // IN_WIDTH
        3,  // FH
        3,  // FW
        1,  // STRIDE_H
        1,  // STRIDE_W
        1,  // CH_PAR
        2  // W_PAR
    > StreamingDepthwiseConv_4;
    StreamingDepthwiseConv_4.step_init(8);
    StreamingMemory <
        std::array<ap_uint<32>, 1>,  // TInput
        ap_int<13>,  // TOutput
        std::array<ap_int<13>, 2>,  // TOutputStruct
        2,  // DATA_PER_WORD
        582974,  // DATA_TO_SHIFT
        49,  // TIMES
        960,  // WORDS
        1,  // ARRAY_PAR
        2  // WORD_PAR
    > StreamingMemory_91;
    StreamingMemory_91.step_init(1);
    BandwidthAdjustIncreaseChannels <
        std::array<ap_uint<8>, 1>,  // TInputStruct
        ap_uint<8>,  // TInput
        std::array<ap_uint<8>, 3>,  // TOutputStruct
        ap_uint<8>,  // TOutput
        DequantQuantEqual<ap_uint<8>>,  // Quantizer
        28,  // IN_HEIGHT
        28,  // IN_WIDTH
        192,  // IN_CH
        2,  // IN_W_PAR
        2,  // OUT_W_PAR
        1,  // IN_CH_PAR
        3  // OUT_CH_PAR
    > BandwidthAdjustIncreaseChannels_8;
    BandwidthAdjustIncreaseChannels_8.step_init(2);
    StreamingMemory <
        std::array<ap_uint<32>, 1>,  // TInput
        ap_int<8>,  // TOutput
        std::array<ap_int<8>, 1>,  // TOutputStruct
        4,  // DATA_PER_WORD
        580814,  // DATA_TO_SHIFT
        49,  // TIMES
        8640,  // WORDS
        9,  // ARRAY_PAR
        1  // WORD_PAR
    > StreamingMemory_92;
    StreamingMemory_92.step_init(1);
    StreamingWindowSelector <
        std::array<ap_uint<8>, 3>,  // TWord
        28,  // IN_HEIGHT
        28,  // IN_WIDTH
        192,  // IN_CH
        1,  // FH
        1,  // FW
        1,  // STRIDE_H
        1,  // STRIDE_W
        1,  // DILATION_H
        1,  // DILATION_W
        0,  // PAD_T
        0,  // PAD_L
        0,  // PAD_B
        0,  // PAD_R
        0,  // POS_H
        1,  // POS_W
        2,  // W_PAR
        3  // CH_PAR
    > StreamingLineBuffer_14_pixel_0;
    StreamingLineBuffer_14_pixel_0.step_init(1, 1);
    StreamingWindowSelector <
        std::array<ap_uint<8>, 3>,  // TWord
        28,  // IN_HEIGHT
        28,  // IN_WIDTH
        192,  // IN_CH
        1,  // FH
        1,  // FW
        1,  // STRIDE_H
        1,  // STRIDE_W
        1,  // DILATION_H
        1,  // DILATION_W
        0,  // PAD_T
        0,  // PAD_L
        0,  // PAD_B
        0,  // PAD_R
        0,  // POS_H
        0,  // POS_W
        2,  // W_PAR
        3  // CH_PAR
    > StreamingLineBuffer_14_pixel_1;
    StreamingLineBuffer_14_pixel_1.step_init(1, 1);
    StreamingMemory <
        std::array<ap_uint<32>, 1>,  // TInput
        ap_int<14>,  // TOutput
        std::array<ap_int<14>, 1>,  // TOutputStruct
        2,  // DATA_PER_WORD
        580334,  // DATA_TO_SHIFT
        49,  // TIMES
        960,  // WORDS
        1,  // ARRAY_PAR
        1  // WORD_PAR
    > StreamingMemory_93;
    StreamingMemory_93.step_init(1);
    StreamingConv <
        std::array<ap_uint<8>, 3>,  // TInputWord
        ap_uint<8>,  // TInput
        std::array<ap_int<8>, 12>,  // TWeightWord
        ap_int<8>,  // TWeight
        std::array<ap_int<15>, 4>,  // TBiasWord
        ap_int<15>,  // TBias
        std::array<ap_int<8>, 4>,  // TOutputWord
        ap_int<8>,  // TOutput
        ap_int<26>,  // TSum
        ap_int<25>,  // TPartialSum
        DequantQuantEqual<ap_int<26>>,  // Activation
        DequantQuantPo2<8, ap_int<26>, ap_int<8>>,  // Quantizer
        32,  // OUT_CH
        192,  // IN_CH
        28,  // OUT_HEIGHT
        28,  // OUT_WIDTH
        1,  // GROUP
        1,  // FH
        1,  // FW
        1,  // STRIDE_H
        1,  // STRIDE_W
        3,  // IN_CH_PAR
        4,  // OUT_CH_PAR
        2  // W_PAR
    > StreamingConv_9;
    StreamingConv_9.step_init(9);
    StreamingMemory <
        std::array<ap_uint<32>, 1>,  // TInput
        ap_int<8>,  // TOutput
        std::array<ap_int<8>, 40>,  // TOutputStruct
        4,  // DATA_PER_WORD
        541934,  // DATA_TO_SHIFT
        49,  // TIMES
        153600,  // WORDS
        1,  // ARRAY_PAR
        40  // WORD_PAR
    > StreamingMemory_94;
    StreamingMemory_94.step_init(1);
    StreamingAdd <
        std::array<ap_int<8>, 4>,  // TInputWordA
        ap_int<8>,  // TInputA
        std::array<ap_int<8>, 4>,  // TInputWordB
        ap_int<8>,  // TInputB
        std::array<ap_int<8>, 4>,  // TOutputWord
        ap_int<8>,  // TOutput
        ap_int<9>,  // TAcc
        DequantQuantEqual<ap_int<9>>,  // Activation
        DequantQuantPo2<0, ap_int<9>, ap_int<8>>,  // Quantizer
        DequantQuantEqual<ap_int<8>>,  // AlignA
        DequantQuantEqual<ap_int<8>>,  // AlignB
        28,  // IN_HEIGHT
        28,  // IN_WIDTH
        32,  // IN_CH
        2,  // W_PAR
        4  // CH_PAR
    > StreamingAdd_1;
    StreamingAdd_1.step_init(2);
    StreamingMemory <
        std::array<ap_uint<32>, 1>,  // TInput
        ap_int<15>,  // TOutput
        std::array<ap_int<15>, 2>,  // TOutputStruct
        2,  // DATA_PER_WORD
        541854,  // DATA_TO_SHIFT
        49,  // TIMES
        160,  // WORDS
        1,  // ARRAY_PAR
        2  // WORD_PAR
    > StreamingMemory_95;
    StreamingMemory_95.step_init(1);
    BandwidthAdjustDecreaseChannels <
        std::array<ap_int<8>, 4>,  // TInputStruct
        ap_int<8>,  // TInput
        std::array<ap_int<8>, 1>,  // TOutputStruct
        ap_int<8>,  // TOutput
        DequantQuantEqual<ap_int<8>>,  // Quantizer
        28,  // IN_HEIGHT
        28,  // IN_WIDTH
        32,  // IN_CH
        2,  // IN_W_PAR
        2,  // OUT_W_PAR
        4,  // IN_CH_PAR
        1  // OUT_CH_PAR
    > BandwidthAdjustDecreaseChannels_5;
    BandwidthAdjustDecreaseChannels_5.step_init(2);
    StreamingMemory <
        std::array<ap_uint<32>, 1>,  // TInput
        ap_int<8>,  // TOutput
        std::array<ap_int<8>, 40>,  // TOutputStruct
        4,  // DATA_PER_WORD
        503454,  // DATA_TO_SHIFT
        49,  // TIMES
        153600,  // WORDS
        1,  // ARRAY_PAR
        40  // WORD_PAR
    > StreamingMemory_96;
    StreamingMemory_96.step_init(1);
    TensorDuplicator <
        std::array<ap_int<8>, 1>,  // TWord
        28,  // IN_HEIGHT
        28,  // IN_WIDTH
        32,  // IN_CH
        1,  // CH_PAR
        2  // W_PAR
    > TensorDuplicator_2;
    TensorDuplicator_2.step_init(1);
    StreamingMemory <
        std::array<ap_uint<32>, 1>,  // TInput
        ap_int<14>,  // TOutput
        std::array<ap_int<14>, 2>,  // TOutputStruct
        2,  // DATA_PER_WORD
        502974,  // DATA_TO_SHIFT
        49,  // TIMES
        960,  // WORDS
        1,  // ARRAY_PAR
        2  // WORD_PAR
    > StreamingMemory_97;
    StreamingMemory_97.step_init(1);
    BandwidthAdjustIncreaseChannels <
        std::array<ap_int<8>, 1>,  // TInputStruct
        ap_int<8>,  // TInput
        std::array<ap_int<8>, 4>,  // TOutputStruct
        ap_int<8>,  // TOutput
        DequantQuantEqual<ap_int<8>>,  // Quantizer
        28,  // IN_HEIGHT
        28,  // IN_WIDTH
        32,  // IN_CH
        2,  // IN_W_PAR
        2,  // OUT_W_PAR
        1,  // IN_CH_PAR
        4  // OUT_CH_PAR
    > BandwidthAdjustIncreaseChannels_9;
    BandwidthAdjustIncreaseChannels_9.step_init(2);
    BandwidthAdjustIncreaseChannels <
        std::array<ap_int<8>, 1>,  // TInputStruct
        ap_int<8>,  // TInput
        std::array<ap_int<8>, 4>,  // TOutputStruct
        ap_int<8>,  // TOutput
        DequantQuantEqual<ap_int<8>>,  // Quantizer
        28,  // IN_HEIGHT
        28,  // IN_WIDTH
        32,  // IN_CH
        2,  // IN_W_PAR
        2,  // OUT_W_PAR
        1,  // IN_CH_PAR
        4  // OUT_CH_PAR
    > BandwidthAdjustIncreaseChannels_10;
    BandwidthAdjustIncreaseChannels_10.step_init(2);
    StreamingMemory <
        std::array<ap_uint<32>, 1>,  // TInput
        ap_int<8>,  // TOutput
        std::array<ap_int<8>, 1>,  // TOutputStruct
        4,  // DATA_PER_WORD
        500814,  // DATA_TO_SHIFT
        49,  // TIMES
        8640,  // WORDS
        9,  // ARRAY_PAR
        1  // WORD_PAR
    > StreamingMemory_98;
    StreamingMemory_98.step_init(1);
    StreamingWindowSelector <
        std::array<ap_int<8>, 4>,  // TWord
        28,  // IN_HEIGHT
        28,  // IN_WIDTH
        32,  // IN_CH
        1,  // FH
        1,  // FW
        1,  // STRIDE_H
        1,  // STRIDE_W
        1,  // DILATION_H
        1,  // DILATION_W
        0,  // PAD_T
        0,  // PAD_L
        0,  // PAD_B
        0,  // PAD_R
        0,  // POS_H
        1,  // POS_W
        2,  // W_PAR
        4  // CH_PAR
    > StreamingLineBuffer_15_pixel_0;
    StreamingLineBuffer_15_pixel_0.step_init(1, 1);
    StreamingWindowSelector <
        std::array<ap_int<8>, 4>,  // TWord
        28,  // IN_HEIGHT
        28,  // IN_WIDTH
        32,  // IN_CH
        1,  // FH
        1,  // FW
        1,  // STRIDE_H
        1,  // STRIDE_W
        1,  // DILATION_H
        1,  // DILATION_W
        0,  // PAD_T
        0,  // PAD_L
        0,  // PAD_B
        0,  // PAD_R
        0,  // POS_H
        0,  // POS_W
        2,  // W_PAR
        4  // CH_PAR
    > StreamingLineBuffer_15_pixel_1;
    StreamingLineBuffer_15_pixel_1.step_init(1, 1);
    StreamingMemory <
        std::array<ap_uint<32>, 1>,  // TInput
        ap_int<15>,  // TOutput
        std::array<ap_int<15>, 1>,  // TOutputStruct
        2,  // DATA_PER_WORD
        500334,  // DATA_TO_SHIFT
        49,  // TIMES
        960,  // WORDS
        1,  // ARRAY_PAR
        1  // WORD_PAR
    > StreamingMemory_99;
    StreamingMemory_99.step_init(1);
    StreamingConv <
        std::array<ap_int<8>, 4>,  // TInputWord
        ap_int<8>,  // TInput
        std::array<ap_int<8>, 12>,  // TWeightWord
        ap_int<8>,  // TWeight
        std::array<ap_int<15>, 3>,  // TBiasWord
        ap_int<15>,  // TBias
        std::array<ap_uint<8>, 3>,  // TOutputWord
        ap_uint<8>,  // TOutput
        ap_int<23>,  // TSum
        ap_int<22>,  // TPartialSum
        ReLU<ap_int<23>>,  // Activation
        DequantQuantPo2<7, ap_int<23>, ap_uint<8>>,  // Quantizer
        192,  // OUT_CH
        32,  // IN_CH
        28,  // OUT_HEIGHT
        28,  // OUT_WIDTH
        1,  // GROUP
        1,  // FH
        1,  // FW
        1,  // STRIDE_H
        1,  // STRIDE_W
        4,  // IN_CH_PAR
        3,  // OUT_CH_PAR
        2  // W_PAR
    > StreamingConv_10;
    StreamingConv_10.step_init(9);
    StreamingMemory <
        std::array<ap_uint<32>, 1>,  // TInput
        ap_int<8>,  // TOutput
        std::array<ap_int<8>, 80>,  // TOutputStruct
        4,  // DATA_PER_WORD
        423534,  // DATA_TO_SHIFT
        49,  // TIMES
        307200,  // WORDS
        1,  // ARRAY_PAR
        80  // WORD_PAR
    > StreamingMemory_100;
    StreamingMemory_100.step_init(1);
    BandwidthAdjustDecreaseChannels <
        std::array<ap_uint<8>, 3>,  // TInputStruct
        ap_uint<8>,  // TInput
        std::array<ap_uint<8>, 1>,  // TOutputStruct
        ap_uint<8>,  // TOutput
        DequantQuantEqual<ap_uint<8>>,  // Quantizer
        28,  // IN_HEIGHT
        28,  // IN_WIDTH
        192,  // IN_CH
        2,  // IN_W_PAR
        2,  // OUT_W_PAR
        3,  // IN_CH_PAR
        1  // OUT_CH_PAR
    > BandwidthAdjustDecreaseChannels_6;
    BandwidthAdjustDecreaseChannels_6.step_init(2);
    StreamingMemory <
        std::array<ap_uint<32>, 1>,  // TInput
        ap_int<15>,  // TOutput
        std::array<ap_int<15>, 4>,  // TOutputStruct
        2,  // DATA_PER_WORD
        423374,  // DATA_TO_SHIFT
        49,  // TIMES
        320,  // WORDS
        1,  // ARRAY_PAR
        4  // WORD_PAR
    > StreamingMemory_101;
    StreamingMemory_101.step_init(1);
    StreamingWindowSelector <
        std::array<ap_uint<8>, 1>,  // TWord
        28,  // IN_HEIGHT
        28,  // IN_WIDTH
        192,  // IN_CH
        3,  // FH
        3,  // FW
        1,  // STRIDE_H
        1,  // STRIDE_W
        1,  // DILATION_H
        1,  // DILATION_W
        1,  // PAD_T
        1,  // PAD_L
        1,  // PAD_B
        1,  // PAD_R
        2,  // POS_H
        3,  // POS_W
        2,  // W_PAR
        1  // CH_PAR
    > StreamingLineBuffer_16_pixel_0;
    StreamingLineBuffer_16_pixel_0.step_init(2, 1);
    StreamingWindowSelector <
        std::array<ap_uint<8>, 1>,  // TWord
        28,  // IN_HEIGHT
        28,  // IN_WIDTH
        192,  // IN_CH
        3,  // FH
        3,  // FW
        1,  // STRIDE_H
        1,  // STRIDE_W
        1,  // DILATION_H
        1,  // DILATION_W
        1,  // PAD_T
        1,  // PAD_L
        1,  // PAD_B
        1,  // PAD_R
        2,  // POS_H
        2,  // POS_W
        2,  // W_PAR
        1  // CH_PAR
    > StreamingLineBuffer_16_pixel_1;
    StreamingLineBuffer_16_pixel_1.step_init(2, 1);
    StreamingMemory <
        std::array<ap_uint<32>, 1>,  // TInput
        ap_int<8>,  // TOutput
        std::array<ap_int<8>, 128>,  // TOutputStruct
        4,  // DATA_PER_WORD
        320974,  // DATA_TO_SHIFT
        49,  // TIMES
        409600,  // WORDS
        1,  // ARRAY_PAR
        128  // WORD_PAR
    > StreamingMemory_102;
    StreamingMemory_102.step_init(1);
    StreamingWindowSelector <
        std::array<ap_uint<8>, 1>,  // TWord
        28,  // IN_HEIGHT
        28,  // IN_WIDTH
        192,  // IN_CH
        3,  // FH
        3,  // FW
        1,  // STRIDE_H
        1,  // STRIDE_W
        1,  // DILATION_H
        1,  // DILATION_W
        1,  // PAD_T
        1,  // PAD_L
        1,  // PAD_B
        1,  // PAD_R
        2,  // POS_H
        1,  // POS_W
        2,  // W_PAR
        1  // CH_PAR
    > StreamingLineBuffer_16_pixel_2;
    StreamingLineBuffer_16_pixel_2.step_init(2, 193);
    StreamingWindowSelector <
        std::array<ap_uint<8>, 1>,  // TWord
        28,  // IN_HEIGHT
        28,  // IN_WIDTH
        192,  // IN_CH
        3,  // FH
        3,  // FW
        1,  // STRIDE_H
        1,  // STRIDE_W
        1,  // DILATION_H
        1,  // DILATION_W
        1,  // PAD_T
        1,  // PAD_L
        1,  // PAD_B
        1,  // PAD_R
        2,  // POS_H
        0,  // POS_W
        2,  // W_PAR
        1  // CH_PAR
    > StreamingLineBuffer_16_pixel_3;
    StreamingLineBuffer_16_pixel_3.step_init(2, 193);
    StreamingMemory <
        std::array<ap_uint<32>, 1>,  // TInput
        ap_int<12>,  // TOutput
        std::array<ap_int<12>, 4>,  // TOutputStruct
        2,  // DATA_PER_WORD
        320334,  // DATA_TO_SHIFT
        49,  // TIMES
        1280,  // WORDS
        1,  // ARRAY_PAR
        4  // WORD_PAR
    > StreamingMemory_103;
    StreamingMemory_103.step_init(1);
    StreamingWindowSelector <
        std::array<ap_uint<8>, 1>,  // TWord
        28,  // IN_HEIGHT
        28,  // IN_WIDTH
        192,  // IN_CH
        3,  // FH
        3,  // FW
        1,  // STRIDE_H
        1,  // STRIDE_W
        1,  // DILATION_H
        1,  // DILATION_W
        1,  // PAD_T
        1,  // PAD_L
        1,  // PAD_B
        1,  // PAD_R
        1,  // POS_H
        3,  // POS_W
        2,  // W_PAR
        1  // CH_PAR
    > StreamingLineBuffer_16_pixel_4;
    StreamingLineBuffer_16_pixel_4.step_init(2, 2497);
    StreamingWindowSelector <
        std::array<ap_uint<8>, 1>,  // TWord
        28,  // IN_HEIGHT
        28,  // IN_WIDTH
        192,  // IN_CH
        3,  // FH
        3,  // FW
        1,  // STRIDE_H
        1,  // STRIDE_W
        1,  // DILATION_H
        1,  // DILATION_W
        1,  // PAD_T
        1,  // PAD_L
        1,  // PAD_B
        1,  // PAD_R
        1,  // POS_H
        2,  // POS_W
        2,  // W_PAR
        1  // CH_PAR
    > StreamingLineBuffer_16_pixel_5;
    StreamingLineBuffer_16_pixel_5.step_init(1, 2497);
    StreamingMemory <
        std::array<ap_uint<32>, 1>,  // TInput
        ap_int<8>,  // TOutput
        std::array<ap_int<8>, 10>,  // TOutputStruct
        4,  // DATA_PER_WORD
        334,  // DATA_TO_SHIFT
        1,  // TIMES
        1280000,  // WORDS
        1,  // ARRAY_PAR
        10  // WORD_PAR
    > StreamingMemory_104;
    StreamingMemory_104.step_init(1);
    StreamingWindowSelector <
        std::array<ap_uint<8>, 1>,  // TWord
        28,  // IN_HEIGHT
        28,  // IN_WIDTH
        192,  // IN_CH
        3,  // FH
        3,  // FW
        1,  // STRIDE_H
        1,  // STRIDE_W
        1,  // DILATION_H
        1,  // DILATION_W
        1,  // PAD_T
        1,  // PAD_L
        1,  // PAD_B
        1,  // PAD_R
        1,  // POS_H
        1,  // POS_W
        2,  // W_PAR
        1  // CH_PAR
    > StreamingLineBuffer_16_pixel_6;
    StreamingLineBuffer_16_pixel_6.step_init(1, 193);
    StreamingWindowSelector <
        std::array<ap_uint<8>, 1>,  // TWord
        28,  // IN_HEIGHT
        28,  // IN_WIDTH
        192,  // IN_CH
        3,  // FH
        3,  // FW
        1,  // STRIDE_H
        1,  // STRIDE_W
        1,  // DILATION_H
        1,  // DILATION_W
        1,  // PAD_T
        1,  // PAD_L
        1,  // PAD_B
        1,  // PAD_R
        1,  // POS_H
        0,  // POS_W
        2,  // W_PAR
        1  // CH_PAR
    > StreamingLineBuffer_16_pixel_7;
    StreamingLineBuffer_16_pixel_7.step_init(2, 193);
    StreamingMemory <
        std::array<ap_uint<32>, 1>,  // TInput
        ap_int<9>,  // TOutput
        std::array<ap_int<9>, 2>,  // TOutputStruct
        3,  // DATA_PER_WORD
        0,  // DATA_TO_SHIFT
        1,  // TIMES
        1000,  // WORDS
        1,  // ARRAY_PAR
        2  // WORD_PAR
    > StreamingMemory_105;
    StreamingMemory_105.step_init(1);
    StreamingWindowSelector <
        std::array<ap_uint<8>, 1>,  // TWord
        28,  // IN_HEIGHT
        28,  // IN_WIDTH
        192,  // IN_CH
        3,  // FH
        3,  // FW
        1,  // STRIDE_H
        1,  // STRIDE_W
        1,  // DILATION_H
        1,  // DILATION_W
        1,  // PAD_T
        1,  // PAD_L
        1,  // PAD_B
        1,  // PAD_R
        0,  // POS_H
        3,  // POS_W
        2,  // W_PAR
        1  // CH_PAR
    > StreamingLineBuffer_16_pixel_8;
    StreamingLineBuffer_16_pixel_8.step_init(2, 2497);
    StreamingWindowSelector <
        std::array<ap_uint<8>, 1>,  // TWord
        28,  // IN_HEIGHT
        28,  // IN_WIDTH
        192,  // IN_CH
        3,  // FH
        3,  // FW
        1,  // STRIDE_H
        1,  // STRIDE_W
        1,  // DILATION_H
        1,  // DILATION_W
        1,  // PAD_T
        1,  // PAD_L
        1,  // PAD_B
        1,  // PAD_R
        0,  // POS_H
        2,  // POS_W
        2,  // W_PAR
        1  // CH_PAR
    > StreamingLineBuffer_16_pixel_9;
    StreamingLineBuffer_16_pixel_9.step_init(2, 2497);
    StreamingWindowSelector <
        std::array<ap_uint<8>, 1>,  // TWord
        28,  // IN_HEIGHT
        28,  // IN_WIDTH
        192,  // IN_CH
        3,  // FH
        3,  // FW
        1,  // STRIDE_H
        1,  // STRIDE_W
        1,  // DILATION_H
        1,  // DILATION_W
        1,  // PAD_T
        1,  // PAD_L
        1,  // PAD_B
        1,  // PAD_R
        0,  // POS_H
        1,  // POS_W
        2,  // W_PAR
        1  // CH_PAR
    > StreamingLineBuffer_16_pixel_10;
    StreamingLineBuffer_16_pixel_10.step_init(1, 193);
    StreamingWindowSelector <
        std::array<ap_uint<8>, 1>,  // TWord
        28,  // IN_HEIGHT
        28,  // IN_WIDTH
        192,  // IN_CH
        3,  // FH
        3,  // FW
        1,  // STRIDE_H
        1,  // STRIDE_W
        1,  // DILATION_H
        1,  // DILATION_W
        1,  // PAD_T
        1,  // PAD_L
        1,  // PAD_B
        1,  // PAD_R
        0,  // POS_H
        0,  // POS_W
        2,  // W_PAR
        1  // CH_PAR
    > StreamingLineBuffer_16_pixel_11;
    StreamingLineBuffer_16_pixel_11.step_init(1, 193);
    StreamingPad <
        std::array<ap_uint<8>, 1>,  // TWord
        ap_uint<8>,  // TData
        28,  // IN_HEIGHT
        28,  // IN_WIDTH
        192,  // IN_CH
        3,  // FH
        3,  // FW
        1,  // STRIDE_H
        1,  // STRIDE_W
        1,  // DILATION_H
        1,  // DILATION_W
        1,  // PAD_T
        1,  // PAD_L
        1,  // PAD_B
        1,  // PAD_R
        2,  // W_PAR
        1,  // CH_PAR
        0  // PAD_VALUE
    > StreamingLineBuffer_16_pad;
    StreamingLineBuffer_16_pad.step_init(3);
    StreamingDepthwiseConv <
        std::array<ap_uint<8>, 1>,  // TInputStruct
        ap_uint<8>,  // TInput
        std::array<ap_int<8>, 1>,  // TWeightStruct
        ap_int<8>,  // TWeight
        std::array<ap_int<14>, 1>,  // TBiasStruct
        ap_int<14>,  // TBias
        std::array<ap_uint<8>, 1>,  // TOutputStruct
        ap_uint<8>,  // TOutput
        ap_int<21>,  // TSum
        ap_int<20>,  // TPartialSum
        ReLU<ap_int<21>>,  // Activation
        DequantQuantPo2<5, ap_int<21>, ap_uint<8>>,  // Quantizer
        192,  // OUT_CH
        192,  // IN_CH
        28,  // IN_HEIGHT
        28,  // IN_WIDTH
        3,  // FH
        3,  // FW
        1,  // STRIDE_H
        1,  // STRIDE_W
        1,  // CH_PAR
        2  // W_PAR
    > StreamingDepthwiseConv_5;
    StreamingDepthwiseConv_5.step_init(8);
    BandwidthAdjustIncreaseChannels <
        std::array<ap_uint<8>, 1>,  // TInputStruct
        ap_uint<8>,  // TInput
        std::array<ap_uint<8>, 3>,  // TOutputStruct
        ap_uint<8>,  // TOutput
        DequantQuantEqual<ap_uint<8>>,  // Quantizer
        28,  // IN_HEIGHT
        28,  // IN_WIDTH
        192,  // IN_CH
        2,  // IN_W_PAR
        2,  // OUT_W_PAR
        1,  // IN_CH_PAR
        3  // OUT_CH_PAR
    > BandwidthAdjustIncreaseChannels_11;
    BandwidthAdjustIncreaseChannels_11.step_init(2);
    StreamingWindowSelector <
        std::array<ap_uint<8>, 3>,  // TWord
        28,  // IN_HEIGHT
        28,  // IN_WIDTH
        192,  // IN_CH
        1,  // FH
        1,  // FW
        1,  // STRIDE_H
        1,  // STRIDE_W
        1,  // DILATION_H
        1,  // DILATION_W
        0,  // PAD_T
        0,  // PAD_L
        0,  // PAD_B
        0,  // PAD_R
        0,  // POS_H
        1,  // POS_W
        2,  // W_PAR
        3  // CH_PAR
    > StreamingLineBuffer_17_pixel_0;
    StreamingLineBuffer_17_pixel_0.step_init(1, 1);
    StreamingWindowSelector <
        std::array<ap_uint<8>, 3>,  // TWord
        28,  // IN_HEIGHT
        28,  // IN_WIDTH
        192,  // IN_CH
        1,  // FH
        1,  // FW
        1,  // STRIDE_H
        1,  // STRIDE_W
        1,  // DILATION_H
        1,  // DILATION_W
        0,  // PAD_T
        0,  // PAD_L
        0,  // PAD_B
        0,  // PAD_R
        0,  // POS_H
        0,  // POS_W
        2,  // W_PAR
        3  // CH_PAR
    > StreamingLineBuffer_17_pixel_1;
    StreamingLineBuffer_17_pixel_1.step_init(1, 1);
    StreamingConv <
        std::array<ap_uint<8>, 3>,  // TInputWord
        ap_uint<8>,  // TInput
        std::array<ap_int<8>, 12>,  // TWeightWord
        ap_int<8>,  // TWeight
        std::array<ap_int<16>, 4>,  // TBiasWord
        ap_int<16>,  // TBias
        std::array<ap_int<8>, 4>,  // TOutputWord
        ap_int<8>,  // TOutput
        ap_int<26>,  // TSum
        ap_int<25>,  // TPartialSum
        DequantQuantEqual<ap_int<26>>,  // Activation
        DequantQuantPo2<9, ap_int<26>, ap_int<8>>,  // Quantizer
        32,  // OUT_CH
        192,  // IN_CH
        28,  // OUT_HEIGHT
        28,  // OUT_WIDTH
        1,  // GROUP
        1,  // FH
        1,  // FW
        1,  // STRIDE_H
        1,  // STRIDE_W
        3,  // IN_CH_PAR
        4,  // OUT_CH_PAR
        2  // W_PAR
    > StreamingConv_11;
    StreamingConv_11.step_init(9);
    StreamingAdd <
        std::array<ap_int<8>, 4>,  // TInputWordA
        ap_int<8>,  // TInputA
        std::array<ap_int<8>, 4>,  // TInputWordB
        ap_int<8>,  // TInputB
        std::array<ap_int<8>, 4>,  // TOutputWord
        ap_int<8>,  // TOutput
        ap_int<9>,  // TAcc
        DequantQuantEqual<ap_int<9>>,  // Activation
        DequantQuantPo2<1, ap_int<9>, ap_int<8>>,  // Quantizer
        DequantQuantEqual<ap_int<8>>,  // AlignA
        DequantQuantEqual<ap_int<8>>,  // AlignB
        28,  // IN_HEIGHT
        28,  // IN_WIDTH
        32,  // IN_CH
        2,  // W_PAR
        4  // CH_PAR
    > StreamingAdd_2;
    StreamingAdd_2.step_init(3);
    StreamingWindowSelector <
        std::array<ap_int<8>, 4>,  // TWord
        28,  // IN_HEIGHT
        28,  // IN_WIDTH
        32,  // IN_CH
        1,  // FH
        1,  // FW
        1,  // STRIDE_H
        1,  // STRIDE_W
        1,  // DILATION_H
        1,  // DILATION_W
        0,  // PAD_T
        0,  // PAD_L
        0,  // PAD_B
        0,  // PAD_R
        0,  // POS_H
        1,  // POS_W
        2,  // W_PAR
        4  // CH_PAR
    > StreamingLineBuffer_18_pixel_0;
    StreamingLineBuffer_18_pixel_0.step_init(1, 1);
    StreamingWindowSelector <
        std::array<ap_int<8>, 4>,  // TWord
        28,  // IN_HEIGHT
        28,  // IN_WIDTH
        32,  // IN_CH
        1,  // FH
        1,  // FW
        1,  // STRIDE_H
        1,  // STRIDE_W
        1,  // DILATION_H
        1,  // DILATION_W
        0,  // PAD_T
        0,  // PAD_L
        0,  // PAD_B
        0,  // PAD_R
        0,  // POS_H
        0,  // POS_W
        2,  // W_PAR
        4  // CH_PAR
    > StreamingLineBuffer_18_pixel_1;
    StreamingLineBuffer_18_pixel_1.step_init(1, 1);
    StreamingConv <
        std::array<ap_int<8>, 4>,  // TInputWord
        ap_int<8>,  // TInput
        std::array<ap_int<8>, 12>,  // TWeightWord
        ap_int<8>,  // TWeight
        std::array<ap_int<14>, 3>,  // TBiasWord
        ap_int<14>,  // TBias
        std::array<ap_uint<8>, 3>,  // TOutputWord
        ap_uint<8>,  // TOutput
        ap_int<23>,  // TSum
        ap_int<22>,  // TPartialSum
        ReLU<ap_int<23>>,  // Activation
        DequantQuantPo2<7, ap_int<23>, ap_uint<8>>,  // Quantizer
        192,  // OUT_CH
        32,  // IN_CH
        28,  // OUT_HEIGHT
        28,  // OUT_WIDTH
        1,  // GROUP
        1,  // FH
        1,  // FW
        1,  // STRIDE_H
        1,  // STRIDE_W
        4,  // IN_CH_PAR
        3,  // OUT_CH_PAR
        2  // W_PAR
    > StreamingConv_12;
    StreamingConv_12.step_init(9);
    BandwidthAdjustDecreaseChannels <
        std::array<ap_uint<8>, 3>,  // TInputStruct
        ap_uint<8>,  // TInput
        std::array<ap_uint<8>, 1>,  // TOutputStruct
        ap_uint<8>,  // TOutput
        DequantQuantEqual<ap_uint<8>>,  // Quantizer
        28,  // IN_HEIGHT
        28,  // IN_WIDTH
        192,  // IN_CH
        2,  // IN_W_PAR
        2,  // OUT_W_PAR
        3,  // IN_CH_PAR
        1  // OUT_CH_PAR
    > BandwidthAdjustDecreaseChannels_7;
    BandwidthAdjustDecreaseChannels_7.step_init(2);
    BandwidthAdjustDecreaseStreams <
        std::array<ap_uint<8>, 1>,  // TInputStruct
        ap_uint<8>,  // TInput
        std::array<ap_uint<8>, 1>,  // TOutputStruct
        ap_uint<8>,  // TOutput
        DequantQuantEqual<ap_uint<8>>,  // Quantizer
        28,  // IN_HEIGHT
        28,  // IN_WIDTH
        192,  // IN_CH
        2,  // IN_W_PAR
        1,  // OUT_W_PAR
        1,  // IN_CH_PAR
        1  // OUT_CH_PAR
    > BandwidthAdjustDecreaseStreams_3;
    BandwidthAdjustDecreaseStreams_3.step_init(2);
    StreamingWindowSelector <
        std::array<ap_uint<8>, 1>,  // TWord
        28,  // IN_HEIGHT
        28,  // IN_WIDTH
        192,  // IN_CH
        3,  // FH
        3,  // FW
        2,  // STRIDE_H
        2,  // STRIDE_W
        1,  // DILATION_H
        1,  // DILATION_W
        1,  // PAD_T
        1,  // PAD_L
        1,  // PAD_B
        1,  // PAD_R
        2,  // POS_H
        2,  // POS_W
        1,  // W_PAR
        1  // CH_PAR
    > StreamingLineBuffer_19_pixel_0;
    StreamingLineBuffer_19_pixel_0.step_init(2, 1);
    StreamingWindowSelector <
        std::array<ap_uint<8>, 1>,  // TWord
        28,  // IN_HEIGHT
        28,  // IN_WIDTH
        192,  // IN_CH
        3,  // FH
        3,  // FW
        2,  // STRIDE_H
        2,  // STRIDE_W
        1,  // DILATION_H
        1,  // DILATION_W
        1,  // PAD_T
        1,  // PAD_L
        1,  // PAD_B
        1,  // PAD_R
        2,  // POS_H
        1,  // POS_W
        1,  // W_PAR
        1  // CH_PAR
    > StreamingLineBuffer_19_pixel_1;
    StreamingLineBuffer_19_pixel_1.step_init(2, 193);
    StreamingWindowSelector <
        std::array<ap_uint<8>, 1>,  // TWord
        28,  // IN_HEIGHT
        28,  // IN_WIDTH
        192,  // IN_CH
        3,  // FH
        3,  // FW
        2,  // STRIDE_H
        2,  // STRIDE_W
        1,  // DILATION_H
        1,  // DILATION_W
        1,  // PAD_T
        1,  // PAD_L
        1,  // PAD_B
        1,  // PAD_R
        2,  // POS_H
        0,  // POS_W
        1,  // W_PAR
        1  // CH_PAR
    > StreamingLineBuffer_19_pixel_2;
    StreamingLineBuffer_19_pixel_2.step_init(2, 193);
    StreamingWindowSelector <
        std::array<ap_uint<8>, 1>,  // TWord
        28,  // IN_HEIGHT
        28,  // IN_WIDTH
        192,  // IN_CH
        3,  // FH
        3,  // FW
        2,  // STRIDE_H
        2,  // STRIDE_W
        1,  // DILATION_H
        1,  // DILATION_W
        1,  // PAD_T
        1,  // PAD_L
        1,  // PAD_B
        1,  // PAD_R
        1,  // POS_H
        2,  // POS_W
        1,  // W_PAR
        1  // CH_PAR
    > StreamingLineBuffer_19_pixel_3;
    StreamingLineBuffer_19_pixel_3.step_init(2, 4993);
    StreamingWindowSelector <
        std::array<ap_uint<8>, 1>,  // TWord
        28,  // IN_HEIGHT
        28,  // IN_WIDTH
        192,  // IN_CH
        3,  // FH
        3,  // FW
        2,  // STRIDE_H
        2,  // STRIDE_W
        1,  // DILATION_H
        1,  // DILATION_W
        1,  // PAD_T
        1,  // PAD_L
        1,  // PAD_B
        1,  // PAD_R
        1,  // POS_H
        1,  // POS_W
        1,  // W_PAR
        1  // CH_PAR
    > StreamingLineBuffer_19_pixel_4;
    StreamingLineBuffer_19_pixel_4.step_init(2, 193);
    StreamingWindowSelector <
        std::array<ap_uint<8>, 1>,  // TWord
        28,  // IN_HEIGHT
        28,  // IN_WIDTH
        192,  // IN_CH
        3,  // FH
        3,  // FW
        2,  // STRIDE_H
        2,  // STRIDE_W
        1,  // DILATION_H
        1,  // DILATION_W
        1,  // PAD_T
        1,  // PAD_L
        1,  // PAD_B
        1,  // PAD_R
        1,  // POS_H
        0,  // POS_W
        1,  // W_PAR
        1  // CH_PAR
    > StreamingLineBuffer_19_pixel_5;
    StreamingLineBuffer_19_pixel_5.step_init(2, 193);
    StreamingWindowSelector <
        std::array<ap_uint<8>, 1>,  // TWord
        28,  // IN_HEIGHT
        28,  // IN_WIDTH
        192,  // IN_CH
        3,  // FH
        3,  // FW
        2,  // STRIDE_H
        2,  // STRIDE_W
        1,  // DILATION_H
        1,  // DILATION_W
        1,  // PAD_T
        1,  // PAD_L
        1,  // PAD_B
        1,  // PAD_R
        0,  // POS_H
        2,  // POS_W
        1,  // W_PAR
        1  // CH_PAR
    > StreamingLineBuffer_19_pixel_6;
    StreamingLineBuffer_19_pixel_6.step_init(2, 4993);
    StreamingWindowSelector <
        std::array<ap_uint<8>, 1>,  // TWord
        28,  // IN_HEIGHT
        28,  // IN_WIDTH
        192,  // IN_CH
        3,  // FH
        3,  // FW
        2,  // STRIDE_H
        2,  // STRIDE_W
        1,  // DILATION_H
        1,  // DILATION_W
        1,  // PAD_T
        1,  // PAD_L
        1,  // PAD_B
        1,  // PAD_R
        0,  // POS_H
        1,  // POS_W
        1,  // W_PAR
        1  // CH_PAR
    > StreamingLineBuffer_19_pixel_7;
    StreamingLineBuffer_19_pixel_7.step_init(2, 193);
    StreamingWindowSelector <
        std::array<ap_uint<8>, 1>,  // TWord
        28,  // IN_HEIGHT
        28,  // IN_WIDTH
        192,  // IN_CH
        3,  // FH
        3,  // FW
        2,  // STRIDE_H
        2,  // STRIDE_W
        1,  // DILATION_H
        1,  // DILATION_W
        1,  // PAD_T
        1,  // PAD_L
        1,  // PAD_B
        1,  // PAD_R
        0,  // POS_H
        0,  // POS_W
        1,  // W_PAR
        1  // CH_PAR
    > StreamingLineBuffer_19_pixel_8;
    StreamingLineBuffer_19_pixel_8.step_init(1, 193);
    StreamingPad <
        std::array<ap_uint<8>, 1>,  // TWord
        ap_uint<8>,  // TData
        28,  // IN_HEIGHT
        28,  // IN_WIDTH
        192,  // IN_CH
        3,  // FH
        3,  // FW
        2,  // STRIDE_H
        2,  // STRIDE_W
        1,  // DILATION_H
        1,  // DILATION_W
        1,  // PAD_T
        1,  // PAD_L
        1,  // PAD_B
        1,  // PAD_R
        1,  // W_PAR
        1,  // CH_PAR
        0  // PAD_VALUE
    > StreamingLineBuffer_19_pad;
    StreamingLineBuffer_19_pad.step_init(3);
    StreamingDepthwiseConv <
        std::array<ap_uint<8>, 1>,  // TInputStruct
        ap_uint<8>,  // TInput
        std::array<ap_int<8>, 1>,  // TWeightStruct
        ap_int<8>,  // TWeight
        std::array<ap_int<15>, 1>,  // TBiasStruct
        ap_int<15>,  // TBias
        std::array<ap_uint<8>, 1>,  // TOutputStruct
        ap_uint<8>,  // TOutput
        ap_int<21>,  // TSum
        ap_int<20>,  // TPartialSum
        ReLU<ap_int<21>>,  // Activation
        DequantQuantPo2<7, ap_int<21>, ap_uint<8>>,  // Quantizer
        192,  // OUT_CH
        192,  // IN_CH
        14,  // IN_HEIGHT
        14,  // IN_WIDTH
        3,  // FH
        3,  // FW
        2,  // STRIDE_H
        2,  // STRIDE_W
        1,  // CH_PAR
        1  // W_PAR
    > StreamingDepthwiseConv_6;
    StreamingDepthwiseConv_6.step_init(8);
    BandwidthAdjustIncreaseChannels <
        std::array<ap_uint<8>, 1>,  // TInputStruct
        ap_uint<8>,  // TInput
        std::array<ap_uint<8>, 3>,  // TOutputStruct
        ap_uint<8>,  // TOutput
        DequantQuantEqual<ap_uint<8>>,  // Quantizer
        14,  // IN_HEIGHT
        14,  // IN_WIDTH
        192,  // IN_CH
        1,  // IN_W_PAR
        1,  // OUT_W_PAR
        1,  // IN_CH_PAR
        3  // OUT_CH_PAR
    > BandwidthAdjustIncreaseChannels_12;
    BandwidthAdjustIncreaseChannels_12.step_init(2);
    StreamingConv <
        std::array<ap_uint<8>, 3>,  // TInputWord
        ap_uint<8>,  // TInput
        std::array<ap_int<8>, 12>,  // TWeightWord
        ap_int<8>,  // TWeight
        std::array<ap_int<16>, 4>,  // TBiasWord
        ap_int<16>,  // TBias
        std::array<ap_int<8>, 4>,  // TOutputWord
        ap_int<8>,  // TOutput
        ap_int<26>,  // TSum
        ap_int<25>,  // TPartialSum
        DequantQuantEqual<ap_int<26>>,  // Activation
        DequantQuantPo2<9, ap_int<26>, ap_int<8>>,  // Quantizer
        64,  // OUT_CH
        192,  // IN_CH
        14,  // OUT_HEIGHT
        14,  // OUT_WIDTH
        1,  // GROUP
        1,  // FH
        1,  // FW
        1,  // STRIDE_H
        1,  // STRIDE_W
        3,  // IN_CH_PAR
        4,  // OUT_CH_PAR
        1  // W_PAR
    > StreamingConv_13;
    StreamingConv_13.step_init(9);
    TensorDuplicator <
        std::array<ap_int<8>, 4>,  // TWord
        14,  // IN_HEIGHT
        14,  // IN_WIDTH
        64,  // IN_CH
        4,  // CH_PAR
        1  // W_PAR
    > TensorDuplicator_3;
    TensorDuplicator_3.step_init(1);
    BandwidthAdjustIncreaseStreams <
        std::array<ap_int<8>, 4>,  // TInputStruct
        ap_int<8>,  // TInput
        std::array<ap_int<8>, 4>,  // TOutputStruct
        ap_int<8>,  // TOutput
        DequantQuantEqual<ap_int<8>>,  // Quantizer
        14,  // IN_HEIGHT
        14,  // IN_WIDTH
        64,  // IN_CH
        1,  // IN_W_PAR
        2,  // OUT_W_PAR
        4,  // IN_CH_PAR
        4  // OUT_CH_PAR
    > BandwidthAdjustIncreaseStreams_2;
    BandwidthAdjustIncreaseStreams_2.step_init(1);
    BandwidthAdjustIncreaseStreams <
        std::array<ap_int<8>, 4>,  // TInputStruct
        ap_int<8>,  // TInput
        std::array<ap_int<8>, 4>,  // TOutputStruct
        ap_int<8>,  // TOutput
        DequantQuantEqual<ap_int<8>>,  // Quantizer
        14,  // IN_HEIGHT
        14,  // IN_WIDTH
        64,  // IN_CH
        1,  // IN_W_PAR
        2,  // OUT_W_PAR
        4,  // IN_CH_PAR
        4  // OUT_CH_PAR
    > BandwidthAdjustIncreaseStreams_3;
    BandwidthAdjustIncreaseStreams_3.step_init(1);
    StreamingWindowSelector <
        std::array<ap_int<8>, 4>,  // TWord
        14,  // IN_HEIGHT
        14,  // IN_WIDTH
        64,  // IN_CH
        1,  // FH
        1,  // FW
        1,  // STRIDE_H
        1,  // STRIDE_W
        1,  // DILATION_H
        1,  // DILATION_W
        0,  // PAD_T
        0,  // PAD_L
        0,  // PAD_B
        0,  // PAD_R
        0,  // POS_H
        1,  // POS_W
        2,  // W_PAR
        4  // CH_PAR
    > StreamingLineBuffer_20_pixel_0;
    StreamingLineBuffer_20_pixel_0.step_init(1, 1);
    StreamingWindowSelector <
        std::array<ap_int<8>, 4>,  // TWord
        14,  // IN_HEIGHT
        14,  // IN_WIDTH
        64,  // IN_CH
        1,  // FH
        1,  // FW
        1,  // STRIDE_H
        1,  // STRIDE_W
        1,  // DILATION_H
        1,  // DILATION_W
        0,  // PAD_T
        0,  // PAD_L
        0,  // PAD_B
        0,  // PAD_R
        0,  // POS_H
        0,  // POS_W
        2,  // W_PAR
        4  // CH_PAR
    > StreamingLineBuffer_20_pixel_1;
    StreamingLineBuffer_20_pixel_1.step_init(1, 1);
    StreamingConv <
        std::array<ap_int<8>, 4>,  // TInputWord
        ap_int<8>,  // TInput
        std::array<ap_int<8>, 12>,  // TWeightWord
        ap_int<8>,  // TWeight
        std::array<ap_int<16>, 3>,  // TBiasWord
        ap_int<16>,  // TBias
        std::array<ap_uint<8>, 3>,  // TOutputWord
        ap_uint<8>,  // TOutput
        ap_int<24>,  // TSum
        ap_int<23>,  // TPartialSum
        ReLU<ap_int<24>>,  // Activation
        DequantQuantPo2<8, ap_int<24>, ap_uint<8>>,  // Quantizer
        384,  // OUT_CH
        64,  // IN_CH
        14,  // OUT_HEIGHT
        14,  // OUT_WIDTH
        1,  // GROUP
        1,  // FH
        1,  // FW
        1,  // STRIDE_H
        1,  // STRIDE_W
        4,  // IN_CH_PAR
        3,  // OUT_CH_PAR
        2  // W_PAR
    > StreamingConv_14;
    StreamingConv_14.step_init(9);
    BandwidthAdjustDecreaseChannels <
        std::array<ap_uint<8>, 3>,  // TInputStruct
        ap_uint<8>,  // TInput
        std::array<ap_uint<8>, 1>,  // TOutputStruct
        ap_uint<8>,  // TOutput
        DequantQuantEqual<ap_uint<8>>,  // Quantizer
        14,  // IN_HEIGHT
        14,  // IN_WIDTH
        384,  // IN_CH
        2,  // IN_W_PAR
        2,  // OUT_W_PAR
        3,  // IN_CH_PAR
        1  // OUT_CH_PAR
    > BandwidthAdjustDecreaseChannels_8;
    BandwidthAdjustDecreaseChannels_8.step_init(2);
    StreamingWindowSelector <
        std::array<ap_uint<8>, 1>,  // TWord
        14,  // IN_HEIGHT
        14,  // IN_WIDTH
        384,  // IN_CH
        3,  // FH
        3,  // FW
        1,  // STRIDE_H
        1,  // STRIDE_W
        1,  // DILATION_H
        1,  // DILATION_W
        1,  // PAD_T
        1,  // PAD_L
        1,  // PAD_B
        1,  // PAD_R
        2,  // POS_H
        3,  // POS_W
        2,  // W_PAR
        1  // CH_PAR
    > StreamingLineBuffer_21_pixel_0;
    StreamingLineBuffer_21_pixel_0.step_init(2, 1);
    StreamingWindowSelector <
        std::array<ap_uint<8>, 1>,  // TWord
        14,  // IN_HEIGHT
        14,  // IN_WIDTH
        384,  // IN_CH
        3,  // FH
        3,  // FW
        1,  // STRIDE_H
        1,  // STRIDE_W
        1,  // DILATION_H
        1,  // DILATION_W
        1,  // PAD_T
        1,  // PAD_L
        1,  // PAD_B
        1,  // PAD_R
        2,  // POS_H
        2,  // POS_W
        2,  // W_PAR
        1  // CH_PAR
    > StreamingLineBuffer_21_pixel_1;
    StreamingLineBuffer_21_pixel_1.step_init(2, 1);
    StreamingWindowSelector <
        std::array<ap_uint<8>, 1>,  // TWord
        14,  // IN_HEIGHT
        14,  // IN_WIDTH
        384,  // IN_CH
        3,  // FH
        3,  // FW
        1,  // STRIDE_H
        1,  // STRIDE_W
        1,  // DILATION_H
        1,  // DILATION_W
        1,  // PAD_T
        1,  // PAD_L
        1,  // PAD_B
        1,  // PAD_R
        2,  // POS_H
        1,  // POS_W
        2,  // W_PAR
        1  // CH_PAR
    > StreamingLineBuffer_21_pixel_2;
    StreamingLineBuffer_21_pixel_2.step_init(2, 385);
    StreamingWindowSelector <
        std::array<ap_uint<8>, 1>,  // TWord
        14,  // IN_HEIGHT
        14,  // IN_WIDTH
        384,  // IN_CH
        3,  // FH
        3,  // FW
        1,  // STRIDE_H
        1,  // STRIDE_W
        1,  // DILATION_H
        1,  // DILATION_W
        1,  // PAD_T
        1,  // PAD_L
        1,  // PAD_B
        1,  // PAD_R
        2,  // POS_H
        0,  // POS_W
        2,  // W_PAR
        1  // CH_PAR
    > StreamingLineBuffer_21_pixel_3;
    StreamingLineBuffer_21_pixel_3.step_init(2, 385);
    StreamingWindowSelector <
        std::array<ap_uint<8>, 1>,  // TWord
        14,  // IN_HEIGHT
        14,  // IN_WIDTH
        384,  // IN_CH
        3,  // FH
        3,  // FW
        1,  // STRIDE_H
        1,  // STRIDE_W
        1,  // DILATION_H
        1,  // DILATION_W
        1,  // PAD_T
        1,  // PAD_L
        1,  // PAD_B
        1,  // PAD_R
        1,  // POS_H
        3,  // POS_W
        2,  // W_PAR
        1  // CH_PAR
    > StreamingLineBuffer_21_pixel_4;
    StreamingLineBuffer_21_pixel_4.step_init(2, 2305);
    StreamingWindowSelector <
        std::array<ap_uint<8>, 1>,  // TWord
        14,  // IN_HEIGHT
        14,  // IN_WIDTH
        384,  // IN_CH
        3,  // FH
        3,  // FW
        1,  // STRIDE_H
        1,  // STRIDE_W
        1,  // DILATION_H
        1,  // DILATION_W
        1,  // PAD_T
        1,  // PAD_L
        1,  // PAD_B
        1,  // PAD_R
        1,  // POS_H
        2,  // POS_W
        2,  // W_PAR
        1  // CH_PAR
    > StreamingLineBuffer_21_pixel_5;
    StreamingLineBuffer_21_pixel_5.step_init(1, 2305);
    StreamingWindowSelector <
        std::array<ap_uint<8>, 1>,  // TWord
        14,  // IN_HEIGHT
        14,  // IN_WIDTH
        384,  // IN_CH
        3,  // FH
        3,  // FW
        1,  // STRIDE_H
        1,  // STRIDE_W
        1,  // DILATION_H
        1,  // DILATION_W
        1,  // PAD_T
        1,  // PAD_L
        1,  // PAD_B
        1,  // PAD_R
        1,  // POS_H
        1,  // POS_W
        2,  // W_PAR
        1  // CH_PAR
    > StreamingLineBuffer_21_pixel_6;
    StreamingLineBuffer_21_pixel_6.step_init(1, 385);
    StreamingWindowSelector <
        std::array<ap_uint<8>, 1>,  // TWord
        14,  // IN_HEIGHT
        14,  // IN_WIDTH
        384,  // IN_CH
        3,  // FH
        3,  // FW
        1,  // STRIDE_H
        1,  // STRIDE_W
        1,  // DILATION_H
        1,  // DILATION_W
        1,  // PAD_T
        1,  // PAD_L
        1,  // PAD_B
        1,  // PAD_R
        1,  // POS_H
        0,  // POS_W
        2,  // W_PAR
        1  // CH_PAR
    > StreamingLineBuffer_21_pixel_7;
    StreamingLineBuffer_21_pixel_7.step_init(2, 385);
    StreamingWindowSelector <
        std::array<ap_uint<8>, 1>,  // TWord
        14,  // IN_HEIGHT
        14,  // IN_WIDTH
        384,  // IN_CH
        3,  // FH
        3,  // FW
        1,  // STRIDE_H
        1,  // STRIDE_W
        1,  // DILATION_H
        1,  // DILATION_W
        1,  // PAD_T
        1,  // PAD_L
        1,  // PAD_B
        1,  // PAD_R
        0,  // POS_H
        3,  // POS_W
        2,  // W_PAR
        1  // CH_PAR
    > StreamingLineBuffer_21_pixel_8;
    StreamingLineBuffer_21_pixel_8.step_init(2, 2305);
    StreamingWindowSelector <
        std::array<ap_uint<8>, 1>,  // TWord
        14,  // IN_HEIGHT
        14,  // IN_WIDTH
        384,  // IN_CH
        3,  // FH
        3,  // FW
        1,  // STRIDE_H
        1,  // STRIDE_W
        1,  // DILATION_H
        1,  // DILATION_W
        1,  // PAD_T
        1,  // PAD_L
        1,  // PAD_B
        1,  // PAD_R
        0,  // POS_H
        2,  // POS_W
        2,  // W_PAR
        1  // CH_PAR
    > StreamingLineBuffer_21_pixel_9;
    StreamingLineBuffer_21_pixel_9.step_init(2, 2305);
    StreamingWindowSelector <
        std::array<ap_uint<8>, 1>,  // TWord
        14,  // IN_HEIGHT
        14,  // IN_WIDTH
        384,  // IN_CH
        3,  // FH
        3,  // FW
        1,  // STRIDE_H
        1,  // STRIDE_W
        1,  // DILATION_H
        1,  // DILATION_W
        1,  // PAD_T
        1,  // PAD_L
        1,  // PAD_B
        1,  // PAD_R
        0,  // POS_H
        1,  // POS_W
        2,  // W_PAR
        1  // CH_PAR
    > StreamingLineBuffer_21_pixel_10;
    StreamingLineBuffer_21_pixel_10.step_init(1, 385);
    StreamingWindowSelector <
        std::array<ap_uint<8>, 1>,  // TWord
        14,  // IN_HEIGHT
        14,  // IN_WIDTH
        384,  // IN_CH
        3,  // FH
        3,  // FW
        1,  // STRIDE_H
        1,  // STRIDE_W
        1,  // DILATION_H
        1,  // DILATION_W
        1,  // PAD_T
        1,  // PAD_L
        1,  // PAD_B
        1,  // PAD_R
        0,  // POS_H
        0,  // POS_W
        2,  // W_PAR
        1  // CH_PAR
    > StreamingLineBuffer_21_pixel_11;
    StreamingLineBuffer_21_pixel_11.step_init(1, 385);
    StreamingPad <
        std::array<ap_uint<8>, 1>,  // TWord
        ap_uint<8>,  // TData
        14,  // IN_HEIGHT
        14,  // IN_WIDTH
        384,  // IN_CH
        3,  // FH
        3,  // FW
        1,  // STRIDE_H
        1,  // STRIDE_W
        1,  // DILATION_H
        1,  // DILATION_W
        1,  // PAD_T
        1,  // PAD_L
        1,  // PAD_B
        1,  // PAD_R
        2,  // W_PAR
        1,  // CH_PAR
        0  // PAD_VALUE
    > StreamingLineBuffer_21_pad;
    StreamingLineBuffer_21_pad.step_init(3);
    StreamingDepthwiseConv <
        std::array<ap_uint<8>, 1>,  // TInputStruct
        ap_uint<8>,  // TInput
        std::array<ap_int<8>, 1>,  // TWeightStruct
        ap_int<8>,  // TWeight
        std::array<ap_int<14>, 1>,  // TBiasStruct
        ap_int<14>,  // TBias
        std::array<ap_uint<8>, 1>,  // TOutputStruct
        ap_uint<8>,  // TOutput
        ap_int<21>,  // TSum
        ap_int<20>,  // TPartialSum
        ReLU<ap_int<21>>,  // Activation
        DequantQuantPo2<5, ap_int<21>, ap_uint<8>>,  // Quantizer
        384,  // OUT_CH
        384,  // IN_CH
        14,  // IN_HEIGHT
        14,  // IN_WIDTH
        3,  // FH
        3,  // FW
        1,  // STRIDE_H
        1,  // STRIDE_W
        1,  // CH_PAR
        2  // W_PAR
    > StreamingDepthwiseConv_7;
    StreamingDepthwiseConv_7.step_init(8);
    BandwidthAdjustIncreaseChannels <
        std::array<ap_uint<8>, 1>,  // TInputStruct
        ap_uint<8>,  // TInput
        std::array<ap_uint<8>, 3>,  // TOutputStruct
        ap_uint<8>,  // TOutput
        DequantQuantEqual<ap_uint<8>>,  // Quantizer
        14,  // IN_HEIGHT
        14,  // IN_WIDTH
        384,  // IN_CH
        2,  // IN_W_PAR
        2,  // OUT_W_PAR
        1,  // IN_CH_PAR
        3  // OUT_CH_PAR
    > BandwidthAdjustIncreaseChannels_13;
    BandwidthAdjustIncreaseChannels_13.step_init(2);
    StreamingWindowSelector <
        std::array<ap_uint<8>, 3>,  // TWord
        14,  // IN_HEIGHT
        14,  // IN_WIDTH
        384,  // IN_CH
        1,  // FH
        1,  // FW
        1,  // STRIDE_H
        1,  // STRIDE_W
        1,  // DILATION_H
        1,  // DILATION_W
        0,  // PAD_T
        0,  // PAD_L
        0,  // PAD_B
        0,  // PAD_R
        0,  // POS_H
        1,  // POS_W
        2,  // W_PAR
        3  // CH_PAR
    > StreamingLineBuffer_22_pixel_0;
    StreamingLineBuffer_22_pixel_0.step_init(1, 1);
    StreamingWindowSelector <
        std::array<ap_uint<8>, 3>,  // TWord
        14,  // IN_HEIGHT
        14,  // IN_WIDTH
        384,  // IN_CH
        1,  // FH
        1,  // FW
        1,  // STRIDE_H
        1,  // STRIDE_W
        1,  // DILATION_H
        1,  // DILATION_W
        0,  // PAD_T
        0,  // PAD_L
        0,  // PAD_B
        0,  // PAD_R
        0,  // POS_H
        0,  // POS_W
        2,  // W_PAR
        3  // CH_PAR
    > StreamingLineBuffer_22_pixel_1;
    StreamingLineBuffer_22_pixel_1.step_init(1, 1);
    StreamingConv <
        std::array<ap_uint<8>, 3>,  // TInputWord
        ap_uint<8>,  // TInput
        std::array<ap_int<8>, 12>,  // TWeightWord
        ap_int<8>,  // TWeight
        std::array<ap_int<16>, 4>,  // TBiasWord
        ap_int<16>,  // TBias
        std::array<ap_int<8>, 4>,  // TOutputWord
        ap_int<8>,  // TOutput
        ap_int<27>,  // TSum
        ap_int<26>,  // TPartialSum
        DequantQuantEqual<ap_int<27>>,  // Activation
        DequantQuantPo2<9, ap_int<27>, ap_int<8>>,  // Quantizer
        64,  // OUT_CH
        384,  // IN_CH
        14,  // OUT_HEIGHT
        14,  // OUT_WIDTH
        1,  // GROUP
        1,  // FH
        1,  // FW
        1,  // STRIDE_H
        1,  // STRIDE_W
        3,  // IN_CH_PAR
        4,  // OUT_CH_PAR
        2  // W_PAR
    > StreamingConv_15;
    StreamingConv_15.step_init(9);
    StreamingAdd <
        std::array<ap_int<8>, 4>,  // TInputWordA
        ap_int<8>,  // TInputA
        std::array<ap_int<8>, 4>,  // TInputWordB
        ap_int<8>,  // TInputB
        std::array<ap_int<8>, 4>,  // TOutputWord
        ap_int<8>,  // TOutput
        ap_int<9>,  // TAcc
        DequantQuantEqual<ap_int<9>>,  // Activation
        DequantQuantPo2<0, ap_int<9>, ap_int<8>>,  // Quantizer
        DequantQuantEqual<ap_int<8>>,  // AlignA
        DequantQuantEqual<ap_int<8>>,  // AlignB
        14,  // IN_HEIGHT
        14,  // IN_WIDTH
        64,  // IN_CH
        2,  // W_PAR
        4  // CH_PAR
    > StreamingAdd_3;
    StreamingAdd_3.step_init(2);
    BandwidthAdjustDecreaseStreams <
        std::array<ap_int<8>, 4>,  // TInputStruct
        ap_int<8>,  // TInput
        std::array<ap_int<8>, 4>,  // TOutputStruct
        ap_int<8>,  // TOutput
        DequantQuantEqual<ap_int<8>>,  // Quantizer
        14,  // IN_HEIGHT
        14,  // IN_WIDTH
        64,  // IN_CH
        2,  // IN_W_PAR
        1,  // OUT_W_PAR
        4,  // IN_CH_PAR
        4  // OUT_CH_PAR
    > BandwidthAdjustDecreaseStreams_4;
    BandwidthAdjustDecreaseStreams_4.step_init(2);
    TensorDuplicator <
        std::array<ap_int<8>, 4>,  // TWord
        14,  // IN_HEIGHT
        14,  // IN_WIDTH
        64,  // IN_CH
        4,  // CH_PAR
        1  // W_PAR
    > TensorDuplicator_4;
    TensorDuplicator_4.step_init(1);
    BandwidthAdjustIncreaseStreams <
        std::array<ap_int<8>, 4>,  // TInputStruct
        ap_int<8>,  // TInput
        std::array<ap_int<8>, 4>,  // TOutputStruct
        ap_int<8>,  // TOutput
        DequantQuantEqual<ap_int<8>>,  // Quantizer
        14,  // IN_HEIGHT
        14,  // IN_WIDTH
        64,  // IN_CH
        1,  // IN_W_PAR
        2,  // OUT_W_PAR
        4,  // IN_CH_PAR
        4  // OUT_CH_PAR
    > BandwidthAdjustIncreaseStreams_4;
    BandwidthAdjustIncreaseStreams_4.step_init(1);
    BandwidthAdjustIncreaseStreams <
        std::array<ap_int<8>, 4>,  // TInputStruct
        ap_int<8>,  // TInput
        std::array<ap_int<8>, 4>,  // TOutputStruct
        ap_int<8>,  // TOutput
        DequantQuantEqual<ap_int<8>>,  // Quantizer
        14,  // IN_HEIGHT
        14,  // IN_WIDTH
        64,  // IN_CH
        1,  // IN_W_PAR
        2,  // OUT_W_PAR
        4,  // IN_CH_PAR
        4  // OUT_CH_PAR
    > BandwidthAdjustIncreaseStreams_5;
    BandwidthAdjustIncreaseStreams_5.step_init(1);
    StreamingWindowSelector <
        std::array<ap_int<8>, 4>,  // TWord
        14,  // IN_HEIGHT
        14,  // IN_WIDTH
        64,  // IN_CH
        1,  // FH
        1,  // FW
        1,  // STRIDE_H
        1,  // STRIDE_W
        1,  // DILATION_H
        1,  // DILATION_W
        0,  // PAD_T
        0,  // PAD_L
        0,  // PAD_B
        0,  // PAD_R
        0,  // POS_H
        1,  // POS_W
        2,  // W_PAR
        4  // CH_PAR
    > StreamingLineBuffer_23_pixel_0;
    StreamingLineBuffer_23_pixel_0.step_init(1, 1);
    StreamingWindowSelector <
        std::array<ap_int<8>, 4>,  // TWord
        14,  // IN_HEIGHT
        14,  // IN_WIDTH
        64,  // IN_CH
        1,  // FH
        1,  // FW
        1,  // STRIDE_H
        1,  // STRIDE_W
        1,  // DILATION_H
        1,  // DILATION_W
        0,  // PAD_T
        0,  // PAD_L
        0,  // PAD_B
        0,  // PAD_R
        0,  // POS_H
        0,  // POS_W
        2,  // W_PAR
        4  // CH_PAR
    > StreamingLineBuffer_23_pixel_1;
    StreamingLineBuffer_23_pixel_1.step_init(1, 1);
    StreamingConv <
        std::array<ap_int<8>, 4>,  // TInputWord
        ap_int<8>,  // TInput
        std::array<ap_int<8>, 12>,  // TWeightWord
        ap_int<8>,  // TWeight
        std::array<ap_int<16>, 3>,  // TBiasWord
        ap_int<16>,  // TBias
        std::array<ap_uint<8>, 3>,  // TOutputWord
        ap_uint<8>,  // TOutput
        ap_int<24>,  // TSum
        ap_int<23>,  // TPartialSum
        ReLU<ap_int<24>>,  // Activation
        DequantQuantPo2<8, ap_int<24>, ap_uint<8>>,  // Quantizer
        384,  // OUT_CH
        64,  // IN_CH
        14,  // OUT_HEIGHT
        14,  // OUT_WIDTH
        1,  // GROUP
        1,  // FH
        1,  // FW
        1,  // STRIDE_H
        1,  // STRIDE_W
        4,  // IN_CH_PAR
        3,  // OUT_CH_PAR
        2  // W_PAR
    > StreamingConv_16;
    StreamingConv_16.step_init(9);
    BandwidthAdjustDecreaseChannels <
        std::array<ap_uint<8>, 3>,  // TInputStruct
        ap_uint<8>,  // TInput
        std::array<ap_uint<8>, 1>,  // TOutputStruct
        ap_uint<8>,  // TOutput
        DequantQuantEqual<ap_uint<8>>,  // Quantizer
        14,  // IN_HEIGHT
        14,  // IN_WIDTH
        384,  // IN_CH
        2,  // IN_W_PAR
        2,  // OUT_W_PAR
        3,  // IN_CH_PAR
        1  // OUT_CH_PAR
    > BandwidthAdjustDecreaseChannels_9;
    BandwidthAdjustDecreaseChannels_9.step_init(2);
    StreamingWindowSelector <
        std::array<ap_uint<8>, 1>,  // TWord
        14,  // IN_HEIGHT
        14,  // IN_WIDTH
        384,  // IN_CH
        3,  // FH
        3,  // FW
        1,  // STRIDE_H
        1,  // STRIDE_W
        1,  // DILATION_H
        1,  // DILATION_W
        1,  // PAD_T
        1,  // PAD_L
        1,  // PAD_B
        1,  // PAD_R
        2,  // POS_H
        3,  // POS_W
        2,  // W_PAR
        1  // CH_PAR
    > StreamingLineBuffer_24_pixel_0;
    StreamingLineBuffer_24_pixel_0.step_init(2, 1);
    StreamingWindowSelector <
        std::array<ap_uint<8>, 1>,  // TWord
        14,  // IN_HEIGHT
        14,  // IN_WIDTH
        384,  // IN_CH
        3,  // FH
        3,  // FW
        1,  // STRIDE_H
        1,  // STRIDE_W
        1,  // DILATION_H
        1,  // DILATION_W
        1,  // PAD_T
        1,  // PAD_L
        1,  // PAD_B
        1,  // PAD_R
        2,  // POS_H
        2,  // POS_W
        2,  // W_PAR
        1  // CH_PAR
    > StreamingLineBuffer_24_pixel_1;
    StreamingLineBuffer_24_pixel_1.step_init(2, 1);
    StreamingWindowSelector <
        std::array<ap_uint<8>, 1>,  // TWord
        14,  // IN_HEIGHT
        14,  // IN_WIDTH
        384,  // IN_CH
        3,  // FH
        3,  // FW
        1,  // STRIDE_H
        1,  // STRIDE_W
        1,  // DILATION_H
        1,  // DILATION_W
        1,  // PAD_T
        1,  // PAD_L
        1,  // PAD_B
        1,  // PAD_R
        2,  // POS_H
        1,  // POS_W
        2,  // W_PAR
        1  // CH_PAR
    > StreamingLineBuffer_24_pixel_2;
    StreamingLineBuffer_24_pixel_2.step_init(2, 385);
    StreamingWindowSelector <
        std::array<ap_uint<8>, 1>,  // TWord
        14,  // IN_HEIGHT
        14,  // IN_WIDTH
        384,  // IN_CH
        3,  // FH
        3,  // FW
        1,  // STRIDE_H
        1,  // STRIDE_W
        1,  // DILATION_H
        1,  // DILATION_W
        1,  // PAD_T
        1,  // PAD_L
        1,  // PAD_B
        1,  // PAD_R
        2,  // POS_H
        0,  // POS_W
        2,  // W_PAR
        1  // CH_PAR
    > StreamingLineBuffer_24_pixel_3;
    StreamingLineBuffer_24_pixel_3.step_init(2, 385);
    StreamingWindowSelector <
        std::array<ap_uint<8>, 1>,  // TWord
        14,  // IN_HEIGHT
        14,  // IN_WIDTH
        384,  // IN_CH
        3,  // FH
        3,  // FW
        1,  // STRIDE_H
        1,  // STRIDE_W
        1,  // DILATION_H
        1,  // DILATION_W
        1,  // PAD_T
        1,  // PAD_L
        1,  // PAD_B
        1,  // PAD_R
        1,  // POS_H
        3,  // POS_W
        2,  // W_PAR
        1  // CH_PAR
    > StreamingLineBuffer_24_pixel_4;
    StreamingLineBuffer_24_pixel_4.step_init(2, 2305);
    StreamingWindowSelector <
        std::array<ap_uint<8>, 1>,  // TWord
        14,  // IN_HEIGHT
        14,  // IN_WIDTH
        384,  // IN_CH
        3,  // FH
        3,  // FW
        1,  // STRIDE_H
        1,  // STRIDE_W
        1,  // DILATION_H
        1,  // DILATION_W
        1,  // PAD_T
        1,  // PAD_L
        1,  // PAD_B
        1,  // PAD_R
        1,  // POS_H
        2,  // POS_W
        2,  // W_PAR
        1  // CH_PAR
    > StreamingLineBuffer_24_pixel_5;
    StreamingLineBuffer_24_pixel_5.step_init(1, 2305);
    StreamingWindowSelector <
        std::array<ap_uint<8>, 1>,  // TWord
        14,  // IN_HEIGHT
        14,  // IN_WIDTH
        384,  // IN_CH
        3,  // FH
        3,  // FW
        1,  // STRIDE_H
        1,  // STRIDE_W
        1,  // DILATION_H
        1,  // DILATION_W
        1,  // PAD_T
        1,  // PAD_L
        1,  // PAD_B
        1,  // PAD_R
        1,  // POS_H
        1,  // POS_W
        2,  // W_PAR
        1  // CH_PAR
    > StreamingLineBuffer_24_pixel_6;
    StreamingLineBuffer_24_pixel_6.step_init(1, 385);
    StreamingWindowSelector <
        std::array<ap_uint<8>, 1>,  // TWord
        14,  // IN_HEIGHT
        14,  // IN_WIDTH
        384,  // IN_CH
        3,  // FH
        3,  // FW
        1,  // STRIDE_H
        1,  // STRIDE_W
        1,  // DILATION_H
        1,  // DILATION_W
        1,  // PAD_T
        1,  // PAD_L
        1,  // PAD_B
        1,  // PAD_R
        1,  // POS_H
        0,  // POS_W
        2,  // W_PAR
        1  // CH_PAR
    > StreamingLineBuffer_24_pixel_7;
    StreamingLineBuffer_24_pixel_7.step_init(2, 385);
    StreamingWindowSelector <
        std::array<ap_uint<8>, 1>,  // TWord
        14,  // IN_HEIGHT
        14,  // IN_WIDTH
        384,  // IN_CH
        3,  // FH
        3,  // FW
        1,  // STRIDE_H
        1,  // STRIDE_W
        1,  // DILATION_H
        1,  // DILATION_W
        1,  // PAD_T
        1,  // PAD_L
        1,  // PAD_B
        1,  // PAD_R
        0,  // POS_H
        3,  // POS_W
        2,  // W_PAR
        1  // CH_PAR
    > StreamingLineBuffer_24_pixel_8;
    StreamingLineBuffer_24_pixel_8.step_init(2, 2305);
    StreamingWindowSelector <
        std::array<ap_uint<8>, 1>,  // TWord
        14,  // IN_HEIGHT
        14,  // IN_WIDTH
        384,  // IN_CH
        3,  // FH
        3,  // FW
        1,  // STRIDE_H
        1,  // STRIDE_W
        1,  // DILATION_H
        1,  // DILATION_W
        1,  // PAD_T
        1,  // PAD_L
        1,  // PAD_B
        1,  // PAD_R
        0,  // POS_H
        2,  // POS_W
        2,  // W_PAR
        1  // CH_PAR
    > StreamingLineBuffer_24_pixel_9;
    StreamingLineBuffer_24_pixel_9.step_init(2, 2305);
    StreamingWindowSelector <
        std::array<ap_uint<8>, 1>,  // TWord
        14,  // IN_HEIGHT
        14,  // IN_WIDTH
        384,  // IN_CH
        3,  // FH
        3,  // FW
        1,  // STRIDE_H
        1,  // STRIDE_W
        1,  // DILATION_H
        1,  // DILATION_W
        1,  // PAD_T
        1,  // PAD_L
        1,  // PAD_B
        1,  // PAD_R
        0,  // POS_H
        1,  // POS_W
        2,  // W_PAR
        1  // CH_PAR
    > StreamingLineBuffer_24_pixel_10;
    StreamingLineBuffer_24_pixel_10.step_init(1, 385);
    StreamingWindowSelector <
        std::array<ap_uint<8>, 1>,  // TWord
        14,  // IN_HEIGHT
        14,  // IN_WIDTH
        384,  // IN_CH
        3,  // FH
        3,  // FW
        1,  // STRIDE_H
        1,  // STRIDE_W
        1,  // DILATION_H
        1,  // DILATION_W
        1,  // PAD_T
        1,  // PAD_L
        1,  // PAD_B
        1,  // PAD_R
        0,  // POS_H
        0,  // POS_W
        2,  // W_PAR
        1  // CH_PAR
    > StreamingLineBuffer_24_pixel_11;
    StreamingLineBuffer_24_pixel_11.step_init(1, 385);
    StreamingPad <
        std::array<ap_uint<8>, 1>,  // TWord
        ap_uint<8>,  // TData
        14,  // IN_HEIGHT
        14,  // IN_WIDTH
        384,  // IN_CH
        3,  // FH
        3,  // FW
        1,  // STRIDE_H
        1,  // STRIDE_W
        1,  // DILATION_H
        1,  // DILATION_W
        1,  // PAD_T
        1,  // PAD_L
        1,  // PAD_B
        1,  // PAD_R
        2,  // W_PAR
        1,  // CH_PAR
        0  // PAD_VALUE
    > StreamingLineBuffer_24_pad;
    StreamingLineBuffer_24_pad.step_init(3);
    StreamingDepthwiseConv <
        std::array<ap_uint<8>, 1>,  // TInputStruct
        ap_uint<8>,  // TInput
        std::array<ap_int<8>, 1>,  // TWeightStruct
        ap_int<8>,  // TWeight
        std::array<ap_int<14>, 1>,  // TBiasStruct
        ap_int<14>,  // TBias
        std::array<ap_uint<8>, 1>,  // TOutputStruct
        ap_uint<8>,  // TOutput
        ap_int<21>,  // TSum
        ap_int<20>,  // TPartialSum
        ReLU<ap_int<21>>,  // Activation
        DequantQuantPo2<5, ap_int<21>, ap_uint<8>>,  // Quantizer
        384,  // OUT_CH
        384,  // IN_CH
        14,  // IN_HEIGHT
        14,  // IN_WIDTH
        3,  // FH
        3,  // FW
        1,  // STRIDE_H
        1,  // STRIDE_W
        1,  // CH_PAR
        2  // W_PAR
    > StreamingDepthwiseConv_8;
    StreamingDepthwiseConv_8.step_init(8);
    BandwidthAdjustIncreaseChannels <
        std::array<ap_uint<8>, 1>,  // TInputStruct
        ap_uint<8>,  // TInput
        std::array<ap_uint<8>, 3>,  // TOutputStruct
        ap_uint<8>,  // TOutput
        DequantQuantEqual<ap_uint<8>>,  // Quantizer
        14,  // IN_HEIGHT
        14,  // IN_WIDTH
        384,  // IN_CH
        2,  // IN_W_PAR
        2,  // OUT_W_PAR
        1,  // IN_CH_PAR
        3  // OUT_CH_PAR
    > BandwidthAdjustIncreaseChannels_14;
    BandwidthAdjustIncreaseChannels_14.step_init(2);
    StreamingWindowSelector <
        std::array<ap_uint<8>, 3>,  // TWord
        14,  // IN_HEIGHT
        14,  // IN_WIDTH
        384,  // IN_CH
        1,  // FH
        1,  // FW
        1,  // STRIDE_H
        1,  // STRIDE_W
        1,  // DILATION_H
        1,  // DILATION_W
        0,  // PAD_T
        0,  // PAD_L
        0,  // PAD_B
        0,  // PAD_R
        0,  // POS_H
        1,  // POS_W
        2,  // W_PAR
        3  // CH_PAR
    > StreamingLineBuffer_25_pixel_0;
    StreamingLineBuffer_25_pixel_0.step_init(1, 1);
    StreamingWindowSelector <
        std::array<ap_uint<8>, 3>,  // TWord
        14,  // IN_HEIGHT
        14,  // IN_WIDTH
        384,  // IN_CH
        1,  // FH
        1,  // FW
        1,  // STRIDE_H
        1,  // STRIDE_W
        1,  // DILATION_H
        1,  // DILATION_W
        0,  // PAD_T
        0,  // PAD_L
        0,  // PAD_B
        0,  // PAD_R
        0,  // POS_H
        0,  // POS_W
        2,  // W_PAR
        3  // CH_PAR
    > StreamingLineBuffer_25_pixel_1;
    StreamingLineBuffer_25_pixel_1.step_init(1, 1);
    StreamingConv <
        std::array<ap_uint<8>, 3>,  // TInputWord
        ap_uint<8>,  // TInput
        std::array<ap_int<8>, 12>,  // TWeightWord
        ap_int<8>,  // TWeight
        std::array<ap_int<15>, 4>,  // TBiasWord
        ap_int<15>,  // TBias
        std::array<ap_int<8>, 4>,  // TOutputWord
        ap_int<8>,  // TOutput
        ap_int<27>,  // TSum
        ap_int<26>,  // TPartialSum
        DequantQuantEqual<ap_int<27>>,  // Activation
        DequantQuantPo2<9, ap_int<27>, ap_int<8>>,  // Quantizer
        64,  // OUT_CH
        384,  // IN_CH
        14,  // OUT_HEIGHT
        14,  // OUT_WIDTH
        1,  // GROUP
        1,  // FH
        1,  // FW
        1,  // STRIDE_H
        1,  // STRIDE_W
        3,  // IN_CH_PAR
        4,  // OUT_CH_PAR
        2  // W_PAR
    > StreamingConv_17;
    StreamingConv_17.step_init(9);
    StreamingAdd <
        std::array<ap_int<8>, 4>,  // TInputWordA
        ap_int<8>,  // TInputA
        std::array<ap_int<8>, 4>,  // TInputWordB
        ap_int<8>,  // TInputB
        std::array<ap_int<8>, 4>,  // TOutputWord
        ap_int<8>,  // TOutput
        ap_int<9>,  // TAcc
        DequantQuantEqual<ap_int<9>>,  // Activation
        DequantQuantPo2<0, ap_int<9>, ap_int<8>>,  // Quantizer
        DequantQuantEqual<ap_int<8>>,  // AlignA
        DequantQuantEqual<ap_int<8>>,  // AlignB
        14,  // IN_HEIGHT
        14,  // IN_WIDTH
        64,  // IN_CH
        2,  // W_PAR
        4  // CH_PAR
    > StreamingAdd_4;
    StreamingAdd_4.step_init(2);
    BandwidthAdjustDecreaseStreams <
        std::array<ap_int<8>, 4>,  // TInputStruct
        ap_int<8>,  // TInput
        std::array<ap_int<8>, 4>,  // TOutputStruct
        ap_int<8>,  // TOutput
        DequantQuantEqual<ap_int<8>>,  // Quantizer
        14,  // IN_HEIGHT
        14,  // IN_WIDTH
        64,  // IN_CH
        2,  // IN_W_PAR
        1,  // OUT_W_PAR
        4,  // IN_CH_PAR
        4  // OUT_CH_PAR
    > BandwidthAdjustDecreaseStreams_5;
    BandwidthAdjustDecreaseStreams_5.step_init(2);
    TensorDuplicator <
        std::array<ap_int<8>, 4>,  // TWord
        14,  // IN_HEIGHT
        14,  // IN_WIDTH
        64,  // IN_CH
        4,  // CH_PAR
        1  // W_PAR
    > TensorDuplicator_5;
    TensorDuplicator_5.step_init(1);
    BandwidthAdjustIncreaseStreams <
        std::array<ap_int<8>, 4>,  // TInputStruct
        ap_int<8>,  // TInput
        std::array<ap_int<8>, 4>,  // TOutputStruct
        ap_int<8>,  // TOutput
        DequantQuantEqual<ap_int<8>>,  // Quantizer
        14,  // IN_HEIGHT
        14,  // IN_WIDTH
        64,  // IN_CH
        1,  // IN_W_PAR
        2,  // OUT_W_PAR
        4,  // IN_CH_PAR
        4  // OUT_CH_PAR
    > BandwidthAdjustIncreaseStreams_6;
    BandwidthAdjustIncreaseStreams_6.step_init(1);
    BandwidthAdjustIncreaseStreams <
        std::array<ap_int<8>, 4>,  // TInputStruct
        ap_int<8>,  // TInput
        std::array<ap_int<8>, 4>,  // TOutputStruct
        ap_int<8>,  // TOutput
        DequantQuantEqual<ap_int<8>>,  // Quantizer
        14,  // IN_HEIGHT
        14,  // IN_WIDTH
        64,  // IN_CH
        1,  // IN_W_PAR
        2,  // OUT_W_PAR
        4,  // IN_CH_PAR
        4  // OUT_CH_PAR
    > BandwidthAdjustIncreaseStreams_7;
    BandwidthAdjustIncreaseStreams_7.step_init(1);
    StreamingWindowSelector <
        std::array<ap_int<8>, 4>,  // TWord
        14,  // IN_HEIGHT
        14,  // IN_WIDTH
        64,  // IN_CH
        1,  // FH
        1,  // FW
        1,  // STRIDE_H
        1,  // STRIDE_W
        1,  // DILATION_H
        1,  // DILATION_W
        0,  // PAD_T
        0,  // PAD_L
        0,  // PAD_B
        0,  // PAD_R
        0,  // POS_H
        1,  // POS_W
        2,  // W_PAR
        4  // CH_PAR
    > StreamingLineBuffer_26_pixel_0;
    StreamingLineBuffer_26_pixel_0.step_init(1, 1);
    StreamingWindowSelector <
        std::array<ap_int<8>, 4>,  // TWord
        14,  // IN_HEIGHT
        14,  // IN_WIDTH
        64,  // IN_CH
        1,  // FH
        1,  // FW
        1,  // STRIDE_H
        1,  // STRIDE_W
        1,  // DILATION_H
        1,  // DILATION_W
        0,  // PAD_T
        0,  // PAD_L
        0,  // PAD_B
        0,  // PAD_R
        0,  // POS_H
        0,  // POS_W
        2,  // W_PAR
        4  // CH_PAR
    > StreamingLineBuffer_26_pixel_1;
    StreamingLineBuffer_26_pixel_1.step_init(1, 1);
    StreamingConv <
        std::array<ap_int<8>, 4>,  // TInputWord
        ap_int<8>,  // TInput
        std::array<ap_int<8>, 12>,  // TWeightWord
        ap_int<8>,  // TWeight
        std::array<ap_int<14>, 3>,  // TBiasWord
        ap_int<14>,  // TBias
        std::array<ap_uint<8>, 3>,  // TOutputWord
        ap_uint<8>,  // TOutput
        ap_int<24>,  // TSum
        ap_int<23>,  // TPartialSum
        ReLU<ap_int<24>>,  // Activation
        DequantQuantPo2<7, ap_int<24>, ap_uint<8>>,  // Quantizer
        384,  // OUT_CH
        64,  // IN_CH
        14,  // OUT_HEIGHT
        14,  // OUT_WIDTH
        1,  // GROUP
        1,  // FH
        1,  // FW
        1,  // STRIDE_H
        1,  // STRIDE_W
        4,  // IN_CH_PAR
        3,  // OUT_CH_PAR
        2  // W_PAR
    > StreamingConv_18;
    StreamingConv_18.step_init(9);
    BandwidthAdjustDecreaseChannels <
        std::array<ap_uint<8>, 3>,  // TInputStruct
        ap_uint<8>,  // TInput
        std::array<ap_uint<8>, 1>,  // TOutputStruct
        ap_uint<8>,  // TOutput
        DequantQuantEqual<ap_uint<8>>,  // Quantizer
        14,  // IN_HEIGHT
        14,  // IN_WIDTH
        384,  // IN_CH
        2,  // IN_W_PAR
        2,  // OUT_W_PAR
        3,  // IN_CH_PAR
        1  // OUT_CH_PAR
    > BandwidthAdjustDecreaseChannels_10;
    BandwidthAdjustDecreaseChannels_10.step_init(2);
    StreamingWindowSelector <
        std::array<ap_uint<8>, 1>,  // TWord
        14,  // IN_HEIGHT
        14,  // IN_WIDTH
        384,  // IN_CH
        3,  // FH
        3,  // FW
        1,  // STRIDE_H
        1,  // STRIDE_W
        1,  // DILATION_H
        1,  // DILATION_W
        1,  // PAD_T
        1,  // PAD_L
        1,  // PAD_B
        1,  // PAD_R
        2,  // POS_H
        3,  // POS_W
        2,  // W_PAR
        1  // CH_PAR
    > StreamingLineBuffer_27_pixel_0;
    StreamingLineBuffer_27_pixel_0.step_init(2, 1);
    StreamingWindowSelector <
        std::array<ap_uint<8>, 1>,  // TWord
        14,  // IN_HEIGHT
        14,  // IN_WIDTH
        384,  // IN_CH
        3,  // FH
        3,  // FW
        1,  // STRIDE_H
        1,  // STRIDE_W
        1,  // DILATION_H
        1,  // DILATION_W
        1,  // PAD_T
        1,  // PAD_L
        1,  // PAD_B
        1,  // PAD_R
        2,  // POS_H
        2,  // POS_W
        2,  // W_PAR
        1  // CH_PAR
    > StreamingLineBuffer_27_pixel_1;
    StreamingLineBuffer_27_pixel_1.step_init(2, 1);
    StreamingWindowSelector <
        std::array<ap_uint<8>, 1>,  // TWord
        14,  // IN_HEIGHT
        14,  // IN_WIDTH
        384,  // IN_CH
        3,  // FH
        3,  // FW
        1,  // STRIDE_H
        1,  // STRIDE_W
        1,  // DILATION_H
        1,  // DILATION_W
        1,  // PAD_T
        1,  // PAD_L
        1,  // PAD_B
        1,  // PAD_R
        2,  // POS_H
        1,  // POS_W
        2,  // W_PAR
        1  // CH_PAR
    > StreamingLineBuffer_27_pixel_2;
    StreamingLineBuffer_27_pixel_2.step_init(2, 385);
    StreamingWindowSelector <
        std::array<ap_uint<8>, 1>,  // TWord
        14,  // IN_HEIGHT
        14,  // IN_WIDTH
        384,  // IN_CH
        3,  // FH
        3,  // FW
        1,  // STRIDE_H
        1,  // STRIDE_W
        1,  // DILATION_H
        1,  // DILATION_W
        1,  // PAD_T
        1,  // PAD_L
        1,  // PAD_B
        1,  // PAD_R
        2,  // POS_H
        0,  // POS_W
        2,  // W_PAR
        1  // CH_PAR
    > StreamingLineBuffer_27_pixel_3;
    StreamingLineBuffer_27_pixel_3.step_init(2, 385);
    StreamingWindowSelector <
        std::array<ap_uint<8>, 1>,  // TWord
        14,  // IN_HEIGHT
        14,  // IN_WIDTH
        384,  // IN_CH
        3,  // FH
        3,  // FW
        1,  // STRIDE_H
        1,  // STRIDE_W
        1,  // DILATION_H
        1,  // DILATION_W
        1,  // PAD_T
        1,  // PAD_L
        1,  // PAD_B
        1,  // PAD_R
        1,  // POS_H
        3,  // POS_W
        2,  // W_PAR
        1  // CH_PAR
    > StreamingLineBuffer_27_pixel_4;
    StreamingLineBuffer_27_pixel_4.step_init(2, 2305);
    StreamingWindowSelector <
        std::array<ap_uint<8>, 1>,  // TWord
        14,  // IN_HEIGHT
        14,  // IN_WIDTH
        384,  // IN_CH
        3,  // FH
        3,  // FW
        1,  // STRIDE_H
        1,  // STRIDE_W
        1,  // DILATION_H
        1,  // DILATION_W
        1,  // PAD_T
        1,  // PAD_L
        1,  // PAD_B
        1,  // PAD_R
        1,  // POS_H
        2,  // POS_W
        2,  // W_PAR
        1  // CH_PAR
    > StreamingLineBuffer_27_pixel_5;
    StreamingLineBuffer_27_pixel_5.step_init(1, 2305);
    StreamingWindowSelector <
        std::array<ap_uint<8>, 1>,  // TWord
        14,  // IN_HEIGHT
        14,  // IN_WIDTH
        384,  // IN_CH
        3,  // FH
        3,  // FW
        1,  // STRIDE_H
        1,  // STRIDE_W
        1,  // DILATION_H
        1,  // DILATION_W
        1,  // PAD_T
        1,  // PAD_L
        1,  // PAD_B
        1,  // PAD_R
        1,  // POS_H
        1,  // POS_W
        2,  // W_PAR
        1  // CH_PAR
    > StreamingLineBuffer_27_pixel_6;
    StreamingLineBuffer_27_pixel_6.step_init(1, 385);
    StreamingWindowSelector <
        std::array<ap_uint<8>, 1>,  // TWord
        14,  // IN_HEIGHT
        14,  // IN_WIDTH
        384,  // IN_CH
        3,  // FH
        3,  // FW
        1,  // STRIDE_H
        1,  // STRIDE_W
        1,  // DILATION_H
        1,  // DILATION_W
        1,  // PAD_T
        1,  // PAD_L
        1,  // PAD_B
        1,  // PAD_R
        1,  // POS_H
        0,  // POS_W
        2,  // W_PAR
        1  // CH_PAR
    > StreamingLineBuffer_27_pixel_7;
    StreamingLineBuffer_27_pixel_7.step_init(2, 385);
    StreamingWindowSelector <
        std::array<ap_uint<8>, 1>,  // TWord
        14,  // IN_HEIGHT
        14,  // IN_WIDTH
        384,  // IN_CH
        3,  // FH
        3,  // FW
        1,  // STRIDE_H
        1,  // STRIDE_W
        1,  // DILATION_H
        1,  // DILATION_W
        1,  // PAD_T
        1,  // PAD_L
        1,  // PAD_B
        1,  // PAD_R
        0,  // POS_H
        3,  // POS_W
        2,  // W_PAR
        1  // CH_PAR
    > StreamingLineBuffer_27_pixel_8;
    StreamingLineBuffer_27_pixel_8.step_init(2, 2305);
    StreamingWindowSelector <
        std::array<ap_uint<8>, 1>,  // TWord
        14,  // IN_HEIGHT
        14,  // IN_WIDTH
        384,  // IN_CH
        3,  // FH
        3,  // FW
        1,  // STRIDE_H
        1,  // STRIDE_W
        1,  // DILATION_H
        1,  // DILATION_W
        1,  // PAD_T
        1,  // PAD_L
        1,  // PAD_B
        1,  // PAD_R
        0,  // POS_H
        2,  // POS_W
        2,  // W_PAR
        1  // CH_PAR
    > StreamingLineBuffer_27_pixel_9;
    StreamingLineBuffer_27_pixel_9.step_init(2, 2305);
    StreamingWindowSelector <
        std::array<ap_uint<8>, 1>,  // TWord
        14,  // IN_HEIGHT
        14,  // IN_WIDTH
        384,  // IN_CH
        3,  // FH
        3,  // FW
        1,  // STRIDE_H
        1,  // STRIDE_W
        1,  // DILATION_H
        1,  // DILATION_W
        1,  // PAD_T
        1,  // PAD_L
        1,  // PAD_B
        1,  // PAD_R
        0,  // POS_H
        1,  // POS_W
        2,  // W_PAR
        1  // CH_PAR
    > StreamingLineBuffer_27_pixel_10;
    StreamingLineBuffer_27_pixel_10.step_init(1, 385);
    StreamingWindowSelector <
        std::array<ap_uint<8>, 1>,  // TWord
        14,  // IN_HEIGHT
        14,  // IN_WIDTH
        384,  // IN_CH
        3,  // FH
        3,  // FW
        1,  // STRIDE_H
        1,  // STRIDE_W
        1,  // DILATION_H
        1,  // DILATION_W
        1,  // PAD_T
        1,  // PAD_L
        1,  // PAD_B
        1,  // PAD_R
        0,  // POS_H
        0,  // POS_W
        2,  // W_PAR
        1  // CH_PAR
    > StreamingLineBuffer_27_pixel_11;
    StreamingLineBuffer_27_pixel_11.step_init(1, 385);
    StreamingPad <
        std::array<ap_uint<8>, 1>,  // TWord
        ap_uint<8>,  // TData
        14,  // IN_HEIGHT
        14,  // IN_WIDTH
        384,  // IN_CH
        3,  // FH
        3,  // FW
        1,  // STRIDE_H
        1,  // STRIDE_W
        1,  // DILATION_H
        1,  // DILATION_W
        1,  // PAD_T
        1,  // PAD_L
        1,  // PAD_B
        1,  // PAD_R
        2,  // W_PAR
        1,  // CH_PAR
        0  // PAD_VALUE
    > StreamingLineBuffer_27_pad;
    StreamingLineBuffer_27_pad.step_init(3);
    StreamingDepthwiseConv <
        std::array<ap_uint<8>, 1>,  // TInputStruct
        ap_uint<8>,  // TInput
        std::array<ap_int<8>, 1>,  // TWeightStruct
        ap_int<8>,  // TWeight
        std::array<ap_int<14>, 1>,  // TBiasStruct
        ap_int<14>,  // TBias
        std::array<ap_uint<8>, 1>,  // TOutputStruct
        ap_uint<8>,  // TOutput
        ap_int<21>,  // TSum
        ap_int<20>,  // TPartialSum
        ReLU<ap_int<21>>,  // Activation
        DequantQuantPo2<5, ap_int<21>, ap_uint<8>>,  // Quantizer
        384,  // OUT_CH
        384,  // IN_CH
        14,  // IN_HEIGHT
        14,  // IN_WIDTH
        3,  // FH
        3,  // FW
        1,  // STRIDE_H
        1,  // STRIDE_W
        1,  // CH_PAR
        2  // W_PAR
    > StreamingDepthwiseConv_9;
    StreamingDepthwiseConv_9.step_init(8);
    BandwidthAdjustIncreaseChannels <
        std::array<ap_uint<8>, 1>,  // TInputStruct
        ap_uint<8>,  // TInput
        std::array<ap_uint<8>, 3>,  // TOutputStruct
        ap_uint<8>,  // TOutput
        DequantQuantEqual<ap_uint<8>>,  // Quantizer
        14,  // IN_HEIGHT
        14,  // IN_WIDTH
        384,  // IN_CH
        2,  // IN_W_PAR
        2,  // OUT_W_PAR
        1,  // IN_CH_PAR
        3  // OUT_CH_PAR
    > BandwidthAdjustIncreaseChannels_15;
    BandwidthAdjustIncreaseChannels_15.step_init(2);
    StreamingWindowSelector <
        std::array<ap_uint<8>, 3>,  // TWord
        14,  // IN_HEIGHT
        14,  // IN_WIDTH
        384,  // IN_CH
        1,  // FH
        1,  // FW
        1,  // STRIDE_H
        1,  // STRIDE_W
        1,  // DILATION_H
        1,  // DILATION_W
        0,  // PAD_T
        0,  // PAD_L
        0,  // PAD_B
        0,  // PAD_R
        0,  // POS_H
        1,  // POS_W
        2,  // W_PAR
        3  // CH_PAR
    > StreamingLineBuffer_28_pixel_0;
    StreamingLineBuffer_28_pixel_0.step_init(1, 1);
    StreamingWindowSelector <
        std::array<ap_uint<8>, 3>,  // TWord
        14,  // IN_HEIGHT
        14,  // IN_WIDTH
        384,  // IN_CH
        1,  // FH
        1,  // FW
        1,  // STRIDE_H
        1,  // STRIDE_W
        1,  // DILATION_H
        1,  // DILATION_W
        0,  // PAD_T
        0,  // PAD_L
        0,  // PAD_B
        0,  // PAD_R
        0,  // POS_H
        0,  // POS_W
        2,  // W_PAR
        3  // CH_PAR
    > StreamingLineBuffer_28_pixel_1;
    StreamingLineBuffer_28_pixel_1.step_init(1, 1);
    StreamingConv <
        std::array<ap_uint<8>, 3>,  // TInputWord
        ap_uint<8>,  // TInput
        std::array<ap_int<8>, 12>,  // TWeightWord
        ap_int<8>,  // TWeight
        std::array<ap_int<15>, 4>,  // TBiasWord
        ap_int<15>,  // TBias
        std::array<ap_int<8>, 4>,  // TOutputWord
        ap_int<8>,  // TOutput
        ap_int<27>,  // TSum
        ap_int<26>,  // TPartialSum
        DequantQuantEqual<ap_int<27>>,  // Activation
        DequantQuantPo2<9, ap_int<27>, ap_int<8>>,  // Quantizer
        64,  // OUT_CH
        384,  // IN_CH
        14,  // OUT_HEIGHT
        14,  // OUT_WIDTH
        1,  // GROUP
        1,  // FH
        1,  // FW
        1,  // STRIDE_H
        1,  // STRIDE_W
        3,  // IN_CH_PAR
        4,  // OUT_CH_PAR
        2  // W_PAR
    > StreamingConv_19;
    StreamingConv_19.step_init(9);
    StreamingAdd <
        std::array<ap_int<8>, 4>,  // TInputWordA
        ap_int<8>,  // TInputA
        std::array<ap_int<8>, 4>,  // TInputWordB
        ap_int<8>,  // TInputB
        std::array<ap_int<8>, 4>,  // TOutputWord
        ap_int<8>,  // TOutput
        ap_int<9>,  // TAcc
        DequantQuantEqual<ap_int<9>>,  // Activation
        DequantQuantPo2<1, ap_int<9>, ap_int<8>>,  // Quantizer
        DequantQuantEqual<ap_int<8>>,  // AlignA
        DequantQuantEqual<ap_int<8>>,  // AlignB
        14,  // IN_HEIGHT
        14,  // IN_WIDTH
        64,  // IN_CH
        2,  // W_PAR
        4  // CH_PAR
    > StreamingAdd_5;
    StreamingAdd_5.step_init(3);
    StreamingWindowSelector <
        std::array<ap_int<8>, 4>,  // TWord
        14,  // IN_HEIGHT
        14,  // IN_WIDTH
        64,  // IN_CH
        1,  // FH
        1,  // FW
        1,  // STRIDE_H
        1,  // STRIDE_W
        1,  // DILATION_H
        1,  // DILATION_W
        0,  // PAD_T
        0,  // PAD_L
        0,  // PAD_B
        0,  // PAD_R
        0,  // POS_H
        1,  // POS_W
        2,  // W_PAR
        4  // CH_PAR
    > StreamingLineBuffer_29_pixel_0;
    StreamingLineBuffer_29_pixel_0.step_init(1, 1);
    StreamingWindowSelector <
        std::array<ap_int<8>, 4>,  // TWord
        14,  // IN_HEIGHT
        14,  // IN_WIDTH
        64,  // IN_CH
        1,  // FH
        1,  // FW
        1,  // STRIDE_H
        1,  // STRIDE_W
        1,  // DILATION_H
        1,  // DILATION_W
        0,  // PAD_T
        0,  // PAD_L
        0,  // PAD_B
        0,  // PAD_R
        0,  // POS_H
        0,  // POS_W
        2,  // W_PAR
        4  // CH_PAR
    > StreamingLineBuffer_29_pixel_1;
    StreamingLineBuffer_29_pixel_1.step_init(1, 1);
    StreamingConv <
        std::array<ap_int<8>, 4>,  // TInputWord
        ap_int<8>,  // TInput
        std::array<ap_int<8>, 12>,  // TWeightWord
        ap_int<8>,  // TWeight
        std::array<ap_int<14>, 3>,  // TBiasWord
        ap_int<14>,  // TBias
        std::array<ap_uint<8>, 3>,  // TOutputWord
        ap_uint<8>,  // TOutput
        ap_int<24>,  // TSum
        ap_int<23>,  // TPartialSum
        ReLU<ap_int<24>>,  // Activation
        DequantQuantPo2<7, ap_int<24>, ap_uint<8>>,  // Quantizer
        384,  // OUT_CH
        64,  // IN_CH
        14,  // OUT_HEIGHT
        14,  // OUT_WIDTH
        1,  // GROUP
        1,  // FH
        1,  // FW
        1,  // STRIDE_H
        1,  // STRIDE_W
        4,  // IN_CH_PAR
        3,  // OUT_CH_PAR
        2  // W_PAR
    > StreamingConv_20;
    StreamingConv_20.step_init(9);
    BandwidthAdjustDecreaseChannels <
        std::array<ap_uint<8>, 3>,  // TInputStruct
        ap_uint<8>,  // TInput
        std::array<ap_uint<8>, 1>,  // TOutputStruct
        ap_uint<8>,  // TOutput
        DequantQuantEqual<ap_uint<8>>,  // Quantizer
        14,  // IN_HEIGHT
        14,  // IN_WIDTH
        384,  // IN_CH
        2,  // IN_W_PAR
        2,  // OUT_W_PAR
        3,  // IN_CH_PAR
        1  // OUT_CH_PAR
    > BandwidthAdjustDecreaseChannels_11;
    BandwidthAdjustDecreaseChannels_11.step_init(2);
    StreamingWindowSelector <
        std::array<ap_uint<8>, 1>,  // TWord
        14,  // IN_HEIGHT
        14,  // IN_WIDTH
        384,  // IN_CH
        3,  // FH
        3,  // FW
        1,  // STRIDE_H
        1,  // STRIDE_W
        1,  // DILATION_H
        1,  // DILATION_W
        1,  // PAD_T
        1,  // PAD_L
        1,  // PAD_B
        1,  // PAD_R
        2,  // POS_H
        3,  // POS_W
        2,  // W_PAR
        1  // CH_PAR
    > StreamingLineBuffer_30_pixel_0;
    StreamingLineBuffer_30_pixel_0.step_init(2, 1);
    StreamingWindowSelector <
        std::array<ap_uint<8>, 1>,  // TWord
        14,  // IN_HEIGHT
        14,  // IN_WIDTH
        384,  // IN_CH
        3,  // FH
        3,  // FW
        1,  // STRIDE_H
        1,  // STRIDE_W
        1,  // DILATION_H
        1,  // DILATION_W
        1,  // PAD_T
        1,  // PAD_L
        1,  // PAD_B
        1,  // PAD_R
        2,  // POS_H
        2,  // POS_W
        2,  // W_PAR
        1  // CH_PAR
    > StreamingLineBuffer_30_pixel_1;
    StreamingLineBuffer_30_pixel_1.step_init(2, 1);
    StreamingWindowSelector <
        std::array<ap_uint<8>, 1>,  // TWord
        14,  // IN_HEIGHT
        14,  // IN_WIDTH
        384,  // IN_CH
        3,  // FH
        3,  // FW
        1,  // STRIDE_H
        1,  // STRIDE_W
        1,  // DILATION_H
        1,  // DILATION_W
        1,  // PAD_T
        1,  // PAD_L
        1,  // PAD_B
        1,  // PAD_R
        2,  // POS_H
        1,  // POS_W
        2,  // W_PAR
        1  // CH_PAR
    > StreamingLineBuffer_30_pixel_2;
    StreamingLineBuffer_30_pixel_2.step_init(2, 385);
    StreamingWindowSelector <
        std::array<ap_uint<8>, 1>,  // TWord
        14,  // IN_HEIGHT
        14,  // IN_WIDTH
        384,  // IN_CH
        3,  // FH
        3,  // FW
        1,  // STRIDE_H
        1,  // STRIDE_W
        1,  // DILATION_H
        1,  // DILATION_W
        1,  // PAD_T
        1,  // PAD_L
        1,  // PAD_B
        1,  // PAD_R
        2,  // POS_H
        0,  // POS_W
        2,  // W_PAR
        1  // CH_PAR
    > StreamingLineBuffer_30_pixel_3;
    StreamingLineBuffer_30_pixel_3.step_init(2, 385);
    StreamingWindowSelector <
        std::array<ap_uint<8>, 1>,  // TWord
        14,  // IN_HEIGHT
        14,  // IN_WIDTH
        384,  // IN_CH
        3,  // FH
        3,  // FW
        1,  // STRIDE_H
        1,  // STRIDE_W
        1,  // DILATION_H
        1,  // DILATION_W
        1,  // PAD_T
        1,  // PAD_L
        1,  // PAD_B
        1,  // PAD_R
        1,  // POS_H
        3,  // POS_W
        2,  // W_PAR
        1  // CH_PAR
    > StreamingLineBuffer_30_pixel_4;
    StreamingLineBuffer_30_pixel_4.step_init(2, 2305);
    StreamingWindowSelector <
        std::array<ap_uint<8>, 1>,  // TWord
        14,  // IN_HEIGHT
        14,  // IN_WIDTH
        384,  // IN_CH
        3,  // FH
        3,  // FW
        1,  // STRIDE_H
        1,  // STRIDE_W
        1,  // DILATION_H
        1,  // DILATION_W
        1,  // PAD_T
        1,  // PAD_L
        1,  // PAD_B
        1,  // PAD_R
        1,  // POS_H
        2,  // POS_W
        2,  // W_PAR
        1  // CH_PAR
    > StreamingLineBuffer_30_pixel_5;
    StreamingLineBuffer_30_pixel_5.step_init(1, 2305);
    StreamingWindowSelector <
        std::array<ap_uint<8>, 1>,  // TWord
        14,  // IN_HEIGHT
        14,  // IN_WIDTH
        384,  // IN_CH
        3,  // FH
        3,  // FW
        1,  // STRIDE_H
        1,  // STRIDE_W
        1,  // DILATION_H
        1,  // DILATION_W
        1,  // PAD_T
        1,  // PAD_L
        1,  // PAD_B
        1,  // PAD_R
        1,  // POS_H
        1,  // POS_W
        2,  // W_PAR
        1  // CH_PAR
    > StreamingLineBuffer_30_pixel_6;
    StreamingLineBuffer_30_pixel_6.step_init(1, 385);
    StreamingWindowSelector <
        std::array<ap_uint<8>, 1>,  // TWord
        14,  // IN_HEIGHT
        14,  // IN_WIDTH
        384,  // IN_CH
        3,  // FH
        3,  // FW
        1,  // STRIDE_H
        1,  // STRIDE_W
        1,  // DILATION_H
        1,  // DILATION_W
        1,  // PAD_T
        1,  // PAD_L
        1,  // PAD_B
        1,  // PAD_R
        1,  // POS_H
        0,  // POS_W
        2,  // W_PAR
        1  // CH_PAR
    > StreamingLineBuffer_30_pixel_7;
    StreamingLineBuffer_30_pixel_7.step_init(2, 385);
    StreamingWindowSelector <
        std::array<ap_uint<8>, 1>,  // TWord
        14,  // IN_HEIGHT
        14,  // IN_WIDTH
        384,  // IN_CH
        3,  // FH
        3,  // FW
        1,  // STRIDE_H
        1,  // STRIDE_W
        1,  // DILATION_H
        1,  // DILATION_W
        1,  // PAD_T
        1,  // PAD_L
        1,  // PAD_B
        1,  // PAD_R
        0,  // POS_H
        3,  // POS_W
        2,  // W_PAR
        1  // CH_PAR
    > StreamingLineBuffer_30_pixel_8;
    StreamingLineBuffer_30_pixel_8.step_init(2, 2305);
    StreamingWindowSelector <
        std::array<ap_uint<8>, 1>,  // TWord
        14,  // IN_HEIGHT
        14,  // IN_WIDTH
        384,  // IN_CH
        3,  // FH
        3,  // FW
        1,  // STRIDE_H
        1,  // STRIDE_W
        1,  // DILATION_H
        1,  // DILATION_W
        1,  // PAD_T
        1,  // PAD_L
        1,  // PAD_B
        1,  // PAD_R
        0,  // POS_H
        2,  // POS_W
        2,  // W_PAR
        1  // CH_PAR
    > StreamingLineBuffer_30_pixel_9;
    StreamingLineBuffer_30_pixel_9.step_init(2, 2305);
    StreamingWindowSelector <
        std::array<ap_uint<8>, 1>,  // TWord
        14,  // IN_HEIGHT
        14,  // IN_WIDTH
        384,  // IN_CH
        3,  // FH
        3,  // FW
        1,  // STRIDE_H
        1,  // STRIDE_W
        1,  // DILATION_H
        1,  // DILATION_W
        1,  // PAD_T
        1,  // PAD_L
        1,  // PAD_B
        1,  // PAD_R
        0,  // POS_H
        1,  // POS_W
        2,  // W_PAR
        1  // CH_PAR
    > StreamingLineBuffer_30_pixel_10;
    StreamingLineBuffer_30_pixel_10.step_init(1, 385);
    StreamingWindowSelector <
        std::array<ap_uint<8>, 1>,  // TWord
        14,  // IN_HEIGHT
        14,  // IN_WIDTH
        384,  // IN_CH
        3,  // FH
        3,  // FW
        1,  // STRIDE_H
        1,  // STRIDE_W
        1,  // DILATION_H
        1,  // DILATION_W
        1,  // PAD_T
        1,  // PAD_L
        1,  // PAD_B
        1,  // PAD_R
        0,  // POS_H
        0,  // POS_W
        2,  // W_PAR
        1  // CH_PAR
    > StreamingLineBuffer_30_pixel_11;
    StreamingLineBuffer_30_pixel_11.step_init(1, 385);
    StreamingPad <
        std::array<ap_uint<8>, 1>,  // TWord
        ap_uint<8>,  // TData
        14,  // IN_HEIGHT
        14,  // IN_WIDTH
        384,  // IN_CH
        3,  // FH
        3,  // FW
        1,  // STRIDE_H
        1,  // STRIDE_W
        1,  // DILATION_H
        1,  // DILATION_W
        1,  // PAD_T
        1,  // PAD_L
        1,  // PAD_B
        1,  // PAD_R
        2,  // W_PAR
        1,  // CH_PAR
        0  // PAD_VALUE
    > StreamingLineBuffer_30_pad;
    StreamingLineBuffer_30_pad.step_init(3);
    StreamingDepthwiseConv <
        std::array<ap_uint<8>, 1>,  // TInputStruct
        ap_uint<8>,  // TInput
        std::array<ap_int<8>, 1>,  // TWeightStruct
        ap_int<8>,  // TWeight
        std::array<ap_int<15>, 1>,  // TBiasStruct
        ap_int<15>,  // TBias
        std::array<ap_uint<8>, 1>,  // TOutputStruct
        ap_uint<8>,  // TOutput
        ap_int<21>,  // TSum
        ap_int<20>,  // TPartialSum
        ReLU<ap_int<21>>,  // Activation
        DequantQuantPo2<6, ap_int<21>, ap_uint<8>>,  // Quantizer
        384,  // OUT_CH
        384,  // IN_CH
        14,  // IN_HEIGHT
        14,  // IN_WIDTH
        3,  // FH
        3,  // FW
        1,  // STRIDE_H
        1,  // STRIDE_W
        1,  // CH_PAR
        2  // W_PAR
    > StreamingDepthwiseConv_10;
    StreamingDepthwiseConv_10.step_init(8);
    BandwidthAdjustIncreaseChannels <
        std::array<ap_uint<8>, 1>,  // TInputStruct
        ap_uint<8>,  // TInput
        std::array<ap_uint<8>, 6>,  // TOutputStruct
        ap_uint<8>,  // TOutput
        DequantQuantEqual<ap_uint<8>>,  // Quantizer
        14,  // IN_HEIGHT
        14,  // IN_WIDTH
        384,  // IN_CH
        2,  // IN_W_PAR
        2,  // OUT_W_PAR
        1,  // IN_CH_PAR
        6  // OUT_CH_PAR
    > BandwidthAdjustIncreaseChannels_16;
    BandwidthAdjustIncreaseChannels_16.step_init(2);
    StreamingWindowSelector <
        std::array<ap_uint<8>, 6>,  // TWord
        14,  // IN_HEIGHT
        14,  // IN_WIDTH
        384,  // IN_CH
        1,  // FH
        1,  // FW
        1,  // STRIDE_H
        1,  // STRIDE_W
        1,  // DILATION_H
        1,  // DILATION_W
        0,  // PAD_T
        0,  // PAD_L
        0,  // PAD_B
        0,  // PAD_R
        0,  // POS_H
        1,  // POS_W
        2,  // W_PAR
        6  // CH_PAR
    > StreamingLineBuffer_31_pixel_0;
    StreamingLineBuffer_31_pixel_0.step_init(1, 1);
    StreamingWindowSelector <
        std::array<ap_uint<8>, 6>,  // TWord
        14,  // IN_HEIGHT
        14,  // IN_WIDTH
        384,  // IN_CH
        1,  // FH
        1,  // FW
        1,  // STRIDE_H
        1,  // STRIDE_W
        1,  // DILATION_H
        1,  // DILATION_W
        0,  // PAD_T
        0,  // PAD_L
        0,  // PAD_B
        0,  // PAD_R
        0,  // POS_H
        0,  // POS_W
        2,  // W_PAR
        6  // CH_PAR
    > StreamingLineBuffer_31_pixel_1;
    StreamingLineBuffer_31_pixel_1.step_init(1, 1);
    StreamingConv <
        std::array<ap_uint<8>, 6>,  // TInputWord
        ap_uint<8>,  // TInput
        std::array<ap_int<8>, 18>,  // TWeightWord
        ap_int<8>,  // TWeight
        std::array<ap_int<16>, 3>,  // TBiasWord
        ap_int<16>,  // TBias
        std::array<ap_int<8>, 3>,  // TOutputWord
        ap_int<8>,  // TOutput
        ap_int<27>,  // TSum
        ap_int<26>,  // TPartialSum
        DequantQuantEqual<ap_int<27>>,  // Activation
        DequantQuantPo2<10, ap_int<27>, ap_int<8>>,  // Quantizer
        96,  // OUT_CH
        384,  // IN_CH
        14,  // OUT_HEIGHT
        14,  // OUT_WIDTH
        1,  // GROUP
        1,  // FH
        1,  // FW
        1,  // STRIDE_H
        1,  // STRIDE_W
        6,  // IN_CH_PAR
        3,  // OUT_CH_PAR
        2  // W_PAR
    > StreamingConv_21;
    StreamingConv_21.step_init(8);
    TensorDuplicator <
        std::array<ap_int<8>, 3>,  // TWord
        14,  // IN_HEIGHT
        14,  // IN_WIDTH
        96,  // IN_CH
        3,  // CH_PAR
        2  // W_PAR
    > TensorDuplicator_6;
    TensorDuplicator_6.step_init(1);
    BandwidthAdjustDecreaseChannels <
        std::array<ap_int<8>, 3>,  // TInputStruct
        ap_int<8>,  // TInput
        std::array<ap_int<8>, 1>,  // TOutputStruct
        ap_int<8>,  // TOutput
        DequantQuantEqual<ap_int<8>>,  // Quantizer
        14,  // IN_HEIGHT
        14,  // IN_WIDTH
        96,  // IN_CH
        2,  // IN_W_PAR
        2,  // OUT_W_PAR
        3,  // IN_CH_PAR
        1  // OUT_CH_PAR
    > BandwidthAdjustDecreaseChannels_12;
    BandwidthAdjustDecreaseChannels_12.step_init(2);
    BandwidthAdjustIncreaseChannels <
        std::array<ap_int<8>, 1>,  // TInputStruct
        ap_int<8>,  // TInput
        std::array<ap_int<8>, 32>,  // TOutputStruct
        ap_int<8>,  // TOutput
        DequantQuantEqual<ap_int<8>>,  // Quantizer
        14,  // IN_HEIGHT
        14,  // IN_WIDTH
        96,  // IN_CH
        2,  // IN_W_PAR
        2,  // OUT_W_PAR
        1,  // IN_CH_PAR
        32  // OUT_CH_PAR
    > BandwidthAdjustIncreaseChannels_17;
    BandwidthAdjustIncreaseChannels_17.step_init(2);
    BandwidthAdjustDecreaseStreams <
        std::array<ap_int<8>, 32>,  // TInputStruct
        ap_int<8>,  // TInput
        std::array<ap_int<8>, 32>,  // TOutputStruct
        ap_int<8>,  // TOutput
        DequantQuantEqual<ap_int<8>>,  // Quantizer
        14,  // IN_HEIGHT
        14,  // IN_WIDTH
        96,  // IN_CH
        2,  // IN_W_PAR
        1,  // OUT_W_PAR
        32,  // IN_CH_PAR
        32  // OUT_CH_PAR
    > BandwidthAdjustDecreaseStreams_6;
    BandwidthAdjustDecreaseStreams_6.step_init(2);
    StreamingConv <
        std::array<ap_int<8>, 32>,  // TInputWord
        ap_int<8>,  // TInput
        std::array<ap_int<8>, 64>,  // TWeightWord
        ap_int<8>,  // TWeight
        std::array<ap_int<14>, 2>,  // TBiasWord
        ap_int<14>,  // TBias
        std::array<ap_uint<8>, 2>,  // TOutputWord
        ap_uint<8>,  // TOutput
        ap_int<24>,  // TSum
        ap_int<23>,  // TPartialSum
        ReLU<ap_int<24>>,  // Activation
        DequantQuantPo2<6, ap_int<24>, ap_uint<8>>,  // Quantizer
        576,  // OUT_CH
        96,  // IN_CH
        14,  // OUT_HEIGHT
        14,  // OUT_WIDTH
        1,  // GROUP
        1,  // FH
        1,  // FW
        1,  // STRIDE_H
        1,  // STRIDE_W
        32,  // IN_CH_PAR
        2,  // OUT_CH_PAR
        1  // W_PAR
    > StreamingConv_22;
    StreamingConv_22.step_init(12);
    BandwidthAdjustDecreaseChannels <
        std::array<ap_uint<8>, 2>,  // TInputStruct
        ap_uint<8>,  // TInput
        std::array<ap_uint<8>, 1>,  // TOutputStruct
        ap_uint<8>,  // TOutput
        DequantQuantEqual<ap_uint<8>>,  // Quantizer
        14,  // IN_HEIGHT
        14,  // IN_WIDTH
        576,  // IN_CH
        1,  // IN_W_PAR
        1,  // OUT_W_PAR
        2,  // IN_CH_PAR
        1  // OUT_CH_PAR
    > BandwidthAdjustDecreaseChannels_13;
    BandwidthAdjustDecreaseChannels_13.step_init(2);
    StreamingWindowSelector <
        std::array<ap_uint<8>, 1>,  // TWord
        14,  // IN_HEIGHT
        14,  // IN_WIDTH
        576,  // IN_CH
        3,  // FH
        3,  // FW
        1,  // STRIDE_H
        1,  // STRIDE_W
        1,  // DILATION_H
        1,  // DILATION_W
        1,  // PAD_T
        1,  // PAD_L
        1,  // PAD_B
        1,  // PAD_R
        2,  // POS_H
        2,  // POS_W
        1,  // W_PAR
        1  // CH_PAR
    > StreamingLineBuffer_32_pixel_0;
    StreamingLineBuffer_32_pixel_0.step_init(2, 1);
    StreamingWindowSelector <
        std::array<ap_uint<8>, 1>,  // TWord
        14,  // IN_HEIGHT
        14,  // IN_WIDTH
        576,  // IN_CH
        3,  // FH
        3,  // FW
        1,  // STRIDE_H
        1,  // STRIDE_W
        1,  // DILATION_H
        1,  // DILATION_W
        1,  // PAD_T
        1,  // PAD_L
        1,  // PAD_B
        1,  // PAD_R
        2,  // POS_H
        1,  // POS_W
        1,  // W_PAR
        1  // CH_PAR
    > StreamingLineBuffer_32_pixel_1;
    StreamingLineBuffer_32_pixel_1.step_init(2, 577);
    StreamingWindowSelector <
        std::array<ap_uint<8>, 1>,  // TWord
        14,  // IN_HEIGHT
        14,  // IN_WIDTH
        576,  // IN_CH
        3,  // FH
        3,  // FW
        1,  // STRIDE_H
        1,  // STRIDE_W
        1,  // DILATION_H
        1,  // DILATION_W
        1,  // PAD_T
        1,  // PAD_L
        1,  // PAD_B
        1,  // PAD_R
        2,  // POS_H
        0,  // POS_W
        1,  // W_PAR
        1  // CH_PAR
    > StreamingLineBuffer_32_pixel_2;
    StreamingLineBuffer_32_pixel_2.step_init(2, 577);
    StreamingWindowSelector <
        std::array<ap_uint<8>, 1>,  // TWord
        14,  // IN_HEIGHT
        14,  // IN_WIDTH
        576,  // IN_CH
        3,  // FH
        3,  // FW
        1,  // STRIDE_H
        1,  // STRIDE_W
        1,  // DILATION_H
        1,  // DILATION_W
        1,  // PAD_T
        1,  // PAD_L
        1,  // PAD_B
        1,  // PAD_R
        1,  // POS_H
        2,  // POS_W
        1,  // W_PAR
        1  // CH_PAR
    > StreamingLineBuffer_32_pixel_3;
    StreamingLineBuffer_32_pixel_3.step_init(2, 6913);
    StreamingWindowSelector <
        std::array<ap_uint<8>, 1>,  // TWord
        14,  // IN_HEIGHT
        14,  // IN_WIDTH
        576,  // IN_CH
        3,  // FH
        3,  // FW
        1,  // STRIDE_H
        1,  // STRIDE_W
        1,  // DILATION_H
        1,  // DILATION_W
        1,  // PAD_T
        1,  // PAD_L
        1,  // PAD_B
        1,  // PAD_R
        1,  // POS_H
        1,  // POS_W
        1,  // W_PAR
        1  // CH_PAR
    > StreamingLineBuffer_32_pixel_4;
    StreamingLineBuffer_32_pixel_4.step_init(1, 577);
    StreamingWindowSelector <
        std::array<ap_uint<8>, 1>,  // TWord
        14,  // IN_HEIGHT
        14,  // IN_WIDTH
        576,  // IN_CH
        3,  // FH
        3,  // FW
        1,  // STRIDE_H
        1,  // STRIDE_W
        1,  // DILATION_H
        1,  // DILATION_W
        1,  // PAD_T
        1,  // PAD_L
        1,  // PAD_B
        1,  // PAD_R
        1,  // POS_H
        0,  // POS_W
        1,  // W_PAR
        1  // CH_PAR
    > StreamingLineBuffer_32_pixel_5;
    StreamingLineBuffer_32_pixel_5.step_init(2, 577);
    StreamingWindowSelector <
        std::array<ap_uint<8>, 1>,  // TWord
        14,  // IN_HEIGHT
        14,  // IN_WIDTH
        576,  // IN_CH
        3,  // FH
        3,  // FW
        1,  // STRIDE_H
        1,  // STRIDE_W
        1,  // DILATION_H
        1,  // DILATION_W
        1,  // PAD_T
        1,  // PAD_L
        1,  // PAD_B
        1,  // PAD_R
        0,  // POS_H
        2,  // POS_W
        1,  // W_PAR
        1  // CH_PAR
    > StreamingLineBuffer_32_pixel_6;
    StreamingLineBuffer_32_pixel_6.step_init(2, 6913);
    StreamingWindowSelector <
        std::array<ap_uint<8>, 1>,  // TWord
        14,  // IN_HEIGHT
        14,  // IN_WIDTH
        576,  // IN_CH
        3,  // FH
        3,  // FW
        1,  // STRIDE_H
        1,  // STRIDE_W
        1,  // DILATION_H
        1,  // DILATION_W
        1,  // PAD_T
        1,  // PAD_L
        1,  // PAD_B
        1,  // PAD_R
        0,  // POS_H
        1,  // POS_W
        1,  // W_PAR
        1  // CH_PAR
    > StreamingLineBuffer_32_pixel_7;
    StreamingLineBuffer_32_pixel_7.step_init(2, 577);
    StreamingWindowSelector <
        std::array<ap_uint<8>, 1>,  // TWord
        14,  // IN_HEIGHT
        14,  // IN_WIDTH
        576,  // IN_CH
        3,  // FH
        3,  // FW
        1,  // STRIDE_H
        1,  // STRIDE_W
        1,  // DILATION_H
        1,  // DILATION_W
        1,  // PAD_T
        1,  // PAD_L
        1,  // PAD_B
        1,  // PAD_R
        0,  // POS_H
        0,  // POS_W
        1,  // W_PAR
        1  // CH_PAR
    > StreamingLineBuffer_32_pixel_8;
    StreamingLineBuffer_32_pixel_8.step_init(1, 577);
    StreamingPad <
        std::array<ap_uint<8>, 1>,  // TWord
        ap_uint<8>,  // TData
        14,  // IN_HEIGHT
        14,  // IN_WIDTH
        576,  // IN_CH
        3,  // FH
        3,  // FW
        1,  // STRIDE_H
        1,  // STRIDE_W
        1,  // DILATION_H
        1,  // DILATION_W
        1,  // PAD_T
        1,  // PAD_L
        1,  // PAD_B
        1,  // PAD_R
        1,  // W_PAR
        1,  // CH_PAR
        0  // PAD_VALUE
    > StreamingLineBuffer_32_pad;
    StreamingLineBuffer_32_pad.step_init(3);
    StreamingDepthwiseConv <
        std::array<ap_uint<8>, 1>,  // TInputStruct
        ap_uint<8>,  // TInput
        std::array<ap_int<8>, 1>,  // TWeightStruct
        ap_int<8>,  // TWeight
        std::array<ap_int<15>, 1>,  // TBiasStruct
        ap_int<15>,  // TBias
        std::array<ap_uint<8>, 1>,  // TOutputStruct
        ap_uint<8>,  // TOutput
        ap_int<21>,  // TSum
        ap_int<20>,  // TPartialSum
        ReLU<ap_int<21>>,  // Activation
        DequantQuantPo2<6, ap_int<21>, ap_uint<8>>,  // Quantizer
        576,  // OUT_CH
        576,  // IN_CH
        14,  // IN_HEIGHT
        14,  // IN_WIDTH
        3,  // FH
        3,  // FW
        1,  // STRIDE_H
        1,  // STRIDE_W
        1,  // CH_PAR
        1  // W_PAR
    > StreamingDepthwiseConv_11;
    StreamingDepthwiseConv_11.step_init(8);
    BandwidthAdjustIncreaseChannels <
        std::array<ap_uint<8>, 1>,  // TInputStruct
        ap_uint<8>,  // TInput
        std::array<ap_uint<8>, 9>,  // TOutputStruct
        ap_uint<8>,  // TOutput
        DequantQuantEqual<ap_uint<8>>,  // Quantizer
        14,  // IN_HEIGHT
        14,  // IN_WIDTH
        576,  // IN_CH
        1,  // IN_W_PAR
        1,  // OUT_W_PAR
        1,  // IN_CH_PAR
        9  // OUT_CH_PAR
    > BandwidthAdjustIncreaseChannels_18;
    BandwidthAdjustIncreaseChannels_18.step_init(2);
    BandwidthAdjustIncreaseStreams <
        std::array<ap_uint<8>, 9>,  // TInputStruct
        ap_uint<8>,  // TInput
        std::array<ap_uint<8>, 9>,  // TOutputStruct
        ap_uint<8>,  // TOutput
        DequantQuantEqual<ap_uint<8>>,  // Quantizer
        14,  // IN_HEIGHT
        14,  // IN_WIDTH
        576,  // IN_CH
        1,  // IN_W_PAR
        2,  // OUT_W_PAR
        9,  // IN_CH_PAR
        9  // OUT_CH_PAR
    > BandwidthAdjustIncreaseStreams_8;
    BandwidthAdjustIncreaseStreams_8.step_init(1);
    StreamingWindowSelector <
        std::array<ap_uint<8>, 9>,  // TWord
        14,  // IN_HEIGHT
        14,  // IN_WIDTH
        576,  // IN_CH
        1,  // FH
        1,  // FW
        1,  // STRIDE_H
        1,  // STRIDE_W
        1,  // DILATION_H
        1,  // DILATION_W
        0,  // PAD_T
        0,  // PAD_L
        0,  // PAD_B
        0,  // PAD_R
        0,  // POS_H
        1,  // POS_W
        2,  // W_PAR
        9  // CH_PAR
    > StreamingLineBuffer_33_pixel_0;
    StreamingLineBuffer_33_pixel_0.step_init(1, 1);
    StreamingWindowSelector <
        std::array<ap_uint<8>, 9>,  // TWord
        14,  // IN_HEIGHT
        14,  // IN_WIDTH
        576,  // IN_CH
        1,  // FH
        1,  // FW
        1,  // STRIDE_H
        1,  // STRIDE_W
        1,  // DILATION_H
        1,  // DILATION_W
        0,  // PAD_T
        0,  // PAD_L
        0,  // PAD_B
        0,  // PAD_R
        0,  // POS_H
        0,  // POS_W
        2,  // W_PAR
        9  // CH_PAR
    > StreamingLineBuffer_33_pixel_1;
    StreamingLineBuffer_33_pixel_1.step_init(1, 1);
    StreamingConv <
        std::array<ap_uint<8>, 9>,  // TInputWord
        ap_uint<8>,  // TInput
        std::array<ap_int<8>, 27>,  // TWeightWord
        ap_int<8>,  // TWeight
        std::array<ap_int<15>, 3>,  // TBiasWord
        ap_int<15>,  // TBias
        std::array<ap_int<8>, 3>,  // TOutputWord
        ap_int<8>,  // TOutput
        ap_int<28>,  // TSum
        ap_int<27>,  // TPartialSum
        DequantQuantEqual<ap_int<28>>,  // Activation
        DequantQuantPo2<9, ap_int<28>, ap_int<8>>,  // Quantizer
        96,  // OUT_CH
        576,  // IN_CH
        14,  // OUT_HEIGHT
        14,  // OUT_WIDTH
        1,  // GROUP
        1,  // FH
        1,  // FW
        1,  // STRIDE_H
        1,  // STRIDE_W
        9,  // IN_CH_PAR
        3,  // OUT_CH_PAR
        2  // W_PAR
    > StreamingConv_23;
    StreamingConv_23.step_init(10);
    StreamingAdd <
        std::array<ap_int<8>, 3>,  // TInputWordA
        ap_int<8>,  // TInputA
        std::array<ap_int<8>, 3>,  // TInputWordB
        ap_int<8>,  // TInputB
        std::array<ap_int<8>, 3>,  // TOutputWord
        ap_int<8>,  // TOutput
        ap_int<9>,  // TAcc
        DequantQuantEqual<ap_int<9>>,  // Activation
        DequantQuantPo2<0, ap_int<9>, ap_int<8>>,  // Quantizer
        DequantQuantEqual<ap_int<8>>,  // AlignA
        DequantQuantEqual<ap_int<8>>,  // AlignB
        14,  // IN_HEIGHT
        14,  // IN_WIDTH
        96,  // IN_CH
        2,  // W_PAR
        3  // CH_PAR
    > StreamingAdd_6;
    StreamingAdd_6.step_init(2);
    TensorDuplicator <
        std::array<ap_int<8>, 3>,  // TWord
        14,  // IN_HEIGHT
        14,  // IN_WIDTH
        96,  // IN_CH
        3,  // CH_PAR
        2  // W_PAR
    > TensorDuplicator_7;
    TensorDuplicator_7.step_init(1);
    BandwidthAdjustDecreaseChannels <
        std::array<ap_int<8>, 3>,  // TInputStruct
        ap_int<8>,  // TInput
        std::array<ap_int<8>, 1>,  // TOutputStruct
        ap_int<8>,  // TOutput
        DequantQuantEqual<ap_int<8>>,  // Quantizer
        14,  // IN_HEIGHT
        14,  // IN_WIDTH
        96,  // IN_CH
        2,  // IN_W_PAR
        2,  // OUT_W_PAR
        3,  // IN_CH_PAR
        1  // OUT_CH_PAR
    > BandwidthAdjustDecreaseChannels_14;
    BandwidthAdjustDecreaseChannels_14.step_init(2);
    BandwidthAdjustIncreaseChannels <
        std::array<ap_int<8>, 1>,  // TInputStruct
        ap_int<8>,  // TInput
        std::array<ap_int<8>, 16>,  // TOutputStruct
        ap_int<8>,  // TOutput
        DequantQuantEqual<ap_int<8>>,  // Quantizer
        14,  // IN_HEIGHT
        14,  // IN_WIDTH
        96,  // IN_CH
        2,  // IN_W_PAR
        2,  // OUT_W_PAR
        1,  // IN_CH_PAR
        16  // OUT_CH_PAR
    > BandwidthAdjustIncreaseChannels_19;
    BandwidthAdjustIncreaseChannels_19.step_init(2);
    BandwidthAdjustDecreaseStreams <
        std::array<ap_int<8>, 16>,  // TInputStruct
        ap_int<8>,  // TInput
        std::array<ap_int<8>, 16>,  // TOutputStruct
        ap_int<8>,  // TOutput
        DequantQuantEqual<ap_int<8>>,  // Quantizer
        14,  // IN_HEIGHT
        14,  // IN_WIDTH
        96,  // IN_CH
        2,  // IN_W_PAR
        1,  // OUT_W_PAR
        16,  // IN_CH_PAR
        16  // OUT_CH_PAR
    > BandwidthAdjustDecreaseStreams_7;
    BandwidthAdjustDecreaseStreams_7.step_init(2);
    StreamingConv <
        std::array<ap_int<8>, 16>,  // TInputWord
        ap_int<8>,  // TInput
        std::array<ap_int<8>, 64>,  // TWeightWord
        ap_int<8>,  // TWeight
        std::array<ap_int<15>, 4>,  // TBiasWord
        ap_int<15>,  // TBias
        std::array<ap_uint<8>, 4>,  // TOutputWord
        ap_uint<8>,  // TOutput
        ap_int<24>,  // TSum
        ap_int<23>,  // TPartialSum
        ReLU<ap_int<24>>,  // Activation
        DequantQuantPo2<6, ap_int<24>, ap_uint<8>>,  // Quantizer
        576,  // OUT_CH
        96,  // IN_CH
        14,  // OUT_HEIGHT
        14,  // OUT_WIDTH
        1,  // GROUP
        1,  // FH
        1,  // FW
        1,  // STRIDE_H
        1,  // STRIDE_W
        16,  // IN_CH_PAR
        4,  // OUT_CH_PAR
        1  // W_PAR
    > StreamingConv_24;
    StreamingConv_24.step_init(11);
    BandwidthAdjustDecreaseChannels <
        std::array<ap_uint<8>, 4>,  // TInputStruct
        ap_uint<8>,  // TInput
        std::array<ap_uint<8>, 1>,  // TOutputStruct
        ap_uint<8>,  // TOutput
        DequantQuantEqual<ap_uint<8>>,  // Quantizer
        14,  // IN_HEIGHT
        14,  // IN_WIDTH
        576,  // IN_CH
        1,  // IN_W_PAR
        1,  // OUT_W_PAR
        4,  // IN_CH_PAR
        1  // OUT_CH_PAR
    > BandwidthAdjustDecreaseChannels_15;
    BandwidthAdjustDecreaseChannels_15.step_init(2);
    StreamingWindowSelector <
        std::array<ap_uint<8>, 1>,  // TWord
        14,  // IN_HEIGHT
        14,  // IN_WIDTH
        576,  // IN_CH
        3,  // FH
        3,  // FW
        1,  // STRIDE_H
        1,  // STRIDE_W
        1,  // DILATION_H
        1,  // DILATION_W
        1,  // PAD_T
        1,  // PAD_L
        1,  // PAD_B
        1,  // PAD_R
        2,  // POS_H
        2,  // POS_W
        1,  // W_PAR
        1  // CH_PAR
    > StreamingLineBuffer_34_pixel_0;
    StreamingLineBuffer_34_pixel_0.step_init(2, 1);
    StreamingWindowSelector <
        std::array<ap_uint<8>, 1>,  // TWord
        14,  // IN_HEIGHT
        14,  // IN_WIDTH
        576,  // IN_CH
        3,  // FH
        3,  // FW
        1,  // STRIDE_H
        1,  // STRIDE_W
        1,  // DILATION_H
        1,  // DILATION_W
        1,  // PAD_T
        1,  // PAD_L
        1,  // PAD_B
        1,  // PAD_R
        2,  // POS_H
        1,  // POS_W
        1,  // W_PAR
        1  // CH_PAR
    > StreamingLineBuffer_34_pixel_1;
    StreamingLineBuffer_34_pixel_1.step_init(2, 577);
    StreamingWindowSelector <
        std::array<ap_uint<8>, 1>,  // TWord
        14,  // IN_HEIGHT
        14,  // IN_WIDTH
        576,  // IN_CH
        3,  // FH
        3,  // FW
        1,  // STRIDE_H
        1,  // STRIDE_W
        1,  // DILATION_H
        1,  // DILATION_W
        1,  // PAD_T
        1,  // PAD_L
        1,  // PAD_B
        1,  // PAD_R
        2,  // POS_H
        0,  // POS_W
        1,  // W_PAR
        1  // CH_PAR
    > StreamingLineBuffer_34_pixel_2;
    StreamingLineBuffer_34_pixel_2.step_init(2, 577);
    StreamingWindowSelector <
        std::array<ap_uint<8>, 1>,  // TWord
        14,  // IN_HEIGHT
        14,  // IN_WIDTH
        576,  // IN_CH
        3,  // FH
        3,  // FW
        1,  // STRIDE_H
        1,  // STRIDE_W
        1,  // DILATION_H
        1,  // DILATION_W
        1,  // PAD_T
        1,  // PAD_L
        1,  // PAD_B
        1,  // PAD_R
        1,  // POS_H
        2,  // POS_W
        1,  // W_PAR
        1  // CH_PAR
    > StreamingLineBuffer_34_pixel_3;
    StreamingLineBuffer_34_pixel_3.step_init(2, 6913);
    StreamingWindowSelector <
        std::array<ap_uint<8>, 1>,  // TWord
        14,  // IN_HEIGHT
        14,  // IN_WIDTH
        576,  // IN_CH
        3,  // FH
        3,  // FW
        1,  // STRIDE_H
        1,  // STRIDE_W
        1,  // DILATION_H
        1,  // DILATION_W
        1,  // PAD_T
        1,  // PAD_L
        1,  // PAD_B
        1,  // PAD_R
        1,  // POS_H
        1,  // POS_W
        1,  // W_PAR
        1  // CH_PAR
    > StreamingLineBuffer_34_pixel_4;
    StreamingLineBuffer_34_pixel_4.step_init(1, 577);
    StreamingWindowSelector <
        std::array<ap_uint<8>, 1>,  // TWord
        14,  // IN_HEIGHT
        14,  // IN_WIDTH
        576,  // IN_CH
        3,  // FH
        3,  // FW
        1,  // STRIDE_H
        1,  // STRIDE_W
        1,  // DILATION_H
        1,  // DILATION_W
        1,  // PAD_T
        1,  // PAD_L
        1,  // PAD_B
        1,  // PAD_R
        1,  // POS_H
        0,  // POS_W
        1,  // W_PAR
        1  // CH_PAR
    > StreamingLineBuffer_34_pixel_5;
    StreamingLineBuffer_34_pixel_5.step_init(2, 577);
    StreamingWindowSelector <
        std::array<ap_uint<8>, 1>,  // TWord
        14,  // IN_HEIGHT
        14,  // IN_WIDTH
        576,  // IN_CH
        3,  // FH
        3,  // FW
        1,  // STRIDE_H
        1,  // STRIDE_W
        1,  // DILATION_H
        1,  // DILATION_W
        1,  // PAD_T
        1,  // PAD_L
        1,  // PAD_B
        1,  // PAD_R
        0,  // POS_H
        2,  // POS_W
        1,  // W_PAR
        1  // CH_PAR
    > StreamingLineBuffer_34_pixel_6;
    StreamingLineBuffer_34_pixel_6.step_init(2, 6913);
    StreamingWindowSelector <
        std::array<ap_uint<8>, 1>,  // TWord
        14,  // IN_HEIGHT
        14,  // IN_WIDTH
        576,  // IN_CH
        3,  // FH
        3,  // FW
        1,  // STRIDE_H
        1,  // STRIDE_W
        1,  // DILATION_H
        1,  // DILATION_W
        1,  // PAD_T
        1,  // PAD_L
        1,  // PAD_B
        1,  // PAD_R
        0,  // POS_H
        1,  // POS_W
        1,  // W_PAR
        1  // CH_PAR
    > StreamingLineBuffer_34_pixel_7;
    StreamingLineBuffer_34_pixel_7.step_init(2, 577);
    StreamingWindowSelector <
        std::array<ap_uint<8>, 1>,  // TWord
        14,  // IN_HEIGHT
        14,  // IN_WIDTH
        576,  // IN_CH
        3,  // FH
        3,  // FW
        1,  // STRIDE_H
        1,  // STRIDE_W
        1,  // DILATION_H
        1,  // DILATION_W
        1,  // PAD_T
        1,  // PAD_L
        1,  // PAD_B
        1,  // PAD_R
        0,  // POS_H
        0,  // POS_W
        1,  // W_PAR
        1  // CH_PAR
    > StreamingLineBuffer_34_pixel_8;
    StreamingLineBuffer_34_pixel_8.step_init(1, 577);
    StreamingPad <
        std::array<ap_uint<8>, 1>,  // TWord
        ap_uint<8>,  // TData
        14,  // IN_HEIGHT
        14,  // IN_WIDTH
        576,  // IN_CH
        3,  // FH
        3,  // FW
        1,  // STRIDE_H
        1,  // STRIDE_W
        1,  // DILATION_H
        1,  // DILATION_W
        1,  // PAD_T
        1,  // PAD_L
        1,  // PAD_B
        1,  // PAD_R
        1,  // W_PAR
        1,  // CH_PAR
        0  // PAD_VALUE
    > StreamingLineBuffer_34_pad;
    StreamingLineBuffer_34_pad.step_init(3);
    StreamingDepthwiseConv <
        std::array<ap_uint<8>, 1>,  // TInputStruct
        ap_uint<8>,  // TInput
        std::array<ap_int<8>, 1>,  // TWeightStruct
        ap_int<8>,  // TWeight
        std::array<ap_int<15>, 1>,  // TBiasStruct
        ap_int<15>,  // TBias
        std::array<ap_uint<8>, 1>,  // TOutputStruct
        ap_uint<8>,  // TOutput
        ap_int<21>,  // TSum
        ap_int<20>,  // TPartialSum
        ReLU<ap_int<21>>,  // Activation
        DequantQuantPo2<6, ap_int<21>, ap_uint<8>>,  // Quantizer
        576,  // OUT_CH
        576,  // IN_CH
        14,  // IN_HEIGHT
        14,  // IN_WIDTH
        3,  // FH
        3,  // FW
        1,  // STRIDE_H
        1,  // STRIDE_W
        1,  // CH_PAR
        1  // W_PAR
    > StreamingDepthwiseConv_12;
    StreamingDepthwiseConv_12.step_init(8);
    BandwidthAdjustIncreaseChannels <
        std::array<ap_uint<8>, 1>,  // TInputStruct
        ap_uint<8>,  // TInput
        std::array<ap_uint<8>, 9>,  // TOutputStruct
        ap_uint<8>,  // TOutput
        DequantQuantEqual<ap_uint<8>>,  // Quantizer
        14,  // IN_HEIGHT
        14,  // IN_WIDTH
        576,  // IN_CH
        1,  // IN_W_PAR
        1,  // OUT_W_PAR
        1,  // IN_CH_PAR
        9  // OUT_CH_PAR
    > BandwidthAdjustIncreaseChannels_20;
    BandwidthAdjustIncreaseChannels_20.step_init(2);
    BandwidthAdjustIncreaseStreams <
        std::array<ap_uint<8>, 9>,  // TInputStruct
        ap_uint<8>,  // TInput
        std::array<ap_uint<8>, 9>,  // TOutputStruct
        ap_uint<8>,  // TOutput
        DequantQuantEqual<ap_uint<8>>,  // Quantizer
        14,  // IN_HEIGHT
        14,  // IN_WIDTH
        576,  // IN_CH
        1,  // IN_W_PAR
        2,  // OUT_W_PAR
        9,  // IN_CH_PAR
        9  // OUT_CH_PAR
    > BandwidthAdjustIncreaseStreams_9;
    BandwidthAdjustIncreaseStreams_9.step_init(1);
    StreamingWindowSelector <
        std::array<ap_uint<8>, 9>,  // TWord
        14,  // IN_HEIGHT
        14,  // IN_WIDTH
        576,  // IN_CH
        1,  // FH
        1,  // FW
        1,  // STRIDE_H
        1,  // STRIDE_W
        1,  // DILATION_H
        1,  // DILATION_W
        0,  // PAD_T
        0,  // PAD_L
        0,  // PAD_B
        0,  // PAD_R
        0,  // POS_H
        1,  // POS_W
        2,  // W_PAR
        9  // CH_PAR
    > StreamingLineBuffer_35_pixel_0;
    StreamingLineBuffer_35_pixel_0.step_init(1, 1);
    StreamingWindowSelector <
        std::array<ap_uint<8>, 9>,  // TWord
        14,  // IN_HEIGHT
        14,  // IN_WIDTH
        576,  // IN_CH
        1,  // FH
        1,  // FW
        1,  // STRIDE_H
        1,  // STRIDE_W
        1,  // DILATION_H
        1,  // DILATION_W
        0,  // PAD_T
        0,  // PAD_L
        0,  // PAD_B
        0,  // PAD_R
        0,  // POS_H
        0,  // POS_W
        2,  // W_PAR
        9  // CH_PAR
    > StreamingLineBuffer_35_pixel_1;
    StreamingLineBuffer_35_pixel_1.step_init(1, 1);
    StreamingConv <
        std::array<ap_uint<8>, 9>,  // TInputWord
        ap_uint<8>,  // TInput
        std::array<ap_int<8>, 27>,  // TWeightWord
        ap_int<8>,  // TWeight
        std::array<ap_int<15>, 3>,  // TBiasWord
        ap_int<15>,  // TBias
        std::array<ap_int<8>, 3>,  // TOutputWord
        ap_int<8>,  // TOutput
        ap_int<28>,  // TSum
        ap_int<27>,  // TPartialSum
        DequantQuantEqual<ap_int<28>>,  // Activation
        DequantQuantPo2<9, ap_int<28>, ap_int<8>>,  // Quantizer
        96,  // OUT_CH
        576,  // IN_CH
        14,  // OUT_HEIGHT
        14,  // OUT_WIDTH
        1,  // GROUP
        1,  // FH
        1,  // FW
        1,  // STRIDE_H
        1,  // STRIDE_W
        9,  // IN_CH_PAR
        3,  // OUT_CH_PAR
        2  // W_PAR
    > StreamingConv_25;
    StreamingConv_25.step_init(10);
    StreamingAdd <
        std::array<ap_int<8>, 3>,  // TInputWordA
        ap_int<8>,  // TInputA
        std::array<ap_int<8>, 3>,  // TInputWordB
        ap_int<8>,  // TInputB
        std::array<ap_int<8>, 3>,  // TOutputWord
        ap_int<8>,  // TOutput
        ap_int<9>,  // TAcc
        DequantQuantEqual<ap_int<9>>,  // Activation
        DequantQuantPo2<0, ap_int<9>, ap_int<8>>,  // Quantizer
        DequantQuantEqual<ap_int<8>>,  // AlignA
        DequantQuantEqual<ap_int<8>>,  // AlignB
        14,  // IN_HEIGHT
        14,  // IN_WIDTH
        96,  // IN_CH
        2,  // W_PAR
        3  // CH_PAR
    > StreamingAdd_7;
    StreamingAdd_7.step_init(2);
    BandwidthAdjustDecreaseChannels <
        std::array<ap_int<8>, 3>,  // TInputStruct
        ap_int<8>,  // TInput
        std::array<ap_int<8>, 1>,  // TOutputStruct
        ap_int<8>,  // TOutput
        DequantQuantEqual<ap_int<8>>,  // Quantizer
        14,  // IN_HEIGHT
        14,  // IN_WIDTH
        96,  // IN_CH
        2,  // IN_W_PAR
        2,  // OUT_W_PAR
        3,  // IN_CH_PAR
        1  // OUT_CH_PAR
    > BandwidthAdjustDecreaseChannels_16;
    BandwidthAdjustDecreaseChannels_16.step_init(2);
    BandwidthAdjustIncreaseChannels <
        std::array<ap_int<8>, 1>,  // TInputStruct
        ap_int<8>,  // TInput
        std::array<ap_int<8>, 16>,  // TOutputStruct
        ap_int<8>,  // TOutput
        DequantQuantEqual<ap_int<8>>,  // Quantizer
        14,  // IN_HEIGHT
        14,  // IN_WIDTH
        96,  // IN_CH
        2,  // IN_W_PAR
        2,  // OUT_W_PAR
        1,  // IN_CH_PAR
        16  // OUT_CH_PAR
    > BandwidthAdjustIncreaseChannels_21;
    BandwidthAdjustIncreaseChannels_21.step_init(2);
    BandwidthAdjustDecreaseStreams <
        std::array<ap_int<8>, 16>,  // TInputStruct
        ap_int<8>,  // TInput
        std::array<ap_int<8>, 16>,  // TOutputStruct
        ap_int<8>,  // TOutput
        DequantQuantEqual<ap_int<8>>,  // Quantizer
        14,  // IN_HEIGHT
        14,  // IN_WIDTH
        96,  // IN_CH
        2,  // IN_W_PAR
        1,  // OUT_W_PAR
        16,  // IN_CH_PAR
        16  // OUT_CH_PAR
    > BandwidthAdjustDecreaseStreams_8;
    BandwidthAdjustDecreaseStreams_8.step_init(2);
    StreamingConv <
        std::array<ap_int<8>, 16>,  // TInputWord
        ap_int<8>,  // TInput
        std::array<ap_int<8>, 64>,  // TWeightWord
        ap_int<8>,  // TWeight
        std::array<ap_int<14>, 4>,  // TBiasWord
        ap_int<14>,  // TBias
        std::array<ap_uint<8>, 4>,  // TOutputWord
        ap_uint<8>,  // TOutput
        ap_int<24>,  // TSum
        ap_int<23>,  // TPartialSum
        ReLU<ap_int<24>>,  // Activation
        DequantQuantPo2<6, ap_int<24>, ap_uint<8>>,  // Quantizer
        576,  // OUT_CH
        96,  // IN_CH
        14,  // OUT_HEIGHT
        14,  // OUT_WIDTH
        1,  // GROUP
        1,  // FH
        1,  // FW
        1,  // STRIDE_H
        1,  // STRIDE_W
        16,  // IN_CH_PAR
        4,  // OUT_CH_PAR
        1  // W_PAR
    > StreamingConv_26;
    StreamingConv_26.step_init(11);
    BandwidthAdjustDecreaseChannels <
        std::array<ap_uint<8>, 4>,  // TInputStruct
        ap_uint<8>,  // TInput
        std::array<ap_uint<8>, 1>,  // TOutputStruct
        ap_uint<8>,  // TOutput
        DequantQuantEqual<ap_uint<8>>,  // Quantizer
        14,  // IN_HEIGHT
        14,  // IN_WIDTH
        576,  // IN_CH
        1,  // IN_W_PAR
        1,  // OUT_W_PAR
        4,  // IN_CH_PAR
        1  // OUT_CH_PAR
    > BandwidthAdjustDecreaseChannels_17;
    BandwidthAdjustDecreaseChannels_17.step_init(2);
    StreamingWindowSelector <
        std::array<ap_uint<8>, 1>,  // TWord
        14,  // IN_HEIGHT
        14,  // IN_WIDTH
        576,  // IN_CH
        3,  // FH
        3,  // FW
        2,  // STRIDE_H
        2,  // STRIDE_W
        1,  // DILATION_H
        1,  // DILATION_W
        1,  // PAD_T
        1,  // PAD_L
        1,  // PAD_B
        1,  // PAD_R
        2,  // POS_H
        2,  // POS_W
        1,  // W_PAR
        1  // CH_PAR
    > StreamingLineBuffer_36_pixel_0;
    StreamingLineBuffer_36_pixel_0.step_init(2, 1);
    StreamingWindowSelector <
        std::array<ap_uint<8>, 1>,  // TWord
        14,  // IN_HEIGHT
        14,  // IN_WIDTH
        576,  // IN_CH
        3,  // FH
        3,  // FW
        2,  // STRIDE_H
        2,  // STRIDE_W
        1,  // DILATION_H
        1,  // DILATION_W
        1,  // PAD_T
        1,  // PAD_L
        1,  // PAD_B
        1,  // PAD_R
        2,  // POS_H
        1,  // POS_W
        1,  // W_PAR
        1  // CH_PAR
    > StreamingLineBuffer_36_pixel_1;
    StreamingLineBuffer_36_pixel_1.step_init(2, 577);
    StreamingWindowSelector <
        std::array<ap_uint<8>, 1>,  // TWord
        14,  // IN_HEIGHT
        14,  // IN_WIDTH
        576,  // IN_CH
        3,  // FH
        3,  // FW
        2,  // STRIDE_H
        2,  // STRIDE_W
        1,  // DILATION_H
        1,  // DILATION_W
        1,  // PAD_T
        1,  // PAD_L
        1,  // PAD_B
        1,  // PAD_R
        2,  // POS_H
        0,  // POS_W
        1,  // W_PAR
        1  // CH_PAR
    > StreamingLineBuffer_36_pixel_2;
    StreamingLineBuffer_36_pixel_2.step_init(2, 577);
    StreamingWindowSelector <
        std::array<ap_uint<8>, 1>,  // TWord
        14,  // IN_HEIGHT
        14,  // IN_WIDTH
        576,  // IN_CH
        3,  // FH
        3,  // FW
        2,  // STRIDE_H
        2,  // STRIDE_W
        1,  // DILATION_H
        1,  // DILATION_W
        1,  // PAD_T
        1,  // PAD_L
        1,  // PAD_B
        1,  // PAD_R
        1,  // POS_H
        2,  // POS_W
        1,  // W_PAR
        1  // CH_PAR
    > StreamingLineBuffer_36_pixel_3;
    StreamingLineBuffer_36_pixel_3.step_init(2, 6913);
    StreamingWindowSelector <
        std::array<ap_uint<8>, 1>,  // TWord
        14,  // IN_HEIGHT
        14,  // IN_WIDTH
        576,  // IN_CH
        3,  // FH
        3,  // FW
        2,  // STRIDE_H
        2,  // STRIDE_W
        1,  // DILATION_H
        1,  // DILATION_W
        1,  // PAD_T
        1,  // PAD_L
        1,  // PAD_B
        1,  // PAD_R
        1,  // POS_H
        1,  // POS_W
        1,  // W_PAR
        1  // CH_PAR
    > StreamingLineBuffer_36_pixel_4;
    StreamingLineBuffer_36_pixel_4.step_init(2, 577);
    StreamingWindowSelector <
        std::array<ap_uint<8>, 1>,  // TWord
        14,  // IN_HEIGHT
        14,  // IN_WIDTH
        576,  // IN_CH
        3,  // FH
        3,  // FW
        2,  // STRIDE_H
        2,  // STRIDE_W
        1,  // DILATION_H
        1,  // DILATION_W
        1,  // PAD_T
        1,  // PAD_L
        1,  // PAD_B
        1,  // PAD_R
        1,  // POS_H
        0,  // POS_W
        1,  // W_PAR
        1  // CH_PAR
    > StreamingLineBuffer_36_pixel_5;
    StreamingLineBuffer_36_pixel_5.step_init(2, 577);
    StreamingWindowSelector <
        std::array<ap_uint<8>, 1>,  // TWord
        14,  // IN_HEIGHT
        14,  // IN_WIDTH
        576,  // IN_CH
        3,  // FH
        3,  // FW
        2,  // STRIDE_H
        2,  // STRIDE_W
        1,  // DILATION_H
        1,  // DILATION_W
        1,  // PAD_T
        1,  // PAD_L
        1,  // PAD_B
        1,  // PAD_R
        0,  // POS_H
        2,  // POS_W
        1,  // W_PAR
        1  // CH_PAR
    > StreamingLineBuffer_36_pixel_6;
    StreamingLineBuffer_36_pixel_6.step_init(2, 6913);
    StreamingWindowSelector <
        std::array<ap_uint<8>, 1>,  // TWord
        14,  // IN_HEIGHT
        14,  // IN_WIDTH
        576,  // IN_CH
        3,  // FH
        3,  // FW
        2,  // STRIDE_H
        2,  // STRIDE_W
        1,  // DILATION_H
        1,  // DILATION_W
        1,  // PAD_T
        1,  // PAD_L
        1,  // PAD_B
        1,  // PAD_R
        0,  // POS_H
        1,  // POS_W
        1,  // W_PAR
        1  // CH_PAR
    > StreamingLineBuffer_36_pixel_7;
    StreamingLineBuffer_36_pixel_7.step_init(2, 577);
    StreamingWindowSelector <
        std::array<ap_uint<8>, 1>,  // TWord
        14,  // IN_HEIGHT
        14,  // IN_WIDTH
        576,  // IN_CH
        3,  // FH
        3,  // FW
        2,  // STRIDE_H
        2,  // STRIDE_W
        1,  // DILATION_H
        1,  // DILATION_W
        1,  // PAD_T
        1,  // PAD_L
        1,  // PAD_B
        1,  // PAD_R
        0,  // POS_H
        0,  // POS_W
        1,  // W_PAR
        1  // CH_PAR
    > StreamingLineBuffer_36_pixel_8;
    StreamingLineBuffer_36_pixel_8.step_init(1, 577);
    StreamingPad <
        std::array<ap_uint<8>, 1>,  // TWord
        ap_uint<8>,  // TData
        14,  // IN_HEIGHT
        14,  // IN_WIDTH
        576,  // IN_CH
        3,  // FH
        3,  // FW
        2,  // STRIDE_H
        2,  // STRIDE_W
        1,  // DILATION_H
        1,  // DILATION_W
        1,  // PAD_T
        1,  // PAD_L
        1,  // PAD_B
        1,  // PAD_R
        1,  // W_PAR
        1,  // CH_PAR
        0  // PAD_VALUE
    > StreamingLineBuffer_36_pad;
    StreamingLineBuffer_36_pad.step_init(2);
    StreamingDepthwiseConv <
        std::array<ap_uint<8>, 1>,  // TInputStruct
        ap_uint<8>,  // TInput
        std::array<ap_int<8>, 1>,  // TWeightStruct
        ap_int<8>,  // TWeight
        std::array<ap_int<15>, 1>,  // TBiasStruct
        ap_int<15>,  // TBias
        std::array<ap_uint<8>, 1>,  // TOutputStruct
        ap_uint<8>,  // TOutput
        ap_int<21>,  // TSum
        ap_int<20>,  // TPartialSum
        ReLU<ap_int<21>>,  // Activation
        DequantQuantPo2<7, ap_int<21>, ap_uint<8>>,  // Quantizer
        576,  // OUT_CH
        576,  // IN_CH
        7,  // IN_HEIGHT
        7,  // IN_WIDTH
        3,  // FH
        3,  // FW
        2,  // STRIDE_H
        2,  // STRIDE_W
        1,  // CH_PAR
        1  // W_PAR
    > StreamingDepthwiseConv_13;
    StreamingDepthwiseConv_13.step_init(8);
    BandwidthAdjustIncreaseChannels <
        std::array<ap_uint<8>, 1>,  // TInputStruct
        ap_uint<8>,  // TInput
        std::array<ap_uint<8>, 6>,  // TOutputStruct
        ap_uint<8>,  // TOutput
        DequantQuantEqual<ap_uint<8>>,  // Quantizer
        7,  // IN_HEIGHT
        7,  // IN_WIDTH
        576,  // IN_CH
        1,  // IN_W_PAR
        1,  // OUT_W_PAR
        1,  // IN_CH_PAR
        6  // OUT_CH_PAR
    > BandwidthAdjustIncreaseChannels_22;
    BandwidthAdjustIncreaseChannels_22.step_init(2);
    StreamingConv <
        std::array<ap_uint<8>, 6>,  // TInputWord
        ap_uint<8>,  // TInput
        std::array<ap_int<8>, 24>,  // TWeightWord
        ap_int<8>,  // TWeight
        std::array<ap_int<15>, 4>,  // TBiasWord
        ap_int<15>,  // TBias
        std::array<ap_int<8>, 4>,  // TOutputWord
        ap_int<8>,  // TOutput
        ap_int<28>,  // TSum
        ap_int<27>,  // TPartialSum
        DequantQuantEqual<ap_int<28>>,  // Activation
        DequantQuantPo2<8, ap_int<28>, ap_int<8>>,  // Quantizer
        160,  // OUT_CH
        576,  // IN_CH
        7,  // OUT_HEIGHT
        7,  // OUT_WIDTH
        1,  // GROUP
        1,  // FH
        1,  // FW
        1,  // STRIDE_H
        1,  // STRIDE_W
        6,  // IN_CH_PAR
        4,  // OUT_CH_PAR
        1  // W_PAR
    > StreamingConv_27;
    StreamingConv_27.step_init(8);
    TensorDuplicator <
        std::array<ap_int<8>, 4>,  // TWord
        7,  // IN_HEIGHT
        7,  // IN_WIDTH
        160,  // IN_CH
        4,  // CH_PAR
        1  // W_PAR
    > TensorDuplicator_8;
    TensorDuplicator_8.step_init(1);
    BandwidthAdjustDecreaseChannels <
        std::array<ap_int<8>, 4>,  // TInputStruct
        ap_int<8>,  // TInput
        std::array<ap_int<8>, 2>,  // TOutputStruct
        ap_int<8>,  // TOutput
        DequantQuantEqual<ap_int<8>>,  // Quantizer
        7,  // IN_HEIGHT
        7,  // IN_WIDTH
        160,  // IN_CH
        1,  // IN_W_PAR
        1,  // OUT_W_PAR
        4,  // IN_CH_PAR
        2  // OUT_CH_PAR
    > BandwidthAdjustDecreaseChannels_18;
    BandwidthAdjustDecreaseChannels_18.step_init(2);
    BandwidthAdjustDecreaseChannels <
        std::array<ap_int<8>, 4>,  // TInputStruct
        ap_int<8>,  // TInput
        std::array<ap_int<8>, 2>,  // TOutputStruct
        ap_int<8>,  // TOutput
        DequantQuantEqual<ap_int<8>>,  // Quantizer
        7,  // IN_HEIGHT
        7,  // IN_WIDTH
        160,  // IN_CH
        1,  // IN_W_PAR
        1,  // OUT_W_PAR
        4,  // IN_CH_PAR
        2  // OUT_CH_PAR
    > BandwidthAdjustDecreaseChannels_19;
    BandwidthAdjustDecreaseChannels_19.step_init(2);
    BandwidthAdjustIncreaseChannels <
        std::array<ap_int<8>, 2>,  // TInputStruct
        ap_int<8>,  // TInput
        std::array<ap_int<8>, 10>,  // TOutputStruct
        ap_int<8>,  // TOutput
        DequantQuantEqual<ap_int<8>>,  // Quantizer
        7,  // IN_HEIGHT
        7,  // IN_WIDTH
        160,  // IN_CH
        1,  // IN_W_PAR
        1,  // OUT_W_PAR
        2,  // IN_CH_PAR
        10  // OUT_CH_PAR
    > BandwidthAdjustIncreaseChannels_23;
    BandwidthAdjustIncreaseChannels_23.step_init(2);
    StreamingConv <
        std::array<ap_int<8>, 10>,  // TInputWord
        ap_int<8>,  // TInput
        std::array<ap_int<8>, 40>,  // TWeightWord
        ap_int<8>,  // TWeight
        std::array<ap_int<15>, 4>,  // TBiasWord
        ap_int<15>,  // TBias
        std::array<ap_uint<8>, 4>,  // TOutputWord
        ap_uint<8>,  // TOutput
        ap_int<25>,  // TSum
        ap_int<24>,  // TPartialSum
        ReLU<ap_int<25>>,  // Activation
        DequantQuantPo2<8, ap_int<25>, ap_uint<8>>,  // Quantizer
        960,  // OUT_CH
        160,  // IN_CH
        7,  // OUT_HEIGHT
        7,  // OUT_WIDTH
        1,  // GROUP
        1,  // FH
        1,  // FW
        1,  // STRIDE_H
        1,  // STRIDE_W
        10,  // IN_CH_PAR
        4,  // OUT_CH_PAR
        1  // W_PAR
    > StreamingConv_28;
    StreamingConv_28.step_init(10);
    BandwidthAdjustDecreaseChannels <
        std::array<ap_uint<8>, 4>,  // TInputStruct
        ap_uint<8>,  // TInput
        std::array<ap_uint<8>, 1>,  // TOutputStruct
        ap_uint<8>,  // TOutput
        DequantQuantEqual<ap_uint<8>>,  // Quantizer
        7,  // IN_HEIGHT
        7,  // IN_WIDTH
        960,  // IN_CH
        1,  // IN_W_PAR
        1,  // OUT_W_PAR
        4,  // IN_CH_PAR
        1  // OUT_CH_PAR
    > BandwidthAdjustDecreaseChannels_20;
    BandwidthAdjustDecreaseChannels_20.step_init(2);
    StreamingWindowSelector <
        std::array<ap_uint<8>, 1>,  // TWord
        7,  // IN_HEIGHT
        7,  // IN_WIDTH
        960,  // IN_CH
        3,  // FH
        3,  // FW
        1,  // STRIDE_H
        1,  // STRIDE_W
        1,  // DILATION_H
        1,  // DILATION_W
        1,  // PAD_T
        1,  // PAD_L
        1,  // PAD_B
        1,  // PAD_R
        2,  // POS_H
        2,  // POS_W
        1,  // W_PAR
        1  // CH_PAR
    > StreamingLineBuffer_37_pixel_0;
    StreamingLineBuffer_37_pixel_0.step_init(2, 1);
    StreamingWindowSelector <
        std::array<ap_uint<8>, 1>,  // TWord
        7,  // IN_HEIGHT
        7,  // IN_WIDTH
        960,  // IN_CH
        3,  // FH
        3,  // FW
        1,  // STRIDE_H
        1,  // STRIDE_W
        1,  // DILATION_H
        1,  // DILATION_W
        1,  // PAD_T
        1,  // PAD_L
        1,  // PAD_B
        1,  // PAD_R
        2,  // POS_H
        1,  // POS_W
        1,  // W_PAR
        1  // CH_PAR
    > StreamingLineBuffer_37_pixel_1;
    StreamingLineBuffer_37_pixel_1.step_init(2, 961);
    StreamingWindowSelector <
        std::array<ap_uint<8>, 1>,  // TWord
        7,  // IN_HEIGHT
        7,  // IN_WIDTH
        960,  // IN_CH
        3,  // FH
        3,  // FW
        1,  // STRIDE_H
        1,  // STRIDE_W
        1,  // DILATION_H
        1,  // DILATION_W
        1,  // PAD_T
        1,  // PAD_L
        1,  // PAD_B
        1,  // PAD_R
        2,  // POS_H
        0,  // POS_W
        1,  // W_PAR
        1  // CH_PAR
    > StreamingLineBuffer_37_pixel_2;
    StreamingLineBuffer_37_pixel_2.step_init(2, 961);
    StreamingWindowSelector <
        std::array<ap_uint<8>, 1>,  // TWord
        7,  // IN_HEIGHT
        7,  // IN_WIDTH
        960,  // IN_CH
        3,  // FH
        3,  // FW
        1,  // STRIDE_H
        1,  // STRIDE_W
        1,  // DILATION_H
        1,  // DILATION_W
        1,  // PAD_T
        1,  // PAD_L
        1,  // PAD_B
        1,  // PAD_R
        1,  // POS_H
        2,  // POS_W
        1,  // W_PAR
        1  // CH_PAR
    > StreamingLineBuffer_37_pixel_3;
    StreamingLineBuffer_37_pixel_3.step_init(2, 4801);
    StreamingWindowSelector <
        std::array<ap_uint<8>, 1>,  // TWord
        7,  // IN_HEIGHT
        7,  // IN_WIDTH
        960,  // IN_CH
        3,  // FH
        3,  // FW
        1,  // STRIDE_H
        1,  // STRIDE_W
        1,  // DILATION_H
        1,  // DILATION_W
        1,  // PAD_T
        1,  // PAD_L
        1,  // PAD_B
        1,  // PAD_R
        1,  // POS_H
        1,  // POS_W
        1,  // W_PAR
        1  // CH_PAR
    > StreamingLineBuffer_37_pixel_4;
    StreamingLineBuffer_37_pixel_4.step_init(1, 961);
    StreamingWindowSelector <
        std::array<ap_uint<8>, 1>,  // TWord
        7,  // IN_HEIGHT
        7,  // IN_WIDTH
        960,  // IN_CH
        3,  // FH
        3,  // FW
        1,  // STRIDE_H
        1,  // STRIDE_W
        1,  // DILATION_H
        1,  // DILATION_W
        1,  // PAD_T
        1,  // PAD_L
        1,  // PAD_B
        1,  // PAD_R
        1,  // POS_H
        0,  // POS_W
        1,  // W_PAR
        1  // CH_PAR
    > StreamingLineBuffer_37_pixel_5;
    StreamingLineBuffer_37_pixel_5.step_init(2, 961);
    StreamingWindowSelector <
        std::array<ap_uint<8>, 1>,  // TWord
        7,  // IN_HEIGHT
        7,  // IN_WIDTH
        960,  // IN_CH
        3,  // FH
        3,  // FW
        1,  // STRIDE_H
        1,  // STRIDE_W
        1,  // DILATION_H
        1,  // DILATION_W
        1,  // PAD_T
        1,  // PAD_L
        1,  // PAD_B
        1,  // PAD_R
        0,  // POS_H
        2,  // POS_W
        1,  // W_PAR
        1  // CH_PAR
    > StreamingLineBuffer_37_pixel_6;
    StreamingLineBuffer_37_pixel_6.step_init(2, 4801);
    StreamingWindowSelector <
        std::array<ap_uint<8>, 1>,  // TWord
        7,  // IN_HEIGHT
        7,  // IN_WIDTH
        960,  // IN_CH
        3,  // FH
        3,  // FW
        1,  // STRIDE_H
        1,  // STRIDE_W
        1,  // DILATION_H
        1,  // DILATION_W
        1,  // PAD_T
        1,  // PAD_L
        1,  // PAD_B
        1,  // PAD_R
        0,  // POS_H
        1,  // POS_W
        1,  // W_PAR
        1  // CH_PAR
    > StreamingLineBuffer_37_pixel_7;
    StreamingLineBuffer_37_pixel_7.step_init(2, 961);
    StreamingWindowSelector <
        std::array<ap_uint<8>, 1>,  // TWord
        7,  // IN_HEIGHT
        7,  // IN_WIDTH
        960,  // IN_CH
        3,  // FH
        3,  // FW
        1,  // STRIDE_H
        1,  // STRIDE_W
        1,  // DILATION_H
        1,  // DILATION_W
        1,  // PAD_T
        1,  // PAD_L
        1,  // PAD_B
        1,  // PAD_R
        0,  // POS_H
        0,  // POS_W
        1,  // W_PAR
        1  // CH_PAR
    > StreamingLineBuffer_37_pixel_8;
    StreamingLineBuffer_37_pixel_8.step_init(1, 961);
    StreamingPad <
        std::array<ap_uint<8>, 1>,  // TWord
        ap_uint<8>,  // TData
        7,  // IN_HEIGHT
        7,  // IN_WIDTH
        960,  // IN_CH
        3,  // FH
        3,  // FW
        1,  // STRIDE_H
        1,  // STRIDE_W
        1,  // DILATION_H
        1,  // DILATION_W
        1,  // PAD_T
        1,  // PAD_L
        1,  // PAD_B
        1,  // PAD_R
        1,  // W_PAR
        1,  // CH_PAR
        0  // PAD_VALUE
    > StreamingLineBuffer_37_pad;
    StreamingLineBuffer_37_pad.step_init(2);
    StreamingDepthwiseConv <
        std::array<ap_uint<8>, 1>,  // TInputStruct
        ap_uint<8>,  // TInput
        std::array<ap_int<8>, 1>,  // TWeightStruct
        ap_int<8>,  // TWeight
        std::array<ap_int<15>, 1>,  // TBiasStruct
        ap_int<15>,  // TBias
        std::array<ap_uint<8>, 1>,  // TOutputStruct
        ap_uint<8>,  // TOutput
        ap_int<21>,  // TSum
        ap_int<20>,  // TPartialSum
        ReLU<ap_int<21>>,  // Activation
        DequantQuantPo2<6, ap_int<21>, ap_uint<8>>,  // Quantizer
        960,  // OUT_CH
        960,  // IN_CH
        7,  // IN_HEIGHT
        7,  // IN_WIDTH
        3,  // FH
        3,  // FW
        1,  // STRIDE_H
        1,  // STRIDE_W
        1,  // CH_PAR
        1  // W_PAR
    > StreamingDepthwiseConv_14;
    StreamingDepthwiseConv_14.step_init(8);
    BandwidthAdjustIncreaseChannels <
        std::array<ap_uint<8>, 1>,  // TInputStruct
        ap_uint<8>,  // TInput
        std::array<ap_uint<8>, 20>,  // TOutputStruct
        ap_uint<8>,  // TOutput
        DequantQuantEqual<ap_uint<8>>,  // Quantizer
        7,  // IN_HEIGHT
        7,  // IN_WIDTH
        960,  // IN_CH
        1,  // IN_W_PAR
        1,  // OUT_W_PAR
        1,  // IN_CH_PAR
        20  // OUT_CH_PAR
    > BandwidthAdjustIncreaseChannels_24;
    BandwidthAdjustIncreaseChannels_24.step_init(2);
    StreamingConv <
        std::array<ap_uint<8>, 20>,  // TInputWord
        ap_uint<8>,  // TInput
        std::array<ap_int<8>, 40>,  // TWeightWord
        ap_int<8>,  // TWeight
        std::array<ap_int<16>, 2>,  // TBiasWord
        ap_int<16>,  // TBias
        std::array<ap_int<8>, 2>,  // TOutputWord
        ap_int<8>,  // TOutput
        ap_int<28>,  // TSum
        ap_int<27>,  // TPartialSum
        DequantQuantEqual<ap_int<28>>,  // Activation
        DequantQuantPo2<10, ap_int<28>, ap_int<8>>,  // Quantizer
        160,  // OUT_CH
        960,  // IN_CH
        7,  // OUT_HEIGHT
        7,  // OUT_WIDTH
        1,  // GROUP
        1,  // FH
        1,  // FW
        1,  // STRIDE_H
        1,  // STRIDE_W
        20,  // IN_CH_PAR
        2,  // OUT_CH_PAR
        1  // W_PAR
    > StreamingConv_29;
    StreamingConv_29.step_init(11);
    StreamingAdd <
        std::array<ap_int<8>, 2>,  // TInputWordA
        ap_int<8>,  // TInputA
        std::array<ap_int<8>, 2>,  // TInputWordB
        ap_int<8>,  // TInputB
        std::array<ap_int<8>, 2>,  // TOutputWord
        ap_int<8>,  // TOutput
        ap_int<9>,  // TAcc
        DequantQuantEqual<ap_int<9>>,  // Activation
        DequantQuantPo2<1, ap_int<9>, ap_int<8>>,  // Quantizer
        DequantQuantEqual<ap_int<8>>,  // AlignA
        DequantQuantEqual<ap_int<8>>,  // AlignB
        7,  // IN_HEIGHT
        7,  // IN_WIDTH
        160,  // IN_CH
        1,  // W_PAR
        2  // CH_PAR
    > StreamingAdd_8;
    StreamingAdd_8.step_init(3);
    BandwidthAdjustIncreaseChannels <
        std::array<ap_int<8>, 2>,  // TInputStruct
        ap_int<8>,  // TInput
        std::array<ap_int<8>, 4>,  // TOutputStruct
        ap_int<8>,  // TOutput
        DequantQuantEqual<ap_int<8>>,  // Quantizer
        7,  // IN_HEIGHT
        7,  // IN_WIDTH
        160,  // IN_CH
        1,  // IN_W_PAR
        1,  // OUT_W_PAR
        2,  // IN_CH_PAR
        4  // OUT_CH_PAR
    > BandwidthAdjustIncreaseChannels_25;
    BandwidthAdjustIncreaseChannels_25.step_init(2);
    TensorDuplicator <
        std::array<ap_int<8>, 4>,  // TWord
        7,  // IN_HEIGHT
        7,  // IN_WIDTH
        160,  // IN_CH
        4,  // CH_PAR
        1  // W_PAR
    > TensorDuplicator_9;
    TensorDuplicator_9.step_init(1);
    BandwidthAdjustIncreaseChannels <
        std::array<ap_int<8>, 4>,  // TInputStruct
        ap_int<8>,  // TInput
        std::array<ap_int<8>, 20>,  // TOutputStruct
        ap_int<8>,  // TOutput
        DequantQuantEqual<ap_int<8>>,  // Quantizer
        7,  // IN_HEIGHT
        7,  // IN_WIDTH
        160,  // IN_CH
        1,  // IN_W_PAR
        1,  // OUT_W_PAR
        4,  // IN_CH_PAR
        20  // OUT_CH_PAR
    > BandwidthAdjustIncreaseChannels_26;
    BandwidthAdjustIncreaseChannels_26.step_init(2);
    BandwidthAdjustDecreaseChannels <
        std::array<ap_int<8>, 4>,  // TInputStruct
        ap_int<8>,  // TInput
        std::array<ap_int<8>, 2>,  // TOutputStruct
        ap_int<8>,  // TOutput
        DequantQuantEqual<ap_int<8>>,  // Quantizer
        7,  // IN_HEIGHT
        7,  // IN_WIDTH
        160,  // IN_CH
        1,  // IN_W_PAR
        1,  // OUT_W_PAR
        4,  // IN_CH_PAR
        2  // OUT_CH_PAR
    > BandwidthAdjustDecreaseChannels_21;
    BandwidthAdjustDecreaseChannels_21.step_init(2);
    StreamingConv <
        std::array<ap_int<8>, 20>,  // TInputWord
        ap_int<8>,  // TInput
        std::array<ap_int<8>, 40>,  // TWeightWord
        ap_int<8>,  // TWeight
        std::array<ap_int<13>, 2>,  // TBiasWord
        ap_int<13>,  // TBias
        std::array<ap_uint<8>, 2>,  // TOutputWord
        ap_uint<8>,  // TOutput
        ap_int<25>,  // TSum
        ap_int<24>,  // TPartialSum
        ReLU<ap_int<25>>,  // Activation
        DequantQuantPo2<6, ap_int<25>, ap_uint<8>>,  // Quantizer
        960,  // OUT_CH
        160,  // IN_CH
        7,  // OUT_HEIGHT
        7,  // OUT_WIDTH
        1,  // GROUP
        1,  // FH
        1,  // FW
        1,  // STRIDE_H
        1,  // STRIDE_W
        20,  // IN_CH_PAR
        2,  // OUT_CH_PAR
        1  // W_PAR
    > StreamingConv_30;
    StreamingConv_30.step_init(10);
    BandwidthAdjustDecreaseChannels <
        std::array<ap_uint<8>, 2>,  // TInputStruct
        ap_uint<8>,  // TInput
        std::array<ap_uint<8>, 1>,  // TOutputStruct
        ap_uint<8>,  // TOutput
        DequantQuantEqual<ap_uint<8>>,  // Quantizer
        7,  // IN_HEIGHT
        7,  // IN_WIDTH
        960,  // IN_CH
        1,  // IN_W_PAR
        1,  // OUT_W_PAR
        2,  // IN_CH_PAR
        1  // OUT_CH_PAR
    > BandwidthAdjustDecreaseChannels_22;
    BandwidthAdjustDecreaseChannels_22.step_init(2);
    StreamingWindowSelector <
        std::array<ap_uint<8>, 1>,  // TWord
        7,  // IN_HEIGHT
        7,  // IN_WIDTH
        960,  // IN_CH
        3,  // FH
        3,  // FW
        1,  // STRIDE_H
        1,  // STRIDE_W
        1,  // DILATION_H
        1,  // DILATION_W
        1,  // PAD_T
        1,  // PAD_L
        1,  // PAD_B
        1,  // PAD_R
        2,  // POS_H
        2,  // POS_W
        1,  // W_PAR
        1  // CH_PAR
    > StreamingLineBuffer_38_pixel_0;
    StreamingLineBuffer_38_pixel_0.step_init(2, 1);
    StreamingWindowSelector <
        std::array<ap_uint<8>, 1>,  // TWord
        7,  // IN_HEIGHT
        7,  // IN_WIDTH
        960,  // IN_CH
        3,  // FH
        3,  // FW
        1,  // STRIDE_H
        1,  // STRIDE_W
        1,  // DILATION_H
        1,  // DILATION_W
        1,  // PAD_T
        1,  // PAD_L
        1,  // PAD_B
        1,  // PAD_R
        2,  // POS_H
        1,  // POS_W
        1,  // W_PAR
        1  // CH_PAR
    > StreamingLineBuffer_38_pixel_1;
    StreamingLineBuffer_38_pixel_1.step_init(2, 961);
    StreamingWindowSelector <
        std::array<ap_uint<8>, 1>,  // TWord
        7,  // IN_HEIGHT
        7,  // IN_WIDTH
        960,  // IN_CH
        3,  // FH
        3,  // FW
        1,  // STRIDE_H
        1,  // STRIDE_W
        1,  // DILATION_H
        1,  // DILATION_W
        1,  // PAD_T
        1,  // PAD_L
        1,  // PAD_B
        1,  // PAD_R
        2,  // POS_H
        0,  // POS_W
        1,  // W_PAR
        1  // CH_PAR
    > StreamingLineBuffer_38_pixel_2;
    StreamingLineBuffer_38_pixel_2.step_init(2, 961);
    StreamingWindowSelector <
        std::array<ap_uint<8>, 1>,  // TWord
        7,  // IN_HEIGHT
        7,  // IN_WIDTH
        960,  // IN_CH
        3,  // FH
        3,  // FW
        1,  // STRIDE_H
        1,  // STRIDE_W
        1,  // DILATION_H
        1,  // DILATION_W
        1,  // PAD_T
        1,  // PAD_L
        1,  // PAD_B
        1,  // PAD_R
        1,  // POS_H
        2,  // POS_W
        1,  // W_PAR
        1  // CH_PAR
    > StreamingLineBuffer_38_pixel_3;
    StreamingLineBuffer_38_pixel_3.step_init(2, 4801);
    StreamingWindowSelector <
        std::array<ap_uint<8>, 1>,  // TWord
        7,  // IN_HEIGHT
        7,  // IN_WIDTH
        960,  // IN_CH
        3,  // FH
        3,  // FW
        1,  // STRIDE_H
        1,  // STRIDE_W
        1,  // DILATION_H
        1,  // DILATION_W
        1,  // PAD_T
        1,  // PAD_L
        1,  // PAD_B
        1,  // PAD_R
        1,  // POS_H
        1,  // POS_W
        1,  // W_PAR
        1  // CH_PAR
    > StreamingLineBuffer_38_pixel_4;
    StreamingLineBuffer_38_pixel_4.step_init(1, 961);
    StreamingWindowSelector <
        std::array<ap_uint<8>, 1>,  // TWord
        7,  // IN_HEIGHT
        7,  // IN_WIDTH
        960,  // IN_CH
        3,  // FH
        3,  // FW
        1,  // STRIDE_H
        1,  // STRIDE_W
        1,  // DILATION_H
        1,  // DILATION_W
        1,  // PAD_T
        1,  // PAD_L
        1,  // PAD_B
        1,  // PAD_R
        1,  // POS_H
        0,  // POS_W
        1,  // W_PAR
        1  // CH_PAR
    > StreamingLineBuffer_38_pixel_5;
    StreamingLineBuffer_38_pixel_5.step_init(2, 961);
    StreamingWindowSelector <
        std::array<ap_uint<8>, 1>,  // TWord
        7,  // IN_HEIGHT
        7,  // IN_WIDTH
        960,  // IN_CH
        3,  // FH
        3,  // FW
        1,  // STRIDE_H
        1,  // STRIDE_W
        1,  // DILATION_H
        1,  // DILATION_W
        1,  // PAD_T
        1,  // PAD_L
        1,  // PAD_B
        1,  // PAD_R
        0,  // POS_H
        2,  // POS_W
        1,  // W_PAR
        1  // CH_PAR
    > StreamingLineBuffer_38_pixel_6;
    StreamingLineBuffer_38_pixel_6.step_init(2, 4801);
    StreamingWindowSelector <
        std::array<ap_uint<8>, 1>,  // TWord
        7,  // IN_HEIGHT
        7,  // IN_WIDTH
        960,  // IN_CH
        3,  // FH
        3,  // FW
        1,  // STRIDE_H
        1,  // STRIDE_W
        1,  // DILATION_H
        1,  // DILATION_W
        1,  // PAD_T
        1,  // PAD_L
        1,  // PAD_B
        1,  // PAD_R
        0,  // POS_H
        1,  // POS_W
        1,  // W_PAR
        1  // CH_PAR
    > StreamingLineBuffer_38_pixel_7;
    StreamingLineBuffer_38_pixel_7.step_init(2, 961);
    StreamingWindowSelector <
        std::array<ap_uint<8>, 1>,  // TWord
        7,  // IN_HEIGHT
        7,  // IN_WIDTH
        960,  // IN_CH
        3,  // FH
        3,  // FW
        1,  // STRIDE_H
        1,  // STRIDE_W
        1,  // DILATION_H
        1,  // DILATION_W
        1,  // PAD_T
        1,  // PAD_L
        1,  // PAD_B
        1,  // PAD_R
        0,  // POS_H
        0,  // POS_W
        1,  // W_PAR
        1  // CH_PAR
    > StreamingLineBuffer_38_pixel_8;
    StreamingLineBuffer_38_pixel_8.step_init(1, 961);
    StreamingPad <
        std::array<ap_uint<8>, 1>,  // TWord
        ap_uint<8>,  // TData
        7,  // IN_HEIGHT
        7,  // IN_WIDTH
        960,  // IN_CH
        3,  // FH
        3,  // FW
        1,  // STRIDE_H
        1,  // STRIDE_W
        1,  // DILATION_H
        1,  // DILATION_W
        1,  // PAD_T
        1,  // PAD_L
        1,  // PAD_B
        1,  // PAD_R
        1,  // W_PAR
        1,  // CH_PAR
        0  // PAD_VALUE
    > StreamingLineBuffer_38_pad;
    StreamingLineBuffer_38_pad.step_init(2);
    StreamingDepthwiseConv <
        std::array<ap_uint<8>, 1>,  // TInputStruct
        ap_uint<8>,  // TInput
        std::array<ap_int<8>, 1>,  // TWeightStruct
        ap_int<8>,  // TWeight
        std::array<ap_int<14>, 1>,  // TBiasStruct
        ap_int<14>,  // TBias
        std::array<ap_uint<8>, 1>,  // TOutputStruct
        ap_uint<8>,  // TOutput
        ap_int<21>,  // TSum
        ap_int<20>,  // TPartialSum
        ReLU<ap_int<21>>,  // Activation
        DequantQuantPo2<6, ap_int<21>, ap_uint<8>>,  // Quantizer
        960,  // OUT_CH
        960,  // IN_CH
        7,  // IN_HEIGHT
        7,  // IN_WIDTH
        3,  // FH
        3,  // FW
        1,  // STRIDE_H
        1,  // STRIDE_W
        1,  // CH_PAR
        1  // W_PAR
    > StreamingDepthwiseConv_15;
    StreamingDepthwiseConv_15.step_init(8);
    BandwidthAdjustIncreaseChannels <
        std::array<ap_uint<8>, 1>,  // TInputStruct
        ap_uint<8>,  // TInput
        std::array<ap_uint<8>, 20>,  // TOutputStruct
        ap_uint<8>,  // TOutput
        DequantQuantEqual<ap_uint<8>>,  // Quantizer
        7,  // IN_HEIGHT
        7,  // IN_WIDTH
        960,  // IN_CH
        1,  // IN_W_PAR
        1,  // OUT_W_PAR
        1,  // IN_CH_PAR
        20  // OUT_CH_PAR
    > BandwidthAdjustIncreaseChannels_27;
    BandwidthAdjustIncreaseChannels_27.step_init(2);
    StreamingConv <
        std::array<ap_uint<8>, 20>,  // TInputWord
        ap_uint<8>,  // TInput
        std::array<ap_int<8>, 40>,  // TWeightWord
        ap_int<8>,  // TWeight
        std::array<ap_int<15>, 2>,  // TBiasWord
        ap_int<15>,  // TBias
        std::array<ap_int<8>, 2>,  // TOutputWord
        ap_int<8>,  // TOutput
        ap_int<28>,  // TSum
        ap_int<27>,  // TPartialSum
        DequantQuantEqual<ap_int<28>>,  // Activation
        DequantQuantPo2<9, ap_int<28>, ap_int<8>>,  // Quantizer
        160,  // OUT_CH
        960,  // IN_CH
        7,  // OUT_HEIGHT
        7,  // OUT_WIDTH
        1,  // GROUP
        1,  // FH
        1,  // FW
        1,  // STRIDE_H
        1,  // STRIDE_W
        20,  // IN_CH_PAR
        2,  // OUT_CH_PAR
        1  // W_PAR
    > StreamingConv_31;
    StreamingConv_31.step_init(11);
    StreamingAdd <
        std::array<ap_int<8>, 2>,  // TInputWordA
        ap_int<8>,  // TInputA
        std::array<ap_int<8>, 2>,  // TInputWordB
        ap_int<8>,  // TInputB
        std::array<ap_int<8>, 2>,  // TOutputWord
        ap_int<8>,  // TOutput
        ap_int<9>,  // TAcc
        DequantQuantEqual<ap_int<9>>,  // Activation
        DequantQuantPo2<1, ap_int<9>, ap_int<8>>,  // Quantizer
        DequantQuantEqual<ap_int<8>>,  // AlignA
        DequantQuantEqual<ap_int<8>>,  // AlignB
        7,  // IN_HEIGHT
        7,  // IN_WIDTH
        160,  // IN_CH
        1,  // W_PAR
        2  // CH_PAR
    > StreamingAdd_9;
    StreamingAdd_9.step_init(3);
    BandwidthAdjustIncreaseChannels <
        std::array<ap_int<8>, 2>,  // TInputStruct
        ap_int<8>,  // TInput
        std::array<ap_int<8>, 20>,  // TOutputStruct
        ap_int<8>,  // TOutput
        DequantQuantEqual<ap_int<8>>,  // Quantizer
        7,  // IN_HEIGHT
        7,  // IN_WIDTH
        160,  // IN_CH
        1,  // IN_W_PAR
        1,  // OUT_W_PAR
        2,  // IN_CH_PAR
        20  // OUT_CH_PAR
    > BandwidthAdjustIncreaseChannels_28;
    BandwidthAdjustIncreaseChannels_28.step_init(2);
    StreamingConv <
        std::array<ap_int<8>, 20>,  // TInputWord
        ap_int<8>,  // TInput
        std::array<ap_int<8>, 40>,  // TWeightWord
        ap_int<8>,  // TWeight
        std::array<ap_int<14>, 2>,  // TBiasWord
        ap_int<14>,  // TBias
        std::array<ap_uint<8>, 2>,  // TOutputWord
        ap_uint<8>,  // TOutput
        ap_int<25>,  // TSum
        ap_int<24>,  // TPartialSum
        ReLU<ap_int<25>>,  // Activation
        DequantQuantPo2<6, ap_int<25>, ap_uint<8>>,  // Quantizer
        960,  // OUT_CH
        160,  // IN_CH
        7,  // OUT_HEIGHT
        7,  // OUT_WIDTH
        1,  // GROUP
        1,  // FH
        1,  // FW
        1,  // STRIDE_H
        1,  // STRIDE_W
        20,  // IN_CH_PAR
        2,  // OUT_CH_PAR
        1  // W_PAR
    > StreamingConv_32;
    StreamingConv_32.step_init(10);
    BandwidthAdjustDecreaseChannels <
        std::array<ap_uint<8>, 2>,  // TInputStruct
        ap_uint<8>,  // TInput
        std::array<ap_uint<8>, 1>,  // TOutputStruct
        ap_uint<8>,  // TOutput
        DequantQuantEqual<ap_uint<8>>,  // Quantizer
        7,  // IN_HEIGHT
        7,  // IN_WIDTH
        960,  // IN_CH
        1,  // IN_W_PAR
        1,  // OUT_W_PAR
        2,  // IN_CH_PAR
        1  // OUT_CH_PAR
    > BandwidthAdjustDecreaseChannels_23;
    BandwidthAdjustDecreaseChannels_23.step_init(2);
    StreamingWindowSelector <
        std::array<ap_uint<8>, 1>,  // TWord
        7,  // IN_HEIGHT
        7,  // IN_WIDTH
        960,  // IN_CH
        3,  // FH
        3,  // FW
        1,  // STRIDE_H
        1,  // STRIDE_W
        1,  // DILATION_H
        1,  // DILATION_W
        1,  // PAD_T
        1,  // PAD_L
        1,  // PAD_B
        1,  // PAD_R
        2,  // POS_H
        2,  // POS_W
        1,  // W_PAR
        1  // CH_PAR
    > StreamingLineBuffer_39_pixel_0;
    StreamingLineBuffer_39_pixel_0.step_init(2, 1);
    StreamingWindowSelector <
        std::array<ap_uint<8>, 1>,  // TWord
        7,  // IN_HEIGHT
        7,  // IN_WIDTH
        960,  // IN_CH
        3,  // FH
        3,  // FW
        1,  // STRIDE_H
        1,  // STRIDE_W
        1,  // DILATION_H
        1,  // DILATION_W
        1,  // PAD_T
        1,  // PAD_L
        1,  // PAD_B
        1,  // PAD_R
        2,  // POS_H
        1,  // POS_W
        1,  // W_PAR
        1  // CH_PAR
    > StreamingLineBuffer_39_pixel_1;
    StreamingLineBuffer_39_pixel_1.step_init(2, 961);
    StreamingWindowSelector <
        std::array<ap_uint<8>, 1>,  // TWord
        7,  // IN_HEIGHT
        7,  // IN_WIDTH
        960,  // IN_CH
        3,  // FH
        3,  // FW
        1,  // STRIDE_H
        1,  // STRIDE_W
        1,  // DILATION_H
        1,  // DILATION_W
        1,  // PAD_T
        1,  // PAD_L
        1,  // PAD_B
        1,  // PAD_R
        2,  // POS_H
        0,  // POS_W
        1,  // W_PAR
        1  // CH_PAR
    > StreamingLineBuffer_39_pixel_2;
    StreamingLineBuffer_39_pixel_2.step_init(2, 961);
    StreamingWindowSelector <
        std::array<ap_uint<8>, 1>,  // TWord
        7,  // IN_HEIGHT
        7,  // IN_WIDTH
        960,  // IN_CH
        3,  // FH
        3,  // FW
        1,  // STRIDE_H
        1,  // STRIDE_W
        1,  // DILATION_H
        1,  // DILATION_W
        1,  // PAD_T
        1,  // PAD_L
        1,  // PAD_B
        1,  // PAD_R
        1,  // POS_H
        2,  // POS_W
        1,  // W_PAR
        1  // CH_PAR
    > StreamingLineBuffer_39_pixel_3;
    StreamingLineBuffer_39_pixel_3.step_init(2, 4801);
    StreamingWindowSelector <
        std::array<ap_uint<8>, 1>,  // TWord
        7,  // IN_HEIGHT
        7,  // IN_WIDTH
        960,  // IN_CH
        3,  // FH
        3,  // FW
        1,  // STRIDE_H
        1,  // STRIDE_W
        1,  // DILATION_H
        1,  // DILATION_W
        1,  // PAD_T
        1,  // PAD_L
        1,  // PAD_B
        1,  // PAD_R
        1,  // POS_H
        1,  // POS_W
        1,  // W_PAR
        1  // CH_PAR
    > StreamingLineBuffer_39_pixel_4;
    StreamingLineBuffer_39_pixel_4.step_init(1, 961);
    StreamingWindowSelector <
        std::array<ap_uint<8>, 1>,  // TWord
        7,  // IN_HEIGHT
        7,  // IN_WIDTH
        960,  // IN_CH
        3,  // FH
        3,  // FW
        1,  // STRIDE_H
        1,  // STRIDE_W
        1,  // DILATION_H
        1,  // DILATION_W
        1,  // PAD_T
        1,  // PAD_L
        1,  // PAD_B
        1,  // PAD_R
        1,  // POS_H
        0,  // POS_W
        1,  // W_PAR
        1  // CH_PAR
    > StreamingLineBuffer_39_pixel_5;
    StreamingLineBuffer_39_pixel_5.step_init(2, 961);
    StreamingWindowSelector <
        std::array<ap_uint<8>, 1>,  // TWord
        7,  // IN_HEIGHT
        7,  // IN_WIDTH
        960,  // IN_CH
        3,  // FH
        3,  // FW
        1,  // STRIDE_H
        1,  // STRIDE_W
        1,  // DILATION_H
        1,  // DILATION_W
        1,  // PAD_T
        1,  // PAD_L
        1,  // PAD_B
        1,  // PAD_R
        0,  // POS_H
        2,  // POS_W
        1,  // W_PAR
        1  // CH_PAR
    > StreamingLineBuffer_39_pixel_6;
    StreamingLineBuffer_39_pixel_6.step_init(2, 4801);
    StreamingWindowSelector <
        std::array<ap_uint<8>, 1>,  // TWord
        7,  // IN_HEIGHT
        7,  // IN_WIDTH
        960,  // IN_CH
        3,  // FH
        3,  // FW
        1,  // STRIDE_H
        1,  // STRIDE_W
        1,  // DILATION_H
        1,  // DILATION_W
        1,  // PAD_T
        1,  // PAD_L
        1,  // PAD_B
        1,  // PAD_R
        0,  // POS_H
        1,  // POS_W
        1,  // W_PAR
        1  // CH_PAR
    > StreamingLineBuffer_39_pixel_7;
    StreamingLineBuffer_39_pixel_7.step_init(2, 961);
    StreamingWindowSelector <
        std::array<ap_uint<8>, 1>,  // TWord
        7,  // IN_HEIGHT
        7,  // IN_WIDTH
        960,  // IN_CH
        3,  // FH
        3,  // FW
        1,  // STRIDE_H
        1,  // STRIDE_W
        1,  // DILATION_H
        1,  // DILATION_W
        1,  // PAD_T
        1,  // PAD_L
        1,  // PAD_B
        1,  // PAD_R
        0,  // POS_H
        0,  // POS_W
        1,  // W_PAR
        1  // CH_PAR
    > StreamingLineBuffer_39_pixel_8;
    StreamingLineBuffer_39_pixel_8.step_init(1, 961);
    StreamingPad <
        std::array<ap_uint<8>, 1>,  // TWord
        ap_uint<8>,  // TData
        7,  // IN_HEIGHT
        7,  // IN_WIDTH
        960,  // IN_CH
        3,  // FH
        3,  // FW
        1,  // STRIDE_H
        1,  // STRIDE_W
        1,  // DILATION_H
        1,  // DILATION_W
        1,  // PAD_T
        1,  // PAD_L
        1,  // PAD_B
        1,  // PAD_R
        1,  // W_PAR
        1,  // CH_PAR
        0  // PAD_VALUE
    > StreamingLineBuffer_39_pad;
    StreamingLineBuffer_39_pad.step_init(2);
    StreamingDepthwiseConv <
        std::array<ap_uint<8>, 1>,  // TInputStruct
        ap_uint<8>,  // TInput
        std::array<ap_int<8>, 1>,  // TWeightStruct
        ap_int<8>,  // TWeight
        std::array<ap_int<15>, 1>,  // TBiasStruct
        ap_int<15>,  // TBias
        std::array<ap_uint<8>, 1>,  // TOutputStruct
        ap_uint<8>,  // TOutput
        ap_int<21>,  // TSum
        ap_int<20>,  // TPartialSum
        ReLU<ap_int<21>>,  // Activation
        DequantQuantPo2<7, ap_int<21>, ap_uint<8>>,  // Quantizer
        960,  // OUT_CH
        960,  // IN_CH
        7,  // IN_HEIGHT
        7,  // IN_WIDTH
        3,  // FH
        3,  // FW
        1,  // STRIDE_H
        1,  // STRIDE_W
        1,  // CH_PAR
        1  // W_PAR
    > StreamingDepthwiseConv_16;
    StreamingDepthwiseConv_16.step_init(8);
    BandwidthAdjustIncreaseChannels <
        std::array<ap_uint<8>, 1>,  // TInputStruct
        ap_uint<8>,  // TInput
        std::array<ap_uint<8>, 20>,  // TOutputStruct
        ap_uint<8>,  // TOutput
        DequantQuantEqual<ap_uint<8>>,  // Quantizer
        7,  // IN_HEIGHT
        7,  // IN_WIDTH
        960,  // IN_CH
        1,  // IN_W_PAR
        1,  // OUT_W_PAR
        1,  // IN_CH_PAR
        20  // OUT_CH_PAR
    > BandwidthAdjustIncreaseChannels_29;
    BandwidthAdjustIncreaseChannels_29.step_init(2);
    StreamingConv <
        std::array<ap_uint<8>, 20>,  // TInputWord
        ap_uint<8>,  // TInput
        std::array<ap_int<8>, 80>,  // TWeightWord
        ap_int<8>,  // TWeight
        std::array<ap_int<15>, 4>,  // TBiasWord
        ap_int<15>,  // TBias
        std::array<ap_int<8>, 4>,  // TOutputWord
        ap_int<8>,  // TOutput
        ap_int<28>,  // TSum
        ap_int<27>,  // TPartialSum
        DequantQuantEqual<ap_int<28>>,  // Activation
        DequantQuantPo2<8, ap_int<28>, ap_int<8>>,  // Quantizer
        320,  // OUT_CH
        960,  // IN_CH
        7,  // OUT_HEIGHT
        7,  // OUT_WIDTH
        1,  // GROUP
        1,  // FH
        1,  // FW
        1,  // STRIDE_H
        1,  // STRIDE_W
        20,  // IN_CH_PAR
        4,  // OUT_CH_PAR
        1  // W_PAR
    > StreamingConv_33;
    StreamingConv_33.step_init(11);
    BandwidthAdjustIncreaseChannels <
        std::array<ap_int<8>, 4>,  // TInputStruct
        ap_int<8>,  // TInput
        std::array<ap_int<8>, 32>,  // TOutputStruct
        ap_int<8>,  // TOutput
        DequantQuantEqual<ap_int<8>>,  // Quantizer
        7,  // IN_HEIGHT
        7,  // IN_WIDTH
        320,  // IN_CH
        1,  // IN_W_PAR
        1,  // OUT_W_PAR
        4,  // IN_CH_PAR
        32  // OUT_CH_PAR
    > BandwidthAdjustIncreaseChannels_30;
    BandwidthAdjustIncreaseChannels_30.step_init(2);
    StreamingConv <
        std::array<ap_int<8>, 32>,  // TInputWord
        ap_int<8>,  // TInput
        std::array<ap_int<8>, 128>,  // TWeightWord
        ap_int<8>,  // TWeight
        std::array<ap_int<12>, 4>,  // TBiasWord
        ap_int<12>,  // TBias
        std::array<ap_uint<8>, 4>,  // TOutputWord
        ap_uint<8>,  // TOutput
        ap_int<26>,  // TSum
        ap_int<25>,  // TPartialSum
        ReLU<ap_int<26>>,  // Activation
        DequantQuantPo2<8, ap_int<26>, ap_uint<8>>,  // Quantizer
        1280,  // OUT_CH
        320,  // IN_CH
        7,  // OUT_HEIGHT
        7,  // OUT_WIDTH
        1,  // GROUP
        1,  // FH
        1,  // FW
        1,  // STRIDE_H
        1,  // STRIDE_W
        32,  // IN_CH_PAR
        4,  // OUT_CH_PAR
        1  // W_PAR
    > StreamingConv_34;
    StreamingConv_34.step_init(12);
    BandwidthAdjustDecreaseChannels <
        std::array<ap_uint<8>, 4>,  // TInputStruct
        ap_uint<8>,  // TInput
        std::array<ap_uint<8>, 1>,  // TOutputStruct
        ap_uint<8>,  // TOutput
        DequantQuantEqual<ap_uint<8>>,  // Quantizer
        7,  // IN_HEIGHT
        7,  // IN_WIDTH
        1280,  // IN_CH
        1,  // IN_W_PAR
        1,  // OUT_W_PAR
        4,  // IN_CH_PAR
        1  // OUT_CH_PAR
    > BandwidthAdjustDecreaseChannels_24;
    BandwidthAdjustDecreaseChannels_24.step_init(2);
    StreamingGlobalAveragePool <
        std::array<ap_uint<8>, 1>,  // TInputStruct
        ap_uint<8>,  // TInput
        std::array<ap_int<8>, 1>,  // TOutputStruct
        ap_int<8>,  // TOutput
        ap_uint<14>,  // TAcc
        ap_uint<6>,  // TDiv
        DequantQuantPo2<0, ap_uint<14>, ap_int<8>>,  // Quantizer
        7,  // IN_HEIGHT
        7,  // IN_WIDTH
        1280,  // OUT_CH
        1  // OUT_CH_PAR
    > StreamingGlobalAveragePool_0;
    StreamingGlobalAveragePool_0.step_init(20);
    BandwidthAdjustIncreaseChannels <
        std::array<ap_int<8>, 1>,  // TInputStruct
        ap_int<8>,  // TInput
        std::array<ap_int<8>, 5>,  // TOutputStruct
        ap_int<8>,  // TOutput
        DequantQuantEqual<ap_int<8>>,  // Quantizer
        1,  // IN_HEIGHT
        1,  // IN_WIDTH
        1280,  // IN_CH
        1,  // IN_W_PAR
        1,  // OUT_W_PAR
        1,  // IN_CH_PAR
        5  // OUT_CH_PAR
    > BandwidthAdjustIncreaseChannels_31;
    BandwidthAdjustIncreaseChannels_31.step_init(2);
    StreamingConv <
        std::array<ap_int<8>, 5>,  // TInputWord
        ap_int<8>,  // TInput
        std::array<ap_int<8>, 10>,  // TWeightWord
        ap_int<8>,  // TWeight
        std::array<ap_int<9>, 2>,  // TBiasWord
        ap_int<9>,  // TBias
        std::array<ap_int<8>, 2>,  // TOutputWord
        ap_int<8>,  // TOutput
        ap_int<28>,  // TSum
        ap_int<27>,  // TPartialSum
        DequantQuantEqual<ap_int<28>>,  // Activation
        DequantQuantPo2<9, ap_int<28>, ap_int<8>>,  // Quantizer
        1000,  // OUT_CH
        1280,  // IN_CH
        1,  // OUT_HEIGHT
        1,  // OUT_WIDTH
        1,  // GROUP
        1,  // FH
        1,  // FW
        1,  // STRIDE_H
        1,  // STRIDE_W
        5,  // IN_CH_PAR
        2,  // OUT_CH_PAR
        1  // W_PAR
    > StreamingConv_35;
    StreamingConv_35.step_init(9);
    StreamToNHWC <
        std::array<ap_int<8>, 2>,  // TInputStruct
        ap_int<8>,  // TInput
        ap_axiu<128, 0, 0, 0>,  // TOutputStruct
        ap_uint<128>,  // TOutput
        DequantQuantEqual<ap_int<8>>,  // Quantizer
        501,  // ITER
        16,  // DATA_PER_WORD
        1,  // HEIGHT
        1,  // WIDTH
        1000,  // CH
        1,  // IN_W_PAR
        2  // IN_CH_PAR
    > StreamToNHWC_0;
    StreamToNHWC_0.step_init(1);
    InfiniteThroughputDMA <
        ap_axiu<128, 0, 0, 0>
    > InfiniteThroughputDMA_global_out(
        63
    );
    FixedThroughputDMA <
        ap_axiu<128, 0, 0, 0>
    > FixedThroughputDMA_global_in(
        9408,
        200704
    );
    hls::stream<std::array<ap_int<8>, 3>> NHWCToStream_0_out0_stream[2];
    hls::stream<std::array<ap_uint<32>, 1>> NHWCToStream_1_out0_stream[1];
    hls::stream<std::array<ap_int<8>, 3>> StreamingLineBuffer_0_out0_stream[15];
    hls::stream<std::array<ap_int<8>, 3>> StreamingLineBuffer_0_out0_stream_prepad[15];
    hls::stream<std::array<ap_int<8>, 3>> StreamingLineBuffer_0_buffer_stream[13];
    hls::stream<std::array<ap_int<8>, 3>> StreamingMemory_0_out0_stream[9];
    hls::stream<std::array<ap_uint<32>, 1>> StreamingMemory_0_out1_stream[1];
    hls::stream<std::array<ap_int<14>, 1>> StreamingMemory_1_out0_stream[1];
    hls::stream<std::array<ap_uint<32>, 1>> StreamingMemory_1_out1_stream[1];
    hls::stream<std::array<ap_uint<8>, 1>> StreamingConv_0_out0_stream[2];
    hls::stream<std::array<ap_int<8>, 1>> StreamingMemory_2_out0_stream[9];
    hls::stream<std::array<ap_uint<32>, 1>> StreamingMemory_2_out1_stream[1];
    hls::stream<std::array<ap_uint<8>, 1>> StreamingLineBuffer_1_out0_stream[12];
    hls::stream<std::array<ap_uint<8>, 1>> StreamingLineBuffer_1_out0_stream_prepad[12];
    hls::stream<std::array<ap_uint<8>, 1>> StreamingLineBuffer_1_buffer_stream[10];
    hls::stream<std::array<ap_int<14>, 1>> StreamingMemory_3_out0_stream[1];
    hls::stream<std::array<ap_uint<32>, 1>> StreamingMemory_3_out1_stream[1];
    hls::stream<std::array<ap_uint<8>, 1>> StreamingDepthwiseConv_0_out0_stream[2];
    hls::stream<std::array<ap_int<8>, 16>> StreamingMemory_4_out0_stream[1];
    hls::stream<std::array<ap_uint<32>, 1>> StreamingMemory_4_out1_stream[1];
    hls::stream<std::array<ap_uint<8>, 8>> BandwidthAdjustIncreaseChannels_0_out0_stream[2];
    hls::stream<std::array<ap_int<15>, 2>> StreamingMemory_5_out0_stream[1];
    hls::stream<std::array<ap_uint<32>, 1>> StreamingMemory_5_out1_stream[1];
    hls::stream<std::array<ap_uint<8>, 8>> StreamingLineBuffer_2_out0_stream[2];
    hls::stream<std::array<ap_int<8>, 48>> StreamingMemory_6_out0_stream[1];
    hls::stream<std::array<ap_uint<32>, 1>> StreamingMemory_6_out1_stream[1];
    hls::stream<std::array<ap_int<8>, 2>> StreamingConv_1_out0_stream[2];
    hls::stream<std::array<ap_int<14>, 3>> StreamingMemory_7_out0_stream[1];
    hls::stream<std::array<ap_uint<32>, 1>> StreamingMemory_7_out1_stream[1];
    hls::stream<std::array<ap_int<8>, 16>> BandwidthAdjustIncreaseChannels_1_out0_stream[2];
    hls::stream<std::array<ap_int<8>, 3>> StreamingMemory_8_out0_stream[9];
    hls::stream<std::array<ap_uint<32>, 1>> StreamingMemory_8_out1_stream[1];
    hls::stream<std::array<ap_int<8>, 16>> StreamingLineBuffer_3_out0_stream[2];
    hls::stream<std::array<ap_int<15>, 3>> StreamingMemory_9_out0_stream[1];
    hls::stream<std::array<ap_uint<32>, 1>> StreamingMemory_9_out1_stream[1];
    hls::stream<std::array<ap_uint<8>, 3>> StreamingConv_2_out0_stream[2];
    hls::stream<std::array<ap_int<8>, 9>> StreamingMemory_10_out0_stream[1];
    hls::stream<std::array<ap_uint<32>, 1>> StreamingMemory_10_out1_stream[1];
    hls::stream<std::array<ap_uint<8>, 3>> StreamingLineBuffer_4_out0_stream[15];
    hls::stream<std::array<ap_uint<8>, 3>> StreamingLineBuffer_4_out0_stream_prepad[15];
    hls::stream<std::array<ap_uint<8>, 3>> StreamingLineBuffer_4_buffer_stream[13];
    hls::stream<std::array<ap_int<15>, 3>> StreamingMemory_11_out0_stream[1];
    hls::stream<std::array<ap_uint<32>, 1>> StreamingMemory_11_out1_stream[1];
    hls::stream<std::array<ap_uint<8>, 3>> StreamingDepthwiseConv_1_out0_stream[2];
    hls::stream<std::array<ap_int<8>, 16>> StreamingMemory_12_out0_stream[1];
    hls::stream<std::array<ap_uint<32>, 1>> StreamingMemory_12_out1_stream[1];
    hls::stream<std::array<ap_uint<8>, 3>> BandwidthAdjustIncreaseStreams_0_out0_stream[4];
    hls::stream<std::array<ap_int<14>, 2>> StreamingMemory_13_out0_stream[1];
    hls::stream<std::array<ap_uint<32>, 1>> StreamingMemory_13_out1_stream[1];
    hls::stream<std::array<ap_uint<8>, 3>> StreamingLineBuffer_5_out0_stream[4];
    hls::stream<std::array<ap_int<8>, 2>> StreamingMemory_14_out0_stream[9];
    hls::stream<std::array<ap_uint<32>, 1>> StreamingMemory_14_out1_stream[1];
    hls::stream<std::array<ap_int<8>, 3>> StreamingConv_3_out0_stream[4];
    hls::stream<std::array<ap_int<14>, 2>> StreamingMemory_15_out0_stream[1];
    hls::stream<std::array<ap_uint<32>, 1>> StreamingMemory_15_out1_stream[1];
    hls::stream<std::array<ap_int<8>, 3>> TensorDuplicator_0_out0_stream[4];
    hls::stream<std::array<ap_int<8>, 3>> TensorDuplicator_0_out1_stream[4];
    hls::stream<std::array<ap_int<8>, 27>> StreamingMemory_16_out0_stream[1];
    hls::stream<std::array<ap_uint<32>, 1>> StreamingMemory_16_out1_stream[1];
    hls::stream<std::array<ap_int<8>, 1>> BandwidthAdjustDecreaseChannels_0_out0_stream[4];
    hls::stream<std::array<ap_int<8>, 3>> BandwidthAdjustDecreaseStreams_0_out0_stream[2];
    hls::stream<std::array<ap_int<15>, 3>> StreamingMemory_17_out0_stream[1];
    hls::stream<std::array<ap_uint<32>, 1>> StreamingMemory_17_out1_stream[1];
    hls::stream<std::array<ap_int<8>, 8>> BandwidthAdjustIncreaseChannels_2_out0_stream[4];
    hls::stream<std::array<ap_int<8>, 16>> StreamingMemory_18_out0_stream[1];
    hls::stream<std::array<ap_uint<32>, 1>> StreamingMemory_18_out1_stream[1];
    hls::stream<std::array<ap_int<8>, 8>> StreamingLineBuffer_6_out0_stream[4];
    hls::stream<std::array<ap_int<13>, 2>> StreamingMemory_19_out0_stream[1];
    hls::stream<std::array<ap_uint<32>, 1>> StreamingMemory_19_out1_stream[1];
    hls::stream<std::array<ap_uint<8>, 2>> StreamingConv_4_out0_stream[4];
    hls::stream<std::array<ap_int<8>, 2>> StreamingMemory_20_out0_stream[9];
    hls::stream<std::array<ap_uint<32>, 1>> StreamingMemory_20_out1_stream[1];
    hls::stream<std::array<ap_uint<8>, 2>> BandwidthAdjustDecreaseStreams_1_out0_stream[2];
    hls::stream<std::array<ap_int<15>, 2>> StreamingMemory_21_out0_stream[1];
    hls::stream<std::array<ap_uint<32>, 1>> StreamingMemory_21_out1_stream[1];
    hls::stream<std::array<ap_uint<8>, 2>> StreamingLineBuffer_7_out0_stream[12];
    hls::stream<std::array<ap_uint<8>, 2>> StreamingLineBuffer_7_out0_stream_prepad[12];
    hls::stream<std::array<ap_uint<8>, 2>> StreamingLineBuffer_7_buffer_stream[10];
    hls::stream<std::array<ap_int<8>, 9>> StreamingMemory_22_out0_stream[1];
    hls::stream<std::array<ap_uint<32>, 1>> StreamingMemory_22_out1_stream[1];
    hls::stream<std::array<ap_uint<8>, 2>> StreamingDepthwiseConv_2_out0_stream[2];
    hls::stream<std::array<ap_int<15>, 1>> StreamingMemory_23_out0_stream[1];
    hls::stream<std::array<ap_uint<32>, 1>> StreamingMemory_23_out1_stream[1];
    hls::stream<std::array<ap_uint<8>, 18>> BandwidthAdjustIncreaseChannels_3_out0_stream[2];
    hls::stream<std::array<ap_int<8>, 12>> StreamingMemory_24_out0_stream[1];
    hls::stream<std::array<ap_uint<32>, 1>> StreamingMemory_24_out1_stream[1];
    hls::stream<std::array<ap_uint<8>, 9>> BandwidthAdjustDecreaseChannels_1_out0_stream[2];
    hls::stream<std::array<ap_int<15>, 3>> StreamingMemory_25_out0_stream[1];
    hls::stream<std::array<ap_uint<32>, 1>> StreamingMemory_25_out1_stream[1];
    hls::stream<std::array<ap_uint<8>, 9>> StreamingLineBuffer_8_out0_stream[2];
    hls::stream<std::array<ap_int<8>, 1>> StreamingMemory_26_out0_stream[9];
    hls::stream<std::array<ap_uint<32>, 1>> StreamingMemory_26_out1_stream[1];
    hls::stream<std::array<ap_int<8>, 3>> StreamingConv_5_out0_stream[2];
    hls::stream<std::array<ap_int<14>, 1>> StreamingMemory_27_out0_stream[1];
    hls::stream<std::array<ap_uint<32>, 1>> StreamingMemory_27_out1_stream[1];
    hls::stream<std::array<ap_int<8>, 3>> StreamingAdd_0_out0_stream[2];
    hls::stream<std::array<ap_int<8>, 12>> StreamingMemory_28_out0_stream[1];
    hls::stream<std::array<ap_uint<32>, 1>> StreamingMemory_28_out1_stream[1];
    hls::stream<std::array<ap_int<8>, 1>> BandwidthAdjustDecreaseChannels_2_out0_stream[2];
    hls::stream<std::array<ap_int<15>, 4>> StreamingMemory_29_out0_stream[1];
    hls::stream<std::array<ap_uint<32>, 1>> StreamingMemory_29_out1_stream[1];
    hls::stream<std::array<ap_int<8>, 8>> BandwidthAdjustIncreaseChannels_4_out0_stream[2];
    hls::stream<std::array<ap_int<8>, 12>> StreamingMemory_30_out0_stream[1];
    hls::stream<std::array<ap_uint<32>, 1>> StreamingMemory_30_out1_stream[1];
    hls::stream<std::array<ap_int<8>, 8>> BandwidthAdjustIncreaseStreams_1_out0_stream[4];
    hls::stream<std::array<ap_int<15>, 3>> StreamingMemory_31_out0_stream[1];
    hls::stream<std::array<ap_uint<32>, 1>> StreamingMemory_31_out1_stream[1];
    hls::stream<std::array<ap_int<8>, 8>> StreamingLineBuffer_9_out0_stream[4];
    hls::stream<std::array<ap_int<8>, 1>> StreamingMemory_32_out0_stream[9];
    hls::stream<std::array<ap_uint<32>, 1>> StreamingMemory_32_out1_stream[1];
    hls::stream<std::array<ap_uint<8>, 2>> StreamingConv_6_out0_stream[4];
    hls::stream<std::array<ap_int<14>, 1>> StreamingMemory_33_out0_stream[1];
    hls::stream<std::array<ap_uint<32>, 1>> StreamingMemory_33_out1_stream[1];
    hls::stream<std::array<ap_uint<8>, 2>> BandwidthAdjustDecreaseStreams_2_out0_stream[2];
    hls::stream<std::array<ap_int<8>, 12>> StreamingMemory_34_out0_stream[1];
    hls::stream<std::array<ap_uint<32>, 1>> StreamingMemory_34_out1_stream[1];
    hls::stream<std::array<ap_uint<8>, 2>> StreamingLineBuffer_10_out0_stream[15];
    hls::stream<std::array<ap_uint<8>, 2>> StreamingLineBuffer_10_out0_stream_prepad[15];
    hls::stream<std::array<ap_uint<8>, 2>> StreamingLineBuffer_10_buffer_stream[13];
    hls::stream<std::array<ap_int<16>, 4>> StreamingMemory_35_out0_stream[1];
    hls::stream<std::array<ap_uint<32>, 1>> StreamingMemory_35_out1_stream[1];
    hls::stream<std::array<ap_uint<8>, 2>> StreamingDepthwiseConv_3_out0_stream[2];
    hls::stream<std::array<ap_int<8>, 12>> StreamingMemory_36_out0_stream[1];
    hls::stream<std::array<ap_uint<32>, 1>> StreamingMemory_36_out1_stream[1];
    hls::stream<std::array<ap_uint<8>, 1>> BandwidthAdjustDecreaseChannels_3_out0_stream[2];
    hls::stream<std::array<ap_int<14>, 3>> StreamingMemory_37_out0_stream[1];
    hls::stream<std::array<ap_uint<32>, 1>> StreamingMemory_37_out1_stream[1];
    hls::stream<std::array<ap_uint<8>, 9>> BandwidthAdjustIncreaseChannels_5_out0_stream[2];
    hls::stream<std::array<ap_int<8>, 1>> StreamingMemory_38_out0_stream[9];
    hls::stream<std::array<ap_uint<32>, 1>> StreamingMemory_38_out1_stream[1];
    hls::stream<std::array<ap_uint<8>, 9>> StreamingLineBuffer_11_out0_stream[2];
    hls::stream<std::array<ap_int<15>, 1>> StreamingMemory_39_out0_stream[1];
    hls::stream<std::array<ap_uint<32>, 1>> StreamingMemory_39_out1_stream[1];
    hls::stream<std::array<ap_int<8>, 1>> StreamingConv_7_out0_stream[2];
    hls::stream<std::array<ap_int<8>, 12>> StreamingMemory_40_out0_stream[1];
    hls::stream<std::array<ap_uint<32>, 1>> StreamingMemory_40_out1_stream[1];
    hls::stream<std::array<ap_int<8>, 1>> TensorDuplicator_1_out0_stream[2];
    hls::stream<std::array<ap_int<8>, 1>> TensorDuplicator_1_out1_stream[2];
    hls::stream<std::array<ap_int<16>, 4>> StreamingMemory_41_out0_stream[1];
    hls::stream<std::array<ap_uint<32>, 1>> StreamingMemory_41_out1_stream[1];
    hls::stream<std::array<ap_int<8>, 4>> BandwidthAdjustIncreaseChannels_6_out0_stream[2];
    hls::stream<std::array<ap_int<8>, 4>> BandwidthAdjustIncreaseChannels_7_out0_stream[2];
    hls::stream<std::array<ap_int<8>, 12>> StreamingMemory_42_out0_stream[1];
    hls::stream<std::array<ap_uint<32>, 1>> StreamingMemory_42_out1_stream[1];
    hls::stream<std::array<ap_int<8>, 4>> StreamingLineBuffer_12_out0_stream[2];
    hls::stream<std::array<ap_int<16>, 3>> StreamingMemory_43_out0_stream[1];
    hls::stream<std::array<ap_uint<32>, 1>> StreamingMemory_43_out1_stream[1];
    hls::stream<std::array<ap_uint<8>, 3>> StreamingConv_8_out0_stream[2];
    hls::stream<std::array<ap_int<8>, 1>> StreamingMemory_44_out0_stream[9];
    hls::stream<std::array<ap_uint<32>, 1>> StreamingMemory_44_out1_stream[1];
    hls::stream<std::array<ap_uint<8>, 1>> BandwidthAdjustDecreaseChannels_4_out0_stream[2];
    hls::stream<std::array<ap_int<14>, 1>> StreamingMemory_45_out0_stream[1];
    hls::stream<std::array<ap_uint<32>, 1>> StreamingMemory_45_out1_stream[1];
    hls::stream<std::array<ap_uint<8>, 1>> StreamingLineBuffer_13_out0_stream[12];
    hls::stream<std::array<ap_uint<8>, 1>> StreamingLineBuffer_13_out0_stream_prepad[12];
    hls::stream<std::array<ap_uint<8>, 1>> StreamingLineBuffer_13_buffer_stream[10];
    hls::stream<std::array<ap_int<8>, 12>> StreamingMemory_46_out0_stream[1];
    hls::stream<std::array<ap_uint<32>, 1>> StreamingMemory_46_out1_stream[1];
    hls::stream<std::array<ap_uint<8>, 1>> StreamingDepthwiseConv_4_out0_stream[2];
    hls::stream<std::array<ap_int<16>, 4>> StreamingMemory_47_out0_stream[1];
    hls::stream<std::array<ap_uint<32>, 1>> StreamingMemory_47_out1_stream[1];
    hls::stream<std::array<ap_uint<8>, 3>> BandwidthAdjustIncreaseChannels_8_out0_stream[2];
    hls::stream<std::array<ap_int<8>, 12>> StreamingMemory_48_out0_stream[1];
    hls::stream<std::array<ap_uint<32>, 1>> StreamingMemory_48_out1_stream[1];
    hls::stream<std::array<ap_uint<8>, 3>> StreamingLineBuffer_14_out0_stream[2];
    hls::stream<std::array<ap_int<16>, 3>> StreamingMemory_49_out0_stream[1];
    hls::stream<std::array<ap_uint<32>, 1>> StreamingMemory_49_out1_stream[1];
    hls::stream<std::array<ap_int<8>, 4>> StreamingConv_9_out0_stream[2];
    hls::stream<std::array<ap_int<8>, 1>> StreamingMemory_50_out0_stream[9];
    hls::stream<std::array<ap_uint<32>, 1>> StreamingMemory_50_out1_stream[1];
    hls::stream<std::array<ap_int<8>, 4>> StreamingAdd_1_out0_stream[2];
    hls::stream<std::array<ap_int<14>, 1>> StreamingMemory_51_out0_stream[1];
    hls::stream<std::array<ap_uint<32>, 1>> StreamingMemory_51_out1_stream[1];
    hls::stream<std::array<ap_int<8>, 1>> BandwidthAdjustDecreaseChannels_5_out0_stream[2];
    hls::stream<std::array<ap_int<8>, 12>> StreamingMemory_52_out0_stream[1];
    hls::stream<std::array<ap_uint<32>, 1>> StreamingMemory_52_out1_stream[1];
    hls::stream<std::array<ap_int<8>, 1>> TensorDuplicator_2_out0_stream[2];
    hls::stream<std::array<ap_int<8>, 1>> TensorDuplicator_2_out1_stream[2];
    hls::stream<std::array<ap_int<15>, 4>> StreamingMemory_53_out0_stream[1];
    hls::stream<std::array<ap_uint<32>, 1>> StreamingMemory_53_out1_stream[1];
    hls::stream<std::array<ap_int<8>, 4>> BandwidthAdjustIncreaseChannels_9_out0_stream[2];
    hls::stream<std::array<ap_int<8>, 4>> BandwidthAdjustIncreaseChannels_10_out0_stream[2];
    hls::stream<std::array<ap_int<8>, 12>> StreamingMemory_54_out0_stream[1];
    hls::stream<std::array<ap_uint<32>, 1>> StreamingMemory_54_out1_stream[1];
    hls::stream<std::array<ap_int<8>, 4>> StreamingLineBuffer_15_out0_stream[2];
    hls::stream<std::array<ap_int<14>, 3>> StreamingMemory_55_out0_stream[1];
    hls::stream<std::array<ap_uint<32>, 1>> StreamingMemory_55_out1_stream[1];
    hls::stream<std::array<ap_uint<8>, 3>> StreamingConv_10_out0_stream[2];
    hls::stream<std::array<ap_int<8>, 1>> StreamingMemory_56_out0_stream[9];
    hls::stream<std::array<ap_uint<32>, 1>> StreamingMemory_56_out1_stream[1];
    hls::stream<std::array<ap_uint<8>, 1>> BandwidthAdjustDecreaseChannels_6_out0_stream[2];
    hls::stream<std::array<ap_int<14>, 1>> StreamingMemory_57_out0_stream[1];
    hls::stream<std::array<ap_uint<32>, 1>> StreamingMemory_57_out1_stream[1];
    hls::stream<std::array<ap_uint<8>, 1>> StreamingLineBuffer_16_out0_stream[12];
    hls::stream<std::array<ap_uint<8>, 1>> StreamingLineBuffer_16_out0_stream_prepad[12];
    hls::stream<std::array<ap_uint<8>, 1>> StreamingLineBuffer_16_buffer_stream[10];
    hls::stream<std::array<ap_int<8>, 12>> StreamingMemory_58_out0_stream[1];
    hls::stream<std::array<ap_uint<32>, 1>> StreamingMemory_58_out1_stream[1];
    hls::stream<std::array<ap_uint<8>, 1>> StreamingDepthwiseConv_5_out0_stream[2];
    hls::stream<std::array<ap_int<15>, 4>> StreamingMemory_59_out0_stream[1];
    hls::stream<std::array<ap_uint<32>, 1>> StreamingMemory_59_out1_stream[1];
    hls::stream<std::array<ap_uint<8>, 3>> BandwidthAdjustIncreaseChannels_11_out0_stream[2];
    hls::stream<std::array<ap_int<8>, 12>> StreamingMemory_60_out0_stream[1];
    hls::stream<std::array<ap_uint<32>, 1>> StreamingMemory_60_out1_stream[1];
    hls::stream<std::array<ap_uint<8>, 3>> StreamingLineBuffer_17_out0_stream[2];
    hls::stream<std::array<ap_int<14>, 3>> StreamingMemory_61_out0_stream[1];
    hls::stream<std::array<ap_uint<32>, 1>> StreamingMemory_61_out1_stream[1];
    hls::stream<std::array<ap_int<8>, 4>> StreamingConv_11_out0_stream[2];
    hls::stream<std::array<ap_int<8>, 1>> StreamingMemory_62_out0_stream[9];
    hls::stream<std::array<ap_uint<32>, 1>> StreamingMemory_62_out1_stream[1];
    hls::stream<std::array<ap_int<8>, 4>> StreamingAdd_2_out0_stream[2];
    hls::stream<std::array<ap_int<15>, 1>> StreamingMemory_63_out0_stream[1];
    hls::stream<std::array<ap_uint<32>, 1>> StreamingMemory_63_out1_stream[1];
    hls::stream<std::array<ap_int<8>, 4>> StreamingLineBuffer_18_out0_stream[2];
    hls::stream<std::array<ap_int<8>, 18>> StreamingMemory_64_out0_stream[1];
    hls::stream<std::array<ap_uint<32>, 1>> StreamingMemory_64_out1_stream[1];
    hls::stream<std::array<ap_uint<8>, 3>> StreamingConv_12_out0_stream[2];
    hls::stream<std::array<ap_int<16>, 3>> StreamingMemory_65_out0_stream[1];
    hls::stream<std::array<ap_uint<32>, 1>> StreamingMemory_65_out1_stream[1];
    hls::stream<std::array<ap_uint<8>, 1>> BandwidthAdjustDecreaseChannels_7_out0_stream[2];
    hls::stream<std::array<ap_int<8>, 64>> StreamingMemory_66_out0_stream[1];
    hls::stream<std::array<ap_uint<32>, 1>> StreamingMemory_66_out1_stream[1];
    hls::stream<std::array<ap_uint<8>, 1>> BandwidthAdjustDecreaseStreams_3_out0_stream[1];
    hls::stream<std::array<ap_int<14>, 2>> StreamingMemory_67_out0_stream[1];
    hls::stream<std::array<ap_uint<32>, 1>> StreamingMemory_67_out1_stream[1];
    hls::stream<std::array<ap_uint<8>, 1>> StreamingLineBuffer_19_out0_stream[9];
    hls::stream<std::array<ap_uint<8>, 1>> StreamingLineBuffer_19_out0_stream_prepad[9];
    hls::stream<std::array<ap_uint<8>, 1>> StreamingLineBuffer_19_buffer_stream[8];
    hls::stream<std::array<ap_int<8>, 1>> StreamingMemory_68_out0_stream[9];
    hls::stream<std::array<ap_uint<32>, 1>> StreamingMemory_68_out1_stream[1];
    hls::stream<std::array<ap_uint<8>, 1>> StreamingDepthwiseConv_6_out0_stream[1];
    hls::stream<std::array<ap_int<15>, 1>> StreamingMemory_69_out0_stream[1];
    hls::stream<std::array<ap_uint<32>, 1>> StreamingMemory_69_out1_stream[1];
    hls::stream<std::array<ap_uint<8>, 3>> BandwidthAdjustIncreaseChannels_12_out0_stream[1];
    hls::stream<std::array<ap_int<8>, 27>> StreamingMemory_70_out0_stream[1];
    hls::stream<std::array<ap_uint<32>, 1>> StreamingMemory_70_out1_stream[1];
    hls::stream<std::array<ap_int<8>, 4>> StreamingConv_13_out0_stream[1];
    hls::stream<std::array<ap_int<15>, 3>> StreamingMemory_71_out0_stream[1];
    hls::stream<std::array<ap_uint<32>, 1>> StreamingMemory_71_out1_stream[1];
    hls::stream<std::array<ap_int<8>, 4>> TensorDuplicator_3_out0_stream[1];
    hls::stream<std::array<ap_int<8>, 4>> TensorDuplicator_3_out1_stream[1];
    hls::stream<std::array<ap_int<8>, 64>> StreamingMemory_72_out0_stream[1];
    hls::stream<std::array<ap_uint<32>, 1>> StreamingMemory_72_out1_stream[1];
    hls::stream<std::array<ap_int<8>, 4>> BandwidthAdjustIncreaseStreams_2_out0_stream[2];
    hls::stream<std::array<ap_int<8>, 4>> BandwidthAdjustIncreaseStreams_3_out0_stream[2];
    hls::stream<std::array<ap_int<15>, 4>> StreamingMemory_73_out0_stream[1];
    hls::stream<std::array<ap_uint<32>, 1>> StreamingMemory_73_out1_stream[1];
    hls::stream<std::array<ap_int<8>, 4>> StreamingLineBuffer_20_out0_stream[2];
    hls::stream<std::array<ap_int<8>, 1>> StreamingMemory_74_out0_stream[9];
    hls::stream<std::array<ap_uint<32>, 1>> StreamingMemory_74_out1_stream[1];
    hls::stream<std::array<ap_uint<8>, 3>> StreamingConv_14_out0_stream[2];
    hls::stream<std::array<ap_int<15>, 1>> StreamingMemory_75_out0_stream[1];
    hls::stream<std::array<ap_uint<32>, 1>> StreamingMemory_75_out1_stream[1];
    hls::stream<std::array<ap_uint<8>, 1>> BandwidthAdjustDecreaseChannels_8_out0_stream[2];
    hls::stream<std::array<ap_int<8>, 27>> StreamingMemory_76_out0_stream[1];
    hls::stream<std::array<ap_uint<32>, 1>> StreamingMemory_76_out1_stream[1];
    hls::stream<std::array<ap_uint<8>, 1>> StreamingLineBuffer_21_out0_stream[12];
    hls::stream<std::array<ap_uint<8>, 1>> StreamingLineBuffer_21_out0_stream_prepad[12];
    hls::stream<std::array<ap_uint<8>, 1>> StreamingLineBuffer_21_buffer_stream[10];
    hls::stream<std::array<ap_int<15>, 3>> StreamingMemory_77_out0_stream[1];
    hls::stream<std::array<ap_uint<32>, 1>> StreamingMemory_77_out1_stream[1];
    hls::stream<std::array<ap_uint<8>, 1>> StreamingDepthwiseConv_7_out0_stream[2];
    hls::stream<std::array<ap_int<8>, 64>> StreamingMemory_78_out0_stream[1];
    hls::stream<std::array<ap_uint<32>, 1>> StreamingMemory_78_out1_stream[1];
    hls::stream<std::array<ap_uint<8>, 3>> BandwidthAdjustIncreaseChannels_13_out0_stream[2];
    hls::stream<std::array<ap_int<14>, 4>> StreamingMemory_79_out0_stream[1];
    hls::stream<std::array<ap_uint<32>, 1>> StreamingMemory_79_out1_stream[1];
    hls::stream<std::array<ap_uint<8>, 3>> StreamingLineBuffer_22_out0_stream[2];
    hls::stream<std::array<ap_int<8>, 1>> StreamingMemory_80_out0_stream[9];
    hls::stream<std::array<ap_uint<32>, 1>> StreamingMemory_80_out1_stream[1];
    hls::stream<std::array<ap_int<8>, 4>> StreamingConv_15_out0_stream[2];
    hls::stream<std::array<ap_int<15>, 1>> StreamingMemory_81_out0_stream[1];
    hls::stream<std::array<ap_uint<32>, 1>> StreamingMemory_81_out1_stream[1];
    hls::stream<std::array<ap_int<8>, 4>> StreamingAdd_3_out0_stream[2];
    hls::stream<std::array<ap_int<8>, 24>> StreamingMemory_82_out0_stream[1];
    hls::stream<std::array<ap_uint<32>, 1>> StreamingMemory_82_out1_stream[1];
    hls::stream<std::array<ap_int<8>, 4>> BandwidthAdjustDecreaseStreams_4_out0_stream[1];
    hls::stream<std::array<ap_int<15>, 4>> StreamingMemory_83_out0_stream[1];
    hls::stream<std::array<ap_uint<32>, 1>> StreamingMemory_83_out1_stream[1];
    hls::stream<std::array<ap_int<8>, 4>> TensorDuplicator_4_out0_stream[1];
    hls::stream<std::array<ap_int<8>, 4>> TensorDuplicator_4_out1_stream[1];
    hls::stream<std::array<ap_int<8>, 40>> StreamingMemory_84_out0_stream[1];
    hls::stream<std::array<ap_uint<32>, 1>> StreamingMemory_84_out1_stream[1];
    hls::stream<std::array<ap_int<8>, 4>> BandwidthAdjustIncreaseStreams_4_out0_stream[2];
    hls::stream<std::array<ap_int<8>, 4>> BandwidthAdjustIncreaseStreams_5_out0_stream[2];
    hls::stream<std::array<ap_int<15>, 4>> StreamingMemory_85_out0_stream[1];
    hls::stream<std::array<ap_uint<32>, 1>> StreamingMemory_85_out1_stream[1];
    hls::stream<std::array<ap_int<8>, 4>> StreamingLineBuffer_23_out0_stream[2];
    hls::stream<std::array<ap_int<8>, 1>> StreamingMemory_86_out0_stream[9];
    hls::stream<std::array<ap_uint<32>, 1>> StreamingMemory_86_out1_stream[1];
    hls::stream<std::array<ap_uint<8>, 3>> StreamingConv_16_out0_stream[2];
    hls::stream<std::array<ap_int<15>, 1>> StreamingMemory_87_out0_stream[1];
    hls::stream<std::array<ap_uint<32>, 1>> StreamingMemory_87_out1_stream[1];
    hls::stream<std::array<ap_uint<8>, 1>> BandwidthAdjustDecreaseChannels_9_out0_stream[2];
    hls::stream<std::array<ap_int<8>, 40>> StreamingMemory_88_out0_stream[1];
    hls::stream<std::array<ap_uint<32>, 1>> StreamingMemory_88_out1_stream[1];
    hls::stream<std::array<ap_uint<8>, 1>> StreamingLineBuffer_24_out0_stream[12];
    hls::stream<std::array<ap_uint<8>, 1>> StreamingLineBuffer_24_out0_stream_prepad[12];
    hls::stream<std::array<ap_uint<8>, 1>> StreamingLineBuffer_24_buffer_stream[10];
    hls::stream<std::array<ap_int<16>, 2>> StreamingMemory_89_out0_stream[1];
    hls::stream<std::array<ap_uint<32>, 1>> StreamingMemory_89_out1_stream[1];
    hls::stream<std::array<ap_uint<8>, 1>> StreamingDepthwiseConv_8_out0_stream[2];
    hls::stream<std::array<ap_int<8>, 40>> StreamingMemory_90_out0_stream[1];
    hls::stream<std::array<ap_uint<32>, 1>> StreamingMemory_90_out1_stream[1];
    hls::stream<std::array<ap_uint<8>, 3>> BandwidthAdjustIncreaseChannels_14_out0_stream[2];
    hls::stream<std::array<ap_int<13>, 2>> StreamingMemory_91_out0_stream[1];
    hls::stream<std::array<ap_uint<32>, 1>> StreamingMemory_91_out1_stream[1];
    hls::stream<std::array<ap_uint<8>, 3>> StreamingLineBuffer_25_out0_stream[2];
    hls::stream<std::array<ap_int<8>, 1>> StreamingMemory_92_out0_stream[9];
    hls::stream<std::array<ap_uint<32>, 1>> StreamingMemory_92_out1_stream[1];
    hls::stream<std::array<ap_int<8>, 4>> StreamingConv_17_out0_stream[2];
    hls::stream<std::array<ap_int<14>, 1>> StreamingMemory_93_out0_stream[1];
    hls::stream<std::array<ap_uint<32>, 1>> StreamingMemory_93_out1_stream[1];
    hls::stream<std::array<ap_int<8>, 4>> StreamingAdd_4_out0_stream[2];
    hls::stream<std::array<ap_int<8>, 40>> StreamingMemory_94_out0_stream[1];
    hls::stream<std::array<ap_uint<32>, 1>> StreamingMemory_94_out1_stream[1];
    hls::stream<std::array<ap_int<8>, 4>> BandwidthAdjustDecreaseStreams_5_out0_stream[1];
    hls::stream<std::array<ap_int<15>, 2>> StreamingMemory_95_out0_stream[1];
    hls::stream<std::array<ap_uint<32>, 1>> StreamingMemory_95_out1_stream[1];
    hls::stream<std::array<ap_int<8>, 4>> TensorDuplicator_5_out0_stream[1];
    hls::stream<std::array<ap_int<8>, 4>> TensorDuplicator_5_out1_stream[1];
    hls::stream<std::array<ap_int<8>, 40>> StreamingMemory_96_out0_stream[1];
    hls::stream<std::array<ap_uint<32>, 1>> StreamingMemory_96_out1_stream[1];
    hls::stream<std::array<ap_int<8>, 4>> BandwidthAdjustIncreaseStreams_6_out0_stream[2];
    hls::stream<std::array<ap_int<8>, 4>> BandwidthAdjustIncreaseStreams_7_out0_stream[2];
    hls::stream<std::array<ap_int<14>, 2>> StreamingMemory_97_out0_stream[1];
    hls::stream<std::array<ap_uint<32>, 1>> StreamingMemory_97_out1_stream[1];
    hls::stream<std::array<ap_int<8>, 4>> StreamingLineBuffer_26_out0_stream[2];
    hls::stream<std::array<ap_int<8>, 1>> StreamingMemory_98_out0_stream[9];
    hls::stream<std::array<ap_uint<32>, 1>> StreamingMemory_98_out1_stream[1];
    hls::stream<std::array<ap_uint<8>, 3>> StreamingConv_18_out0_stream[2];
    hls::stream<std::array<ap_int<15>, 1>> StreamingMemory_99_out0_stream[1];
    hls::stream<std::array<ap_uint<32>, 1>> StreamingMemory_99_out1_stream[1];
    hls::stream<std::array<ap_uint<8>, 1>> BandwidthAdjustDecreaseChannels_10_out0_stream[2];
    hls::stream<std::array<ap_int<8>, 80>> StreamingMemory_100_out0_stream[1];
    hls::stream<std::array<ap_uint<32>, 1>> StreamingMemory_100_out1_stream[1];
    hls::stream<std::array<ap_uint<8>, 1>> StreamingLineBuffer_27_out0_stream[12];
    hls::stream<std::array<ap_uint<8>, 1>> StreamingLineBuffer_27_out0_stream_prepad[12];
    hls::stream<std::array<ap_uint<8>, 1>> StreamingLineBuffer_27_buffer_stream[10];
    hls::stream<std::array<ap_int<15>, 4>> StreamingMemory_101_out0_stream[1];
    hls::stream<std::array<ap_uint<32>, 1>> StreamingMemory_101_out1_stream[1];
    hls::stream<std::array<ap_uint<8>, 1>> StreamingDepthwiseConv_9_out0_stream[2];
    hls::stream<std::array<ap_int<8>, 128>> StreamingMemory_102_out0_stream[1];
    hls::stream<std::array<ap_uint<32>, 1>> StreamingMemory_102_out1_stream[1];
    hls::stream<std::array<ap_uint<8>, 3>> BandwidthAdjustIncreaseChannels_15_out0_stream[2];
    hls::stream<std::array<ap_int<12>, 4>> StreamingMemory_103_out0_stream[1];
    hls::stream<std::array<ap_uint<32>, 1>> StreamingMemory_103_out1_stream[1];
    hls::stream<std::array<ap_uint<8>, 3>> StreamingLineBuffer_28_out0_stream[2];
    hls::stream<std::array<ap_int<8>, 10>> StreamingMemory_104_out0_stream[1];
    hls::stream<std::array<ap_uint<32>, 1>> StreamingMemory_104_out1_stream[1];
    hls::stream<std::array<ap_int<8>, 4>> StreamingConv_19_out0_stream[2];
    hls::stream<std::array<ap_int<9>, 2>> StreamingMemory_105_out0_stream[1];
    hls::stream<std::array<ap_int<8>, 4>> StreamingAdd_5_out0_stream[2];
    hls::stream<std::array<ap_int<8>, 4>> StreamingLineBuffer_29_out0_stream[2];
    hls::stream<std::array<ap_uint<8>, 3>> StreamingConv_20_out0_stream[2];
    hls::stream<std::array<ap_uint<8>, 1>> BandwidthAdjustDecreaseChannels_11_out0_stream[2];
    hls::stream<std::array<ap_uint<8>, 1>> StreamingLineBuffer_30_out0_stream[12];
    hls::stream<std::array<ap_uint<8>, 1>> StreamingLineBuffer_30_out0_stream_prepad[12];
    hls::stream<std::array<ap_uint<8>, 1>> StreamingLineBuffer_30_buffer_stream[10];
    hls::stream<std::array<ap_uint<8>, 1>> StreamingDepthwiseConv_10_out0_stream[2];
    hls::stream<std::array<ap_uint<8>, 6>> BandwidthAdjustIncreaseChannels_16_out0_stream[2];
    hls::stream<std::array<ap_uint<8>, 6>> StreamingLineBuffer_31_out0_stream[2];
    hls::stream<std::array<ap_int<8>, 3>> StreamingConv_21_out0_stream[2];
    hls::stream<std::array<ap_int<8>, 3>> TensorDuplicator_6_out0_stream[2];
    hls::stream<std::array<ap_int<8>, 3>> TensorDuplicator_6_out1_stream[2];
    hls::stream<std::array<ap_int<8>, 1>> BandwidthAdjustDecreaseChannels_12_out0_stream[2];
    hls::stream<std::array<ap_int<8>, 32>> BandwidthAdjustIncreaseChannels_17_out0_stream[2];
    hls::stream<std::array<ap_int<8>, 32>> BandwidthAdjustDecreaseStreams_6_out0_stream[1];
    hls::stream<std::array<ap_uint<8>, 2>> StreamingConv_22_out0_stream[1];
    hls::stream<std::array<ap_uint<8>, 1>> BandwidthAdjustDecreaseChannels_13_out0_stream[1];
    hls::stream<std::array<ap_uint<8>, 1>> StreamingLineBuffer_32_out0_stream[9];
    hls::stream<std::array<ap_uint<8>, 1>> StreamingLineBuffer_32_out0_stream_prepad[9];
    hls::stream<std::array<ap_uint<8>, 1>> StreamingLineBuffer_32_buffer_stream[8];
    hls::stream<std::array<ap_uint<8>, 1>> StreamingDepthwiseConv_11_out0_stream[1];
    hls::stream<std::array<ap_uint<8>, 9>> BandwidthAdjustIncreaseChannels_18_out0_stream[1];
    hls::stream<std::array<ap_uint<8>, 9>> BandwidthAdjustIncreaseStreams_8_out0_stream[2];
    hls::stream<std::array<ap_uint<8>, 9>> StreamingLineBuffer_33_out0_stream[2];
    hls::stream<std::array<ap_int<8>, 3>> StreamingConv_23_out0_stream[2];
    hls::stream<std::array<ap_int<8>, 3>> StreamingAdd_6_out0_stream[2];
    hls::stream<std::array<ap_int<8>, 3>> TensorDuplicator_7_out0_stream[2];
    hls::stream<std::array<ap_int<8>, 3>> TensorDuplicator_7_out1_stream[2];
    hls::stream<std::array<ap_int<8>, 1>> BandwidthAdjustDecreaseChannels_14_out0_stream[2];
    hls::stream<std::array<ap_int<8>, 16>> BandwidthAdjustIncreaseChannels_19_out0_stream[2];
    hls::stream<std::array<ap_int<8>, 16>> BandwidthAdjustDecreaseStreams_7_out0_stream[1];
    hls::stream<std::array<ap_uint<8>, 4>> StreamingConv_24_out0_stream[1];
    hls::stream<std::array<ap_uint<8>, 1>> BandwidthAdjustDecreaseChannels_15_out0_stream[1];
    hls::stream<std::array<ap_uint<8>, 1>> StreamingLineBuffer_34_out0_stream[9];
    hls::stream<std::array<ap_uint<8>, 1>> StreamingLineBuffer_34_out0_stream_prepad[9];
    hls::stream<std::array<ap_uint<8>, 1>> StreamingLineBuffer_34_buffer_stream[8];
    hls::stream<std::array<ap_uint<8>, 1>> StreamingDepthwiseConv_12_out0_stream[1];
    hls::stream<std::array<ap_uint<8>, 9>> BandwidthAdjustIncreaseChannels_20_out0_stream[1];
    hls::stream<std::array<ap_uint<8>, 9>> BandwidthAdjustIncreaseStreams_9_out0_stream[2];
    hls::stream<std::array<ap_uint<8>, 9>> StreamingLineBuffer_35_out0_stream[2];
    hls::stream<std::array<ap_int<8>, 3>> StreamingConv_25_out0_stream[2];
    hls::stream<std::array<ap_int<8>, 3>> StreamingAdd_7_out0_stream[2];
    hls::stream<std::array<ap_int<8>, 1>> BandwidthAdjustDecreaseChannels_16_out0_stream[2];
    hls::stream<std::array<ap_int<8>, 16>> BandwidthAdjustIncreaseChannels_21_out0_stream[2];
    hls::stream<std::array<ap_int<8>, 16>> BandwidthAdjustDecreaseStreams_8_out0_stream[1];
    hls::stream<std::array<ap_uint<8>, 4>> StreamingConv_26_out0_stream[1];
    hls::stream<std::array<ap_uint<8>, 1>> BandwidthAdjustDecreaseChannels_17_out0_stream[1];
    hls::stream<std::array<ap_uint<8>, 1>> StreamingLineBuffer_36_out0_stream[9];
    hls::stream<std::array<ap_uint<8>, 1>> StreamingLineBuffer_36_out0_stream_prepad[9];
    hls::stream<std::array<ap_uint<8>, 1>> StreamingLineBuffer_36_buffer_stream[8];
    hls::stream<std::array<ap_uint<8>, 1>> StreamingDepthwiseConv_13_out0_stream[1];
    hls::stream<std::array<ap_uint<8>, 6>> BandwidthAdjustIncreaseChannels_22_out0_stream[1];
    hls::stream<std::array<ap_int<8>, 4>> StreamingConv_27_out0_stream[1];
    hls::stream<std::array<ap_int<8>, 4>> TensorDuplicator_8_out0_stream[1];
    hls::stream<std::array<ap_int<8>, 4>> TensorDuplicator_8_out1_stream[1];
    hls::stream<std::array<ap_int<8>, 2>> BandwidthAdjustDecreaseChannels_18_out0_stream[1];
    hls::stream<std::array<ap_int<8>, 2>> BandwidthAdjustDecreaseChannels_19_out0_stream[1];
    hls::stream<std::array<ap_int<8>, 10>> BandwidthAdjustIncreaseChannels_23_out0_stream[1];
    hls::stream<std::array<ap_uint<8>, 4>> StreamingConv_28_out0_stream[1];
    hls::stream<std::array<ap_uint<8>, 1>> BandwidthAdjustDecreaseChannels_20_out0_stream[1];
    hls::stream<std::array<ap_uint<8>, 1>> StreamingLineBuffer_37_out0_stream[9];
    hls::stream<std::array<ap_uint<8>, 1>> StreamingLineBuffer_37_out0_stream_prepad[9];
    hls::stream<std::array<ap_uint<8>, 1>> StreamingLineBuffer_37_buffer_stream[8];
    hls::stream<std::array<ap_uint<8>, 1>> StreamingDepthwiseConv_14_out0_stream[1];
    hls::stream<std::array<ap_uint<8>, 20>> BandwidthAdjustIncreaseChannels_24_out0_stream[1];
    hls::stream<std::array<ap_int<8>, 2>> StreamingConv_29_out0_stream[1];
    hls::stream<std::array<ap_int<8>, 2>> StreamingAdd_8_out0_stream[1];
    hls::stream<std::array<ap_int<8>, 4>> BandwidthAdjustIncreaseChannels_25_out0_stream[1];
    hls::stream<std::array<ap_int<8>, 4>> TensorDuplicator_9_out0_stream[1];
    hls::stream<std::array<ap_int<8>, 4>> TensorDuplicator_9_out1_stream[1];
    hls::stream<std::array<ap_int<8>, 20>> BandwidthAdjustIncreaseChannels_26_out0_stream[1];
    hls::stream<std::array<ap_int<8>, 2>> BandwidthAdjustDecreaseChannels_21_out0_stream[1];
    hls::stream<std::array<ap_uint<8>, 2>> StreamingConv_30_out0_stream[1];
    hls::stream<std::array<ap_uint<8>, 1>> BandwidthAdjustDecreaseChannels_22_out0_stream[1];
    hls::stream<std::array<ap_uint<8>, 1>> StreamingLineBuffer_38_out0_stream[9];
    hls::stream<std::array<ap_uint<8>, 1>> StreamingLineBuffer_38_out0_stream_prepad[9];
    hls::stream<std::array<ap_uint<8>, 1>> StreamingLineBuffer_38_buffer_stream[8];
    hls::stream<std::array<ap_uint<8>, 1>> StreamingDepthwiseConv_15_out0_stream[1];
    hls::stream<std::array<ap_uint<8>, 20>> BandwidthAdjustIncreaseChannels_27_out0_stream[1];
    hls::stream<std::array<ap_int<8>, 2>> StreamingConv_31_out0_stream[1];
    hls::stream<std::array<ap_int<8>, 2>> StreamingAdd_9_out0_stream[1];
    hls::stream<std::array<ap_int<8>, 20>> BandwidthAdjustIncreaseChannels_28_out0_stream[1];
    hls::stream<std::array<ap_uint<8>, 2>> StreamingConv_32_out0_stream[1];
    hls::stream<std::array<ap_uint<8>, 1>> BandwidthAdjustDecreaseChannels_23_out0_stream[1];
    hls::stream<std::array<ap_uint<8>, 1>> StreamingLineBuffer_39_out0_stream[9];
    hls::stream<std::array<ap_uint<8>, 1>> StreamingLineBuffer_39_out0_stream_prepad[9];
    hls::stream<std::array<ap_uint<8>, 1>> StreamingLineBuffer_39_buffer_stream[8];
    hls::stream<std::array<ap_uint<8>, 1>> StreamingDepthwiseConv_16_out0_stream[1];
    hls::stream<std::array<ap_uint<8>, 20>> BandwidthAdjustIncreaseChannels_29_out0_stream[1];
    hls::stream<std::array<ap_int<8>, 4>> StreamingConv_33_out0_stream[1];
    hls::stream<std::array<ap_int<8>, 32>> BandwidthAdjustIncreaseChannels_30_out0_stream[1];
    hls::stream<std::array<ap_uint<8>, 4>> StreamingConv_34_out0_stream[1];
    hls::stream<std::array<ap_uint<8>, 1>> BandwidthAdjustDecreaseChannels_24_out0_stream[1];
    hls::stream<std::array<ap_int<8>, 1>> StreamingGlobalAveragePool_0_out0_stream[1];
    hls::stream<std::array<ap_int<8>, 5>> BandwidthAdjustIncreaseChannels_31_out0_stream[1];
    hls::stream<std::array<ap_int<8>, 2>> StreamingConv_35_out0_stream[1];
    hls::stream<ap_axiu<128, 0, 0, 0>> global_out;
    hls::stream<ap_axiu<128, 0, 0, 0>> global_in;
    hls::stream<ap_axiu<128, 0, 0, 0>> global_in_1;
    size_t stream_max_size[1267] = {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1};
    size_t clock_cycle = 0;
    size_t actual_II = 0;
    std::unordered_map<StateSig, std::vector<StateRef>> visited_states;
    CSDFGState current_state;
    std::vector<ActorStatus> actor_statuses;
    actor_statuses.reserve(2);
    std::vector<size_t> channel_quantities;
    channel_quantities.reserve(1270);
    while (true) {
        ActorStatus actor_status;
        actor_statuses.clear();
        channel_quantities.clear();
        actor_status = InfiniteThroughputDMA_global_out.step(global_out);
        actor_statuses.push_back(actor_status);
        actor_status = StreamToNHWC_0.step(StreamingConv_35_out0_stream, global_out);
        actor_statuses.push_back(actor_status);
        actor_status = StreamingConv_35.step(BandwidthAdjustIncreaseChannels_31_out0_stream, StreamingMemory_104_out0_stream, StreamingMemory_105_out0_stream, StreamingConv_35_out0_stream);
        actor_statuses.push_back(actor_status);
        actor_status = BandwidthAdjustIncreaseChannels_31.step(StreamingGlobalAveragePool_0_out0_stream, BandwidthAdjustIncreaseChannels_31_out0_stream);
        actor_statuses.push_back(actor_status);
        actor_status = StreamingGlobalAveragePool_0.step(BandwidthAdjustDecreaseChannels_24_out0_stream, StreamingGlobalAveragePool_0_out0_stream);
        actor_statuses.push_back(actor_status);
        actor_status = BandwidthAdjustDecreaseChannels_24.step(StreamingConv_34_out0_stream, BandwidthAdjustDecreaseChannels_24_out0_stream);
        actor_statuses.push_back(actor_status);
        actor_status = StreamingConv_34.step(BandwidthAdjustIncreaseChannels_30_out0_stream, StreamingMemory_102_out0_stream, StreamingMemory_103_out0_stream, StreamingConv_34_out0_stream);
        actor_statuses.push_back(actor_status);
        actor_status = BandwidthAdjustIncreaseChannels_30.step(StreamingConv_33_out0_stream, BandwidthAdjustIncreaseChannels_30_out0_stream);
        actor_statuses.push_back(actor_status);
        actor_status = StreamingConv_33.step(BandwidthAdjustIncreaseChannels_29_out0_stream, StreamingMemory_100_out0_stream, StreamingMemory_101_out0_stream, StreamingConv_33_out0_stream);
        actor_statuses.push_back(actor_status);
        actor_status = BandwidthAdjustIncreaseChannels_29.step(StreamingDepthwiseConv_16_out0_stream, BandwidthAdjustIncreaseChannels_29_out0_stream);
        actor_statuses.push_back(actor_status);
        actor_status = StreamingDepthwiseConv_16.step(StreamingLineBuffer_39_out0_stream, StreamingMemory_98_out0_stream, StreamingMemory_99_out0_stream, StreamingDepthwiseConv_16_out0_stream);
        actor_statuses.push_back(actor_status);
        actor_status = StreamingLineBuffer_39_pad.step(StreamingLineBuffer_39_out0_stream_prepad, StreamingLineBuffer_39_out0_stream);
        actor_statuses.push_back(actor_status);
        actor_status = StreamingLineBuffer_39_pixel_8.step(StreamingLineBuffer_39_buffer_stream[7], StreamingLineBuffer_39_out0_stream_prepad[0]);
        actor_statuses.push_back(actor_status);
        actor_status = StreamingLineBuffer_39_pixel_7.step(StreamingLineBuffer_39_buffer_stream[6], StreamingLineBuffer_39_out0_stream_prepad[1], StreamingLineBuffer_39_buffer_stream[7]);
        actor_statuses.push_back(actor_status);
        actor_status = StreamingLineBuffer_39_pixel_6.step(StreamingLineBuffer_39_buffer_stream[5], StreamingLineBuffer_39_out0_stream_prepad[2], StreamingLineBuffer_39_buffer_stream[6]);
        actor_statuses.push_back(actor_status);
        actor_status = StreamingLineBuffer_39_pixel_5.step(StreamingLineBuffer_39_buffer_stream[4], StreamingLineBuffer_39_out0_stream_prepad[3], StreamingLineBuffer_39_buffer_stream[5]);
        actor_statuses.push_back(actor_status);
        actor_status = StreamingLineBuffer_39_pixel_4.step(StreamingLineBuffer_39_buffer_stream[3], StreamingLineBuffer_39_out0_stream_prepad[4], StreamingLineBuffer_39_buffer_stream[4]);
        actor_statuses.push_back(actor_status);
        actor_status = StreamingLineBuffer_39_pixel_3.step(StreamingLineBuffer_39_buffer_stream[2], StreamingLineBuffer_39_out0_stream_prepad[5], StreamingLineBuffer_39_buffer_stream[3]);
        actor_statuses.push_back(actor_status);
        actor_status = StreamingLineBuffer_39_pixel_2.step(StreamingLineBuffer_39_buffer_stream[1], StreamingLineBuffer_39_out0_stream_prepad[6], StreamingLineBuffer_39_buffer_stream[2]);
        actor_statuses.push_back(actor_status);
        actor_status = StreamingLineBuffer_39_pixel_1.step(StreamingLineBuffer_39_buffer_stream[0], StreamingLineBuffer_39_out0_stream_prepad[7], StreamingLineBuffer_39_buffer_stream[1]);
        actor_statuses.push_back(actor_status);
        actor_status = StreamingLineBuffer_39_pixel_0.step(BandwidthAdjustDecreaseChannels_23_out0_stream[0], StreamingLineBuffer_39_out0_stream_prepad[8], StreamingLineBuffer_39_buffer_stream[0]);
        actor_statuses.push_back(actor_status);
        actor_status = BandwidthAdjustDecreaseChannels_23.step(StreamingConv_32_out0_stream, BandwidthAdjustDecreaseChannels_23_out0_stream);
        actor_statuses.push_back(actor_status);
        actor_status = StreamingConv_32.step(BandwidthAdjustIncreaseChannels_28_out0_stream, StreamingMemory_96_out0_stream, StreamingMemory_97_out0_stream, StreamingConv_32_out0_stream);
        actor_statuses.push_back(actor_status);
        actor_status = BandwidthAdjustIncreaseChannels_28.step(StreamingAdd_9_out0_stream, BandwidthAdjustIncreaseChannels_28_out0_stream);
        actor_statuses.push_back(actor_status);
        actor_status = StreamingAdd_9.step(BandwidthAdjustDecreaseChannels_21_out0_stream, StreamingConv_31_out0_stream, StreamingAdd_9_out0_stream);
        actor_statuses.push_back(actor_status);
        actor_status = StreamingConv_31.step(BandwidthAdjustIncreaseChannels_27_out0_stream, StreamingMemory_94_out0_stream, StreamingMemory_95_out0_stream, StreamingConv_31_out0_stream);
        actor_statuses.push_back(actor_status);
        actor_status = BandwidthAdjustIncreaseChannels_27.step(StreamingDepthwiseConv_15_out0_stream, BandwidthAdjustIncreaseChannels_27_out0_stream);
        actor_statuses.push_back(actor_status);
        actor_status = StreamingDepthwiseConv_15.step(StreamingLineBuffer_38_out0_stream, StreamingMemory_92_out0_stream, StreamingMemory_93_out0_stream, StreamingDepthwiseConv_15_out0_stream);
        actor_statuses.push_back(actor_status);
        actor_status = StreamingLineBuffer_38_pad.step(StreamingLineBuffer_38_out0_stream_prepad, StreamingLineBuffer_38_out0_stream);
        actor_statuses.push_back(actor_status);
        actor_status = StreamingLineBuffer_38_pixel_8.step(StreamingLineBuffer_38_buffer_stream[7], StreamingLineBuffer_38_out0_stream_prepad[0]);
        actor_statuses.push_back(actor_status);
        actor_status = StreamingLineBuffer_38_pixel_7.step(StreamingLineBuffer_38_buffer_stream[6], StreamingLineBuffer_38_out0_stream_prepad[1], StreamingLineBuffer_38_buffer_stream[7]);
        actor_statuses.push_back(actor_status);
        actor_status = StreamingLineBuffer_38_pixel_6.step(StreamingLineBuffer_38_buffer_stream[5], StreamingLineBuffer_38_out0_stream_prepad[2], StreamingLineBuffer_38_buffer_stream[6]);
        actor_statuses.push_back(actor_status);
        actor_status = StreamingLineBuffer_38_pixel_5.step(StreamingLineBuffer_38_buffer_stream[4], StreamingLineBuffer_38_out0_stream_prepad[3], StreamingLineBuffer_38_buffer_stream[5]);
        actor_statuses.push_back(actor_status);
        actor_status = StreamingLineBuffer_38_pixel_4.step(StreamingLineBuffer_38_buffer_stream[3], StreamingLineBuffer_38_out0_stream_prepad[4], StreamingLineBuffer_38_buffer_stream[4]);
        actor_statuses.push_back(actor_status);
        actor_status = StreamingLineBuffer_38_pixel_3.step(StreamingLineBuffer_38_buffer_stream[2], StreamingLineBuffer_38_out0_stream_prepad[5], StreamingLineBuffer_38_buffer_stream[3]);
        actor_statuses.push_back(actor_status);
        actor_status = StreamingLineBuffer_38_pixel_2.step(StreamingLineBuffer_38_buffer_stream[1], StreamingLineBuffer_38_out0_stream_prepad[6], StreamingLineBuffer_38_buffer_stream[2]);
        actor_statuses.push_back(actor_status);
        actor_status = StreamingLineBuffer_38_pixel_1.step(StreamingLineBuffer_38_buffer_stream[0], StreamingLineBuffer_38_out0_stream_prepad[7], StreamingLineBuffer_38_buffer_stream[1]);
        actor_statuses.push_back(actor_status);
        actor_status = StreamingLineBuffer_38_pixel_0.step(BandwidthAdjustDecreaseChannels_22_out0_stream[0], StreamingLineBuffer_38_out0_stream_prepad[8], StreamingLineBuffer_38_buffer_stream[0]);
        actor_statuses.push_back(actor_status);
        actor_status = BandwidthAdjustDecreaseChannels_22.step(StreamingConv_30_out0_stream, BandwidthAdjustDecreaseChannels_22_out0_stream);
        actor_statuses.push_back(actor_status);
        actor_status = StreamingConv_30.step(BandwidthAdjustIncreaseChannels_26_out0_stream, StreamingMemory_90_out0_stream, StreamingMemory_91_out0_stream, StreamingConv_30_out0_stream);
        actor_statuses.push_back(actor_status);
        actor_status = BandwidthAdjustDecreaseChannels_21.step(TensorDuplicator_9_out1_stream, BandwidthAdjustDecreaseChannels_21_out0_stream);
        actor_statuses.push_back(actor_status);
        actor_status = BandwidthAdjustIncreaseChannels_26.step(TensorDuplicator_9_out0_stream, BandwidthAdjustIncreaseChannels_26_out0_stream);
        actor_statuses.push_back(actor_status);
        actor_status = TensorDuplicator_9.step(BandwidthAdjustIncreaseChannels_25_out0_stream, TensorDuplicator_9_out0_stream, TensorDuplicator_9_out1_stream);
        actor_statuses.push_back(actor_status);
        actor_status = BandwidthAdjustIncreaseChannels_25.step(StreamingAdd_8_out0_stream, BandwidthAdjustIncreaseChannels_25_out0_stream);
        actor_statuses.push_back(actor_status);
        actor_status = StreamingAdd_8.step(BandwidthAdjustDecreaseChannels_19_out0_stream, StreamingConv_29_out0_stream, StreamingAdd_8_out0_stream);
        actor_statuses.push_back(actor_status);
        actor_status = StreamingConv_29.step(BandwidthAdjustIncreaseChannels_24_out0_stream, StreamingMemory_88_out0_stream, StreamingMemory_89_out0_stream, StreamingConv_29_out0_stream);
        actor_statuses.push_back(actor_status);
        actor_status = BandwidthAdjustIncreaseChannels_24.step(StreamingDepthwiseConv_14_out0_stream, BandwidthAdjustIncreaseChannels_24_out0_stream);
        actor_statuses.push_back(actor_status);
        actor_status = StreamingDepthwiseConv_14.step(StreamingLineBuffer_37_out0_stream, StreamingMemory_86_out0_stream, StreamingMemory_87_out0_stream, StreamingDepthwiseConv_14_out0_stream);
        actor_statuses.push_back(actor_status);
        actor_status = StreamingLineBuffer_37_pad.step(StreamingLineBuffer_37_out0_stream_prepad, StreamingLineBuffer_37_out0_stream);
        actor_statuses.push_back(actor_status);
        actor_status = StreamingLineBuffer_37_pixel_8.step(StreamingLineBuffer_37_buffer_stream[7], StreamingLineBuffer_37_out0_stream_prepad[0]);
        actor_statuses.push_back(actor_status);
        actor_status = StreamingLineBuffer_37_pixel_7.step(StreamingLineBuffer_37_buffer_stream[6], StreamingLineBuffer_37_out0_stream_prepad[1], StreamingLineBuffer_37_buffer_stream[7]);
        actor_statuses.push_back(actor_status);
        actor_status = StreamingLineBuffer_37_pixel_6.step(StreamingLineBuffer_37_buffer_stream[5], StreamingLineBuffer_37_out0_stream_prepad[2], StreamingLineBuffer_37_buffer_stream[6]);
        actor_statuses.push_back(actor_status);
        actor_status = StreamingLineBuffer_37_pixel_5.step(StreamingLineBuffer_37_buffer_stream[4], StreamingLineBuffer_37_out0_stream_prepad[3], StreamingLineBuffer_37_buffer_stream[5]);
        actor_statuses.push_back(actor_status);
        actor_status = StreamingLineBuffer_37_pixel_4.step(StreamingLineBuffer_37_buffer_stream[3], StreamingLineBuffer_37_out0_stream_prepad[4], StreamingLineBuffer_37_buffer_stream[4]);
        actor_statuses.push_back(actor_status);
        actor_status = StreamingLineBuffer_37_pixel_3.step(StreamingLineBuffer_37_buffer_stream[2], StreamingLineBuffer_37_out0_stream_prepad[5], StreamingLineBuffer_37_buffer_stream[3]);
        actor_statuses.push_back(actor_status);
        actor_status = StreamingLineBuffer_37_pixel_2.step(StreamingLineBuffer_37_buffer_stream[1], StreamingLineBuffer_37_out0_stream_prepad[6], StreamingLineBuffer_37_buffer_stream[2]);
        actor_statuses.push_back(actor_status);
        actor_status = StreamingLineBuffer_37_pixel_1.step(StreamingLineBuffer_37_buffer_stream[0], StreamingLineBuffer_37_out0_stream_prepad[7], StreamingLineBuffer_37_buffer_stream[1]);
        actor_statuses.push_back(actor_status);
        actor_status = StreamingLineBuffer_37_pixel_0.step(BandwidthAdjustDecreaseChannels_20_out0_stream[0], StreamingLineBuffer_37_out0_stream_prepad[8], StreamingLineBuffer_37_buffer_stream[0]);
        actor_statuses.push_back(actor_status);
        actor_status = BandwidthAdjustDecreaseChannels_20.step(StreamingConv_28_out0_stream, BandwidthAdjustDecreaseChannels_20_out0_stream);
        actor_statuses.push_back(actor_status);
        actor_status = StreamingConv_28.step(BandwidthAdjustIncreaseChannels_23_out0_stream, StreamingMemory_84_out0_stream, StreamingMemory_85_out0_stream, StreamingConv_28_out0_stream);
        actor_statuses.push_back(actor_status);
        actor_status = BandwidthAdjustIncreaseChannels_23.step(BandwidthAdjustDecreaseChannels_18_out0_stream, BandwidthAdjustIncreaseChannels_23_out0_stream);
        actor_statuses.push_back(actor_status);
        actor_status = BandwidthAdjustDecreaseChannels_19.step(TensorDuplicator_8_out1_stream, BandwidthAdjustDecreaseChannels_19_out0_stream);
        actor_statuses.push_back(actor_status);
        actor_status = BandwidthAdjustDecreaseChannels_18.step(TensorDuplicator_8_out0_stream, BandwidthAdjustDecreaseChannels_18_out0_stream);
        actor_statuses.push_back(actor_status);
        actor_status = TensorDuplicator_8.step(StreamingConv_27_out0_stream, TensorDuplicator_8_out0_stream, TensorDuplicator_8_out1_stream);
        actor_statuses.push_back(actor_status);
        actor_status = StreamingConv_27.step(BandwidthAdjustIncreaseChannels_22_out0_stream, StreamingMemory_82_out0_stream, StreamingMemory_83_out0_stream, StreamingConv_27_out0_stream);
        actor_statuses.push_back(actor_status);
        actor_status = BandwidthAdjustIncreaseChannels_22.step(StreamingDepthwiseConv_13_out0_stream, BandwidthAdjustIncreaseChannels_22_out0_stream);
        actor_statuses.push_back(actor_status);
        actor_status = StreamingDepthwiseConv_13.step(StreamingLineBuffer_36_out0_stream, StreamingMemory_80_out0_stream, StreamingMemory_81_out0_stream, StreamingDepthwiseConv_13_out0_stream);
        actor_statuses.push_back(actor_status);
        actor_status = StreamingLineBuffer_36_pad.step(StreamingLineBuffer_36_out0_stream_prepad, StreamingLineBuffer_36_out0_stream);
        actor_statuses.push_back(actor_status);
        actor_status = StreamingLineBuffer_36_pixel_8.step(StreamingLineBuffer_36_buffer_stream[7], StreamingLineBuffer_36_out0_stream_prepad[0]);
        actor_statuses.push_back(actor_status);
        actor_status = StreamingLineBuffer_36_pixel_7.step(StreamingLineBuffer_36_buffer_stream[6], StreamingLineBuffer_36_out0_stream_prepad[1], StreamingLineBuffer_36_buffer_stream[7]);
        actor_statuses.push_back(actor_status);
        actor_status = StreamingLineBuffer_36_pixel_6.step(StreamingLineBuffer_36_buffer_stream[5], StreamingLineBuffer_36_out0_stream_prepad[2], StreamingLineBuffer_36_buffer_stream[6]);
        actor_statuses.push_back(actor_status);
        actor_status = StreamingLineBuffer_36_pixel_5.step(StreamingLineBuffer_36_buffer_stream[4], StreamingLineBuffer_36_out0_stream_prepad[3], StreamingLineBuffer_36_buffer_stream[5]);
        actor_statuses.push_back(actor_status);
        actor_status = StreamingLineBuffer_36_pixel_4.step(StreamingLineBuffer_36_buffer_stream[3], StreamingLineBuffer_36_out0_stream_prepad[4], StreamingLineBuffer_36_buffer_stream[4]);
        actor_statuses.push_back(actor_status);
        actor_status = StreamingLineBuffer_36_pixel_3.step(StreamingLineBuffer_36_buffer_stream[2], StreamingLineBuffer_36_out0_stream_prepad[5], StreamingLineBuffer_36_buffer_stream[3]);
        actor_statuses.push_back(actor_status);
        actor_status = StreamingLineBuffer_36_pixel_2.step(StreamingLineBuffer_36_buffer_stream[1], StreamingLineBuffer_36_out0_stream_prepad[6], StreamingLineBuffer_36_buffer_stream[2]);
        actor_statuses.push_back(actor_status);
        actor_status = StreamingLineBuffer_36_pixel_1.step(StreamingLineBuffer_36_buffer_stream[0], StreamingLineBuffer_36_out0_stream_prepad[7], StreamingLineBuffer_36_buffer_stream[1]);
        actor_statuses.push_back(actor_status);
        actor_status = StreamingLineBuffer_36_pixel_0.step(BandwidthAdjustDecreaseChannels_17_out0_stream[0], StreamingLineBuffer_36_out0_stream_prepad[8], StreamingLineBuffer_36_buffer_stream[0]);
        actor_statuses.push_back(actor_status);
        actor_status = BandwidthAdjustDecreaseChannels_17.step(StreamingConv_26_out0_stream, BandwidthAdjustDecreaseChannels_17_out0_stream);
        actor_statuses.push_back(actor_status);
        actor_status = StreamingConv_26.step(BandwidthAdjustDecreaseStreams_8_out0_stream, StreamingMemory_78_out0_stream, StreamingMemory_79_out0_stream, StreamingConv_26_out0_stream);
        actor_statuses.push_back(actor_status);
        actor_status = BandwidthAdjustDecreaseStreams_8.step(BandwidthAdjustIncreaseChannels_21_out0_stream, BandwidthAdjustDecreaseStreams_8_out0_stream);
        actor_statuses.push_back(actor_status);
        actor_status = BandwidthAdjustIncreaseChannels_21.step(BandwidthAdjustDecreaseChannels_16_out0_stream, BandwidthAdjustIncreaseChannels_21_out0_stream);
        actor_statuses.push_back(actor_status);
        actor_status = BandwidthAdjustDecreaseChannels_16.step(StreamingAdd_7_out0_stream, BandwidthAdjustDecreaseChannels_16_out0_stream);
        actor_statuses.push_back(actor_status);
        actor_status = StreamingAdd_7.step(TensorDuplicator_7_out1_stream, StreamingConv_25_out0_stream, StreamingAdd_7_out0_stream);
        actor_statuses.push_back(actor_status);
        actor_status = StreamingConv_25.step(StreamingLineBuffer_35_out0_stream, StreamingMemory_76_out0_stream, StreamingMemory_77_out0_stream, StreamingConv_25_out0_stream);
        actor_statuses.push_back(actor_status);
        actor_status = StreamingLineBuffer_35_pixel_1.step(BandwidthAdjustIncreaseStreams_9_out0_stream[0], StreamingLineBuffer_35_out0_stream[0]);
        actor_statuses.push_back(actor_status);
        actor_status = StreamingLineBuffer_35_pixel_0.step(BandwidthAdjustIncreaseStreams_9_out0_stream[1], StreamingLineBuffer_35_out0_stream[1]);
        actor_statuses.push_back(actor_status);
        actor_status = BandwidthAdjustIncreaseStreams_9.step(BandwidthAdjustIncreaseChannels_20_out0_stream, BandwidthAdjustIncreaseStreams_9_out0_stream);
        actor_statuses.push_back(actor_status);
        actor_status = BandwidthAdjustIncreaseChannels_20.step(StreamingDepthwiseConv_12_out0_stream, BandwidthAdjustIncreaseChannels_20_out0_stream);
        actor_statuses.push_back(actor_status);
        actor_status = StreamingDepthwiseConv_12.step(StreamingLineBuffer_34_out0_stream, StreamingMemory_74_out0_stream, StreamingMemory_75_out0_stream, StreamingDepthwiseConv_12_out0_stream);
        actor_statuses.push_back(actor_status);
        actor_status = StreamingLineBuffer_34_pad.step(StreamingLineBuffer_34_out0_stream_prepad, StreamingLineBuffer_34_out0_stream);
        actor_statuses.push_back(actor_status);
        actor_status = StreamingLineBuffer_34_pixel_8.step(StreamingLineBuffer_34_buffer_stream[7], StreamingLineBuffer_34_out0_stream_prepad[0]);
        actor_statuses.push_back(actor_status);
        actor_status = StreamingLineBuffer_34_pixel_7.step(StreamingLineBuffer_34_buffer_stream[6], StreamingLineBuffer_34_out0_stream_prepad[1], StreamingLineBuffer_34_buffer_stream[7]);
        actor_statuses.push_back(actor_status);
        actor_status = StreamingLineBuffer_34_pixel_6.step(StreamingLineBuffer_34_buffer_stream[5], StreamingLineBuffer_34_out0_stream_prepad[2], StreamingLineBuffer_34_buffer_stream[6]);
        actor_statuses.push_back(actor_status);
        actor_status = StreamingLineBuffer_34_pixel_5.step(StreamingLineBuffer_34_buffer_stream[4], StreamingLineBuffer_34_out0_stream_prepad[3], StreamingLineBuffer_34_buffer_stream[5]);
        actor_statuses.push_back(actor_status);
        actor_status = StreamingLineBuffer_34_pixel_4.step(StreamingLineBuffer_34_buffer_stream[3], StreamingLineBuffer_34_out0_stream_prepad[4], StreamingLineBuffer_34_buffer_stream[4]);
        actor_statuses.push_back(actor_status);
        actor_status = StreamingLineBuffer_34_pixel_3.step(StreamingLineBuffer_34_buffer_stream[2], StreamingLineBuffer_34_out0_stream_prepad[5], StreamingLineBuffer_34_buffer_stream[3]);
        actor_statuses.push_back(actor_status);
        actor_status = StreamingLineBuffer_34_pixel_2.step(StreamingLineBuffer_34_buffer_stream[1], StreamingLineBuffer_34_out0_stream_prepad[6], StreamingLineBuffer_34_buffer_stream[2]);
        actor_statuses.push_back(actor_status);
        actor_status = StreamingLineBuffer_34_pixel_1.step(StreamingLineBuffer_34_buffer_stream[0], StreamingLineBuffer_34_out0_stream_prepad[7], StreamingLineBuffer_34_buffer_stream[1]);
        actor_statuses.push_back(actor_status);
        actor_status = StreamingLineBuffer_34_pixel_0.step(BandwidthAdjustDecreaseChannels_15_out0_stream[0], StreamingLineBuffer_34_out0_stream_prepad[8], StreamingLineBuffer_34_buffer_stream[0]);
        actor_statuses.push_back(actor_status);
        actor_status = BandwidthAdjustDecreaseChannels_15.step(StreamingConv_24_out0_stream, BandwidthAdjustDecreaseChannels_15_out0_stream);
        actor_statuses.push_back(actor_status);
        actor_status = StreamingConv_24.step(BandwidthAdjustDecreaseStreams_7_out0_stream, StreamingMemory_72_out0_stream, StreamingMemory_73_out0_stream, StreamingConv_24_out0_stream);
        actor_statuses.push_back(actor_status);
        actor_status = BandwidthAdjustDecreaseStreams_7.step(BandwidthAdjustIncreaseChannels_19_out0_stream, BandwidthAdjustDecreaseStreams_7_out0_stream);
        actor_statuses.push_back(actor_status);
        actor_status = BandwidthAdjustIncreaseChannels_19.step(BandwidthAdjustDecreaseChannels_14_out0_stream, BandwidthAdjustIncreaseChannels_19_out0_stream);
        actor_statuses.push_back(actor_status);
        actor_status = BandwidthAdjustDecreaseChannels_14.step(TensorDuplicator_7_out0_stream, BandwidthAdjustDecreaseChannels_14_out0_stream);
        actor_statuses.push_back(actor_status);
        actor_status = TensorDuplicator_7.step(StreamingAdd_6_out0_stream, TensorDuplicator_7_out0_stream, TensorDuplicator_7_out1_stream);
        actor_statuses.push_back(actor_status);
        actor_status = StreamingAdd_6.step(TensorDuplicator_6_out1_stream, StreamingConv_23_out0_stream, StreamingAdd_6_out0_stream);
        actor_statuses.push_back(actor_status);
        actor_status = StreamingConv_23.step(StreamingLineBuffer_33_out0_stream, StreamingMemory_70_out0_stream, StreamingMemory_71_out0_stream, StreamingConv_23_out0_stream);
        actor_statuses.push_back(actor_status);
        actor_status = StreamingLineBuffer_33_pixel_1.step(BandwidthAdjustIncreaseStreams_8_out0_stream[0], StreamingLineBuffer_33_out0_stream[0]);
        actor_statuses.push_back(actor_status);
        actor_status = StreamingLineBuffer_33_pixel_0.step(BandwidthAdjustIncreaseStreams_8_out0_stream[1], StreamingLineBuffer_33_out0_stream[1]);
        actor_statuses.push_back(actor_status);
        actor_status = BandwidthAdjustIncreaseStreams_8.step(BandwidthAdjustIncreaseChannels_18_out0_stream, BandwidthAdjustIncreaseStreams_8_out0_stream);
        actor_statuses.push_back(actor_status);
        actor_status = BandwidthAdjustIncreaseChannels_18.step(StreamingDepthwiseConv_11_out0_stream, BandwidthAdjustIncreaseChannels_18_out0_stream);
        actor_statuses.push_back(actor_status);
        actor_status = StreamingDepthwiseConv_11.step(StreamingLineBuffer_32_out0_stream, StreamingMemory_68_out0_stream, StreamingMemory_69_out0_stream, StreamingDepthwiseConv_11_out0_stream);
        actor_statuses.push_back(actor_status);
        actor_status = StreamingLineBuffer_32_pad.step(StreamingLineBuffer_32_out0_stream_prepad, StreamingLineBuffer_32_out0_stream);
        actor_statuses.push_back(actor_status);
        actor_status = StreamingLineBuffer_32_pixel_8.step(StreamingLineBuffer_32_buffer_stream[7], StreamingLineBuffer_32_out0_stream_prepad[0]);
        actor_statuses.push_back(actor_status);
        actor_status = StreamingLineBuffer_32_pixel_7.step(StreamingLineBuffer_32_buffer_stream[6], StreamingLineBuffer_32_out0_stream_prepad[1], StreamingLineBuffer_32_buffer_stream[7]);
        actor_statuses.push_back(actor_status);
        actor_status = StreamingLineBuffer_32_pixel_6.step(StreamingLineBuffer_32_buffer_stream[5], StreamingLineBuffer_32_out0_stream_prepad[2], StreamingLineBuffer_32_buffer_stream[6]);
        actor_statuses.push_back(actor_status);
        actor_status = StreamingLineBuffer_32_pixel_5.step(StreamingLineBuffer_32_buffer_stream[4], StreamingLineBuffer_32_out0_stream_prepad[3], StreamingLineBuffer_32_buffer_stream[5]);
        actor_statuses.push_back(actor_status);
        actor_status = StreamingLineBuffer_32_pixel_4.step(StreamingLineBuffer_32_buffer_stream[3], StreamingLineBuffer_32_out0_stream_prepad[4], StreamingLineBuffer_32_buffer_stream[4]);
        actor_statuses.push_back(actor_status);
        actor_status = StreamingLineBuffer_32_pixel_3.step(StreamingLineBuffer_32_buffer_stream[2], StreamingLineBuffer_32_out0_stream_prepad[5], StreamingLineBuffer_32_buffer_stream[3]);
        actor_statuses.push_back(actor_status);
        actor_status = StreamingLineBuffer_32_pixel_2.step(StreamingLineBuffer_32_buffer_stream[1], StreamingLineBuffer_32_out0_stream_prepad[6], StreamingLineBuffer_32_buffer_stream[2]);
        actor_statuses.push_back(actor_status);
        actor_status = StreamingLineBuffer_32_pixel_1.step(StreamingLineBuffer_32_buffer_stream[0], StreamingLineBuffer_32_out0_stream_prepad[7], StreamingLineBuffer_32_buffer_stream[1]);
        actor_statuses.push_back(actor_status);
        actor_status = StreamingLineBuffer_32_pixel_0.step(BandwidthAdjustDecreaseChannels_13_out0_stream[0], StreamingLineBuffer_32_out0_stream_prepad[8], StreamingLineBuffer_32_buffer_stream[0]);
        actor_statuses.push_back(actor_status);
        actor_status = BandwidthAdjustDecreaseChannels_13.step(StreamingConv_22_out0_stream, BandwidthAdjustDecreaseChannels_13_out0_stream);
        actor_statuses.push_back(actor_status);
        actor_status = StreamingConv_22.step(BandwidthAdjustDecreaseStreams_6_out0_stream, StreamingMemory_66_out0_stream, StreamingMemory_67_out0_stream, StreamingConv_22_out0_stream);
        actor_statuses.push_back(actor_status);
        actor_status = BandwidthAdjustDecreaseStreams_6.step(BandwidthAdjustIncreaseChannels_17_out0_stream, BandwidthAdjustDecreaseStreams_6_out0_stream);
        actor_statuses.push_back(actor_status);
        actor_status = BandwidthAdjustIncreaseChannels_17.step(BandwidthAdjustDecreaseChannels_12_out0_stream, BandwidthAdjustIncreaseChannels_17_out0_stream);
        actor_statuses.push_back(actor_status);
        actor_status = BandwidthAdjustDecreaseChannels_12.step(TensorDuplicator_6_out0_stream, BandwidthAdjustDecreaseChannels_12_out0_stream);
        actor_statuses.push_back(actor_status);
        actor_status = TensorDuplicator_6.step(StreamingConv_21_out0_stream, TensorDuplicator_6_out0_stream, TensorDuplicator_6_out1_stream);
        actor_statuses.push_back(actor_status);
        actor_status = StreamingConv_21.step(StreamingLineBuffer_31_out0_stream, StreamingMemory_64_out0_stream, StreamingMemory_65_out0_stream, StreamingConv_21_out0_stream);
        actor_statuses.push_back(actor_status);
        actor_status = StreamingLineBuffer_31_pixel_1.step(BandwidthAdjustIncreaseChannels_16_out0_stream[0], StreamingLineBuffer_31_out0_stream[0]);
        actor_statuses.push_back(actor_status);
        actor_status = StreamingLineBuffer_31_pixel_0.step(BandwidthAdjustIncreaseChannels_16_out0_stream[1], StreamingLineBuffer_31_out0_stream[1]);
        actor_statuses.push_back(actor_status);
        actor_status = BandwidthAdjustIncreaseChannels_16.step(StreamingDepthwiseConv_10_out0_stream, BandwidthAdjustIncreaseChannels_16_out0_stream);
        actor_statuses.push_back(actor_status);
        actor_status = StreamingDepthwiseConv_10.step(StreamingLineBuffer_30_out0_stream, StreamingMemory_62_out0_stream, StreamingMemory_63_out0_stream, StreamingDepthwiseConv_10_out0_stream);
        actor_statuses.push_back(actor_status);
        actor_status = StreamingLineBuffer_30_pad.step(StreamingLineBuffer_30_out0_stream_prepad, StreamingLineBuffer_30_out0_stream);
        actor_statuses.push_back(actor_status);
        actor_status = StreamingLineBuffer_30_pixel_11.step(StreamingLineBuffer_30_buffer_stream[9], StreamingLineBuffer_30_out0_stream_prepad[0]);
        actor_statuses.push_back(actor_status);
        actor_status = StreamingLineBuffer_30_pixel_10.step(StreamingLineBuffer_30_buffer_stream[8], StreamingLineBuffer_30_out0_stream_prepad[1]);
        actor_statuses.push_back(actor_status);
        actor_status = StreamingLineBuffer_30_pixel_9.step(StreamingLineBuffer_30_buffer_stream[7], StreamingLineBuffer_30_out0_stream_prepad[2], StreamingLineBuffer_30_buffer_stream[9]);
        actor_statuses.push_back(actor_status);
        actor_status = StreamingLineBuffer_30_pixel_8.step(StreamingLineBuffer_30_buffer_stream[6], StreamingLineBuffer_30_out0_stream_prepad[3], StreamingLineBuffer_30_buffer_stream[8]);
        actor_statuses.push_back(actor_status);
        actor_status = StreamingLineBuffer_30_pixel_7.step(StreamingLineBuffer_30_buffer_stream[5], StreamingLineBuffer_30_out0_stream_prepad[4], StreamingLineBuffer_30_buffer_stream[7]);
        actor_statuses.push_back(actor_status);
        actor_status = StreamingLineBuffer_30_pixel_6.step(StreamingLineBuffer_30_buffer_stream[4], StreamingLineBuffer_30_out0_stream_prepad[5], StreamingLineBuffer_30_buffer_stream[6]);
        actor_statuses.push_back(actor_status);
        actor_status = StreamingLineBuffer_30_pixel_5.step(StreamingLineBuffer_30_buffer_stream[3], StreamingLineBuffer_30_out0_stream_prepad[6], StreamingLineBuffer_30_buffer_stream[5]);
        actor_statuses.push_back(actor_status);
        actor_status = StreamingLineBuffer_30_pixel_4.step(StreamingLineBuffer_30_buffer_stream[2], StreamingLineBuffer_30_out0_stream_prepad[7], StreamingLineBuffer_30_buffer_stream[4]);
        actor_statuses.push_back(actor_status);
        actor_status = StreamingLineBuffer_30_pixel_3.step(StreamingLineBuffer_30_buffer_stream[1], StreamingLineBuffer_30_out0_stream_prepad[8], StreamingLineBuffer_30_buffer_stream[3]);
        actor_statuses.push_back(actor_status);
        actor_status = StreamingLineBuffer_30_pixel_2.step(StreamingLineBuffer_30_buffer_stream[0], StreamingLineBuffer_30_out0_stream_prepad[9], StreamingLineBuffer_30_buffer_stream[2]);
        actor_statuses.push_back(actor_status);
        actor_status = StreamingLineBuffer_30_pixel_1.step(BandwidthAdjustDecreaseChannels_11_out0_stream[1], StreamingLineBuffer_30_out0_stream_prepad[10], StreamingLineBuffer_30_buffer_stream[1]);
        actor_statuses.push_back(actor_status);
        actor_status = StreamingLineBuffer_30_pixel_0.step(BandwidthAdjustDecreaseChannels_11_out0_stream[0], StreamingLineBuffer_30_out0_stream_prepad[11], StreamingLineBuffer_30_buffer_stream[0]);
        actor_statuses.push_back(actor_status);
        actor_status = BandwidthAdjustDecreaseChannels_11.step(StreamingConv_20_out0_stream, BandwidthAdjustDecreaseChannels_11_out0_stream);
        actor_statuses.push_back(actor_status);
        actor_status = StreamingConv_20.step(StreamingLineBuffer_29_out0_stream, StreamingMemory_60_out0_stream, StreamingMemory_61_out0_stream, StreamingConv_20_out0_stream);
        actor_statuses.push_back(actor_status);
        actor_status = StreamingLineBuffer_29_pixel_1.step(StreamingAdd_5_out0_stream[0], StreamingLineBuffer_29_out0_stream[0]);
        actor_statuses.push_back(actor_status);
        actor_status = StreamingLineBuffer_29_pixel_0.step(StreamingAdd_5_out0_stream[1], StreamingLineBuffer_29_out0_stream[1]);
        actor_statuses.push_back(actor_status);
        actor_status = StreamingAdd_5.step(BandwidthAdjustIncreaseStreams_7_out0_stream, StreamingConv_19_out0_stream, StreamingAdd_5_out0_stream);
        actor_statuses.push_back(actor_status);
        actor_status = StreamingConv_19.step(StreamingLineBuffer_28_out0_stream, StreamingMemory_58_out0_stream, StreamingMemory_59_out0_stream, StreamingConv_19_out0_stream);
        actor_statuses.push_back(actor_status);
        actor_status = StreamingLineBuffer_28_pixel_1.step(BandwidthAdjustIncreaseChannels_15_out0_stream[0], StreamingLineBuffer_28_out0_stream[0]);
        actor_statuses.push_back(actor_status);
        actor_status = StreamingLineBuffer_28_pixel_0.step(BandwidthAdjustIncreaseChannels_15_out0_stream[1], StreamingLineBuffer_28_out0_stream[1]);
        actor_statuses.push_back(actor_status);
        actor_status = BandwidthAdjustIncreaseChannels_15.step(StreamingDepthwiseConv_9_out0_stream, BandwidthAdjustIncreaseChannels_15_out0_stream);
        actor_statuses.push_back(actor_status);
        actor_status = StreamingDepthwiseConv_9.step(StreamingLineBuffer_27_out0_stream, StreamingMemory_56_out0_stream, StreamingMemory_57_out0_stream, StreamingDepthwiseConv_9_out0_stream);
        actor_statuses.push_back(actor_status);
        actor_status = StreamingLineBuffer_27_pad.step(StreamingLineBuffer_27_out0_stream_prepad, StreamingLineBuffer_27_out0_stream);
        actor_statuses.push_back(actor_status);
        actor_status = StreamingLineBuffer_27_pixel_11.step(StreamingLineBuffer_27_buffer_stream[9], StreamingLineBuffer_27_out0_stream_prepad[0]);
        actor_statuses.push_back(actor_status);
        actor_status = StreamingLineBuffer_27_pixel_10.step(StreamingLineBuffer_27_buffer_stream[8], StreamingLineBuffer_27_out0_stream_prepad[1]);
        actor_statuses.push_back(actor_status);
        actor_status = StreamingLineBuffer_27_pixel_9.step(StreamingLineBuffer_27_buffer_stream[7], StreamingLineBuffer_27_out0_stream_prepad[2], StreamingLineBuffer_27_buffer_stream[9]);
        actor_statuses.push_back(actor_status);
        actor_status = StreamingLineBuffer_27_pixel_8.step(StreamingLineBuffer_27_buffer_stream[6], StreamingLineBuffer_27_out0_stream_prepad[3], StreamingLineBuffer_27_buffer_stream[8]);
        actor_statuses.push_back(actor_status);
        actor_status = StreamingLineBuffer_27_pixel_7.step(StreamingLineBuffer_27_buffer_stream[5], StreamingLineBuffer_27_out0_stream_prepad[4], StreamingLineBuffer_27_buffer_stream[7]);
        actor_statuses.push_back(actor_status);
        actor_status = StreamingLineBuffer_27_pixel_6.step(StreamingLineBuffer_27_buffer_stream[4], StreamingLineBuffer_27_out0_stream_prepad[5], StreamingLineBuffer_27_buffer_stream[6]);
        actor_statuses.push_back(actor_status);
        actor_status = StreamingLineBuffer_27_pixel_5.step(StreamingLineBuffer_27_buffer_stream[3], StreamingLineBuffer_27_out0_stream_prepad[6], StreamingLineBuffer_27_buffer_stream[5]);
        actor_statuses.push_back(actor_status);
        actor_status = StreamingLineBuffer_27_pixel_4.step(StreamingLineBuffer_27_buffer_stream[2], StreamingLineBuffer_27_out0_stream_prepad[7], StreamingLineBuffer_27_buffer_stream[4]);
        actor_statuses.push_back(actor_status);
        actor_status = StreamingLineBuffer_27_pixel_3.step(StreamingLineBuffer_27_buffer_stream[1], StreamingLineBuffer_27_out0_stream_prepad[8], StreamingLineBuffer_27_buffer_stream[3]);
        actor_statuses.push_back(actor_status);
        actor_status = StreamingLineBuffer_27_pixel_2.step(StreamingLineBuffer_27_buffer_stream[0], StreamingLineBuffer_27_out0_stream_prepad[9], StreamingLineBuffer_27_buffer_stream[2]);
        actor_statuses.push_back(actor_status);
        actor_status = StreamingLineBuffer_27_pixel_1.step(BandwidthAdjustDecreaseChannels_10_out0_stream[1], StreamingLineBuffer_27_out0_stream_prepad[10], StreamingLineBuffer_27_buffer_stream[1]);
        actor_statuses.push_back(actor_status);
        actor_status = StreamingLineBuffer_27_pixel_0.step(BandwidthAdjustDecreaseChannels_10_out0_stream[0], StreamingLineBuffer_27_out0_stream_prepad[11], StreamingLineBuffer_27_buffer_stream[0]);
        actor_statuses.push_back(actor_status);
        actor_status = BandwidthAdjustDecreaseChannels_10.step(StreamingConv_18_out0_stream, BandwidthAdjustDecreaseChannels_10_out0_stream);
        actor_statuses.push_back(actor_status);
        actor_status = StreamingConv_18.step(StreamingLineBuffer_26_out0_stream, StreamingMemory_54_out0_stream, StreamingMemory_55_out0_stream, StreamingConv_18_out0_stream);
        actor_statuses.push_back(actor_status);
        actor_status = StreamingLineBuffer_26_pixel_1.step(BandwidthAdjustIncreaseStreams_6_out0_stream[0], StreamingLineBuffer_26_out0_stream[0]);
        actor_statuses.push_back(actor_status);
        actor_status = StreamingLineBuffer_26_pixel_0.step(BandwidthAdjustIncreaseStreams_6_out0_stream[1], StreamingLineBuffer_26_out0_stream[1]);
        actor_statuses.push_back(actor_status);
        actor_status = BandwidthAdjustIncreaseStreams_7.step(TensorDuplicator_5_out1_stream, BandwidthAdjustIncreaseStreams_7_out0_stream);
        actor_statuses.push_back(actor_status);
        actor_status = BandwidthAdjustIncreaseStreams_6.step(TensorDuplicator_5_out0_stream, BandwidthAdjustIncreaseStreams_6_out0_stream);
        actor_statuses.push_back(actor_status);
        actor_status = TensorDuplicator_5.step(BandwidthAdjustDecreaseStreams_5_out0_stream, TensorDuplicator_5_out0_stream, TensorDuplicator_5_out1_stream);
        actor_statuses.push_back(actor_status);
        actor_status = BandwidthAdjustDecreaseStreams_5.step(StreamingAdd_4_out0_stream, BandwidthAdjustDecreaseStreams_5_out0_stream);
        actor_statuses.push_back(actor_status);
        actor_status = StreamingAdd_4.step(BandwidthAdjustIncreaseStreams_5_out0_stream, StreamingConv_17_out0_stream, StreamingAdd_4_out0_stream);
        actor_statuses.push_back(actor_status);
        actor_status = StreamingConv_17.step(StreamingLineBuffer_25_out0_stream, StreamingMemory_52_out0_stream, StreamingMemory_53_out0_stream, StreamingConv_17_out0_stream);
        actor_statuses.push_back(actor_status);
        actor_status = StreamingLineBuffer_25_pixel_1.step(BandwidthAdjustIncreaseChannels_14_out0_stream[0], StreamingLineBuffer_25_out0_stream[0]);
        actor_statuses.push_back(actor_status);
        actor_status = StreamingLineBuffer_25_pixel_0.step(BandwidthAdjustIncreaseChannels_14_out0_stream[1], StreamingLineBuffer_25_out0_stream[1]);
        actor_statuses.push_back(actor_status);
        actor_status = BandwidthAdjustIncreaseChannels_14.step(StreamingDepthwiseConv_8_out0_stream, BandwidthAdjustIncreaseChannels_14_out0_stream);
        actor_statuses.push_back(actor_status);
        actor_status = StreamingDepthwiseConv_8.step(StreamingLineBuffer_24_out0_stream, StreamingMemory_50_out0_stream, StreamingMemory_51_out0_stream, StreamingDepthwiseConv_8_out0_stream);
        actor_statuses.push_back(actor_status);
        actor_status = StreamingLineBuffer_24_pad.step(StreamingLineBuffer_24_out0_stream_prepad, StreamingLineBuffer_24_out0_stream);
        actor_statuses.push_back(actor_status);
        actor_status = StreamingLineBuffer_24_pixel_11.step(StreamingLineBuffer_24_buffer_stream[9], StreamingLineBuffer_24_out0_stream_prepad[0]);
        actor_statuses.push_back(actor_status);
        actor_status = StreamingLineBuffer_24_pixel_10.step(StreamingLineBuffer_24_buffer_stream[8], StreamingLineBuffer_24_out0_stream_prepad[1]);
        actor_statuses.push_back(actor_status);
        actor_status = StreamingLineBuffer_24_pixel_9.step(StreamingLineBuffer_24_buffer_stream[7], StreamingLineBuffer_24_out0_stream_prepad[2], StreamingLineBuffer_24_buffer_stream[9]);
        actor_statuses.push_back(actor_status);
        actor_status = StreamingLineBuffer_24_pixel_8.step(StreamingLineBuffer_24_buffer_stream[6], StreamingLineBuffer_24_out0_stream_prepad[3], StreamingLineBuffer_24_buffer_stream[8]);
        actor_statuses.push_back(actor_status);
        actor_status = StreamingLineBuffer_24_pixel_7.step(StreamingLineBuffer_24_buffer_stream[5], StreamingLineBuffer_24_out0_stream_prepad[4], StreamingLineBuffer_24_buffer_stream[7]);
        actor_statuses.push_back(actor_status);
        actor_status = StreamingLineBuffer_24_pixel_6.step(StreamingLineBuffer_24_buffer_stream[4], StreamingLineBuffer_24_out0_stream_prepad[5], StreamingLineBuffer_24_buffer_stream[6]);
        actor_statuses.push_back(actor_status);
        actor_status = StreamingLineBuffer_24_pixel_5.step(StreamingLineBuffer_24_buffer_stream[3], StreamingLineBuffer_24_out0_stream_prepad[6], StreamingLineBuffer_24_buffer_stream[5]);
        actor_statuses.push_back(actor_status);
        actor_status = StreamingLineBuffer_24_pixel_4.step(StreamingLineBuffer_24_buffer_stream[2], StreamingLineBuffer_24_out0_stream_prepad[7], StreamingLineBuffer_24_buffer_stream[4]);
        actor_statuses.push_back(actor_status);
        actor_status = StreamingLineBuffer_24_pixel_3.step(StreamingLineBuffer_24_buffer_stream[1], StreamingLineBuffer_24_out0_stream_prepad[8], StreamingLineBuffer_24_buffer_stream[3]);
        actor_statuses.push_back(actor_status);
        actor_status = StreamingLineBuffer_24_pixel_2.step(StreamingLineBuffer_24_buffer_stream[0], StreamingLineBuffer_24_out0_stream_prepad[9], StreamingLineBuffer_24_buffer_stream[2]);
        actor_statuses.push_back(actor_status);
        actor_status = StreamingLineBuffer_24_pixel_1.step(BandwidthAdjustDecreaseChannels_9_out0_stream[1], StreamingLineBuffer_24_out0_stream_prepad[10], StreamingLineBuffer_24_buffer_stream[1]);
        actor_statuses.push_back(actor_status);
        actor_status = StreamingLineBuffer_24_pixel_0.step(BandwidthAdjustDecreaseChannels_9_out0_stream[0], StreamingLineBuffer_24_out0_stream_prepad[11], StreamingLineBuffer_24_buffer_stream[0]);
        actor_statuses.push_back(actor_status);
        actor_status = BandwidthAdjustDecreaseChannels_9.step(StreamingConv_16_out0_stream, BandwidthAdjustDecreaseChannels_9_out0_stream);
        actor_statuses.push_back(actor_status);
        actor_status = StreamingConv_16.step(StreamingLineBuffer_23_out0_stream, StreamingMemory_48_out0_stream, StreamingMemory_49_out0_stream, StreamingConv_16_out0_stream);
        actor_statuses.push_back(actor_status);
        actor_status = StreamingLineBuffer_23_pixel_1.step(BandwidthAdjustIncreaseStreams_4_out0_stream[0], StreamingLineBuffer_23_out0_stream[0]);
        actor_statuses.push_back(actor_status);
        actor_status = StreamingLineBuffer_23_pixel_0.step(BandwidthAdjustIncreaseStreams_4_out0_stream[1], StreamingLineBuffer_23_out0_stream[1]);
        actor_statuses.push_back(actor_status);
        actor_status = BandwidthAdjustIncreaseStreams_5.step(TensorDuplicator_4_out1_stream, BandwidthAdjustIncreaseStreams_5_out0_stream);
        actor_statuses.push_back(actor_status);
        actor_status = BandwidthAdjustIncreaseStreams_4.step(TensorDuplicator_4_out0_stream, BandwidthAdjustIncreaseStreams_4_out0_stream);
        actor_statuses.push_back(actor_status);
        actor_status = TensorDuplicator_4.step(BandwidthAdjustDecreaseStreams_4_out0_stream, TensorDuplicator_4_out0_stream, TensorDuplicator_4_out1_stream);
        actor_statuses.push_back(actor_status);
        actor_status = BandwidthAdjustDecreaseStreams_4.step(StreamingAdd_3_out0_stream, BandwidthAdjustDecreaseStreams_4_out0_stream);
        actor_statuses.push_back(actor_status);
        actor_status = StreamingAdd_3.step(BandwidthAdjustIncreaseStreams_3_out0_stream, StreamingConv_15_out0_stream, StreamingAdd_3_out0_stream);
        actor_statuses.push_back(actor_status);
        actor_status = StreamingConv_15.step(StreamingLineBuffer_22_out0_stream, StreamingMemory_46_out0_stream, StreamingMemory_47_out0_stream, StreamingConv_15_out0_stream);
        actor_statuses.push_back(actor_status);
        actor_status = StreamingLineBuffer_22_pixel_1.step(BandwidthAdjustIncreaseChannels_13_out0_stream[0], StreamingLineBuffer_22_out0_stream[0]);
        actor_statuses.push_back(actor_status);
        actor_status = StreamingLineBuffer_22_pixel_0.step(BandwidthAdjustIncreaseChannels_13_out0_stream[1], StreamingLineBuffer_22_out0_stream[1]);
        actor_statuses.push_back(actor_status);
        actor_status = BandwidthAdjustIncreaseChannels_13.step(StreamingDepthwiseConv_7_out0_stream, BandwidthAdjustIncreaseChannels_13_out0_stream);
        actor_statuses.push_back(actor_status);
        actor_status = StreamingDepthwiseConv_7.step(StreamingLineBuffer_21_out0_stream, StreamingMemory_44_out0_stream, StreamingMemory_45_out0_stream, StreamingDepthwiseConv_7_out0_stream);
        actor_statuses.push_back(actor_status);
        actor_status = StreamingLineBuffer_21_pad.step(StreamingLineBuffer_21_out0_stream_prepad, StreamingLineBuffer_21_out0_stream);
        actor_statuses.push_back(actor_status);
        actor_status = StreamingLineBuffer_21_pixel_11.step(StreamingLineBuffer_21_buffer_stream[9], StreamingLineBuffer_21_out0_stream_prepad[0]);
        actor_statuses.push_back(actor_status);
        actor_status = StreamingLineBuffer_21_pixel_10.step(StreamingLineBuffer_21_buffer_stream[8], StreamingLineBuffer_21_out0_stream_prepad[1]);
        actor_statuses.push_back(actor_status);
        actor_status = StreamingLineBuffer_21_pixel_9.step(StreamingLineBuffer_21_buffer_stream[7], StreamingLineBuffer_21_out0_stream_prepad[2], StreamingLineBuffer_21_buffer_stream[9]);
        actor_statuses.push_back(actor_status);
        actor_status = StreamingLineBuffer_21_pixel_8.step(StreamingLineBuffer_21_buffer_stream[6], StreamingLineBuffer_21_out0_stream_prepad[3], StreamingLineBuffer_21_buffer_stream[8]);
        actor_statuses.push_back(actor_status);
        actor_status = StreamingLineBuffer_21_pixel_7.step(StreamingLineBuffer_21_buffer_stream[5], StreamingLineBuffer_21_out0_stream_prepad[4], StreamingLineBuffer_21_buffer_stream[7]);
        actor_statuses.push_back(actor_status);
        actor_status = StreamingLineBuffer_21_pixel_6.step(StreamingLineBuffer_21_buffer_stream[4], StreamingLineBuffer_21_out0_stream_prepad[5], StreamingLineBuffer_21_buffer_stream[6]);
        actor_statuses.push_back(actor_status);
        actor_status = StreamingLineBuffer_21_pixel_5.step(StreamingLineBuffer_21_buffer_stream[3], StreamingLineBuffer_21_out0_stream_prepad[6], StreamingLineBuffer_21_buffer_stream[5]);
        actor_statuses.push_back(actor_status);
        actor_status = StreamingLineBuffer_21_pixel_4.step(StreamingLineBuffer_21_buffer_stream[2], StreamingLineBuffer_21_out0_stream_prepad[7], StreamingLineBuffer_21_buffer_stream[4]);
        actor_statuses.push_back(actor_status);
        actor_status = StreamingLineBuffer_21_pixel_3.step(StreamingLineBuffer_21_buffer_stream[1], StreamingLineBuffer_21_out0_stream_prepad[8], StreamingLineBuffer_21_buffer_stream[3]);
        actor_statuses.push_back(actor_status);
        actor_status = StreamingLineBuffer_21_pixel_2.step(StreamingLineBuffer_21_buffer_stream[0], StreamingLineBuffer_21_out0_stream_prepad[9], StreamingLineBuffer_21_buffer_stream[2]);
        actor_statuses.push_back(actor_status);
        actor_status = StreamingLineBuffer_21_pixel_1.step(BandwidthAdjustDecreaseChannels_8_out0_stream[1], StreamingLineBuffer_21_out0_stream_prepad[10], StreamingLineBuffer_21_buffer_stream[1]);
        actor_statuses.push_back(actor_status);
        actor_status = StreamingLineBuffer_21_pixel_0.step(BandwidthAdjustDecreaseChannels_8_out0_stream[0], StreamingLineBuffer_21_out0_stream_prepad[11], StreamingLineBuffer_21_buffer_stream[0]);
        actor_statuses.push_back(actor_status);
        actor_status = BandwidthAdjustDecreaseChannels_8.step(StreamingConv_14_out0_stream, BandwidthAdjustDecreaseChannels_8_out0_stream);
        actor_statuses.push_back(actor_status);
        actor_status = StreamingConv_14.step(StreamingLineBuffer_20_out0_stream, StreamingMemory_42_out0_stream, StreamingMemory_43_out0_stream, StreamingConv_14_out0_stream);
        actor_statuses.push_back(actor_status);
        actor_status = StreamingLineBuffer_20_pixel_1.step(BandwidthAdjustIncreaseStreams_2_out0_stream[0], StreamingLineBuffer_20_out0_stream[0]);
        actor_statuses.push_back(actor_status);
        actor_status = StreamingLineBuffer_20_pixel_0.step(BandwidthAdjustIncreaseStreams_2_out0_stream[1], StreamingLineBuffer_20_out0_stream[1]);
        actor_statuses.push_back(actor_status);
        actor_status = BandwidthAdjustIncreaseStreams_3.step(TensorDuplicator_3_out1_stream, BandwidthAdjustIncreaseStreams_3_out0_stream);
        actor_statuses.push_back(actor_status);
        actor_status = BandwidthAdjustIncreaseStreams_2.step(TensorDuplicator_3_out0_stream, BandwidthAdjustIncreaseStreams_2_out0_stream);
        actor_statuses.push_back(actor_status);
        actor_status = TensorDuplicator_3.step(StreamingConv_13_out0_stream, TensorDuplicator_3_out0_stream, TensorDuplicator_3_out1_stream);
        actor_statuses.push_back(actor_status);
        actor_status = StreamingConv_13.step(BandwidthAdjustIncreaseChannels_12_out0_stream, StreamingMemory_40_out0_stream, StreamingMemory_41_out0_stream, StreamingConv_13_out0_stream);
        actor_statuses.push_back(actor_status);
        actor_status = BandwidthAdjustIncreaseChannels_12.step(StreamingDepthwiseConv_6_out0_stream, BandwidthAdjustIncreaseChannels_12_out0_stream);
        actor_statuses.push_back(actor_status);
        actor_status = StreamingDepthwiseConv_6.step(StreamingLineBuffer_19_out0_stream, StreamingMemory_38_out0_stream, StreamingMemory_39_out0_stream, StreamingDepthwiseConv_6_out0_stream);
        actor_statuses.push_back(actor_status);
        actor_status = StreamingLineBuffer_19_pad.step(StreamingLineBuffer_19_out0_stream_prepad, StreamingLineBuffer_19_out0_stream);
        actor_statuses.push_back(actor_status);
        actor_status = StreamingLineBuffer_19_pixel_8.step(StreamingLineBuffer_19_buffer_stream[7], StreamingLineBuffer_19_out0_stream_prepad[0]);
        actor_statuses.push_back(actor_status);
        actor_status = StreamingLineBuffer_19_pixel_7.step(StreamingLineBuffer_19_buffer_stream[6], StreamingLineBuffer_19_out0_stream_prepad[1], StreamingLineBuffer_19_buffer_stream[7]);
        actor_statuses.push_back(actor_status);
        actor_status = StreamingLineBuffer_19_pixel_6.step(StreamingLineBuffer_19_buffer_stream[5], StreamingLineBuffer_19_out0_stream_prepad[2], StreamingLineBuffer_19_buffer_stream[6]);
        actor_statuses.push_back(actor_status);
        actor_status = StreamingLineBuffer_19_pixel_5.step(StreamingLineBuffer_19_buffer_stream[4], StreamingLineBuffer_19_out0_stream_prepad[3], StreamingLineBuffer_19_buffer_stream[5]);
        actor_statuses.push_back(actor_status);
        actor_status = StreamingLineBuffer_19_pixel_4.step(StreamingLineBuffer_19_buffer_stream[3], StreamingLineBuffer_19_out0_stream_prepad[4], StreamingLineBuffer_19_buffer_stream[4]);
        actor_statuses.push_back(actor_status);
        actor_status = StreamingLineBuffer_19_pixel_3.step(StreamingLineBuffer_19_buffer_stream[2], StreamingLineBuffer_19_out0_stream_prepad[5], StreamingLineBuffer_19_buffer_stream[3]);
        actor_statuses.push_back(actor_status);
        actor_status = StreamingLineBuffer_19_pixel_2.step(StreamingLineBuffer_19_buffer_stream[1], StreamingLineBuffer_19_out0_stream_prepad[6], StreamingLineBuffer_19_buffer_stream[2]);
        actor_statuses.push_back(actor_status);
        actor_status = StreamingLineBuffer_19_pixel_1.step(StreamingLineBuffer_19_buffer_stream[0], StreamingLineBuffer_19_out0_stream_prepad[7], StreamingLineBuffer_19_buffer_stream[1]);
        actor_statuses.push_back(actor_status);
        actor_status = StreamingLineBuffer_19_pixel_0.step(BandwidthAdjustDecreaseStreams_3_out0_stream[0], StreamingLineBuffer_19_out0_stream_prepad[8], StreamingLineBuffer_19_buffer_stream[0]);
        actor_statuses.push_back(actor_status);
        actor_status = BandwidthAdjustDecreaseStreams_3.step(BandwidthAdjustDecreaseChannels_7_out0_stream, BandwidthAdjustDecreaseStreams_3_out0_stream);
        actor_statuses.push_back(actor_status);
        actor_status = BandwidthAdjustDecreaseChannels_7.step(StreamingConv_12_out0_stream, BandwidthAdjustDecreaseChannels_7_out0_stream);
        actor_statuses.push_back(actor_status);
        actor_status = StreamingConv_12.step(StreamingLineBuffer_18_out0_stream, StreamingMemory_36_out0_stream, StreamingMemory_37_out0_stream, StreamingConv_12_out0_stream);
        actor_statuses.push_back(actor_status);
        actor_status = StreamingLineBuffer_18_pixel_1.step(StreamingAdd_2_out0_stream[0], StreamingLineBuffer_18_out0_stream[0]);
        actor_statuses.push_back(actor_status);
        actor_status = StreamingLineBuffer_18_pixel_0.step(StreamingAdd_2_out0_stream[1], StreamingLineBuffer_18_out0_stream[1]);
        actor_statuses.push_back(actor_status);
        actor_status = StreamingAdd_2.step(BandwidthAdjustIncreaseChannels_10_out0_stream, StreamingConv_11_out0_stream, StreamingAdd_2_out0_stream);
        actor_statuses.push_back(actor_status);
        actor_status = StreamingConv_11.step(StreamingLineBuffer_17_out0_stream, StreamingMemory_34_out0_stream, StreamingMemory_35_out0_stream, StreamingConv_11_out0_stream);
        actor_statuses.push_back(actor_status);
        actor_status = StreamingLineBuffer_17_pixel_1.step(BandwidthAdjustIncreaseChannels_11_out0_stream[0], StreamingLineBuffer_17_out0_stream[0]);
        actor_statuses.push_back(actor_status);
        actor_status = StreamingLineBuffer_17_pixel_0.step(BandwidthAdjustIncreaseChannels_11_out0_stream[1], StreamingLineBuffer_17_out0_stream[1]);
        actor_statuses.push_back(actor_status);
        actor_status = BandwidthAdjustIncreaseChannels_11.step(StreamingDepthwiseConv_5_out0_stream, BandwidthAdjustIncreaseChannels_11_out0_stream);
        actor_statuses.push_back(actor_status);
        actor_status = StreamingDepthwiseConv_5.step(StreamingLineBuffer_16_out0_stream, StreamingMemory_32_out0_stream, StreamingMemory_33_out0_stream, StreamingDepthwiseConv_5_out0_stream);
        actor_statuses.push_back(actor_status);
        actor_status = StreamingLineBuffer_16_pad.step(StreamingLineBuffer_16_out0_stream_prepad, StreamingLineBuffer_16_out0_stream);
        actor_statuses.push_back(actor_status);
        actor_status = StreamingLineBuffer_16_pixel_11.step(StreamingLineBuffer_16_buffer_stream[9], StreamingLineBuffer_16_out0_stream_prepad[0]);
        actor_statuses.push_back(actor_status);
        actor_status = StreamingLineBuffer_16_pixel_10.step(StreamingLineBuffer_16_buffer_stream[8], StreamingLineBuffer_16_out0_stream_prepad[1]);
        actor_statuses.push_back(actor_status);
        actor_status = StreamingLineBuffer_16_pixel_9.step(StreamingLineBuffer_16_buffer_stream[7], StreamingLineBuffer_16_out0_stream_prepad[2], StreamingLineBuffer_16_buffer_stream[9]);
        actor_statuses.push_back(actor_status);
        actor_status = StreamingLineBuffer_16_pixel_8.step(StreamingLineBuffer_16_buffer_stream[6], StreamingLineBuffer_16_out0_stream_prepad[3], StreamingLineBuffer_16_buffer_stream[8]);
        actor_statuses.push_back(actor_status);
        actor_status = StreamingMemory_105.step(StreamingMemory_104_out1_stream, StreamingMemory_105_out0_stream);
        actor_statuses.push_back(actor_status);
        actor_status = StreamingLineBuffer_16_pixel_7.step(StreamingLineBuffer_16_buffer_stream[5], StreamingLineBuffer_16_out0_stream_prepad[4], StreamingLineBuffer_16_buffer_stream[7]);
        actor_statuses.push_back(actor_status);
        actor_status = StreamingLineBuffer_16_pixel_6.step(StreamingLineBuffer_16_buffer_stream[4], StreamingLineBuffer_16_out0_stream_prepad[5], StreamingLineBuffer_16_buffer_stream[6]);
        actor_statuses.push_back(actor_status);
        actor_status = StreamingMemory_104.step(StreamingMemory_103_out1_stream, StreamingMemory_104_out0_stream, StreamingMemory_104_out1_stream);
        actor_statuses.push_back(actor_status);
        actor_status = StreamingLineBuffer_16_pixel_5.step(StreamingLineBuffer_16_buffer_stream[3], StreamingLineBuffer_16_out0_stream_prepad[6], StreamingLineBuffer_16_buffer_stream[5]);
        actor_statuses.push_back(actor_status);
        actor_status = StreamingLineBuffer_16_pixel_4.step(StreamingLineBuffer_16_buffer_stream[2], StreamingLineBuffer_16_out0_stream_prepad[7], StreamingLineBuffer_16_buffer_stream[4]);
        actor_statuses.push_back(actor_status);
        actor_status = StreamingMemory_103.step(StreamingMemory_102_out1_stream, StreamingMemory_103_out0_stream, StreamingMemory_103_out1_stream);
        actor_statuses.push_back(actor_status);
        actor_status = StreamingLineBuffer_16_pixel_3.step(StreamingLineBuffer_16_buffer_stream[1], StreamingLineBuffer_16_out0_stream_prepad[8], StreamingLineBuffer_16_buffer_stream[3]);
        actor_statuses.push_back(actor_status);
        actor_status = StreamingLineBuffer_16_pixel_2.step(StreamingLineBuffer_16_buffer_stream[0], StreamingLineBuffer_16_out0_stream_prepad[9], StreamingLineBuffer_16_buffer_stream[2]);
        actor_statuses.push_back(actor_status);
        actor_status = StreamingMemory_102.step(StreamingMemory_101_out1_stream, StreamingMemory_102_out0_stream, StreamingMemory_102_out1_stream);
        actor_statuses.push_back(actor_status);
        actor_status = StreamingLineBuffer_16_pixel_1.step(BandwidthAdjustDecreaseChannels_6_out0_stream[1], StreamingLineBuffer_16_out0_stream_prepad[10], StreamingLineBuffer_16_buffer_stream[1]);
        actor_statuses.push_back(actor_status);
        actor_status = StreamingLineBuffer_16_pixel_0.step(BandwidthAdjustDecreaseChannels_6_out0_stream[0], StreamingLineBuffer_16_out0_stream_prepad[11], StreamingLineBuffer_16_buffer_stream[0]);
        actor_statuses.push_back(actor_status);
        actor_status = StreamingMemory_101.step(StreamingMemory_100_out1_stream, StreamingMemory_101_out0_stream, StreamingMemory_101_out1_stream);
        actor_statuses.push_back(actor_status);
        actor_status = BandwidthAdjustDecreaseChannels_6.step(StreamingConv_10_out0_stream, BandwidthAdjustDecreaseChannels_6_out0_stream);
        actor_statuses.push_back(actor_status);
        actor_status = StreamingMemory_100.step(StreamingMemory_99_out1_stream, StreamingMemory_100_out0_stream, StreamingMemory_100_out1_stream);
        actor_statuses.push_back(actor_status);
        actor_status = StreamingConv_10.step(StreamingLineBuffer_15_out0_stream, StreamingMemory_30_out0_stream, StreamingMemory_31_out0_stream, StreamingConv_10_out0_stream);
        actor_statuses.push_back(actor_status);
        actor_status = StreamingMemory_99.step(StreamingMemory_98_out1_stream, StreamingMemory_99_out0_stream, StreamingMemory_99_out1_stream);
        actor_statuses.push_back(actor_status);
        actor_status = StreamingLineBuffer_15_pixel_1.step(BandwidthAdjustIncreaseChannels_9_out0_stream[0], StreamingLineBuffer_15_out0_stream[0]);
        actor_statuses.push_back(actor_status);
        actor_status = StreamingLineBuffer_15_pixel_0.step(BandwidthAdjustIncreaseChannels_9_out0_stream[1], StreamingLineBuffer_15_out0_stream[1]);
        actor_statuses.push_back(actor_status);
        actor_status = StreamingMemory_98.step(StreamingMemory_97_out1_stream, StreamingMemory_98_out0_stream, StreamingMemory_98_out1_stream);
        actor_statuses.push_back(actor_status);
        actor_status = BandwidthAdjustIncreaseChannels_10.step(TensorDuplicator_2_out1_stream, BandwidthAdjustIncreaseChannels_10_out0_stream);
        actor_statuses.push_back(actor_status);
        actor_status = BandwidthAdjustIncreaseChannels_9.step(TensorDuplicator_2_out0_stream, BandwidthAdjustIncreaseChannels_9_out0_stream);
        actor_statuses.push_back(actor_status);
        actor_status = StreamingMemory_97.step(StreamingMemory_96_out1_stream, StreamingMemory_97_out0_stream, StreamingMemory_97_out1_stream);
        actor_statuses.push_back(actor_status);
        actor_status = TensorDuplicator_2.step(BandwidthAdjustDecreaseChannels_5_out0_stream, TensorDuplicator_2_out0_stream, TensorDuplicator_2_out1_stream);
        actor_statuses.push_back(actor_status);
        actor_status = StreamingMemory_96.step(StreamingMemory_95_out1_stream, StreamingMemory_96_out0_stream, StreamingMemory_96_out1_stream);
        actor_statuses.push_back(actor_status);
        actor_status = BandwidthAdjustDecreaseChannels_5.step(StreamingAdd_1_out0_stream, BandwidthAdjustDecreaseChannels_5_out0_stream);
        actor_statuses.push_back(actor_status);
        actor_status = StreamingMemory_95.step(StreamingMemory_94_out1_stream, StreamingMemory_95_out0_stream, StreamingMemory_95_out1_stream);
        actor_statuses.push_back(actor_status);
        actor_status = StreamingAdd_1.step(BandwidthAdjustIncreaseChannels_7_out0_stream, StreamingConv_9_out0_stream, StreamingAdd_1_out0_stream);
        actor_statuses.push_back(actor_status);
        actor_status = StreamingMemory_94.step(StreamingMemory_93_out1_stream, StreamingMemory_94_out0_stream, StreamingMemory_94_out1_stream);
        actor_statuses.push_back(actor_status);
        actor_status = StreamingConv_9.step(StreamingLineBuffer_14_out0_stream, StreamingMemory_28_out0_stream, StreamingMemory_29_out0_stream, StreamingConv_9_out0_stream);
        actor_statuses.push_back(actor_status);
        actor_status = StreamingMemory_93.step(StreamingMemory_92_out1_stream, StreamingMemory_93_out0_stream, StreamingMemory_93_out1_stream);
        actor_statuses.push_back(actor_status);
        actor_status = StreamingLineBuffer_14_pixel_1.step(BandwidthAdjustIncreaseChannels_8_out0_stream[0], StreamingLineBuffer_14_out0_stream[0]);
        actor_statuses.push_back(actor_status);
        actor_status = StreamingLineBuffer_14_pixel_0.step(BandwidthAdjustIncreaseChannels_8_out0_stream[1], StreamingLineBuffer_14_out0_stream[1]);
        actor_statuses.push_back(actor_status);
        actor_status = StreamingMemory_92.step(StreamingMemory_91_out1_stream, StreamingMemory_92_out0_stream, StreamingMemory_92_out1_stream);
        actor_statuses.push_back(actor_status);
        actor_status = BandwidthAdjustIncreaseChannels_8.step(StreamingDepthwiseConv_4_out0_stream, BandwidthAdjustIncreaseChannels_8_out0_stream);
        actor_statuses.push_back(actor_status);
        actor_status = StreamingMemory_91.step(StreamingMemory_90_out1_stream, StreamingMemory_91_out0_stream, StreamingMemory_91_out1_stream);
        actor_statuses.push_back(actor_status);
        actor_status = StreamingDepthwiseConv_4.step(StreamingLineBuffer_13_out0_stream, StreamingMemory_26_out0_stream, StreamingMemory_27_out0_stream, StreamingDepthwiseConv_4_out0_stream);
        actor_statuses.push_back(actor_status);
        actor_status = StreamingMemory_90.step(StreamingMemory_89_out1_stream, StreamingMemory_90_out0_stream, StreamingMemory_90_out1_stream);
        actor_statuses.push_back(actor_status);
        actor_status = StreamingLineBuffer_13_pad.step(StreamingLineBuffer_13_out0_stream_prepad, StreamingLineBuffer_13_out0_stream);
        actor_statuses.push_back(actor_status);
        actor_status = StreamingMemory_89.step(StreamingMemory_88_out1_stream, StreamingMemory_89_out0_stream, StreamingMemory_89_out1_stream);
        actor_statuses.push_back(actor_status);
        actor_status = StreamingLineBuffer_13_pixel_11.step(StreamingLineBuffer_13_buffer_stream[9], StreamingLineBuffer_13_out0_stream_prepad[0]);
        actor_statuses.push_back(actor_status);
        actor_status = StreamingLineBuffer_13_pixel_10.step(StreamingLineBuffer_13_buffer_stream[8], StreamingLineBuffer_13_out0_stream_prepad[1]);
        actor_statuses.push_back(actor_status);
        actor_status = StreamingMemory_88.step(StreamingMemory_87_out1_stream, StreamingMemory_88_out0_stream, StreamingMemory_88_out1_stream);
        actor_statuses.push_back(actor_status);
        actor_status = StreamingLineBuffer_13_pixel_9.step(StreamingLineBuffer_13_buffer_stream[7], StreamingLineBuffer_13_out0_stream_prepad[2], StreamingLineBuffer_13_buffer_stream[9]);
        actor_statuses.push_back(actor_status);
        actor_status = StreamingLineBuffer_13_pixel_8.step(StreamingLineBuffer_13_buffer_stream[6], StreamingLineBuffer_13_out0_stream_prepad[3], StreamingLineBuffer_13_buffer_stream[8]);
        actor_statuses.push_back(actor_status);
        actor_status = StreamingMemory_87.step(StreamingMemory_86_out1_stream, StreamingMemory_87_out0_stream, StreamingMemory_87_out1_stream);
        actor_statuses.push_back(actor_status);
        actor_status = StreamingLineBuffer_13_pixel_7.step(StreamingLineBuffer_13_buffer_stream[5], StreamingLineBuffer_13_out0_stream_prepad[4], StreamingLineBuffer_13_buffer_stream[7]);
        actor_statuses.push_back(actor_status);
        actor_status = StreamingLineBuffer_13_pixel_6.step(StreamingLineBuffer_13_buffer_stream[4], StreamingLineBuffer_13_out0_stream_prepad[5], StreamingLineBuffer_13_buffer_stream[6]);
        actor_statuses.push_back(actor_status);
        actor_status = StreamingMemory_86.step(StreamingMemory_85_out1_stream, StreamingMemory_86_out0_stream, StreamingMemory_86_out1_stream);
        actor_statuses.push_back(actor_status);
        actor_status = StreamingLineBuffer_13_pixel_5.step(StreamingLineBuffer_13_buffer_stream[3], StreamingLineBuffer_13_out0_stream_prepad[6], StreamingLineBuffer_13_buffer_stream[5]);
        actor_statuses.push_back(actor_status);
        actor_status = StreamingLineBuffer_13_pixel_4.step(StreamingLineBuffer_13_buffer_stream[2], StreamingLineBuffer_13_out0_stream_prepad[7], StreamingLineBuffer_13_buffer_stream[4]);
        actor_statuses.push_back(actor_status);
        actor_status = StreamingMemory_85.step(StreamingMemory_84_out1_stream, StreamingMemory_85_out0_stream, StreamingMemory_85_out1_stream);
        actor_statuses.push_back(actor_status);
        actor_status = StreamingLineBuffer_13_pixel_3.step(StreamingLineBuffer_13_buffer_stream[1], StreamingLineBuffer_13_out0_stream_prepad[8], StreamingLineBuffer_13_buffer_stream[3]);
        actor_statuses.push_back(actor_status);
        actor_status = StreamingLineBuffer_13_pixel_2.step(StreamingLineBuffer_13_buffer_stream[0], StreamingLineBuffer_13_out0_stream_prepad[9], StreamingLineBuffer_13_buffer_stream[2]);
        actor_statuses.push_back(actor_status);
        actor_status = StreamingMemory_84.step(StreamingMemory_83_out1_stream, StreamingMemory_84_out0_stream, StreamingMemory_84_out1_stream);
        actor_statuses.push_back(actor_status);
        actor_status = StreamingLineBuffer_13_pixel_1.step(BandwidthAdjustDecreaseChannels_4_out0_stream[1], StreamingLineBuffer_13_out0_stream_prepad[10], StreamingLineBuffer_13_buffer_stream[1]);
        actor_statuses.push_back(actor_status);
        actor_status = StreamingLineBuffer_13_pixel_0.step(BandwidthAdjustDecreaseChannels_4_out0_stream[0], StreamingLineBuffer_13_out0_stream_prepad[11], StreamingLineBuffer_13_buffer_stream[0]);
        actor_statuses.push_back(actor_status);
        actor_status = StreamingMemory_83.step(StreamingMemory_82_out1_stream, StreamingMemory_83_out0_stream, StreamingMemory_83_out1_stream);
        actor_statuses.push_back(actor_status);
        actor_status = BandwidthAdjustDecreaseChannels_4.step(StreamingConv_8_out0_stream, BandwidthAdjustDecreaseChannels_4_out0_stream);
        actor_statuses.push_back(actor_status);
        actor_status = StreamingMemory_82.step(StreamingMemory_81_out1_stream, StreamingMemory_82_out0_stream, StreamingMemory_82_out1_stream);
        actor_statuses.push_back(actor_status);
        actor_status = StreamingConv_8.step(StreamingLineBuffer_12_out0_stream, StreamingMemory_24_out0_stream, StreamingMemory_25_out0_stream, StreamingConv_8_out0_stream);
        actor_statuses.push_back(actor_status);
        actor_status = StreamingMemory_81.step(StreamingMemory_80_out1_stream, StreamingMemory_81_out0_stream, StreamingMemory_81_out1_stream);
        actor_statuses.push_back(actor_status);
        actor_status = StreamingLineBuffer_12_pixel_1.step(BandwidthAdjustIncreaseChannels_6_out0_stream[0], StreamingLineBuffer_12_out0_stream[0]);
        actor_statuses.push_back(actor_status);
        actor_status = StreamingLineBuffer_12_pixel_0.step(BandwidthAdjustIncreaseChannels_6_out0_stream[1], StreamingLineBuffer_12_out0_stream[1]);
        actor_statuses.push_back(actor_status);
        actor_status = StreamingMemory_80.step(StreamingMemory_79_out1_stream, StreamingMemory_80_out0_stream, StreamingMemory_80_out1_stream);
        actor_statuses.push_back(actor_status);
        actor_status = BandwidthAdjustIncreaseChannels_7.step(TensorDuplicator_1_out1_stream, BandwidthAdjustIncreaseChannels_7_out0_stream);
        actor_statuses.push_back(actor_status);
        actor_status = BandwidthAdjustIncreaseChannels_6.step(TensorDuplicator_1_out0_stream, BandwidthAdjustIncreaseChannels_6_out0_stream);
        actor_statuses.push_back(actor_status);
        actor_status = StreamingMemory_79.step(StreamingMemory_78_out1_stream, StreamingMemory_79_out0_stream, StreamingMemory_79_out1_stream);
        actor_statuses.push_back(actor_status);
        actor_status = TensorDuplicator_1.step(StreamingConv_7_out0_stream, TensorDuplicator_1_out0_stream, TensorDuplicator_1_out1_stream);
        actor_statuses.push_back(actor_status);
        actor_status = StreamingMemory_78.step(StreamingMemory_77_out1_stream, StreamingMemory_78_out0_stream, StreamingMemory_78_out1_stream);
        actor_statuses.push_back(actor_status);
        actor_status = StreamingConv_7.step(StreamingLineBuffer_11_out0_stream, StreamingMemory_22_out0_stream, StreamingMemory_23_out0_stream, StreamingConv_7_out0_stream);
        actor_statuses.push_back(actor_status);
        actor_status = StreamingMemory_77.step(StreamingMemory_76_out1_stream, StreamingMemory_77_out0_stream, StreamingMemory_77_out1_stream);
        actor_statuses.push_back(actor_status);
        actor_status = StreamingLineBuffer_11_pixel_1.step(BandwidthAdjustIncreaseChannels_5_out0_stream[0], StreamingLineBuffer_11_out0_stream[0]);
        actor_statuses.push_back(actor_status);
        actor_status = StreamingLineBuffer_11_pixel_0.step(BandwidthAdjustIncreaseChannels_5_out0_stream[1], StreamingLineBuffer_11_out0_stream[1]);
        actor_statuses.push_back(actor_status);
        actor_status = StreamingMemory_76.step(StreamingMemory_75_out1_stream, StreamingMemory_76_out0_stream, StreamingMemory_76_out1_stream);
        actor_statuses.push_back(actor_status);
        actor_status = BandwidthAdjustIncreaseChannels_5.step(BandwidthAdjustDecreaseChannels_3_out0_stream, BandwidthAdjustIncreaseChannels_5_out0_stream);
        actor_statuses.push_back(actor_status);
        actor_status = StreamingMemory_75.step(StreamingMemory_74_out1_stream, StreamingMemory_75_out0_stream, StreamingMemory_75_out1_stream);
        actor_statuses.push_back(actor_status);
        actor_status = BandwidthAdjustDecreaseChannels_3.step(StreamingDepthwiseConv_3_out0_stream, BandwidthAdjustDecreaseChannels_3_out0_stream);
        actor_statuses.push_back(actor_status);
        actor_status = StreamingMemory_74.step(StreamingMemory_73_out1_stream, StreamingMemory_74_out0_stream, StreamingMemory_74_out1_stream);
        actor_statuses.push_back(actor_status);
        actor_status = StreamingDepthwiseConv_3.step(StreamingLineBuffer_10_out0_stream, StreamingMemory_20_out0_stream, StreamingMemory_21_out0_stream, StreamingDepthwiseConv_3_out0_stream);
        actor_statuses.push_back(actor_status);
        actor_status = StreamingMemory_73.step(StreamingMemory_72_out1_stream, StreamingMemory_73_out0_stream, StreamingMemory_73_out1_stream);
        actor_statuses.push_back(actor_status);
        actor_status = StreamingLineBuffer_10_pad.step(StreamingLineBuffer_10_out0_stream_prepad, StreamingLineBuffer_10_out0_stream);
        actor_statuses.push_back(actor_status);
        actor_status = StreamingMemory_72.step(StreamingMemory_71_out1_stream, StreamingMemory_72_out0_stream, StreamingMemory_72_out1_stream);
        actor_statuses.push_back(actor_status);
        actor_status = StreamingLineBuffer_10_pixel_14.step(StreamingLineBuffer_10_buffer_stream[12], StreamingLineBuffer_10_out0_stream_prepad[0]);
        actor_statuses.push_back(actor_status);
        actor_status = StreamingMemory_71.step(StreamingMemory_70_out1_stream, StreamingMemory_71_out0_stream, StreamingMemory_71_out1_stream);
        actor_statuses.push_back(actor_status);
        actor_status = StreamingLineBuffer_10_pixel_12.step(StreamingLineBuffer_10_buffer_stream[10], StreamingLineBuffer_10_out0_stream_prepad[2], StreamingLineBuffer_10_buffer_stream[12]);
        actor_statuses.push_back(actor_status);
        actor_status = StreamingMemory_70.step(StreamingMemory_69_out1_stream, StreamingMemory_70_out0_stream, StreamingMemory_70_out1_stream);
        actor_statuses.push_back(actor_status);
        actor_status = StreamingLineBuffer_10_pixel_10.step(StreamingLineBuffer_10_buffer_stream[8], StreamingLineBuffer_10_out0_stream_prepad[4], StreamingLineBuffer_10_buffer_stream[10]);
        actor_statuses.push_back(actor_status);
        actor_status = StreamingMemory_69.step(StreamingMemory_68_out1_stream, StreamingMemory_69_out0_stream, StreamingMemory_69_out1_stream);
        actor_statuses.push_back(actor_status);
        actor_status = StreamingLineBuffer_10_pixel_13.step(StreamingLineBuffer_10_buffer_stream[11], StreamingLineBuffer_10_out0_stream_prepad[1]);
        actor_statuses.push_back(actor_status);
        actor_status = StreamingLineBuffer_10_pixel_9.step(StreamingLineBuffer_10_buffer_stream[7], StreamingLineBuffer_10_out0_stream_prepad[5], StreamingLineBuffer_10_buffer_stream[8]);
        actor_statuses.push_back(actor_status);
        actor_status = StreamingMemory_68.step(StreamingMemory_67_out1_stream, StreamingMemory_68_out0_stream, StreamingMemory_68_out1_stream);
        actor_statuses.push_back(actor_status);
        actor_status = StreamingLineBuffer_10_pixel_11.step(StreamingLineBuffer_10_buffer_stream[9], StreamingLineBuffer_10_out0_stream_prepad[3], StreamingLineBuffer_10_buffer_stream[11]);
        actor_statuses.push_back(actor_status);
        actor_status = StreamingLineBuffer_10_pixel_7.step(StreamingLineBuffer_10_buffer_stream[5], StreamingLineBuffer_10_out0_stream_prepad[7], StreamingLineBuffer_10_buffer_stream[7]);
        actor_statuses.push_back(actor_status);
        actor_status = StreamingMemory_67.step(StreamingMemory_66_out1_stream, StreamingMemory_67_out0_stream, StreamingMemory_67_out1_stream);
        actor_statuses.push_back(actor_status);
        actor_status = StreamingLineBuffer_10_pixel_8.step(StreamingLineBuffer_10_buffer_stream[6], StreamingLineBuffer_10_out0_stream_prepad[6], StreamingLineBuffer_10_buffer_stream[9]);
        actor_statuses.push_back(actor_status);
        actor_status = StreamingLineBuffer_10_pixel_5.step(StreamingLineBuffer_10_buffer_stream[3], StreamingLineBuffer_10_out0_stream_prepad[9], StreamingLineBuffer_10_buffer_stream[5]);
        actor_statuses.push_back(actor_status);
        actor_status = StreamingMemory_66.step(StreamingMemory_65_out1_stream, StreamingMemory_66_out0_stream, StreamingMemory_66_out1_stream);
        actor_statuses.push_back(actor_status);
        actor_status = StreamingLineBuffer_10_pixel_6.step(StreamingLineBuffer_10_buffer_stream[4], StreamingLineBuffer_10_out0_stream_prepad[8], StreamingLineBuffer_10_buffer_stream[6]);
        actor_statuses.push_back(actor_status);
        actor_status = StreamingLineBuffer_10_pixel_4.step(StreamingLineBuffer_10_buffer_stream[2], StreamingLineBuffer_10_out0_stream_prepad[10], StreamingLineBuffer_10_buffer_stream[3]);
        actor_statuses.push_back(actor_status);
        actor_status = StreamingMemory_65.step(StreamingMemory_64_out1_stream, StreamingMemory_65_out0_stream, StreamingMemory_65_out1_stream);
        actor_statuses.push_back(actor_status);
        actor_status = StreamingLineBuffer_10_pixel_3.step(StreamingLineBuffer_10_buffer_stream[1], StreamingLineBuffer_10_out0_stream_prepad[11], StreamingLineBuffer_10_buffer_stream[4]);
        actor_statuses.push_back(actor_status);
        actor_status = StreamingLineBuffer_10_pixel_2.step(StreamingLineBuffer_10_buffer_stream[0], StreamingLineBuffer_10_out0_stream_prepad[12], StreamingLineBuffer_10_buffer_stream[2]);
        actor_statuses.push_back(actor_status);
        actor_status = StreamingMemory_64.step(StreamingMemory_63_out1_stream, StreamingMemory_64_out0_stream, StreamingMemory_64_out1_stream);
        actor_statuses.push_back(actor_status);
        actor_status = StreamingLineBuffer_10_pixel_1.step(BandwidthAdjustDecreaseStreams_2_out0_stream[0], StreamingLineBuffer_10_out0_stream_prepad[13], StreamingLineBuffer_10_buffer_stream[1]);
        actor_statuses.push_back(actor_status);
        actor_status = StreamingLineBuffer_10_pixel_0.step(BandwidthAdjustDecreaseStreams_2_out0_stream[1], StreamingLineBuffer_10_out0_stream_prepad[14], StreamingLineBuffer_10_buffer_stream[0]);
        actor_statuses.push_back(actor_status);
        actor_status = StreamingMemory_63.step(StreamingMemory_62_out1_stream, StreamingMemory_63_out0_stream, StreamingMemory_63_out1_stream);
        actor_statuses.push_back(actor_status);
        actor_status = BandwidthAdjustDecreaseStreams_2.step(StreamingConv_6_out0_stream, BandwidthAdjustDecreaseStreams_2_out0_stream);
        actor_statuses.push_back(actor_status);
        actor_status = StreamingMemory_62.step(StreamingMemory_61_out1_stream, StreamingMemory_62_out0_stream, StreamingMemory_62_out1_stream);
        actor_statuses.push_back(actor_status);
        actor_status = StreamingConv_6.step(StreamingLineBuffer_9_out0_stream, StreamingMemory_18_out0_stream, StreamingMemory_19_out0_stream, StreamingConv_6_out0_stream);
        actor_statuses.push_back(actor_status);
        actor_status = StreamingMemory_61.step(StreamingMemory_60_out1_stream, StreamingMemory_61_out0_stream, StreamingMemory_61_out1_stream);
        actor_statuses.push_back(actor_status);
        actor_status = StreamingLineBuffer_9_pixel_3.step(BandwidthAdjustIncreaseStreams_1_out0_stream[0], StreamingLineBuffer_9_out0_stream[0]);
        actor_statuses.push_back(actor_status);
        actor_status = StreamingLineBuffer_9_pixel_2.step(BandwidthAdjustIncreaseStreams_1_out0_stream[1], StreamingLineBuffer_9_out0_stream[1]);
        actor_statuses.push_back(actor_status);
        actor_status = StreamingLineBuffer_9_pixel_1.step(BandwidthAdjustIncreaseStreams_1_out0_stream[2], StreamingLineBuffer_9_out0_stream[2]);
        actor_statuses.push_back(actor_status);
        actor_status = StreamingLineBuffer_9_pixel_0.step(BandwidthAdjustIncreaseStreams_1_out0_stream[3], StreamingLineBuffer_9_out0_stream[3]);
        actor_statuses.push_back(actor_status);
        actor_status = StreamingMemory_60.step(StreamingMemory_59_out1_stream, StreamingMemory_60_out0_stream, StreamingMemory_60_out1_stream);
        actor_statuses.push_back(actor_status);
        actor_status = BandwidthAdjustIncreaseStreams_1.step(BandwidthAdjustIncreaseChannels_4_out0_stream, BandwidthAdjustIncreaseStreams_1_out0_stream);
        actor_statuses.push_back(actor_status);
        actor_status = StreamingMemory_59.step(StreamingMemory_58_out1_stream, StreamingMemory_59_out0_stream, StreamingMemory_59_out1_stream);
        actor_statuses.push_back(actor_status);
        actor_status = BandwidthAdjustIncreaseChannels_4.step(BandwidthAdjustDecreaseChannels_2_out0_stream, BandwidthAdjustIncreaseChannels_4_out0_stream);
        actor_statuses.push_back(actor_status);
        actor_status = StreamingMemory_58.step(StreamingMemory_57_out1_stream, StreamingMemory_58_out0_stream, StreamingMemory_58_out1_stream);
        actor_statuses.push_back(actor_status);
        actor_status = BandwidthAdjustDecreaseChannels_2.step(StreamingAdd_0_out0_stream, BandwidthAdjustDecreaseChannels_2_out0_stream);
        actor_statuses.push_back(actor_status);
        actor_status = StreamingMemory_57.step(StreamingMemory_56_out1_stream, StreamingMemory_57_out0_stream, StreamingMemory_57_out1_stream);
        actor_statuses.push_back(actor_status);
        actor_status = StreamingAdd_0.step(BandwidthAdjustDecreaseStreams_0_out0_stream, StreamingConv_5_out0_stream, StreamingAdd_0_out0_stream);
        actor_statuses.push_back(actor_status);
        actor_status = StreamingMemory_56.step(StreamingMemory_55_out1_stream, StreamingMemory_56_out0_stream, StreamingMemory_56_out1_stream);
        actor_statuses.push_back(actor_status);
        actor_status = StreamingConv_5.step(StreamingLineBuffer_8_out0_stream, StreamingMemory_16_out0_stream, StreamingMemory_17_out0_stream, StreamingConv_5_out0_stream);
        actor_statuses.push_back(actor_status);
        actor_status = StreamingMemory_55.step(StreamingMemory_54_out1_stream, StreamingMemory_55_out0_stream, StreamingMemory_55_out1_stream);
        actor_statuses.push_back(actor_status);
        actor_status = StreamingLineBuffer_8_pixel_1.step(BandwidthAdjustDecreaseChannels_1_out0_stream[0], StreamingLineBuffer_8_out0_stream[0]);
        actor_statuses.push_back(actor_status);
        actor_status = StreamingLineBuffer_8_pixel_0.step(BandwidthAdjustDecreaseChannels_1_out0_stream[1], StreamingLineBuffer_8_out0_stream[1]);
        actor_statuses.push_back(actor_status);
        actor_status = StreamingMemory_54.step(StreamingMemory_53_out1_stream, StreamingMemory_54_out0_stream, StreamingMemory_54_out1_stream);
        actor_statuses.push_back(actor_status);
        actor_status = BandwidthAdjustDecreaseChannels_1.step(BandwidthAdjustIncreaseChannels_3_out0_stream, BandwidthAdjustDecreaseChannels_1_out0_stream);
        actor_statuses.push_back(actor_status);
        actor_status = StreamingMemory_53.step(StreamingMemory_52_out1_stream, StreamingMemory_53_out0_stream, StreamingMemory_53_out1_stream);
        actor_statuses.push_back(actor_status);
        actor_status = BandwidthAdjustIncreaseChannels_3.step(StreamingDepthwiseConv_2_out0_stream, BandwidthAdjustIncreaseChannels_3_out0_stream);
        actor_statuses.push_back(actor_status);
        actor_status = StreamingMemory_52.step(StreamingMemory_51_out1_stream, StreamingMemory_52_out0_stream, StreamingMemory_52_out1_stream);
        actor_statuses.push_back(actor_status);
        actor_status = StreamingDepthwiseConv_2.step(StreamingLineBuffer_7_out0_stream, StreamingMemory_14_out0_stream, StreamingMemory_15_out0_stream, StreamingDepthwiseConv_2_out0_stream);
        actor_statuses.push_back(actor_status);
        actor_status = StreamingMemory_51.step(StreamingMemory_50_out1_stream, StreamingMemory_51_out0_stream, StreamingMemory_51_out1_stream);
        actor_statuses.push_back(actor_status);
        actor_status = StreamingLineBuffer_7_pad.step(StreamingLineBuffer_7_out0_stream_prepad, StreamingLineBuffer_7_out0_stream);
        actor_statuses.push_back(actor_status);
        actor_status = StreamingMemory_50.step(StreamingMemory_49_out1_stream, StreamingMemory_50_out0_stream, StreamingMemory_50_out1_stream);
        actor_statuses.push_back(actor_status);
        actor_status = StreamingLineBuffer_7_pixel_11.step(StreamingLineBuffer_7_buffer_stream[9], StreamingLineBuffer_7_out0_stream_prepad[0]);
        actor_statuses.push_back(actor_status);
        actor_status = StreamingLineBuffer_7_pixel_10.step(StreamingLineBuffer_7_buffer_stream[8], StreamingLineBuffer_7_out0_stream_prepad[1]);
        actor_statuses.push_back(actor_status);
        actor_status = StreamingMemory_49.step(StreamingMemory_48_out1_stream, StreamingMemory_49_out0_stream, StreamingMemory_49_out1_stream);
        actor_statuses.push_back(actor_status);
        actor_status = StreamingLineBuffer_7_pixel_9.step(StreamingLineBuffer_7_buffer_stream[7], StreamingLineBuffer_7_out0_stream_prepad[2], StreamingLineBuffer_7_buffer_stream[9]);
        actor_statuses.push_back(actor_status);
        actor_status = StreamingLineBuffer_7_pixel_8.step(StreamingLineBuffer_7_buffer_stream[6], StreamingLineBuffer_7_out0_stream_prepad[3], StreamingLineBuffer_7_buffer_stream[8]);
        actor_statuses.push_back(actor_status);
        actor_status = StreamingMemory_48.step(StreamingMemory_47_out1_stream, StreamingMemory_48_out0_stream, StreamingMemory_48_out1_stream);
        actor_statuses.push_back(actor_status);
        actor_status = StreamingLineBuffer_7_pixel_7.step(StreamingLineBuffer_7_buffer_stream[5], StreamingLineBuffer_7_out0_stream_prepad[4], StreamingLineBuffer_7_buffer_stream[7]);
        actor_statuses.push_back(actor_status);
        actor_status = StreamingLineBuffer_7_pixel_6.step(StreamingLineBuffer_7_buffer_stream[4], StreamingLineBuffer_7_out0_stream_prepad[5], StreamingLineBuffer_7_buffer_stream[6]);
        actor_statuses.push_back(actor_status);
        actor_status = StreamingMemory_47.step(StreamingMemory_46_out1_stream, StreamingMemory_47_out0_stream, StreamingMemory_47_out1_stream);
        actor_statuses.push_back(actor_status);
        actor_status = StreamingLineBuffer_7_pixel_5.step(StreamingLineBuffer_7_buffer_stream[3], StreamingLineBuffer_7_out0_stream_prepad[6], StreamingLineBuffer_7_buffer_stream[5]);
        actor_statuses.push_back(actor_status);
        actor_status = StreamingLineBuffer_7_pixel_4.step(StreamingLineBuffer_7_buffer_stream[2], StreamingLineBuffer_7_out0_stream_prepad[7], StreamingLineBuffer_7_buffer_stream[4]);
        actor_statuses.push_back(actor_status);
        actor_status = StreamingMemory_46.step(StreamingMemory_45_out1_stream, StreamingMemory_46_out0_stream, StreamingMemory_46_out1_stream);
        actor_statuses.push_back(actor_status);
        actor_status = StreamingLineBuffer_7_pixel_3.step(StreamingLineBuffer_7_buffer_stream[1], StreamingLineBuffer_7_out0_stream_prepad[8], StreamingLineBuffer_7_buffer_stream[3]);
        actor_statuses.push_back(actor_status);
        actor_status = StreamingLineBuffer_7_pixel_2.step(StreamingLineBuffer_7_buffer_stream[0], StreamingLineBuffer_7_out0_stream_prepad[9], StreamingLineBuffer_7_buffer_stream[2]);
        actor_statuses.push_back(actor_status);
        actor_status = StreamingMemory_45.step(StreamingMemory_44_out1_stream, StreamingMemory_45_out0_stream, StreamingMemory_45_out1_stream);
        actor_statuses.push_back(actor_status);
        actor_status = StreamingLineBuffer_7_pixel_1.step(BandwidthAdjustDecreaseStreams_1_out0_stream[1], StreamingLineBuffer_7_out0_stream_prepad[10], StreamingLineBuffer_7_buffer_stream[1]);
        actor_statuses.push_back(actor_status);
        actor_status = StreamingLineBuffer_7_pixel_0.step(BandwidthAdjustDecreaseStreams_1_out0_stream[0], StreamingLineBuffer_7_out0_stream_prepad[11], StreamingLineBuffer_7_buffer_stream[0]);
        actor_statuses.push_back(actor_status);
        actor_status = StreamingMemory_44.step(StreamingMemory_43_out1_stream, StreamingMemory_44_out0_stream, StreamingMemory_44_out1_stream);
        actor_statuses.push_back(actor_status);
        actor_status = BandwidthAdjustDecreaseStreams_1.step(StreamingConv_4_out0_stream, BandwidthAdjustDecreaseStreams_1_out0_stream);
        actor_statuses.push_back(actor_status);
        actor_status = StreamingMemory_43.step(StreamingMemory_42_out1_stream, StreamingMemory_43_out0_stream, StreamingMemory_43_out1_stream);
        actor_statuses.push_back(actor_status);
        actor_status = StreamingConv_4.step(StreamingLineBuffer_6_out0_stream, StreamingMemory_12_out0_stream, StreamingMemory_13_out0_stream, StreamingConv_4_out0_stream);
        actor_statuses.push_back(actor_status);
        actor_status = StreamingMemory_42.step(StreamingMemory_41_out1_stream, StreamingMemory_42_out0_stream, StreamingMemory_42_out1_stream);
        actor_statuses.push_back(actor_status);
        actor_status = StreamingLineBuffer_6_pixel_3.step(BandwidthAdjustIncreaseChannels_2_out0_stream[0], StreamingLineBuffer_6_out0_stream[0]);
        actor_statuses.push_back(actor_status);
        actor_status = StreamingLineBuffer_6_pixel_2.step(BandwidthAdjustIncreaseChannels_2_out0_stream[1], StreamingLineBuffer_6_out0_stream[1]);
        actor_statuses.push_back(actor_status);
        actor_status = StreamingLineBuffer_6_pixel_1.step(BandwidthAdjustIncreaseChannels_2_out0_stream[2], StreamingLineBuffer_6_out0_stream[2]);
        actor_statuses.push_back(actor_status);
        actor_status = StreamingLineBuffer_6_pixel_0.step(BandwidthAdjustIncreaseChannels_2_out0_stream[3], StreamingLineBuffer_6_out0_stream[3]);
        actor_statuses.push_back(actor_status);
        actor_status = StreamingMemory_41.step(StreamingMemory_40_out1_stream, StreamingMemory_41_out0_stream, StreamingMemory_41_out1_stream);
        actor_statuses.push_back(actor_status);
        actor_status = BandwidthAdjustIncreaseChannels_2.step(BandwidthAdjustDecreaseChannels_0_out0_stream, BandwidthAdjustIncreaseChannels_2_out0_stream);
        actor_statuses.push_back(actor_status);
        actor_status = StreamingMemory_40.step(StreamingMemory_39_out1_stream, StreamingMemory_40_out0_stream, StreamingMemory_40_out1_stream);
        actor_statuses.push_back(actor_status);
        actor_status = BandwidthAdjustDecreaseStreams_0.step(TensorDuplicator_0_out1_stream, BandwidthAdjustDecreaseStreams_0_out0_stream);
        actor_statuses.push_back(actor_status);
        actor_status = BandwidthAdjustDecreaseChannels_0.step(TensorDuplicator_0_out0_stream, BandwidthAdjustDecreaseChannels_0_out0_stream);
        actor_statuses.push_back(actor_status);
        actor_status = StreamingMemory_39.step(StreamingMemory_38_out1_stream, StreamingMemory_39_out0_stream, StreamingMemory_39_out1_stream);
        actor_statuses.push_back(actor_status);
        actor_status = TensorDuplicator_0.step(StreamingConv_3_out0_stream, TensorDuplicator_0_out0_stream, TensorDuplicator_0_out1_stream);
        actor_statuses.push_back(actor_status);
        actor_status = StreamingMemory_38.step(StreamingMemory_37_out1_stream, StreamingMemory_38_out0_stream, StreamingMemory_38_out1_stream);
        actor_statuses.push_back(actor_status);
        actor_status = StreamingConv_3.step(StreamingLineBuffer_5_out0_stream, StreamingMemory_10_out0_stream, StreamingMemory_11_out0_stream, StreamingConv_3_out0_stream);
        actor_statuses.push_back(actor_status);
        actor_status = StreamingMemory_37.step(StreamingMemory_36_out1_stream, StreamingMemory_37_out0_stream, StreamingMemory_37_out1_stream);
        actor_statuses.push_back(actor_status);
        actor_status = StreamingLineBuffer_5_pixel_3.step(BandwidthAdjustIncreaseStreams_0_out0_stream[0], StreamingLineBuffer_5_out0_stream[0]);
        actor_statuses.push_back(actor_status);
        actor_status = StreamingLineBuffer_5_pixel_2.step(BandwidthAdjustIncreaseStreams_0_out0_stream[1], StreamingLineBuffer_5_out0_stream[1]);
        actor_statuses.push_back(actor_status);
        actor_status = StreamingLineBuffer_5_pixel_1.step(BandwidthAdjustIncreaseStreams_0_out0_stream[2], StreamingLineBuffer_5_out0_stream[2]);
        actor_statuses.push_back(actor_status);
        actor_status = StreamingLineBuffer_5_pixel_0.step(BandwidthAdjustIncreaseStreams_0_out0_stream[3], StreamingLineBuffer_5_out0_stream[3]);
        actor_statuses.push_back(actor_status);
        actor_status = StreamingMemory_36.step(StreamingMemory_35_out1_stream, StreamingMemory_36_out0_stream, StreamingMemory_36_out1_stream);
        actor_statuses.push_back(actor_status);
        actor_status = BandwidthAdjustIncreaseStreams_0.step(StreamingDepthwiseConv_1_out0_stream, BandwidthAdjustIncreaseStreams_0_out0_stream);
        actor_statuses.push_back(actor_status);
        actor_status = StreamingMemory_35.step(StreamingMemory_34_out1_stream, StreamingMemory_35_out0_stream, StreamingMemory_35_out1_stream);
        actor_statuses.push_back(actor_status);
        actor_status = StreamingDepthwiseConv_1.step(StreamingLineBuffer_4_out0_stream, StreamingMemory_8_out0_stream, StreamingMemory_9_out0_stream, StreamingDepthwiseConv_1_out0_stream);
        actor_statuses.push_back(actor_status);
        actor_status = StreamingMemory_34.step(StreamingMemory_33_out1_stream, StreamingMemory_34_out0_stream, StreamingMemory_34_out1_stream);
        actor_statuses.push_back(actor_status);
        actor_status = StreamingLineBuffer_4_pad.step(StreamingLineBuffer_4_out0_stream_prepad, StreamingLineBuffer_4_out0_stream);
        actor_statuses.push_back(actor_status);
        actor_status = StreamingMemory_33.step(StreamingMemory_32_out1_stream, StreamingMemory_33_out0_stream, StreamingMemory_33_out1_stream);
        actor_statuses.push_back(actor_status);
        actor_status = StreamingLineBuffer_4_pixel_14.step(StreamingLineBuffer_4_buffer_stream[12], StreamingLineBuffer_4_out0_stream_prepad[0]);
        actor_statuses.push_back(actor_status);
        actor_status = StreamingMemory_32.step(StreamingMemory_31_out1_stream, StreamingMemory_32_out0_stream, StreamingMemory_32_out1_stream);
        actor_statuses.push_back(actor_status);
        actor_status = StreamingLineBuffer_4_pixel_12.step(StreamingLineBuffer_4_buffer_stream[10], StreamingLineBuffer_4_out0_stream_prepad[2], StreamingLineBuffer_4_buffer_stream[12]);
        actor_statuses.push_back(actor_status);
        actor_status = StreamingMemory_31.step(StreamingMemory_30_out1_stream, StreamingMemory_31_out0_stream, StreamingMemory_31_out1_stream);
        actor_statuses.push_back(actor_status);
        actor_status = StreamingLineBuffer_4_pixel_10.step(StreamingLineBuffer_4_buffer_stream[8], StreamingLineBuffer_4_out0_stream_prepad[4], StreamingLineBuffer_4_buffer_stream[10]);
        actor_statuses.push_back(actor_status);
        actor_status = StreamingMemory_30.step(StreamingMemory_29_out1_stream, StreamingMemory_30_out0_stream, StreamingMemory_30_out1_stream);
        actor_statuses.push_back(actor_status);
        actor_status = StreamingLineBuffer_4_pixel_13.step(StreamingLineBuffer_4_buffer_stream[11], StreamingLineBuffer_4_out0_stream_prepad[1]);
        actor_statuses.push_back(actor_status);
        actor_status = StreamingLineBuffer_4_pixel_9.step(StreamingLineBuffer_4_buffer_stream[7], StreamingLineBuffer_4_out0_stream_prepad[5], StreamingLineBuffer_4_buffer_stream[8]);
        actor_statuses.push_back(actor_status);
        actor_status = StreamingMemory_29.step(StreamingMemory_28_out1_stream, StreamingMemory_29_out0_stream, StreamingMemory_29_out1_stream);
        actor_statuses.push_back(actor_status);
        actor_status = StreamingLineBuffer_4_pixel_11.step(StreamingLineBuffer_4_buffer_stream[9], StreamingLineBuffer_4_out0_stream_prepad[3], StreamingLineBuffer_4_buffer_stream[11]);
        actor_statuses.push_back(actor_status);
        actor_status = StreamingLineBuffer_4_pixel_7.step(StreamingLineBuffer_4_buffer_stream[5], StreamingLineBuffer_4_out0_stream_prepad[7], StreamingLineBuffer_4_buffer_stream[7]);
        actor_statuses.push_back(actor_status);
        actor_status = StreamingMemory_28.step(StreamingMemory_27_out1_stream, StreamingMemory_28_out0_stream, StreamingMemory_28_out1_stream);
        actor_statuses.push_back(actor_status);
        actor_status = StreamingLineBuffer_4_pixel_8.step(StreamingLineBuffer_4_buffer_stream[6], StreamingLineBuffer_4_out0_stream_prepad[6], StreamingLineBuffer_4_buffer_stream[9]);
        actor_statuses.push_back(actor_status);
        actor_status = StreamingLineBuffer_4_pixel_5.step(StreamingLineBuffer_4_buffer_stream[3], StreamingLineBuffer_4_out0_stream_prepad[9], StreamingLineBuffer_4_buffer_stream[5]);
        actor_statuses.push_back(actor_status);
        actor_status = StreamingMemory_27.step(StreamingMemory_26_out1_stream, StreamingMemory_27_out0_stream, StreamingMemory_27_out1_stream);
        actor_statuses.push_back(actor_status);
        actor_status = StreamingLineBuffer_4_pixel_6.step(StreamingLineBuffer_4_buffer_stream[4], StreamingLineBuffer_4_out0_stream_prepad[8], StreamingLineBuffer_4_buffer_stream[6]);
        actor_statuses.push_back(actor_status);
        actor_status = StreamingLineBuffer_4_pixel_4.step(StreamingLineBuffer_4_buffer_stream[2], StreamingLineBuffer_4_out0_stream_prepad[10], StreamingLineBuffer_4_buffer_stream[3]);
        actor_statuses.push_back(actor_status);
        actor_status = StreamingMemory_26.step(StreamingMemory_25_out1_stream, StreamingMemory_26_out0_stream, StreamingMemory_26_out1_stream);
        actor_statuses.push_back(actor_status);
        actor_status = StreamingLineBuffer_4_pixel_3.step(StreamingLineBuffer_4_buffer_stream[1], StreamingLineBuffer_4_out0_stream_prepad[11], StreamingLineBuffer_4_buffer_stream[4]);
        actor_statuses.push_back(actor_status);
        actor_status = StreamingLineBuffer_4_pixel_2.step(StreamingLineBuffer_4_buffer_stream[0], StreamingLineBuffer_4_out0_stream_prepad[12], StreamingLineBuffer_4_buffer_stream[2]);
        actor_statuses.push_back(actor_status);
        actor_status = StreamingMemory_25.step(StreamingMemory_24_out1_stream, StreamingMemory_25_out0_stream, StreamingMemory_25_out1_stream);
        actor_statuses.push_back(actor_status);
        actor_status = StreamingLineBuffer_4_pixel_1.step(StreamingConv_2_out0_stream[0], StreamingLineBuffer_4_out0_stream_prepad[13], StreamingLineBuffer_4_buffer_stream[1]);
        actor_statuses.push_back(actor_status);
        actor_status = StreamingLineBuffer_4_pixel_0.step(StreamingConv_2_out0_stream[1], StreamingLineBuffer_4_out0_stream_prepad[14], StreamingLineBuffer_4_buffer_stream[0]);
        actor_statuses.push_back(actor_status);
        actor_status = StreamingMemory_24.step(StreamingMemory_23_out1_stream, StreamingMemory_24_out0_stream, StreamingMemory_24_out1_stream);
        actor_statuses.push_back(actor_status);
        actor_status = StreamingConv_2.step(StreamingLineBuffer_3_out0_stream, StreamingMemory_6_out0_stream, StreamingMemory_7_out0_stream, StreamingConv_2_out0_stream);
        actor_statuses.push_back(actor_status);
        actor_status = StreamingMemory_23.step(StreamingMemory_22_out1_stream, StreamingMemory_23_out0_stream, StreamingMemory_23_out1_stream);
        actor_statuses.push_back(actor_status);
        actor_status = StreamingLineBuffer_3_pixel_1.step(BandwidthAdjustIncreaseChannels_1_out0_stream[0], StreamingLineBuffer_3_out0_stream[0]);
        actor_statuses.push_back(actor_status);
        actor_status = StreamingLineBuffer_3_pixel_0.step(BandwidthAdjustIncreaseChannels_1_out0_stream[1], StreamingLineBuffer_3_out0_stream[1]);
        actor_statuses.push_back(actor_status);
        actor_status = StreamingMemory_22.step(StreamingMemory_21_out1_stream, StreamingMemory_22_out0_stream, StreamingMemory_22_out1_stream);
        actor_statuses.push_back(actor_status);
        actor_status = BandwidthAdjustIncreaseChannels_1.step(StreamingConv_1_out0_stream, BandwidthAdjustIncreaseChannels_1_out0_stream);
        actor_statuses.push_back(actor_status);
        actor_status = StreamingMemory_21.step(StreamingMemory_20_out1_stream, StreamingMemory_21_out0_stream, StreamingMemory_21_out1_stream);
        actor_statuses.push_back(actor_status);
        actor_status = StreamingConv_1.step(StreamingLineBuffer_2_out0_stream, StreamingMemory_4_out0_stream, StreamingMemory_5_out0_stream, StreamingConv_1_out0_stream);
        actor_statuses.push_back(actor_status);
        actor_status = StreamingMemory_20.step(StreamingMemory_19_out1_stream, StreamingMemory_20_out0_stream, StreamingMemory_20_out1_stream);
        actor_statuses.push_back(actor_status);
        actor_status = StreamingLineBuffer_2_pixel_1.step(BandwidthAdjustIncreaseChannels_0_out0_stream[0], StreamingLineBuffer_2_out0_stream[0]);
        actor_statuses.push_back(actor_status);
        actor_status = StreamingLineBuffer_2_pixel_0.step(BandwidthAdjustIncreaseChannels_0_out0_stream[1], StreamingLineBuffer_2_out0_stream[1]);
        actor_statuses.push_back(actor_status);
        actor_status = StreamingMemory_19.step(StreamingMemory_18_out1_stream, StreamingMemory_19_out0_stream, StreamingMemory_19_out1_stream);
        actor_statuses.push_back(actor_status);
        actor_status = BandwidthAdjustIncreaseChannels_0.step(StreamingDepthwiseConv_0_out0_stream, BandwidthAdjustIncreaseChannels_0_out0_stream);
        actor_statuses.push_back(actor_status);
        actor_status = StreamingMemory_18.step(StreamingMemory_17_out1_stream, StreamingMemory_18_out0_stream, StreamingMemory_18_out1_stream);
        actor_statuses.push_back(actor_status);
        actor_status = StreamingDepthwiseConv_0.step(StreamingLineBuffer_1_out0_stream, StreamingMemory_2_out0_stream, StreamingMemory_3_out0_stream, StreamingDepthwiseConv_0_out0_stream);
        actor_statuses.push_back(actor_status);
        actor_status = StreamingMemory_17.step(StreamingMemory_16_out1_stream, StreamingMemory_17_out0_stream, StreamingMemory_17_out1_stream);
        actor_statuses.push_back(actor_status);
        actor_status = StreamingLineBuffer_1_pad.step(StreamingLineBuffer_1_out0_stream_prepad, StreamingLineBuffer_1_out0_stream);
        actor_statuses.push_back(actor_status);
        actor_status = StreamingMemory_16.step(StreamingMemory_15_out1_stream, StreamingMemory_16_out0_stream, StreamingMemory_16_out1_stream);
        actor_statuses.push_back(actor_status);
        actor_status = StreamingLineBuffer_1_pixel_11.step(StreamingLineBuffer_1_buffer_stream[9], StreamingLineBuffer_1_out0_stream_prepad[0]);
        actor_statuses.push_back(actor_status);
        actor_status = StreamingLineBuffer_1_pixel_10.step(StreamingLineBuffer_1_buffer_stream[8], StreamingLineBuffer_1_out0_stream_prepad[1]);
        actor_statuses.push_back(actor_status);
        actor_status = StreamingMemory_15.step(StreamingMemory_14_out1_stream, StreamingMemory_15_out0_stream, StreamingMemory_15_out1_stream);
        actor_statuses.push_back(actor_status);
        actor_status = StreamingLineBuffer_1_pixel_9.step(StreamingLineBuffer_1_buffer_stream[7], StreamingLineBuffer_1_out0_stream_prepad[2], StreamingLineBuffer_1_buffer_stream[9]);
        actor_statuses.push_back(actor_status);
        actor_status = StreamingLineBuffer_1_pixel_8.step(StreamingLineBuffer_1_buffer_stream[6], StreamingLineBuffer_1_out0_stream_prepad[3], StreamingLineBuffer_1_buffer_stream[8]);
        actor_statuses.push_back(actor_status);
        actor_status = StreamingMemory_14.step(StreamingMemory_13_out1_stream, StreamingMemory_14_out0_stream, StreamingMemory_14_out1_stream);
        actor_statuses.push_back(actor_status);
        actor_status = StreamingLineBuffer_1_pixel_7.step(StreamingLineBuffer_1_buffer_stream[5], StreamingLineBuffer_1_out0_stream_prepad[4], StreamingLineBuffer_1_buffer_stream[7]);
        actor_statuses.push_back(actor_status);
        actor_status = StreamingLineBuffer_1_pixel_6.step(StreamingLineBuffer_1_buffer_stream[4], StreamingLineBuffer_1_out0_stream_prepad[5], StreamingLineBuffer_1_buffer_stream[6]);
        actor_statuses.push_back(actor_status);
        actor_status = StreamingMemory_13.step(StreamingMemory_12_out1_stream, StreamingMemory_13_out0_stream, StreamingMemory_13_out1_stream);
        actor_statuses.push_back(actor_status);
        actor_status = StreamingLineBuffer_1_pixel_5.step(StreamingLineBuffer_1_buffer_stream[3], StreamingLineBuffer_1_out0_stream_prepad[6], StreamingLineBuffer_1_buffer_stream[5]);
        actor_statuses.push_back(actor_status);
        actor_status = StreamingLineBuffer_1_pixel_4.step(StreamingLineBuffer_1_buffer_stream[2], StreamingLineBuffer_1_out0_stream_prepad[7], StreamingLineBuffer_1_buffer_stream[4]);
        actor_statuses.push_back(actor_status);
        actor_status = StreamingMemory_12.step(StreamingMemory_11_out1_stream, StreamingMemory_12_out0_stream, StreamingMemory_12_out1_stream);
        actor_statuses.push_back(actor_status);
        actor_status = StreamingLineBuffer_1_pixel_3.step(StreamingLineBuffer_1_buffer_stream[1], StreamingLineBuffer_1_out0_stream_prepad[8], StreamingLineBuffer_1_buffer_stream[3]);
        actor_statuses.push_back(actor_status);
        actor_status = StreamingLineBuffer_1_pixel_2.step(StreamingLineBuffer_1_buffer_stream[0], StreamingLineBuffer_1_out0_stream_prepad[9], StreamingLineBuffer_1_buffer_stream[2]);
        actor_statuses.push_back(actor_status);
        actor_status = StreamingMemory_11.step(StreamingMemory_10_out1_stream, StreamingMemory_11_out0_stream, StreamingMemory_11_out1_stream);
        actor_statuses.push_back(actor_status);
        actor_status = StreamingLineBuffer_1_pixel_1.step(StreamingConv_0_out0_stream[1], StreamingLineBuffer_1_out0_stream_prepad[10], StreamingLineBuffer_1_buffer_stream[1]);
        actor_statuses.push_back(actor_status);
        actor_status = StreamingLineBuffer_1_pixel_0.step(StreamingConv_0_out0_stream[0], StreamingLineBuffer_1_out0_stream_prepad[11], StreamingLineBuffer_1_buffer_stream[0]);
        actor_statuses.push_back(actor_status);
        actor_status = StreamingMemory_10.step(StreamingMemory_9_out1_stream, StreamingMemory_10_out0_stream, StreamingMemory_10_out1_stream);
        actor_statuses.push_back(actor_status);
        actor_status = StreamingConv_0.step(StreamingLineBuffer_0_out0_stream, StreamingMemory_0_out0_stream, StreamingMemory_1_out0_stream, StreamingConv_0_out0_stream);
        actor_statuses.push_back(actor_status);
        actor_status = StreamingMemory_9.step(StreamingMemory_8_out1_stream, StreamingMemory_9_out0_stream, StreamingMemory_9_out1_stream);
        actor_statuses.push_back(actor_status);
        actor_status = StreamingLineBuffer_0_pad.step(StreamingLineBuffer_0_out0_stream_prepad, StreamingLineBuffer_0_out0_stream);
        actor_statuses.push_back(actor_status);
        actor_status = StreamingMemory_8.step(StreamingMemory_7_out1_stream, StreamingMemory_8_out0_stream, StreamingMemory_8_out1_stream);
        actor_statuses.push_back(actor_status);
        actor_status = StreamingLineBuffer_0_pixel_14.step(StreamingLineBuffer_0_buffer_stream[12], StreamingLineBuffer_0_out0_stream_prepad[0]);
        actor_statuses.push_back(actor_status);
        actor_status = StreamingMemory_7.step(StreamingMemory_6_out1_stream, StreamingMemory_7_out0_stream, StreamingMemory_7_out1_stream);
        actor_statuses.push_back(actor_status);
        actor_status = StreamingLineBuffer_0_pixel_12.step(StreamingLineBuffer_0_buffer_stream[10], StreamingLineBuffer_0_out0_stream_prepad[2], StreamingLineBuffer_0_buffer_stream[12]);
        actor_statuses.push_back(actor_status);
        actor_status = StreamingMemory_6.step(StreamingMemory_5_out1_stream, StreamingMemory_6_out0_stream, StreamingMemory_6_out1_stream);
        actor_statuses.push_back(actor_status);
        actor_status = StreamingLineBuffer_0_pixel_10.step(StreamingLineBuffer_0_buffer_stream[8], StreamingLineBuffer_0_out0_stream_prepad[4], StreamingLineBuffer_0_buffer_stream[10]);
        actor_statuses.push_back(actor_status);
        actor_status = StreamingMemory_5.step(StreamingMemory_4_out1_stream, StreamingMemory_5_out0_stream, StreamingMemory_5_out1_stream);
        actor_statuses.push_back(actor_status);
        actor_status = StreamingLineBuffer_0_pixel_13.step(StreamingLineBuffer_0_buffer_stream[11], StreamingLineBuffer_0_out0_stream_prepad[1]);
        actor_statuses.push_back(actor_status);
        actor_status = StreamingLineBuffer_0_pixel_9.step(StreamingLineBuffer_0_buffer_stream[7], StreamingLineBuffer_0_out0_stream_prepad[5], StreamingLineBuffer_0_buffer_stream[8]);
        actor_statuses.push_back(actor_status);
        actor_status = StreamingMemory_4.step(StreamingMemory_3_out1_stream, StreamingMemory_4_out0_stream, StreamingMemory_4_out1_stream);
        actor_statuses.push_back(actor_status);
        actor_status = StreamingLineBuffer_0_pixel_11.step(StreamingLineBuffer_0_buffer_stream[9], StreamingLineBuffer_0_out0_stream_prepad[3], StreamingLineBuffer_0_buffer_stream[11]);
        actor_statuses.push_back(actor_status);
        actor_status = StreamingLineBuffer_0_pixel_7.step(StreamingLineBuffer_0_buffer_stream[5], StreamingLineBuffer_0_out0_stream_prepad[7], StreamingLineBuffer_0_buffer_stream[7]);
        actor_statuses.push_back(actor_status);
        actor_status = StreamingMemory_3.step(StreamingMemory_2_out1_stream, StreamingMemory_3_out0_stream, StreamingMemory_3_out1_stream);
        actor_statuses.push_back(actor_status);
        actor_status = StreamingLineBuffer_0_pixel_8.step(StreamingLineBuffer_0_buffer_stream[6], StreamingLineBuffer_0_out0_stream_prepad[6], StreamingLineBuffer_0_buffer_stream[9]);
        actor_statuses.push_back(actor_status);
        actor_status = StreamingLineBuffer_0_pixel_5.step(StreamingLineBuffer_0_buffer_stream[3], StreamingLineBuffer_0_out0_stream_prepad[9], StreamingLineBuffer_0_buffer_stream[5]);
        actor_statuses.push_back(actor_status);
        actor_status = StreamingMemory_2.step(StreamingMemory_1_out1_stream, StreamingMemory_2_out0_stream, StreamingMemory_2_out1_stream);
        actor_statuses.push_back(actor_status);
        actor_status = StreamingLineBuffer_0_pixel_6.step(StreamingLineBuffer_0_buffer_stream[4], StreamingLineBuffer_0_out0_stream_prepad[8], StreamingLineBuffer_0_buffer_stream[6]);
        actor_statuses.push_back(actor_status);
        actor_status = StreamingLineBuffer_0_pixel_4.step(StreamingLineBuffer_0_buffer_stream[2], StreamingLineBuffer_0_out0_stream_prepad[10], StreamingLineBuffer_0_buffer_stream[3]);
        actor_statuses.push_back(actor_status);
        actor_status = StreamingMemory_1.step(StreamingMemory_0_out1_stream, StreamingMemory_1_out0_stream, StreamingMemory_1_out1_stream);
        actor_statuses.push_back(actor_status);
        actor_status = StreamingLineBuffer_0_pixel_3.step(StreamingLineBuffer_0_buffer_stream[1], StreamingLineBuffer_0_out0_stream_prepad[11], StreamingLineBuffer_0_buffer_stream[4]);
        actor_statuses.push_back(actor_status);
        actor_status = StreamingLineBuffer_0_pixel_2.step(StreamingLineBuffer_0_buffer_stream[0], StreamingLineBuffer_0_out0_stream_prepad[12], StreamingLineBuffer_0_buffer_stream[2]);
        actor_statuses.push_back(actor_status);
        actor_status = StreamingMemory_0.step(NHWCToStream_1_out0_stream, StreamingMemory_0_out0_stream, StreamingMemory_0_out1_stream);
        actor_statuses.push_back(actor_status);
        actor_status = StreamingLineBuffer_0_pixel_1.step(NHWCToStream_0_out0_stream[0], StreamingLineBuffer_0_out0_stream_prepad[13], StreamingLineBuffer_0_buffer_stream[1]);
        actor_statuses.push_back(actor_status);
        actor_status = StreamingLineBuffer_0_pixel_0.step(NHWCToStream_0_out0_stream[1], StreamingLineBuffer_0_out0_stream_prepad[14], StreamingLineBuffer_0_buffer_stream[0]);
        actor_statuses.push_back(actor_status);
        actor_status = NHWCToStream_1.step(global_in_1, NHWCToStream_1_out0_stream);
        actor_statuses.push_back(actor_status);
        actor_status = NHWCToStream_0.step(global_in, NHWCToStream_0_out0_stream);
        actor_statuses.push_back(actor_status);
        actor_status = FixedThroughputDMA_global_in.step(global_in);
        actor_statuses.push_back(actor_status);
        stream_max_size[0] = std::max<size_t>(NHWCToStream_0_out0_stream[0].size(), stream_max_size[0]);
        channel_quantities.push_back(NHWCToStream_0_out0_stream[0].size());
        stream_max_size[1] = std::max<size_t>(NHWCToStream_0_out0_stream[1].size(), stream_max_size[1]);
        channel_quantities.push_back(NHWCToStream_0_out0_stream[1].size());
        stream_max_size[2] = std::max<size_t>(NHWCToStream_1_out0_stream[0].size(), stream_max_size[2]);
        channel_quantities.push_back(NHWCToStream_1_out0_stream[0].size());
        stream_max_size[3] = std::max<size_t>(StreamingLineBuffer_0_out0_stream[0].size(), stream_max_size[3]);
        channel_quantities.push_back(StreamingLineBuffer_0_out0_stream[0].size());
        stream_max_size[4] = std::max<size_t>(StreamingLineBuffer_0_out0_stream[1].size(), stream_max_size[4]);
        channel_quantities.push_back(StreamingLineBuffer_0_out0_stream[1].size());
        stream_max_size[5] = std::max<size_t>(StreamingLineBuffer_0_out0_stream[2].size(), stream_max_size[5]);
        channel_quantities.push_back(StreamingLineBuffer_0_out0_stream[2].size());
        stream_max_size[6] = std::max<size_t>(StreamingLineBuffer_0_out0_stream[3].size(), stream_max_size[6]);
        channel_quantities.push_back(StreamingLineBuffer_0_out0_stream[3].size());
        stream_max_size[7] = std::max<size_t>(StreamingLineBuffer_0_out0_stream[4].size(), stream_max_size[7]);
        channel_quantities.push_back(StreamingLineBuffer_0_out0_stream[4].size());
        stream_max_size[8] = std::max<size_t>(StreamingLineBuffer_0_out0_stream[5].size(), stream_max_size[8]);
        channel_quantities.push_back(StreamingLineBuffer_0_out0_stream[5].size());
        stream_max_size[9] = std::max<size_t>(StreamingLineBuffer_0_out0_stream[6].size(), stream_max_size[9]);
        channel_quantities.push_back(StreamingLineBuffer_0_out0_stream[6].size());
        stream_max_size[10] = std::max<size_t>(StreamingLineBuffer_0_out0_stream[7].size(), stream_max_size[10]);
        channel_quantities.push_back(StreamingLineBuffer_0_out0_stream[7].size());
        stream_max_size[11] = std::max<size_t>(StreamingLineBuffer_0_out0_stream[8].size(), stream_max_size[11]);
        channel_quantities.push_back(StreamingLineBuffer_0_out0_stream[8].size());
        stream_max_size[12] = std::max<size_t>(StreamingLineBuffer_0_out0_stream[9].size(), stream_max_size[12]);
        channel_quantities.push_back(StreamingLineBuffer_0_out0_stream[9].size());
        stream_max_size[13] = std::max<size_t>(StreamingLineBuffer_0_out0_stream[10].size(), stream_max_size[13]);
        channel_quantities.push_back(StreamingLineBuffer_0_out0_stream[10].size());
        stream_max_size[14] = std::max<size_t>(StreamingLineBuffer_0_out0_stream[11].size(), stream_max_size[14]);
        channel_quantities.push_back(StreamingLineBuffer_0_out0_stream[11].size());
        stream_max_size[15] = std::max<size_t>(StreamingLineBuffer_0_out0_stream[12].size(), stream_max_size[15]);
        channel_quantities.push_back(StreamingLineBuffer_0_out0_stream[12].size());
        stream_max_size[16] = std::max<size_t>(StreamingLineBuffer_0_out0_stream[13].size(), stream_max_size[16]);
        channel_quantities.push_back(StreamingLineBuffer_0_out0_stream[13].size());
        stream_max_size[17] = std::max<size_t>(StreamingLineBuffer_0_out0_stream[14].size(), stream_max_size[17]);
        channel_quantities.push_back(StreamingLineBuffer_0_out0_stream[14].size());
        stream_max_size[18] = std::max<size_t>(StreamingLineBuffer_0_out0_stream_prepad[0].size(), stream_max_size[18]);
        channel_quantities.push_back(StreamingLineBuffer_0_out0_stream_prepad[0].size());
        stream_max_size[19] = std::max<size_t>(StreamingLineBuffer_0_out0_stream_prepad[1].size(), stream_max_size[19]);
        channel_quantities.push_back(StreamingLineBuffer_0_out0_stream_prepad[1].size());
        stream_max_size[20] = std::max<size_t>(StreamingLineBuffer_0_out0_stream_prepad[2].size(), stream_max_size[20]);
        channel_quantities.push_back(StreamingLineBuffer_0_out0_stream_prepad[2].size());
        stream_max_size[21] = std::max<size_t>(StreamingLineBuffer_0_out0_stream_prepad[3].size(), stream_max_size[21]);
        channel_quantities.push_back(StreamingLineBuffer_0_out0_stream_prepad[3].size());
        stream_max_size[22] = std::max<size_t>(StreamingLineBuffer_0_out0_stream_prepad[4].size(), stream_max_size[22]);
        channel_quantities.push_back(StreamingLineBuffer_0_out0_stream_prepad[4].size());
        stream_max_size[23] = std::max<size_t>(StreamingLineBuffer_0_out0_stream_prepad[5].size(), stream_max_size[23]);
        channel_quantities.push_back(StreamingLineBuffer_0_out0_stream_prepad[5].size());
        stream_max_size[24] = std::max<size_t>(StreamingLineBuffer_0_out0_stream_prepad[6].size(), stream_max_size[24]);
        channel_quantities.push_back(StreamingLineBuffer_0_out0_stream_prepad[6].size());
        stream_max_size[25] = std::max<size_t>(StreamingLineBuffer_0_out0_stream_prepad[7].size(), stream_max_size[25]);
        channel_quantities.push_back(StreamingLineBuffer_0_out0_stream_prepad[7].size());
        stream_max_size[26] = std::max<size_t>(StreamingLineBuffer_0_out0_stream_prepad[8].size(), stream_max_size[26]);
        channel_quantities.push_back(StreamingLineBuffer_0_out0_stream_prepad[8].size());
        stream_max_size[27] = std::max<size_t>(StreamingLineBuffer_0_out0_stream_prepad[9].size(), stream_max_size[27]);
        channel_quantities.push_back(StreamingLineBuffer_0_out0_stream_prepad[9].size());
        stream_max_size[28] = std::max<size_t>(StreamingLineBuffer_0_out0_stream_prepad[10].size(), stream_max_size[28]);
        channel_quantities.push_back(StreamingLineBuffer_0_out0_stream_prepad[10].size());
        stream_max_size[29] = std::max<size_t>(StreamingLineBuffer_0_out0_stream_prepad[11].size(), stream_max_size[29]);
        channel_quantities.push_back(StreamingLineBuffer_0_out0_stream_prepad[11].size());
        stream_max_size[30] = std::max<size_t>(StreamingLineBuffer_0_out0_stream_prepad[12].size(), stream_max_size[30]);
        channel_quantities.push_back(StreamingLineBuffer_0_out0_stream_prepad[12].size());
        stream_max_size[31] = std::max<size_t>(StreamingLineBuffer_0_out0_stream_prepad[13].size(), stream_max_size[31]);
        channel_quantities.push_back(StreamingLineBuffer_0_out0_stream_prepad[13].size());
        stream_max_size[32] = std::max<size_t>(StreamingLineBuffer_0_out0_stream_prepad[14].size(), stream_max_size[32]);
        channel_quantities.push_back(StreamingLineBuffer_0_out0_stream_prepad[14].size());
        stream_max_size[33] = std::max<size_t>(StreamingLineBuffer_0_buffer_stream[0].size(), stream_max_size[33]);
        channel_quantities.push_back(StreamingLineBuffer_0_buffer_stream[0].size());
        stream_max_size[34] = std::max<size_t>(StreamingLineBuffer_0_buffer_stream[1].size(), stream_max_size[34]);
        channel_quantities.push_back(StreamingLineBuffer_0_buffer_stream[1].size());
        stream_max_size[35] = std::max<size_t>(StreamingLineBuffer_0_buffer_stream[2].size(), stream_max_size[35]);
        channel_quantities.push_back(StreamingLineBuffer_0_buffer_stream[2].size());
        stream_max_size[36] = std::max<size_t>(StreamingLineBuffer_0_buffer_stream[3].size(), stream_max_size[36]);
        channel_quantities.push_back(StreamingLineBuffer_0_buffer_stream[3].size());
        stream_max_size[37] = std::max<size_t>(StreamingLineBuffer_0_buffer_stream[4].size(), stream_max_size[37]);
        channel_quantities.push_back(StreamingLineBuffer_0_buffer_stream[4].size());
        stream_max_size[38] = std::max<size_t>(StreamingLineBuffer_0_buffer_stream[5].size(), stream_max_size[38]);
        channel_quantities.push_back(StreamingLineBuffer_0_buffer_stream[5].size());
        stream_max_size[39] = std::max<size_t>(StreamingLineBuffer_0_buffer_stream[6].size(), stream_max_size[39]);
        channel_quantities.push_back(StreamingLineBuffer_0_buffer_stream[6].size());
        stream_max_size[40] = std::max<size_t>(StreamingLineBuffer_0_buffer_stream[7].size(), stream_max_size[40]);
        channel_quantities.push_back(StreamingLineBuffer_0_buffer_stream[7].size());
        stream_max_size[41] = std::max<size_t>(StreamingLineBuffer_0_buffer_stream[8].size(), stream_max_size[41]);
        channel_quantities.push_back(StreamingLineBuffer_0_buffer_stream[8].size());
        stream_max_size[42] = std::max<size_t>(StreamingLineBuffer_0_buffer_stream[9].size(), stream_max_size[42]);
        channel_quantities.push_back(StreamingLineBuffer_0_buffer_stream[9].size());
        stream_max_size[43] = std::max<size_t>(StreamingLineBuffer_0_buffer_stream[10].size(), stream_max_size[43]);
        channel_quantities.push_back(StreamingLineBuffer_0_buffer_stream[10].size());
        stream_max_size[44] = std::max<size_t>(StreamingLineBuffer_0_buffer_stream[11].size(), stream_max_size[44]);
        channel_quantities.push_back(StreamingLineBuffer_0_buffer_stream[11].size());
        stream_max_size[45] = std::max<size_t>(StreamingLineBuffer_0_buffer_stream[12].size(), stream_max_size[45]);
        channel_quantities.push_back(StreamingLineBuffer_0_buffer_stream[12].size());
        stream_max_size[46] = std::max<size_t>(StreamingMemory_0_out0_stream[0].size(), stream_max_size[46]);
        channel_quantities.push_back(StreamingMemory_0_out0_stream[0].size());
        stream_max_size[47] = std::max<size_t>(StreamingMemory_0_out0_stream[1].size(), stream_max_size[47]);
        channel_quantities.push_back(StreamingMemory_0_out0_stream[1].size());
        stream_max_size[48] = std::max<size_t>(StreamingMemory_0_out0_stream[2].size(), stream_max_size[48]);
        channel_quantities.push_back(StreamingMemory_0_out0_stream[2].size());
        stream_max_size[49] = std::max<size_t>(StreamingMemory_0_out0_stream[3].size(), stream_max_size[49]);
        channel_quantities.push_back(StreamingMemory_0_out0_stream[3].size());
        stream_max_size[50] = std::max<size_t>(StreamingMemory_0_out0_stream[4].size(), stream_max_size[50]);
        channel_quantities.push_back(StreamingMemory_0_out0_stream[4].size());
        stream_max_size[51] = std::max<size_t>(StreamingMemory_0_out0_stream[5].size(), stream_max_size[51]);
        channel_quantities.push_back(StreamingMemory_0_out0_stream[5].size());
        stream_max_size[52] = std::max<size_t>(StreamingMemory_0_out0_stream[6].size(), stream_max_size[52]);
        channel_quantities.push_back(StreamingMemory_0_out0_stream[6].size());
        stream_max_size[53] = std::max<size_t>(StreamingMemory_0_out0_stream[7].size(), stream_max_size[53]);
        channel_quantities.push_back(StreamingMemory_0_out0_stream[7].size());
        stream_max_size[54] = std::max<size_t>(StreamingMemory_0_out0_stream[8].size(), stream_max_size[54]);
        channel_quantities.push_back(StreamingMemory_0_out0_stream[8].size());
        stream_max_size[55] = std::max<size_t>(StreamingMemory_0_out1_stream[0].size(), stream_max_size[55]);
        channel_quantities.push_back(StreamingMemory_0_out1_stream[0].size());
        stream_max_size[56] = std::max<size_t>(StreamingMemory_1_out0_stream[0].size(), stream_max_size[56]);
        channel_quantities.push_back(StreamingMemory_1_out0_stream[0].size());
        stream_max_size[57] = std::max<size_t>(StreamingMemory_1_out1_stream[0].size(), stream_max_size[57]);
        channel_quantities.push_back(StreamingMemory_1_out1_stream[0].size());
        stream_max_size[58] = std::max<size_t>(StreamingConv_0_out0_stream[0].size(), stream_max_size[58]);
        channel_quantities.push_back(StreamingConv_0_out0_stream[0].size());
        stream_max_size[59] = std::max<size_t>(StreamingConv_0_out0_stream[1].size(), stream_max_size[59]);
        channel_quantities.push_back(StreamingConv_0_out0_stream[1].size());
        stream_max_size[60] = std::max<size_t>(StreamingMemory_2_out0_stream[0].size(), stream_max_size[60]);
        channel_quantities.push_back(StreamingMemory_2_out0_stream[0].size());
        stream_max_size[61] = std::max<size_t>(StreamingMemory_2_out0_stream[1].size(), stream_max_size[61]);
        channel_quantities.push_back(StreamingMemory_2_out0_stream[1].size());
        stream_max_size[62] = std::max<size_t>(StreamingMemory_2_out0_stream[2].size(), stream_max_size[62]);
        channel_quantities.push_back(StreamingMemory_2_out0_stream[2].size());
        stream_max_size[63] = std::max<size_t>(StreamingMemory_2_out0_stream[3].size(), stream_max_size[63]);
        channel_quantities.push_back(StreamingMemory_2_out0_stream[3].size());
        stream_max_size[64] = std::max<size_t>(StreamingMemory_2_out0_stream[4].size(), stream_max_size[64]);
        channel_quantities.push_back(StreamingMemory_2_out0_stream[4].size());
        stream_max_size[65] = std::max<size_t>(StreamingMemory_2_out0_stream[5].size(), stream_max_size[65]);
        channel_quantities.push_back(StreamingMemory_2_out0_stream[5].size());
        stream_max_size[66] = std::max<size_t>(StreamingMemory_2_out0_stream[6].size(), stream_max_size[66]);
        channel_quantities.push_back(StreamingMemory_2_out0_stream[6].size());
        stream_max_size[67] = std::max<size_t>(StreamingMemory_2_out0_stream[7].size(), stream_max_size[67]);
        channel_quantities.push_back(StreamingMemory_2_out0_stream[7].size());
        stream_max_size[68] = std::max<size_t>(StreamingMemory_2_out0_stream[8].size(), stream_max_size[68]);
        channel_quantities.push_back(StreamingMemory_2_out0_stream[8].size());
        stream_max_size[69] = std::max<size_t>(StreamingMemory_2_out1_stream[0].size(), stream_max_size[69]);
        channel_quantities.push_back(StreamingMemory_2_out1_stream[0].size());
        stream_max_size[70] = std::max<size_t>(StreamingLineBuffer_1_out0_stream[0].size(), stream_max_size[70]);
        channel_quantities.push_back(StreamingLineBuffer_1_out0_stream[0].size());
        stream_max_size[71] = std::max<size_t>(StreamingLineBuffer_1_out0_stream[1].size(), stream_max_size[71]);
        channel_quantities.push_back(StreamingLineBuffer_1_out0_stream[1].size());
        stream_max_size[72] = std::max<size_t>(StreamingLineBuffer_1_out0_stream[2].size(), stream_max_size[72]);
        channel_quantities.push_back(StreamingLineBuffer_1_out0_stream[2].size());
        stream_max_size[73] = std::max<size_t>(StreamingLineBuffer_1_out0_stream[3].size(), stream_max_size[73]);
        channel_quantities.push_back(StreamingLineBuffer_1_out0_stream[3].size());
        stream_max_size[74] = std::max<size_t>(StreamingLineBuffer_1_out0_stream[4].size(), stream_max_size[74]);
        channel_quantities.push_back(StreamingLineBuffer_1_out0_stream[4].size());
        stream_max_size[75] = std::max<size_t>(StreamingLineBuffer_1_out0_stream[5].size(), stream_max_size[75]);
        channel_quantities.push_back(StreamingLineBuffer_1_out0_stream[5].size());
        stream_max_size[76] = std::max<size_t>(StreamingLineBuffer_1_out0_stream[6].size(), stream_max_size[76]);
        channel_quantities.push_back(StreamingLineBuffer_1_out0_stream[6].size());
        stream_max_size[77] = std::max<size_t>(StreamingLineBuffer_1_out0_stream[7].size(), stream_max_size[77]);
        channel_quantities.push_back(StreamingLineBuffer_1_out0_stream[7].size());
        stream_max_size[78] = std::max<size_t>(StreamingLineBuffer_1_out0_stream[8].size(), stream_max_size[78]);
        channel_quantities.push_back(StreamingLineBuffer_1_out0_stream[8].size());
        stream_max_size[79] = std::max<size_t>(StreamingLineBuffer_1_out0_stream[9].size(), stream_max_size[79]);
        channel_quantities.push_back(StreamingLineBuffer_1_out0_stream[9].size());
        stream_max_size[80] = std::max<size_t>(StreamingLineBuffer_1_out0_stream[10].size(), stream_max_size[80]);
        channel_quantities.push_back(StreamingLineBuffer_1_out0_stream[10].size());
        stream_max_size[81] = std::max<size_t>(StreamingLineBuffer_1_out0_stream[11].size(), stream_max_size[81]);
        channel_quantities.push_back(StreamingLineBuffer_1_out0_stream[11].size());
        stream_max_size[82] = std::max<size_t>(StreamingLineBuffer_1_out0_stream_prepad[0].size(), stream_max_size[82]);
        channel_quantities.push_back(StreamingLineBuffer_1_out0_stream_prepad[0].size());
        stream_max_size[83] = std::max<size_t>(StreamingLineBuffer_1_out0_stream_prepad[1].size(), stream_max_size[83]);
        channel_quantities.push_back(StreamingLineBuffer_1_out0_stream_prepad[1].size());
        stream_max_size[84] = std::max<size_t>(StreamingLineBuffer_1_out0_stream_prepad[2].size(), stream_max_size[84]);
        channel_quantities.push_back(StreamingLineBuffer_1_out0_stream_prepad[2].size());
        stream_max_size[85] = std::max<size_t>(StreamingLineBuffer_1_out0_stream_prepad[3].size(), stream_max_size[85]);
        channel_quantities.push_back(StreamingLineBuffer_1_out0_stream_prepad[3].size());
        stream_max_size[86] = std::max<size_t>(StreamingLineBuffer_1_out0_stream_prepad[4].size(), stream_max_size[86]);
        channel_quantities.push_back(StreamingLineBuffer_1_out0_stream_prepad[4].size());
        stream_max_size[87] = std::max<size_t>(StreamingLineBuffer_1_out0_stream_prepad[5].size(), stream_max_size[87]);
        channel_quantities.push_back(StreamingLineBuffer_1_out0_stream_prepad[5].size());
        stream_max_size[88] = std::max<size_t>(StreamingLineBuffer_1_out0_stream_prepad[6].size(), stream_max_size[88]);
        channel_quantities.push_back(StreamingLineBuffer_1_out0_stream_prepad[6].size());
        stream_max_size[89] = std::max<size_t>(StreamingLineBuffer_1_out0_stream_prepad[7].size(), stream_max_size[89]);
        channel_quantities.push_back(StreamingLineBuffer_1_out0_stream_prepad[7].size());
        stream_max_size[90] = std::max<size_t>(StreamingLineBuffer_1_out0_stream_prepad[8].size(), stream_max_size[90]);
        channel_quantities.push_back(StreamingLineBuffer_1_out0_stream_prepad[8].size());
        stream_max_size[91] = std::max<size_t>(StreamingLineBuffer_1_out0_stream_prepad[9].size(), stream_max_size[91]);
        channel_quantities.push_back(StreamingLineBuffer_1_out0_stream_prepad[9].size());
        stream_max_size[92] = std::max<size_t>(StreamingLineBuffer_1_out0_stream_prepad[10].size(), stream_max_size[92]);
        channel_quantities.push_back(StreamingLineBuffer_1_out0_stream_prepad[10].size());
        stream_max_size[93] = std::max<size_t>(StreamingLineBuffer_1_out0_stream_prepad[11].size(), stream_max_size[93]);
        channel_quantities.push_back(StreamingLineBuffer_1_out0_stream_prepad[11].size());
        stream_max_size[94] = std::max<size_t>(StreamingLineBuffer_1_buffer_stream[0].size(), stream_max_size[94]);
        channel_quantities.push_back(StreamingLineBuffer_1_buffer_stream[0].size());
        stream_max_size[95] = std::max<size_t>(StreamingLineBuffer_1_buffer_stream[1].size(), stream_max_size[95]);
        channel_quantities.push_back(StreamingLineBuffer_1_buffer_stream[1].size());
        stream_max_size[96] = std::max<size_t>(StreamingLineBuffer_1_buffer_stream[2].size(), stream_max_size[96]);
        channel_quantities.push_back(StreamingLineBuffer_1_buffer_stream[2].size());
        stream_max_size[97] = std::max<size_t>(StreamingLineBuffer_1_buffer_stream[3].size(), stream_max_size[97]);
        channel_quantities.push_back(StreamingLineBuffer_1_buffer_stream[3].size());
        stream_max_size[98] = std::max<size_t>(StreamingLineBuffer_1_buffer_stream[4].size(), stream_max_size[98]);
        channel_quantities.push_back(StreamingLineBuffer_1_buffer_stream[4].size());
        stream_max_size[99] = std::max<size_t>(StreamingLineBuffer_1_buffer_stream[5].size(), stream_max_size[99]);
        channel_quantities.push_back(StreamingLineBuffer_1_buffer_stream[5].size());
        stream_max_size[100] = std::max<size_t>(StreamingLineBuffer_1_buffer_stream[6].size(), stream_max_size[100]);
        channel_quantities.push_back(StreamingLineBuffer_1_buffer_stream[6].size());
        stream_max_size[101] = std::max<size_t>(StreamingLineBuffer_1_buffer_stream[7].size(), stream_max_size[101]);
        channel_quantities.push_back(StreamingLineBuffer_1_buffer_stream[7].size());
        stream_max_size[102] = std::max<size_t>(StreamingLineBuffer_1_buffer_stream[8].size(), stream_max_size[102]);
        channel_quantities.push_back(StreamingLineBuffer_1_buffer_stream[8].size());
        stream_max_size[103] = std::max<size_t>(StreamingLineBuffer_1_buffer_stream[9].size(), stream_max_size[103]);
        channel_quantities.push_back(StreamingLineBuffer_1_buffer_stream[9].size());
        stream_max_size[104] = std::max<size_t>(StreamingMemory_3_out0_stream[0].size(), stream_max_size[104]);
        channel_quantities.push_back(StreamingMemory_3_out0_stream[0].size());
        stream_max_size[105] = std::max<size_t>(StreamingMemory_3_out1_stream[0].size(), stream_max_size[105]);
        channel_quantities.push_back(StreamingMemory_3_out1_stream[0].size());
        stream_max_size[106] = std::max<size_t>(StreamingDepthwiseConv_0_out0_stream[0].size(), stream_max_size[106]);
        channel_quantities.push_back(StreamingDepthwiseConv_0_out0_stream[0].size());
        stream_max_size[107] = std::max<size_t>(StreamingDepthwiseConv_0_out0_stream[1].size(), stream_max_size[107]);
        channel_quantities.push_back(StreamingDepthwiseConv_0_out0_stream[1].size());
        stream_max_size[108] = std::max<size_t>(StreamingMemory_4_out0_stream[0].size(), stream_max_size[108]);
        channel_quantities.push_back(StreamingMemory_4_out0_stream[0].size());
        stream_max_size[109] = std::max<size_t>(StreamingMemory_4_out1_stream[0].size(), stream_max_size[109]);
        channel_quantities.push_back(StreamingMemory_4_out1_stream[0].size());
        stream_max_size[110] = std::max<size_t>(BandwidthAdjustIncreaseChannels_0_out0_stream[0].size(), stream_max_size[110]);
        channel_quantities.push_back(BandwidthAdjustIncreaseChannels_0_out0_stream[0].size());
        stream_max_size[111] = std::max<size_t>(BandwidthAdjustIncreaseChannels_0_out0_stream[1].size(), stream_max_size[111]);
        channel_quantities.push_back(BandwidthAdjustIncreaseChannels_0_out0_stream[1].size());
        stream_max_size[112] = std::max<size_t>(StreamingMemory_5_out0_stream[0].size(), stream_max_size[112]);
        channel_quantities.push_back(StreamingMemory_5_out0_stream[0].size());
        stream_max_size[113] = std::max<size_t>(StreamingMemory_5_out1_stream[0].size(), stream_max_size[113]);
        channel_quantities.push_back(StreamingMemory_5_out1_stream[0].size());
        stream_max_size[114] = std::max<size_t>(StreamingLineBuffer_2_out0_stream[0].size(), stream_max_size[114]);
        channel_quantities.push_back(StreamingLineBuffer_2_out0_stream[0].size());
        stream_max_size[115] = std::max<size_t>(StreamingLineBuffer_2_out0_stream[1].size(), stream_max_size[115]);
        channel_quantities.push_back(StreamingLineBuffer_2_out0_stream[1].size());
        stream_max_size[116] = std::max<size_t>(StreamingMemory_6_out0_stream[0].size(), stream_max_size[116]);
        channel_quantities.push_back(StreamingMemory_6_out0_stream[0].size());
        stream_max_size[117] = std::max<size_t>(StreamingMemory_6_out1_stream[0].size(), stream_max_size[117]);
        channel_quantities.push_back(StreamingMemory_6_out1_stream[0].size());
        stream_max_size[118] = std::max<size_t>(StreamingConv_1_out0_stream[0].size(), stream_max_size[118]);
        channel_quantities.push_back(StreamingConv_1_out0_stream[0].size());
        stream_max_size[119] = std::max<size_t>(StreamingConv_1_out0_stream[1].size(), stream_max_size[119]);
        channel_quantities.push_back(StreamingConv_1_out0_stream[1].size());
        stream_max_size[120] = std::max<size_t>(StreamingMemory_7_out0_stream[0].size(), stream_max_size[120]);
        channel_quantities.push_back(StreamingMemory_7_out0_stream[0].size());
        stream_max_size[121] = std::max<size_t>(StreamingMemory_7_out1_stream[0].size(), stream_max_size[121]);
        channel_quantities.push_back(StreamingMemory_7_out1_stream[0].size());
        stream_max_size[122] = std::max<size_t>(BandwidthAdjustIncreaseChannels_1_out0_stream[0].size(), stream_max_size[122]);
        channel_quantities.push_back(BandwidthAdjustIncreaseChannels_1_out0_stream[0].size());
        stream_max_size[123] = std::max<size_t>(BandwidthAdjustIncreaseChannels_1_out0_stream[1].size(), stream_max_size[123]);
        channel_quantities.push_back(BandwidthAdjustIncreaseChannels_1_out0_stream[1].size());
        stream_max_size[124] = std::max<size_t>(StreamingMemory_8_out0_stream[0].size(), stream_max_size[124]);
        channel_quantities.push_back(StreamingMemory_8_out0_stream[0].size());
        stream_max_size[125] = std::max<size_t>(StreamingMemory_8_out0_stream[1].size(), stream_max_size[125]);
        channel_quantities.push_back(StreamingMemory_8_out0_stream[1].size());
        stream_max_size[126] = std::max<size_t>(StreamingMemory_8_out0_stream[2].size(), stream_max_size[126]);
        channel_quantities.push_back(StreamingMemory_8_out0_stream[2].size());
        stream_max_size[127] = std::max<size_t>(StreamingMemory_8_out0_stream[3].size(), stream_max_size[127]);
        channel_quantities.push_back(StreamingMemory_8_out0_stream[3].size());
        stream_max_size[128] = std::max<size_t>(StreamingMemory_8_out0_stream[4].size(), stream_max_size[128]);
        channel_quantities.push_back(StreamingMemory_8_out0_stream[4].size());
        stream_max_size[129] = std::max<size_t>(StreamingMemory_8_out0_stream[5].size(), stream_max_size[129]);
        channel_quantities.push_back(StreamingMemory_8_out0_stream[5].size());
        stream_max_size[130] = std::max<size_t>(StreamingMemory_8_out0_stream[6].size(), stream_max_size[130]);
        channel_quantities.push_back(StreamingMemory_8_out0_stream[6].size());
        stream_max_size[131] = std::max<size_t>(StreamingMemory_8_out0_stream[7].size(), stream_max_size[131]);
        channel_quantities.push_back(StreamingMemory_8_out0_stream[7].size());
        stream_max_size[132] = std::max<size_t>(StreamingMemory_8_out0_stream[8].size(), stream_max_size[132]);
        channel_quantities.push_back(StreamingMemory_8_out0_stream[8].size());
        stream_max_size[133] = std::max<size_t>(StreamingMemory_8_out1_stream[0].size(), stream_max_size[133]);
        channel_quantities.push_back(StreamingMemory_8_out1_stream[0].size());
        stream_max_size[134] = std::max<size_t>(StreamingLineBuffer_3_out0_stream[0].size(), stream_max_size[134]);
        channel_quantities.push_back(StreamingLineBuffer_3_out0_stream[0].size());
        stream_max_size[135] = std::max<size_t>(StreamingLineBuffer_3_out0_stream[1].size(), stream_max_size[135]);
        channel_quantities.push_back(StreamingLineBuffer_3_out0_stream[1].size());
        stream_max_size[136] = std::max<size_t>(StreamingMemory_9_out0_stream[0].size(), stream_max_size[136]);
        channel_quantities.push_back(StreamingMemory_9_out0_stream[0].size());
        stream_max_size[137] = std::max<size_t>(StreamingMemory_9_out1_stream[0].size(), stream_max_size[137]);
        channel_quantities.push_back(StreamingMemory_9_out1_stream[0].size());
        stream_max_size[138] = std::max<size_t>(StreamingConv_2_out0_stream[0].size(), stream_max_size[138]);
        channel_quantities.push_back(StreamingConv_2_out0_stream[0].size());
        stream_max_size[139] = std::max<size_t>(StreamingConv_2_out0_stream[1].size(), stream_max_size[139]);
        channel_quantities.push_back(StreamingConv_2_out0_stream[1].size());
        stream_max_size[140] = std::max<size_t>(StreamingMemory_10_out0_stream[0].size(), stream_max_size[140]);
        channel_quantities.push_back(StreamingMemory_10_out0_stream[0].size());
        stream_max_size[141] = std::max<size_t>(StreamingMemory_10_out1_stream[0].size(), stream_max_size[141]);
        channel_quantities.push_back(StreamingMemory_10_out1_stream[0].size());
        stream_max_size[142] = std::max<size_t>(StreamingLineBuffer_4_out0_stream[0].size(), stream_max_size[142]);
        channel_quantities.push_back(StreamingLineBuffer_4_out0_stream[0].size());
        stream_max_size[143] = std::max<size_t>(StreamingLineBuffer_4_out0_stream[1].size(), stream_max_size[143]);
        channel_quantities.push_back(StreamingLineBuffer_4_out0_stream[1].size());
        stream_max_size[144] = std::max<size_t>(StreamingLineBuffer_4_out0_stream[2].size(), stream_max_size[144]);
        channel_quantities.push_back(StreamingLineBuffer_4_out0_stream[2].size());
        stream_max_size[145] = std::max<size_t>(StreamingLineBuffer_4_out0_stream[3].size(), stream_max_size[145]);
        channel_quantities.push_back(StreamingLineBuffer_4_out0_stream[3].size());
        stream_max_size[146] = std::max<size_t>(StreamingLineBuffer_4_out0_stream[4].size(), stream_max_size[146]);
        channel_quantities.push_back(StreamingLineBuffer_4_out0_stream[4].size());
        stream_max_size[147] = std::max<size_t>(StreamingLineBuffer_4_out0_stream[5].size(), stream_max_size[147]);
        channel_quantities.push_back(StreamingLineBuffer_4_out0_stream[5].size());
        stream_max_size[148] = std::max<size_t>(StreamingLineBuffer_4_out0_stream[6].size(), stream_max_size[148]);
        channel_quantities.push_back(StreamingLineBuffer_4_out0_stream[6].size());
        stream_max_size[149] = std::max<size_t>(StreamingLineBuffer_4_out0_stream[7].size(), stream_max_size[149]);
        channel_quantities.push_back(StreamingLineBuffer_4_out0_stream[7].size());
        stream_max_size[150] = std::max<size_t>(StreamingLineBuffer_4_out0_stream[8].size(), stream_max_size[150]);
        channel_quantities.push_back(StreamingLineBuffer_4_out0_stream[8].size());
        stream_max_size[151] = std::max<size_t>(StreamingLineBuffer_4_out0_stream[9].size(), stream_max_size[151]);
        channel_quantities.push_back(StreamingLineBuffer_4_out0_stream[9].size());
        stream_max_size[152] = std::max<size_t>(StreamingLineBuffer_4_out0_stream[10].size(), stream_max_size[152]);
        channel_quantities.push_back(StreamingLineBuffer_4_out0_stream[10].size());
        stream_max_size[153] = std::max<size_t>(StreamingLineBuffer_4_out0_stream[11].size(), stream_max_size[153]);
        channel_quantities.push_back(StreamingLineBuffer_4_out0_stream[11].size());
        stream_max_size[154] = std::max<size_t>(StreamingLineBuffer_4_out0_stream[12].size(), stream_max_size[154]);
        channel_quantities.push_back(StreamingLineBuffer_4_out0_stream[12].size());
        stream_max_size[155] = std::max<size_t>(StreamingLineBuffer_4_out0_stream[13].size(), stream_max_size[155]);
        channel_quantities.push_back(StreamingLineBuffer_4_out0_stream[13].size());
        stream_max_size[156] = std::max<size_t>(StreamingLineBuffer_4_out0_stream[14].size(), stream_max_size[156]);
        channel_quantities.push_back(StreamingLineBuffer_4_out0_stream[14].size());
        stream_max_size[157] = std::max<size_t>(StreamingLineBuffer_4_out0_stream_prepad[0].size(), stream_max_size[157]);
        channel_quantities.push_back(StreamingLineBuffer_4_out0_stream_prepad[0].size());
        stream_max_size[158] = std::max<size_t>(StreamingLineBuffer_4_out0_stream_prepad[1].size(), stream_max_size[158]);
        channel_quantities.push_back(StreamingLineBuffer_4_out0_stream_prepad[1].size());
        stream_max_size[159] = std::max<size_t>(StreamingLineBuffer_4_out0_stream_prepad[2].size(), stream_max_size[159]);
        channel_quantities.push_back(StreamingLineBuffer_4_out0_stream_prepad[2].size());
        stream_max_size[160] = std::max<size_t>(StreamingLineBuffer_4_out0_stream_prepad[3].size(), stream_max_size[160]);
        channel_quantities.push_back(StreamingLineBuffer_4_out0_stream_prepad[3].size());
        stream_max_size[161] = std::max<size_t>(StreamingLineBuffer_4_out0_stream_prepad[4].size(), stream_max_size[161]);
        channel_quantities.push_back(StreamingLineBuffer_4_out0_stream_prepad[4].size());
        stream_max_size[162] = std::max<size_t>(StreamingLineBuffer_4_out0_stream_prepad[5].size(), stream_max_size[162]);
        channel_quantities.push_back(StreamingLineBuffer_4_out0_stream_prepad[5].size());
        stream_max_size[163] = std::max<size_t>(StreamingLineBuffer_4_out0_stream_prepad[6].size(), stream_max_size[163]);
        channel_quantities.push_back(StreamingLineBuffer_4_out0_stream_prepad[6].size());
        stream_max_size[164] = std::max<size_t>(StreamingLineBuffer_4_out0_stream_prepad[7].size(), stream_max_size[164]);
        channel_quantities.push_back(StreamingLineBuffer_4_out0_stream_prepad[7].size());
        stream_max_size[165] = std::max<size_t>(StreamingLineBuffer_4_out0_stream_prepad[8].size(), stream_max_size[165]);
        channel_quantities.push_back(StreamingLineBuffer_4_out0_stream_prepad[8].size());
        stream_max_size[166] = std::max<size_t>(StreamingLineBuffer_4_out0_stream_prepad[9].size(), stream_max_size[166]);
        channel_quantities.push_back(StreamingLineBuffer_4_out0_stream_prepad[9].size());
        stream_max_size[167] = std::max<size_t>(StreamingLineBuffer_4_out0_stream_prepad[10].size(), stream_max_size[167]);
        channel_quantities.push_back(StreamingLineBuffer_4_out0_stream_prepad[10].size());
        stream_max_size[168] = std::max<size_t>(StreamingLineBuffer_4_out0_stream_prepad[11].size(), stream_max_size[168]);
        channel_quantities.push_back(StreamingLineBuffer_4_out0_stream_prepad[11].size());
        stream_max_size[169] = std::max<size_t>(StreamingLineBuffer_4_out0_stream_prepad[12].size(), stream_max_size[169]);
        channel_quantities.push_back(StreamingLineBuffer_4_out0_stream_prepad[12].size());
        stream_max_size[170] = std::max<size_t>(StreamingLineBuffer_4_out0_stream_prepad[13].size(), stream_max_size[170]);
        channel_quantities.push_back(StreamingLineBuffer_4_out0_stream_prepad[13].size());
        stream_max_size[171] = std::max<size_t>(StreamingLineBuffer_4_out0_stream_prepad[14].size(), stream_max_size[171]);
        channel_quantities.push_back(StreamingLineBuffer_4_out0_stream_prepad[14].size());
        stream_max_size[172] = std::max<size_t>(StreamingLineBuffer_4_buffer_stream[0].size(), stream_max_size[172]);
        channel_quantities.push_back(StreamingLineBuffer_4_buffer_stream[0].size());
        stream_max_size[173] = std::max<size_t>(StreamingLineBuffer_4_buffer_stream[1].size(), stream_max_size[173]);
        channel_quantities.push_back(StreamingLineBuffer_4_buffer_stream[1].size());
        stream_max_size[174] = std::max<size_t>(StreamingLineBuffer_4_buffer_stream[2].size(), stream_max_size[174]);
        channel_quantities.push_back(StreamingLineBuffer_4_buffer_stream[2].size());
        stream_max_size[175] = std::max<size_t>(StreamingLineBuffer_4_buffer_stream[3].size(), stream_max_size[175]);
        channel_quantities.push_back(StreamingLineBuffer_4_buffer_stream[3].size());
        stream_max_size[176] = std::max<size_t>(StreamingLineBuffer_4_buffer_stream[4].size(), stream_max_size[176]);
        channel_quantities.push_back(StreamingLineBuffer_4_buffer_stream[4].size());
        stream_max_size[177] = std::max<size_t>(StreamingLineBuffer_4_buffer_stream[5].size(), stream_max_size[177]);
        channel_quantities.push_back(StreamingLineBuffer_4_buffer_stream[5].size());
        stream_max_size[178] = std::max<size_t>(StreamingLineBuffer_4_buffer_stream[6].size(), stream_max_size[178]);
        channel_quantities.push_back(StreamingLineBuffer_4_buffer_stream[6].size());
        stream_max_size[179] = std::max<size_t>(StreamingLineBuffer_4_buffer_stream[7].size(), stream_max_size[179]);
        channel_quantities.push_back(StreamingLineBuffer_4_buffer_stream[7].size());
        stream_max_size[180] = std::max<size_t>(StreamingLineBuffer_4_buffer_stream[8].size(), stream_max_size[180]);
        channel_quantities.push_back(StreamingLineBuffer_4_buffer_stream[8].size());
        stream_max_size[181] = std::max<size_t>(StreamingLineBuffer_4_buffer_stream[9].size(), stream_max_size[181]);
        channel_quantities.push_back(StreamingLineBuffer_4_buffer_stream[9].size());
        stream_max_size[182] = std::max<size_t>(StreamingLineBuffer_4_buffer_stream[10].size(), stream_max_size[182]);
        channel_quantities.push_back(StreamingLineBuffer_4_buffer_stream[10].size());
        stream_max_size[183] = std::max<size_t>(StreamingLineBuffer_4_buffer_stream[11].size(), stream_max_size[183]);
        channel_quantities.push_back(StreamingLineBuffer_4_buffer_stream[11].size());
        stream_max_size[184] = std::max<size_t>(StreamingLineBuffer_4_buffer_stream[12].size(), stream_max_size[184]);
        channel_quantities.push_back(StreamingLineBuffer_4_buffer_stream[12].size());
        stream_max_size[185] = std::max<size_t>(StreamingMemory_11_out0_stream[0].size(), stream_max_size[185]);
        channel_quantities.push_back(StreamingMemory_11_out0_stream[0].size());
        stream_max_size[186] = std::max<size_t>(StreamingMemory_11_out1_stream[0].size(), stream_max_size[186]);
        channel_quantities.push_back(StreamingMemory_11_out1_stream[0].size());
        stream_max_size[187] = std::max<size_t>(StreamingDepthwiseConv_1_out0_stream[0].size(), stream_max_size[187]);
        channel_quantities.push_back(StreamingDepthwiseConv_1_out0_stream[0].size());
        stream_max_size[188] = std::max<size_t>(StreamingDepthwiseConv_1_out0_stream[1].size(), stream_max_size[188]);
        channel_quantities.push_back(StreamingDepthwiseConv_1_out0_stream[1].size());
        stream_max_size[189] = std::max<size_t>(StreamingMemory_12_out0_stream[0].size(), stream_max_size[189]);
        channel_quantities.push_back(StreamingMemory_12_out0_stream[0].size());
        stream_max_size[190] = std::max<size_t>(StreamingMemory_12_out1_stream[0].size(), stream_max_size[190]);
        channel_quantities.push_back(StreamingMemory_12_out1_stream[0].size());
        stream_max_size[191] = std::max<size_t>(BandwidthAdjustIncreaseStreams_0_out0_stream[0].size(), stream_max_size[191]);
        channel_quantities.push_back(BandwidthAdjustIncreaseStreams_0_out0_stream[0].size());
        stream_max_size[192] = std::max<size_t>(BandwidthAdjustIncreaseStreams_0_out0_stream[1].size(), stream_max_size[192]);
        channel_quantities.push_back(BandwidthAdjustIncreaseStreams_0_out0_stream[1].size());
        stream_max_size[193] = std::max<size_t>(BandwidthAdjustIncreaseStreams_0_out0_stream[2].size(), stream_max_size[193]);
        channel_quantities.push_back(BandwidthAdjustIncreaseStreams_0_out0_stream[2].size());
        stream_max_size[194] = std::max<size_t>(BandwidthAdjustIncreaseStreams_0_out0_stream[3].size(), stream_max_size[194]);
        channel_quantities.push_back(BandwidthAdjustIncreaseStreams_0_out0_stream[3].size());
        stream_max_size[195] = std::max<size_t>(StreamingMemory_13_out0_stream[0].size(), stream_max_size[195]);
        channel_quantities.push_back(StreamingMemory_13_out0_stream[0].size());
        stream_max_size[196] = std::max<size_t>(StreamingMemory_13_out1_stream[0].size(), stream_max_size[196]);
        channel_quantities.push_back(StreamingMemory_13_out1_stream[0].size());
        stream_max_size[197] = std::max<size_t>(StreamingLineBuffer_5_out0_stream[0].size(), stream_max_size[197]);
        channel_quantities.push_back(StreamingLineBuffer_5_out0_stream[0].size());
        stream_max_size[198] = std::max<size_t>(StreamingLineBuffer_5_out0_stream[1].size(), stream_max_size[198]);
        channel_quantities.push_back(StreamingLineBuffer_5_out0_stream[1].size());
        stream_max_size[199] = std::max<size_t>(StreamingLineBuffer_5_out0_stream[2].size(), stream_max_size[199]);
        channel_quantities.push_back(StreamingLineBuffer_5_out0_stream[2].size());
        stream_max_size[200] = std::max<size_t>(StreamingLineBuffer_5_out0_stream[3].size(), stream_max_size[200]);
        channel_quantities.push_back(StreamingLineBuffer_5_out0_stream[3].size());
        stream_max_size[201] = std::max<size_t>(StreamingMemory_14_out0_stream[0].size(), stream_max_size[201]);
        channel_quantities.push_back(StreamingMemory_14_out0_stream[0].size());
        stream_max_size[202] = std::max<size_t>(StreamingMemory_14_out0_stream[1].size(), stream_max_size[202]);
        channel_quantities.push_back(StreamingMemory_14_out0_stream[1].size());
        stream_max_size[203] = std::max<size_t>(StreamingMemory_14_out0_stream[2].size(), stream_max_size[203]);
        channel_quantities.push_back(StreamingMemory_14_out0_stream[2].size());
        stream_max_size[204] = std::max<size_t>(StreamingMemory_14_out0_stream[3].size(), stream_max_size[204]);
        channel_quantities.push_back(StreamingMemory_14_out0_stream[3].size());
        stream_max_size[205] = std::max<size_t>(StreamingMemory_14_out0_stream[4].size(), stream_max_size[205]);
        channel_quantities.push_back(StreamingMemory_14_out0_stream[4].size());
        stream_max_size[206] = std::max<size_t>(StreamingMemory_14_out0_stream[5].size(), stream_max_size[206]);
        channel_quantities.push_back(StreamingMemory_14_out0_stream[5].size());
        stream_max_size[207] = std::max<size_t>(StreamingMemory_14_out0_stream[6].size(), stream_max_size[207]);
        channel_quantities.push_back(StreamingMemory_14_out0_stream[6].size());
        stream_max_size[208] = std::max<size_t>(StreamingMemory_14_out0_stream[7].size(), stream_max_size[208]);
        channel_quantities.push_back(StreamingMemory_14_out0_stream[7].size());
        stream_max_size[209] = std::max<size_t>(StreamingMemory_14_out0_stream[8].size(), stream_max_size[209]);
        channel_quantities.push_back(StreamingMemory_14_out0_stream[8].size());
        stream_max_size[210] = std::max<size_t>(StreamingMemory_14_out1_stream[0].size(), stream_max_size[210]);
        channel_quantities.push_back(StreamingMemory_14_out1_stream[0].size());
        stream_max_size[211] = std::max<size_t>(StreamingConv_3_out0_stream[0].size(), stream_max_size[211]);
        channel_quantities.push_back(StreamingConv_3_out0_stream[0].size());
        stream_max_size[212] = std::max<size_t>(StreamingConv_3_out0_stream[1].size(), stream_max_size[212]);
        channel_quantities.push_back(StreamingConv_3_out0_stream[1].size());
        stream_max_size[213] = std::max<size_t>(StreamingConv_3_out0_stream[2].size(), stream_max_size[213]);
        channel_quantities.push_back(StreamingConv_3_out0_stream[2].size());
        stream_max_size[214] = std::max<size_t>(StreamingConv_3_out0_stream[3].size(), stream_max_size[214]);
        channel_quantities.push_back(StreamingConv_3_out0_stream[3].size());
        stream_max_size[215] = std::max<size_t>(StreamingMemory_15_out0_stream[0].size(), stream_max_size[215]);
        channel_quantities.push_back(StreamingMemory_15_out0_stream[0].size());
        stream_max_size[216] = std::max<size_t>(StreamingMemory_15_out1_stream[0].size(), stream_max_size[216]);
        channel_quantities.push_back(StreamingMemory_15_out1_stream[0].size());
        stream_max_size[217] = std::max<size_t>(TensorDuplicator_0_out0_stream[0].size(), stream_max_size[217]);
        channel_quantities.push_back(TensorDuplicator_0_out0_stream[0].size());
        stream_max_size[218] = std::max<size_t>(TensorDuplicator_0_out0_stream[1].size(), stream_max_size[218]);
        channel_quantities.push_back(TensorDuplicator_0_out0_stream[1].size());
        stream_max_size[219] = std::max<size_t>(TensorDuplicator_0_out0_stream[2].size(), stream_max_size[219]);
        channel_quantities.push_back(TensorDuplicator_0_out0_stream[2].size());
        stream_max_size[220] = std::max<size_t>(TensorDuplicator_0_out0_stream[3].size(), stream_max_size[220]);
        channel_quantities.push_back(TensorDuplicator_0_out0_stream[3].size());
        stream_max_size[221] = std::max<size_t>(TensorDuplicator_0_out1_stream[0].size(), stream_max_size[221]);
        channel_quantities.push_back(TensorDuplicator_0_out1_stream[0].size());
        stream_max_size[222] = std::max<size_t>(TensorDuplicator_0_out1_stream[1].size(), stream_max_size[222]);
        channel_quantities.push_back(TensorDuplicator_0_out1_stream[1].size());
        stream_max_size[223] = std::max<size_t>(TensorDuplicator_0_out1_stream[2].size(), stream_max_size[223]);
        channel_quantities.push_back(TensorDuplicator_0_out1_stream[2].size());
        stream_max_size[224] = std::max<size_t>(TensorDuplicator_0_out1_stream[3].size(), stream_max_size[224]);
        channel_quantities.push_back(TensorDuplicator_0_out1_stream[3].size());
        stream_max_size[225] = std::max<size_t>(StreamingMemory_16_out0_stream[0].size(), stream_max_size[225]);
        channel_quantities.push_back(StreamingMemory_16_out0_stream[0].size());
        stream_max_size[226] = std::max<size_t>(StreamingMemory_16_out1_stream[0].size(), stream_max_size[226]);
        channel_quantities.push_back(StreamingMemory_16_out1_stream[0].size());
        stream_max_size[227] = std::max<size_t>(BandwidthAdjustDecreaseChannels_0_out0_stream[0].size(), stream_max_size[227]);
        channel_quantities.push_back(BandwidthAdjustDecreaseChannels_0_out0_stream[0].size());
        stream_max_size[228] = std::max<size_t>(BandwidthAdjustDecreaseChannels_0_out0_stream[1].size(), stream_max_size[228]);
        channel_quantities.push_back(BandwidthAdjustDecreaseChannels_0_out0_stream[1].size());
        stream_max_size[229] = std::max<size_t>(BandwidthAdjustDecreaseChannels_0_out0_stream[2].size(), stream_max_size[229]);
        channel_quantities.push_back(BandwidthAdjustDecreaseChannels_0_out0_stream[2].size());
        stream_max_size[230] = std::max<size_t>(BandwidthAdjustDecreaseChannels_0_out0_stream[3].size(), stream_max_size[230]);
        channel_quantities.push_back(BandwidthAdjustDecreaseChannels_0_out0_stream[3].size());
        stream_max_size[231] = std::max<size_t>(BandwidthAdjustDecreaseStreams_0_out0_stream[0].size(), stream_max_size[231]);
        channel_quantities.push_back(BandwidthAdjustDecreaseStreams_0_out0_stream[0].size());
        stream_max_size[232] = std::max<size_t>(BandwidthAdjustDecreaseStreams_0_out0_stream[1].size(), stream_max_size[232]);
        channel_quantities.push_back(BandwidthAdjustDecreaseStreams_0_out0_stream[1].size());
        stream_max_size[233] = std::max<size_t>(StreamingMemory_17_out0_stream[0].size(), stream_max_size[233]);
        channel_quantities.push_back(StreamingMemory_17_out0_stream[0].size());
        stream_max_size[234] = std::max<size_t>(StreamingMemory_17_out1_stream[0].size(), stream_max_size[234]);
        channel_quantities.push_back(StreamingMemory_17_out1_stream[0].size());
        stream_max_size[235] = std::max<size_t>(BandwidthAdjustIncreaseChannels_2_out0_stream[0].size(), stream_max_size[235]);
        channel_quantities.push_back(BandwidthAdjustIncreaseChannels_2_out0_stream[0].size());
        stream_max_size[236] = std::max<size_t>(BandwidthAdjustIncreaseChannels_2_out0_stream[1].size(), stream_max_size[236]);
        channel_quantities.push_back(BandwidthAdjustIncreaseChannels_2_out0_stream[1].size());
        stream_max_size[237] = std::max<size_t>(BandwidthAdjustIncreaseChannels_2_out0_stream[2].size(), stream_max_size[237]);
        channel_quantities.push_back(BandwidthAdjustIncreaseChannels_2_out0_stream[2].size());
        stream_max_size[238] = std::max<size_t>(BandwidthAdjustIncreaseChannels_2_out0_stream[3].size(), stream_max_size[238]);
        channel_quantities.push_back(BandwidthAdjustIncreaseChannels_2_out0_stream[3].size());
        stream_max_size[239] = std::max<size_t>(StreamingMemory_18_out0_stream[0].size(), stream_max_size[239]);
        channel_quantities.push_back(StreamingMemory_18_out0_stream[0].size());
        stream_max_size[240] = std::max<size_t>(StreamingMemory_18_out1_stream[0].size(), stream_max_size[240]);
        channel_quantities.push_back(StreamingMemory_18_out1_stream[0].size());
        stream_max_size[241] = std::max<size_t>(StreamingLineBuffer_6_out0_stream[0].size(), stream_max_size[241]);
        channel_quantities.push_back(StreamingLineBuffer_6_out0_stream[0].size());
        stream_max_size[242] = std::max<size_t>(StreamingLineBuffer_6_out0_stream[1].size(), stream_max_size[242]);
        channel_quantities.push_back(StreamingLineBuffer_6_out0_stream[1].size());
        stream_max_size[243] = std::max<size_t>(StreamingLineBuffer_6_out0_stream[2].size(), stream_max_size[243]);
        channel_quantities.push_back(StreamingLineBuffer_6_out0_stream[2].size());
        stream_max_size[244] = std::max<size_t>(StreamingLineBuffer_6_out0_stream[3].size(), stream_max_size[244]);
        channel_quantities.push_back(StreamingLineBuffer_6_out0_stream[3].size());
        stream_max_size[245] = std::max<size_t>(StreamingMemory_19_out0_stream[0].size(), stream_max_size[245]);
        channel_quantities.push_back(StreamingMemory_19_out0_stream[0].size());
        stream_max_size[246] = std::max<size_t>(StreamingMemory_19_out1_stream[0].size(), stream_max_size[246]);
        channel_quantities.push_back(StreamingMemory_19_out1_stream[0].size());
        stream_max_size[247] = std::max<size_t>(StreamingConv_4_out0_stream[0].size(), stream_max_size[247]);
        channel_quantities.push_back(StreamingConv_4_out0_stream[0].size());
        stream_max_size[248] = std::max<size_t>(StreamingConv_4_out0_stream[1].size(), stream_max_size[248]);
        channel_quantities.push_back(StreamingConv_4_out0_stream[1].size());
        stream_max_size[249] = std::max<size_t>(StreamingConv_4_out0_stream[2].size(), stream_max_size[249]);
        channel_quantities.push_back(StreamingConv_4_out0_stream[2].size());
        stream_max_size[250] = std::max<size_t>(StreamingConv_4_out0_stream[3].size(), stream_max_size[250]);
        channel_quantities.push_back(StreamingConv_4_out0_stream[3].size());
        stream_max_size[251] = std::max<size_t>(StreamingMemory_20_out0_stream[0].size(), stream_max_size[251]);
        channel_quantities.push_back(StreamingMemory_20_out0_stream[0].size());
        stream_max_size[252] = std::max<size_t>(StreamingMemory_20_out0_stream[1].size(), stream_max_size[252]);
        channel_quantities.push_back(StreamingMemory_20_out0_stream[1].size());
        stream_max_size[253] = std::max<size_t>(StreamingMemory_20_out0_stream[2].size(), stream_max_size[253]);
        channel_quantities.push_back(StreamingMemory_20_out0_stream[2].size());
        stream_max_size[254] = std::max<size_t>(StreamingMemory_20_out0_stream[3].size(), stream_max_size[254]);
        channel_quantities.push_back(StreamingMemory_20_out0_stream[3].size());
        stream_max_size[255] = std::max<size_t>(StreamingMemory_20_out0_stream[4].size(), stream_max_size[255]);
        channel_quantities.push_back(StreamingMemory_20_out0_stream[4].size());
        stream_max_size[256] = std::max<size_t>(StreamingMemory_20_out0_stream[5].size(), stream_max_size[256]);
        channel_quantities.push_back(StreamingMemory_20_out0_stream[5].size());
        stream_max_size[257] = std::max<size_t>(StreamingMemory_20_out0_stream[6].size(), stream_max_size[257]);
        channel_quantities.push_back(StreamingMemory_20_out0_stream[6].size());
        stream_max_size[258] = std::max<size_t>(StreamingMemory_20_out0_stream[7].size(), stream_max_size[258]);
        channel_quantities.push_back(StreamingMemory_20_out0_stream[7].size());
        stream_max_size[259] = std::max<size_t>(StreamingMemory_20_out0_stream[8].size(), stream_max_size[259]);
        channel_quantities.push_back(StreamingMemory_20_out0_stream[8].size());
        stream_max_size[260] = std::max<size_t>(StreamingMemory_20_out1_stream[0].size(), stream_max_size[260]);
        channel_quantities.push_back(StreamingMemory_20_out1_stream[0].size());
        stream_max_size[261] = std::max<size_t>(BandwidthAdjustDecreaseStreams_1_out0_stream[0].size(), stream_max_size[261]);
        channel_quantities.push_back(BandwidthAdjustDecreaseStreams_1_out0_stream[0].size());
        stream_max_size[262] = std::max<size_t>(BandwidthAdjustDecreaseStreams_1_out0_stream[1].size(), stream_max_size[262]);
        channel_quantities.push_back(BandwidthAdjustDecreaseStreams_1_out0_stream[1].size());
        stream_max_size[263] = std::max<size_t>(StreamingMemory_21_out0_stream[0].size(), stream_max_size[263]);
        channel_quantities.push_back(StreamingMemory_21_out0_stream[0].size());
        stream_max_size[264] = std::max<size_t>(StreamingMemory_21_out1_stream[0].size(), stream_max_size[264]);
        channel_quantities.push_back(StreamingMemory_21_out1_stream[0].size());
        stream_max_size[265] = std::max<size_t>(StreamingLineBuffer_7_out0_stream[0].size(), stream_max_size[265]);
        channel_quantities.push_back(StreamingLineBuffer_7_out0_stream[0].size());
        stream_max_size[266] = std::max<size_t>(StreamingLineBuffer_7_out0_stream[1].size(), stream_max_size[266]);
        channel_quantities.push_back(StreamingLineBuffer_7_out0_stream[1].size());
        stream_max_size[267] = std::max<size_t>(StreamingLineBuffer_7_out0_stream[2].size(), stream_max_size[267]);
        channel_quantities.push_back(StreamingLineBuffer_7_out0_stream[2].size());
        stream_max_size[268] = std::max<size_t>(StreamingLineBuffer_7_out0_stream[3].size(), stream_max_size[268]);
        channel_quantities.push_back(StreamingLineBuffer_7_out0_stream[3].size());
        stream_max_size[269] = std::max<size_t>(StreamingLineBuffer_7_out0_stream[4].size(), stream_max_size[269]);
        channel_quantities.push_back(StreamingLineBuffer_7_out0_stream[4].size());
        stream_max_size[270] = std::max<size_t>(StreamingLineBuffer_7_out0_stream[5].size(), stream_max_size[270]);
        channel_quantities.push_back(StreamingLineBuffer_7_out0_stream[5].size());
        stream_max_size[271] = std::max<size_t>(StreamingLineBuffer_7_out0_stream[6].size(), stream_max_size[271]);
        channel_quantities.push_back(StreamingLineBuffer_7_out0_stream[6].size());
        stream_max_size[272] = std::max<size_t>(StreamingLineBuffer_7_out0_stream[7].size(), stream_max_size[272]);
        channel_quantities.push_back(StreamingLineBuffer_7_out0_stream[7].size());
        stream_max_size[273] = std::max<size_t>(StreamingLineBuffer_7_out0_stream[8].size(), stream_max_size[273]);
        channel_quantities.push_back(StreamingLineBuffer_7_out0_stream[8].size());
        stream_max_size[274] = std::max<size_t>(StreamingLineBuffer_7_out0_stream[9].size(), stream_max_size[274]);
        channel_quantities.push_back(StreamingLineBuffer_7_out0_stream[9].size());
        stream_max_size[275] = std::max<size_t>(StreamingLineBuffer_7_out0_stream[10].size(), stream_max_size[275]);
        channel_quantities.push_back(StreamingLineBuffer_7_out0_stream[10].size());
        stream_max_size[276] = std::max<size_t>(StreamingLineBuffer_7_out0_stream[11].size(), stream_max_size[276]);
        channel_quantities.push_back(StreamingLineBuffer_7_out0_stream[11].size());
        stream_max_size[277] = std::max<size_t>(StreamingLineBuffer_7_out0_stream_prepad[0].size(), stream_max_size[277]);
        channel_quantities.push_back(StreamingLineBuffer_7_out0_stream_prepad[0].size());
        stream_max_size[278] = std::max<size_t>(StreamingLineBuffer_7_out0_stream_prepad[1].size(), stream_max_size[278]);
        channel_quantities.push_back(StreamingLineBuffer_7_out0_stream_prepad[1].size());
        stream_max_size[279] = std::max<size_t>(StreamingLineBuffer_7_out0_stream_prepad[2].size(), stream_max_size[279]);
        channel_quantities.push_back(StreamingLineBuffer_7_out0_stream_prepad[2].size());
        stream_max_size[280] = std::max<size_t>(StreamingLineBuffer_7_out0_stream_prepad[3].size(), stream_max_size[280]);
        channel_quantities.push_back(StreamingLineBuffer_7_out0_stream_prepad[3].size());
        stream_max_size[281] = std::max<size_t>(StreamingLineBuffer_7_out0_stream_prepad[4].size(), stream_max_size[281]);
        channel_quantities.push_back(StreamingLineBuffer_7_out0_stream_prepad[4].size());
        stream_max_size[282] = std::max<size_t>(StreamingLineBuffer_7_out0_stream_prepad[5].size(), stream_max_size[282]);
        channel_quantities.push_back(StreamingLineBuffer_7_out0_stream_prepad[5].size());
        stream_max_size[283] = std::max<size_t>(StreamingLineBuffer_7_out0_stream_prepad[6].size(), stream_max_size[283]);
        channel_quantities.push_back(StreamingLineBuffer_7_out0_stream_prepad[6].size());
        stream_max_size[284] = std::max<size_t>(StreamingLineBuffer_7_out0_stream_prepad[7].size(), stream_max_size[284]);
        channel_quantities.push_back(StreamingLineBuffer_7_out0_stream_prepad[7].size());
        stream_max_size[285] = std::max<size_t>(StreamingLineBuffer_7_out0_stream_prepad[8].size(), stream_max_size[285]);
        channel_quantities.push_back(StreamingLineBuffer_7_out0_stream_prepad[8].size());
        stream_max_size[286] = std::max<size_t>(StreamingLineBuffer_7_out0_stream_prepad[9].size(), stream_max_size[286]);
        channel_quantities.push_back(StreamingLineBuffer_7_out0_stream_prepad[9].size());
        stream_max_size[287] = std::max<size_t>(StreamingLineBuffer_7_out0_stream_prepad[10].size(), stream_max_size[287]);
        channel_quantities.push_back(StreamingLineBuffer_7_out0_stream_prepad[10].size());
        stream_max_size[288] = std::max<size_t>(StreamingLineBuffer_7_out0_stream_prepad[11].size(), stream_max_size[288]);
        channel_quantities.push_back(StreamingLineBuffer_7_out0_stream_prepad[11].size());
        stream_max_size[289] = std::max<size_t>(StreamingLineBuffer_7_buffer_stream[0].size(), stream_max_size[289]);
        channel_quantities.push_back(StreamingLineBuffer_7_buffer_stream[0].size());
        stream_max_size[290] = std::max<size_t>(StreamingLineBuffer_7_buffer_stream[1].size(), stream_max_size[290]);
        channel_quantities.push_back(StreamingLineBuffer_7_buffer_stream[1].size());
        stream_max_size[291] = std::max<size_t>(StreamingLineBuffer_7_buffer_stream[2].size(), stream_max_size[291]);
        channel_quantities.push_back(StreamingLineBuffer_7_buffer_stream[2].size());
        stream_max_size[292] = std::max<size_t>(StreamingLineBuffer_7_buffer_stream[3].size(), stream_max_size[292]);
        channel_quantities.push_back(StreamingLineBuffer_7_buffer_stream[3].size());
        stream_max_size[293] = std::max<size_t>(StreamingLineBuffer_7_buffer_stream[4].size(), stream_max_size[293]);
        channel_quantities.push_back(StreamingLineBuffer_7_buffer_stream[4].size());
        stream_max_size[294] = std::max<size_t>(StreamingLineBuffer_7_buffer_stream[5].size(), stream_max_size[294]);
        channel_quantities.push_back(StreamingLineBuffer_7_buffer_stream[5].size());
        stream_max_size[295] = std::max<size_t>(StreamingLineBuffer_7_buffer_stream[6].size(), stream_max_size[295]);
        channel_quantities.push_back(StreamingLineBuffer_7_buffer_stream[6].size());
        stream_max_size[296] = std::max<size_t>(StreamingLineBuffer_7_buffer_stream[7].size(), stream_max_size[296]);
        channel_quantities.push_back(StreamingLineBuffer_7_buffer_stream[7].size());
        stream_max_size[297] = std::max<size_t>(StreamingLineBuffer_7_buffer_stream[8].size(), stream_max_size[297]);
        channel_quantities.push_back(StreamingLineBuffer_7_buffer_stream[8].size());
        stream_max_size[298] = std::max<size_t>(StreamingLineBuffer_7_buffer_stream[9].size(), stream_max_size[298]);
        channel_quantities.push_back(StreamingLineBuffer_7_buffer_stream[9].size());
        stream_max_size[299] = std::max<size_t>(StreamingMemory_22_out0_stream[0].size(), stream_max_size[299]);
        channel_quantities.push_back(StreamingMemory_22_out0_stream[0].size());
        stream_max_size[300] = std::max<size_t>(StreamingMemory_22_out1_stream[0].size(), stream_max_size[300]);
        channel_quantities.push_back(StreamingMemory_22_out1_stream[0].size());
        stream_max_size[301] = std::max<size_t>(StreamingDepthwiseConv_2_out0_stream[0].size(), stream_max_size[301]);
        channel_quantities.push_back(StreamingDepthwiseConv_2_out0_stream[0].size());
        stream_max_size[302] = std::max<size_t>(StreamingDepthwiseConv_2_out0_stream[1].size(), stream_max_size[302]);
        channel_quantities.push_back(StreamingDepthwiseConv_2_out0_stream[1].size());
        stream_max_size[303] = std::max<size_t>(StreamingMemory_23_out0_stream[0].size(), stream_max_size[303]);
        channel_quantities.push_back(StreamingMemory_23_out0_stream[0].size());
        stream_max_size[304] = std::max<size_t>(StreamingMemory_23_out1_stream[0].size(), stream_max_size[304]);
        channel_quantities.push_back(StreamingMemory_23_out1_stream[0].size());
        stream_max_size[305] = std::max<size_t>(BandwidthAdjustIncreaseChannels_3_out0_stream[0].size(), stream_max_size[305]);
        channel_quantities.push_back(BandwidthAdjustIncreaseChannels_3_out0_stream[0].size());
        stream_max_size[306] = std::max<size_t>(BandwidthAdjustIncreaseChannels_3_out0_stream[1].size(), stream_max_size[306]);
        channel_quantities.push_back(BandwidthAdjustIncreaseChannels_3_out0_stream[1].size());
        stream_max_size[307] = std::max<size_t>(StreamingMemory_24_out0_stream[0].size(), stream_max_size[307]);
        channel_quantities.push_back(StreamingMemory_24_out0_stream[0].size());
        stream_max_size[308] = std::max<size_t>(StreamingMemory_24_out1_stream[0].size(), stream_max_size[308]);
        channel_quantities.push_back(StreamingMemory_24_out1_stream[0].size());
        stream_max_size[309] = std::max<size_t>(BandwidthAdjustDecreaseChannels_1_out0_stream[0].size(), stream_max_size[309]);
        channel_quantities.push_back(BandwidthAdjustDecreaseChannels_1_out0_stream[0].size());
        stream_max_size[310] = std::max<size_t>(BandwidthAdjustDecreaseChannels_1_out0_stream[1].size(), stream_max_size[310]);
        channel_quantities.push_back(BandwidthAdjustDecreaseChannels_1_out0_stream[1].size());
        stream_max_size[311] = std::max<size_t>(StreamingMemory_25_out0_stream[0].size(), stream_max_size[311]);
        channel_quantities.push_back(StreamingMemory_25_out0_stream[0].size());
        stream_max_size[312] = std::max<size_t>(StreamingMemory_25_out1_stream[0].size(), stream_max_size[312]);
        channel_quantities.push_back(StreamingMemory_25_out1_stream[0].size());
        stream_max_size[313] = std::max<size_t>(StreamingLineBuffer_8_out0_stream[0].size(), stream_max_size[313]);
        channel_quantities.push_back(StreamingLineBuffer_8_out0_stream[0].size());
        stream_max_size[314] = std::max<size_t>(StreamingLineBuffer_8_out0_stream[1].size(), stream_max_size[314]);
        channel_quantities.push_back(StreamingLineBuffer_8_out0_stream[1].size());
        stream_max_size[315] = std::max<size_t>(StreamingMemory_26_out0_stream[0].size(), stream_max_size[315]);
        channel_quantities.push_back(StreamingMemory_26_out0_stream[0].size());
        stream_max_size[316] = std::max<size_t>(StreamingMemory_26_out0_stream[1].size(), stream_max_size[316]);
        channel_quantities.push_back(StreamingMemory_26_out0_stream[1].size());
        stream_max_size[317] = std::max<size_t>(StreamingMemory_26_out0_stream[2].size(), stream_max_size[317]);
        channel_quantities.push_back(StreamingMemory_26_out0_stream[2].size());
        stream_max_size[318] = std::max<size_t>(StreamingMemory_26_out0_stream[3].size(), stream_max_size[318]);
        channel_quantities.push_back(StreamingMemory_26_out0_stream[3].size());
        stream_max_size[319] = std::max<size_t>(StreamingMemory_26_out0_stream[4].size(), stream_max_size[319]);
        channel_quantities.push_back(StreamingMemory_26_out0_stream[4].size());
        stream_max_size[320] = std::max<size_t>(StreamingMemory_26_out0_stream[5].size(), stream_max_size[320]);
        channel_quantities.push_back(StreamingMemory_26_out0_stream[5].size());
        stream_max_size[321] = std::max<size_t>(StreamingMemory_26_out0_stream[6].size(), stream_max_size[321]);
        channel_quantities.push_back(StreamingMemory_26_out0_stream[6].size());
        stream_max_size[322] = std::max<size_t>(StreamingMemory_26_out0_stream[7].size(), stream_max_size[322]);
        channel_quantities.push_back(StreamingMemory_26_out0_stream[7].size());
        stream_max_size[323] = std::max<size_t>(StreamingMemory_26_out0_stream[8].size(), stream_max_size[323]);
        channel_quantities.push_back(StreamingMemory_26_out0_stream[8].size());
        stream_max_size[324] = std::max<size_t>(StreamingMemory_26_out1_stream[0].size(), stream_max_size[324]);
        channel_quantities.push_back(StreamingMemory_26_out1_stream[0].size());
        stream_max_size[325] = std::max<size_t>(StreamingConv_5_out0_stream[0].size(), stream_max_size[325]);
        channel_quantities.push_back(StreamingConv_5_out0_stream[0].size());
        stream_max_size[326] = std::max<size_t>(StreamingConv_5_out0_stream[1].size(), stream_max_size[326]);
        channel_quantities.push_back(StreamingConv_5_out0_stream[1].size());
        stream_max_size[327] = std::max<size_t>(StreamingMemory_27_out0_stream[0].size(), stream_max_size[327]);
        channel_quantities.push_back(StreamingMemory_27_out0_stream[0].size());
        stream_max_size[328] = std::max<size_t>(StreamingMemory_27_out1_stream[0].size(), stream_max_size[328]);
        channel_quantities.push_back(StreamingMemory_27_out1_stream[0].size());
        stream_max_size[329] = std::max<size_t>(StreamingAdd_0_out0_stream[0].size(), stream_max_size[329]);
        channel_quantities.push_back(StreamingAdd_0_out0_stream[0].size());
        stream_max_size[330] = std::max<size_t>(StreamingAdd_0_out0_stream[1].size(), stream_max_size[330]);
        channel_quantities.push_back(StreamingAdd_0_out0_stream[1].size());
        stream_max_size[331] = std::max<size_t>(StreamingMemory_28_out0_stream[0].size(), stream_max_size[331]);
        channel_quantities.push_back(StreamingMemory_28_out0_stream[0].size());
        stream_max_size[332] = std::max<size_t>(StreamingMemory_28_out1_stream[0].size(), stream_max_size[332]);
        channel_quantities.push_back(StreamingMemory_28_out1_stream[0].size());
        stream_max_size[333] = std::max<size_t>(BandwidthAdjustDecreaseChannels_2_out0_stream[0].size(), stream_max_size[333]);
        channel_quantities.push_back(BandwidthAdjustDecreaseChannels_2_out0_stream[0].size());
        stream_max_size[334] = std::max<size_t>(BandwidthAdjustDecreaseChannels_2_out0_stream[1].size(), stream_max_size[334]);
        channel_quantities.push_back(BandwidthAdjustDecreaseChannels_2_out0_stream[1].size());
        stream_max_size[335] = std::max<size_t>(StreamingMemory_29_out0_stream[0].size(), stream_max_size[335]);
        channel_quantities.push_back(StreamingMemory_29_out0_stream[0].size());
        stream_max_size[336] = std::max<size_t>(StreamingMemory_29_out1_stream[0].size(), stream_max_size[336]);
        channel_quantities.push_back(StreamingMemory_29_out1_stream[0].size());
        stream_max_size[337] = std::max<size_t>(BandwidthAdjustIncreaseChannels_4_out0_stream[0].size(), stream_max_size[337]);
        channel_quantities.push_back(BandwidthAdjustIncreaseChannels_4_out0_stream[0].size());
        stream_max_size[338] = std::max<size_t>(BandwidthAdjustIncreaseChannels_4_out0_stream[1].size(), stream_max_size[338]);
        channel_quantities.push_back(BandwidthAdjustIncreaseChannels_4_out0_stream[1].size());
        stream_max_size[339] = std::max<size_t>(StreamingMemory_30_out0_stream[0].size(), stream_max_size[339]);
        channel_quantities.push_back(StreamingMemory_30_out0_stream[0].size());
        stream_max_size[340] = std::max<size_t>(StreamingMemory_30_out1_stream[0].size(), stream_max_size[340]);
        channel_quantities.push_back(StreamingMemory_30_out1_stream[0].size());
        stream_max_size[341] = std::max<size_t>(BandwidthAdjustIncreaseStreams_1_out0_stream[0].size(), stream_max_size[341]);
        channel_quantities.push_back(BandwidthAdjustIncreaseStreams_1_out0_stream[0].size());
        stream_max_size[342] = std::max<size_t>(BandwidthAdjustIncreaseStreams_1_out0_stream[1].size(), stream_max_size[342]);
        channel_quantities.push_back(BandwidthAdjustIncreaseStreams_1_out0_stream[1].size());
        stream_max_size[343] = std::max<size_t>(BandwidthAdjustIncreaseStreams_1_out0_stream[2].size(), stream_max_size[343]);
        channel_quantities.push_back(BandwidthAdjustIncreaseStreams_1_out0_stream[2].size());
        stream_max_size[344] = std::max<size_t>(BandwidthAdjustIncreaseStreams_1_out0_stream[3].size(), stream_max_size[344]);
        channel_quantities.push_back(BandwidthAdjustIncreaseStreams_1_out0_stream[3].size());
        stream_max_size[345] = std::max<size_t>(StreamingMemory_31_out0_stream[0].size(), stream_max_size[345]);
        channel_quantities.push_back(StreamingMemory_31_out0_stream[0].size());
        stream_max_size[346] = std::max<size_t>(StreamingMemory_31_out1_stream[0].size(), stream_max_size[346]);
        channel_quantities.push_back(StreamingMemory_31_out1_stream[0].size());
        stream_max_size[347] = std::max<size_t>(StreamingLineBuffer_9_out0_stream[0].size(), stream_max_size[347]);
        channel_quantities.push_back(StreamingLineBuffer_9_out0_stream[0].size());
        stream_max_size[348] = std::max<size_t>(StreamingLineBuffer_9_out0_stream[1].size(), stream_max_size[348]);
        channel_quantities.push_back(StreamingLineBuffer_9_out0_stream[1].size());
        stream_max_size[349] = std::max<size_t>(StreamingLineBuffer_9_out0_stream[2].size(), stream_max_size[349]);
        channel_quantities.push_back(StreamingLineBuffer_9_out0_stream[2].size());
        stream_max_size[350] = std::max<size_t>(StreamingLineBuffer_9_out0_stream[3].size(), stream_max_size[350]);
        channel_quantities.push_back(StreamingLineBuffer_9_out0_stream[3].size());
        stream_max_size[351] = std::max<size_t>(StreamingMemory_32_out0_stream[0].size(), stream_max_size[351]);
        channel_quantities.push_back(StreamingMemory_32_out0_stream[0].size());
        stream_max_size[352] = std::max<size_t>(StreamingMemory_32_out0_stream[1].size(), stream_max_size[352]);
        channel_quantities.push_back(StreamingMemory_32_out0_stream[1].size());
        stream_max_size[353] = std::max<size_t>(StreamingMemory_32_out0_stream[2].size(), stream_max_size[353]);
        channel_quantities.push_back(StreamingMemory_32_out0_stream[2].size());
        stream_max_size[354] = std::max<size_t>(StreamingMemory_32_out0_stream[3].size(), stream_max_size[354]);
        channel_quantities.push_back(StreamingMemory_32_out0_stream[3].size());
        stream_max_size[355] = std::max<size_t>(StreamingMemory_32_out0_stream[4].size(), stream_max_size[355]);
        channel_quantities.push_back(StreamingMemory_32_out0_stream[4].size());
        stream_max_size[356] = std::max<size_t>(StreamingMemory_32_out0_stream[5].size(), stream_max_size[356]);
        channel_quantities.push_back(StreamingMemory_32_out0_stream[5].size());
        stream_max_size[357] = std::max<size_t>(StreamingMemory_32_out0_stream[6].size(), stream_max_size[357]);
        channel_quantities.push_back(StreamingMemory_32_out0_stream[6].size());
        stream_max_size[358] = std::max<size_t>(StreamingMemory_32_out0_stream[7].size(), stream_max_size[358]);
        channel_quantities.push_back(StreamingMemory_32_out0_stream[7].size());
        stream_max_size[359] = std::max<size_t>(StreamingMemory_32_out0_stream[8].size(), stream_max_size[359]);
        channel_quantities.push_back(StreamingMemory_32_out0_stream[8].size());
        stream_max_size[360] = std::max<size_t>(StreamingMemory_32_out1_stream[0].size(), stream_max_size[360]);
        channel_quantities.push_back(StreamingMemory_32_out1_stream[0].size());
        stream_max_size[361] = std::max<size_t>(StreamingConv_6_out0_stream[0].size(), stream_max_size[361]);
        channel_quantities.push_back(StreamingConv_6_out0_stream[0].size());
        stream_max_size[362] = std::max<size_t>(StreamingConv_6_out0_stream[1].size(), stream_max_size[362]);
        channel_quantities.push_back(StreamingConv_6_out0_stream[1].size());
        stream_max_size[363] = std::max<size_t>(StreamingConv_6_out0_stream[2].size(), stream_max_size[363]);
        channel_quantities.push_back(StreamingConv_6_out0_stream[2].size());
        stream_max_size[364] = std::max<size_t>(StreamingConv_6_out0_stream[3].size(), stream_max_size[364]);
        channel_quantities.push_back(StreamingConv_6_out0_stream[3].size());
        stream_max_size[365] = std::max<size_t>(StreamingMemory_33_out0_stream[0].size(), stream_max_size[365]);
        channel_quantities.push_back(StreamingMemory_33_out0_stream[0].size());
        stream_max_size[366] = std::max<size_t>(StreamingMemory_33_out1_stream[0].size(), stream_max_size[366]);
        channel_quantities.push_back(StreamingMemory_33_out1_stream[0].size());
        stream_max_size[367] = std::max<size_t>(BandwidthAdjustDecreaseStreams_2_out0_stream[0].size(), stream_max_size[367]);
        channel_quantities.push_back(BandwidthAdjustDecreaseStreams_2_out0_stream[0].size());
        stream_max_size[368] = std::max<size_t>(BandwidthAdjustDecreaseStreams_2_out0_stream[1].size(), stream_max_size[368]);
        channel_quantities.push_back(BandwidthAdjustDecreaseStreams_2_out0_stream[1].size());
        stream_max_size[369] = std::max<size_t>(StreamingMemory_34_out0_stream[0].size(), stream_max_size[369]);
        channel_quantities.push_back(StreamingMemory_34_out0_stream[0].size());
        stream_max_size[370] = std::max<size_t>(StreamingMemory_34_out1_stream[0].size(), stream_max_size[370]);
        channel_quantities.push_back(StreamingMemory_34_out1_stream[0].size());
        stream_max_size[371] = std::max<size_t>(StreamingLineBuffer_10_out0_stream[0].size(), stream_max_size[371]);
        channel_quantities.push_back(StreamingLineBuffer_10_out0_stream[0].size());
        stream_max_size[372] = std::max<size_t>(StreamingLineBuffer_10_out0_stream[1].size(), stream_max_size[372]);
        channel_quantities.push_back(StreamingLineBuffer_10_out0_stream[1].size());
        stream_max_size[373] = std::max<size_t>(StreamingLineBuffer_10_out0_stream[2].size(), stream_max_size[373]);
        channel_quantities.push_back(StreamingLineBuffer_10_out0_stream[2].size());
        stream_max_size[374] = std::max<size_t>(StreamingLineBuffer_10_out0_stream[3].size(), stream_max_size[374]);
        channel_quantities.push_back(StreamingLineBuffer_10_out0_stream[3].size());
        stream_max_size[375] = std::max<size_t>(StreamingLineBuffer_10_out0_stream[4].size(), stream_max_size[375]);
        channel_quantities.push_back(StreamingLineBuffer_10_out0_stream[4].size());
        stream_max_size[376] = std::max<size_t>(StreamingLineBuffer_10_out0_stream[5].size(), stream_max_size[376]);
        channel_quantities.push_back(StreamingLineBuffer_10_out0_stream[5].size());
        stream_max_size[377] = std::max<size_t>(StreamingLineBuffer_10_out0_stream[6].size(), stream_max_size[377]);
        channel_quantities.push_back(StreamingLineBuffer_10_out0_stream[6].size());
        stream_max_size[378] = std::max<size_t>(StreamingLineBuffer_10_out0_stream[7].size(), stream_max_size[378]);
        channel_quantities.push_back(StreamingLineBuffer_10_out0_stream[7].size());
        stream_max_size[379] = std::max<size_t>(StreamingLineBuffer_10_out0_stream[8].size(), stream_max_size[379]);
        channel_quantities.push_back(StreamingLineBuffer_10_out0_stream[8].size());
        stream_max_size[380] = std::max<size_t>(StreamingLineBuffer_10_out0_stream[9].size(), stream_max_size[380]);
        channel_quantities.push_back(StreamingLineBuffer_10_out0_stream[9].size());
        stream_max_size[381] = std::max<size_t>(StreamingLineBuffer_10_out0_stream[10].size(), stream_max_size[381]);
        channel_quantities.push_back(StreamingLineBuffer_10_out0_stream[10].size());
        stream_max_size[382] = std::max<size_t>(StreamingLineBuffer_10_out0_stream[11].size(), stream_max_size[382]);
        channel_quantities.push_back(StreamingLineBuffer_10_out0_stream[11].size());
        stream_max_size[383] = std::max<size_t>(StreamingLineBuffer_10_out0_stream[12].size(), stream_max_size[383]);
        channel_quantities.push_back(StreamingLineBuffer_10_out0_stream[12].size());
        stream_max_size[384] = std::max<size_t>(StreamingLineBuffer_10_out0_stream[13].size(), stream_max_size[384]);
        channel_quantities.push_back(StreamingLineBuffer_10_out0_stream[13].size());
        stream_max_size[385] = std::max<size_t>(StreamingLineBuffer_10_out0_stream[14].size(), stream_max_size[385]);
        channel_quantities.push_back(StreamingLineBuffer_10_out0_stream[14].size());
        stream_max_size[386] = std::max<size_t>(StreamingLineBuffer_10_out0_stream_prepad[0].size(), stream_max_size[386]);
        channel_quantities.push_back(StreamingLineBuffer_10_out0_stream_prepad[0].size());
        stream_max_size[387] = std::max<size_t>(StreamingLineBuffer_10_out0_stream_prepad[1].size(), stream_max_size[387]);
        channel_quantities.push_back(StreamingLineBuffer_10_out0_stream_prepad[1].size());
        stream_max_size[388] = std::max<size_t>(StreamingLineBuffer_10_out0_stream_prepad[2].size(), stream_max_size[388]);
        channel_quantities.push_back(StreamingLineBuffer_10_out0_stream_prepad[2].size());
        stream_max_size[389] = std::max<size_t>(StreamingLineBuffer_10_out0_stream_prepad[3].size(), stream_max_size[389]);
        channel_quantities.push_back(StreamingLineBuffer_10_out0_stream_prepad[3].size());
        stream_max_size[390] = std::max<size_t>(StreamingLineBuffer_10_out0_stream_prepad[4].size(), stream_max_size[390]);
        channel_quantities.push_back(StreamingLineBuffer_10_out0_stream_prepad[4].size());
        stream_max_size[391] = std::max<size_t>(StreamingLineBuffer_10_out0_stream_prepad[5].size(), stream_max_size[391]);
        channel_quantities.push_back(StreamingLineBuffer_10_out0_stream_prepad[5].size());
        stream_max_size[392] = std::max<size_t>(StreamingLineBuffer_10_out0_stream_prepad[6].size(), stream_max_size[392]);
        channel_quantities.push_back(StreamingLineBuffer_10_out0_stream_prepad[6].size());
        stream_max_size[393] = std::max<size_t>(StreamingLineBuffer_10_out0_stream_prepad[7].size(), stream_max_size[393]);
        channel_quantities.push_back(StreamingLineBuffer_10_out0_stream_prepad[7].size());
        stream_max_size[394] = std::max<size_t>(StreamingLineBuffer_10_out0_stream_prepad[8].size(), stream_max_size[394]);
        channel_quantities.push_back(StreamingLineBuffer_10_out0_stream_prepad[8].size());
        stream_max_size[395] = std::max<size_t>(StreamingLineBuffer_10_out0_stream_prepad[9].size(), stream_max_size[395]);
        channel_quantities.push_back(StreamingLineBuffer_10_out0_stream_prepad[9].size());
        stream_max_size[396] = std::max<size_t>(StreamingLineBuffer_10_out0_stream_prepad[10].size(), stream_max_size[396]);
        channel_quantities.push_back(StreamingLineBuffer_10_out0_stream_prepad[10].size());
        stream_max_size[397] = std::max<size_t>(StreamingLineBuffer_10_out0_stream_prepad[11].size(), stream_max_size[397]);
        channel_quantities.push_back(StreamingLineBuffer_10_out0_stream_prepad[11].size());
        stream_max_size[398] = std::max<size_t>(StreamingLineBuffer_10_out0_stream_prepad[12].size(), stream_max_size[398]);
        channel_quantities.push_back(StreamingLineBuffer_10_out0_stream_prepad[12].size());
        stream_max_size[399] = std::max<size_t>(StreamingLineBuffer_10_out0_stream_prepad[13].size(), stream_max_size[399]);
        channel_quantities.push_back(StreamingLineBuffer_10_out0_stream_prepad[13].size());
        stream_max_size[400] = std::max<size_t>(StreamingLineBuffer_10_out0_stream_prepad[14].size(), stream_max_size[400]);
        channel_quantities.push_back(StreamingLineBuffer_10_out0_stream_prepad[14].size());
        stream_max_size[401] = std::max<size_t>(StreamingLineBuffer_10_buffer_stream[0].size(), stream_max_size[401]);
        channel_quantities.push_back(StreamingLineBuffer_10_buffer_stream[0].size());
        stream_max_size[402] = std::max<size_t>(StreamingLineBuffer_10_buffer_stream[1].size(), stream_max_size[402]);
        channel_quantities.push_back(StreamingLineBuffer_10_buffer_stream[1].size());
        stream_max_size[403] = std::max<size_t>(StreamingLineBuffer_10_buffer_stream[2].size(), stream_max_size[403]);
        channel_quantities.push_back(StreamingLineBuffer_10_buffer_stream[2].size());
        stream_max_size[404] = std::max<size_t>(StreamingLineBuffer_10_buffer_stream[3].size(), stream_max_size[404]);
        channel_quantities.push_back(StreamingLineBuffer_10_buffer_stream[3].size());
        stream_max_size[405] = std::max<size_t>(StreamingLineBuffer_10_buffer_stream[4].size(), stream_max_size[405]);
        channel_quantities.push_back(StreamingLineBuffer_10_buffer_stream[4].size());
        stream_max_size[406] = std::max<size_t>(StreamingLineBuffer_10_buffer_stream[5].size(), stream_max_size[406]);
        channel_quantities.push_back(StreamingLineBuffer_10_buffer_stream[5].size());
        stream_max_size[407] = std::max<size_t>(StreamingLineBuffer_10_buffer_stream[6].size(), stream_max_size[407]);
        channel_quantities.push_back(StreamingLineBuffer_10_buffer_stream[6].size());
        stream_max_size[408] = std::max<size_t>(StreamingLineBuffer_10_buffer_stream[7].size(), stream_max_size[408]);
        channel_quantities.push_back(StreamingLineBuffer_10_buffer_stream[7].size());
        stream_max_size[409] = std::max<size_t>(StreamingLineBuffer_10_buffer_stream[8].size(), stream_max_size[409]);
        channel_quantities.push_back(StreamingLineBuffer_10_buffer_stream[8].size());
        stream_max_size[410] = std::max<size_t>(StreamingLineBuffer_10_buffer_stream[9].size(), stream_max_size[410]);
        channel_quantities.push_back(StreamingLineBuffer_10_buffer_stream[9].size());
        stream_max_size[411] = std::max<size_t>(StreamingLineBuffer_10_buffer_stream[10].size(), stream_max_size[411]);
        channel_quantities.push_back(StreamingLineBuffer_10_buffer_stream[10].size());
        stream_max_size[412] = std::max<size_t>(StreamingLineBuffer_10_buffer_stream[11].size(), stream_max_size[412]);
        channel_quantities.push_back(StreamingLineBuffer_10_buffer_stream[11].size());
        stream_max_size[413] = std::max<size_t>(StreamingLineBuffer_10_buffer_stream[12].size(), stream_max_size[413]);
        channel_quantities.push_back(StreamingLineBuffer_10_buffer_stream[12].size());
        stream_max_size[414] = std::max<size_t>(StreamingMemory_35_out0_stream[0].size(), stream_max_size[414]);
        channel_quantities.push_back(StreamingMemory_35_out0_stream[0].size());
        stream_max_size[415] = std::max<size_t>(StreamingMemory_35_out1_stream[0].size(), stream_max_size[415]);
        channel_quantities.push_back(StreamingMemory_35_out1_stream[0].size());
        stream_max_size[416] = std::max<size_t>(StreamingDepthwiseConv_3_out0_stream[0].size(), stream_max_size[416]);
        channel_quantities.push_back(StreamingDepthwiseConv_3_out0_stream[0].size());
        stream_max_size[417] = std::max<size_t>(StreamingDepthwiseConv_3_out0_stream[1].size(), stream_max_size[417]);
        channel_quantities.push_back(StreamingDepthwiseConv_3_out0_stream[1].size());
        stream_max_size[418] = std::max<size_t>(StreamingMemory_36_out0_stream[0].size(), stream_max_size[418]);
        channel_quantities.push_back(StreamingMemory_36_out0_stream[0].size());
        stream_max_size[419] = std::max<size_t>(StreamingMemory_36_out1_stream[0].size(), stream_max_size[419]);
        channel_quantities.push_back(StreamingMemory_36_out1_stream[0].size());
        stream_max_size[420] = std::max<size_t>(BandwidthAdjustDecreaseChannels_3_out0_stream[0].size(), stream_max_size[420]);
        channel_quantities.push_back(BandwidthAdjustDecreaseChannels_3_out0_stream[0].size());
        stream_max_size[421] = std::max<size_t>(BandwidthAdjustDecreaseChannels_3_out0_stream[1].size(), stream_max_size[421]);
        channel_quantities.push_back(BandwidthAdjustDecreaseChannels_3_out0_stream[1].size());
        stream_max_size[422] = std::max<size_t>(StreamingMemory_37_out0_stream[0].size(), stream_max_size[422]);
        channel_quantities.push_back(StreamingMemory_37_out0_stream[0].size());
        stream_max_size[423] = std::max<size_t>(StreamingMemory_37_out1_stream[0].size(), stream_max_size[423]);
        channel_quantities.push_back(StreamingMemory_37_out1_stream[0].size());
        stream_max_size[424] = std::max<size_t>(BandwidthAdjustIncreaseChannels_5_out0_stream[0].size(), stream_max_size[424]);
        channel_quantities.push_back(BandwidthAdjustIncreaseChannels_5_out0_stream[0].size());
        stream_max_size[425] = std::max<size_t>(BandwidthAdjustIncreaseChannels_5_out0_stream[1].size(), stream_max_size[425]);
        channel_quantities.push_back(BandwidthAdjustIncreaseChannels_5_out0_stream[1].size());
        stream_max_size[426] = std::max<size_t>(StreamingMemory_38_out0_stream[0].size(), stream_max_size[426]);
        channel_quantities.push_back(StreamingMemory_38_out0_stream[0].size());
        stream_max_size[427] = std::max<size_t>(StreamingMemory_38_out0_stream[1].size(), stream_max_size[427]);
        channel_quantities.push_back(StreamingMemory_38_out0_stream[1].size());
        stream_max_size[428] = std::max<size_t>(StreamingMemory_38_out0_stream[2].size(), stream_max_size[428]);
        channel_quantities.push_back(StreamingMemory_38_out0_stream[2].size());
        stream_max_size[429] = std::max<size_t>(StreamingMemory_38_out0_stream[3].size(), stream_max_size[429]);
        channel_quantities.push_back(StreamingMemory_38_out0_stream[3].size());
        stream_max_size[430] = std::max<size_t>(StreamingMemory_38_out0_stream[4].size(), stream_max_size[430]);
        channel_quantities.push_back(StreamingMemory_38_out0_stream[4].size());
        stream_max_size[431] = std::max<size_t>(StreamingMemory_38_out0_stream[5].size(), stream_max_size[431]);
        channel_quantities.push_back(StreamingMemory_38_out0_stream[5].size());
        stream_max_size[432] = std::max<size_t>(StreamingMemory_38_out0_stream[6].size(), stream_max_size[432]);
        channel_quantities.push_back(StreamingMemory_38_out0_stream[6].size());
        stream_max_size[433] = std::max<size_t>(StreamingMemory_38_out0_stream[7].size(), stream_max_size[433]);
        channel_quantities.push_back(StreamingMemory_38_out0_stream[7].size());
        stream_max_size[434] = std::max<size_t>(StreamingMemory_38_out0_stream[8].size(), stream_max_size[434]);
        channel_quantities.push_back(StreamingMemory_38_out0_stream[8].size());
        stream_max_size[435] = std::max<size_t>(StreamingMemory_38_out1_stream[0].size(), stream_max_size[435]);
        channel_quantities.push_back(StreamingMemory_38_out1_stream[0].size());
        stream_max_size[436] = std::max<size_t>(StreamingLineBuffer_11_out0_stream[0].size(), stream_max_size[436]);
        channel_quantities.push_back(StreamingLineBuffer_11_out0_stream[0].size());
        stream_max_size[437] = std::max<size_t>(StreamingLineBuffer_11_out0_stream[1].size(), stream_max_size[437]);
        channel_quantities.push_back(StreamingLineBuffer_11_out0_stream[1].size());
        stream_max_size[438] = std::max<size_t>(StreamingMemory_39_out0_stream[0].size(), stream_max_size[438]);
        channel_quantities.push_back(StreamingMemory_39_out0_stream[0].size());
        stream_max_size[439] = std::max<size_t>(StreamingMemory_39_out1_stream[0].size(), stream_max_size[439]);
        channel_quantities.push_back(StreamingMemory_39_out1_stream[0].size());
        stream_max_size[440] = std::max<size_t>(StreamingConv_7_out0_stream[0].size(), stream_max_size[440]);
        channel_quantities.push_back(StreamingConv_7_out0_stream[0].size());
        stream_max_size[441] = std::max<size_t>(StreamingConv_7_out0_stream[1].size(), stream_max_size[441]);
        channel_quantities.push_back(StreamingConv_7_out0_stream[1].size());
        stream_max_size[442] = std::max<size_t>(StreamingMemory_40_out0_stream[0].size(), stream_max_size[442]);
        channel_quantities.push_back(StreamingMemory_40_out0_stream[0].size());
        stream_max_size[443] = std::max<size_t>(StreamingMemory_40_out1_stream[0].size(), stream_max_size[443]);
        channel_quantities.push_back(StreamingMemory_40_out1_stream[0].size());
        stream_max_size[444] = std::max<size_t>(TensorDuplicator_1_out0_stream[0].size(), stream_max_size[444]);
        channel_quantities.push_back(TensorDuplicator_1_out0_stream[0].size());
        stream_max_size[445] = std::max<size_t>(TensorDuplicator_1_out0_stream[1].size(), stream_max_size[445]);
        channel_quantities.push_back(TensorDuplicator_1_out0_stream[1].size());
        stream_max_size[446] = std::max<size_t>(TensorDuplicator_1_out1_stream[0].size(), stream_max_size[446]);
        channel_quantities.push_back(TensorDuplicator_1_out1_stream[0].size());
        stream_max_size[447] = std::max<size_t>(TensorDuplicator_1_out1_stream[1].size(), stream_max_size[447]);
        channel_quantities.push_back(TensorDuplicator_1_out1_stream[1].size());
        stream_max_size[448] = std::max<size_t>(StreamingMemory_41_out0_stream[0].size(), stream_max_size[448]);
        channel_quantities.push_back(StreamingMemory_41_out0_stream[0].size());
        stream_max_size[449] = std::max<size_t>(StreamingMemory_41_out1_stream[0].size(), stream_max_size[449]);
        channel_quantities.push_back(StreamingMemory_41_out1_stream[0].size());
        stream_max_size[450] = std::max<size_t>(BandwidthAdjustIncreaseChannels_6_out0_stream[0].size(), stream_max_size[450]);
        channel_quantities.push_back(BandwidthAdjustIncreaseChannels_6_out0_stream[0].size());
        stream_max_size[451] = std::max<size_t>(BandwidthAdjustIncreaseChannels_6_out0_stream[1].size(), stream_max_size[451]);
        channel_quantities.push_back(BandwidthAdjustIncreaseChannels_6_out0_stream[1].size());
        stream_max_size[452] = std::max<size_t>(BandwidthAdjustIncreaseChannels_7_out0_stream[0].size(), stream_max_size[452]);
        channel_quantities.push_back(BandwidthAdjustIncreaseChannels_7_out0_stream[0].size());
        stream_max_size[453] = std::max<size_t>(BandwidthAdjustIncreaseChannels_7_out0_stream[1].size(), stream_max_size[453]);
        channel_quantities.push_back(BandwidthAdjustIncreaseChannels_7_out0_stream[1].size());
        stream_max_size[454] = std::max<size_t>(StreamingMemory_42_out0_stream[0].size(), stream_max_size[454]);
        channel_quantities.push_back(StreamingMemory_42_out0_stream[0].size());
        stream_max_size[455] = std::max<size_t>(StreamingMemory_42_out1_stream[0].size(), stream_max_size[455]);
        channel_quantities.push_back(StreamingMemory_42_out1_stream[0].size());
        stream_max_size[456] = std::max<size_t>(StreamingLineBuffer_12_out0_stream[0].size(), stream_max_size[456]);
        channel_quantities.push_back(StreamingLineBuffer_12_out0_stream[0].size());
        stream_max_size[457] = std::max<size_t>(StreamingLineBuffer_12_out0_stream[1].size(), stream_max_size[457]);
        channel_quantities.push_back(StreamingLineBuffer_12_out0_stream[1].size());
        stream_max_size[458] = std::max<size_t>(StreamingMemory_43_out0_stream[0].size(), stream_max_size[458]);
        channel_quantities.push_back(StreamingMemory_43_out0_stream[0].size());
        stream_max_size[459] = std::max<size_t>(StreamingMemory_43_out1_stream[0].size(), stream_max_size[459]);
        channel_quantities.push_back(StreamingMemory_43_out1_stream[0].size());
        stream_max_size[460] = std::max<size_t>(StreamingConv_8_out0_stream[0].size(), stream_max_size[460]);
        channel_quantities.push_back(StreamingConv_8_out0_stream[0].size());
        stream_max_size[461] = std::max<size_t>(StreamingConv_8_out0_stream[1].size(), stream_max_size[461]);
        channel_quantities.push_back(StreamingConv_8_out0_stream[1].size());
        stream_max_size[462] = std::max<size_t>(StreamingMemory_44_out0_stream[0].size(), stream_max_size[462]);
        channel_quantities.push_back(StreamingMemory_44_out0_stream[0].size());
        stream_max_size[463] = std::max<size_t>(StreamingMemory_44_out0_stream[1].size(), stream_max_size[463]);
        channel_quantities.push_back(StreamingMemory_44_out0_stream[1].size());
        stream_max_size[464] = std::max<size_t>(StreamingMemory_44_out0_stream[2].size(), stream_max_size[464]);
        channel_quantities.push_back(StreamingMemory_44_out0_stream[2].size());
        stream_max_size[465] = std::max<size_t>(StreamingMemory_44_out0_stream[3].size(), stream_max_size[465]);
        channel_quantities.push_back(StreamingMemory_44_out0_stream[3].size());
        stream_max_size[466] = std::max<size_t>(StreamingMemory_44_out0_stream[4].size(), stream_max_size[466]);
        channel_quantities.push_back(StreamingMemory_44_out0_stream[4].size());
        stream_max_size[467] = std::max<size_t>(StreamingMemory_44_out0_stream[5].size(), stream_max_size[467]);
        channel_quantities.push_back(StreamingMemory_44_out0_stream[5].size());
        stream_max_size[468] = std::max<size_t>(StreamingMemory_44_out0_stream[6].size(), stream_max_size[468]);
        channel_quantities.push_back(StreamingMemory_44_out0_stream[6].size());
        stream_max_size[469] = std::max<size_t>(StreamingMemory_44_out0_stream[7].size(), stream_max_size[469]);
        channel_quantities.push_back(StreamingMemory_44_out0_stream[7].size());
        stream_max_size[470] = std::max<size_t>(StreamingMemory_44_out0_stream[8].size(), stream_max_size[470]);
        channel_quantities.push_back(StreamingMemory_44_out0_stream[8].size());
        stream_max_size[471] = std::max<size_t>(StreamingMemory_44_out1_stream[0].size(), stream_max_size[471]);
        channel_quantities.push_back(StreamingMemory_44_out1_stream[0].size());
        stream_max_size[472] = std::max<size_t>(BandwidthAdjustDecreaseChannels_4_out0_stream[0].size(), stream_max_size[472]);
        channel_quantities.push_back(BandwidthAdjustDecreaseChannels_4_out0_stream[0].size());
        stream_max_size[473] = std::max<size_t>(BandwidthAdjustDecreaseChannels_4_out0_stream[1].size(), stream_max_size[473]);
        channel_quantities.push_back(BandwidthAdjustDecreaseChannels_4_out0_stream[1].size());
        stream_max_size[474] = std::max<size_t>(StreamingMemory_45_out0_stream[0].size(), stream_max_size[474]);
        channel_quantities.push_back(StreamingMemory_45_out0_stream[0].size());
        stream_max_size[475] = std::max<size_t>(StreamingMemory_45_out1_stream[0].size(), stream_max_size[475]);
        channel_quantities.push_back(StreamingMemory_45_out1_stream[0].size());
        stream_max_size[476] = std::max<size_t>(StreamingLineBuffer_13_out0_stream[0].size(), stream_max_size[476]);
        channel_quantities.push_back(StreamingLineBuffer_13_out0_stream[0].size());
        stream_max_size[477] = std::max<size_t>(StreamingLineBuffer_13_out0_stream[1].size(), stream_max_size[477]);
        channel_quantities.push_back(StreamingLineBuffer_13_out0_stream[1].size());
        stream_max_size[478] = std::max<size_t>(StreamingLineBuffer_13_out0_stream[2].size(), stream_max_size[478]);
        channel_quantities.push_back(StreamingLineBuffer_13_out0_stream[2].size());
        stream_max_size[479] = std::max<size_t>(StreamingLineBuffer_13_out0_stream[3].size(), stream_max_size[479]);
        channel_quantities.push_back(StreamingLineBuffer_13_out0_stream[3].size());
        stream_max_size[480] = std::max<size_t>(StreamingLineBuffer_13_out0_stream[4].size(), stream_max_size[480]);
        channel_quantities.push_back(StreamingLineBuffer_13_out0_stream[4].size());
        stream_max_size[481] = std::max<size_t>(StreamingLineBuffer_13_out0_stream[5].size(), stream_max_size[481]);
        channel_quantities.push_back(StreamingLineBuffer_13_out0_stream[5].size());
        stream_max_size[482] = std::max<size_t>(StreamingLineBuffer_13_out0_stream[6].size(), stream_max_size[482]);
        channel_quantities.push_back(StreamingLineBuffer_13_out0_stream[6].size());
        stream_max_size[483] = std::max<size_t>(StreamingLineBuffer_13_out0_stream[7].size(), stream_max_size[483]);
        channel_quantities.push_back(StreamingLineBuffer_13_out0_stream[7].size());
        stream_max_size[484] = std::max<size_t>(StreamingLineBuffer_13_out0_stream[8].size(), stream_max_size[484]);
        channel_quantities.push_back(StreamingLineBuffer_13_out0_stream[8].size());
        stream_max_size[485] = std::max<size_t>(StreamingLineBuffer_13_out0_stream[9].size(), stream_max_size[485]);
        channel_quantities.push_back(StreamingLineBuffer_13_out0_stream[9].size());
        stream_max_size[486] = std::max<size_t>(StreamingLineBuffer_13_out0_stream[10].size(), stream_max_size[486]);
        channel_quantities.push_back(StreamingLineBuffer_13_out0_stream[10].size());
        stream_max_size[487] = std::max<size_t>(StreamingLineBuffer_13_out0_stream[11].size(), stream_max_size[487]);
        channel_quantities.push_back(StreamingLineBuffer_13_out0_stream[11].size());
        stream_max_size[488] = std::max<size_t>(StreamingLineBuffer_13_out0_stream_prepad[0].size(), stream_max_size[488]);
        channel_quantities.push_back(StreamingLineBuffer_13_out0_stream_prepad[0].size());
        stream_max_size[489] = std::max<size_t>(StreamingLineBuffer_13_out0_stream_prepad[1].size(), stream_max_size[489]);
        channel_quantities.push_back(StreamingLineBuffer_13_out0_stream_prepad[1].size());
        stream_max_size[490] = std::max<size_t>(StreamingLineBuffer_13_out0_stream_prepad[2].size(), stream_max_size[490]);
        channel_quantities.push_back(StreamingLineBuffer_13_out0_stream_prepad[2].size());
        stream_max_size[491] = std::max<size_t>(StreamingLineBuffer_13_out0_stream_prepad[3].size(), stream_max_size[491]);
        channel_quantities.push_back(StreamingLineBuffer_13_out0_stream_prepad[3].size());
        stream_max_size[492] = std::max<size_t>(StreamingLineBuffer_13_out0_stream_prepad[4].size(), stream_max_size[492]);
        channel_quantities.push_back(StreamingLineBuffer_13_out0_stream_prepad[4].size());
        stream_max_size[493] = std::max<size_t>(StreamingLineBuffer_13_out0_stream_prepad[5].size(), stream_max_size[493]);
        channel_quantities.push_back(StreamingLineBuffer_13_out0_stream_prepad[5].size());
        stream_max_size[494] = std::max<size_t>(StreamingLineBuffer_13_out0_stream_prepad[6].size(), stream_max_size[494]);
        channel_quantities.push_back(StreamingLineBuffer_13_out0_stream_prepad[6].size());
        stream_max_size[495] = std::max<size_t>(StreamingLineBuffer_13_out0_stream_prepad[7].size(), stream_max_size[495]);
        channel_quantities.push_back(StreamingLineBuffer_13_out0_stream_prepad[7].size());
        stream_max_size[496] = std::max<size_t>(StreamingLineBuffer_13_out0_stream_prepad[8].size(), stream_max_size[496]);
        channel_quantities.push_back(StreamingLineBuffer_13_out0_stream_prepad[8].size());
        stream_max_size[497] = std::max<size_t>(StreamingLineBuffer_13_out0_stream_prepad[9].size(), stream_max_size[497]);
        channel_quantities.push_back(StreamingLineBuffer_13_out0_stream_prepad[9].size());
        stream_max_size[498] = std::max<size_t>(StreamingLineBuffer_13_out0_stream_prepad[10].size(), stream_max_size[498]);
        channel_quantities.push_back(StreamingLineBuffer_13_out0_stream_prepad[10].size());
        stream_max_size[499] = std::max<size_t>(StreamingLineBuffer_13_out0_stream_prepad[11].size(), stream_max_size[499]);
        channel_quantities.push_back(StreamingLineBuffer_13_out0_stream_prepad[11].size());
        stream_max_size[500] = std::max<size_t>(StreamingLineBuffer_13_buffer_stream[0].size(), stream_max_size[500]);
        channel_quantities.push_back(StreamingLineBuffer_13_buffer_stream[0].size());
        stream_max_size[501] = std::max<size_t>(StreamingLineBuffer_13_buffer_stream[1].size(), stream_max_size[501]);
        channel_quantities.push_back(StreamingLineBuffer_13_buffer_stream[1].size());
        stream_max_size[502] = std::max<size_t>(StreamingLineBuffer_13_buffer_stream[2].size(), stream_max_size[502]);
        channel_quantities.push_back(StreamingLineBuffer_13_buffer_stream[2].size());
        stream_max_size[503] = std::max<size_t>(StreamingLineBuffer_13_buffer_stream[3].size(), stream_max_size[503]);
        channel_quantities.push_back(StreamingLineBuffer_13_buffer_stream[3].size());
        stream_max_size[504] = std::max<size_t>(StreamingLineBuffer_13_buffer_stream[4].size(), stream_max_size[504]);
        channel_quantities.push_back(StreamingLineBuffer_13_buffer_stream[4].size());
        stream_max_size[505] = std::max<size_t>(StreamingLineBuffer_13_buffer_stream[5].size(), stream_max_size[505]);
        channel_quantities.push_back(StreamingLineBuffer_13_buffer_stream[5].size());
        stream_max_size[506] = std::max<size_t>(StreamingLineBuffer_13_buffer_stream[6].size(), stream_max_size[506]);
        channel_quantities.push_back(StreamingLineBuffer_13_buffer_stream[6].size());
        stream_max_size[507] = std::max<size_t>(StreamingLineBuffer_13_buffer_stream[7].size(), stream_max_size[507]);
        channel_quantities.push_back(StreamingLineBuffer_13_buffer_stream[7].size());
        stream_max_size[508] = std::max<size_t>(StreamingLineBuffer_13_buffer_stream[8].size(), stream_max_size[508]);
        channel_quantities.push_back(StreamingLineBuffer_13_buffer_stream[8].size());
        stream_max_size[509] = std::max<size_t>(StreamingLineBuffer_13_buffer_stream[9].size(), stream_max_size[509]);
        channel_quantities.push_back(StreamingLineBuffer_13_buffer_stream[9].size());
        stream_max_size[510] = std::max<size_t>(StreamingMemory_46_out0_stream[0].size(), stream_max_size[510]);
        channel_quantities.push_back(StreamingMemory_46_out0_stream[0].size());
        stream_max_size[511] = std::max<size_t>(StreamingMemory_46_out1_stream[0].size(), stream_max_size[511]);
        channel_quantities.push_back(StreamingMemory_46_out1_stream[0].size());
        stream_max_size[512] = std::max<size_t>(StreamingDepthwiseConv_4_out0_stream[0].size(), stream_max_size[512]);
        channel_quantities.push_back(StreamingDepthwiseConv_4_out0_stream[0].size());
        stream_max_size[513] = std::max<size_t>(StreamingDepthwiseConv_4_out0_stream[1].size(), stream_max_size[513]);
        channel_quantities.push_back(StreamingDepthwiseConv_4_out0_stream[1].size());
        stream_max_size[514] = std::max<size_t>(StreamingMemory_47_out0_stream[0].size(), stream_max_size[514]);
        channel_quantities.push_back(StreamingMemory_47_out0_stream[0].size());
        stream_max_size[515] = std::max<size_t>(StreamingMemory_47_out1_stream[0].size(), stream_max_size[515]);
        channel_quantities.push_back(StreamingMemory_47_out1_stream[0].size());
        stream_max_size[516] = std::max<size_t>(BandwidthAdjustIncreaseChannels_8_out0_stream[0].size(), stream_max_size[516]);
        channel_quantities.push_back(BandwidthAdjustIncreaseChannels_8_out0_stream[0].size());
        stream_max_size[517] = std::max<size_t>(BandwidthAdjustIncreaseChannels_8_out0_stream[1].size(), stream_max_size[517]);
        channel_quantities.push_back(BandwidthAdjustIncreaseChannels_8_out0_stream[1].size());
        stream_max_size[518] = std::max<size_t>(StreamingMemory_48_out0_stream[0].size(), stream_max_size[518]);
        channel_quantities.push_back(StreamingMemory_48_out0_stream[0].size());
        stream_max_size[519] = std::max<size_t>(StreamingMemory_48_out1_stream[0].size(), stream_max_size[519]);
        channel_quantities.push_back(StreamingMemory_48_out1_stream[0].size());
        stream_max_size[520] = std::max<size_t>(StreamingLineBuffer_14_out0_stream[0].size(), stream_max_size[520]);
        channel_quantities.push_back(StreamingLineBuffer_14_out0_stream[0].size());
        stream_max_size[521] = std::max<size_t>(StreamingLineBuffer_14_out0_stream[1].size(), stream_max_size[521]);
        channel_quantities.push_back(StreamingLineBuffer_14_out0_stream[1].size());
        stream_max_size[522] = std::max<size_t>(StreamingMemory_49_out0_stream[0].size(), stream_max_size[522]);
        channel_quantities.push_back(StreamingMemory_49_out0_stream[0].size());
        stream_max_size[523] = std::max<size_t>(StreamingMemory_49_out1_stream[0].size(), stream_max_size[523]);
        channel_quantities.push_back(StreamingMemory_49_out1_stream[0].size());
        stream_max_size[524] = std::max<size_t>(StreamingConv_9_out0_stream[0].size(), stream_max_size[524]);
        channel_quantities.push_back(StreamingConv_9_out0_stream[0].size());
        stream_max_size[525] = std::max<size_t>(StreamingConv_9_out0_stream[1].size(), stream_max_size[525]);
        channel_quantities.push_back(StreamingConv_9_out0_stream[1].size());
        stream_max_size[526] = std::max<size_t>(StreamingMemory_50_out0_stream[0].size(), stream_max_size[526]);
        channel_quantities.push_back(StreamingMemory_50_out0_stream[0].size());
        stream_max_size[527] = std::max<size_t>(StreamingMemory_50_out0_stream[1].size(), stream_max_size[527]);
        channel_quantities.push_back(StreamingMemory_50_out0_stream[1].size());
        stream_max_size[528] = std::max<size_t>(StreamingMemory_50_out0_stream[2].size(), stream_max_size[528]);
        channel_quantities.push_back(StreamingMemory_50_out0_stream[2].size());
        stream_max_size[529] = std::max<size_t>(StreamingMemory_50_out0_stream[3].size(), stream_max_size[529]);
        channel_quantities.push_back(StreamingMemory_50_out0_stream[3].size());
        stream_max_size[530] = std::max<size_t>(StreamingMemory_50_out0_stream[4].size(), stream_max_size[530]);
        channel_quantities.push_back(StreamingMemory_50_out0_stream[4].size());
        stream_max_size[531] = std::max<size_t>(StreamingMemory_50_out0_stream[5].size(), stream_max_size[531]);
        channel_quantities.push_back(StreamingMemory_50_out0_stream[5].size());
        stream_max_size[532] = std::max<size_t>(StreamingMemory_50_out0_stream[6].size(), stream_max_size[532]);
        channel_quantities.push_back(StreamingMemory_50_out0_stream[6].size());
        stream_max_size[533] = std::max<size_t>(StreamingMemory_50_out0_stream[7].size(), stream_max_size[533]);
        channel_quantities.push_back(StreamingMemory_50_out0_stream[7].size());
        stream_max_size[534] = std::max<size_t>(StreamingMemory_50_out0_stream[8].size(), stream_max_size[534]);
        channel_quantities.push_back(StreamingMemory_50_out0_stream[8].size());
        stream_max_size[535] = std::max<size_t>(StreamingMemory_50_out1_stream[0].size(), stream_max_size[535]);
        channel_quantities.push_back(StreamingMemory_50_out1_stream[0].size());
        stream_max_size[536] = std::max<size_t>(StreamingAdd_1_out0_stream[0].size(), stream_max_size[536]);
        channel_quantities.push_back(StreamingAdd_1_out0_stream[0].size());
        stream_max_size[537] = std::max<size_t>(StreamingAdd_1_out0_stream[1].size(), stream_max_size[537]);
        channel_quantities.push_back(StreamingAdd_1_out0_stream[1].size());
        stream_max_size[538] = std::max<size_t>(StreamingMemory_51_out0_stream[0].size(), stream_max_size[538]);
        channel_quantities.push_back(StreamingMemory_51_out0_stream[0].size());
        stream_max_size[539] = std::max<size_t>(StreamingMemory_51_out1_stream[0].size(), stream_max_size[539]);
        channel_quantities.push_back(StreamingMemory_51_out1_stream[0].size());
        stream_max_size[540] = std::max<size_t>(BandwidthAdjustDecreaseChannels_5_out0_stream[0].size(), stream_max_size[540]);
        channel_quantities.push_back(BandwidthAdjustDecreaseChannels_5_out0_stream[0].size());
        stream_max_size[541] = std::max<size_t>(BandwidthAdjustDecreaseChannels_5_out0_stream[1].size(), stream_max_size[541]);
        channel_quantities.push_back(BandwidthAdjustDecreaseChannels_5_out0_stream[1].size());
        stream_max_size[542] = std::max<size_t>(StreamingMemory_52_out0_stream[0].size(), stream_max_size[542]);
        channel_quantities.push_back(StreamingMemory_52_out0_stream[0].size());
        stream_max_size[543] = std::max<size_t>(StreamingMemory_52_out1_stream[0].size(), stream_max_size[543]);
        channel_quantities.push_back(StreamingMemory_52_out1_stream[0].size());
        stream_max_size[544] = std::max<size_t>(TensorDuplicator_2_out0_stream[0].size(), stream_max_size[544]);
        channel_quantities.push_back(TensorDuplicator_2_out0_stream[0].size());
        stream_max_size[545] = std::max<size_t>(TensorDuplicator_2_out0_stream[1].size(), stream_max_size[545]);
        channel_quantities.push_back(TensorDuplicator_2_out0_stream[1].size());
        stream_max_size[546] = std::max<size_t>(TensorDuplicator_2_out1_stream[0].size(), stream_max_size[546]);
        channel_quantities.push_back(TensorDuplicator_2_out1_stream[0].size());
        stream_max_size[547] = std::max<size_t>(TensorDuplicator_2_out1_stream[1].size(), stream_max_size[547]);
        channel_quantities.push_back(TensorDuplicator_2_out1_stream[1].size());
        stream_max_size[548] = std::max<size_t>(StreamingMemory_53_out0_stream[0].size(), stream_max_size[548]);
        channel_quantities.push_back(StreamingMemory_53_out0_stream[0].size());
        stream_max_size[549] = std::max<size_t>(StreamingMemory_53_out1_stream[0].size(), stream_max_size[549]);
        channel_quantities.push_back(StreamingMemory_53_out1_stream[0].size());
        stream_max_size[550] = std::max<size_t>(BandwidthAdjustIncreaseChannels_9_out0_stream[0].size(), stream_max_size[550]);
        channel_quantities.push_back(BandwidthAdjustIncreaseChannels_9_out0_stream[0].size());
        stream_max_size[551] = std::max<size_t>(BandwidthAdjustIncreaseChannels_9_out0_stream[1].size(), stream_max_size[551]);
        channel_quantities.push_back(BandwidthAdjustIncreaseChannels_9_out0_stream[1].size());
        stream_max_size[552] = std::max<size_t>(BandwidthAdjustIncreaseChannels_10_out0_stream[0].size(), stream_max_size[552]);
        channel_quantities.push_back(BandwidthAdjustIncreaseChannels_10_out0_stream[0].size());
        stream_max_size[553] = std::max<size_t>(BandwidthAdjustIncreaseChannels_10_out0_stream[1].size(), stream_max_size[553]);
        channel_quantities.push_back(BandwidthAdjustIncreaseChannels_10_out0_stream[1].size());
        stream_max_size[554] = std::max<size_t>(StreamingMemory_54_out0_stream[0].size(), stream_max_size[554]);
        channel_quantities.push_back(StreamingMemory_54_out0_stream[0].size());
        stream_max_size[555] = std::max<size_t>(StreamingMemory_54_out1_stream[0].size(), stream_max_size[555]);
        channel_quantities.push_back(StreamingMemory_54_out1_stream[0].size());
        stream_max_size[556] = std::max<size_t>(StreamingLineBuffer_15_out0_stream[0].size(), stream_max_size[556]);
        channel_quantities.push_back(StreamingLineBuffer_15_out0_stream[0].size());
        stream_max_size[557] = std::max<size_t>(StreamingLineBuffer_15_out0_stream[1].size(), stream_max_size[557]);
        channel_quantities.push_back(StreamingLineBuffer_15_out0_stream[1].size());
        stream_max_size[558] = std::max<size_t>(StreamingMemory_55_out0_stream[0].size(), stream_max_size[558]);
        channel_quantities.push_back(StreamingMemory_55_out0_stream[0].size());
        stream_max_size[559] = std::max<size_t>(StreamingMemory_55_out1_stream[0].size(), stream_max_size[559]);
        channel_quantities.push_back(StreamingMemory_55_out1_stream[0].size());
        stream_max_size[560] = std::max<size_t>(StreamingConv_10_out0_stream[0].size(), stream_max_size[560]);
        channel_quantities.push_back(StreamingConv_10_out0_stream[0].size());
        stream_max_size[561] = std::max<size_t>(StreamingConv_10_out0_stream[1].size(), stream_max_size[561]);
        channel_quantities.push_back(StreamingConv_10_out0_stream[1].size());
        stream_max_size[562] = std::max<size_t>(StreamingMemory_56_out0_stream[0].size(), stream_max_size[562]);
        channel_quantities.push_back(StreamingMemory_56_out0_stream[0].size());
        stream_max_size[563] = std::max<size_t>(StreamingMemory_56_out0_stream[1].size(), stream_max_size[563]);
        channel_quantities.push_back(StreamingMemory_56_out0_stream[1].size());
        stream_max_size[564] = std::max<size_t>(StreamingMemory_56_out0_stream[2].size(), stream_max_size[564]);
        channel_quantities.push_back(StreamingMemory_56_out0_stream[2].size());
        stream_max_size[565] = std::max<size_t>(StreamingMemory_56_out0_stream[3].size(), stream_max_size[565]);
        channel_quantities.push_back(StreamingMemory_56_out0_stream[3].size());
        stream_max_size[566] = std::max<size_t>(StreamingMemory_56_out0_stream[4].size(), stream_max_size[566]);
        channel_quantities.push_back(StreamingMemory_56_out0_stream[4].size());
        stream_max_size[567] = std::max<size_t>(StreamingMemory_56_out0_stream[5].size(), stream_max_size[567]);
        channel_quantities.push_back(StreamingMemory_56_out0_stream[5].size());
        stream_max_size[568] = std::max<size_t>(StreamingMemory_56_out0_stream[6].size(), stream_max_size[568]);
        channel_quantities.push_back(StreamingMemory_56_out0_stream[6].size());
        stream_max_size[569] = std::max<size_t>(StreamingMemory_56_out0_stream[7].size(), stream_max_size[569]);
        channel_quantities.push_back(StreamingMemory_56_out0_stream[7].size());
        stream_max_size[570] = std::max<size_t>(StreamingMemory_56_out0_stream[8].size(), stream_max_size[570]);
        channel_quantities.push_back(StreamingMemory_56_out0_stream[8].size());
        stream_max_size[571] = std::max<size_t>(StreamingMemory_56_out1_stream[0].size(), stream_max_size[571]);
        channel_quantities.push_back(StreamingMemory_56_out1_stream[0].size());
        stream_max_size[572] = std::max<size_t>(BandwidthAdjustDecreaseChannels_6_out0_stream[0].size(), stream_max_size[572]);
        channel_quantities.push_back(BandwidthAdjustDecreaseChannels_6_out0_stream[0].size());
        stream_max_size[573] = std::max<size_t>(BandwidthAdjustDecreaseChannels_6_out0_stream[1].size(), stream_max_size[573]);
        channel_quantities.push_back(BandwidthAdjustDecreaseChannels_6_out0_stream[1].size());
        stream_max_size[574] = std::max<size_t>(StreamingMemory_57_out0_stream[0].size(), stream_max_size[574]);
        channel_quantities.push_back(StreamingMemory_57_out0_stream[0].size());
        stream_max_size[575] = std::max<size_t>(StreamingMemory_57_out1_stream[0].size(), stream_max_size[575]);
        channel_quantities.push_back(StreamingMemory_57_out1_stream[0].size());
        stream_max_size[576] = std::max<size_t>(StreamingLineBuffer_16_out0_stream[0].size(), stream_max_size[576]);
        channel_quantities.push_back(StreamingLineBuffer_16_out0_stream[0].size());
        stream_max_size[577] = std::max<size_t>(StreamingLineBuffer_16_out0_stream[1].size(), stream_max_size[577]);
        channel_quantities.push_back(StreamingLineBuffer_16_out0_stream[1].size());
        stream_max_size[578] = std::max<size_t>(StreamingLineBuffer_16_out0_stream[2].size(), stream_max_size[578]);
        channel_quantities.push_back(StreamingLineBuffer_16_out0_stream[2].size());
        stream_max_size[579] = std::max<size_t>(StreamingLineBuffer_16_out0_stream[3].size(), stream_max_size[579]);
        channel_quantities.push_back(StreamingLineBuffer_16_out0_stream[3].size());
        stream_max_size[580] = std::max<size_t>(StreamingLineBuffer_16_out0_stream[4].size(), stream_max_size[580]);
        channel_quantities.push_back(StreamingLineBuffer_16_out0_stream[4].size());
        stream_max_size[581] = std::max<size_t>(StreamingLineBuffer_16_out0_stream[5].size(), stream_max_size[581]);
        channel_quantities.push_back(StreamingLineBuffer_16_out0_stream[5].size());
        stream_max_size[582] = std::max<size_t>(StreamingLineBuffer_16_out0_stream[6].size(), stream_max_size[582]);
        channel_quantities.push_back(StreamingLineBuffer_16_out0_stream[6].size());
        stream_max_size[583] = std::max<size_t>(StreamingLineBuffer_16_out0_stream[7].size(), stream_max_size[583]);
        channel_quantities.push_back(StreamingLineBuffer_16_out0_stream[7].size());
        stream_max_size[584] = std::max<size_t>(StreamingLineBuffer_16_out0_stream[8].size(), stream_max_size[584]);
        channel_quantities.push_back(StreamingLineBuffer_16_out0_stream[8].size());
        stream_max_size[585] = std::max<size_t>(StreamingLineBuffer_16_out0_stream[9].size(), stream_max_size[585]);
        channel_quantities.push_back(StreamingLineBuffer_16_out0_stream[9].size());
        stream_max_size[586] = std::max<size_t>(StreamingLineBuffer_16_out0_stream[10].size(), stream_max_size[586]);
        channel_quantities.push_back(StreamingLineBuffer_16_out0_stream[10].size());
        stream_max_size[587] = std::max<size_t>(StreamingLineBuffer_16_out0_stream[11].size(), stream_max_size[587]);
        channel_quantities.push_back(StreamingLineBuffer_16_out0_stream[11].size());
        stream_max_size[588] = std::max<size_t>(StreamingLineBuffer_16_out0_stream_prepad[0].size(), stream_max_size[588]);
        channel_quantities.push_back(StreamingLineBuffer_16_out0_stream_prepad[0].size());
        stream_max_size[589] = std::max<size_t>(StreamingLineBuffer_16_out0_stream_prepad[1].size(), stream_max_size[589]);
        channel_quantities.push_back(StreamingLineBuffer_16_out0_stream_prepad[1].size());
        stream_max_size[590] = std::max<size_t>(StreamingLineBuffer_16_out0_stream_prepad[2].size(), stream_max_size[590]);
        channel_quantities.push_back(StreamingLineBuffer_16_out0_stream_prepad[2].size());
        stream_max_size[591] = std::max<size_t>(StreamingLineBuffer_16_out0_stream_prepad[3].size(), stream_max_size[591]);
        channel_quantities.push_back(StreamingLineBuffer_16_out0_stream_prepad[3].size());
        stream_max_size[592] = std::max<size_t>(StreamingLineBuffer_16_out0_stream_prepad[4].size(), stream_max_size[592]);
        channel_quantities.push_back(StreamingLineBuffer_16_out0_stream_prepad[4].size());
        stream_max_size[593] = std::max<size_t>(StreamingLineBuffer_16_out0_stream_prepad[5].size(), stream_max_size[593]);
        channel_quantities.push_back(StreamingLineBuffer_16_out0_stream_prepad[5].size());
        stream_max_size[594] = std::max<size_t>(StreamingLineBuffer_16_out0_stream_prepad[6].size(), stream_max_size[594]);
        channel_quantities.push_back(StreamingLineBuffer_16_out0_stream_prepad[6].size());
        stream_max_size[595] = std::max<size_t>(StreamingLineBuffer_16_out0_stream_prepad[7].size(), stream_max_size[595]);
        channel_quantities.push_back(StreamingLineBuffer_16_out0_stream_prepad[7].size());
        stream_max_size[596] = std::max<size_t>(StreamingLineBuffer_16_out0_stream_prepad[8].size(), stream_max_size[596]);
        channel_quantities.push_back(StreamingLineBuffer_16_out0_stream_prepad[8].size());
        stream_max_size[597] = std::max<size_t>(StreamingLineBuffer_16_out0_stream_prepad[9].size(), stream_max_size[597]);
        channel_quantities.push_back(StreamingLineBuffer_16_out0_stream_prepad[9].size());
        stream_max_size[598] = std::max<size_t>(StreamingLineBuffer_16_out0_stream_prepad[10].size(), stream_max_size[598]);
        channel_quantities.push_back(StreamingLineBuffer_16_out0_stream_prepad[10].size());
        stream_max_size[599] = std::max<size_t>(StreamingLineBuffer_16_out0_stream_prepad[11].size(), stream_max_size[599]);
        channel_quantities.push_back(StreamingLineBuffer_16_out0_stream_prepad[11].size());
        stream_max_size[600] = std::max<size_t>(StreamingLineBuffer_16_buffer_stream[0].size(), stream_max_size[600]);
        channel_quantities.push_back(StreamingLineBuffer_16_buffer_stream[0].size());
        stream_max_size[601] = std::max<size_t>(StreamingLineBuffer_16_buffer_stream[1].size(), stream_max_size[601]);
        channel_quantities.push_back(StreamingLineBuffer_16_buffer_stream[1].size());
        stream_max_size[602] = std::max<size_t>(StreamingLineBuffer_16_buffer_stream[2].size(), stream_max_size[602]);
        channel_quantities.push_back(StreamingLineBuffer_16_buffer_stream[2].size());
        stream_max_size[603] = std::max<size_t>(StreamingLineBuffer_16_buffer_stream[3].size(), stream_max_size[603]);
        channel_quantities.push_back(StreamingLineBuffer_16_buffer_stream[3].size());
        stream_max_size[604] = std::max<size_t>(StreamingLineBuffer_16_buffer_stream[4].size(), stream_max_size[604]);
        channel_quantities.push_back(StreamingLineBuffer_16_buffer_stream[4].size());
        stream_max_size[605] = std::max<size_t>(StreamingLineBuffer_16_buffer_stream[5].size(), stream_max_size[605]);
        channel_quantities.push_back(StreamingLineBuffer_16_buffer_stream[5].size());
        stream_max_size[606] = std::max<size_t>(StreamingLineBuffer_16_buffer_stream[6].size(), stream_max_size[606]);
        channel_quantities.push_back(StreamingLineBuffer_16_buffer_stream[6].size());
        stream_max_size[607] = std::max<size_t>(StreamingLineBuffer_16_buffer_stream[7].size(), stream_max_size[607]);
        channel_quantities.push_back(StreamingLineBuffer_16_buffer_stream[7].size());
        stream_max_size[608] = std::max<size_t>(StreamingLineBuffer_16_buffer_stream[8].size(), stream_max_size[608]);
        channel_quantities.push_back(StreamingLineBuffer_16_buffer_stream[8].size());
        stream_max_size[609] = std::max<size_t>(StreamingLineBuffer_16_buffer_stream[9].size(), stream_max_size[609]);
        channel_quantities.push_back(StreamingLineBuffer_16_buffer_stream[9].size());
        stream_max_size[610] = std::max<size_t>(StreamingMemory_58_out0_stream[0].size(), stream_max_size[610]);
        channel_quantities.push_back(StreamingMemory_58_out0_stream[0].size());
        stream_max_size[611] = std::max<size_t>(StreamingMemory_58_out1_stream[0].size(), stream_max_size[611]);
        channel_quantities.push_back(StreamingMemory_58_out1_stream[0].size());
        stream_max_size[612] = std::max<size_t>(StreamingDepthwiseConv_5_out0_stream[0].size(), stream_max_size[612]);
        channel_quantities.push_back(StreamingDepthwiseConv_5_out0_stream[0].size());
        stream_max_size[613] = std::max<size_t>(StreamingDepthwiseConv_5_out0_stream[1].size(), stream_max_size[613]);
        channel_quantities.push_back(StreamingDepthwiseConv_5_out0_stream[1].size());
        stream_max_size[614] = std::max<size_t>(StreamingMemory_59_out0_stream[0].size(), stream_max_size[614]);
        channel_quantities.push_back(StreamingMemory_59_out0_stream[0].size());
        stream_max_size[615] = std::max<size_t>(StreamingMemory_59_out1_stream[0].size(), stream_max_size[615]);
        channel_quantities.push_back(StreamingMemory_59_out1_stream[0].size());
        stream_max_size[616] = std::max<size_t>(BandwidthAdjustIncreaseChannels_11_out0_stream[0].size(), stream_max_size[616]);
        channel_quantities.push_back(BandwidthAdjustIncreaseChannels_11_out0_stream[0].size());
        stream_max_size[617] = std::max<size_t>(BandwidthAdjustIncreaseChannels_11_out0_stream[1].size(), stream_max_size[617]);
        channel_quantities.push_back(BandwidthAdjustIncreaseChannels_11_out0_stream[1].size());
        stream_max_size[618] = std::max<size_t>(StreamingMemory_60_out0_stream[0].size(), stream_max_size[618]);
        channel_quantities.push_back(StreamingMemory_60_out0_stream[0].size());
        stream_max_size[619] = std::max<size_t>(StreamingMemory_60_out1_stream[0].size(), stream_max_size[619]);
        channel_quantities.push_back(StreamingMemory_60_out1_stream[0].size());
        stream_max_size[620] = std::max<size_t>(StreamingLineBuffer_17_out0_stream[0].size(), stream_max_size[620]);
        channel_quantities.push_back(StreamingLineBuffer_17_out0_stream[0].size());
        stream_max_size[621] = std::max<size_t>(StreamingLineBuffer_17_out0_stream[1].size(), stream_max_size[621]);
        channel_quantities.push_back(StreamingLineBuffer_17_out0_stream[1].size());
        stream_max_size[622] = std::max<size_t>(StreamingMemory_61_out0_stream[0].size(), stream_max_size[622]);
        channel_quantities.push_back(StreamingMemory_61_out0_stream[0].size());
        stream_max_size[623] = std::max<size_t>(StreamingMemory_61_out1_stream[0].size(), stream_max_size[623]);
        channel_quantities.push_back(StreamingMemory_61_out1_stream[0].size());
        stream_max_size[624] = std::max<size_t>(StreamingConv_11_out0_stream[0].size(), stream_max_size[624]);
        channel_quantities.push_back(StreamingConv_11_out0_stream[0].size());
        stream_max_size[625] = std::max<size_t>(StreamingConv_11_out0_stream[1].size(), stream_max_size[625]);
        channel_quantities.push_back(StreamingConv_11_out0_stream[1].size());
        stream_max_size[626] = std::max<size_t>(StreamingMemory_62_out0_stream[0].size(), stream_max_size[626]);
        channel_quantities.push_back(StreamingMemory_62_out0_stream[0].size());
        stream_max_size[627] = std::max<size_t>(StreamingMemory_62_out0_stream[1].size(), stream_max_size[627]);
        channel_quantities.push_back(StreamingMemory_62_out0_stream[1].size());
        stream_max_size[628] = std::max<size_t>(StreamingMemory_62_out0_stream[2].size(), stream_max_size[628]);
        channel_quantities.push_back(StreamingMemory_62_out0_stream[2].size());
        stream_max_size[629] = std::max<size_t>(StreamingMemory_62_out0_stream[3].size(), stream_max_size[629]);
        channel_quantities.push_back(StreamingMemory_62_out0_stream[3].size());
        stream_max_size[630] = std::max<size_t>(StreamingMemory_62_out0_stream[4].size(), stream_max_size[630]);
        channel_quantities.push_back(StreamingMemory_62_out0_stream[4].size());
        stream_max_size[631] = std::max<size_t>(StreamingMemory_62_out0_stream[5].size(), stream_max_size[631]);
        channel_quantities.push_back(StreamingMemory_62_out0_stream[5].size());
        stream_max_size[632] = std::max<size_t>(StreamingMemory_62_out0_stream[6].size(), stream_max_size[632]);
        channel_quantities.push_back(StreamingMemory_62_out0_stream[6].size());
        stream_max_size[633] = std::max<size_t>(StreamingMemory_62_out0_stream[7].size(), stream_max_size[633]);
        channel_quantities.push_back(StreamingMemory_62_out0_stream[7].size());
        stream_max_size[634] = std::max<size_t>(StreamingMemory_62_out0_stream[8].size(), stream_max_size[634]);
        channel_quantities.push_back(StreamingMemory_62_out0_stream[8].size());
        stream_max_size[635] = std::max<size_t>(StreamingMemory_62_out1_stream[0].size(), stream_max_size[635]);
        channel_quantities.push_back(StreamingMemory_62_out1_stream[0].size());
        stream_max_size[636] = std::max<size_t>(StreamingAdd_2_out0_stream[0].size(), stream_max_size[636]);
        channel_quantities.push_back(StreamingAdd_2_out0_stream[0].size());
        stream_max_size[637] = std::max<size_t>(StreamingAdd_2_out0_stream[1].size(), stream_max_size[637]);
        channel_quantities.push_back(StreamingAdd_2_out0_stream[1].size());
        stream_max_size[638] = std::max<size_t>(StreamingMemory_63_out0_stream[0].size(), stream_max_size[638]);
        channel_quantities.push_back(StreamingMemory_63_out0_stream[0].size());
        stream_max_size[639] = std::max<size_t>(StreamingMemory_63_out1_stream[0].size(), stream_max_size[639]);
        channel_quantities.push_back(StreamingMemory_63_out1_stream[0].size());
        stream_max_size[640] = std::max<size_t>(StreamingLineBuffer_18_out0_stream[0].size(), stream_max_size[640]);
        channel_quantities.push_back(StreamingLineBuffer_18_out0_stream[0].size());
        stream_max_size[641] = std::max<size_t>(StreamingLineBuffer_18_out0_stream[1].size(), stream_max_size[641]);
        channel_quantities.push_back(StreamingLineBuffer_18_out0_stream[1].size());
        stream_max_size[642] = std::max<size_t>(StreamingMemory_64_out0_stream[0].size(), stream_max_size[642]);
        channel_quantities.push_back(StreamingMemory_64_out0_stream[0].size());
        stream_max_size[643] = std::max<size_t>(StreamingMemory_64_out1_stream[0].size(), stream_max_size[643]);
        channel_quantities.push_back(StreamingMemory_64_out1_stream[0].size());
        stream_max_size[644] = std::max<size_t>(StreamingConv_12_out0_stream[0].size(), stream_max_size[644]);
        channel_quantities.push_back(StreamingConv_12_out0_stream[0].size());
        stream_max_size[645] = std::max<size_t>(StreamingConv_12_out0_stream[1].size(), stream_max_size[645]);
        channel_quantities.push_back(StreamingConv_12_out0_stream[1].size());
        stream_max_size[646] = std::max<size_t>(StreamingMemory_65_out0_stream[0].size(), stream_max_size[646]);
        channel_quantities.push_back(StreamingMemory_65_out0_stream[0].size());
        stream_max_size[647] = std::max<size_t>(StreamingMemory_65_out1_stream[0].size(), stream_max_size[647]);
        channel_quantities.push_back(StreamingMemory_65_out1_stream[0].size());
        stream_max_size[648] = std::max<size_t>(BandwidthAdjustDecreaseChannels_7_out0_stream[0].size(), stream_max_size[648]);
        channel_quantities.push_back(BandwidthAdjustDecreaseChannels_7_out0_stream[0].size());
        stream_max_size[649] = std::max<size_t>(BandwidthAdjustDecreaseChannels_7_out0_stream[1].size(), stream_max_size[649]);
        channel_quantities.push_back(BandwidthAdjustDecreaseChannels_7_out0_stream[1].size());
        stream_max_size[650] = std::max<size_t>(StreamingMemory_66_out0_stream[0].size(), stream_max_size[650]);
        channel_quantities.push_back(StreamingMemory_66_out0_stream[0].size());
        stream_max_size[651] = std::max<size_t>(StreamingMemory_66_out1_stream[0].size(), stream_max_size[651]);
        channel_quantities.push_back(StreamingMemory_66_out1_stream[0].size());
        stream_max_size[652] = std::max<size_t>(BandwidthAdjustDecreaseStreams_3_out0_stream[0].size(), stream_max_size[652]);
        channel_quantities.push_back(BandwidthAdjustDecreaseStreams_3_out0_stream[0].size());
        stream_max_size[653] = std::max<size_t>(StreamingMemory_67_out0_stream[0].size(), stream_max_size[653]);
        channel_quantities.push_back(StreamingMemory_67_out0_stream[0].size());
        stream_max_size[654] = std::max<size_t>(StreamingMemory_67_out1_stream[0].size(), stream_max_size[654]);
        channel_quantities.push_back(StreamingMemory_67_out1_stream[0].size());
        stream_max_size[655] = std::max<size_t>(StreamingLineBuffer_19_out0_stream[0].size(), stream_max_size[655]);
        channel_quantities.push_back(StreamingLineBuffer_19_out0_stream[0].size());
        stream_max_size[656] = std::max<size_t>(StreamingLineBuffer_19_out0_stream[1].size(), stream_max_size[656]);
        channel_quantities.push_back(StreamingLineBuffer_19_out0_stream[1].size());
        stream_max_size[657] = std::max<size_t>(StreamingLineBuffer_19_out0_stream[2].size(), stream_max_size[657]);
        channel_quantities.push_back(StreamingLineBuffer_19_out0_stream[2].size());
        stream_max_size[658] = std::max<size_t>(StreamingLineBuffer_19_out0_stream[3].size(), stream_max_size[658]);
        channel_quantities.push_back(StreamingLineBuffer_19_out0_stream[3].size());
        stream_max_size[659] = std::max<size_t>(StreamingLineBuffer_19_out0_stream[4].size(), stream_max_size[659]);
        channel_quantities.push_back(StreamingLineBuffer_19_out0_stream[4].size());
        stream_max_size[660] = std::max<size_t>(StreamingLineBuffer_19_out0_stream[5].size(), stream_max_size[660]);
        channel_quantities.push_back(StreamingLineBuffer_19_out0_stream[5].size());
        stream_max_size[661] = std::max<size_t>(StreamingLineBuffer_19_out0_stream[6].size(), stream_max_size[661]);
        channel_quantities.push_back(StreamingLineBuffer_19_out0_stream[6].size());
        stream_max_size[662] = std::max<size_t>(StreamingLineBuffer_19_out0_stream[7].size(), stream_max_size[662]);
        channel_quantities.push_back(StreamingLineBuffer_19_out0_stream[7].size());
        stream_max_size[663] = std::max<size_t>(StreamingLineBuffer_19_out0_stream[8].size(), stream_max_size[663]);
        channel_quantities.push_back(StreamingLineBuffer_19_out0_stream[8].size());
        stream_max_size[664] = std::max<size_t>(StreamingLineBuffer_19_out0_stream_prepad[0].size(), stream_max_size[664]);
        channel_quantities.push_back(StreamingLineBuffer_19_out0_stream_prepad[0].size());
        stream_max_size[665] = std::max<size_t>(StreamingLineBuffer_19_out0_stream_prepad[1].size(), stream_max_size[665]);
        channel_quantities.push_back(StreamingLineBuffer_19_out0_stream_prepad[1].size());
        stream_max_size[666] = std::max<size_t>(StreamingLineBuffer_19_out0_stream_prepad[2].size(), stream_max_size[666]);
        channel_quantities.push_back(StreamingLineBuffer_19_out0_stream_prepad[2].size());
        stream_max_size[667] = std::max<size_t>(StreamingLineBuffer_19_out0_stream_prepad[3].size(), stream_max_size[667]);
        channel_quantities.push_back(StreamingLineBuffer_19_out0_stream_prepad[3].size());
        stream_max_size[668] = std::max<size_t>(StreamingLineBuffer_19_out0_stream_prepad[4].size(), stream_max_size[668]);
        channel_quantities.push_back(StreamingLineBuffer_19_out0_stream_prepad[4].size());
        stream_max_size[669] = std::max<size_t>(StreamingLineBuffer_19_out0_stream_prepad[5].size(), stream_max_size[669]);
        channel_quantities.push_back(StreamingLineBuffer_19_out0_stream_prepad[5].size());
        stream_max_size[670] = std::max<size_t>(StreamingLineBuffer_19_out0_stream_prepad[6].size(), stream_max_size[670]);
        channel_quantities.push_back(StreamingLineBuffer_19_out0_stream_prepad[6].size());
        stream_max_size[671] = std::max<size_t>(StreamingLineBuffer_19_out0_stream_prepad[7].size(), stream_max_size[671]);
        channel_quantities.push_back(StreamingLineBuffer_19_out0_stream_prepad[7].size());
        stream_max_size[672] = std::max<size_t>(StreamingLineBuffer_19_out0_stream_prepad[8].size(), stream_max_size[672]);
        channel_quantities.push_back(StreamingLineBuffer_19_out0_stream_prepad[8].size());
        stream_max_size[673] = std::max<size_t>(StreamingLineBuffer_19_buffer_stream[0].size(), stream_max_size[673]);
        channel_quantities.push_back(StreamingLineBuffer_19_buffer_stream[0].size());
        stream_max_size[674] = std::max<size_t>(StreamingLineBuffer_19_buffer_stream[1].size(), stream_max_size[674]);
        channel_quantities.push_back(StreamingLineBuffer_19_buffer_stream[1].size());
        stream_max_size[675] = std::max<size_t>(StreamingLineBuffer_19_buffer_stream[2].size(), stream_max_size[675]);
        channel_quantities.push_back(StreamingLineBuffer_19_buffer_stream[2].size());
        stream_max_size[676] = std::max<size_t>(StreamingLineBuffer_19_buffer_stream[3].size(), stream_max_size[676]);
        channel_quantities.push_back(StreamingLineBuffer_19_buffer_stream[3].size());
        stream_max_size[677] = std::max<size_t>(StreamingLineBuffer_19_buffer_stream[4].size(), stream_max_size[677]);
        channel_quantities.push_back(StreamingLineBuffer_19_buffer_stream[4].size());
        stream_max_size[678] = std::max<size_t>(StreamingLineBuffer_19_buffer_stream[5].size(), stream_max_size[678]);
        channel_quantities.push_back(StreamingLineBuffer_19_buffer_stream[5].size());
        stream_max_size[679] = std::max<size_t>(StreamingLineBuffer_19_buffer_stream[6].size(), stream_max_size[679]);
        channel_quantities.push_back(StreamingLineBuffer_19_buffer_stream[6].size());
        stream_max_size[680] = std::max<size_t>(StreamingLineBuffer_19_buffer_stream[7].size(), stream_max_size[680]);
        channel_quantities.push_back(StreamingLineBuffer_19_buffer_stream[7].size());
        stream_max_size[681] = std::max<size_t>(StreamingMemory_68_out0_stream[0].size(), stream_max_size[681]);
        channel_quantities.push_back(StreamingMemory_68_out0_stream[0].size());
        stream_max_size[682] = std::max<size_t>(StreamingMemory_68_out0_stream[1].size(), stream_max_size[682]);
        channel_quantities.push_back(StreamingMemory_68_out0_stream[1].size());
        stream_max_size[683] = std::max<size_t>(StreamingMemory_68_out0_stream[2].size(), stream_max_size[683]);
        channel_quantities.push_back(StreamingMemory_68_out0_stream[2].size());
        stream_max_size[684] = std::max<size_t>(StreamingMemory_68_out0_stream[3].size(), stream_max_size[684]);
        channel_quantities.push_back(StreamingMemory_68_out0_stream[3].size());
        stream_max_size[685] = std::max<size_t>(StreamingMemory_68_out0_stream[4].size(), stream_max_size[685]);
        channel_quantities.push_back(StreamingMemory_68_out0_stream[4].size());
        stream_max_size[686] = std::max<size_t>(StreamingMemory_68_out0_stream[5].size(), stream_max_size[686]);
        channel_quantities.push_back(StreamingMemory_68_out0_stream[5].size());
        stream_max_size[687] = std::max<size_t>(StreamingMemory_68_out0_stream[6].size(), stream_max_size[687]);
        channel_quantities.push_back(StreamingMemory_68_out0_stream[6].size());
        stream_max_size[688] = std::max<size_t>(StreamingMemory_68_out0_stream[7].size(), stream_max_size[688]);
        channel_quantities.push_back(StreamingMemory_68_out0_stream[7].size());
        stream_max_size[689] = std::max<size_t>(StreamingMemory_68_out0_stream[8].size(), stream_max_size[689]);
        channel_quantities.push_back(StreamingMemory_68_out0_stream[8].size());
        stream_max_size[690] = std::max<size_t>(StreamingMemory_68_out1_stream[0].size(), stream_max_size[690]);
        channel_quantities.push_back(StreamingMemory_68_out1_stream[0].size());
        stream_max_size[691] = std::max<size_t>(StreamingDepthwiseConv_6_out0_stream[0].size(), stream_max_size[691]);
        channel_quantities.push_back(StreamingDepthwiseConv_6_out0_stream[0].size());
        stream_max_size[692] = std::max<size_t>(StreamingMemory_69_out0_stream[0].size(), stream_max_size[692]);
        channel_quantities.push_back(StreamingMemory_69_out0_stream[0].size());
        stream_max_size[693] = std::max<size_t>(StreamingMemory_69_out1_stream[0].size(), stream_max_size[693]);
        channel_quantities.push_back(StreamingMemory_69_out1_stream[0].size());
        stream_max_size[694] = std::max<size_t>(BandwidthAdjustIncreaseChannels_12_out0_stream[0].size(), stream_max_size[694]);
        channel_quantities.push_back(BandwidthAdjustIncreaseChannels_12_out0_stream[0].size());
        stream_max_size[695] = std::max<size_t>(StreamingMemory_70_out0_stream[0].size(), stream_max_size[695]);
        channel_quantities.push_back(StreamingMemory_70_out0_stream[0].size());
        stream_max_size[696] = std::max<size_t>(StreamingMemory_70_out1_stream[0].size(), stream_max_size[696]);
        channel_quantities.push_back(StreamingMemory_70_out1_stream[0].size());
        stream_max_size[697] = std::max<size_t>(StreamingConv_13_out0_stream[0].size(), stream_max_size[697]);
        channel_quantities.push_back(StreamingConv_13_out0_stream[0].size());
        stream_max_size[698] = std::max<size_t>(StreamingMemory_71_out0_stream[0].size(), stream_max_size[698]);
        channel_quantities.push_back(StreamingMemory_71_out0_stream[0].size());
        stream_max_size[699] = std::max<size_t>(StreamingMemory_71_out1_stream[0].size(), stream_max_size[699]);
        channel_quantities.push_back(StreamingMemory_71_out1_stream[0].size());
        stream_max_size[700] = std::max<size_t>(TensorDuplicator_3_out0_stream[0].size(), stream_max_size[700]);
        channel_quantities.push_back(TensorDuplicator_3_out0_stream[0].size());
        stream_max_size[701] = std::max<size_t>(TensorDuplicator_3_out1_stream[0].size(), stream_max_size[701]);
        channel_quantities.push_back(TensorDuplicator_3_out1_stream[0].size());
        stream_max_size[702] = std::max<size_t>(StreamingMemory_72_out0_stream[0].size(), stream_max_size[702]);
        channel_quantities.push_back(StreamingMemory_72_out0_stream[0].size());
        stream_max_size[703] = std::max<size_t>(StreamingMemory_72_out1_stream[0].size(), stream_max_size[703]);
        channel_quantities.push_back(StreamingMemory_72_out1_stream[0].size());
        stream_max_size[704] = std::max<size_t>(BandwidthAdjustIncreaseStreams_2_out0_stream[0].size(), stream_max_size[704]);
        channel_quantities.push_back(BandwidthAdjustIncreaseStreams_2_out0_stream[0].size());
        stream_max_size[705] = std::max<size_t>(BandwidthAdjustIncreaseStreams_2_out0_stream[1].size(), stream_max_size[705]);
        channel_quantities.push_back(BandwidthAdjustIncreaseStreams_2_out0_stream[1].size());
        stream_max_size[706] = std::max<size_t>(BandwidthAdjustIncreaseStreams_3_out0_stream[0].size(), stream_max_size[706]);
        channel_quantities.push_back(BandwidthAdjustIncreaseStreams_3_out0_stream[0].size());
        stream_max_size[707] = std::max<size_t>(BandwidthAdjustIncreaseStreams_3_out0_stream[1].size(), stream_max_size[707]);
        channel_quantities.push_back(BandwidthAdjustIncreaseStreams_3_out0_stream[1].size());
        stream_max_size[708] = std::max<size_t>(StreamingMemory_73_out0_stream[0].size(), stream_max_size[708]);
        channel_quantities.push_back(StreamingMemory_73_out0_stream[0].size());
        stream_max_size[709] = std::max<size_t>(StreamingMemory_73_out1_stream[0].size(), stream_max_size[709]);
        channel_quantities.push_back(StreamingMemory_73_out1_stream[0].size());
        stream_max_size[710] = std::max<size_t>(StreamingLineBuffer_20_out0_stream[0].size(), stream_max_size[710]);
        channel_quantities.push_back(StreamingLineBuffer_20_out0_stream[0].size());
        stream_max_size[711] = std::max<size_t>(StreamingLineBuffer_20_out0_stream[1].size(), stream_max_size[711]);
        channel_quantities.push_back(StreamingLineBuffer_20_out0_stream[1].size());
        stream_max_size[712] = std::max<size_t>(StreamingMemory_74_out0_stream[0].size(), stream_max_size[712]);
        channel_quantities.push_back(StreamingMemory_74_out0_stream[0].size());
        stream_max_size[713] = std::max<size_t>(StreamingMemory_74_out0_stream[1].size(), stream_max_size[713]);
        channel_quantities.push_back(StreamingMemory_74_out0_stream[1].size());
        stream_max_size[714] = std::max<size_t>(StreamingMemory_74_out0_stream[2].size(), stream_max_size[714]);
        channel_quantities.push_back(StreamingMemory_74_out0_stream[2].size());
        stream_max_size[715] = std::max<size_t>(StreamingMemory_74_out0_stream[3].size(), stream_max_size[715]);
        channel_quantities.push_back(StreamingMemory_74_out0_stream[3].size());
        stream_max_size[716] = std::max<size_t>(StreamingMemory_74_out0_stream[4].size(), stream_max_size[716]);
        channel_quantities.push_back(StreamingMemory_74_out0_stream[4].size());
        stream_max_size[717] = std::max<size_t>(StreamingMemory_74_out0_stream[5].size(), stream_max_size[717]);
        channel_quantities.push_back(StreamingMemory_74_out0_stream[5].size());
        stream_max_size[718] = std::max<size_t>(StreamingMemory_74_out0_stream[6].size(), stream_max_size[718]);
        channel_quantities.push_back(StreamingMemory_74_out0_stream[6].size());
        stream_max_size[719] = std::max<size_t>(StreamingMemory_74_out0_stream[7].size(), stream_max_size[719]);
        channel_quantities.push_back(StreamingMemory_74_out0_stream[7].size());
        stream_max_size[720] = std::max<size_t>(StreamingMemory_74_out0_stream[8].size(), stream_max_size[720]);
        channel_quantities.push_back(StreamingMemory_74_out0_stream[8].size());
        stream_max_size[721] = std::max<size_t>(StreamingMemory_74_out1_stream[0].size(), stream_max_size[721]);
        channel_quantities.push_back(StreamingMemory_74_out1_stream[0].size());
        stream_max_size[722] = std::max<size_t>(StreamingConv_14_out0_stream[0].size(), stream_max_size[722]);
        channel_quantities.push_back(StreamingConv_14_out0_stream[0].size());
        stream_max_size[723] = std::max<size_t>(StreamingConv_14_out0_stream[1].size(), stream_max_size[723]);
        channel_quantities.push_back(StreamingConv_14_out0_stream[1].size());
        stream_max_size[724] = std::max<size_t>(StreamingMemory_75_out0_stream[0].size(), stream_max_size[724]);
        channel_quantities.push_back(StreamingMemory_75_out0_stream[0].size());
        stream_max_size[725] = std::max<size_t>(StreamingMemory_75_out1_stream[0].size(), stream_max_size[725]);
        channel_quantities.push_back(StreamingMemory_75_out1_stream[0].size());
        stream_max_size[726] = std::max<size_t>(BandwidthAdjustDecreaseChannels_8_out0_stream[0].size(), stream_max_size[726]);
        channel_quantities.push_back(BandwidthAdjustDecreaseChannels_8_out0_stream[0].size());
        stream_max_size[727] = std::max<size_t>(BandwidthAdjustDecreaseChannels_8_out0_stream[1].size(), stream_max_size[727]);
        channel_quantities.push_back(BandwidthAdjustDecreaseChannels_8_out0_stream[1].size());
        stream_max_size[728] = std::max<size_t>(StreamingMemory_76_out0_stream[0].size(), stream_max_size[728]);
        channel_quantities.push_back(StreamingMemory_76_out0_stream[0].size());
        stream_max_size[729] = std::max<size_t>(StreamingMemory_76_out1_stream[0].size(), stream_max_size[729]);
        channel_quantities.push_back(StreamingMemory_76_out1_stream[0].size());
        stream_max_size[730] = std::max<size_t>(StreamingLineBuffer_21_out0_stream[0].size(), stream_max_size[730]);
        channel_quantities.push_back(StreamingLineBuffer_21_out0_stream[0].size());
        stream_max_size[731] = std::max<size_t>(StreamingLineBuffer_21_out0_stream[1].size(), stream_max_size[731]);
        channel_quantities.push_back(StreamingLineBuffer_21_out0_stream[1].size());
        stream_max_size[732] = std::max<size_t>(StreamingLineBuffer_21_out0_stream[2].size(), stream_max_size[732]);
        channel_quantities.push_back(StreamingLineBuffer_21_out0_stream[2].size());
        stream_max_size[733] = std::max<size_t>(StreamingLineBuffer_21_out0_stream[3].size(), stream_max_size[733]);
        channel_quantities.push_back(StreamingLineBuffer_21_out0_stream[3].size());
        stream_max_size[734] = std::max<size_t>(StreamingLineBuffer_21_out0_stream[4].size(), stream_max_size[734]);
        channel_quantities.push_back(StreamingLineBuffer_21_out0_stream[4].size());
        stream_max_size[735] = std::max<size_t>(StreamingLineBuffer_21_out0_stream[5].size(), stream_max_size[735]);
        channel_quantities.push_back(StreamingLineBuffer_21_out0_stream[5].size());
        stream_max_size[736] = std::max<size_t>(StreamingLineBuffer_21_out0_stream[6].size(), stream_max_size[736]);
        channel_quantities.push_back(StreamingLineBuffer_21_out0_stream[6].size());
        stream_max_size[737] = std::max<size_t>(StreamingLineBuffer_21_out0_stream[7].size(), stream_max_size[737]);
        channel_quantities.push_back(StreamingLineBuffer_21_out0_stream[7].size());
        stream_max_size[738] = std::max<size_t>(StreamingLineBuffer_21_out0_stream[8].size(), stream_max_size[738]);
        channel_quantities.push_back(StreamingLineBuffer_21_out0_stream[8].size());
        stream_max_size[739] = std::max<size_t>(StreamingLineBuffer_21_out0_stream[9].size(), stream_max_size[739]);
        channel_quantities.push_back(StreamingLineBuffer_21_out0_stream[9].size());
        stream_max_size[740] = std::max<size_t>(StreamingLineBuffer_21_out0_stream[10].size(), stream_max_size[740]);
        channel_quantities.push_back(StreamingLineBuffer_21_out0_stream[10].size());
        stream_max_size[741] = std::max<size_t>(StreamingLineBuffer_21_out0_stream[11].size(), stream_max_size[741]);
        channel_quantities.push_back(StreamingLineBuffer_21_out0_stream[11].size());
        stream_max_size[742] = std::max<size_t>(StreamingLineBuffer_21_out0_stream_prepad[0].size(), stream_max_size[742]);
        channel_quantities.push_back(StreamingLineBuffer_21_out0_stream_prepad[0].size());
        stream_max_size[743] = std::max<size_t>(StreamingLineBuffer_21_out0_stream_prepad[1].size(), stream_max_size[743]);
        channel_quantities.push_back(StreamingLineBuffer_21_out0_stream_prepad[1].size());
        stream_max_size[744] = std::max<size_t>(StreamingLineBuffer_21_out0_stream_prepad[2].size(), stream_max_size[744]);
        channel_quantities.push_back(StreamingLineBuffer_21_out0_stream_prepad[2].size());
        stream_max_size[745] = std::max<size_t>(StreamingLineBuffer_21_out0_stream_prepad[3].size(), stream_max_size[745]);
        channel_quantities.push_back(StreamingLineBuffer_21_out0_stream_prepad[3].size());
        stream_max_size[746] = std::max<size_t>(StreamingLineBuffer_21_out0_stream_prepad[4].size(), stream_max_size[746]);
        channel_quantities.push_back(StreamingLineBuffer_21_out0_stream_prepad[4].size());
        stream_max_size[747] = std::max<size_t>(StreamingLineBuffer_21_out0_stream_prepad[5].size(), stream_max_size[747]);
        channel_quantities.push_back(StreamingLineBuffer_21_out0_stream_prepad[5].size());
        stream_max_size[748] = std::max<size_t>(StreamingLineBuffer_21_out0_stream_prepad[6].size(), stream_max_size[748]);
        channel_quantities.push_back(StreamingLineBuffer_21_out0_stream_prepad[6].size());
        stream_max_size[749] = std::max<size_t>(StreamingLineBuffer_21_out0_stream_prepad[7].size(), stream_max_size[749]);
        channel_quantities.push_back(StreamingLineBuffer_21_out0_stream_prepad[7].size());
        stream_max_size[750] = std::max<size_t>(StreamingLineBuffer_21_out0_stream_prepad[8].size(), stream_max_size[750]);
        channel_quantities.push_back(StreamingLineBuffer_21_out0_stream_prepad[8].size());
        stream_max_size[751] = std::max<size_t>(StreamingLineBuffer_21_out0_stream_prepad[9].size(), stream_max_size[751]);
        channel_quantities.push_back(StreamingLineBuffer_21_out0_stream_prepad[9].size());
        stream_max_size[752] = std::max<size_t>(StreamingLineBuffer_21_out0_stream_prepad[10].size(), stream_max_size[752]);
        channel_quantities.push_back(StreamingLineBuffer_21_out0_stream_prepad[10].size());
        stream_max_size[753] = std::max<size_t>(StreamingLineBuffer_21_out0_stream_prepad[11].size(), stream_max_size[753]);
        channel_quantities.push_back(StreamingLineBuffer_21_out0_stream_prepad[11].size());
        stream_max_size[754] = std::max<size_t>(StreamingLineBuffer_21_buffer_stream[0].size(), stream_max_size[754]);
        channel_quantities.push_back(StreamingLineBuffer_21_buffer_stream[0].size());
        stream_max_size[755] = std::max<size_t>(StreamingLineBuffer_21_buffer_stream[1].size(), stream_max_size[755]);
        channel_quantities.push_back(StreamingLineBuffer_21_buffer_stream[1].size());
        stream_max_size[756] = std::max<size_t>(StreamingLineBuffer_21_buffer_stream[2].size(), stream_max_size[756]);
        channel_quantities.push_back(StreamingLineBuffer_21_buffer_stream[2].size());
        stream_max_size[757] = std::max<size_t>(StreamingLineBuffer_21_buffer_stream[3].size(), stream_max_size[757]);
        channel_quantities.push_back(StreamingLineBuffer_21_buffer_stream[3].size());
        stream_max_size[758] = std::max<size_t>(StreamingLineBuffer_21_buffer_stream[4].size(), stream_max_size[758]);
        channel_quantities.push_back(StreamingLineBuffer_21_buffer_stream[4].size());
        stream_max_size[759] = std::max<size_t>(StreamingLineBuffer_21_buffer_stream[5].size(), stream_max_size[759]);
        channel_quantities.push_back(StreamingLineBuffer_21_buffer_stream[5].size());
        stream_max_size[760] = std::max<size_t>(StreamingLineBuffer_21_buffer_stream[6].size(), stream_max_size[760]);
        channel_quantities.push_back(StreamingLineBuffer_21_buffer_stream[6].size());
        stream_max_size[761] = std::max<size_t>(StreamingLineBuffer_21_buffer_stream[7].size(), stream_max_size[761]);
        channel_quantities.push_back(StreamingLineBuffer_21_buffer_stream[7].size());
        stream_max_size[762] = std::max<size_t>(StreamingLineBuffer_21_buffer_stream[8].size(), stream_max_size[762]);
        channel_quantities.push_back(StreamingLineBuffer_21_buffer_stream[8].size());
        stream_max_size[763] = std::max<size_t>(StreamingLineBuffer_21_buffer_stream[9].size(), stream_max_size[763]);
        channel_quantities.push_back(StreamingLineBuffer_21_buffer_stream[9].size());
        stream_max_size[764] = std::max<size_t>(StreamingMemory_77_out0_stream[0].size(), stream_max_size[764]);
        channel_quantities.push_back(StreamingMemory_77_out0_stream[0].size());
        stream_max_size[765] = std::max<size_t>(StreamingMemory_77_out1_stream[0].size(), stream_max_size[765]);
        channel_quantities.push_back(StreamingMemory_77_out1_stream[0].size());
        stream_max_size[766] = std::max<size_t>(StreamingDepthwiseConv_7_out0_stream[0].size(), stream_max_size[766]);
        channel_quantities.push_back(StreamingDepthwiseConv_7_out0_stream[0].size());
        stream_max_size[767] = std::max<size_t>(StreamingDepthwiseConv_7_out0_stream[1].size(), stream_max_size[767]);
        channel_quantities.push_back(StreamingDepthwiseConv_7_out0_stream[1].size());
        stream_max_size[768] = std::max<size_t>(StreamingMemory_78_out0_stream[0].size(), stream_max_size[768]);
        channel_quantities.push_back(StreamingMemory_78_out0_stream[0].size());
        stream_max_size[769] = std::max<size_t>(StreamingMemory_78_out1_stream[0].size(), stream_max_size[769]);
        channel_quantities.push_back(StreamingMemory_78_out1_stream[0].size());
        stream_max_size[770] = std::max<size_t>(BandwidthAdjustIncreaseChannels_13_out0_stream[0].size(), stream_max_size[770]);
        channel_quantities.push_back(BandwidthAdjustIncreaseChannels_13_out0_stream[0].size());
        stream_max_size[771] = std::max<size_t>(BandwidthAdjustIncreaseChannels_13_out0_stream[1].size(), stream_max_size[771]);
        channel_quantities.push_back(BandwidthAdjustIncreaseChannels_13_out0_stream[1].size());
        stream_max_size[772] = std::max<size_t>(StreamingMemory_79_out0_stream[0].size(), stream_max_size[772]);
        channel_quantities.push_back(StreamingMemory_79_out0_stream[0].size());
        stream_max_size[773] = std::max<size_t>(StreamingMemory_79_out1_stream[0].size(), stream_max_size[773]);
        channel_quantities.push_back(StreamingMemory_79_out1_stream[0].size());
        stream_max_size[774] = std::max<size_t>(StreamingLineBuffer_22_out0_stream[0].size(), stream_max_size[774]);
        channel_quantities.push_back(StreamingLineBuffer_22_out0_stream[0].size());
        stream_max_size[775] = std::max<size_t>(StreamingLineBuffer_22_out0_stream[1].size(), stream_max_size[775]);
        channel_quantities.push_back(StreamingLineBuffer_22_out0_stream[1].size());
        stream_max_size[776] = std::max<size_t>(StreamingMemory_80_out0_stream[0].size(), stream_max_size[776]);
        channel_quantities.push_back(StreamingMemory_80_out0_stream[0].size());
        stream_max_size[777] = std::max<size_t>(StreamingMemory_80_out0_stream[1].size(), stream_max_size[777]);
        channel_quantities.push_back(StreamingMemory_80_out0_stream[1].size());
        stream_max_size[778] = std::max<size_t>(StreamingMemory_80_out0_stream[2].size(), stream_max_size[778]);
        channel_quantities.push_back(StreamingMemory_80_out0_stream[2].size());
        stream_max_size[779] = std::max<size_t>(StreamingMemory_80_out0_stream[3].size(), stream_max_size[779]);
        channel_quantities.push_back(StreamingMemory_80_out0_stream[3].size());
        stream_max_size[780] = std::max<size_t>(StreamingMemory_80_out0_stream[4].size(), stream_max_size[780]);
        channel_quantities.push_back(StreamingMemory_80_out0_stream[4].size());
        stream_max_size[781] = std::max<size_t>(StreamingMemory_80_out0_stream[5].size(), stream_max_size[781]);
        channel_quantities.push_back(StreamingMemory_80_out0_stream[5].size());
        stream_max_size[782] = std::max<size_t>(StreamingMemory_80_out0_stream[6].size(), stream_max_size[782]);
        channel_quantities.push_back(StreamingMemory_80_out0_stream[6].size());
        stream_max_size[783] = std::max<size_t>(StreamingMemory_80_out0_stream[7].size(), stream_max_size[783]);
        channel_quantities.push_back(StreamingMemory_80_out0_stream[7].size());
        stream_max_size[784] = std::max<size_t>(StreamingMemory_80_out0_stream[8].size(), stream_max_size[784]);
        channel_quantities.push_back(StreamingMemory_80_out0_stream[8].size());
        stream_max_size[785] = std::max<size_t>(StreamingMemory_80_out1_stream[0].size(), stream_max_size[785]);
        channel_quantities.push_back(StreamingMemory_80_out1_stream[0].size());
        stream_max_size[786] = std::max<size_t>(StreamingConv_15_out0_stream[0].size(), stream_max_size[786]);
        channel_quantities.push_back(StreamingConv_15_out0_stream[0].size());
        stream_max_size[787] = std::max<size_t>(StreamingConv_15_out0_stream[1].size(), stream_max_size[787]);
        channel_quantities.push_back(StreamingConv_15_out0_stream[1].size());
        stream_max_size[788] = std::max<size_t>(StreamingMemory_81_out0_stream[0].size(), stream_max_size[788]);
        channel_quantities.push_back(StreamingMemory_81_out0_stream[0].size());
        stream_max_size[789] = std::max<size_t>(StreamingMemory_81_out1_stream[0].size(), stream_max_size[789]);
        channel_quantities.push_back(StreamingMemory_81_out1_stream[0].size());
        stream_max_size[790] = std::max<size_t>(StreamingAdd_3_out0_stream[0].size(), stream_max_size[790]);
        channel_quantities.push_back(StreamingAdd_3_out0_stream[0].size());
        stream_max_size[791] = std::max<size_t>(StreamingAdd_3_out0_stream[1].size(), stream_max_size[791]);
        channel_quantities.push_back(StreamingAdd_3_out0_stream[1].size());
        stream_max_size[792] = std::max<size_t>(StreamingMemory_82_out0_stream[0].size(), stream_max_size[792]);
        channel_quantities.push_back(StreamingMemory_82_out0_stream[0].size());
        stream_max_size[793] = std::max<size_t>(StreamingMemory_82_out1_stream[0].size(), stream_max_size[793]);
        channel_quantities.push_back(StreamingMemory_82_out1_stream[0].size());
        stream_max_size[794] = std::max<size_t>(BandwidthAdjustDecreaseStreams_4_out0_stream[0].size(), stream_max_size[794]);
        channel_quantities.push_back(BandwidthAdjustDecreaseStreams_4_out0_stream[0].size());
        stream_max_size[795] = std::max<size_t>(StreamingMemory_83_out0_stream[0].size(), stream_max_size[795]);
        channel_quantities.push_back(StreamingMemory_83_out0_stream[0].size());
        stream_max_size[796] = std::max<size_t>(StreamingMemory_83_out1_stream[0].size(), stream_max_size[796]);
        channel_quantities.push_back(StreamingMemory_83_out1_stream[0].size());
        stream_max_size[797] = std::max<size_t>(TensorDuplicator_4_out0_stream[0].size(), stream_max_size[797]);
        channel_quantities.push_back(TensorDuplicator_4_out0_stream[0].size());
        stream_max_size[798] = std::max<size_t>(TensorDuplicator_4_out1_stream[0].size(), stream_max_size[798]);
        channel_quantities.push_back(TensorDuplicator_4_out1_stream[0].size());
        stream_max_size[799] = std::max<size_t>(StreamingMemory_84_out0_stream[0].size(), stream_max_size[799]);
        channel_quantities.push_back(StreamingMemory_84_out0_stream[0].size());
        stream_max_size[800] = std::max<size_t>(StreamingMemory_84_out1_stream[0].size(), stream_max_size[800]);
        channel_quantities.push_back(StreamingMemory_84_out1_stream[0].size());
        stream_max_size[801] = std::max<size_t>(BandwidthAdjustIncreaseStreams_4_out0_stream[0].size(), stream_max_size[801]);
        channel_quantities.push_back(BandwidthAdjustIncreaseStreams_4_out0_stream[0].size());
        stream_max_size[802] = std::max<size_t>(BandwidthAdjustIncreaseStreams_4_out0_stream[1].size(), stream_max_size[802]);
        channel_quantities.push_back(BandwidthAdjustIncreaseStreams_4_out0_stream[1].size());
        stream_max_size[803] = std::max<size_t>(BandwidthAdjustIncreaseStreams_5_out0_stream[0].size(), stream_max_size[803]);
        channel_quantities.push_back(BandwidthAdjustIncreaseStreams_5_out0_stream[0].size());
        stream_max_size[804] = std::max<size_t>(BandwidthAdjustIncreaseStreams_5_out0_stream[1].size(), stream_max_size[804]);
        channel_quantities.push_back(BandwidthAdjustIncreaseStreams_5_out0_stream[1].size());
        stream_max_size[805] = std::max<size_t>(StreamingMemory_85_out0_stream[0].size(), stream_max_size[805]);
        channel_quantities.push_back(StreamingMemory_85_out0_stream[0].size());
        stream_max_size[806] = std::max<size_t>(StreamingMemory_85_out1_stream[0].size(), stream_max_size[806]);
        channel_quantities.push_back(StreamingMemory_85_out1_stream[0].size());
        stream_max_size[807] = std::max<size_t>(StreamingLineBuffer_23_out0_stream[0].size(), stream_max_size[807]);
        channel_quantities.push_back(StreamingLineBuffer_23_out0_stream[0].size());
        stream_max_size[808] = std::max<size_t>(StreamingLineBuffer_23_out0_stream[1].size(), stream_max_size[808]);
        channel_quantities.push_back(StreamingLineBuffer_23_out0_stream[1].size());
        stream_max_size[809] = std::max<size_t>(StreamingMemory_86_out0_stream[0].size(), stream_max_size[809]);
        channel_quantities.push_back(StreamingMemory_86_out0_stream[0].size());
        stream_max_size[810] = std::max<size_t>(StreamingMemory_86_out0_stream[1].size(), stream_max_size[810]);
        channel_quantities.push_back(StreamingMemory_86_out0_stream[1].size());
        stream_max_size[811] = std::max<size_t>(StreamingMemory_86_out0_stream[2].size(), stream_max_size[811]);
        channel_quantities.push_back(StreamingMemory_86_out0_stream[2].size());
        stream_max_size[812] = std::max<size_t>(StreamingMemory_86_out0_stream[3].size(), stream_max_size[812]);
        channel_quantities.push_back(StreamingMemory_86_out0_stream[3].size());
        stream_max_size[813] = std::max<size_t>(StreamingMemory_86_out0_stream[4].size(), stream_max_size[813]);
        channel_quantities.push_back(StreamingMemory_86_out0_stream[4].size());
        stream_max_size[814] = std::max<size_t>(StreamingMemory_86_out0_stream[5].size(), stream_max_size[814]);
        channel_quantities.push_back(StreamingMemory_86_out0_stream[5].size());
        stream_max_size[815] = std::max<size_t>(StreamingMemory_86_out0_stream[6].size(), stream_max_size[815]);
        channel_quantities.push_back(StreamingMemory_86_out0_stream[6].size());
        stream_max_size[816] = std::max<size_t>(StreamingMemory_86_out0_stream[7].size(), stream_max_size[816]);
        channel_quantities.push_back(StreamingMemory_86_out0_stream[7].size());
        stream_max_size[817] = std::max<size_t>(StreamingMemory_86_out0_stream[8].size(), stream_max_size[817]);
        channel_quantities.push_back(StreamingMemory_86_out0_stream[8].size());
        stream_max_size[818] = std::max<size_t>(StreamingMemory_86_out1_stream[0].size(), stream_max_size[818]);
        channel_quantities.push_back(StreamingMemory_86_out1_stream[0].size());
        stream_max_size[819] = std::max<size_t>(StreamingConv_16_out0_stream[0].size(), stream_max_size[819]);
        channel_quantities.push_back(StreamingConv_16_out0_stream[0].size());
        stream_max_size[820] = std::max<size_t>(StreamingConv_16_out0_stream[1].size(), stream_max_size[820]);
        channel_quantities.push_back(StreamingConv_16_out0_stream[1].size());
        stream_max_size[821] = std::max<size_t>(StreamingMemory_87_out0_stream[0].size(), stream_max_size[821]);
        channel_quantities.push_back(StreamingMemory_87_out0_stream[0].size());
        stream_max_size[822] = std::max<size_t>(StreamingMemory_87_out1_stream[0].size(), stream_max_size[822]);
        channel_quantities.push_back(StreamingMemory_87_out1_stream[0].size());
        stream_max_size[823] = std::max<size_t>(BandwidthAdjustDecreaseChannels_9_out0_stream[0].size(), stream_max_size[823]);
        channel_quantities.push_back(BandwidthAdjustDecreaseChannels_9_out0_stream[0].size());
        stream_max_size[824] = std::max<size_t>(BandwidthAdjustDecreaseChannels_9_out0_stream[1].size(), stream_max_size[824]);
        channel_quantities.push_back(BandwidthAdjustDecreaseChannels_9_out0_stream[1].size());
        stream_max_size[825] = std::max<size_t>(StreamingMemory_88_out0_stream[0].size(), stream_max_size[825]);
        channel_quantities.push_back(StreamingMemory_88_out0_stream[0].size());
        stream_max_size[826] = std::max<size_t>(StreamingMemory_88_out1_stream[0].size(), stream_max_size[826]);
        channel_quantities.push_back(StreamingMemory_88_out1_stream[0].size());
        stream_max_size[827] = std::max<size_t>(StreamingLineBuffer_24_out0_stream[0].size(), stream_max_size[827]);
        channel_quantities.push_back(StreamingLineBuffer_24_out0_stream[0].size());
        stream_max_size[828] = std::max<size_t>(StreamingLineBuffer_24_out0_stream[1].size(), stream_max_size[828]);
        channel_quantities.push_back(StreamingLineBuffer_24_out0_stream[1].size());
        stream_max_size[829] = std::max<size_t>(StreamingLineBuffer_24_out0_stream[2].size(), stream_max_size[829]);
        channel_quantities.push_back(StreamingLineBuffer_24_out0_stream[2].size());
        stream_max_size[830] = std::max<size_t>(StreamingLineBuffer_24_out0_stream[3].size(), stream_max_size[830]);
        channel_quantities.push_back(StreamingLineBuffer_24_out0_stream[3].size());
        stream_max_size[831] = std::max<size_t>(StreamingLineBuffer_24_out0_stream[4].size(), stream_max_size[831]);
        channel_quantities.push_back(StreamingLineBuffer_24_out0_stream[4].size());
        stream_max_size[832] = std::max<size_t>(StreamingLineBuffer_24_out0_stream[5].size(), stream_max_size[832]);
        channel_quantities.push_back(StreamingLineBuffer_24_out0_stream[5].size());
        stream_max_size[833] = std::max<size_t>(StreamingLineBuffer_24_out0_stream[6].size(), stream_max_size[833]);
        channel_quantities.push_back(StreamingLineBuffer_24_out0_stream[6].size());
        stream_max_size[834] = std::max<size_t>(StreamingLineBuffer_24_out0_stream[7].size(), stream_max_size[834]);
        channel_quantities.push_back(StreamingLineBuffer_24_out0_stream[7].size());
        stream_max_size[835] = std::max<size_t>(StreamingLineBuffer_24_out0_stream[8].size(), stream_max_size[835]);
        channel_quantities.push_back(StreamingLineBuffer_24_out0_stream[8].size());
        stream_max_size[836] = std::max<size_t>(StreamingLineBuffer_24_out0_stream[9].size(), stream_max_size[836]);
        channel_quantities.push_back(StreamingLineBuffer_24_out0_stream[9].size());
        stream_max_size[837] = std::max<size_t>(StreamingLineBuffer_24_out0_stream[10].size(), stream_max_size[837]);
        channel_quantities.push_back(StreamingLineBuffer_24_out0_stream[10].size());
        stream_max_size[838] = std::max<size_t>(StreamingLineBuffer_24_out0_stream[11].size(), stream_max_size[838]);
        channel_quantities.push_back(StreamingLineBuffer_24_out0_stream[11].size());
        stream_max_size[839] = std::max<size_t>(StreamingLineBuffer_24_out0_stream_prepad[0].size(), stream_max_size[839]);
        channel_quantities.push_back(StreamingLineBuffer_24_out0_stream_prepad[0].size());
        stream_max_size[840] = std::max<size_t>(StreamingLineBuffer_24_out0_stream_prepad[1].size(), stream_max_size[840]);
        channel_quantities.push_back(StreamingLineBuffer_24_out0_stream_prepad[1].size());
        stream_max_size[841] = std::max<size_t>(StreamingLineBuffer_24_out0_stream_prepad[2].size(), stream_max_size[841]);
        channel_quantities.push_back(StreamingLineBuffer_24_out0_stream_prepad[2].size());
        stream_max_size[842] = std::max<size_t>(StreamingLineBuffer_24_out0_stream_prepad[3].size(), stream_max_size[842]);
        channel_quantities.push_back(StreamingLineBuffer_24_out0_stream_prepad[3].size());
        stream_max_size[843] = std::max<size_t>(StreamingLineBuffer_24_out0_stream_prepad[4].size(), stream_max_size[843]);
        channel_quantities.push_back(StreamingLineBuffer_24_out0_stream_prepad[4].size());
        stream_max_size[844] = std::max<size_t>(StreamingLineBuffer_24_out0_stream_prepad[5].size(), stream_max_size[844]);
        channel_quantities.push_back(StreamingLineBuffer_24_out0_stream_prepad[5].size());
        stream_max_size[845] = std::max<size_t>(StreamingLineBuffer_24_out0_stream_prepad[6].size(), stream_max_size[845]);
        channel_quantities.push_back(StreamingLineBuffer_24_out0_stream_prepad[6].size());
        stream_max_size[846] = std::max<size_t>(StreamingLineBuffer_24_out0_stream_prepad[7].size(), stream_max_size[846]);
        channel_quantities.push_back(StreamingLineBuffer_24_out0_stream_prepad[7].size());
        stream_max_size[847] = std::max<size_t>(StreamingLineBuffer_24_out0_stream_prepad[8].size(), stream_max_size[847]);
        channel_quantities.push_back(StreamingLineBuffer_24_out0_stream_prepad[8].size());
        stream_max_size[848] = std::max<size_t>(StreamingLineBuffer_24_out0_stream_prepad[9].size(), stream_max_size[848]);
        channel_quantities.push_back(StreamingLineBuffer_24_out0_stream_prepad[9].size());
        stream_max_size[849] = std::max<size_t>(StreamingLineBuffer_24_out0_stream_prepad[10].size(), stream_max_size[849]);
        channel_quantities.push_back(StreamingLineBuffer_24_out0_stream_prepad[10].size());
        stream_max_size[850] = std::max<size_t>(StreamingLineBuffer_24_out0_stream_prepad[11].size(), stream_max_size[850]);
        channel_quantities.push_back(StreamingLineBuffer_24_out0_stream_prepad[11].size());
        stream_max_size[851] = std::max<size_t>(StreamingLineBuffer_24_buffer_stream[0].size(), stream_max_size[851]);
        channel_quantities.push_back(StreamingLineBuffer_24_buffer_stream[0].size());
        stream_max_size[852] = std::max<size_t>(StreamingLineBuffer_24_buffer_stream[1].size(), stream_max_size[852]);
        channel_quantities.push_back(StreamingLineBuffer_24_buffer_stream[1].size());
        stream_max_size[853] = std::max<size_t>(StreamingLineBuffer_24_buffer_stream[2].size(), stream_max_size[853]);
        channel_quantities.push_back(StreamingLineBuffer_24_buffer_stream[2].size());
        stream_max_size[854] = std::max<size_t>(StreamingLineBuffer_24_buffer_stream[3].size(), stream_max_size[854]);
        channel_quantities.push_back(StreamingLineBuffer_24_buffer_stream[3].size());
        stream_max_size[855] = std::max<size_t>(StreamingLineBuffer_24_buffer_stream[4].size(), stream_max_size[855]);
        channel_quantities.push_back(StreamingLineBuffer_24_buffer_stream[4].size());
        stream_max_size[856] = std::max<size_t>(StreamingLineBuffer_24_buffer_stream[5].size(), stream_max_size[856]);
        channel_quantities.push_back(StreamingLineBuffer_24_buffer_stream[5].size());
        stream_max_size[857] = std::max<size_t>(StreamingLineBuffer_24_buffer_stream[6].size(), stream_max_size[857]);
        channel_quantities.push_back(StreamingLineBuffer_24_buffer_stream[6].size());
        stream_max_size[858] = std::max<size_t>(StreamingLineBuffer_24_buffer_stream[7].size(), stream_max_size[858]);
        channel_quantities.push_back(StreamingLineBuffer_24_buffer_stream[7].size());
        stream_max_size[859] = std::max<size_t>(StreamingLineBuffer_24_buffer_stream[8].size(), stream_max_size[859]);
        channel_quantities.push_back(StreamingLineBuffer_24_buffer_stream[8].size());
        stream_max_size[860] = std::max<size_t>(StreamingLineBuffer_24_buffer_stream[9].size(), stream_max_size[860]);
        channel_quantities.push_back(StreamingLineBuffer_24_buffer_stream[9].size());
        stream_max_size[861] = std::max<size_t>(StreamingMemory_89_out0_stream[0].size(), stream_max_size[861]);
        channel_quantities.push_back(StreamingMemory_89_out0_stream[0].size());
        stream_max_size[862] = std::max<size_t>(StreamingMemory_89_out1_stream[0].size(), stream_max_size[862]);
        channel_quantities.push_back(StreamingMemory_89_out1_stream[0].size());
        stream_max_size[863] = std::max<size_t>(StreamingDepthwiseConv_8_out0_stream[0].size(), stream_max_size[863]);
        channel_quantities.push_back(StreamingDepthwiseConv_8_out0_stream[0].size());
        stream_max_size[864] = std::max<size_t>(StreamingDepthwiseConv_8_out0_stream[1].size(), stream_max_size[864]);
        channel_quantities.push_back(StreamingDepthwiseConv_8_out0_stream[1].size());
        stream_max_size[865] = std::max<size_t>(StreamingMemory_90_out0_stream[0].size(), stream_max_size[865]);
        channel_quantities.push_back(StreamingMemory_90_out0_stream[0].size());
        stream_max_size[866] = std::max<size_t>(StreamingMemory_90_out1_stream[0].size(), stream_max_size[866]);
        channel_quantities.push_back(StreamingMemory_90_out1_stream[0].size());
        stream_max_size[867] = std::max<size_t>(BandwidthAdjustIncreaseChannels_14_out0_stream[0].size(), stream_max_size[867]);
        channel_quantities.push_back(BandwidthAdjustIncreaseChannels_14_out0_stream[0].size());
        stream_max_size[868] = std::max<size_t>(BandwidthAdjustIncreaseChannels_14_out0_stream[1].size(), stream_max_size[868]);
        channel_quantities.push_back(BandwidthAdjustIncreaseChannels_14_out0_stream[1].size());
        stream_max_size[869] = std::max<size_t>(StreamingMemory_91_out0_stream[0].size(), stream_max_size[869]);
        channel_quantities.push_back(StreamingMemory_91_out0_stream[0].size());
        stream_max_size[870] = std::max<size_t>(StreamingMemory_91_out1_stream[0].size(), stream_max_size[870]);
        channel_quantities.push_back(StreamingMemory_91_out1_stream[0].size());
        stream_max_size[871] = std::max<size_t>(StreamingLineBuffer_25_out0_stream[0].size(), stream_max_size[871]);
        channel_quantities.push_back(StreamingLineBuffer_25_out0_stream[0].size());
        stream_max_size[872] = std::max<size_t>(StreamingLineBuffer_25_out0_stream[1].size(), stream_max_size[872]);
        channel_quantities.push_back(StreamingLineBuffer_25_out0_stream[1].size());
        stream_max_size[873] = std::max<size_t>(StreamingMemory_92_out0_stream[0].size(), stream_max_size[873]);
        channel_quantities.push_back(StreamingMemory_92_out0_stream[0].size());
        stream_max_size[874] = std::max<size_t>(StreamingMemory_92_out0_stream[1].size(), stream_max_size[874]);
        channel_quantities.push_back(StreamingMemory_92_out0_stream[1].size());
        stream_max_size[875] = std::max<size_t>(StreamingMemory_92_out0_stream[2].size(), stream_max_size[875]);
        channel_quantities.push_back(StreamingMemory_92_out0_stream[2].size());
        stream_max_size[876] = std::max<size_t>(StreamingMemory_92_out0_stream[3].size(), stream_max_size[876]);
        channel_quantities.push_back(StreamingMemory_92_out0_stream[3].size());
        stream_max_size[877] = std::max<size_t>(StreamingMemory_92_out0_stream[4].size(), stream_max_size[877]);
        channel_quantities.push_back(StreamingMemory_92_out0_stream[4].size());
        stream_max_size[878] = std::max<size_t>(StreamingMemory_92_out0_stream[5].size(), stream_max_size[878]);
        channel_quantities.push_back(StreamingMemory_92_out0_stream[5].size());
        stream_max_size[879] = std::max<size_t>(StreamingMemory_92_out0_stream[6].size(), stream_max_size[879]);
        channel_quantities.push_back(StreamingMemory_92_out0_stream[6].size());
        stream_max_size[880] = std::max<size_t>(StreamingMemory_92_out0_stream[7].size(), stream_max_size[880]);
        channel_quantities.push_back(StreamingMemory_92_out0_stream[7].size());
        stream_max_size[881] = std::max<size_t>(StreamingMemory_92_out0_stream[8].size(), stream_max_size[881]);
        channel_quantities.push_back(StreamingMemory_92_out0_stream[8].size());
        stream_max_size[882] = std::max<size_t>(StreamingMemory_92_out1_stream[0].size(), stream_max_size[882]);
        channel_quantities.push_back(StreamingMemory_92_out1_stream[0].size());
        stream_max_size[883] = std::max<size_t>(StreamingConv_17_out0_stream[0].size(), stream_max_size[883]);
        channel_quantities.push_back(StreamingConv_17_out0_stream[0].size());
        stream_max_size[884] = std::max<size_t>(StreamingConv_17_out0_stream[1].size(), stream_max_size[884]);
        channel_quantities.push_back(StreamingConv_17_out0_stream[1].size());
        stream_max_size[885] = std::max<size_t>(StreamingMemory_93_out0_stream[0].size(), stream_max_size[885]);
        channel_quantities.push_back(StreamingMemory_93_out0_stream[0].size());
        stream_max_size[886] = std::max<size_t>(StreamingMemory_93_out1_stream[0].size(), stream_max_size[886]);
        channel_quantities.push_back(StreamingMemory_93_out1_stream[0].size());
        stream_max_size[887] = std::max<size_t>(StreamingAdd_4_out0_stream[0].size(), stream_max_size[887]);
        channel_quantities.push_back(StreamingAdd_4_out0_stream[0].size());
        stream_max_size[888] = std::max<size_t>(StreamingAdd_4_out0_stream[1].size(), stream_max_size[888]);
        channel_quantities.push_back(StreamingAdd_4_out0_stream[1].size());
        stream_max_size[889] = std::max<size_t>(StreamingMemory_94_out0_stream[0].size(), stream_max_size[889]);
        channel_quantities.push_back(StreamingMemory_94_out0_stream[0].size());
        stream_max_size[890] = std::max<size_t>(StreamingMemory_94_out1_stream[0].size(), stream_max_size[890]);
        channel_quantities.push_back(StreamingMemory_94_out1_stream[0].size());
        stream_max_size[891] = std::max<size_t>(BandwidthAdjustDecreaseStreams_5_out0_stream[0].size(), stream_max_size[891]);
        channel_quantities.push_back(BandwidthAdjustDecreaseStreams_5_out0_stream[0].size());
        stream_max_size[892] = std::max<size_t>(StreamingMemory_95_out0_stream[0].size(), stream_max_size[892]);
        channel_quantities.push_back(StreamingMemory_95_out0_stream[0].size());
        stream_max_size[893] = std::max<size_t>(StreamingMemory_95_out1_stream[0].size(), stream_max_size[893]);
        channel_quantities.push_back(StreamingMemory_95_out1_stream[0].size());
        stream_max_size[894] = std::max<size_t>(TensorDuplicator_5_out0_stream[0].size(), stream_max_size[894]);
        channel_quantities.push_back(TensorDuplicator_5_out0_stream[0].size());
        stream_max_size[895] = std::max<size_t>(TensorDuplicator_5_out1_stream[0].size(), stream_max_size[895]);
        channel_quantities.push_back(TensorDuplicator_5_out1_stream[0].size());
        stream_max_size[896] = std::max<size_t>(StreamingMemory_96_out0_stream[0].size(), stream_max_size[896]);
        channel_quantities.push_back(StreamingMemory_96_out0_stream[0].size());
        stream_max_size[897] = std::max<size_t>(StreamingMemory_96_out1_stream[0].size(), stream_max_size[897]);
        channel_quantities.push_back(StreamingMemory_96_out1_stream[0].size());
        stream_max_size[898] = std::max<size_t>(BandwidthAdjustIncreaseStreams_6_out0_stream[0].size(), stream_max_size[898]);
        channel_quantities.push_back(BandwidthAdjustIncreaseStreams_6_out0_stream[0].size());
        stream_max_size[899] = std::max<size_t>(BandwidthAdjustIncreaseStreams_6_out0_stream[1].size(), stream_max_size[899]);
        channel_quantities.push_back(BandwidthAdjustIncreaseStreams_6_out0_stream[1].size());
        stream_max_size[900] = std::max<size_t>(BandwidthAdjustIncreaseStreams_7_out0_stream[0].size(), stream_max_size[900]);
        channel_quantities.push_back(BandwidthAdjustIncreaseStreams_7_out0_stream[0].size());
        stream_max_size[901] = std::max<size_t>(BandwidthAdjustIncreaseStreams_7_out0_stream[1].size(), stream_max_size[901]);
        channel_quantities.push_back(BandwidthAdjustIncreaseStreams_7_out0_stream[1].size());
        stream_max_size[902] = std::max<size_t>(StreamingMemory_97_out0_stream[0].size(), stream_max_size[902]);
        channel_quantities.push_back(StreamingMemory_97_out0_stream[0].size());
        stream_max_size[903] = std::max<size_t>(StreamingMemory_97_out1_stream[0].size(), stream_max_size[903]);
        channel_quantities.push_back(StreamingMemory_97_out1_stream[0].size());
        stream_max_size[904] = std::max<size_t>(StreamingLineBuffer_26_out0_stream[0].size(), stream_max_size[904]);
        channel_quantities.push_back(StreamingLineBuffer_26_out0_stream[0].size());
        stream_max_size[905] = std::max<size_t>(StreamingLineBuffer_26_out0_stream[1].size(), stream_max_size[905]);
        channel_quantities.push_back(StreamingLineBuffer_26_out0_stream[1].size());
        stream_max_size[906] = std::max<size_t>(StreamingMemory_98_out0_stream[0].size(), stream_max_size[906]);
        channel_quantities.push_back(StreamingMemory_98_out0_stream[0].size());
        stream_max_size[907] = std::max<size_t>(StreamingMemory_98_out0_stream[1].size(), stream_max_size[907]);
        channel_quantities.push_back(StreamingMemory_98_out0_stream[1].size());
        stream_max_size[908] = std::max<size_t>(StreamingMemory_98_out0_stream[2].size(), stream_max_size[908]);
        channel_quantities.push_back(StreamingMemory_98_out0_stream[2].size());
        stream_max_size[909] = std::max<size_t>(StreamingMemory_98_out0_stream[3].size(), stream_max_size[909]);
        channel_quantities.push_back(StreamingMemory_98_out0_stream[3].size());
        stream_max_size[910] = std::max<size_t>(StreamingMemory_98_out0_stream[4].size(), stream_max_size[910]);
        channel_quantities.push_back(StreamingMemory_98_out0_stream[4].size());
        stream_max_size[911] = std::max<size_t>(StreamingMemory_98_out0_stream[5].size(), stream_max_size[911]);
        channel_quantities.push_back(StreamingMemory_98_out0_stream[5].size());
        stream_max_size[912] = std::max<size_t>(StreamingMemory_98_out0_stream[6].size(), stream_max_size[912]);
        channel_quantities.push_back(StreamingMemory_98_out0_stream[6].size());
        stream_max_size[913] = std::max<size_t>(StreamingMemory_98_out0_stream[7].size(), stream_max_size[913]);
        channel_quantities.push_back(StreamingMemory_98_out0_stream[7].size());
        stream_max_size[914] = std::max<size_t>(StreamingMemory_98_out0_stream[8].size(), stream_max_size[914]);
        channel_quantities.push_back(StreamingMemory_98_out0_stream[8].size());
        stream_max_size[915] = std::max<size_t>(StreamingMemory_98_out1_stream[0].size(), stream_max_size[915]);
        channel_quantities.push_back(StreamingMemory_98_out1_stream[0].size());
        stream_max_size[916] = std::max<size_t>(StreamingConv_18_out0_stream[0].size(), stream_max_size[916]);
        channel_quantities.push_back(StreamingConv_18_out0_stream[0].size());
        stream_max_size[917] = std::max<size_t>(StreamingConv_18_out0_stream[1].size(), stream_max_size[917]);
        channel_quantities.push_back(StreamingConv_18_out0_stream[1].size());
        stream_max_size[918] = std::max<size_t>(StreamingMemory_99_out0_stream[0].size(), stream_max_size[918]);
        channel_quantities.push_back(StreamingMemory_99_out0_stream[0].size());
        stream_max_size[919] = std::max<size_t>(StreamingMemory_99_out1_stream[0].size(), stream_max_size[919]);
        channel_quantities.push_back(StreamingMemory_99_out1_stream[0].size());
        stream_max_size[920] = std::max<size_t>(BandwidthAdjustDecreaseChannels_10_out0_stream[0].size(), stream_max_size[920]);
        channel_quantities.push_back(BandwidthAdjustDecreaseChannels_10_out0_stream[0].size());
        stream_max_size[921] = std::max<size_t>(BandwidthAdjustDecreaseChannels_10_out0_stream[1].size(), stream_max_size[921]);
        channel_quantities.push_back(BandwidthAdjustDecreaseChannels_10_out0_stream[1].size());
        stream_max_size[922] = std::max<size_t>(StreamingMemory_100_out0_stream[0].size(), stream_max_size[922]);
        channel_quantities.push_back(StreamingMemory_100_out0_stream[0].size());
        stream_max_size[923] = std::max<size_t>(StreamingMemory_100_out1_stream[0].size(), stream_max_size[923]);
        channel_quantities.push_back(StreamingMemory_100_out1_stream[0].size());
        stream_max_size[924] = std::max<size_t>(StreamingLineBuffer_27_out0_stream[0].size(), stream_max_size[924]);
        channel_quantities.push_back(StreamingLineBuffer_27_out0_stream[0].size());
        stream_max_size[925] = std::max<size_t>(StreamingLineBuffer_27_out0_stream[1].size(), stream_max_size[925]);
        channel_quantities.push_back(StreamingLineBuffer_27_out0_stream[1].size());
        stream_max_size[926] = std::max<size_t>(StreamingLineBuffer_27_out0_stream[2].size(), stream_max_size[926]);
        channel_quantities.push_back(StreamingLineBuffer_27_out0_stream[2].size());
        stream_max_size[927] = std::max<size_t>(StreamingLineBuffer_27_out0_stream[3].size(), stream_max_size[927]);
        channel_quantities.push_back(StreamingLineBuffer_27_out0_stream[3].size());
        stream_max_size[928] = std::max<size_t>(StreamingLineBuffer_27_out0_stream[4].size(), stream_max_size[928]);
        channel_quantities.push_back(StreamingLineBuffer_27_out0_stream[4].size());
        stream_max_size[929] = std::max<size_t>(StreamingLineBuffer_27_out0_stream[5].size(), stream_max_size[929]);
        channel_quantities.push_back(StreamingLineBuffer_27_out0_stream[5].size());
        stream_max_size[930] = std::max<size_t>(StreamingLineBuffer_27_out0_stream[6].size(), stream_max_size[930]);
        channel_quantities.push_back(StreamingLineBuffer_27_out0_stream[6].size());
        stream_max_size[931] = std::max<size_t>(StreamingLineBuffer_27_out0_stream[7].size(), stream_max_size[931]);
        channel_quantities.push_back(StreamingLineBuffer_27_out0_stream[7].size());
        stream_max_size[932] = std::max<size_t>(StreamingLineBuffer_27_out0_stream[8].size(), stream_max_size[932]);
        channel_quantities.push_back(StreamingLineBuffer_27_out0_stream[8].size());
        stream_max_size[933] = std::max<size_t>(StreamingLineBuffer_27_out0_stream[9].size(), stream_max_size[933]);
        channel_quantities.push_back(StreamingLineBuffer_27_out0_stream[9].size());
        stream_max_size[934] = std::max<size_t>(StreamingLineBuffer_27_out0_stream[10].size(), stream_max_size[934]);
        channel_quantities.push_back(StreamingLineBuffer_27_out0_stream[10].size());
        stream_max_size[935] = std::max<size_t>(StreamingLineBuffer_27_out0_stream[11].size(), stream_max_size[935]);
        channel_quantities.push_back(StreamingLineBuffer_27_out0_stream[11].size());
        stream_max_size[936] = std::max<size_t>(StreamingLineBuffer_27_out0_stream_prepad[0].size(), stream_max_size[936]);
        channel_quantities.push_back(StreamingLineBuffer_27_out0_stream_prepad[0].size());
        stream_max_size[937] = std::max<size_t>(StreamingLineBuffer_27_out0_stream_prepad[1].size(), stream_max_size[937]);
        channel_quantities.push_back(StreamingLineBuffer_27_out0_stream_prepad[1].size());
        stream_max_size[938] = std::max<size_t>(StreamingLineBuffer_27_out0_stream_prepad[2].size(), stream_max_size[938]);
        channel_quantities.push_back(StreamingLineBuffer_27_out0_stream_prepad[2].size());
        stream_max_size[939] = std::max<size_t>(StreamingLineBuffer_27_out0_stream_prepad[3].size(), stream_max_size[939]);
        channel_quantities.push_back(StreamingLineBuffer_27_out0_stream_prepad[3].size());
        stream_max_size[940] = std::max<size_t>(StreamingLineBuffer_27_out0_stream_prepad[4].size(), stream_max_size[940]);
        channel_quantities.push_back(StreamingLineBuffer_27_out0_stream_prepad[4].size());
        stream_max_size[941] = std::max<size_t>(StreamingLineBuffer_27_out0_stream_prepad[5].size(), stream_max_size[941]);
        channel_quantities.push_back(StreamingLineBuffer_27_out0_stream_prepad[5].size());
        stream_max_size[942] = std::max<size_t>(StreamingLineBuffer_27_out0_stream_prepad[6].size(), stream_max_size[942]);
        channel_quantities.push_back(StreamingLineBuffer_27_out0_stream_prepad[6].size());
        stream_max_size[943] = std::max<size_t>(StreamingLineBuffer_27_out0_stream_prepad[7].size(), stream_max_size[943]);
        channel_quantities.push_back(StreamingLineBuffer_27_out0_stream_prepad[7].size());
        stream_max_size[944] = std::max<size_t>(StreamingLineBuffer_27_out0_stream_prepad[8].size(), stream_max_size[944]);
        channel_quantities.push_back(StreamingLineBuffer_27_out0_stream_prepad[8].size());
        stream_max_size[945] = std::max<size_t>(StreamingLineBuffer_27_out0_stream_prepad[9].size(), stream_max_size[945]);
        channel_quantities.push_back(StreamingLineBuffer_27_out0_stream_prepad[9].size());
        stream_max_size[946] = std::max<size_t>(StreamingLineBuffer_27_out0_stream_prepad[10].size(), stream_max_size[946]);
        channel_quantities.push_back(StreamingLineBuffer_27_out0_stream_prepad[10].size());
        stream_max_size[947] = std::max<size_t>(StreamingLineBuffer_27_out0_stream_prepad[11].size(), stream_max_size[947]);
        channel_quantities.push_back(StreamingLineBuffer_27_out0_stream_prepad[11].size());
        stream_max_size[948] = std::max<size_t>(StreamingLineBuffer_27_buffer_stream[0].size(), stream_max_size[948]);
        channel_quantities.push_back(StreamingLineBuffer_27_buffer_stream[0].size());
        stream_max_size[949] = std::max<size_t>(StreamingLineBuffer_27_buffer_stream[1].size(), stream_max_size[949]);
        channel_quantities.push_back(StreamingLineBuffer_27_buffer_stream[1].size());
        stream_max_size[950] = std::max<size_t>(StreamingLineBuffer_27_buffer_stream[2].size(), stream_max_size[950]);
        channel_quantities.push_back(StreamingLineBuffer_27_buffer_stream[2].size());
        stream_max_size[951] = std::max<size_t>(StreamingLineBuffer_27_buffer_stream[3].size(), stream_max_size[951]);
        channel_quantities.push_back(StreamingLineBuffer_27_buffer_stream[3].size());
        stream_max_size[952] = std::max<size_t>(StreamingLineBuffer_27_buffer_stream[4].size(), stream_max_size[952]);
        channel_quantities.push_back(StreamingLineBuffer_27_buffer_stream[4].size());
        stream_max_size[953] = std::max<size_t>(StreamingLineBuffer_27_buffer_stream[5].size(), stream_max_size[953]);
        channel_quantities.push_back(StreamingLineBuffer_27_buffer_stream[5].size());
        stream_max_size[954] = std::max<size_t>(StreamingLineBuffer_27_buffer_stream[6].size(), stream_max_size[954]);
        channel_quantities.push_back(StreamingLineBuffer_27_buffer_stream[6].size());
        stream_max_size[955] = std::max<size_t>(StreamingLineBuffer_27_buffer_stream[7].size(), stream_max_size[955]);
        channel_quantities.push_back(StreamingLineBuffer_27_buffer_stream[7].size());
        stream_max_size[956] = std::max<size_t>(StreamingLineBuffer_27_buffer_stream[8].size(), stream_max_size[956]);
        channel_quantities.push_back(StreamingLineBuffer_27_buffer_stream[8].size());
        stream_max_size[957] = std::max<size_t>(StreamingLineBuffer_27_buffer_stream[9].size(), stream_max_size[957]);
        channel_quantities.push_back(StreamingLineBuffer_27_buffer_stream[9].size());
        stream_max_size[958] = std::max<size_t>(StreamingMemory_101_out0_stream[0].size(), stream_max_size[958]);
        channel_quantities.push_back(StreamingMemory_101_out0_stream[0].size());
        stream_max_size[959] = std::max<size_t>(StreamingMemory_101_out1_stream[0].size(), stream_max_size[959]);
        channel_quantities.push_back(StreamingMemory_101_out1_stream[0].size());
        stream_max_size[960] = std::max<size_t>(StreamingDepthwiseConv_9_out0_stream[0].size(), stream_max_size[960]);
        channel_quantities.push_back(StreamingDepthwiseConv_9_out0_stream[0].size());
        stream_max_size[961] = std::max<size_t>(StreamingDepthwiseConv_9_out0_stream[1].size(), stream_max_size[961]);
        channel_quantities.push_back(StreamingDepthwiseConv_9_out0_stream[1].size());
        stream_max_size[962] = std::max<size_t>(StreamingMemory_102_out0_stream[0].size(), stream_max_size[962]);
        channel_quantities.push_back(StreamingMemory_102_out0_stream[0].size());
        stream_max_size[963] = std::max<size_t>(StreamingMemory_102_out1_stream[0].size(), stream_max_size[963]);
        channel_quantities.push_back(StreamingMemory_102_out1_stream[0].size());
        stream_max_size[964] = std::max<size_t>(BandwidthAdjustIncreaseChannels_15_out0_stream[0].size(), stream_max_size[964]);
        channel_quantities.push_back(BandwidthAdjustIncreaseChannels_15_out0_stream[0].size());
        stream_max_size[965] = std::max<size_t>(BandwidthAdjustIncreaseChannels_15_out0_stream[1].size(), stream_max_size[965]);
        channel_quantities.push_back(BandwidthAdjustIncreaseChannels_15_out0_stream[1].size());
        stream_max_size[966] = std::max<size_t>(StreamingMemory_103_out0_stream[0].size(), stream_max_size[966]);
        channel_quantities.push_back(StreamingMemory_103_out0_stream[0].size());
        stream_max_size[967] = std::max<size_t>(StreamingMemory_103_out1_stream[0].size(), stream_max_size[967]);
        channel_quantities.push_back(StreamingMemory_103_out1_stream[0].size());
        stream_max_size[968] = std::max<size_t>(StreamingLineBuffer_28_out0_stream[0].size(), stream_max_size[968]);
        channel_quantities.push_back(StreamingLineBuffer_28_out0_stream[0].size());
        stream_max_size[969] = std::max<size_t>(StreamingLineBuffer_28_out0_stream[1].size(), stream_max_size[969]);
        channel_quantities.push_back(StreamingLineBuffer_28_out0_stream[1].size());
        stream_max_size[970] = std::max<size_t>(StreamingMemory_104_out0_stream[0].size(), stream_max_size[970]);
        channel_quantities.push_back(StreamingMemory_104_out0_stream[0].size());
        stream_max_size[971] = std::max<size_t>(StreamingMemory_104_out1_stream[0].size(), stream_max_size[971]);
        channel_quantities.push_back(StreamingMemory_104_out1_stream[0].size());
        stream_max_size[972] = std::max<size_t>(StreamingConv_19_out0_stream[0].size(), stream_max_size[972]);
        channel_quantities.push_back(StreamingConv_19_out0_stream[0].size());
        stream_max_size[973] = std::max<size_t>(StreamingConv_19_out0_stream[1].size(), stream_max_size[973]);
        channel_quantities.push_back(StreamingConv_19_out0_stream[1].size());
        stream_max_size[974] = std::max<size_t>(StreamingMemory_105_out0_stream[0].size(), stream_max_size[974]);
        channel_quantities.push_back(StreamingMemory_105_out0_stream[0].size());
        stream_max_size[975] = std::max<size_t>(StreamingAdd_5_out0_stream[0].size(), stream_max_size[975]);
        channel_quantities.push_back(StreamingAdd_5_out0_stream[0].size());
        stream_max_size[976] = std::max<size_t>(StreamingAdd_5_out0_stream[1].size(), stream_max_size[976]);
        channel_quantities.push_back(StreamingAdd_5_out0_stream[1].size());
        stream_max_size[977] = std::max<size_t>(StreamingLineBuffer_29_out0_stream[0].size(), stream_max_size[977]);
        channel_quantities.push_back(StreamingLineBuffer_29_out0_stream[0].size());
        stream_max_size[978] = std::max<size_t>(StreamingLineBuffer_29_out0_stream[1].size(), stream_max_size[978]);
        channel_quantities.push_back(StreamingLineBuffer_29_out0_stream[1].size());
        stream_max_size[979] = std::max<size_t>(StreamingConv_20_out0_stream[0].size(), stream_max_size[979]);
        channel_quantities.push_back(StreamingConv_20_out0_stream[0].size());
        stream_max_size[980] = std::max<size_t>(StreamingConv_20_out0_stream[1].size(), stream_max_size[980]);
        channel_quantities.push_back(StreamingConv_20_out0_stream[1].size());
        stream_max_size[981] = std::max<size_t>(BandwidthAdjustDecreaseChannels_11_out0_stream[0].size(), stream_max_size[981]);
        channel_quantities.push_back(BandwidthAdjustDecreaseChannels_11_out0_stream[0].size());
        stream_max_size[982] = std::max<size_t>(BandwidthAdjustDecreaseChannels_11_out0_stream[1].size(), stream_max_size[982]);
        channel_quantities.push_back(BandwidthAdjustDecreaseChannels_11_out0_stream[1].size());
        stream_max_size[983] = std::max<size_t>(StreamingLineBuffer_30_out0_stream[0].size(), stream_max_size[983]);
        channel_quantities.push_back(StreamingLineBuffer_30_out0_stream[0].size());
        stream_max_size[984] = std::max<size_t>(StreamingLineBuffer_30_out0_stream[1].size(), stream_max_size[984]);
        channel_quantities.push_back(StreamingLineBuffer_30_out0_stream[1].size());
        stream_max_size[985] = std::max<size_t>(StreamingLineBuffer_30_out0_stream[2].size(), stream_max_size[985]);
        channel_quantities.push_back(StreamingLineBuffer_30_out0_stream[2].size());
        stream_max_size[986] = std::max<size_t>(StreamingLineBuffer_30_out0_stream[3].size(), stream_max_size[986]);
        channel_quantities.push_back(StreamingLineBuffer_30_out0_stream[3].size());
        stream_max_size[987] = std::max<size_t>(StreamingLineBuffer_30_out0_stream[4].size(), stream_max_size[987]);
        channel_quantities.push_back(StreamingLineBuffer_30_out0_stream[4].size());
        stream_max_size[988] = std::max<size_t>(StreamingLineBuffer_30_out0_stream[5].size(), stream_max_size[988]);
        channel_quantities.push_back(StreamingLineBuffer_30_out0_stream[5].size());
        stream_max_size[989] = std::max<size_t>(StreamingLineBuffer_30_out0_stream[6].size(), stream_max_size[989]);
        channel_quantities.push_back(StreamingLineBuffer_30_out0_stream[6].size());
        stream_max_size[990] = std::max<size_t>(StreamingLineBuffer_30_out0_stream[7].size(), stream_max_size[990]);
        channel_quantities.push_back(StreamingLineBuffer_30_out0_stream[7].size());
        stream_max_size[991] = std::max<size_t>(StreamingLineBuffer_30_out0_stream[8].size(), stream_max_size[991]);
        channel_quantities.push_back(StreamingLineBuffer_30_out0_stream[8].size());
        stream_max_size[992] = std::max<size_t>(StreamingLineBuffer_30_out0_stream[9].size(), stream_max_size[992]);
        channel_quantities.push_back(StreamingLineBuffer_30_out0_stream[9].size());
        stream_max_size[993] = std::max<size_t>(StreamingLineBuffer_30_out0_stream[10].size(), stream_max_size[993]);
        channel_quantities.push_back(StreamingLineBuffer_30_out0_stream[10].size());
        stream_max_size[994] = std::max<size_t>(StreamingLineBuffer_30_out0_stream[11].size(), stream_max_size[994]);
        channel_quantities.push_back(StreamingLineBuffer_30_out0_stream[11].size());
        stream_max_size[995] = std::max<size_t>(StreamingLineBuffer_30_out0_stream_prepad[0].size(), stream_max_size[995]);
        channel_quantities.push_back(StreamingLineBuffer_30_out0_stream_prepad[0].size());
        stream_max_size[996] = std::max<size_t>(StreamingLineBuffer_30_out0_stream_prepad[1].size(), stream_max_size[996]);
        channel_quantities.push_back(StreamingLineBuffer_30_out0_stream_prepad[1].size());
        stream_max_size[997] = std::max<size_t>(StreamingLineBuffer_30_out0_stream_prepad[2].size(), stream_max_size[997]);
        channel_quantities.push_back(StreamingLineBuffer_30_out0_stream_prepad[2].size());
        stream_max_size[998] = std::max<size_t>(StreamingLineBuffer_30_out0_stream_prepad[3].size(), stream_max_size[998]);
        channel_quantities.push_back(StreamingLineBuffer_30_out0_stream_prepad[3].size());
        stream_max_size[999] = std::max<size_t>(StreamingLineBuffer_30_out0_stream_prepad[4].size(), stream_max_size[999]);
        channel_quantities.push_back(StreamingLineBuffer_30_out0_stream_prepad[4].size());
        stream_max_size[1000] = std::max<size_t>(StreamingLineBuffer_30_out0_stream_prepad[5].size(), stream_max_size[1000]);
        channel_quantities.push_back(StreamingLineBuffer_30_out0_stream_prepad[5].size());
        stream_max_size[1001] = std::max<size_t>(StreamingLineBuffer_30_out0_stream_prepad[6].size(), stream_max_size[1001]);
        channel_quantities.push_back(StreamingLineBuffer_30_out0_stream_prepad[6].size());
        stream_max_size[1002] = std::max<size_t>(StreamingLineBuffer_30_out0_stream_prepad[7].size(), stream_max_size[1002]);
        channel_quantities.push_back(StreamingLineBuffer_30_out0_stream_prepad[7].size());
        stream_max_size[1003] = std::max<size_t>(StreamingLineBuffer_30_out0_stream_prepad[8].size(), stream_max_size[1003]);
        channel_quantities.push_back(StreamingLineBuffer_30_out0_stream_prepad[8].size());
        stream_max_size[1004] = std::max<size_t>(StreamingLineBuffer_30_out0_stream_prepad[9].size(), stream_max_size[1004]);
        channel_quantities.push_back(StreamingLineBuffer_30_out0_stream_prepad[9].size());
        stream_max_size[1005] = std::max<size_t>(StreamingLineBuffer_30_out0_stream_prepad[10].size(), stream_max_size[1005]);
        channel_quantities.push_back(StreamingLineBuffer_30_out0_stream_prepad[10].size());
        stream_max_size[1006] = std::max<size_t>(StreamingLineBuffer_30_out0_stream_prepad[11].size(), stream_max_size[1006]);
        channel_quantities.push_back(StreamingLineBuffer_30_out0_stream_prepad[11].size());
        stream_max_size[1007] = std::max<size_t>(StreamingLineBuffer_30_buffer_stream[0].size(), stream_max_size[1007]);
        channel_quantities.push_back(StreamingLineBuffer_30_buffer_stream[0].size());
        stream_max_size[1008] = std::max<size_t>(StreamingLineBuffer_30_buffer_stream[1].size(), stream_max_size[1008]);
        channel_quantities.push_back(StreamingLineBuffer_30_buffer_stream[1].size());
        stream_max_size[1009] = std::max<size_t>(StreamingLineBuffer_30_buffer_stream[2].size(), stream_max_size[1009]);
        channel_quantities.push_back(StreamingLineBuffer_30_buffer_stream[2].size());
        stream_max_size[1010] = std::max<size_t>(StreamingLineBuffer_30_buffer_stream[3].size(), stream_max_size[1010]);
        channel_quantities.push_back(StreamingLineBuffer_30_buffer_stream[3].size());
        stream_max_size[1011] = std::max<size_t>(StreamingLineBuffer_30_buffer_stream[4].size(), stream_max_size[1011]);
        channel_quantities.push_back(StreamingLineBuffer_30_buffer_stream[4].size());
        stream_max_size[1012] = std::max<size_t>(StreamingLineBuffer_30_buffer_stream[5].size(), stream_max_size[1012]);
        channel_quantities.push_back(StreamingLineBuffer_30_buffer_stream[5].size());
        stream_max_size[1013] = std::max<size_t>(StreamingLineBuffer_30_buffer_stream[6].size(), stream_max_size[1013]);
        channel_quantities.push_back(StreamingLineBuffer_30_buffer_stream[6].size());
        stream_max_size[1014] = std::max<size_t>(StreamingLineBuffer_30_buffer_stream[7].size(), stream_max_size[1014]);
        channel_quantities.push_back(StreamingLineBuffer_30_buffer_stream[7].size());
        stream_max_size[1015] = std::max<size_t>(StreamingLineBuffer_30_buffer_stream[8].size(), stream_max_size[1015]);
        channel_quantities.push_back(StreamingLineBuffer_30_buffer_stream[8].size());
        stream_max_size[1016] = std::max<size_t>(StreamingLineBuffer_30_buffer_stream[9].size(), stream_max_size[1016]);
        channel_quantities.push_back(StreamingLineBuffer_30_buffer_stream[9].size());
        stream_max_size[1017] = std::max<size_t>(StreamingDepthwiseConv_10_out0_stream[0].size(), stream_max_size[1017]);
        channel_quantities.push_back(StreamingDepthwiseConv_10_out0_stream[0].size());
        stream_max_size[1018] = std::max<size_t>(StreamingDepthwiseConv_10_out0_stream[1].size(), stream_max_size[1018]);
        channel_quantities.push_back(StreamingDepthwiseConv_10_out0_stream[1].size());
        stream_max_size[1019] = std::max<size_t>(BandwidthAdjustIncreaseChannels_16_out0_stream[0].size(), stream_max_size[1019]);
        channel_quantities.push_back(BandwidthAdjustIncreaseChannels_16_out0_stream[0].size());
        stream_max_size[1020] = std::max<size_t>(BandwidthAdjustIncreaseChannels_16_out0_stream[1].size(), stream_max_size[1020]);
        channel_quantities.push_back(BandwidthAdjustIncreaseChannels_16_out0_stream[1].size());
        stream_max_size[1021] = std::max<size_t>(StreamingLineBuffer_31_out0_stream[0].size(), stream_max_size[1021]);
        channel_quantities.push_back(StreamingLineBuffer_31_out0_stream[0].size());
        stream_max_size[1022] = std::max<size_t>(StreamingLineBuffer_31_out0_stream[1].size(), stream_max_size[1022]);
        channel_quantities.push_back(StreamingLineBuffer_31_out0_stream[1].size());
        stream_max_size[1023] = std::max<size_t>(StreamingConv_21_out0_stream[0].size(), stream_max_size[1023]);
        channel_quantities.push_back(StreamingConv_21_out0_stream[0].size());
        stream_max_size[1024] = std::max<size_t>(StreamingConv_21_out0_stream[1].size(), stream_max_size[1024]);
        channel_quantities.push_back(StreamingConv_21_out0_stream[1].size());
        stream_max_size[1025] = std::max<size_t>(TensorDuplicator_6_out0_stream[0].size(), stream_max_size[1025]);
        channel_quantities.push_back(TensorDuplicator_6_out0_stream[0].size());
        stream_max_size[1026] = std::max<size_t>(TensorDuplicator_6_out0_stream[1].size(), stream_max_size[1026]);
        channel_quantities.push_back(TensorDuplicator_6_out0_stream[1].size());
        stream_max_size[1027] = std::max<size_t>(TensorDuplicator_6_out1_stream[0].size(), stream_max_size[1027]);
        channel_quantities.push_back(TensorDuplicator_6_out1_stream[0].size());
        stream_max_size[1028] = std::max<size_t>(TensorDuplicator_6_out1_stream[1].size(), stream_max_size[1028]);
        channel_quantities.push_back(TensorDuplicator_6_out1_stream[1].size());
        stream_max_size[1029] = std::max<size_t>(BandwidthAdjustDecreaseChannels_12_out0_stream[0].size(), stream_max_size[1029]);
        channel_quantities.push_back(BandwidthAdjustDecreaseChannels_12_out0_stream[0].size());
        stream_max_size[1030] = std::max<size_t>(BandwidthAdjustDecreaseChannels_12_out0_stream[1].size(), stream_max_size[1030]);
        channel_quantities.push_back(BandwidthAdjustDecreaseChannels_12_out0_stream[1].size());
        stream_max_size[1031] = std::max<size_t>(BandwidthAdjustIncreaseChannels_17_out0_stream[0].size(), stream_max_size[1031]);
        channel_quantities.push_back(BandwidthAdjustIncreaseChannels_17_out0_stream[0].size());
        stream_max_size[1032] = std::max<size_t>(BandwidthAdjustIncreaseChannels_17_out0_stream[1].size(), stream_max_size[1032]);
        channel_quantities.push_back(BandwidthAdjustIncreaseChannels_17_out0_stream[1].size());
        stream_max_size[1033] = std::max<size_t>(BandwidthAdjustDecreaseStreams_6_out0_stream[0].size(), stream_max_size[1033]);
        channel_quantities.push_back(BandwidthAdjustDecreaseStreams_6_out0_stream[0].size());
        stream_max_size[1034] = std::max<size_t>(StreamingConv_22_out0_stream[0].size(), stream_max_size[1034]);
        channel_quantities.push_back(StreamingConv_22_out0_stream[0].size());
        stream_max_size[1035] = std::max<size_t>(BandwidthAdjustDecreaseChannels_13_out0_stream[0].size(), stream_max_size[1035]);
        channel_quantities.push_back(BandwidthAdjustDecreaseChannels_13_out0_stream[0].size());
        stream_max_size[1036] = std::max<size_t>(StreamingLineBuffer_32_out0_stream[0].size(), stream_max_size[1036]);
        channel_quantities.push_back(StreamingLineBuffer_32_out0_stream[0].size());
        stream_max_size[1037] = std::max<size_t>(StreamingLineBuffer_32_out0_stream[1].size(), stream_max_size[1037]);
        channel_quantities.push_back(StreamingLineBuffer_32_out0_stream[1].size());
        stream_max_size[1038] = std::max<size_t>(StreamingLineBuffer_32_out0_stream[2].size(), stream_max_size[1038]);
        channel_quantities.push_back(StreamingLineBuffer_32_out0_stream[2].size());
        stream_max_size[1039] = std::max<size_t>(StreamingLineBuffer_32_out0_stream[3].size(), stream_max_size[1039]);
        channel_quantities.push_back(StreamingLineBuffer_32_out0_stream[3].size());
        stream_max_size[1040] = std::max<size_t>(StreamingLineBuffer_32_out0_stream[4].size(), stream_max_size[1040]);
        channel_quantities.push_back(StreamingLineBuffer_32_out0_stream[4].size());
        stream_max_size[1041] = std::max<size_t>(StreamingLineBuffer_32_out0_stream[5].size(), stream_max_size[1041]);
        channel_quantities.push_back(StreamingLineBuffer_32_out0_stream[5].size());
        stream_max_size[1042] = std::max<size_t>(StreamingLineBuffer_32_out0_stream[6].size(), stream_max_size[1042]);
        channel_quantities.push_back(StreamingLineBuffer_32_out0_stream[6].size());
        stream_max_size[1043] = std::max<size_t>(StreamingLineBuffer_32_out0_stream[7].size(), stream_max_size[1043]);
        channel_quantities.push_back(StreamingLineBuffer_32_out0_stream[7].size());
        stream_max_size[1044] = std::max<size_t>(StreamingLineBuffer_32_out0_stream[8].size(), stream_max_size[1044]);
        channel_quantities.push_back(StreamingLineBuffer_32_out0_stream[8].size());
        stream_max_size[1045] = std::max<size_t>(StreamingLineBuffer_32_out0_stream_prepad[0].size(), stream_max_size[1045]);
        channel_quantities.push_back(StreamingLineBuffer_32_out0_stream_prepad[0].size());
        stream_max_size[1046] = std::max<size_t>(StreamingLineBuffer_32_out0_stream_prepad[1].size(), stream_max_size[1046]);
        channel_quantities.push_back(StreamingLineBuffer_32_out0_stream_prepad[1].size());
        stream_max_size[1047] = std::max<size_t>(StreamingLineBuffer_32_out0_stream_prepad[2].size(), stream_max_size[1047]);
        channel_quantities.push_back(StreamingLineBuffer_32_out0_stream_prepad[2].size());
        stream_max_size[1048] = std::max<size_t>(StreamingLineBuffer_32_out0_stream_prepad[3].size(), stream_max_size[1048]);
        channel_quantities.push_back(StreamingLineBuffer_32_out0_stream_prepad[3].size());
        stream_max_size[1049] = std::max<size_t>(StreamingLineBuffer_32_out0_stream_prepad[4].size(), stream_max_size[1049]);
        channel_quantities.push_back(StreamingLineBuffer_32_out0_stream_prepad[4].size());
        stream_max_size[1050] = std::max<size_t>(StreamingLineBuffer_32_out0_stream_prepad[5].size(), stream_max_size[1050]);
        channel_quantities.push_back(StreamingLineBuffer_32_out0_stream_prepad[5].size());
        stream_max_size[1051] = std::max<size_t>(StreamingLineBuffer_32_out0_stream_prepad[6].size(), stream_max_size[1051]);
        channel_quantities.push_back(StreamingLineBuffer_32_out0_stream_prepad[6].size());
        stream_max_size[1052] = std::max<size_t>(StreamingLineBuffer_32_out0_stream_prepad[7].size(), stream_max_size[1052]);
        channel_quantities.push_back(StreamingLineBuffer_32_out0_stream_prepad[7].size());
        stream_max_size[1053] = std::max<size_t>(StreamingLineBuffer_32_out0_stream_prepad[8].size(), stream_max_size[1053]);
        channel_quantities.push_back(StreamingLineBuffer_32_out0_stream_prepad[8].size());
        stream_max_size[1054] = std::max<size_t>(StreamingLineBuffer_32_buffer_stream[0].size(), stream_max_size[1054]);
        channel_quantities.push_back(StreamingLineBuffer_32_buffer_stream[0].size());
        stream_max_size[1055] = std::max<size_t>(StreamingLineBuffer_32_buffer_stream[1].size(), stream_max_size[1055]);
        channel_quantities.push_back(StreamingLineBuffer_32_buffer_stream[1].size());
        stream_max_size[1056] = std::max<size_t>(StreamingLineBuffer_32_buffer_stream[2].size(), stream_max_size[1056]);
        channel_quantities.push_back(StreamingLineBuffer_32_buffer_stream[2].size());
        stream_max_size[1057] = std::max<size_t>(StreamingLineBuffer_32_buffer_stream[3].size(), stream_max_size[1057]);
        channel_quantities.push_back(StreamingLineBuffer_32_buffer_stream[3].size());
        stream_max_size[1058] = std::max<size_t>(StreamingLineBuffer_32_buffer_stream[4].size(), stream_max_size[1058]);
        channel_quantities.push_back(StreamingLineBuffer_32_buffer_stream[4].size());
        stream_max_size[1059] = std::max<size_t>(StreamingLineBuffer_32_buffer_stream[5].size(), stream_max_size[1059]);
        channel_quantities.push_back(StreamingLineBuffer_32_buffer_stream[5].size());
        stream_max_size[1060] = std::max<size_t>(StreamingLineBuffer_32_buffer_stream[6].size(), stream_max_size[1060]);
        channel_quantities.push_back(StreamingLineBuffer_32_buffer_stream[6].size());
        stream_max_size[1061] = std::max<size_t>(StreamingLineBuffer_32_buffer_stream[7].size(), stream_max_size[1061]);
        channel_quantities.push_back(StreamingLineBuffer_32_buffer_stream[7].size());
        stream_max_size[1062] = std::max<size_t>(StreamingDepthwiseConv_11_out0_stream[0].size(), stream_max_size[1062]);
        channel_quantities.push_back(StreamingDepthwiseConv_11_out0_stream[0].size());
        stream_max_size[1063] = std::max<size_t>(BandwidthAdjustIncreaseChannels_18_out0_stream[0].size(), stream_max_size[1063]);
        channel_quantities.push_back(BandwidthAdjustIncreaseChannels_18_out0_stream[0].size());
        stream_max_size[1064] = std::max<size_t>(BandwidthAdjustIncreaseStreams_8_out0_stream[0].size(), stream_max_size[1064]);
        channel_quantities.push_back(BandwidthAdjustIncreaseStreams_8_out0_stream[0].size());
        stream_max_size[1065] = std::max<size_t>(BandwidthAdjustIncreaseStreams_8_out0_stream[1].size(), stream_max_size[1065]);
        channel_quantities.push_back(BandwidthAdjustIncreaseStreams_8_out0_stream[1].size());
        stream_max_size[1066] = std::max<size_t>(StreamingLineBuffer_33_out0_stream[0].size(), stream_max_size[1066]);
        channel_quantities.push_back(StreamingLineBuffer_33_out0_stream[0].size());
        stream_max_size[1067] = std::max<size_t>(StreamingLineBuffer_33_out0_stream[1].size(), stream_max_size[1067]);
        channel_quantities.push_back(StreamingLineBuffer_33_out0_stream[1].size());
        stream_max_size[1068] = std::max<size_t>(StreamingConv_23_out0_stream[0].size(), stream_max_size[1068]);
        channel_quantities.push_back(StreamingConv_23_out0_stream[0].size());
        stream_max_size[1069] = std::max<size_t>(StreamingConv_23_out0_stream[1].size(), stream_max_size[1069]);
        channel_quantities.push_back(StreamingConv_23_out0_stream[1].size());
        stream_max_size[1070] = std::max<size_t>(StreamingAdd_6_out0_stream[0].size(), stream_max_size[1070]);
        channel_quantities.push_back(StreamingAdd_6_out0_stream[0].size());
        stream_max_size[1071] = std::max<size_t>(StreamingAdd_6_out0_stream[1].size(), stream_max_size[1071]);
        channel_quantities.push_back(StreamingAdd_6_out0_stream[1].size());
        stream_max_size[1072] = std::max<size_t>(TensorDuplicator_7_out0_stream[0].size(), stream_max_size[1072]);
        channel_quantities.push_back(TensorDuplicator_7_out0_stream[0].size());
        stream_max_size[1073] = std::max<size_t>(TensorDuplicator_7_out0_stream[1].size(), stream_max_size[1073]);
        channel_quantities.push_back(TensorDuplicator_7_out0_stream[1].size());
        stream_max_size[1074] = std::max<size_t>(TensorDuplicator_7_out1_stream[0].size(), stream_max_size[1074]);
        channel_quantities.push_back(TensorDuplicator_7_out1_stream[0].size());
        stream_max_size[1075] = std::max<size_t>(TensorDuplicator_7_out1_stream[1].size(), stream_max_size[1075]);
        channel_quantities.push_back(TensorDuplicator_7_out1_stream[1].size());
        stream_max_size[1076] = std::max<size_t>(BandwidthAdjustDecreaseChannels_14_out0_stream[0].size(), stream_max_size[1076]);
        channel_quantities.push_back(BandwidthAdjustDecreaseChannels_14_out0_stream[0].size());
        stream_max_size[1077] = std::max<size_t>(BandwidthAdjustDecreaseChannels_14_out0_stream[1].size(), stream_max_size[1077]);
        channel_quantities.push_back(BandwidthAdjustDecreaseChannels_14_out0_stream[1].size());
        stream_max_size[1078] = std::max<size_t>(BandwidthAdjustIncreaseChannels_19_out0_stream[0].size(), stream_max_size[1078]);
        channel_quantities.push_back(BandwidthAdjustIncreaseChannels_19_out0_stream[0].size());
        stream_max_size[1079] = std::max<size_t>(BandwidthAdjustIncreaseChannels_19_out0_stream[1].size(), stream_max_size[1079]);
        channel_quantities.push_back(BandwidthAdjustIncreaseChannels_19_out0_stream[1].size());
        stream_max_size[1080] = std::max<size_t>(BandwidthAdjustDecreaseStreams_7_out0_stream[0].size(), stream_max_size[1080]);
        channel_quantities.push_back(BandwidthAdjustDecreaseStreams_7_out0_stream[0].size());
        stream_max_size[1081] = std::max<size_t>(StreamingConv_24_out0_stream[0].size(), stream_max_size[1081]);
        channel_quantities.push_back(StreamingConv_24_out0_stream[0].size());
        stream_max_size[1082] = std::max<size_t>(BandwidthAdjustDecreaseChannels_15_out0_stream[0].size(), stream_max_size[1082]);
        channel_quantities.push_back(BandwidthAdjustDecreaseChannels_15_out0_stream[0].size());
        stream_max_size[1083] = std::max<size_t>(StreamingLineBuffer_34_out0_stream[0].size(), stream_max_size[1083]);
        channel_quantities.push_back(StreamingLineBuffer_34_out0_stream[0].size());
        stream_max_size[1084] = std::max<size_t>(StreamingLineBuffer_34_out0_stream[1].size(), stream_max_size[1084]);
        channel_quantities.push_back(StreamingLineBuffer_34_out0_stream[1].size());
        stream_max_size[1085] = std::max<size_t>(StreamingLineBuffer_34_out0_stream[2].size(), stream_max_size[1085]);
        channel_quantities.push_back(StreamingLineBuffer_34_out0_stream[2].size());
        stream_max_size[1086] = std::max<size_t>(StreamingLineBuffer_34_out0_stream[3].size(), stream_max_size[1086]);
        channel_quantities.push_back(StreamingLineBuffer_34_out0_stream[3].size());
        stream_max_size[1087] = std::max<size_t>(StreamingLineBuffer_34_out0_stream[4].size(), stream_max_size[1087]);
        channel_quantities.push_back(StreamingLineBuffer_34_out0_stream[4].size());
        stream_max_size[1088] = std::max<size_t>(StreamingLineBuffer_34_out0_stream[5].size(), stream_max_size[1088]);
        channel_quantities.push_back(StreamingLineBuffer_34_out0_stream[5].size());
        stream_max_size[1089] = std::max<size_t>(StreamingLineBuffer_34_out0_stream[6].size(), stream_max_size[1089]);
        channel_quantities.push_back(StreamingLineBuffer_34_out0_stream[6].size());
        stream_max_size[1090] = std::max<size_t>(StreamingLineBuffer_34_out0_stream[7].size(), stream_max_size[1090]);
        channel_quantities.push_back(StreamingLineBuffer_34_out0_stream[7].size());
        stream_max_size[1091] = std::max<size_t>(StreamingLineBuffer_34_out0_stream[8].size(), stream_max_size[1091]);
        channel_quantities.push_back(StreamingLineBuffer_34_out0_stream[8].size());
        stream_max_size[1092] = std::max<size_t>(StreamingLineBuffer_34_out0_stream_prepad[0].size(), stream_max_size[1092]);
        channel_quantities.push_back(StreamingLineBuffer_34_out0_stream_prepad[0].size());
        stream_max_size[1093] = std::max<size_t>(StreamingLineBuffer_34_out0_stream_prepad[1].size(), stream_max_size[1093]);
        channel_quantities.push_back(StreamingLineBuffer_34_out0_stream_prepad[1].size());
        stream_max_size[1094] = std::max<size_t>(StreamingLineBuffer_34_out0_stream_prepad[2].size(), stream_max_size[1094]);
        channel_quantities.push_back(StreamingLineBuffer_34_out0_stream_prepad[2].size());
        stream_max_size[1095] = std::max<size_t>(StreamingLineBuffer_34_out0_stream_prepad[3].size(), stream_max_size[1095]);
        channel_quantities.push_back(StreamingLineBuffer_34_out0_stream_prepad[3].size());
        stream_max_size[1096] = std::max<size_t>(StreamingLineBuffer_34_out0_stream_prepad[4].size(), stream_max_size[1096]);
        channel_quantities.push_back(StreamingLineBuffer_34_out0_stream_prepad[4].size());
        stream_max_size[1097] = std::max<size_t>(StreamingLineBuffer_34_out0_stream_prepad[5].size(), stream_max_size[1097]);
        channel_quantities.push_back(StreamingLineBuffer_34_out0_stream_prepad[5].size());
        stream_max_size[1098] = std::max<size_t>(StreamingLineBuffer_34_out0_stream_prepad[6].size(), stream_max_size[1098]);
        channel_quantities.push_back(StreamingLineBuffer_34_out0_stream_prepad[6].size());
        stream_max_size[1099] = std::max<size_t>(StreamingLineBuffer_34_out0_stream_prepad[7].size(), stream_max_size[1099]);
        channel_quantities.push_back(StreamingLineBuffer_34_out0_stream_prepad[7].size());
        stream_max_size[1100] = std::max<size_t>(StreamingLineBuffer_34_out0_stream_prepad[8].size(), stream_max_size[1100]);
        channel_quantities.push_back(StreamingLineBuffer_34_out0_stream_prepad[8].size());
        stream_max_size[1101] = std::max<size_t>(StreamingLineBuffer_34_buffer_stream[0].size(), stream_max_size[1101]);
        channel_quantities.push_back(StreamingLineBuffer_34_buffer_stream[0].size());
        stream_max_size[1102] = std::max<size_t>(StreamingLineBuffer_34_buffer_stream[1].size(), stream_max_size[1102]);
        channel_quantities.push_back(StreamingLineBuffer_34_buffer_stream[1].size());
        stream_max_size[1103] = std::max<size_t>(StreamingLineBuffer_34_buffer_stream[2].size(), stream_max_size[1103]);
        channel_quantities.push_back(StreamingLineBuffer_34_buffer_stream[2].size());
        stream_max_size[1104] = std::max<size_t>(StreamingLineBuffer_34_buffer_stream[3].size(), stream_max_size[1104]);
        channel_quantities.push_back(StreamingLineBuffer_34_buffer_stream[3].size());
        stream_max_size[1105] = std::max<size_t>(StreamingLineBuffer_34_buffer_stream[4].size(), stream_max_size[1105]);
        channel_quantities.push_back(StreamingLineBuffer_34_buffer_stream[4].size());
        stream_max_size[1106] = std::max<size_t>(StreamingLineBuffer_34_buffer_stream[5].size(), stream_max_size[1106]);
        channel_quantities.push_back(StreamingLineBuffer_34_buffer_stream[5].size());
        stream_max_size[1107] = std::max<size_t>(StreamingLineBuffer_34_buffer_stream[6].size(), stream_max_size[1107]);
        channel_quantities.push_back(StreamingLineBuffer_34_buffer_stream[6].size());
        stream_max_size[1108] = std::max<size_t>(StreamingLineBuffer_34_buffer_stream[7].size(), stream_max_size[1108]);
        channel_quantities.push_back(StreamingLineBuffer_34_buffer_stream[7].size());
        stream_max_size[1109] = std::max<size_t>(StreamingDepthwiseConv_12_out0_stream[0].size(), stream_max_size[1109]);
        channel_quantities.push_back(StreamingDepthwiseConv_12_out0_stream[0].size());
        stream_max_size[1110] = std::max<size_t>(BandwidthAdjustIncreaseChannels_20_out0_stream[0].size(), stream_max_size[1110]);
        channel_quantities.push_back(BandwidthAdjustIncreaseChannels_20_out0_stream[0].size());
        stream_max_size[1111] = std::max<size_t>(BandwidthAdjustIncreaseStreams_9_out0_stream[0].size(), stream_max_size[1111]);
        channel_quantities.push_back(BandwidthAdjustIncreaseStreams_9_out0_stream[0].size());
        stream_max_size[1112] = std::max<size_t>(BandwidthAdjustIncreaseStreams_9_out0_stream[1].size(), stream_max_size[1112]);
        channel_quantities.push_back(BandwidthAdjustIncreaseStreams_9_out0_stream[1].size());
        stream_max_size[1113] = std::max<size_t>(StreamingLineBuffer_35_out0_stream[0].size(), stream_max_size[1113]);
        channel_quantities.push_back(StreamingLineBuffer_35_out0_stream[0].size());
        stream_max_size[1114] = std::max<size_t>(StreamingLineBuffer_35_out0_stream[1].size(), stream_max_size[1114]);
        channel_quantities.push_back(StreamingLineBuffer_35_out0_stream[1].size());
        stream_max_size[1115] = std::max<size_t>(StreamingConv_25_out0_stream[0].size(), stream_max_size[1115]);
        channel_quantities.push_back(StreamingConv_25_out0_stream[0].size());
        stream_max_size[1116] = std::max<size_t>(StreamingConv_25_out0_stream[1].size(), stream_max_size[1116]);
        channel_quantities.push_back(StreamingConv_25_out0_stream[1].size());
        stream_max_size[1117] = std::max<size_t>(StreamingAdd_7_out0_stream[0].size(), stream_max_size[1117]);
        channel_quantities.push_back(StreamingAdd_7_out0_stream[0].size());
        stream_max_size[1118] = std::max<size_t>(StreamingAdd_7_out0_stream[1].size(), stream_max_size[1118]);
        channel_quantities.push_back(StreamingAdd_7_out0_stream[1].size());
        stream_max_size[1119] = std::max<size_t>(BandwidthAdjustDecreaseChannels_16_out0_stream[0].size(), stream_max_size[1119]);
        channel_quantities.push_back(BandwidthAdjustDecreaseChannels_16_out0_stream[0].size());
        stream_max_size[1120] = std::max<size_t>(BandwidthAdjustDecreaseChannels_16_out0_stream[1].size(), stream_max_size[1120]);
        channel_quantities.push_back(BandwidthAdjustDecreaseChannels_16_out0_stream[1].size());
        stream_max_size[1121] = std::max<size_t>(BandwidthAdjustIncreaseChannels_21_out0_stream[0].size(), stream_max_size[1121]);
        channel_quantities.push_back(BandwidthAdjustIncreaseChannels_21_out0_stream[0].size());
        stream_max_size[1122] = std::max<size_t>(BandwidthAdjustIncreaseChannels_21_out0_stream[1].size(), stream_max_size[1122]);
        channel_quantities.push_back(BandwidthAdjustIncreaseChannels_21_out0_stream[1].size());
        stream_max_size[1123] = std::max<size_t>(BandwidthAdjustDecreaseStreams_8_out0_stream[0].size(), stream_max_size[1123]);
        channel_quantities.push_back(BandwidthAdjustDecreaseStreams_8_out0_stream[0].size());
        stream_max_size[1124] = std::max<size_t>(StreamingConv_26_out0_stream[0].size(), stream_max_size[1124]);
        channel_quantities.push_back(StreamingConv_26_out0_stream[0].size());
        stream_max_size[1125] = std::max<size_t>(BandwidthAdjustDecreaseChannels_17_out0_stream[0].size(), stream_max_size[1125]);
        channel_quantities.push_back(BandwidthAdjustDecreaseChannels_17_out0_stream[0].size());
        stream_max_size[1126] = std::max<size_t>(StreamingLineBuffer_36_out0_stream[0].size(), stream_max_size[1126]);
        channel_quantities.push_back(StreamingLineBuffer_36_out0_stream[0].size());
        stream_max_size[1127] = std::max<size_t>(StreamingLineBuffer_36_out0_stream[1].size(), stream_max_size[1127]);
        channel_quantities.push_back(StreamingLineBuffer_36_out0_stream[1].size());
        stream_max_size[1128] = std::max<size_t>(StreamingLineBuffer_36_out0_stream[2].size(), stream_max_size[1128]);
        channel_quantities.push_back(StreamingLineBuffer_36_out0_stream[2].size());
        stream_max_size[1129] = std::max<size_t>(StreamingLineBuffer_36_out0_stream[3].size(), stream_max_size[1129]);
        channel_quantities.push_back(StreamingLineBuffer_36_out0_stream[3].size());
        stream_max_size[1130] = std::max<size_t>(StreamingLineBuffer_36_out0_stream[4].size(), stream_max_size[1130]);
        channel_quantities.push_back(StreamingLineBuffer_36_out0_stream[4].size());
        stream_max_size[1131] = std::max<size_t>(StreamingLineBuffer_36_out0_stream[5].size(), stream_max_size[1131]);
        channel_quantities.push_back(StreamingLineBuffer_36_out0_stream[5].size());
        stream_max_size[1132] = std::max<size_t>(StreamingLineBuffer_36_out0_stream[6].size(), stream_max_size[1132]);
        channel_quantities.push_back(StreamingLineBuffer_36_out0_stream[6].size());
        stream_max_size[1133] = std::max<size_t>(StreamingLineBuffer_36_out0_stream[7].size(), stream_max_size[1133]);
        channel_quantities.push_back(StreamingLineBuffer_36_out0_stream[7].size());
        stream_max_size[1134] = std::max<size_t>(StreamingLineBuffer_36_out0_stream[8].size(), stream_max_size[1134]);
        channel_quantities.push_back(StreamingLineBuffer_36_out0_stream[8].size());
        stream_max_size[1135] = std::max<size_t>(StreamingLineBuffer_36_out0_stream_prepad[0].size(), stream_max_size[1135]);
        channel_quantities.push_back(StreamingLineBuffer_36_out0_stream_prepad[0].size());
        stream_max_size[1136] = std::max<size_t>(StreamingLineBuffer_36_out0_stream_prepad[1].size(), stream_max_size[1136]);
        channel_quantities.push_back(StreamingLineBuffer_36_out0_stream_prepad[1].size());
        stream_max_size[1137] = std::max<size_t>(StreamingLineBuffer_36_out0_stream_prepad[2].size(), stream_max_size[1137]);
        channel_quantities.push_back(StreamingLineBuffer_36_out0_stream_prepad[2].size());
        stream_max_size[1138] = std::max<size_t>(StreamingLineBuffer_36_out0_stream_prepad[3].size(), stream_max_size[1138]);
        channel_quantities.push_back(StreamingLineBuffer_36_out0_stream_prepad[3].size());
        stream_max_size[1139] = std::max<size_t>(StreamingLineBuffer_36_out0_stream_prepad[4].size(), stream_max_size[1139]);
        channel_quantities.push_back(StreamingLineBuffer_36_out0_stream_prepad[4].size());
        stream_max_size[1140] = std::max<size_t>(StreamingLineBuffer_36_out0_stream_prepad[5].size(), stream_max_size[1140]);
        channel_quantities.push_back(StreamingLineBuffer_36_out0_stream_prepad[5].size());
        stream_max_size[1141] = std::max<size_t>(StreamingLineBuffer_36_out0_stream_prepad[6].size(), stream_max_size[1141]);
        channel_quantities.push_back(StreamingLineBuffer_36_out0_stream_prepad[6].size());
        stream_max_size[1142] = std::max<size_t>(StreamingLineBuffer_36_out0_stream_prepad[7].size(), stream_max_size[1142]);
        channel_quantities.push_back(StreamingLineBuffer_36_out0_stream_prepad[7].size());
        stream_max_size[1143] = std::max<size_t>(StreamingLineBuffer_36_out0_stream_prepad[8].size(), stream_max_size[1143]);
        channel_quantities.push_back(StreamingLineBuffer_36_out0_stream_prepad[8].size());
        stream_max_size[1144] = std::max<size_t>(StreamingLineBuffer_36_buffer_stream[0].size(), stream_max_size[1144]);
        channel_quantities.push_back(StreamingLineBuffer_36_buffer_stream[0].size());
        stream_max_size[1145] = std::max<size_t>(StreamingLineBuffer_36_buffer_stream[1].size(), stream_max_size[1145]);
        channel_quantities.push_back(StreamingLineBuffer_36_buffer_stream[1].size());
        stream_max_size[1146] = std::max<size_t>(StreamingLineBuffer_36_buffer_stream[2].size(), stream_max_size[1146]);
        channel_quantities.push_back(StreamingLineBuffer_36_buffer_stream[2].size());
        stream_max_size[1147] = std::max<size_t>(StreamingLineBuffer_36_buffer_stream[3].size(), stream_max_size[1147]);
        channel_quantities.push_back(StreamingLineBuffer_36_buffer_stream[3].size());
        stream_max_size[1148] = std::max<size_t>(StreamingLineBuffer_36_buffer_stream[4].size(), stream_max_size[1148]);
        channel_quantities.push_back(StreamingLineBuffer_36_buffer_stream[4].size());
        stream_max_size[1149] = std::max<size_t>(StreamingLineBuffer_36_buffer_stream[5].size(), stream_max_size[1149]);
        channel_quantities.push_back(StreamingLineBuffer_36_buffer_stream[5].size());
        stream_max_size[1150] = std::max<size_t>(StreamingLineBuffer_36_buffer_stream[6].size(), stream_max_size[1150]);
        channel_quantities.push_back(StreamingLineBuffer_36_buffer_stream[6].size());
        stream_max_size[1151] = std::max<size_t>(StreamingLineBuffer_36_buffer_stream[7].size(), stream_max_size[1151]);
        channel_quantities.push_back(StreamingLineBuffer_36_buffer_stream[7].size());
        stream_max_size[1152] = std::max<size_t>(StreamingDepthwiseConv_13_out0_stream[0].size(), stream_max_size[1152]);
        channel_quantities.push_back(StreamingDepthwiseConv_13_out0_stream[0].size());
        stream_max_size[1153] = std::max<size_t>(BandwidthAdjustIncreaseChannels_22_out0_stream[0].size(), stream_max_size[1153]);
        channel_quantities.push_back(BandwidthAdjustIncreaseChannels_22_out0_stream[0].size());
        stream_max_size[1154] = std::max<size_t>(StreamingConv_27_out0_stream[0].size(), stream_max_size[1154]);
        channel_quantities.push_back(StreamingConv_27_out0_stream[0].size());
        stream_max_size[1155] = std::max<size_t>(TensorDuplicator_8_out0_stream[0].size(), stream_max_size[1155]);
        channel_quantities.push_back(TensorDuplicator_8_out0_stream[0].size());
        stream_max_size[1156] = std::max<size_t>(TensorDuplicator_8_out1_stream[0].size(), stream_max_size[1156]);
        channel_quantities.push_back(TensorDuplicator_8_out1_stream[0].size());
        stream_max_size[1157] = std::max<size_t>(BandwidthAdjustDecreaseChannels_18_out0_stream[0].size(), stream_max_size[1157]);
        channel_quantities.push_back(BandwidthAdjustDecreaseChannels_18_out0_stream[0].size());
        stream_max_size[1158] = std::max<size_t>(BandwidthAdjustDecreaseChannels_19_out0_stream[0].size(), stream_max_size[1158]);
        channel_quantities.push_back(BandwidthAdjustDecreaseChannels_19_out0_stream[0].size());
        stream_max_size[1159] = std::max<size_t>(BandwidthAdjustIncreaseChannels_23_out0_stream[0].size(), stream_max_size[1159]);
        channel_quantities.push_back(BandwidthAdjustIncreaseChannels_23_out0_stream[0].size());
        stream_max_size[1160] = std::max<size_t>(StreamingConv_28_out0_stream[0].size(), stream_max_size[1160]);
        channel_quantities.push_back(StreamingConv_28_out0_stream[0].size());
        stream_max_size[1161] = std::max<size_t>(BandwidthAdjustDecreaseChannels_20_out0_stream[0].size(), stream_max_size[1161]);
        channel_quantities.push_back(BandwidthAdjustDecreaseChannels_20_out0_stream[0].size());
        stream_max_size[1162] = std::max<size_t>(StreamingLineBuffer_37_out0_stream[0].size(), stream_max_size[1162]);
        channel_quantities.push_back(StreamingLineBuffer_37_out0_stream[0].size());
        stream_max_size[1163] = std::max<size_t>(StreamingLineBuffer_37_out0_stream[1].size(), stream_max_size[1163]);
        channel_quantities.push_back(StreamingLineBuffer_37_out0_stream[1].size());
        stream_max_size[1164] = std::max<size_t>(StreamingLineBuffer_37_out0_stream[2].size(), stream_max_size[1164]);
        channel_quantities.push_back(StreamingLineBuffer_37_out0_stream[2].size());
        stream_max_size[1165] = std::max<size_t>(StreamingLineBuffer_37_out0_stream[3].size(), stream_max_size[1165]);
        channel_quantities.push_back(StreamingLineBuffer_37_out0_stream[3].size());
        stream_max_size[1166] = std::max<size_t>(StreamingLineBuffer_37_out0_stream[4].size(), stream_max_size[1166]);
        channel_quantities.push_back(StreamingLineBuffer_37_out0_stream[4].size());
        stream_max_size[1167] = std::max<size_t>(StreamingLineBuffer_37_out0_stream[5].size(), stream_max_size[1167]);
        channel_quantities.push_back(StreamingLineBuffer_37_out0_stream[5].size());
        stream_max_size[1168] = std::max<size_t>(StreamingLineBuffer_37_out0_stream[6].size(), stream_max_size[1168]);
        channel_quantities.push_back(StreamingLineBuffer_37_out0_stream[6].size());
        stream_max_size[1169] = std::max<size_t>(StreamingLineBuffer_37_out0_stream[7].size(), stream_max_size[1169]);
        channel_quantities.push_back(StreamingLineBuffer_37_out0_stream[7].size());
        stream_max_size[1170] = std::max<size_t>(StreamingLineBuffer_37_out0_stream[8].size(), stream_max_size[1170]);
        channel_quantities.push_back(StreamingLineBuffer_37_out0_stream[8].size());
        stream_max_size[1171] = std::max<size_t>(StreamingLineBuffer_37_out0_stream_prepad[0].size(), stream_max_size[1171]);
        channel_quantities.push_back(StreamingLineBuffer_37_out0_stream_prepad[0].size());
        stream_max_size[1172] = std::max<size_t>(StreamingLineBuffer_37_out0_stream_prepad[1].size(), stream_max_size[1172]);
        channel_quantities.push_back(StreamingLineBuffer_37_out0_stream_prepad[1].size());
        stream_max_size[1173] = std::max<size_t>(StreamingLineBuffer_37_out0_stream_prepad[2].size(), stream_max_size[1173]);
        channel_quantities.push_back(StreamingLineBuffer_37_out0_stream_prepad[2].size());
        stream_max_size[1174] = std::max<size_t>(StreamingLineBuffer_37_out0_stream_prepad[3].size(), stream_max_size[1174]);
        channel_quantities.push_back(StreamingLineBuffer_37_out0_stream_prepad[3].size());
        stream_max_size[1175] = std::max<size_t>(StreamingLineBuffer_37_out0_stream_prepad[4].size(), stream_max_size[1175]);
        channel_quantities.push_back(StreamingLineBuffer_37_out0_stream_prepad[4].size());
        stream_max_size[1176] = std::max<size_t>(StreamingLineBuffer_37_out0_stream_prepad[5].size(), stream_max_size[1176]);
        channel_quantities.push_back(StreamingLineBuffer_37_out0_stream_prepad[5].size());
        stream_max_size[1177] = std::max<size_t>(StreamingLineBuffer_37_out0_stream_prepad[6].size(), stream_max_size[1177]);
        channel_quantities.push_back(StreamingLineBuffer_37_out0_stream_prepad[6].size());
        stream_max_size[1178] = std::max<size_t>(StreamingLineBuffer_37_out0_stream_prepad[7].size(), stream_max_size[1178]);
        channel_quantities.push_back(StreamingLineBuffer_37_out0_stream_prepad[7].size());
        stream_max_size[1179] = std::max<size_t>(StreamingLineBuffer_37_out0_stream_prepad[8].size(), stream_max_size[1179]);
        channel_quantities.push_back(StreamingLineBuffer_37_out0_stream_prepad[8].size());
        stream_max_size[1180] = std::max<size_t>(StreamingLineBuffer_37_buffer_stream[0].size(), stream_max_size[1180]);
        channel_quantities.push_back(StreamingLineBuffer_37_buffer_stream[0].size());
        stream_max_size[1181] = std::max<size_t>(StreamingLineBuffer_37_buffer_stream[1].size(), stream_max_size[1181]);
        channel_quantities.push_back(StreamingLineBuffer_37_buffer_stream[1].size());
        stream_max_size[1182] = std::max<size_t>(StreamingLineBuffer_37_buffer_stream[2].size(), stream_max_size[1182]);
        channel_quantities.push_back(StreamingLineBuffer_37_buffer_stream[2].size());
        stream_max_size[1183] = std::max<size_t>(StreamingLineBuffer_37_buffer_stream[3].size(), stream_max_size[1183]);
        channel_quantities.push_back(StreamingLineBuffer_37_buffer_stream[3].size());
        stream_max_size[1184] = std::max<size_t>(StreamingLineBuffer_37_buffer_stream[4].size(), stream_max_size[1184]);
        channel_quantities.push_back(StreamingLineBuffer_37_buffer_stream[4].size());
        stream_max_size[1185] = std::max<size_t>(StreamingLineBuffer_37_buffer_stream[5].size(), stream_max_size[1185]);
        channel_quantities.push_back(StreamingLineBuffer_37_buffer_stream[5].size());
        stream_max_size[1186] = std::max<size_t>(StreamingLineBuffer_37_buffer_stream[6].size(), stream_max_size[1186]);
        channel_quantities.push_back(StreamingLineBuffer_37_buffer_stream[6].size());
        stream_max_size[1187] = std::max<size_t>(StreamingLineBuffer_37_buffer_stream[7].size(), stream_max_size[1187]);
        channel_quantities.push_back(StreamingLineBuffer_37_buffer_stream[7].size());
        stream_max_size[1188] = std::max<size_t>(StreamingDepthwiseConv_14_out0_stream[0].size(), stream_max_size[1188]);
        channel_quantities.push_back(StreamingDepthwiseConv_14_out0_stream[0].size());
        stream_max_size[1189] = std::max<size_t>(BandwidthAdjustIncreaseChannels_24_out0_stream[0].size(), stream_max_size[1189]);
        channel_quantities.push_back(BandwidthAdjustIncreaseChannels_24_out0_stream[0].size());
        stream_max_size[1190] = std::max<size_t>(StreamingConv_29_out0_stream[0].size(), stream_max_size[1190]);
        channel_quantities.push_back(StreamingConv_29_out0_stream[0].size());
        stream_max_size[1191] = std::max<size_t>(StreamingAdd_8_out0_stream[0].size(), stream_max_size[1191]);
        channel_quantities.push_back(StreamingAdd_8_out0_stream[0].size());
        stream_max_size[1192] = std::max<size_t>(BandwidthAdjustIncreaseChannels_25_out0_stream[0].size(), stream_max_size[1192]);
        channel_quantities.push_back(BandwidthAdjustIncreaseChannels_25_out0_stream[0].size());
        stream_max_size[1193] = std::max<size_t>(TensorDuplicator_9_out0_stream[0].size(), stream_max_size[1193]);
        channel_quantities.push_back(TensorDuplicator_9_out0_stream[0].size());
        stream_max_size[1194] = std::max<size_t>(TensorDuplicator_9_out1_stream[0].size(), stream_max_size[1194]);
        channel_quantities.push_back(TensorDuplicator_9_out1_stream[0].size());
        stream_max_size[1195] = std::max<size_t>(BandwidthAdjustIncreaseChannels_26_out0_stream[0].size(), stream_max_size[1195]);
        channel_quantities.push_back(BandwidthAdjustIncreaseChannels_26_out0_stream[0].size());
        stream_max_size[1196] = std::max<size_t>(BandwidthAdjustDecreaseChannels_21_out0_stream[0].size(), stream_max_size[1196]);
        channel_quantities.push_back(BandwidthAdjustDecreaseChannels_21_out0_stream[0].size());
        stream_max_size[1197] = std::max<size_t>(StreamingConv_30_out0_stream[0].size(), stream_max_size[1197]);
        channel_quantities.push_back(StreamingConv_30_out0_stream[0].size());
        stream_max_size[1198] = std::max<size_t>(BandwidthAdjustDecreaseChannels_22_out0_stream[0].size(), stream_max_size[1198]);
        channel_quantities.push_back(BandwidthAdjustDecreaseChannels_22_out0_stream[0].size());
        stream_max_size[1199] = std::max<size_t>(StreamingLineBuffer_38_out0_stream[0].size(), stream_max_size[1199]);
        channel_quantities.push_back(StreamingLineBuffer_38_out0_stream[0].size());
        stream_max_size[1200] = std::max<size_t>(StreamingLineBuffer_38_out0_stream[1].size(), stream_max_size[1200]);
        channel_quantities.push_back(StreamingLineBuffer_38_out0_stream[1].size());
        stream_max_size[1201] = std::max<size_t>(StreamingLineBuffer_38_out0_stream[2].size(), stream_max_size[1201]);
        channel_quantities.push_back(StreamingLineBuffer_38_out0_stream[2].size());
        stream_max_size[1202] = std::max<size_t>(StreamingLineBuffer_38_out0_stream[3].size(), stream_max_size[1202]);
        channel_quantities.push_back(StreamingLineBuffer_38_out0_stream[3].size());
        stream_max_size[1203] = std::max<size_t>(StreamingLineBuffer_38_out0_stream[4].size(), stream_max_size[1203]);
        channel_quantities.push_back(StreamingLineBuffer_38_out0_stream[4].size());
        stream_max_size[1204] = std::max<size_t>(StreamingLineBuffer_38_out0_stream[5].size(), stream_max_size[1204]);
        channel_quantities.push_back(StreamingLineBuffer_38_out0_stream[5].size());
        stream_max_size[1205] = std::max<size_t>(StreamingLineBuffer_38_out0_stream[6].size(), stream_max_size[1205]);
        channel_quantities.push_back(StreamingLineBuffer_38_out0_stream[6].size());
        stream_max_size[1206] = std::max<size_t>(StreamingLineBuffer_38_out0_stream[7].size(), stream_max_size[1206]);
        channel_quantities.push_back(StreamingLineBuffer_38_out0_stream[7].size());
        stream_max_size[1207] = std::max<size_t>(StreamingLineBuffer_38_out0_stream[8].size(), stream_max_size[1207]);
        channel_quantities.push_back(StreamingLineBuffer_38_out0_stream[8].size());
        stream_max_size[1208] = std::max<size_t>(StreamingLineBuffer_38_out0_stream_prepad[0].size(), stream_max_size[1208]);
        channel_quantities.push_back(StreamingLineBuffer_38_out0_stream_prepad[0].size());
        stream_max_size[1209] = std::max<size_t>(StreamingLineBuffer_38_out0_stream_prepad[1].size(), stream_max_size[1209]);
        channel_quantities.push_back(StreamingLineBuffer_38_out0_stream_prepad[1].size());
        stream_max_size[1210] = std::max<size_t>(StreamingLineBuffer_38_out0_stream_prepad[2].size(), stream_max_size[1210]);
        channel_quantities.push_back(StreamingLineBuffer_38_out0_stream_prepad[2].size());
        stream_max_size[1211] = std::max<size_t>(StreamingLineBuffer_38_out0_stream_prepad[3].size(), stream_max_size[1211]);
        channel_quantities.push_back(StreamingLineBuffer_38_out0_stream_prepad[3].size());
        stream_max_size[1212] = std::max<size_t>(StreamingLineBuffer_38_out0_stream_prepad[4].size(), stream_max_size[1212]);
        channel_quantities.push_back(StreamingLineBuffer_38_out0_stream_prepad[4].size());
        stream_max_size[1213] = std::max<size_t>(StreamingLineBuffer_38_out0_stream_prepad[5].size(), stream_max_size[1213]);
        channel_quantities.push_back(StreamingLineBuffer_38_out0_stream_prepad[5].size());
        stream_max_size[1214] = std::max<size_t>(StreamingLineBuffer_38_out0_stream_prepad[6].size(), stream_max_size[1214]);
        channel_quantities.push_back(StreamingLineBuffer_38_out0_stream_prepad[6].size());
        stream_max_size[1215] = std::max<size_t>(StreamingLineBuffer_38_out0_stream_prepad[7].size(), stream_max_size[1215]);
        channel_quantities.push_back(StreamingLineBuffer_38_out0_stream_prepad[7].size());
        stream_max_size[1216] = std::max<size_t>(StreamingLineBuffer_38_out0_stream_prepad[8].size(), stream_max_size[1216]);
        channel_quantities.push_back(StreamingLineBuffer_38_out0_stream_prepad[8].size());
        stream_max_size[1217] = std::max<size_t>(StreamingLineBuffer_38_buffer_stream[0].size(), stream_max_size[1217]);
        channel_quantities.push_back(StreamingLineBuffer_38_buffer_stream[0].size());
        stream_max_size[1218] = std::max<size_t>(StreamingLineBuffer_38_buffer_stream[1].size(), stream_max_size[1218]);
        channel_quantities.push_back(StreamingLineBuffer_38_buffer_stream[1].size());
        stream_max_size[1219] = std::max<size_t>(StreamingLineBuffer_38_buffer_stream[2].size(), stream_max_size[1219]);
        channel_quantities.push_back(StreamingLineBuffer_38_buffer_stream[2].size());
        stream_max_size[1220] = std::max<size_t>(StreamingLineBuffer_38_buffer_stream[3].size(), stream_max_size[1220]);
        channel_quantities.push_back(StreamingLineBuffer_38_buffer_stream[3].size());
        stream_max_size[1221] = std::max<size_t>(StreamingLineBuffer_38_buffer_stream[4].size(), stream_max_size[1221]);
        channel_quantities.push_back(StreamingLineBuffer_38_buffer_stream[4].size());
        stream_max_size[1222] = std::max<size_t>(StreamingLineBuffer_38_buffer_stream[5].size(), stream_max_size[1222]);
        channel_quantities.push_back(StreamingLineBuffer_38_buffer_stream[5].size());
        stream_max_size[1223] = std::max<size_t>(StreamingLineBuffer_38_buffer_stream[6].size(), stream_max_size[1223]);
        channel_quantities.push_back(StreamingLineBuffer_38_buffer_stream[6].size());
        stream_max_size[1224] = std::max<size_t>(StreamingLineBuffer_38_buffer_stream[7].size(), stream_max_size[1224]);
        channel_quantities.push_back(StreamingLineBuffer_38_buffer_stream[7].size());
        stream_max_size[1225] = std::max<size_t>(StreamingDepthwiseConv_15_out0_stream[0].size(), stream_max_size[1225]);
        channel_quantities.push_back(StreamingDepthwiseConv_15_out0_stream[0].size());
        stream_max_size[1226] = std::max<size_t>(BandwidthAdjustIncreaseChannels_27_out0_stream[0].size(), stream_max_size[1226]);
        channel_quantities.push_back(BandwidthAdjustIncreaseChannels_27_out0_stream[0].size());
        stream_max_size[1227] = std::max<size_t>(StreamingConv_31_out0_stream[0].size(), stream_max_size[1227]);
        channel_quantities.push_back(StreamingConv_31_out0_stream[0].size());
        stream_max_size[1228] = std::max<size_t>(StreamingAdd_9_out0_stream[0].size(), stream_max_size[1228]);
        channel_quantities.push_back(StreamingAdd_9_out0_stream[0].size());
        stream_max_size[1229] = std::max<size_t>(BandwidthAdjustIncreaseChannels_28_out0_stream[0].size(), stream_max_size[1229]);
        channel_quantities.push_back(BandwidthAdjustIncreaseChannels_28_out0_stream[0].size());
        stream_max_size[1230] = std::max<size_t>(StreamingConv_32_out0_stream[0].size(), stream_max_size[1230]);
        channel_quantities.push_back(StreamingConv_32_out0_stream[0].size());
        stream_max_size[1231] = std::max<size_t>(BandwidthAdjustDecreaseChannels_23_out0_stream[0].size(), stream_max_size[1231]);
        channel_quantities.push_back(BandwidthAdjustDecreaseChannels_23_out0_stream[0].size());
        stream_max_size[1232] = std::max<size_t>(StreamingLineBuffer_39_out0_stream[0].size(), stream_max_size[1232]);
        channel_quantities.push_back(StreamingLineBuffer_39_out0_stream[0].size());
        stream_max_size[1233] = std::max<size_t>(StreamingLineBuffer_39_out0_stream[1].size(), stream_max_size[1233]);
        channel_quantities.push_back(StreamingLineBuffer_39_out0_stream[1].size());
        stream_max_size[1234] = std::max<size_t>(StreamingLineBuffer_39_out0_stream[2].size(), stream_max_size[1234]);
        channel_quantities.push_back(StreamingLineBuffer_39_out0_stream[2].size());
        stream_max_size[1235] = std::max<size_t>(StreamingLineBuffer_39_out0_stream[3].size(), stream_max_size[1235]);
        channel_quantities.push_back(StreamingLineBuffer_39_out0_stream[3].size());
        stream_max_size[1236] = std::max<size_t>(StreamingLineBuffer_39_out0_stream[4].size(), stream_max_size[1236]);
        channel_quantities.push_back(StreamingLineBuffer_39_out0_stream[4].size());
        stream_max_size[1237] = std::max<size_t>(StreamingLineBuffer_39_out0_stream[5].size(), stream_max_size[1237]);
        channel_quantities.push_back(StreamingLineBuffer_39_out0_stream[5].size());
        stream_max_size[1238] = std::max<size_t>(StreamingLineBuffer_39_out0_stream[6].size(), stream_max_size[1238]);
        channel_quantities.push_back(StreamingLineBuffer_39_out0_stream[6].size());
        stream_max_size[1239] = std::max<size_t>(StreamingLineBuffer_39_out0_stream[7].size(), stream_max_size[1239]);
        channel_quantities.push_back(StreamingLineBuffer_39_out0_stream[7].size());
        stream_max_size[1240] = std::max<size_t>(StreamingLineBuffer_39_out0_stream[8].size(), stream_max_size[1240]);
        channel_quantities.push_back(StreamingLineBuffer_39_out0_stream[8].size());
        stream_max_size[1241] = std::max<size_t>(StreamingLineBuffer_39_out0_stream_prepad[0].size(), stream_max_size[1241]);
        channel_quantities.push_back(StreamingLineBuffer_39_out0_stream_prepad[0].size());
        stream_max_size[1242] = std::max<size_t>(StreamingLineBuffer_39_out0_stream_prepad[1].size(), stream_max_size[1242]);
        channel_quantities.push_back(StreamingLineBuffer_39_out0_stream_prepad[1].size());
        stream_max_size[1243] = std::max<size_t>(StreamingLineBuffer_39_out0_stream_prepad[2].size(), stream_max_size[1243]);
        channel_quantities.push_back(StreamingLineBuffer_39_out0_stream_prepad[2].size());
        stream_max_size[1244] = std::max<size_t>(StreamingLineBuffer_39_out0_stream_prepad[3].size(), stream_max_size[1244]);
        channel_quantities.push_back(StreamingLineBuffer_39_out0_stream_prepad[3].size());
        stream_max_size[1245] = std::max<size_t>(StreamingLineBuffer_39_out0_stream_prepad[4].size(), stream_max_size[1245]);
        channel_quantities.push_back(StreamingLineBuffer_39_out0_stream_prepad[4].size());
        stream_max_size[1246] = std::max<size_t>(StreamingLineBuffer_39_out0_stream_prepad[5].size(), stream_max_size[1246]);
        channel_quantities.push_back(StreamingLineBuffer_39_out0_stream_prepad[5].size());
        stream_max_size[1247] = std::max<size_t>(StreamingLineBuffer_39_out0_stream_prepad[6].size(), stream_max_size[1247]);
        channel_quantities.push_back(StreamingLineBuffer_39_out0_stream_prepad[6].size());
        stream_max_size[1248] = std::max<size_t>(StreamingLineBuffer_39_out0_stream_prepad[7].size(), stream_max_size[1248]);
        channel_quantities.push_back(StreamingLineBuffer_39_out0_stream_prepad[7].size());
        stream_max_size[1249] = std::max<size_t>(StreamingLineBuffer_39_out0_stream_prepad[8].size(), stream_max_size[1249]);
        channel_quantities.push_back(StreamingLineBuffer_39_out0_stream_prepad[8].size());
        stream_max_size[1250] = std::max<size_t>(StreamingLineBuffer_39_buffer_stream[0].size(), stream_max_size[1250]);
        channel_quantities.push_back(StreamingLineBuffer_39_buffer_stream[0].size());
        stream_max_size[1251] = std::max<size_t>(StreamingLineBuffer_39_buffer_stream[1].size(), stream_max_size[1251]);
        channel_quantities.push_back(StreamingLineBuffer_39_buffer_stream[1].size());
        stream_max_size[1252] = std::max<size_t>(StreamingLineBuffer_39_buffer_stream[2].size(), stream_max_size[1252]);
        channel_quantities.push_back(StreamingLineBuffer_39_buffer_stream[2].size());
        stream_max_size[1253] = std::max<size_t>(StreamingLineBuffer_39_buffer_stream[3].size(), stream_max_size[1253]);
        channel_quantities.push_back(StreamingLineBuffer_39_buffer_stream[3].size());
        stream_max_size[1254] = std::max<size_t>(StreamingLineBuffer_39_buffer_stream[4].size(), stream_max_size[1254]);
        channel_quantities.push_back(StreamingLineBuffer_39_buffer_stream[4].size());
        stream_max_size[1255] = std::max<size_t>(StreamingLineBuffer_39_buffer_stream[5].size(), stream_max_size[1255]);
        channel_quantities.push_back(StreamingLineBuffer_39_buffer_stream[5].size());
        stream_max_size[1256] = std::max<size_t>(StreamingLineBuffer_39_buffer_stream[6].size(), stream_max_size[1256]);
        channel_quantities.push_back(StreamingLineBuffer_39_buffer_stream[6].size());
        stream_max_size[1257] = std::max<size_t>(StreamingLineBuffer_39_buffer_stream[7].size(), stream_max_size[1257]);
        channel_quantities.push_back(StreamingLineBuffer_39_buffer_stream[7].size());
        stream_max_size[1258] = std::max<size_t>(StreamingDepthwiseConv_16_out0_stream[0].size(), stream_max_size[1258]);
        channel_quantities.push_back(StreamingDepthwiseConv_16_out0_stream[0].size());
        stream_max_size[1259] = std::max<size_t>(BandwidthAdjustIncreaseChannels_29_out0_stream[0].size(), stream_max_size[1259]);
        channel_quantities.push_back(BandwidthAdjustIncreaseChannels_29_out0_stream[0].size());
        stream_max_size[1260] = std::max<size_t>(StreamingConv_33_out0_stream[0].size(), stream_max_size[1260]);
        channel_quantities.push_back(StreamingConv_33_out0_stream[0].size());
        stream_max_size[1261] = std::max<size_t>(BandwidthAdjustIncreaseChannels_30_out0_stream[0].size(), stream_max_size[1261]);
        channel_quantities.push_back(BandwidthAdjustIncreaseChannels_30_out0_stream[0].size());
        stream_max_size[1262] = std::max<size_t>(StreamingConv_34_out0_stream[0].size(), stream_max_size[1262]);
        channel_quantities.push_back(StreamingConv_34_out0_stream[0].size());
        stream_max_size[1263] = std::max<size_t>(BandwidthAdjustDecreaseChannels_24_out0_stream[0].size(), stream_max_size[1263]);
        channel_quantities.push_back(BandwidthAdjustDecreaseChannels_24_out0_stream[0].size());
        stream_max_size[1264] = std::max<size_t>(StreamingGlobalAveragePool_0_out0_stream[0].size(), stream_max_size[1264]);
        channel_quantities.push_back(StreamingGlobalAveragePool_0_out0_stream[0].size());
        stream_max_size[1265] = std::max<size_t>(BandwidthAdjustIncreaseChannels_31_out0_stream[0].size(), stream_max_size[1265]);
        channel_quantities.push_back(BandwidthAdjustIncreaseChannels_31_out0_stream[0].size());
        stream_max_size[1266] = std::max<size_t>(StreamingConv_35_out0_stream[0].size(), stream_max_size[1266]);
        channel_quantities.push_back(StreamingConv_35_out0_stream[0].size());
        channel_quantities.push_back(global_out.size());
        channel_quantities.push_back(global_in.size());
        channel_quantities.push_back(global_in_1.size());
        current_state = CSDFGState(actor_statuses, channel_quantities);
        CompactState compact = make_compact_state(current_state);
        StateSig sig = make_signature(compact);
        auto &bucket = visited_states[sig];
        for (const auto &ref : bucket) {
            if (states_equal_on_disk(ref.offset, compact.data)) {
                actual_II = clock_cycle - ref.clock;
                goto done_simulation;
            }
        }
        uint64_t offset = append_state_to_file(compact.data);
        bucket.push_back(StateRef{offset, static_cast<uint32_t>(clock_cycle)});
        clock_cycle++;
        if (clock_cycle > 2007040) {
            std::cout << "Warning: Exceeded maximum clock cycles. The model might be deadlocked." << std::endl;
            actual_II = 0;
            break;
        }
        if (clock_cycle % 100000 == 0) {
            std::cout << "Current clock cycle: " << clock_cycle << std::endl;
        }
    };
    done_simulation:
    auto end_time = std::chrono::high_resolution_clock::now();
    auto duration = std::chrono::duration_cast<std::chrono::milliseconds>(end_time - start_time).count();
    const char *fifo_depth_json = std::getenv("STE_FIFO_DEPTH_JSON");
    std::ofstream report_file(fifo_depth_json ? fifo_depth_json : "fifo_depth.json");
    report_file << "{\n";
    report_file << "	\"fifo_depth\": {\n";
    report_file << "		\"NHWCToStream_0_out0_stream_0_\": " << stream_max_size[0] << ",\n";
    report_file << "		\"NHWCToStream_0_out0_stream_1_\": " << stream_max_size[1] << ",\n";
    report_file << "		\"NHWCToStream_1_out0_stream_0_\": " << stream_max_size[2] << ",\n";
    report_file << "		\"StreamingLineBuffer_0_out0_stream_0_\": " << stream_max_size[3] << ",\n";
    report_file << "		\"StreamingLineBuffer_0_out0_stream_1_\": " << stream_max_size[4] << ",\n";
    report_file << "		\"StreamingLineBuffer_0_out0_stream_2_\": " << stream_max_size[5] << ",\n";
    report_file << "		\"StreamingLineBuffer_0_out0_stream_3_\": " << stream_max_size[6] << ",\n";
    report_file << "		\"StreamingLineBuffer_0_out0_stream_4_\": " << stream_max_size[7] << ",\n";
    report_file << "		\"StreamingLineBuffer_0_out0_stream_5_\": " << stream_max_size[8] << ",\n";
    report_file << "		\"StreamingLineBuffer_0_out0_stream_6_\": " << stream_max_size[9] << ",\n";
    report_file << "		\"StreamingLineBuffer_0_out0_stream_7_\": " << stream_max_size[10] << ",\n";
    report_file << "		\"StreamingLineBuffer_0_out0_stream_8_\": " << stream_max_size[11] << ",\n";
    report_file << "		\"StreamingLineBuffer_0_out0_stream_9_\": " << stream_max_size[12] << ",\n";
    report_file << "		\"StreamingLineBuffer_0_out0_stream_10_\": " << stream_max_size[13] << ",\n";
    report_file << "		\"StreamingLineBuffer_0_out0_stream_11_\": " << stream_max_size[14] << ",\n";
    report_file << "		\"StreamingLineBuffer_0_out0_stream_12_\": " << stream_max_size[15] << ",\n";
    report_file << "		\"StreamingLineBuffer_0_out0_stream_13_\": " << stream_max_size[16] << ",\n";
    report_file << "		\"StreamingLineBuffer_0_out0_stream_14_\": " << stream_max_size[17] << ",\n";
    report_file << "		\"StreamingLineBuffer_0_out0_stream_prepad_0_\": " << stream_max_size[18] << ",\n";
    report_file << "		\"StreamingLineBuffer_0_out0_stream_prepad_1_\": " << stream_max_size[19] << ",\n";
    report_file << "		\"StreamingLineBuffer_0_out0_stream_prepad_2_\": " << stream_max_size[20] << ",\n";
    report_file << "		\"StreamingLineBuffer_0_out0_stream_prepad_3_\": " << stream_max_size[21] << ",\n";
    report_file << "		\"StreamingLineBuffer_0_out0_stream_prepad_4_\": " << stream_max_size[22] << ",\n";
    report_file << "		\"StreamingLineBuffer_0_out0_stream_prepad_5_\": " << stream_max_size[23] << ",\n";
    report_file << "		\"StreamingLineBuffer_0_out0_stream_prepad_6_\": " << stream_max_size[24] << ",\n";
    report_file << "		\"StreamingLineBuffer_0_out0_stream_prepad_7_\": " << stream_max_size[25] << ",\n";
    report_file << "		\"StreamingLineBuffer_0_out0_stream_prepad_8_\": " << stream_max_size[26] << ",\n";
    report_file << "		\"StreamingLineBuffer_0_out0_stream_prepad_9_\": " << stream_max_size[27] << ",\n";
    report_file << "		\"StreamingLineBuffer_0_out0_stream_prepad_10_\": " << stream_max_size[28] << ",\n";
    report_file << "		\"StreamingLineBuffer_0_out0_stream_prepad_11_\": " << stream_max_size[29] << ",\n";
    report_file << "		\"StreamingLineBuffer_0_out0_stream_prepad_12_\": " << stream_max_size[30] << ",\n";
    report_file << "		\"StreamingLineBuffer_0_out0_stream_prepad_13_\": " << stream_max_size[31] << ",\n";
    report_file << "		\"StreamingLineBuffer_0_out0_stream_prepad_14_\": " << stream_max_size[32] << ",\n";
    report_file << "		\"StreamingLineBuffer_0_buffer_stream_0_\": " << stream_max_size[33] << ",\n";
    report_file << "		\"StreamingLineBuffer_0_buffer_stream_1_\": " << stream_max_size[34] << ",\n";
    report_file << "		\"StreamingLineBuffer_0_buffer_stream_2_\": " << stream_max_size[35] << ",\n";
    report_file << "		\"StreamingLineBuffer_0_buffer_stream_3_\": " << stream_max_size[36] << ",\n";
    report_file << "		\"StreamingLineBuffer_0_buffer_stream_4_\": " << stream_max_size[37] << ",\n";
    report_file << "		\"StreamingLineBuffer_0_buffer_stream_5_\": " << stream_max_size[38] << ",\n";
    report_file << "		\"StreamingLineBuffer_0_buffer_stream_6_\": " << stream_max_size[39] << ",\n";
    report_file << "		\"StreamingLineBuffer_0_buffer_stream_7_\": " << stream_max_size[40] << ",\n";
    report_file << "		\"StreamingLineBuffer_0_buffer_stream_8_\": " << stream_max_size[41] << ",\n";
    report_file << "		\"StreamingLineBuffer_0_buffer_stream_9_\": " << stream_max_size[42] << ",\n";
    report_file << "		\"StreamingLineBuffer_0_buffer_stream_10_\": " << stream_max_size[43] << ",\n";
    report_file << "		\"StreamingLineBuffer_0_buffer_stream_11_\": " << stream_max_size[44] << ",\n";
    report_file << "		\"StreamingLineBuffer_0_buffer_stream_12_\": " << stream_max_size[45] << ",\n";
    report_file << "		\"StreamingMemory_0_out0_stream_0_\": " << stream_max_size[46] << ",\n";
    report_file << "		\"StreamingMemory_0_out0_stream_1_\": " << stream_max_size[47] << ",\n";
    report_file << "		\"StreamingMemory_0_out0_stream_2_\": " << stream_max_size[48] << ",\n";
    report_file << "		\"StreamingMemory_0_out0_stream_3_\": " << stream_max_size[49] << ",\n";
    report_file << "		\"StreamingMemory_0_out0_stream_4_\": " << stream_max_size[50] << ",\n";
    report_file << "		\"StreamingMemory_0_out0_stream_5_\": " << stream_max_size[51] << ",\n";
    report_file << "		\"StreamingMemory_0_out0_stream_6_\": " << stream_max_size[52] << ",\n";
    report_file << "		\"StreamingMemory_0_out0_stream_7_\": " << stream_max_size[53] << ",\n";
    report_file << "		\"StreamingMemory_0_out0_stream_8_\": " << stream_max_size[54] << ",\n";
    report_file << "		\"StreamingMemory_0_out1_stream_0_\": " << stream_max_size[55] << ",\n";
    report_file << "		\"StreamingMemory_1_out0_stream_0_\": " << stream_max_size[56] << ",\n";
    report_file << "		\"StreamingMemory_1_out1_stream_0_\": " << stream_max_size[57] << ",\n";
    report_file << "		\"StreamingConv_0_out0_stream_0_\": " << stream_max_size[58] << ",\n";
    report_file << "		\"StreamingConv_0_out0_stream_1_\": " << stream_max_size[59] << ",\n";
    report_file << "		\"StreamingMemory_2_out0_stream_0_\": " << stream_max_size[60] << ",\n";
    report_file << "		\"StreamingMemory_2_out0_stream_1_\": " << stream_max_size[61] << ",\n";
    report_file << "		\"StreamingMemory_2_out0_stream_2_\": " << stream_max_size[62] << ",\n";
    report_file << "		\"StreamingMemory_2_out0_stream_3_\": " << stream_max_size[63] << ",\n";
    report_file << "		\"StreamingMemory_2_out0_stream_4_\": " << stream_max_size[64] << ",\n";
    report_file << "		\"StreamingMemory_2_out0_stream_5_\": " << stream_max_size[65] << ",\n";
    report_file << "		\"StreamingMemory_2_out0_stream_6_\": " << stream_max_size[66] << ",\n";
    report_file << "		\"StreamingMemory_2_out0_stream_7_\": " << stream_max_size[67] << ",\n";
    report_file << "		\"StreamingMemory_2_out0_stream_8_\": " << stream_max_size[68] << ",\n";
    report_file << "		\"StreamingMemory_2_out1_stream_0_\": " << stream_max_size[69] << ",\n";
    report_file << "		\"StreamingLineBuffer_1_out0_stream_0_\": " << stream_max_size[70] << ",\n";
    report_file << "		\"StreamingLineBuffer_1_out0_stream_1_\": " << stream_max_size[71] << ",\n";
    report_file << "		\"StreamingLineBuffer_1_out0_stream_2_\": " << stream_max_size[72] << ",\n";
    report_file << "		\"StreamingLineBuffer_1_out0_stream_3_\": " << stream_max_size[73] << ",\n";
    report_file << "		\"StreamingLineBuffer_1_out0_stream_4_\": " << stream_max_size[74] << ",\n";
    report_file << "		\"StreamingLineBuffer_1_out0_stream_5_\": " << stream_max_size[75] << ",\n";
    report_file << "		\"StreamingLineBuffer_1_out0_stream_6_\": " << stream_max_size[76] << ",\n";
    report_file << "		\"StreamingLineBuffer_1_out0_stream_7_\": " << stream_max_size[77] << ",\n";
    report_file << "		\"StreamingLineBuffer_1_out0_stream_8_\": " << stream_max_size[78] << ",\n";
    report_file << "		\"StreamingLineBuffer_1_out0_stream_9_\": " << stream_max_size[79] << ",\n";
    report_file << "		\"StreamingLineBuffer_1_out0_stream_10_\": " << stream_max_size[80] << ",\n";
    report_file << "		\"StreamingLineBuffer_1_out0_stream_11_\": " << stream_max_size[81] << ",\n";
    report_file << "		\"StreamingLineBuffer_1_out0_stream_prepad_0_\": " << stream_max_size[82] << ",\n";
    report_file << "		\"StreamingLineBuffer_1_out0_stream_prepad_1_\": " << stream_max_size[83] << ",\n";
    report_file << "		\"StreamingLineBuffer_1_out0_stream_prepad_2_\": " << stream_max_size[84] << ",\n";
    report_file << "		\"StreamingLineBuffer_1_out0_stream_prepad_3_\": " << stream_max_size[85] << ",\n";
    report_file << "		\"StreamingLineBuffer_1_out0_stream_prepad_4_\": " << stream_max_size[86] << ",\n";
    report_file << "		\"StreamingLineBuffer_1_out0_stream_prepad_5_\": " << stream_max_size[87] << ",\n";
    report_file << "		\"StreamingLineBuffer_1_out0_stream_prepad_6_\": " << stream_max_size[88] << ",\n";
    report_file << "		\"StreamingLineBuffer_1_out0_stream_prepad_7_\": " << stream_max_size[89] << ",\n";
    report_file << "		\"StreamingLineBuffer_1_out0_stream_prepad_8_\": " << stream_max_size[90] << ",\n";
    report_file << "		\"StreamingLineBuffer_1_out0_stream_prepad_9_\": " << stream_max_size[91] << ",\n";
    report_file << "		\"StreamingLineBuffer_1_out0_stream_prepad_10_\": " << stream_max_size[92] << ",\n";
    report_file << "		\"StreamingLineBuffer_1_out0_stream_prepad_11_\": " << stream_max_size[93] << ",\n";
    report_file << "		\"StreamingLineBuffer_1_buffer_stream_0_\": " << stream_max_size[94] << ",\n";
    report_file << "		\"StreamingLineBuffer_1_buffer_stream_1_\": " << stream_max_size[95] << ",\n";
    report_file << "		\"StreamingLineBuffer_1_buffer_stream_2_\": " << stream_max_size[96] << ",\n";
    report_file << "		\"StreamingLineBuffer_1_buffer_stream_3_\": " << stream_max_size[97] << ",\n";
    report_file << "		\"StreamingLineBuffer_1_buffer_stream_4_\": " << stream_max_size[98] << ",\n";
    report_file << "		\"StreamingLineBuffer_1_buffer_stream_5_\": " << stream_max_size[99] << ",\n";
    report_file << "		\"StreamingLineBuffer_1_buffer_stream_6_\": " << stream_max_size[100] << ",\n";
    report_file << "		\"StreamingLineBuffer_1_buffer_stream_7_\": " << stream_max_size[101] << ",\n";
    report_file << "		\"StreamingLineBuffer_1_buffer_stream_8_\": " << stream_max_size[102] << ",\n";
    report_file << "		\"StreamingLineBuffer_1_buffer_stream_9_\": " << stream_max_size[103] << ",\n";
    report_file << "		\"StreamingMemory_3_out0_stream_0_\": " << stream_max_size[104] << ",\n";
    report_file << "		\"StreamingMemory_3_out1_stream_0_\": " << stream_max_size[105] << ",\n";
    report_file << "		\"StreamingDepthwiseConv_0_out0_stream_0_\": " << stream_max_size[106] << ",\n";
    report_file << "		\"StreamingDepthwiseConv_0_out0_stream_1_\": " << stream_max_size[107] << ",\n";
    report_file << "		\"StreamingMemory_4_out0_stream_0_\": " << stream_max_size[108] << ",\n";
    report_file << "		\"StreamingMemory_4_out1_stream_0_\": " << stream_max_size[109] << ",\n";
    report_file << "		\"BandwidthAdjustIncreaseChannels_0_out0_stream_0_\": " << stream_max_size[110] << ",\n";
    report_file << "		\"BandwidthAdjustIncreaseChannels_0_out0_stream_1_\": " << stream_max_size[111] << ",\n";
    report_file << "		\"StreamingMemory_5_out0_stream_0_\": " << stream_max_size[112] << ",\n";
    report_file << "		\"StreamingMemory_5_out1_stream_0_\": " << stream_max_size[113] << ",\n";
    report_file << "		\"StreamingLineBuffer_2_out0_stream_0_\": " << stream_max_size[114] << ",\n";
    report_file << "		\"StreamingLineBuffer_2_out0_stream_1_\": " << stream_max_size[115] << ",\n";
    report_file << "		\"StreamingMemory_6_out0_stream_0_\": " << stream_max_size[116] << ",\n";
    report_file << "		\"StreamingMemory_6_out1_stream_0_\": " << stream_max_size[117] << ",\n";
    report_file << "		\"StreamingConv_1_out0_stream_0_\": " << stream_max_size[118] << ",\n";
    report_file << "		\"StreamingConv_1_out0_stream_1_\": " << stream_max_size[119] << ",\n";
    report_file << "		\"StreamingMemory_7_out0_stream_0_\": " << stream_max_size[120] << ",\n";
    report_file << "		\"StreamingMemory_7_out1_stream_0_\": " << stream_max_size[121] << ",\n";
    report_file << "		\"BandwidthAdjustIncreaseChannels_1_out0_stream_0_\": " << stream_max_size[122] << ",\n";
    report_file << "		\"BandwidthAdjustIncreaseChannels_1_out0_stream_1_\": " << stream_max_size[123] << ",\n";
    report_file << "		\"StreamingMemory_8_out0_stream_0_\": " << stream_max_size[124] << ",\n";
    report_file << "		\"StreamingMemory_8_out0_stream_1_\": " << stream_max_size[125] << ",\n";
    report_file << "		\"StreamingMemory_8_out0_stream_2_\": " << stream_max_size[126] << ",\n";
    report_file << "		\"StreamingMemory_8_out0_stream_3_\": " << stream_max_size[127] << ",\n";
    report_file << "		\"StreamingMemory_8_out0_stream_4_\": " << stream_max_size[128] << ",\n";
    report_file << "		\"StreamingMemory_8_out0_stream_5_\": " << stream_max_size[129] << ",\n";
    report_file << "		\"StreamingMemory_8_out0_stream_6_\": " << stream_max_size[130] << ",\n";
    report_file << "		\"StreamingMemory_8_out0_stream_7_\": " << stream_max_size[131] << ",\n";
    report_file << "		\"StreamingMemory_8_out0_stream_8_\": " << stream_max_size[132] << ",\n";
    report_file << "		\"StreamingMemory_8_out1_stream_0_\": " << stream_max_size[133] << ",\n";
    report_file << "		\"StreamingLineBuffer_3_out0_stream_0_\": " << stream_max_size[134] << ",\n";
    report_file << "		\"StreamingLineBuffer_3_out0_stream_1_\": " << stream_max_size[135] << ",\n";
    report_file << "		\"StreamingMemory_9_out0_stream_0_\": " << stream_max_size[136] << ",\n";
    report_file << "		\"StreamingMemory_9_out1_stream_0_\": " << stream_max_size[137] << ",\n";
    report_file << "		\"StreamingConv_2_out0_stream_0_\": " << stream_max_size[138] << ",\n";
    report_file << "		\"StreamingConv_2_out0_stream_1_\": " << stream_max_size[139] << ",\n";
    report_file << "		\"StreamingMemory_10_out0_stream_0_\": " << stream_max_size[140] << ",\n";
    report_file << "		\"StreamingMemory_10_out1_stream_0_\": " << stream_max_size[141] << ",\n";
    report_file << "		\"StreamingLineBuffer_4_out0_stream_0_\": " << stream_max_size[142] << ",\n";
    report_file << "		\"StreamingLineBuffer_4_out0_stream_1_\": " << stream_max_size[143] << ",\n";
    report_file << "		\"StreamingLineBuffer_4_out0_stream_2_\": " << stream_max_size[144] << ",\n";
    report_file << "		\"StreamingLineBuffer_4_out0_stream_3_\": " << stream_max_size[145] << ",\n";
    report_file << "		\"StreamingLineBuffer_4_out0_stream_4_\": " << stream_max_size[146] << ",\n";
    report_file << "		\"StreamingLineBuffer_4_out0_stream_5_\": " << stream_max_size[147] << ",\n";
    report_file << "		\"StreamingLineBuffer_4_out0_stream_6_\": " << stream_max_size[148] << ",\n";
    report_file << "		\"StreamingLineBuffer_4_out0_stream_7_\": " << stream_max_size[149] << ",\n";
    report_file << "		\"StreamingLineBuffer_4_out0_stream_8_\": " << stream_max_size[150] << ",\n";
    report_file << "		\"StreamingLineBuffer_4_out0_stream_9_\": " << stream_max_size[151] << ",\n";
    report_file << "		\"StreamingLineBuffer_4_out0_stream_10_\": " << stream_max_size[152] << ",\n";
    report_file << "		\"StreamingLineBuffer_4_out0_stream_11_\": " << stream_max_size[153] << ",\n";
    report_file << "		\"StreamingLineBuffer_4_out0_stream_12_\": " << stream_max_size[154] << ",\n";
    report_file << "		\"StreamingLineBuffer_4_out0_stream_13_\": " << stream_max_size[155] << ",\n";
    report_file << "		\"StreamingLineBuffer_4_out0_stream_14_\": " << stream_max_size[156] << ",\n";
    report_file << "		\"StreamingLineBuffer_4_out0_stream_prepad_0_\": " << stream_max_size[157] << ",\n";
    report_file << "		\"StreamingLineBuffer_4_out0_stream_prepad_1_\": " << stream_max_size[158] << ",\n";
    report_file << "		\"StreamingLineBuffer_4_out0_stream_prepad_2_\": " << stream_max_size[159] << ",\n";
    report_file << "		\"StreamingLineBuffer_4_out0_stream_prepad_3_\": " << stream_max_size[160] << ",\n";
    report_file << "		\"StreamingLineBuffer_4_out0_stream_prepad_4_\": " << stream_max_size[161] << ",\n";
    report_file << "		\"StreamingLineBuffer_4_out0_stream_prepad_5_\": " << stream_max_size[162] << ",\n";
    report_file << "		\"StreamingLineBuffer_4_out0_stream_prepad_6_\": " << stream_max_size[163] << ",\n";
    report_file << "		\"StreamingLineBuffer_4_out0_stream_prepad_7_\": " << stream_max_size[164] << ",\n";
    report_file << "		\"StreamingLineBuffer_4_out0_stream_prepad_8_\": " << stream_max_size[165] << ",\n";
    report_file << "		\"StreamingLineBuffer_4_out0_stream_prepad_9_\": " << stream_max_size[166] << ",\n";
    report_file << "		\"StreamingLineBuffer_4_out0_stream_prepad_10_\": " << stream_max_size[167] << ",\n";
    report_file << "		\"StreamingLineBuffer_4_out0_stream_prepad_11_\": " << stream_max_size[168] << ",\n";
    report_file << "		\"StreamingLineBuffer_4_out0_stream_prepad_12_\": " << stream_max_size[169] << ",\n";
    report_file << "		\"StreamingLineBuffer_4_out0_stream_prepad_13_\": " << stream_max_size[170] << ",\n";
    report_file << "		\"StreamingLineBuffer_4_out0_stream_prepad_14_\": " << stream_max_size[171] << ",\n";
    report_file << "		\"StreamingLineBuffer_4_buffer_stream_0_\": " << stream_max_size[172] << ",\n";
    report_file << "		\"StreamingLineBuffer_4_buffer_stream_1_\": " << stream_max_size[173] << ",\n";
    report_file << "		\"StreamingLineBuffer_4_buffer_stream_2_\": " << stream_max_size[174] << ",\n";
    report_file << "		\"StreamingLineBuffer_4_buffer_stream_3_\": " << stream_max_size[175] << ",\n";
    report_file << "		\"StreamingLineBuffer_4_buffer_stream_4_\": " << stream_max_size[176] << ",\n";
    report_file << "		\"StreamingLineBuffer_4_buffer_stream_5_\": " << stream_max_size[177] << ",\n";
    report_file << "		\"StreamingLineBuffer_4_buffer_stream_6_\": " << stream_max_size[178] << ",\n";
    report_file << "		\"StreamingLineBuffer_4_buffer_stream_7_\": " << stream_max_size[179] << ",\n";
    report_file << "		\"StreamingLineBuffer_4_buffer_stream_8_\": " << stream_max_size[180] << ",\n";
    report_file << "		\"StreamingLineBuffer_4_buffer_stream_9_\": " << stream_max_size[181] << ",\n";
    report_file << "		\"StreamingLineBuffer_4_buffer_stream_10_\": " << stream_max_size[182] << ",\n";
    report_file << "		\"StreamingLineBuffer_4_buffer_stream_11_\": " << stream_max_size[183] << ",\n";
    report_file << "		\"StreamingLineBuffer_4_buffer_stream_12_\": " << stream_max_size[184] << ",\n";
    report_file << "		\"StreamingMemory_11_out0_stream_0_\": " << stream_max_size[185] << ",\n";
    report_file << "		\"StreamingMemory_11_out1_stream_0_\": " << stream_max_size[186] << ",\n";
    report_file << "		\"StreamingDepthwiseConv_1_out0_stream_0_\": " << stream_max_size[187] << ",\n";
    report_file << "		\"StreamingDepthwiseConv_1_out0_stream_1_\": " << stream_max_size[188] << ",\n";
    report_file << "		\"StreamingMemory_12_out0_stream_0_\": " << stream_max_size[189] << ",\n";
    report_file << "		\"StreamingMemory_12_out1_stream_0_\": " << stream_max_size[190] << ",\n";
    report_file << "		\"BandwidthAdjustIncreaseStreams_0_out0_stream_0_\": " << stream_max_size[191] << ",\n";
    report_file << "		\"BandwidthAdjustIncreaseStreams_0_out0_stream_1_\": " << stream_max_size[192] << ",\n";
    report_file << "		\"BandwidthAdjustIncreaseStreams_0_out0_stream_2_\": " << stream_max_size[193] << ",\n";
    report_file << "		\"BandwidthAdjustIncreaseStreams_0_out0_stream_3_\": " << stream_max_size[194] << ",\n";
    report_file << "		\"StreamingMemory_13_out0_stream_0_\": " << stream_max_size[195] << ",\n";
    report_file << "		\"StreamingMemory_13_out1_stream_0_\": " << stream_max_size[196] << ",\n";
    report_file << "		\"StreamingLineBuffer_5_out0_stream_0_\": " << stream_max_size[197] << ",\n";
    report_file << "		\"StreamingLineBuffer_5_out0_stream_1_\": " << stream_max_size[198] << ",\n";
    report_file << "		\"StreamingLineBuffer_5_out0_stream_2_\": " << stream_max_size[199] << ",\n";
    report_file << "		\"StreamingLineBuffer_5_out0_stream_3_\": " << stream_max_size[200] << ",\n";
    report_file << "		\"StreamingMemory_14_out0_stream_0_\": " << stream_max_size[201] << ",\n";
    report_file << "		\"StreamingMemory_14_out0_stream_1_\": " << stream_max_size[202] << ",\n";
    report_file << "		\"StreamingMemory_14_out0_stream_2_\": " << stream_max_size[203] << ",\n";
    report_file << "		\"StreamingMemory_14_out0_stream_3_\": " << stream_max_size[204] << ",\n";
    report_file << "		\"StreamingMemory_14_out0_stream_4_\": " << stream_max_size[205] << ",\n";
    report_file << "		\"StreamingMemory_14_out0_stream_5_\": " << stream_max_size[206] << ",\n";
    report_file << "		\"StreamingMemory_14_out0_stream_6_\": " << stream_max_size[207] << ",\n";
    report_file << "		\"StreamingMemory_14_out0_stream_7_\": " << stream_max_size[208] << ",\n";
    report_file << "		\"StreamingMemory_14_out0_stream_8_\": " << stream_max_size[209] << ",\n";
    report_file << "		\"StreamingMemory_14_out1_stream_0_\": " << stream_max_size[210] << ",\n";
    report_file << "		\"StreamingConv_3_out0_stream_0_\": " << stream_max_size[211] << ",\n";
    report_file << "		\"StreamingConv_3_out0_stream_1_\": " << stream_max_size[212] << ",\n";
    report_file << "		\"StreamingConv_3_out0_stream_2_\": " << stream_max_size[213] << ",\n";
    report_file << "		\"StreamingConv_3_out0_stream_3_\": " << stream_max_size[214] << ",\n";
    report_file << "		\"StreamingMemory_15_out0_stream_0_\": " << stream_max_size[215] << ",\n";
    report_file << "		\"StreamingMemory_15_out1_stream_0_\": " << stream_max_size[216] << ",\n";
    report_file << "		\"TensorDuplicator_0_out0_stream_0_\": " << stream_max_size[217] << ",\n";
    report_file << "		\"TensorDuplicator_0_out0_stream_1_\": " << stream_max_size[218] << ",\n";
    report_file << "		\"TensorDuplicator_0_out0_stream_2_\": " << stream_max_size[219] << ",\n";
    report_file << "		\"TensorDuplicator_0_out0_stream_3_\": " << stream_max_size[220] << ",\n";
    report_file << "		\"TensorDuplicator_0_out1_stream_0_\": " << stream_max_size[221] << ",\n";
    report_file << "		\"TensorDuplicator_0_out1_stream_1_\": " << stream_max_size[222] << ",\n";
    report_file << "		\"TensorDuplicator_0_out1_stream_2_\": " << stream_max_size[223] << ",\n";
    report_file << "		\"TensorDuplicator_0_out1_stream_3_\": " << stream_max_size[224] << ",\n";
    report_file << "		\"StreamingMemory_16_out0_stream_0_\": " << stream_max_size[225] << ",\n";
    report_file << "		\"StreamingMemory_16_out1_stream_0_\": " << stream_max_size[226] << ",\n";
    report_file << "		\"BandwidthAdjustDecreaseChannels_0_out0_stream_0_\": " << stream_max_size[227] << ",\n";
    report_file << "		\"BandwidthAdjustDecreaseChannels_0_out0_stream_1_\": " << stream_max_size[228] << ",\n";
    report_file << "		\"BandwidthAdjustDecreaseChannels_0_out0_stream_2_\": " << stream_max_size[229] << ",\n";
    report_file << "		\"BandwidthAdjustDecreaseChannels_0_out0_stream_3_\": " << stream_max_size[230] << ",\n";
    report_file << "		\"BandwidthAdjustDecreaseStreams_0_out0_stream_0_\": " << stream_max_size[231] << ",\n";
    report_file << "		\"BandwidthAdjustDecreaseStreams_0_out0_stream_1_\": " << stream_max_size[232] << ",\n";
    report_file << "		\"StreamingMemory_17_out0_stream_0_\": " << stream_max_size[233] << ",\n";
    report_file << "		\"StreamingMemory_17_out1_stream_0_\": " << stream_max_size[234] << ",\n";
    report_file << "		\"BandwidthAdjustIncreaseChannels_2_out0_stream_0_\": " << stream_max_size[235] << ",\n";
    report_file << "		\"BandwidthAdjustIncreaseChannels_2_out0_stream_1_\": " << stream_max_size[236] << ",\n";
    report_file << "		\"BandwidthAdjustIncreaseChannels_2_out0_stream_2_\": " << stream_max_size[237] << ",\n";
    report_file << "		\"BandwidthAdjustIncreaseChannels_2_out0_stream_3_\": " << stream_max_size[238] << ",\n";
    report_file << "		\"StreamingMemory_18_out0_stream_0_\": " << stream_max_size[239] << ",\n";
    report_file << "		\"StreamingMemory_18_out1_stream_0_\": " << stream_max_size[240] << ",\n";
    report_file << "		\"StreamingLineBuffer_6_out0_stream_0_\": " << stream_max_size[241] << ",\n";
    report_file << "		\"StreamingLineBuffer_6_out0_stream_1_\": " << stream_max_size[242] << ",\n";
    report_file << "		\"StreamingLineBuffer_6_out0_stream_2_\": " << stream_max_size[243] << ",\n";
    report_file << "		\"StreamingLineBuffer_6_out0_stream_3_\": " << stream_max_size[244] << ",\n";
    report_file << "		\"StreamingMemory_19_out0_stream_0_\": " << stream_max_size[245] << ",\n";
    report_file << "		\"StreamingMemory_19_out1_stream_0_\": " << stream_max_size[246] << ",\n";
    report_file << "		\"StreamingConv_4_out0_stream_0_\": " << stream_max_size[247] << ",\n";
    report_file << "		\"StreamingConv_4_out0_stream_1_\": " << stream_max_size[248] << ",\n";
    report_file << "		\"StreamingConv_4_out0_stream_2_\": " << stream_max_size[249] << ",\n";
    report_file << "		\"StreamingConv_4_out0_stream_3_\": " << stream_max_size[250] << ",\n";
    report_file << "		\"StreamingMemory_20_out0_stream_0_\": " << stream_max_size[251] << ",\n";
    report_file << "		\"StreamingMemory_20_out0_stream_1_\": " << stream_max_size[252] << ",\n";
    report_file << "		\"StreamingMemory_20_out0_stream_2_\": " << stream_max_size[253] << ",\n";
    report_file << "		\"StreamingMemory_20_out0_stream_3_\": " << stream_max_size[254] << ",\n";
    report_file << "		\"StreamingMemory_20_out0_stream_4_\": " << stream_max_size[255] << ",\n";
    report_file << "		\"StreamingMemory_20_out0_stream_5_\": " << stream_max_size[256] << ",\n";
    report_file << "		\"StreamingMemory_20_out0_stream_6_\": " << stream_max_size[257] << ",\n";
    report_file << "		\"StreamingMemory_20_out0_stream_7_\": " << stream_max_size[258] << ",\n";
    report_file << "		\"StreamingMemory_20_out0_stream_8_\": " << stream_max_size[259] << ",\n";
    report_file << "		\"StreamingMemory_20_out1_stream_0_\": " << stream_max_size[260] << ",\n";
    report_file << "		\"BandwidthAdjustDecreaseStreams_1_out0_stream_0_\": " << stream_max_size[261] << ",\n";
    report_file << "		\"BandwidthAdjustDecreaseStreams_1_out0_stream_1_\": " << stream_max_size[262] << ",\n";
    report_file << "		\"StreamingMemory_21_out0_stream_0_\": " << stream_max_size[263] << ",\n";
    report_file << "		\"StreamingMemory_21_out1_stream_0_\": " << stream_max_size[264] << ",\n";
    report_file << "		\"StreamingLineBuffer_7_out0_stream_0_\": " << stream_max_size[265] << ",\n";
    report_file << "		\"StreamingLineBuffer_7_out0_stream_1_\": " << stream_max_size[266] << ",\n";
    report_file << "		\"StreamingLineBuffer_7_out0_stream_2_\": " << stream_max_size[267] << ",\n";
    report_file << "		\"StreamingLineBuffer_7_out0_stream_3_\": " << stream_max_size[268] << ",\n";
    report_file << "		\"StreamingLineBuffer_7_out0_stream_4_\": " << stream_max_size[269] << ",\n";
    report_file << "		\"StreamingLineBuffer_7_out0_stream_5_\": " << stream_max_size[270] << ",\n";
    report_file << "		\"StreamingLineBuffer_7_out0_stream_6_\": " << stream_max_size[271] << ",\n";
    report_file << "		\"StreamingLineBuffer_7_out0_stream_7_\": " << stream_max_size[272] << ",\n";
    report_file << "		\"StreamingLineBuffer_7_out0_stream_8_\": " << stream_max_size[273] << ",\n";
    report_file << "		\"StreamingLineBuffer_7_out0_stream_9_\": " << stream_max_size[274] << ",\n";
    report_file << "		\"StreamingLineBuffer_7_out0_stream_10_\": " << stream_max_size[275] << ",\n";
    report_file << "		\"StreamingLineBuffer_7_out0_stream_11_\": " << stream_max_size[276] << ",\n";
    report_file << "		\"StreamingLineBuffer_7_out0_stream_prepad_0_\": " << stream_max_size[277] << ",\n";
    report_file << "		\"StreamingLineBuffer_7_out0_stream_prepad_1_\": " << stream_max_size[278] << ",\n";
    report_file << "		\"StreamingLineBuffer_7_out0_stream_prepad_2_\": " << stream_max_size[279] << ",\n";
    report_file << "		\"StreamingLineBuffer_7_out0_stream_prepad_3_\": " << stream_max_size[280] << ",\n";
    report_file << "		\"StreamingLineBuffer_7_out0_stream_prepad_4_\": " << stream_max_size[281] << ",\n";
    report_file << "		\"StreamingLineBuffer_7_out0_stream_prepad_5_\": " << stream_max_size[282] << ",\n";
    report_file << "		\"StreamingLineBuffer_7_out0_stream_prepad_6_\": " << stream_max_size[283] << ",\n";
    report_file << "		\"StreamingLineBuffer_7_out0_stream_prepad_7_\": " << stream_max_size[284] << ",\n";
    report_file << "		\"StreamingLineBuffer_7_out0_stream_prepad_8_\": " << stream_max_size[285] << ",\n";
    report_file << "		\"StreamingLineBuffer_7_out0_stream_prepad_9_\": " << stream_max_size[286] << ",\n";
    report_file << "		\"StreamingLineBuffer_7_out0_stream_prepad_10_\": " << stream_max_size[287] << ",\n";
    report_file << "		\"StreamingLineBuffer_7_out0_stream_prepad_11_\": " << stream_max_size[288] << ",\n";
    report_file << "		\"StreamingLineBuffer_7_buffer_stream_0_\": " << stream_max_size[289] << ",\n";
    report_file << "		\"StreamingLineBuffer_7_buffer_stream_1_\": " << stream_max_size[290] << ",\n";
    report_file << "		\"StreamingLineBuffer_7_buffer_stream_2_\": " << stream_max_size[291] << ",\n";
    report_file << "		\"StreamingLineBuffer_7_buffer_stream_3_\": " << stream_max_size[292] << ",\n";
    report_file << "		\"StreamingLineBuffer_7_buffer_stream_4_\": " << stream_max_size[293] << ",\n";
    report_file << "		\"StreamingLineBuffer_7_buffer_stream_5_\": " << stream_max_size[294] << ",\n";
    report_file << "		\"StreamingLineBuffer_7_buffer_stream_6_\": " << stream_max_size[295] << ",\n";
    report_file << "		\"StreamingLineBuffer_7_buffer_stream_7_\": " << stream_max_size[296] << ",\n";
    report_file << "		\"StreamingLineBuffer_7_buffer_stream_8_\": " << stream_max_size[297] << ",\n";
    report_file << "		\"StreamingLineBuffer_7_buffer_stream_9_\": " << stream_max_size[298] << ",\n";
    report_file << "		\"StreamingMemory_22_out0_stream_0_\": " << stream_max_size[299] << ",\n";
    report_file << "		\"StreamingMemory_22_out1_stream_0_\": " << stream_max_size[300] << ",\n";
    report_file << "		\"StreamingDepthwiseConv_2_out0_stream_0_\": " << stream_max_size[301] << ",\n";
    report_file << "		\"StreamingDepthwiseConv_2_out0_stream_1_\": " << stream_max_size[302] << ",\n";
    report_file << "		\"StreamingMemory_23_out0_stream_0_\": " << stream_max_size[303] << ",\n";
    report_file << "		\"StreamingMemory_23_out1_stream_0_\": " << stream_max_size[304] << ",\n";
    report_file << "		\"BandwidthAdjustIncreaseChannels_3_out0_stream_0_\": " << stream_max_size[305] << ",\n";
    report_file << "		\"BandwidthAdjustIncreaseChannels_3_out0_stream_1_\": " << stream_max_size[306] << ",\n";
    report_file << "		\"StreamingMemory_24_out0_stream_0_\": " << stream_max_size[307] << ",\n";
    report_file << "		\"StreamingMemory_24_out1_stream_0_\": " << stream_max_size[308] << ",\n";
    report_file << "		\"BandwidthAdjustDecreaseChannels_1_out0_stream_0_\": " << stream_max_size[309] << ",\n";
    report_file << "		\"BandwidthAdjustDecreaseChannels_1_out0_stream_1_\": " << stream_max_size[310] << ",\n";
    report_file << "		\"StreamingMemory_25_out0_stream_0_\": " << stream_max_size[311] << ",\n";
    report_file << "		\"StreamingMemory_25_out1_stream_0_\": " << stream_max_size[312] << ",\n";
    report_file << "		\"StreamingLineBuffer_8_out0_stream_0_\": " << stream_max_size[313] << ",\n";
    report_file << "		\"StreamingLineBuffer_8_out0_stream_1_\": " << stream_max_size[314] << ",\n";
    report_file << "		\"StreamingMemory_26_out0_stream_0_\": " << stream_max_size[315] << ",\n";
    report_file << "		\"StreamingMemory_26_out0_stream_1_\": " << stream_max_size[316] << ",\n";
    report_file << "		\"StreamingMemory_26_out0_stream_2_\": " << stream_max_size[317] << ",\n";
    report_file << "		\"StreamingMemory_26_out0_stream_3_\": " << stream_max_size[318] << ",\n";
    report_file << "		\"StreamingMemory_26_out0_stream_4_\": " << stream_max_size[319] << ",\n";
    report_file << "		\"StreamingMemory_26_out0_stream_5_\": " << stream_max_size[320] << ",\n";
    report_file << "		\"StreamingMemory_26_out0_stream_6_\": " << stream_max_size[321] << ",\n";
    report_file << "		\"StreamingMemory_26_out0_stream_7_\": " << stream_max_size[322] << ",\n";
    report_file << "		\"StreamingMemory_26_out0_stream_8_\": " << stream_max_size[323] << ",\n";
    report_file << "		\"StreamingMemory_26_out1_stream_0_\": " << stream_max_size[324] << ",\n";
    report_file << "		\"StreamingConv_5_out0_stream_0_\": " << stream_max_size[325] << ",\n";
    report_file << "		\"StreamingConv_5_out0_stream_1_\": " << stream_max_size[326] << ",\n";
    report_file << "		\"StreamingMemory_27_out0_stream_0_\": " << stream_max_size[327] << ",\n";
    report_file << "		\"StreamingMemory_27_out1_stream_0_\": " << stream_max_size[328] << ",\n";
    report_file << "		\"StreamingAdd_0_out0_stream_0_\": " << stream_max_size[329] << ",\n";
    report_file << "		\"StreamingAdd_0_out0_stream_1_\": " << stream_max_size[330] << ",\n";
    report_file << "		\"StreamingMemory_28_out0_stream_0_\": " << stream_max_size[331] << ",\n";
    report_file << "		\"StreamingMemory_28_out1_stream_0_\": " << stream_max_size[332] << ",\n";
    report_file << "		\"BandwidthAdjustDecreaseChannels_2_out0_stream_0_\": " << stream_max_size[333] << ",\n";
    report_file << "		\"BandwidthAdjustDecreaseChannels_2_out0_stream_1_\": " << stream_max_size[334] << ",\n";
    report_file << "		\"StreamingMemory_29_out0_stream_0_\": " << stream_max_size[335] << ",\n";
    report_file << "		\"StreamingMemory_29_out1_stream_0_\": " << stream_max_size[336] << ",\n";
    report_file << "		\"BandwidthAdjustIncreaseChannels_4_out0_stream_0_\": " << stream_max_size[337] << ",\n";
    report_file << "		\"BandwidthAdjustIncreaseChannels_4_out0_stream_1_\": " << stream_max_size[338] << ",\n";
    report_file << "		\"StreamingMemory_30_out0_stream_0_\": " << stream_max_size[339] << ",\n";
    report_file << "		\"StreamingMemory_30_out1_stream_0_\": " << stream_max_size[340] << ",\n";
    report_file << "		\"BandwidthAdjustIncreaseStreams_1_out0_stream_0_\": " << stream_max_size[341] << ",\n";
    report_file << "		\"BandwidthAdjustIncreaseStreams_1_out0_stream_1_\": " << stream_max_size[342] << ",\n";
    report_file << "		\"BandwidthAdjustIncreaseStreams_1_out0_stream_2_\": " << stream_max_size[343] << ",\n";
    report_file << "		\"BandwidthAdjustIncreaseStreams_1_out0_stream_3_\": " << stream_max_size[344] << ",\n";
    report_file << "		\"StreamingMemory_31_out0_stream_0_\": " << stream_max_size[345] << ",\n";
    report_file << "		\"StreamingMemory_31_out1_stream_0_\": " << stream_max_size[346] << ",\n";
    report_file << "		\"StreamingLineBuffer_9_out0_stream_0_\": " << stream_max_size[347] << ",\n";
    report_file << "		\"StreamingLineBuffer_9_out0_stream_1_\": " << stream_max_size[348] << ",\n";
    report_file << "		\"StreamingLineBuffer_9_out0_stream_2_\": " << stream_max_size[349] << ",\n";
    report_file << "		\"StreamingLineBuffer_9_out0_stream_3_\": " << stream_max_size[350] << ",\n";
    report_file << "		\"StreamingMemory_32_out0_stream_0_\": " << stream_max_size[351] << ",\n";
    report_file << "		\"StreamingMemory_32_out0_stream_1_\": " << stream_max_size[352] << ",\n";
    report_file << "		\"StreamingMemory_32_out0_stream_2_\": " << stream_max_size[353] << ",\n";
    report_file << "		\"StreamingMemory_32_out0_stream_3_\": " << stream_max_size[354] << ",\n";
    report_file << "		\"StreamingMemory_32_out0_stream_4_\": " << stream_max_size[355] << ",\n";
    report_file << "		\"StreamingMemory_32_out0_stream_5_\": " << stream_max_size[356] << ",\n";
    report_file << "		\"StreamingMemory_32_out0_stream_6_\": " << stream_max_size[357] << ",\n";
    report_file << "		\"StreamingMemory_32_out0_stream_7_\": " << stream_max_size[358] << ",\n";
    report_file << "		\"StreamingMemory_32_out0_stream_8_\": " << stream_max_size[359] << ",\n";
    report_file << "		\"StreamingMemory_32_out1_stream_0_\": " << stream_max_size[360] << ",\n";
    report_file << "		\"StreamingConv_6_out0_stream_0_\": " << stream_max_size[361] << ",\n";
    report_file << "		\"StreamingConv_6_out0_stream_1_\": " << stream_max_size[362] << ",\n";
    report_file << "		\"StreamingConv_6_out0_stream_2_\": " << stream_max_size[363] << ",\n";
    report_file << "		\"StreamingConv_6_out0_stream_3_\": " << stream_max_size[364] << ",\n";
    report_file << "		\"StreamingMemory_33_out0_stream_0_\": " << stream_max_size[365] << ",\n";
    report_file << "		\"StreamingMemory_33_out1_stream_0_\": " << stream_max_size[366] << ",\n";
    report_file << "		\"BandwidthAdjustDecreaseStreams_2_out0_stream_0_\": " << stream_max_size[367] << ",\n";
    report_file << "		\"BandwidthAdjustDecreaseStreams_2_out0_stream_1_\": " << stream_max_size[368] << ",\n";
    report_file << "		\"StreamingMemory_34_out0_stream_0_\": " << stream_max_size[369] << ",\n";
    report_file << "		\"StreamingMemory_34_out1_stream_0_\": " << stream_max_size[370] << ",\n";
    report_file << "		\"StreamingLineBuffer_10_out0_stream_0_\": " << stream_max_size[371] << ",\n";
    report_file << "		\"StreamingLineBuffer_10_out0_stream_1_\": " << stream_max_size[372] << ",\n";
    report_file << "		\"StreamingLineBuffer_10_out0_stream_2_\": " << stream_max_size[373] << ",\n";
    report_file << "		\"StreamingLineBuffer_10_out0_stream_3_\": " << stream_max_size[374] << ",\n";
    report_file << "		\"StreamingLineBuffer_10_out0_stream_4_\": " << stream_max_size[375] << ",\n";
    report_file << "		\"StreamingLineBuffer_10_out0_stream_5_\": " << stream_max_size[376] << ",\n";
    report_file << "		\"StreamingLineBuffer_10_out0_stream_6_\": " << stream_max_size[377] << ",\n";
    report_file << "		\"StreamingLineBuffer_10_out0_stream_7_\": " << stream_max_size[378] << ",\n";
    report_file << "		\"StreamingLineBuffer_10_out0_stream_8_\": " << stream_max_size[379] << ",\n";
    report_file << "		\"StreamingLineBuffer_10_out0_stream_9_\": " << stream_max_size[380] << ",\n";
    report_file << "		\"StreamingLineBuffer_10_out0_stream_10_\": " << stream_max_size[381] << ",\n";
    report_file << "		\"StreamingLineBuffer_10_out0_stream_11_\": " << stream_max_size[382] << ",\n";
    report_file << "		\"StreamingLineBuffer_10_out0_stream_12_\": " << stream_max_size[383] << ",\n";
    report_file << "		\"StreamingLineBuffer_10_out0_stream_13_\": " << stream_max_size[384] << ",\n";
    report_file << "		\"StreamingLineBuffer_10_out0_stream_14_\": " << stream_max_size[385] << ",\n";
    report_file << "		\"StreamingLineBuffer_10_out0_stream_prepad_0_\": " << stream_max_size[386] << ",\n";
    report_file << "		\"StreamingLineBuffer_10_out0_stream_prepad_1_\": " << stream_max_size[387] << ",\n";
    report_file << "		\"StreamingLineBuffer_10_out0_stream_prepad_2_\": " << stream_max_size[388] << ",\n";
    report_file << "		\"StreamingLineBuffer_10_out0_stream_prepad_3_\": " << stream_max_size[389] << ",\n";
    report_file << "		\"StreamingLineBuffer_10_out0_stream_prepad_4_\": " << stream_max_size[390] << ",\n";
    report_file << "		\"StreamingLineBuffer_10_out0_stream_prepad_5_\": " << stream_max_size[391] << ",\n";
    report_file << "		\"StreamingLineBuffer_10_out0_stream_prepad_6_\": " << stream_max_size[392] << ",\n";
    report_file << "		\"StreamingLineBuffer_10_out0_stream_prepad_7_\": " << stream_max_size[393] << ",\n";
    report_file << "		\"StreamingLineBuffer_10_out0_stream_prepad_8_\": " << stream_max_size[394] << ",\n";
    report_file << "		\"StreamingLineBuffer_10_out0_stream_prepad_9_\": " << stream_max_size[395] << ",\n";
    report_file << "		\"StreamingLineBuffer_10_out0_stream_prepad_10_\": " << stream_max_size[396] << ",\n";
    report_file << "		\"StreamingLineBuffer_10_out0_stream_prepad_11_\": " << stream_max_size[397] << ",\n";
    report_file << "		\"StreamingLineBuffer_10_out0_stream_prepad_12_\": " << stream_max_size[398] << ",\n";
    report_file << "		\"StreamingLineBuffer_10_out0_stream_prepad_13_\": " << stream_max_size[399] << ",\n";
    report_file << "		\"StreamingLineBuffer_10_out0_stream_prepad_14_\": " << stream_max_size[400] << ",\n";
    report_file << "		\"StreamingLineBuffer_10_buffer_stream_0_\": " << stream_max_size[401] << ",\n";
    report_file << "		\"StreamingLineBuffer_10_buffer_stream_1_\": " << stream_max_size[402] << ",\n";
    report_file << "		\"StreamingLineBuffer_10_buffer_stream_2_\": " << stream_max_size[403] << ",\n";
    report_file << "		\"StreamingLineBuffer_10_buffer_stream_3_\": " << stream_max_size[404] << ",\n";
    report_file << "		\"StreamingLineBuffer_10_buffer_stream_4_\": " << stream_max_size[405] << ",\n";
    report_file << "		\"StreamingLineBuffer_10_buffer_stream_5_\": " << stream_max_size[406] << ",\n";
    report_file << "		\"StreamingLineBuffer_10_buffer_stream_6_\": " << stream_max_size[407] << ",\n";
    report_file << "		\"StreamingLineBuffer_10_buffer_stream_7_\": " << stream_max_size[408] << ",\n";
    report_file << "		\"StreamingLineBuffer_10_buffer_stream_8_\": " << stream_max_size[409] << ",\n";
    report_file << "		\"StreamingLineBuffer_10_buffer_stream_9_\": " << stream_max_size[410] << ",\n";
    report_file << "		\"StreamingLineBuffer_10_buffer_stream_10_\": " << stream_max_size[411] << ",\n";
    report_file << "		\"StreamingLineBuffer_10_buffer_stream_11_\": " << stream_max_size[412] << ",\n";
    report_file << "		\"StreamingLineBuffer_10_buffer_stream_12_\": " << stream_max_size[413] << ",\n";
    report_file << "		\"StreamingMemory_35_out0_stream_0_\": " << stream_max_size[414] << ",\n";
    report_file << "		\"StreamingMemory_35_out1_stream_0_\": " << stream_max_size[415] << ",\n";
    report_file << "		\"StreamingDepthwiseConv_3_out0_stream_0_\": " << stream_max_size[416] << ",\n";
    report_file << "		\"StreamingDepthwiseConv_3_out0_stream_1_\": " << stream_max_size[417] << ",\n";
    report_file << "		\"StreamingMemory_36_out0_stream_0_\": " << stream_max_size[418] << ",\n";
    report_file << "		\"StreamingMemory_36_out1_stream_0_\": " << stream_max_size[419] << ",\n";
    report_file << "		\"BandwidthAdjustDecreaseChannels_3_out0_stream_0_\": " << stream_max_size[420] << ",\n";
    report_file << "		\"BandwidthAdjustDecreaseChannels_3_out0_stream_1_\": " << stream_max_size[421] << ",\n";
    report_file << "		\"StreamingMemory_37_out0_stream_0_\": " << stream_max_size[422] << ",\n";
    report_file << "		\"StreamingMemory_37_out1_stream_0_\": " << stream_max_size[423] << ",\n";
    report_file << "		\"BandwidthAdjustIncreaseChannels_5_out0_stream_0_\": " << stream_max_size[424] << ",\n";
    report_file << "		\"BandwidthAdjustIncreaseChannels_5_out0_stream_1_\": " << stream_max_size[425] << ",\n";
    report_file << "		\"StreamingMemory_38_out0_stream_0_\": " << stream_max_size[426] << ",\n";
    report_file << "		\"StreamingMemory_38_out0_stream_1_\": " << stream_max_size[427] << ",\n";
    report_file << "		\"StreamingMemory_38_out0_stream_2_\": " << stream_max_size[428] << ",\n";
    report_file << "		\"StreamingMemory_38_out0_stream_3_\": " << stream_max_size[429] << ",\n";
    report_file << "		\"StreamingMemory_38_out0_stream_4_\": " << stream_max_size[430] << ",\n";
    report_file << "		\"StreamingMemory_38_out0_stream_5_\": " << stream_max_size[431] << ",\n";
    report_file << "		\"StreamingMemory_38_out0_stream_6_\": " << stream_max_size[432] << ",\n";
    report_file << "		\"StreamingMemory_38_out0_stream_7_\": " << stream_max_size[433] << ",\n";
    report_file << "		\"StreamingMemory_38_out0_stream_8_\": " << stream_max_size[434] << ",\n";
    report_file << "		\"StreamingMemory_38_out1_stream_0_\": " << stream_max_size[435] << ",\n";
    report_file << "		\"StreamingLineBuffer_11_out0_stream_0_\": " << stream_max_size[436] << ",\n";
    report_file << "		\"StreamingLineBuffer_11_out0_stream_1_\": " << stream_max_size[437] << ",\n";
    report_file << "		\"StreamingMemory_39_out0_stream_0_\": " << stream_max_size[438] << ",\n";
    report_file << "		\"StreamingMemory_39_out1_stream_0_\": " << stream_max_size[439] << ",\n";
    report_file << "		\"StreamingConv_7_out0_stream_0_\": " << stream_max_size[440] << ",\n";
    report_file << "		\"StreamingConv_7_out0_stream_1_\": " << stream_max_size[441] << ",\n";
    report_file << "		\"StreamingMemory_40_out0_stream_0_\": " << stream_max_size[442] << ",\n";
    report_file << "		\"StreamingMemory_40_out1_stream_0_\": " << stream_max_size[443] << ",\n";
    report_file << "		\"TensorDuplicator_1_out0_stream_0_\": " << stream_max_size[444] << ",\n";
    report_file << "		\"TensorDuplicator_1_out0_stream_1_\": " << stream_max_size[445] << ",\n";
    report_file << "		\"TensorDuplicator_1_out1_stream_0_\": " << stream_max_size[446] << ",\n";
    report_file << "		\"TensorDuplicator_1_out1_stream_1_\": " << stream_max_size[447] << ",\n";
    report_file << "		\"StreamingMemory_41_out0_stream_0_\": " << stream_max_size[448] << ",\n";
    report_file << "		\"StreamingMemory_41_out1_stream_0_\": " << stream_max_size[449] << ",\n";
    report_file << "		\"BandwidthAdjustIncreaseChannels_6_out0_stream_0_\": " << stream_max_size[450] << ",\n";
    report_file << "		\"BandwidthAdjustIncreaseChannels_6_out0_stream_1_\": " << stream_max_size[451] << ",\n";
    report_file << "		\"BandwidthAdjustIncreaseChannels_7_out0_stream_0_\": " << stream_max_size[452] << ",\n";
    report_file << "		\"BandwidthAdjustIncreaseChannels_7_out0_stream_1_\": " << stream_max_size[453] << ",\n";
    report_file << "		\"StreamingMemory_42_out0_stream_0_\": " << stream_max_size[454] << ",\n";
    report_file << "		\"StreamingMemory_42_out1_stream_0_\": " << stream_max_size[455] << ",\n";
    report_file << "		\"StreamingLineBuffer_12_out0_stream_0_\": " << stream_max_size[456] << ",\n";
    report_file << "		\"StreamingLineBuffer_12_out0_stream_1_\": " << stream_max_size[457] << ",\n";
    report_file << "		\"StreamingMemory_43_out0_stream_0_\": " << stream_max_size[458] << ",\n";
    report_file << "		\"StreamingMemory_43_out1_stream_0_\": " << stream_max_size[459] << ",\n";
    report_file << "		\"StreamingConv_8_out0_stream_0_\": " << stream_max_size[460] << ",\n";
    report_file << "		\"StreamingConv_8_out0_stream_1_\": " << stream_max_size[461] << ",\n";
    report_file << "		\"StreamingMemory_44_out0_stream_0_\": " << stream_max_size[462] << ",\n";
    report_file << "		\"StreamingMemory_44_out0_stream_1_\": " << stream_max_size[463] << ",\n";
    report_file << "		\"StreamingMemory_44_out0_stream_2_\": " << stream_max_size[464] << ",\n";
    report_file << "		\"StreamingMemory_44_out0_stream_3_\": " << stream_max_size[465] << ",\n";
    report_file << "		\"StreamingMemory_44_out0_stream_4_\": " << stream_max_size[466] << ",\n";
    report_file << "		\"StreamingMemory_44_out0_stream_5_\": " << stream_max_size[467] << ",\n";
    report_file << "		\"StreamingMemory_44_out0_stream_6_\": " << stream_max_size[468] << ",\n";
    report_file << "		\"StreamingMemory_44_out0_stream_7_\": " << stream_max_size[469] << ",\n";
    report_file << "		\"StreamingMemory_44_out0_stream_8_\": " << stream_max_size[470] << ",\n";
    report_file << "		\"StreamingMemory_44_out1_stream_0_\": " << stream_max_size[471] << ",\n";
    report_file << "		\"BandwidthAdjustDecreaseChannels_4_out0_stream_0_\": " << stream_max_size[472] << ",\n";
    report_file << "		\"BandwidthAdjustDecreaseChannels_4_out0_stream_1_\": " << stream_max_size[473] << ",\n";
    report_file << "		\"StreamingMemory_45_out0_stream_0_\": " << stream_max_size[474] << ",\n";
    report_file << "		\"StreamingMemory_45_out1_stream_0_\": " << stream_max_size[475] << ",\n";
    report_file << "		\"StreamingLineBuffer_13_out0_stream_0_\": " << stream_max_size[476] << ",\n";
    report_file << "		\"StreamingLineBuffer_13_out0_stream_1_\": " << stream_max_size[477] << ",\n";
    report_file << "		\"StreamingLineBuffer_13_out0_stream_2_\": " << stream_max_size[478] << ",\n";
    report_file << "		\"StreamingLineBuffer_13_out0_stream_3_\": " << stream_max_size[479] << ",\n";
    report_file << "		\"StreamingLineBuffer_13_out0_stream_4_\": " << stream_max_size[480] << ",\n";
    report_file << "		\"StreamingLineBuffer_13_out0_stream_5_\": " << stream_max_size[481] << ",\n";
    report_file << "		\"StreamingLineBuffer_13_out0_stream_6_\": " << stream_max_size[482] << ",\n";
    report_file << "		\"StreamingLineBuffer_13_out0_stream_7_\": " << stream_max_size[483] << ",\n";
    report_file << "		\"StreamingLineBuffer_13_out0_stream_8_\": " << stream_max_size[484] << ",\n";
    report_file << "		\"StreamingLineBuffer_13_out0_stream_9_\": " << stream_max_size[485] << ",\n";
    report_file << "		\"StreamingLineBuffer_13_out0_stream_10_\": " << stream_max_size[486] << ",\n";
    report_file << "		\"StreamingLineBuffer_13_out0_stream_11_\": " << stream_max_size[487] << ",\n";
    report_file << "		\"StreamingLineBuffer_13_out0_stream_prepad_0_\": " << stream_max_size[488] << ",\n";
    report_file << "		\"StreamingLineBuffer_13_out0_stream_prepad_1_\": " << stream_max_size[489] << ",\n";
    report_file << "		\"StreamingLineBuffer_13_out0_stream_prepad_2_\": " << stream_max_size[490] << ",\n";
    report_file << "		\"StreamingLineBuffer_13_out0_stream_prepad_3_\": " << stream_max_size[491] << ",\n";
    report_file << "		\"StreamingLineBuffer_13_out0_stream_prepad_4_\": " << stream_max_size[492] << ",\n";
    report_file << "		\"StreamingLineBuffer_13_out0_stream_prepad_5_\": " << stream_max_size[493] << ",\n";
    report_file << "		\"StreamingLineBuffer_13_out0_stream_prepad_6_\": " << stream_max_size[494] << ",\n";
    report_file << "		\"StreamingLineBuffer_13_out0_stream_prepad_7_\": " << stream_max_size[495] << ",\n";
    report_file << "		\"StreamingLineBuffer_13_out0_stream_prepad_8_\": " << stream_max_size[496] << ",\n";
    report_file << "		\"StreamingLineBuffer_13_out0_stream_prepad_9_\": " << stream_max_size[497] << ",\n";
    report_file << "		\"StreamingLineBuffer_13_out0_stream_prepad_10_\": " << stream_max_size[498] << ",\n";
    report_file << "		\"StreamingLineBuffer_13_out0_stream_prepad_11_\": " << stream_max_size[499] << ",\n";
    report_file << "		\"StreamingLineBuffer_13_buffer_stream_0_\": " << stream_max_size[500] << ",\n";
    report_file << "		\"StreamingLineBuffer_13_buffer_stream_1_\": " << stream_max_size[501] << ",\n";
    report_file << "		\"StreamingLineBuffer_13_buffer_stream_2_\": " << stream_max_size[502] << ",\n";
    report_file << "		\"StreamingLineBuffer_13_buffer_stream_3_\": " << stream_max_size[503] << ",\n";
    report_file << "		\"StreamingLineBuffer_13_buffer_stream_4_\": " << stream_max_size[504] << ",\n";
    report_file << "		\"StreamingLineBuffer_13_buffer_stream_5_\": " << stream_max_size[505] << ",\n";
    report_file << "		\"StreamingLineBuffer_13_buffer_stream_6_\": " << stream_max_size[506] << ",\n";
    report_file << "		\"StreamingLineBuffer_13_buffer_stream_7_\": " << stream_max_size[507] << ",\n";
    report_file << "		\"StreamingLineBuffer_13_buffer_stream_8_\": " << stream_max_size[508] << ",\n";
    report_file << "		\"StreamingLineBuffer_13_buffer_stream_9_\": " << stream_max_size[509] << ",\n";
    report_file << "		\"StreamingMemory_46_out0_stream_0_\": " << stream_max_size[510] << ",\n";
    report_file << "		\"StreamingMemory_46_out1_stream_0_\": " << stream_max_size[511] << ",\n";
    report_file << "		\"StreamingDepthwiseConv_4_out0_stream_0_\": " << stream_max_size[512] << ",\n";
    report_file << "		\"StreamingDepthwiseConv_4_out0_stream_1_\": " << stream_max_size[513] << ",\n";
    report_file << "		\"StreamingMemory_47_out0_stream_0_\": " << stream_max_size[514] << ",\n";
    report_file << "		\"StreamingMemory_47_out1_stream_0_\": " << stream_max_size[515] << ",\n";
    report_file << "		\"BandwidthAdjustIncreaseChannels_8_out0_stream_0_\": " << stream_max_size[516] << ",\n";
    report_file << "		\"BandwidthAdjustIncreaseChannels_8_out0_stream_1_\": " << stream_max_size[517] << ",\n";
    report_file << "		\"StreamingMemory_48_out0_stream_0_\": " << stream_max_size[518] << ",\n";
    report_file << "		\"StreamingMemory_48_out1_stream_0_\": " << stream_max_size[519] << ",\n";
    report_file << "		\"StreamingLineBuffer_14_out0_stream_0_\": " << stream_max_size[520] << ",\n";
    report_file << "		\"StreamingLineBuffer_14_out0_stream_1_\": " << stream_max_size[521] << ",\n";
    report_file << "		\"StreamingMemory_49_out0_stream_0_\": " << stream_max_size[522] << ",\n";
    report_file << "		\"StreamingMemory_49_out1_stream_0_\": " << stream_max_size[523] << ",\n";
    report_file << "		\"StreamingConv_9_out0_stream_0_\": " << stream_max_size[524] << ",\n";
    report_file << "		\"StreamingConv_9_out0_stream_1_\": " << stream_max_size[525] << ",\n";
    report_file << "		\"StreamingMemory_50_out0_stream_0_\": " << stream_max_size[526] << ",\n";
    report_file << "		\"StreamingMemory_50_out0_stream_1_\": " << stream_max_size[527] << ",\n";
    report_file << "		\"StreamingMemory_50_out0_stream_2_\": " << stream_max_size[528] << ",\n";
    report_file << "		\"StreamingMemory_50_out0_stream_3_\": " << stream_max_size[529] << ",\n";
    report_file << "		\"StreamingMemory_50_out0_stream_4_\": " << stream_max_size[530] << ",\n";
    report_file << "		\"StreamingMemory_50_out0_stream_5_\": " << stream_max_size[531] << ",\n";
    report_file << "		\"StreamingMemory_50_out0_stream_6_\": " << stream_max_size[532] << ",\n";
    report_file << "		\"StreamingMemory_50_out0_stream_7_\": " << stream_max_size[533] << ",\n";
    report_file << "		\"StreamingMemory_50_out0_stream_8_\": " << stream_max_size[534] << ",\n";
    report_file << "		\"StreamingMemory_50_out1_stream_0_\": " << stream_max_size[535] << ",\n";
    report_file << "		\"StreamingAdd_1_out0_stream_0_\": " << stream_max_size[536] << ",\n";
    report_file << "		\"StreamingAdd_1_out0_stream_1_\": " << stream_max_size[537] << ",\n";
    report_file << "		\"StreamingMemory_51_out0_stream_0_\": " << stream_max_size[538] << ",\n";
    report_file << "		\"StreamingMemory_51_out1_stream_0_\": " << stream_max_size[539] << ",\n";
    report_file << "		\"BandwidthAdjustDecreaseChannels_5_out0_stream_0_\": " << stream_max_size[540] << ",\n";
    report_file << "		\"BandwidthAdjustDecreaseChannels_5_out0_stream_1_\": " << stream_max_size[541] << ",\n";
    report_file << "		\"StreamingMemory_52_out0_stream_0_\": " << stream_max_size[542] << ",\n";
    report_file << "		\"StreamingMemory_52_out1_stream_0_\": " << stream_max_size[543] << ",\n";
    report_file << "		\"TensorDuplicator_2_out0_stream_0_\": " << stream_max_size[544] << ",\n";
    report_file << "		\"TensorDuplicator_2_out0_stream_1_\": " << stream_max_size[545] << ",\n";
    report_file << "		\"TensorDuplicator_2_out1_stream_0_\": " << stream_max_size[546] << ",\n";
    report_file << "		\"TensorDuplicator_2_out1_stream_1_\": " << stream_max_size[547] << ",\n";
    report_file << "		\"StreamingMemory_53_out0_stream_0_\": " << stream_max_size[548] << ",\n";
    report_file << "		\"StreamingMemory_53_out1_stream_0_\": " << stream_max_size[549] << ",\n";
    report_file << "		\"BandwidthAdjustIncreaseChannels_9_out0_stream_0_\": " << stream_max_size[550] << ",\n";
    report_file << "		\"BandwidthAdjustIncreaseChannels_9_out0_stream_1_\": " << stream_max_size[551] << ",\n";
    report_file << "		\"BandwidthAdjustIncreaseChannels_10_out0_stream_0_\": " << stream_max_size[552] << ",\n";
    report_file << "		\"BandwidthAdjustIncreaseChannels_10_out0_stream_1_\": " << stream_max_size[553] << ",\n";
    report_file << "		\"StreamingMemory_54_out0_stream_0_\": " << stream_max_size[554] << ",\n";
    report_file << "		\"StreamingMemory_54_out1_stream_0_\": " << stream_max_size[555] << ",\n";
    report_file << "		\"StreamingLineBuffer_15_out0_stream_0_\": " << stream_max_size[556] << ",\n";
    report_file << "		\"StreamingLineBuffer_15_out0_stream_1_\": " << stream_max_size[557] << ",\n";
    report_file << "		\"StreamingMemory_55_out0_stream_0_\": " << stream_max_size[558] << ",\n";
    report_file << "		\"StreamingMemory_55_out1_stream_0_\": " << stream_max_size[559] << ",\n";
    report_file << "		\"StreamingConv_10_out0_stream_0_\": " << stream_max_size[560] << ",\n";
    report_file << "		\"StreamingConv_10_out0_stream_1_\": " << stream_max_size[561] << ",\n";
    report_file << "		\"StreamingMemory_56_out0_stream_0_\": " << stream_max_size[562] << ",\n";
    report_file << "		\"StreamingMemory_56_out0_stream_1_\": " << stream_max_size[563] << ",\n";
    report_file << "		\"StreamingMemory_56_out0_stream_2_\": " << stream_max_size[564] << ",\n";
    report_file << "		\"StreamingMemory_56_out0_stream_3_\": " << stream_max_size[565] << ",\n";
    report_file << "		\"StreamingMemory_56_out0_stream_4_\": " << stream_max_size[566] << ",\n";
    report_file << "		\"StreamingMemory_56_out0_stream_5_\": " << stream_max_size[567] << ",\n";
    report_file << "		\"StreamingMemory_56_out0_stream_6_\": " << stream_max_size[568] << ",\n";
    report_file << "		\"StreamingMemory_56_out0_stream_7_\": " << stream_max_size[569] << ",\n";
    report_file << "		\"StreamingMemory_56_out0_stream_8_\": " << stream_max_size[570] << ",\n";
    report_file << "		\"StreamingMemory_56_out1_stream_0_\": " << stream_max_size[571] << ",\n";
    report_file << "		\"BandwidthAdjustDecreaseChannels_6_out0_stream_0_\": " << stream_max_size[572] << ",\n";
    report_file << "		\"BandwidthAdjustDecreaseChannels_6_out0_stream_1_\": " << stream_max_size[573] << ",\n";
    report_file << "		\"StreamingMemory_57_out0_stream_0_\": " << stream_max_size[574] << ",\n";
    report_file << "		\"StreamingMemory_57_out1_stream_0_\": " << stream_max_size[575] << ",\n";
    report_file << "		\"StreamingLineBuffer_16_out0_stream_0_\": " << stream_max_size[576] << ",\n";
    report_file << "		\"StreamingLineBuffer_16_out0_stream_1_\": " << stream_max_size[577] << ",\n";
    report_file << "		\"StreamingLineBuffer_16_out0_stream_2_\": " << stream_max_size[578] << ",\n";
    report_file << "		\"StreamingLineBuffer_16_out0_stream_3_\": " << stream_max_size[579] << ",\n";
    report_file << "		\"StreamingLineBuffer_16_out0_stream_4_\": " << stream_max_size[580] << ",\n";
    report_file << "		\"StreamingLineBuffer_16_out0_stream_5_\": " << stream_max_size[581] << ",\n";
    report_file << "		\"StreamingLineBuffer_16_out0_stream_6_\": " << stream_max_size[582] << ",\n";
    report_file << "		\"StreamingLineBuffer_16_out0_stream_7_\": " << stream_max_size[583] << ",\n";
    report_file << "		\"StreamingLineBuffer_16_out0_stream_8_\": " << stream_max_size[584] << ",\n";
    report_file << "		\"StreamingLineBuffer_16_out0_stream_9_\": " << stream_max_size[585] << ",\n";
    report_file << "		\"StreamingLineBuffer_16_out0_stream_10_\": " << stream_max_size[586] << ",\n";
    report_file << "		\"StreamingLineBuffer_16_out0_stream_11_\": " << stream_max_size[587] << ",\n";
    report_file << "		\"StreamingLineBuffer_16_out0_stream_prepad_0_\": " << stream_max_size[588] << ",\n";
    report_file << "		\"StreamingLineBuffer_16_out0_stream_prepad_1_\": " << stream_max_size[589] << ",\n";
    report_file << "		\"StreamingLineBuffer_16_out0_stream_prepad_2_\": " << stream_max_size[590] << ",\n";
    report_file << "		\"StreamingLineBuffer_16_out0_stream_prepad_3_\": " << stream_max_size[591] << ",\n";
    report_file << "		\"StreamingLineBuffer_16_out0_stream_prepad_4_\": " << stream_max_size[592] << ",\n";
    report_file << "		\"StreamingLineBuffer_16_out0_stream_prepad_5_\": " << stream_max_size[593] << ",\n";
    report_file << "		\"StreamingLineBuffer_16_out0_stream_prepad_6_\": " << stream_max_size[594] << ",\n";
    report_file << "		\"StreamingLineBuffer_16_out0_stream_prepad_7_\": " << stream_max_size[595] << ",\n";
    report_file << "		\"StreamingLineBuffer_16_out0_stream_prepad_8_\": " << stream_max_size[596] << ",\n";
    report_file << "		\"StreamingLineBuffer_16_out0_stream_prepad_9_\": " << stream_max_size[597] << ",\n";
    report_file << "		\"StreamingLineBuffer_16_out0_stream_prepad_10_\": " << stream_max_size[598] << ",\n";
    report_file << "		\"StreamingLineBuffer_16_out0_stream_prepad_11_\": " << stream_max_size[599] << ",\n";
    report_file << "		\"StreamingLineBuffer_16_buffer_stream_0_\": " << stream_max_size[600] << ",\n";
    report_file << "		\"StreamingLineBuffer_16_buffer_stream_1_\": " << stream_max_size[601] << ",\n";
    report_file << "		\"StreamingLineBuffer_16_buffer_stream_2_\": " << stream_max_size[602] << ",\n";
    report_file << "		\"StreamingLineBuffer_16_buffer_stream_3_\": " << stream_max_size[603] << ",\n";
    report_file << "		\"StreamingLineBuffer_16_buffer_stream_4_\": " << stream_max_size[604] << ",\n";
    report_file << "		\"StreamingLineBuffer_16_buffer_stream_5_\": " << stream_max_size[605] << ",\n";
    report_file << "		\"StreamingLineBuffer_16_buffer_stream_6_\": " << stream_max_size[606] << ",\n";
    report_file << "		\"StreamingLineBuffer_16_buffer_stream_7_\": " << stream_max_size[607] << ",\n";
    report_file << "		\"StreamingLineBuffer_16_buffer_stream_8_\": " << stream_max_size[608] << ",\n";
    report_file << "		\"StreamingLineBuffer_16_buffer_stream_9_\": " << stream_max_size[609] << ",\n";
    report_file << "		\"StreamingMemory_58_out0_stream_0_\": " << stream_max_size[610] << ",\n";
    report_file << "		\"StreamingMemory_58_out1_stream_0_\": " << stream_max_size[611] << ",\n";
    report_file << "		\"StreamingDepthwiseConv_5_out0_stream_0_\": " << stream_max_size[612] << ",\n";
    report_file << "		\"StreamingDepthwiseConv_5_out0_stream_1_\": " << stream_max_size[613] << ",\n";
    report_file << "		\"StreamingMemory_59_out0_stream_0_\": " << stream_max_size[614] << ",\n";
    report_file << "		\"StreamingMemory_59_out1_stream_0_\": " << stream_max_size[615] << ",\n";
    report_file << "		\"BandwidthAdjustIncreaseChannels_11_out0_stream_0_\": " << stream_max_size[616] << ",\n";
    report_file << "		\"BandwidthAdjustIncreaseChannels_11_out0_stream_1_\": " << stream_max_size[617] << ",\n";
    report_file << "		\"StreamingMemory_60_out0_stream_0_\": " << stream_max_size[618] << ",\n";
    report_file << "		\"StreamingMemory_60_out1_stream_0_\": " << stream_max_size[619] << ",\n";
    report_file << "		\"StreamingLineBuffer_17_out0_stream_0_\": " << stream_max_size[620] << ",\n";
    report_file << "		\"StreamingLineBuffer_17_out0_stream_1_\": " << stream_max_size[621] << ",\n";
    report_file << "		\"StreamingMemory_61_out0_stream_0_\": " << stream_max_size[622] << ",\n";
    report_file << "		\"StreamingMemory_61_out1_stream_0_\": " << stream_max_size[623] << ",\n";
    report_file << "		\"StreamingConv_11_out0_stream_0_\": " << stream_max_size[624] << ",\n";
    report_file << "		\"StreamingConv_11_out0_stream_1_\": " << stream_max_size[625] << ",\n";
    report_file << "		\"StreamingMemory_62_out0_stream_0_\": " << stream_max_size[626] << ",\n";
    report_file << "		\"StreamingMemory_62_out0_stream_1_\": " << stream_max_size[627] << ",\n";
    report_file << "		\"StreamingMemory_62_out0_stream_2_\": " << stream_max_size[628] << ",\n";
    report_file << "		\"StreamingMemory_62_out0_stream_3_\": " << stream_max_size[629] << ",\n";
    report_file << "		\"StreamingMemory_62_out0_stream_4_\": " << stream_max_size[630] << ",\n";
    report_file << "		\"StreamingMemory_62_out0_stream_5_\": " << stream_max_size[631] << ",\n";
    report_file << "		\"StreamingMemory_62_out0_stream_6_\": " << stream_max_size[632] << ",\n";
    report_file << "		\"StreamingMemory_62_out0_stream_7_\": " << stream_max_size[633] << ",\n";
    report_file << "		\"StreamingMemory_62_out0_stream_8_\": " << stream_max_size[634] << ",\n";
    report_file << "		\"StreamingMemory_62_out1_stream_0_\": " << stream_max_size[635] << ",\n";
    report_file << "		\"StreamingAdd_2_out0_stream_0_\": " << stream_max_size[636] << ",\n";
    report_file << "		\"StreamingAdd_2_out0_stream_1_\": " << stream_max_size[637] << ",\n";
    report_file << "		\"StreamingMemory_63_out0_stream_0_\": " << stream_max_size[638] << ",\n";
    report_file << "		\"StreamingMemory_63_out1_stream_0_\": " << stream_max_size[639] << ",\n";
    report_file << "		\"StreamingLineBuffer_18_out0_stream_0_\": " << stream_max_size[640] << ",\n";
    report_file << "		\"StreamingLineBuffer_18_out0_stream_1_\": " << stream_max_size[641] << ",\n";
    report_file << "		\"StreamingMemory_64_out0_stream_0_\": " << stream_max_size[642] << ",\n";
    report_file << "		\"StreamingMemory_64_out1_stream_0_\": " << stream_max_size[643] << ",\n";
    report_file << "		\"StreamingConv_12_out0_stream_0_\": " << stream_max_size[644] << ",\n";
    report_file << "		\"StreamingConv_12_out0_stream_1_\": " << stream_max_size[645] << ",\n";
    report_file << "		\"StreamingMemory_65_out0_stream_0_\": " << stream_max_size[646] << ",\n";
    report_file << "		\"StreamingMemory_65_out1_stream_0_\": " << stream_max_size[647] << ",\n";
    report_file << "		\"BandwidthAdjustDecreaseChannels_7_out0_stream_0_\": " << stream_max_size[648] << ",\n";
    report_file << "		\"BandwidthAdjustDecreaseChannels_7_out0_stream_1_\": " << stream_max_size[649] << ",\n";
    report_file << "		\"StreamingMemory_66_out0_stream_0_\": " << stream_max_size[650] << ",\n";
    report_file << "		\"StreamingMemory_66_out1_stream_0_\": " << stream_max_size[651] << ",\n";
    report_file << "		\"BandwidthAdjustDecreaseStreams_3_out0_stream_0_\": " << stream_max_size[652] << ",\n";
    report_file << "		\"StreamingMemory_67_out0_stream_0_\": " << stream_max_size[653] << ",\n";
    report_file << "		\"StreamingMemory_67_out1_stream_0_\": " << stream_max_size[654] << ",\n";
    report_file << "		\"StreamingLineBuffer_19_out0_stream_0_\": " << stream_max_size[655] << ",\n";
    report_file << "		\"StreamingLineBuffer_19_out0_stream_1_\": " << stream_max_size[656] << ",\n";
    report_file << "		\"StreamingLineBuffer_19_out0_stream_2_\": " << stream_max_size[657] << ",\n";
    report_file << "		\"StreamingLineBuffer_19_out0_stream_3_\": " << stream_max_size[658] << ",\n";
    report_file << "		\"StreamingLineBuffer_19_out0_stream_4_\": " << stream_max_size[659] << ",\n";
    report_file << "		\"StreamingLineBuffer_19_out0_stream_5_\": " << stream_max_size[660] << ",\n";
    report_file << "		\"StreamingLineBuffer_19_out0_stream_6_\": " << stream_max_size[661] << ",\n";
    report_file << "		\"StreamingLineBuffer_19_out0_stream_7_\": " << stream_max_size[662] << ",\n";
    report_file << "		\"StreamingLineBuffer_19_out0_stream_8_\": " << stream_max_size[663] << ",\n";
    report_file << "		\"StreamingLineBuffer_19_out0_stream_prepad_0_\": " << stream_max_size[664] << ",\n";
    report_file << "		\"StreamingLineBuffer_19_out0_stream_prepad_1_\": " << stream_max_size[665] << ",\n";
    report_file << "		\"StreamingLineBuffer_19_out0_stream_prepad_2_\": " << stream_max_size[666] << ",\n";
    report_file << "		\"StreamingLineBuffer_19_out0_stream_prepad_3_\": " << stream_max_size[667] << ",\n";
    report_file << "		\"StreamingLineBuffer_19_out0_stream_prepad_4_\": " << stream_max_size[668] << ",\n";
    report_file << "		\"StreamingLineBuffer_19_out0_stream_prepad_5_\": " << stream_max_size[669] << ",\n";
    report_file << "		\"StreamingLineBuffer_19_out0_stream_prepad_6_\": " << stream_max_size[670] << ",\n";
    report_file << "		\"StreamingLineBuffer_19_out0_stream_prepad_7_\": " << stream_max_size[671] << ",\n";
    report_file << "		\"StreamingLineBuffer_19_out0_stream_prepad_8_\": " << stream_max_size[672] << ",\n";
    report_file << "		\"StreamingLineBuffer_19_buffer_stream_0_\": " << stream_max_size[673] << ",\n";
    report_file << "		\"StreamingLineBuffer_19_buffer_stream_1_\": " << stream_max_size[674] << ",\n";
    report_file << "		\"StreamingLineBuffer_19_buffer_stream_2_\": " << stream_max_size[675] << ",\n";
    report_file << "		\"StreamingLineBuffer_19_buffer_stream_3_\": " << stream_max_size[676] << ",\n";
    report_file << "		\"StreamingLineBuffer_19_buffer_stream_4_\": " << stream_max_size[677] << ",\n";
    report_file << "		\"StreamingLineBuffer_19_buffer_stream_5_\": " << stream_max_size[678] << ",\n";
    report_file << "		\"StreamingLineBuffer_19_buffer_stream_6_\": " << stream_max_size[679] << ",\n";
    report_file << "		\"StreamingLineBuffer_19_buffer_stream_7_\": " << stream_max_size[680] << ",\n";
    report_file << "		\"StreamingMemory_68_out0_stream_0_\": " << stream_max_size[681] << ",\n";
    report_file << "		\"StreamingMemory_68_out0_stream_1_\": " << stream_max_size[682] << ",\n";
    report_file << "		\"StreamingMemory_68_out0_stream_2_\": " << stream_max_size[683] << ",\n";
    report_file << "		\"StreamingMemory_68_out0_stream_3_\": " << stream_max_size[684] << ",\n";
    report_file << "		\"StreamingMemory_68_out0_stream_4_\": " << stream_max_size[685] << ",\n";
    report_file << "		\"StreamingMemory_68_out0_stream_5_\": " << stream_max_size[686] << ",\n";
    report_file << "		\"StreamingMemory_68_out0_stream_6_\": " << stream_max_size[687] << ",\n";
    report_file << "		\"StreamingMemory_68_out0_stream_7_\": " << stream_max_size[688] << ",\n";
    report_file << "		\"StreamingMemory_68_out0_stream_8_\": " << stream_max_size[689] << ",\n";
    report_file << "		\"StreamingMemory_68_out1_stream_0_\": " << stream_max_size[690] << ",\n";
    report_file << "		\"StreamingDepthwiseConv_6_out0_stream_0_\": " << stream_max_size[691] << ",\n";
    report_file << "		\"StreamingMemory_69_out0_stream_0_\": " << stream_max_size[692] << ",\n";
    report_file << "		\"StreamingMemory_69_out1_stream_0_\": " << stream_max_size[693] << ",\n";
    report_file << "		\"BandwidthAdjustIncreaseChannels_12_out0_stream_0_\": " << stream_max_size[694] << ",\n";
    report_file << "		\"StreamingMemory_70_out0_stream_0_\": " << stream_max_size[695] << ",\n";
    report_file << "		\"StreamingMemory_70_out1_stream_0_\": " << stream_max_size[696] << ",\n";
    report_file << "		\"StreamingConv_13_out0_stream_0_\": " << stream_max_size[697] << ",\n";
    report_file << "		\"StreamingMemory_71_out0_stream_0_\": " << stream_max_size[698] << ",\n";
    report_file << "		\"StreamingMemory_71_out1_stream_0_\": " << stream_max_size[699] << ",\n";
    report_file << "		\"TensorDuplicator_3_out0_stream_0_\": " << stream_max_size[700] << ",\n";
    report_file << "		\"TensorDuplicator_3_out1_stream_0_\": " << stream_max_size[701] << ",\n";
    report_file << "		\"StreamingMemory_72_out0_stream_0_\": " << stream_max_size[702] << ",\n";
    report_file << "		\"StreamingMemory_72_out1_stream_0_\": " << stream_max_size[703] << ",\n";
    report_file << "		\"BandwidthAdjustIncreaseStreams_2_out0_stream_0_\": " << stream_max_size[704] << ",\n";
    report_file << "		\"BandwidthAdjustIncreaseStreams_2_out0_stream_1_\": " << stream_max_size[705] << ",\n";
    report_file << "		\"BandwidthAdjustIncreaseStreams_3_out0_stream_0_\": " << stream_max_size[706] << ",\n";
    report_file << "		\"BandwidthAdjustIncreaseStreams_3_out0_stream_1_\": " << stream_max_size[707] << ",\n";
    report_file << "		\"StreamingMemory_73_out0_stream_0_\": " << stream_max_size[708] << ",\n";
    report_file << "		\"StreamingMemory_73_out1_stream_0_\": " << stream_max_size[709] << ",\n";
    report_file << "		\"StreamingLineBuffer_20_out0_stream_0_\": " << stream_max_size[710] << ",\n";
    report_file << "		\"StreamingLineBuffer_20_out0_stream_1_\": " << stream_max_size[711] << ",\n";
    report_file << "		\"StreamingMemory_74_out0_stream_0_\": " << stream_max_size[712] << ",\n";
    report_file << "		\"StreamingMemory_74_out0_stream_1_\": " << stream_max_size[713] << ",\n";
    report_file << "		\"StreamingMemory_74_out0_stream_2_\": " << stream_max_size[714] << ",\n";
    report_file << "		\"StreamingMemory_74_out0_stream_3_\": " << stream_max_size[715] << ",\n";
    report_file << "		\"StreamingMemory_74_out0_stream_4_\": " << stream_max_size[716] << ",\n";
    report_file << "		\"StreamingMemory_74_out0_stream_5_\": " << stream_max_size[717] << ",\n";
    report_file << "		\"StreamingMemory_74_out0_stream_6_\": " << stream_max_size[718] << ",\n";
    report_file << "		\"StreamingMemory_74_out0_stream_7_\": " << stream_max_size[719] << ",\n";
    report_file << "		\"StreamingMemory_74_out0_stream_8_\": " << stream_max_size[720] << ",\n";
    report_file << "		\"StreamingMemory_74_out1_stream_0_\": " << stream_max_size[721] << ",\n";
    report_file << "		\"StreamingConv_14_out0_stream_0_\": " << stream_max_size[722] << ",\n";
    report_file << "		\"StreamingConv_14_out0_stream_1_\": " << stream_max_size[723] << ",\n";
    report_file << "		\"StreamingMemory_75_out0_stream_0_\": " << stream_max_size[724] << ",\n";
    report_file << "		\"StreamingMemory_75_out1_stream_0_\": " << stream_max_size[725] << ",\n";
    report_file << "		\"BandwidthAdjustDecreaseChannels_8_out0_stream_0_\": " << stream_max_size[726] << ",\n";
    report_file << "		\"BandwidthAdjustDecreaseChannels_8_out0_stream_1_\": " << stream_max_size[727] << ",\n";
    report_file << "		\"StreamingMemory_76_out0_stream_0_\": " << stream_max_size[728] << ",\n";
    report_file << "		\"StreamingMemory_76_out1_stream_0_\": " << stream_max_size[729] << ",\n";
    report_file << "		\"StreamingLineBuffer_21_out0_stream_0_\": " << stream_max_size[730] << ",\n";
    report_file << "		\"StreamingLineBuffer_21_out0_stream_1_\": " << stream_max_size[731] << ",\n";
    report_file << "		\"StreamingLineBuffer_21_out0_stream_2_\": " << stream_max_size[732] << ",\n";
    report_file << "		\"StreamingLineBuffer_21_out0_stream_3_\": " << stream_max_size[733] << ",\n";
    report_file << "		\"StreamingLineBuffer_21_out0_stream_4_\": " << stream_max_size[734] << ",\n";
    report_file << "		\"StreamingLineBuffer_21_out0_stream_5_\": " << stream_max_size[735] << ",\n";
    report_file << "		\"StreamingLineBuffer_21_out0_stream_6_\": " << stream_max_size[736] << ",\n";
    report_file << "		\"StreamingLineBuffer_21_out0_stream_7_\": " << stream_max_size[737] << ",\n";
    report_file << "		\"StreamingLineBuffer_21_out0_stream_8_\": " << stream_max_size[738] << ",\n";
    report_file << "		\"StreamingLineBuffer_21_out0_stream_9_\": " << stream_max_size[739] << ",\n";
    report_file << "		\"StreamingLineBuffer_21_out0_stream_10_\": " << stream_max_size[740] << ",\n";
    report_file << "		\"StreamingLineBuffer_21_out0_stream_11_\": " << stream_max_size[741] << ",\n";
    report_file << "		\"StreamingLineBuffer_21_out0_stream_prepad_0_\": " << stream_max_size[742] << ",\n";
    report_file << "		\"StreamingLineBuffer_21_out0_stream_prepad_1_\": " << stream_max_size[743] << ",\n";
    report_file << "		\"StreamingLineBuffer_21_out0_stream_prepad_2_\": " << stream_max_size[744] << ",\n";
    report_file << "		\"StreamingLineBuffer_21_out0_stream_prepad_3_\": " << stream_max_size[745] << ",\n";
    report_file << "		\"StreamingLineBuffer_21_out0_stream_prepad_4_\": " << stream_max_size[746] << ",\n";
    report_file << "		\"StreamingLineBuffer_21_out0_stream_prepad_5_\": " << stream_max_size[747] << ",\n";
    report_file << "		\"StreamingLineBuffer_21_out0_stream_prepad_6_\": " << stream_max_size[748] << ",\n";
    report_file << "		\"StreamingLineBuffer_21_out0_stream_prepad_7_\": " << stream_max_size[749] << ",\n";
    report_file << "		\"StreamingLineBuffer_21_out0_stream_prepad_8_\": " << stream_max_size[750] << ",\n";
    report_file << "		\"StreamingLineBuffer_21_out0_stream_prepad_9_\": " << stream_max_size[751] << ",\n";
    report_file << "		\"StreamingLineBuffer_21_out0_stream_prepad_10_\": " << stream_max_size[752] << ",\n";
    report_file << "		\"StreamingLineBuffer_21_out0_stream_prepad_11_\": " << stream_max_size[753] << ",\n";
    report_file << "		\"StreamingLineBuffer_21_buffer_stream_0_\": " << stream_max_size[754] << ",\n";
    report_file << "		\"StreamingLineBuffer_21_buffer_stream_1_\": " << stream_max_size[755] << ",\n";
    report_file << "		\"StreamingLineBuffer_21_buffer_stream_2_\": " << stream_max_size[756] << ",\n";
    report_file << "		\"StreamingLineBuffer_21_buffer_stream_3_\": " << stream_max_size[757] << ",\n";
    report_file << "		\"StreamingLineBuffer_21_buffer_stream_4_\": " << stream_max_size[758] << ",\n";
    report_file << "		\"StreamingLineBuffer_21_buffer_stream_5_\": " << stream_max_size[759] << ",\n";
    report_file << "		\"StreamingLineBuffer_21_buffer_stream_6_\": " << stream_max_size[760] << ",\n";
    report_file << "		\"StreamingLineBuffer_21_buffer_stream_7_\": " << stream_max_size[761] << ",\n";
    report_file << "		\"StreamingLineBuffer_21_buffer_stream_8_\": " << stream_max_size[762] << ",\n";
    report_file << "		\"StreamingLineBuffer_21_buffer_stream_9_\": " << stream_max_size[763] << ",\n";
    report_file << "		\"StreamingMemory_77_out0_stream_0_\": " << stream_max_size[764] << ",\n";
    report_file << "		\"StreamingMemory_77_out1_stream_0_\": " << stream_max_size[765] << ",\n";
    report_file << "		\"StreamingDepthwiseConv_7_out0_stream_0_\": " << stream_max_size[766] << ",\n";
    report_file << "		\"StreamingDepthwiseConv_7_out0_stream_1_\": " << stream_max_size[767] << ",\n";
    report_file << "		\"StreamingMemory_78_out0_stream_0_\": " << stream_max_size[768] << ",\n";
    report_file << "		\"StreamingMemory_78_out1_stream_0_\": " << stream_max_size[769] << ",\n";
    report_file << "		\"BandwidthAdjustIncreaseChannels_13_out0_stream_0_\": " << stream_max_size[770] << ",\n";
    report_file << "		\"BandwidthAdjustIncreaseChannels_13_out0_stream_1_\": " << stream_max_size[771] << ",\n";
    report_file << "		\"StreamingMemory_79_out0_stream_0_\": " << stream_max_size[772] << ",\n";
    report_file << "		\"StreamingMemory_79_out1_stream_0_\": " << stream_max_size[773] << ",\n";
    report_file << "		\"StreamingLineBuffer_22_out0_stream_0_\": " << stream_max_size[774] << ",\n";
    report_file << "		\"StreamingLineBuffer_22_out0_stream_1_\": " << stream_max_size[775] << ",\n";
    report_file << "		\"StreamingMemory_80_out0_stream_0_\": " << stream_max_size[776] << ",\n";
    report_file << "		\"StreamingMemory_80_out0_stream_1_\": " << stream_max_size[777] << ",\n";
    report_file << "		\"StreamingMemory_80_out0_stream_2_\": " << stream_max_size[778] << ",\n";
    report_file << "		\"StreamingMemory_80_out0_stream_3_\": " << stream_max_size[779] << ",\n";
    report_file << "		\"StreamingMemory_80_out0_stream_4_\": " << stream_max_size[780] << ",\n";
    report_file << "		\"StreamingMemory_80_out0_stream_5_\": " << stream_max_size[781] << ",\n";
    report_file << "		\"StreamingMemory_80_out0_stream_6_\": " << stream_max_size[782] << ",\n";
    report_file << "		\"StreamingMemory_80_out0_stream_7_\": " << stream_max_size[783] << ",\n";
    report_file << "		\"StreamingMemory_80_out0_stream_8_\": " << stream_max_size[784] << ",\n";
    report_file << "		\"StreamingMemory_80_out1_stream_0_\": " << stream_max_size[785] << ",\n";
    report_file << "		\"StreamingConv_15_out0_stream_0_\": " << stream_max_size[786] << ",\n";
    report_file << "		\"StreamingConv_15_out0_stream_1_\": " << stream_max_size[787] << ",\n";
    report_file << "		\"StreamingMemory_81_out0_stream_0_\": " << stream_max_size[788] << ",\n";
    report_file << "		\"StreamingMemory_81_out1_stream_0_\": " << stream_max_size[789] << ",\n";
    report_file << "		\"StreamingAdd_3_out0_stream_0_\": " << stream_max_size[790] << ",\n";
    report_file << "		\"StreamingAdd_3_out0_stream_1_\": " << stream_max_size[791] << ",\n";
    report_file << "		\"StreamingMemory_82_out0_stream_0_\": " << stream_max_size[792] << ",\n";
    report_file << "		\"StreamingMemory_82_out1_stream_0_\": " << stream_max_size[793] << ",\n";
    report_file << "		\"BandwidthAdjustDecreaseStreams_4_out0_stream_0_\": " << stream_max_size[794] << ",\n";
    report_file << "		\"StreamingMemory_83_out0_stream_0_\": " << stream_max_size[795] << ",\n";
    report_file << "		\"StreamingMemory_83_out1_stream_0_\": " << stream_max_size[796] << ",\n";
    report_file << "		\"TensorDuplicator_4_out0_stream_0_\": " << stream_max_size[797] << ",\n";
    report_file << "		\"TensorDuplicator_4_out1_stream_0_\": " << stream_max_size[798] << ",\n";
    report_file << "		\"StreamingMemory_84_out0_stream_0_\": " << stream_max_size[799] << ",\n";
    report_file << "		\"StreamingMemory_84_out1_stream_0_\": " << stream_max_size[800] << ",\n";
    report_file << "		\"BandwidthAdjustIncreaseStreams_4_out0_stream_0_\": " << stream_max_size[801] << ",\n";
    report_file << "		\"BandwidthAdjustIncreaseStreams_4_out0_stream_1_\": " << stream_max_size[802] << ",\n";
    report_file << "		\"BandwidthAdjustIncreaseStreams_5_out0_stream_0_\": " << stream_max_size[803] << ",\n";
    report_file << "		\"BandwidthAdjustIncreaseStreams_5_out0_stream_1_\": " << stream_max_size[804] << ",\n";
    report_file << "		\"StreamingMemory_85_out0_stream_0_\": " << stream_max_size[805] << ",\n";
    report_file << "		\"StreamingMemory_85_out1_stream_0_\": " << stream_max_size[806] << ",\n";
    report_file << "		\"StreamingLineBuffer_23_out0_stream_0_\": " << stream_max_size[807] << ",\n";
    report_file << "		\"StreamingLineBuffer_23_out0_stream_1_\": " << stream_max_size[808] << ",\n";
    report_file << "		\"StreamingMemory_86_out0_stream_0_\": " << stream_max_size[809] << ",\n";
    report_file << "		\"StreamingMemory_86_out0_stream_1_\": " << stream_max_size[810] << ",\n";
    report_file << "		\"StreamingMemory_86_out0_stream_2_\": " << stream_max_size[811] << ",\n";
    report_file << "		\"StreamingMemory_86_out0_stream_3_\": " << stream_max_size[812] << ",\n";
    report_file << "		\"StreamingMemory_86_out0_stream_4_\": " << stream_max_size[813] << ",\n";
    report_file << "		\"StreamingMemory_86_out0_stream_5_\": " << stream_max_size[814] << ",\n";
    report_file << "		\"StreamingMemory_86_out0_stream_6_\": " << stream_max_size[815] << ",\n";
    report_file << "		\"StreamingMemory_86_out0_stream_7_\": " << stream_max_size[816] << ",\n";
    report_file << "		\"StreamingMemory_86_out0_stream_8_\": " << stream_max_size[817] << ",\n";
    report_file << "		\"StreamingMemory_86_out1_stream_0_\": " << stream_max_size[818] << ",\n";
    report_file << "		\"StreamingConv_16_out0_stream_0_\": " << stream_max_size[819] << ",\n";
    report_file << "		\"StreamingConv_16_out0_stream_1_\": " << stream_max_size[820] << ",\n";
    report_file << "		\"StreamingMemory_87_out0_stream_0_\": " << stream_max_size[821] << ",\n";
    report_file << "		\"StreamingMemory_87_out1_stream_0_\": " << stream_max_size[822] << ",\n";
    report_file << "		\"BandwidthAdjustDecreaseChannels_9_out0_stream_0_\": " << stream_max_size[823] << ",\n";
    report_file << "		\"BandwidthAdjustDecreaseChannels_9_out0_stream_1_\": " << stream_max_size[824] << ",\n";
    report_file << "		\"StreamingMemory_88_out0_stream_0_\": " << stream_max_size[825] << ",\n";
    report_file << "		\"StreamingMemory_88_out1_stream_0_\": " << stream_max_size[826] << ",\n";
    report_file << "		\"StreamingLineBuffer_24_out0_stream_0_\": " << stream_max_size[827] << ",\n";
    report_file << "		\"StreamingLineBuffer_24_out0_stream_1_\": " << stream_max_size[828] << ",\n";
    report_file << "		\"StreamingLineBuffer_24_out0_stream_2_\": " << stream_max_size[829] << ",\n";
    report_file << "		\"StreamingLineBuffer_24_out0_stream_3_\": " << stream_max_size[830] << ",\n";
    report_file << "		\"StreamingLineBuffer_24_out0_stream_4_\": " << stream_max_size[831] << ",\n";
    report_file << "		\"StreamingLineBuffer_24_out0_stream_5_\": " << stream_max_size[832] << ",\n";
    report_file << "		\"StreamingLineBuffer_24_out0_stream_6_\": " << stream_max_size[833] << ",\n";
    report_file << "		\"StreamingLineBuffer_24_out0_stream_7_\": " << stream_max_size[834] << ",\n";
    report_file << "		\"StreamingLineBuffer_24_out0_stream_8_\": " << stream_max_size[835] << ",\n";
    report_file << "		\"StreamingLineBuffer_24_out0_stream_9_\": " << stream_max_size[836] << ",\n";
    report_file << "		\"StreamingLineBuffer_24_out0_stream_10_\": " << stream_max_size[837] << ",\n";
    report_file << "		\"StreamingLineBuffer_24_out0_stream_11_\": " << stream_max_size[838] << ",\n";
    report_file << "		\"StreamingLineBuffer_24_out0_stream_prepad_0_\": " << stream_max_size[839] << ",\n";
    report_file << "		\"StreamingLineBuffer_24_out0_stream_prepad_1_\": " << stream_max_size[840] << ",\n";
    report_file << "		\"StreamingLineBuffer_24_out0_stream_prepad_2_\": " << stream_max_size[841] << ",\n";
    report_file << "		\"StreamingLineBuffer_24_out0_stream_prepad_3_\": " << stream_max_size[842] << ",\n";
    report_file << "		\"StreamingLineBuffer_24_out0_stream_prepad_4_\": " << stream_max_size[843] << ",\n";
    report_file << "		\"StreamingLineBuffer_24_out0_stream_prepad_5_\": " << stream_max_size[844] << ",\n";
    report_file << "		\"StreamingLineBuffer_24_out0_stream_prepad_6_\": " << stream_max_size[845] << ",\n";
    report_file << "		\"StreamingLineBuffer_24_out0_stream_prepad_7_\": " << stream_max_size[846] << ",\n";
    report_file << "		\"StreamingLineBuffer_24_out0_stream_prepad_8_\": " << stream_max_size[847] << ",\n";
    report_file << "		\"StreamingLineBuffer_24_out0_stream_prepad_9_\": " << stream_max_size[848] << ",\n";
    report_file << "		\"StreamingLineBuffer_24_out0_stream_prepad_10_\": " << stream_max_size[849] << ",\n";
    report_file << "		\"StreamingLineBuffer_24_out0_stream_prepad_11_\": " << stream_max_size[850] << ",\n";
    report_file << "		\"StreamingLineBuffer_24_buffer_stream_0_\": " << stream_max_size[851] << ",\n";
    report_file << "		\"StreamingLineBuffer_24_buffer_stream_1_\": " << stream_max_size[852] << ",\n";
    report_file << "		\"StreamingLineBuffer_24_buffer_stream_2_\": " << stream_max_size[853] << ",\n";
    report_file << "		\"StreamingLineBuffer_24_buffer_stream_3_\": " << stream_max_size[854] << ",\n";
    report_file << "		\"StreamingLineBuffer_24_buffer_stream_4_\": " << stream_max_size[855] << ",\n";
    report_file << "		\"StreamingLineBuffer_24_buffer_stream_5_\": " << stream_max_size[856] << ",\n";
    report_file << "		\"StreamingLineBuffer_24_buffer_stream_6_\": " << stream_max_size[857] << ",\n";
    report_file << "		\"StreamingLineBuffer_24_buffer_stream_7_\": " << stream_max_size[858] << ",\n";
    report_file << "		\"StreamingLineBuffer_24_buffer_stream_8_\": " << stream_max_size[859] << ",\n";
    report_file << "		\"StreamingLineBuffer_24_buffer_stream_9_\": " << stream_max_size[860] << ",\n";
    report_file << "		\"StreamingMemory_89_out0_stream_0_\": " << stream_max_size[861] << ",\n";
    report_file << "		\"StreamingMemory_89_out1_stream_0_\": " << stream_max_size[862] << ",\n";
    report_file << "		\"StreamingDepthwiseConv_8_out0_stream_0_\": " << stream_max_size[863] << ",\n";
    report_file << "		\"StreamingDepthwiseConv_8_out0_stream_1_\": " << stream_max_size[864] << ",\n";
    report_file << "		\"StreamingMemory_90_out0_stream_0_\": " << stream_max_size[865] << ",\n";
    report_file << "		\"StreamingMemory_90_out1_stream_0_\": " << stream_max_size[866] << ",\n";
    report_file << "		\"BandwidthAdjustIncreaseChannels_14_out0_stream_0_\": " << stream_max_size[867] << ",\n";
    report_file << "		\"BandwidthAdjustIncreaseChannels_14_out0_stream_1_\": " << stream_max_size[868] << ",\n";
    report_file << "		\"StreamingMemory_91_out0_stream_0_\": " << stream_max_size[869] << ",\n";
    report_file << "		\"StreamingMemory_91_out1_stream_0_\": " << stream_max_size[870] << ",\n";
    report_file << "		\"StreamingLineBuffer_25_out0_stream_0_\": " << stream_max_size[871] << ",\n";
    report_file << "		\"StreamingLineBuffer_25_out0_stream_1_\": " << stream_max_size[872] << ",\n";
    report_file << "		\"StreamingMemory_92_out0_stream_0_\": " << stream_max_size[873] << ",\n";
    report_file << "		\"StreamingMemory_92_out0_stream_1_\": " << stream_max_size[874] << ",\n";
    report_file << "		\"StreamingMemory_92_out0_stream_2_\": " << stream_max_size[875] << ",\n";
    report_file << "		\"StreamingMemory_92_out0_stream_3_\": " << stream_max_size[876] << ",\n";
    report_file << "		\"StreamingMemory_92_out0_stream_4_\": " << stream_max_size[877] << ",\n";
    report_file << "		\"StreamingMemory_92_out0_stream_5_\": " << stream_max_size[878] << ",\n";
    report_file << "		\"StreamingMemory_92_out0_stream_6_\": " << stream_max_size[879] << ",\n";
    report_file << "		\"StreamingMemory_92_out0_stream_7_\": " << stream_max_size[880] << ",\n";
    report_file << "		\"StreamingMemory_92_out0_stream_8_\": " << stream_max_size[881] << ",\n";
    report_file << "		\"StreamingMemory_92_out1_stream_0_\": " << stream_max_size[882] << ",\n";
    report_file << "		\"StreamingConv_17_out0_stream_0_\": " << stream_max_size[883] << ",\n";
    report_file << "		\"StreamingConv_17_out0_stream_1_\": " << stream_max_size[884] << ",\n";
    report_file << "		\"StreamingMemory_93_out0_stream_0_\": " << stream_max_size[885] << ",\n";
    report_file << "		\"StreamingMemory_93_out1_stream_0_\": " << stream_max_size[886] << ",\n";
    report_file << "		\"StreamingAdd_4_out0_stream_0_\": " << stream_max_size[887] << ",\n";
    report_file << "		\"StreamingAdd_4_out0_stream_1_\": " << stream_max_size[888] << ",\n";
    report_file << "		\"StreamingMemory_94_out0_stream_0_\": " << stream_max_size[889] << ",\n";
    report_file << "		\"StreamingMemory_94_out1_stream_0_\": " << stream_max_size[890] << ",\n";
    report_file << "		\"BandwidthAdjustDecreaseStreams_5_out0_stream_0_\": " << stream_max_size[891] << ",\n";
    report_file << "		\"StreamingMemory_95_out0_stream_0_\": " << stream_max_size[892] << ",\n";
    report_file << "		\"StreamingMemory_95_out1_stream_0_\": " << stream_max_size[893] << ",\n";
    report_file << "		\"TensorDuplicator_5_out0_stream_0_\": " << stream_max_size[894] << ",\n";
    report_file << "		\"TensorDuplicator_5_out1_stream_0_\": " << stream_max_size[895] << ",\n";
    report_file << "		\"StreamingMemory_96_out0_stream_0_\": " << stream_max_size[896] << ",\n";
    report_file << "		\"StreamingMemory_96_out1_stream_0_\": " << stream_max_size[897] << ",\n";
    report_file << "		\"BandwidthAdjustIncreaseStreams_6_out0_stream_0_\": " << stream_max_size[898] << ",\n";
    report_file << "		\"BandwidthAdjustIncreaseStreams_6_out0_stream_1_\": " << stream_max_size[899] << ",\n";
    report_file << "		\"BandwidthAdjustIncreaseStreams_7_out0_stream_0_\": " << stream_max_size[900] << ",\n";
    report_file << "		\"BandwidthAdjustIncreaseStreams_7_out0_stream_1_\": " << stream_max_size[901] << ",\n";
    report_file << "		\"StreamingMemory_97_out0_stream_0_\": " << stream_max_size[902] << ",\n";
    report_file << "		\"StreamingMemory_97_out1_stream_0_\": " << stream_max_size[903] << ",\n";
    report_file << "		\"StreamingLineBuffer_26_out0_stream_0_\": " << stream_max_size[904] << ",\n";
    report_file << "		\"StreamingLineBuffer_26_out0_stream_1_\": " << stream_max_size[905] << ",\n";
    report_file << "		\"StreamingMemory_98_out0_stream_0_\": " << stream_max_size[906] << ",\n";
    report_file << "		\"StreamingMemory_98_out0_stream_1_\": " << stream_max_size[907] << ",\n";
    report_file << "		\"StreamingMemory_98_out0_stream_2_\": " << stream_max_size[908] << ",\n";
    report_file << "		\"StreamingMemory_98_out0_stream_3_\": " << stream_max_size[909] << ",\n";
    report_file << "		\"StreamingMemory_98_out0_stream_4_\": " << stream_max_size[910] << ",\n";
    report_file << "		\"StreamingMemory_98_out0_stream_5_\": " << stream_max_size[911] << ",\n";
    report_file << "		\"StreamingMemory_98_out0_stream_6_\": " << stream_max_size[912] << ",\n";
    report_file << "		\"StreamingMemory_98_out0_stream_7_\": " << stream_max_size[913] << ",\n";
    report_file << "		\"StreamingMemory_98_out0_stream_8_\": " << stream_max_size[914] << ",\n";
    report_file << "		\"StreamingMemory_98_out1_stream_0_\": " << stream_max_size[915] << ",\n";
    report_file << "		\"StreamingConv_18_out0_stream_0_\": " << stream_max_size[916] << ",\n";
    report_file << "		\"StreamingConv_18_out0_stream_1_\": " << stream_max_size[917] << ",\n";
    report_file << "		\"StreamingMemory_99_out0_stream_0_\": " << stream_max_size[918] << ",\n";
    report_file << "		\"StreamingMemory_99_out1_stream_0_\": " << stream_max_size[919] << ",\n";
    report_file << "		\"BandwidthAdjustDecreaseChannels_10_out0_stream_0_\": " << stream_max_size[920] << ",\n";
    report_file << "		\"BandwidthAdjustDecreaseChannels_10_out0_stream_1_\": " << stream_max_size[921] << ",\n";
    report_file << "		\"StreamingMemory_100_out0_stream_0_\": " << stream_max_size[922] << ",\n";
    report_file << "		\"StreamingMemory_100_out1_stream_0_\": " << stream_max_size[923] << ",\n";
    report_file << "		\"StreamingLineBuffer_27_out0_stream_0_\": " << stream_max_size[924] << ",\n";
    report_file << "		\"StreamingLineBuffer_27_out0_stream_1_\": " << stream_max_size[925] << ",\n";
    report_file << "		\"StreamingLineBuffer_27_out0_stream_2_\": " << stream_max_size[926] << ",\n";
    report_file << "		\"StreamingLineBuffer_27_out0_stream_3_\": " << stream_max_size[927] << ",\n";
    report_file << "		\"StreamingLineBuffer_27_out0_stream_4_\": " << stream_max_size[928] << ",\n";
    report_file << "		\"StreamingLineBuffer_27_out0_stream_5_\": " << stream_max_size[929] << ",\n";
    report_file << "		\"StreamingLineBuffer_27_out0_stream_6_\": " << stream_max_size[930] << ",\n";
    report_file << "		\"StreamingLineBuffer_27_out0_stream_7_\": " << stream_max_size[931] << ",\n";
    report_file << "		\"StreamingLineBuffer_27_out0_stream_8_\": " << stream_max_size[932] << ",\n";
    report_file << "		\"StreamingLineBuffer_27_out0_stream_9_\": " << stream_max_size[933] << ",\n";
    report_file << "		\"StreamingLineBuffer_27_out0_stream_10_\": " << stream_max_size[934] << ",\n";
    report_file << "		\"StreamingLineBuffer_27_out0_stream_11_\": " << stream_max_size[935] << ",\n";
    report_file << "		\"StreamingLineBuffer_27_out0_stream_prepad_0_\": " << stream_max_size[936] << ",\n";
    report_file << "		\"StreamingLineBuffer_27_out0_stream_prepad_1_\": " << stream_max_size[937] << ",\n";
    report_file << "		\"StreamingLineBuffer_27_out0_stream_prepad_2_\": " << stream_max_size[938] << ",\n";
    report_file << "		\"StreamingLineBuffer_27_out0_stream_prepad_3_\": " << stream_max_size[939] << ",\n";
    report_file << "		\"StreamingLineBuffer_27_out0_stream_prepad_4_\": " << stream_max_size[940] << ",\n";
    report_file << "		\"StreamingLineBuffer_27_out0_stream_prepad_5_\": " << stream_max_size[941] << ",\n";
    report_file << "		\"StreamingLineBuffer_27_out0_stream_prepad_6_\": " << stream_max_size[942] << ",\n";
    report_file << "		\"StreamingLineBuffer_27_out0_stream_prepad_7_\": " << stream_max_size[943] << ",\n";
    report_file << "		\"StreamingLineBuffer_27_out0_stream_prepad_8_\": " << stream_max_size[944] << ",\n";
    report_file << "		\"StreamingLineBuffer_27_out0_stream_prepad_9_\": " << stream_max_size[945] << ",\n";
    report_file << "		\"StreamingLineBuffer_27_out0_stream_prepad_10_\": " << stream_max_size[946] << ",\n";
    report_file << "		\"StreamingLineBuffer_27_out0_stream_prepad_11_\": " << stream_max_size[947] << ",\n";
    report_file << "		\"StreamingLineBuffer_27_buffer_stream_0_\": " << stream_max_size[948] << ",\n";
    report_file << "		\"StreamingLineBuffer_27_buffer_stream_1_\": " << stream_max_size[949] << ",\n";
    report_file << "		\"StreamingLineBuffer_27_buffer_stream_2_\": " << stream_max_size[950] << ",\n";
    report_file << "		\"StreamingLineBuffer_27_buffer_stream_3_\": " << stream_max_size[951] << ",\n";
    report_file << "		\"StreamingLineBuffer_27_buffer_stream_4_\": " << stream_max_size[952] << ",\n";
    report_file << "		\"StreamingLineBuffer_27_buffer_stream_5_\": " << stream_max_size[953] << ",\n";
    report_file << "		\"StreamingLineBuffer_27_buffer_stream_6_\": " << stream_max_size[954] << ",\n";
    report_file << "		\"StreamingLineBuffer_27_buffer_stream_7_\": " << stream_max_size[955] << ",\n";
    report_file << "		\"StreamingLineBuffer_27_buffer_stream_8_\": " << stream_max_size[956] << ",\n";
    report_file << "		\"StreamingLineBuffer_27_buffer_stream_9_\": " << stream_max_size[957] << ",\n";
    report_file << "		\"StreamingMemory_101_out0_stream_0_\": " << stream_max_size[958] << ",\n";
    report_file << "		\"StreamingMemory_101_out1_stream_0_\": " << stream_max_size[959] << ",\n";
    report_file << "		\"StreamingDepthwiseConv_9_out0_stream_0_\": " << stream_max_size[960] << ",\n";
    report_file << "		\"StreamingDepthwiseConv_9_out0_stream_1_\": " << stream_max_size[961] << ",\n";
    report_file << "		\"StreamingMemory_102_out0_stream_0_\": " << stream_max_size[962] << ",\n";
    report_file << "		\"StreamingMemory_102_out1_stream_0_\": " << stream_max_size[963] << ",\n";
    report_file << "		\"BandwidthAdjustIncreaseChannels_15_out0_stream_0_\": " << stream_max_size[964] << ",\n";
    report_file << "		\"BandwidthAdjustIncreaseChannels_15_out0_stream_1_\": " << stream_max_size[965] << ",\n";
    report_file << "		\"StreamingMemory_103_out0_stream_0_\": " << stream_max_size[966] << ",\n";
    report_file << "		\"StreamingMemory_103_out1_stream_0_\": " << stream_max_size[967] << ",\n";
    report_file << "		\"StreamingLineBuffer_28_out0_stream_0_\": " << stream_max_size[968] << ",\n";
    report_file << "		\"StreamingLineBuffer_28_out0_stream_1_\": " << stream_max_size[969] << ",\n";
    report_file << "		\"StreamingMemory_104_out0_stream_0_\": " << stream_max_size[970] << ",\n";
    report_file << "		\"StreamingMemory_104_out1_stream_0_\": " << stream_max_size[971] << ",\n";
    report_file << "		\"StreamingConv_19_out0_stream_0_\": " << stream_max_size[972] << ",\n";
    report_file << "		\"StreamingConv_19_out0_stream_1_\": " << stream_max_size[973] << ",\n";
    report_file << "		\"StreamingMemory_105_out0_stream_0_\": " << stream_max_size[974] << ",\n";
    report_file << "		\"StreamingAdd_5_out0_stream_0_\": " << stream_max_size[975] << ",\n";
    report_file << "		\"StreamingAdd_5_out0_stream_1_\": " << stream_max_size[976] << ",\n";
    report_file << "		\"StreamingLineBuffer_29_out0_stream_0_\": " << stream_max_size[977] << ",\n";
    report_file << "		\"StreamingLineBuffer_29_out0_stream_1_\": " << stream_max_size[978] << ",\n";
    report_file << "		\"StreamingConv_20_out0_stream_0_\": " << stream_max_size[979] << ",\n";
    report_file << "		\"StreamingConv_20_out0_stream_1_\": " << stream_max_size[980] << ",\n";
    report_file << "		\"BandwidthAdjustDecreaseChannels_11_out0_stream_0_\": " << stream_max_size[981] << ",\n";
    report_file << "		\"BandwidthAdjustDecreaseChannels_11_out0_stream_1_\": " << stream_max_size[982] << ",\n";
    report_file << "		\"StreamingLineBuffer_30_out0_stream_0_\": " << stream_max_size[983] << ",\n";
    report_file << "		\"StreamingLineBuffer_30_out0_stream_1_\": " << stream_max_size[984] << ",\n";
    report_file << "		\"StreamingLineBuffer_30_out0_stream_2_\": " << stream_max_size[985] << ",\n";
    report_file << "		\"StreamingLineBuffer_30_out0_stream_3_\": " << stream_max_size[986] << ",\n";
    report_file << "		\"StreamingLineBuffer_30_out0_stream_4_\": " << stream_max_size[987] << ",\n";
    report_file << "		\"StreamingLineBuffer_30_out0_stream_5_\": " << stream_max_size[988] << ",\n";
    report_file << "		\"StreamingLineBuffer_30_out0_stream_6_\": " << stream_max_size[989] << ",\n";
    report_file << "		\"StreamingLineBuffer_30_out0_stream_7_\": " << stream_max_size[990] << ",\n";
    report_file << "		\"StreamingLineBuffer_30_out0_stream_8_\": " << stream_max_size[991] << ",\n";
    report_file << "		\"StreamingLineBuffer_30_out0_stream_9_\": " << stream_max_size[992] << ",\n";
    report_file << "		\"StreamingLineBuffer_30_out0_stream_10_\": " << stream_max_size[993] << ",\n";
    report_file << "		\"StreamingLineBuffer_30_out0_stream_11_\": " << stream_max_size[994] << ",\n";
    report_file << "		\"StreamingLineBuffer_30_out0_stream_prepad_0_\": " << stream_max_size[995] << ",\n";
    report_file << "		\"StreamingLineBuffer_30_out0_stream_prepad_1_\": " << stream_max_size[996] << ",\n";
    report_file << "		\"StreamingLineBuffer_30_out0_stream_prepad_2_\": " << stream_max_size[997] << ",\n";
    report_file << "		\"StreamingLineBuffer_30_out0_stream_prepad_3_\": " << stream_max_size[998] << ",\n";
    report_file << "		\"StreamingLineBuffer_30_out0_stream_prepad_4_\": " << stream_max_size[999] << ",\n";
    report_file << "		\"StreamingLineBuffer_30_out0_stream_prepad_5_\": " << stream_max_size[1000] << ",\n";
    report_file << "		\"StreamingLineBuffer_30_out0_stream_prepad_6_\": " << stream_max_size[1001] << ",\n";
    report_file << "		\"StreamingLineBuffer_30_out0_stream_prepad_7_\": " << stream_max_size[1002] << ",\n";
    report_file << "		\"StreamingLineBuffer_30_out0_stream_prepad_8_\": " << stream_max_size[1003] << ",\n";
    report_file << "		\"StreamingLineBuffer_30_out0_stream_prepad_9_\": " << stream_max_size[1004] << ",\n";
    report_file << "		\"StreamingLineBuffer_30_out0_stream_prepad_10_\": " << stream_max_size[1005] << ",\n";
    report_file << "		\"StreamingLineBuffer_30_out0_stream_prepad_11_\": " << stream_max_size[1006] << ",\n";
    report_file << "		\"StreamingLineBuffer_30_buffer_stream_0_\": " << stream_max_size[1007] << ",\n";
    report_file << "		\"StreamingLineBuffer_30_buffer_stream_1_\": " << stream_max_size[1008] << ",\n";
    report_file << "		\"StreamingLineBuffer_30_buffer_stream_2_\": " << stream_max_size[1009] << ",\n";
    report_file << "		\"StreamingLineBuffer_30_buffer_stream_3_\": " << stream_max_size[1010] << ",\n";
    report_file << "		\"StreamingLineBuffer_30_buffer_stream_4_\": " << stream_max_size[1011] << ",\n";
    report_file << "		\"StreamingLineBuffer_30_buffer_stream_5_\": " << stream_max_size[1012] << ",\n";
    report_file << "		\"StreamingLineBuffer_30_buffer_stream_6_\": " << stream_max_size[1013] << ",\n";
    report_file << "		\"StreamingLineBuffer_30_buffer_stream_7_\": " << stream_max_size[1014] << ",\n";
    report_file << "		\"StreamingLineBuffer_30_buffer_stream_8_\": " << stream_max_size[1015] << ",\n";
    report_file << "		\"StreamingLineBuffer_30_buffer_stream_9_\": " << stream_max_size[1016] << ",\n";
    report_file << "		\"StreamingDepthwiseConv_10_out0_stream_0_\": " << stream_max_size[1017] << ",\n";
    report_file << "		\"StreamingDepthwiseConv_10_out0_stream_1_\": " << stream_max_size[1018] << ",\n";
    report_file << "		\"BandwidthAdjustIncreaseChannels_16_out0_stream_0_\": " << stream_max_size[1019] << ",\n";
    report_file << "		\"BandwidthAdjustIncreaseChannels_16_out0_stream_1_\": " << stream_max_size[1020] << ",\n";
    report_file << "		\"StreamingLineBuffer_31_out0_stream_0_\": " << stream_max_size[1021] << ",\n";
    report_file << "		\"StreamingLineBuffer_31_out0_stream_1_\": " << stream_max_size[1022] << ",\n";
    report_file << "		\"StreamingConv_21_out0_stream_0_\": " << stream_max_size[1023] << ",\n";
    report_file << "		\"StreamingConv_21_out0_stream_1_\": " << stream_max_size[1024] << ",\n";
    report_file << "		\"TensorDuplicator_6_out0_stream_0_\": " << stream_max_size[1025] << ",\n";
    report_file << "		\"TensorDuplicator_6_out0_stream_1_\": " << stream_max_size[1026] << ",\n";
    report_file << "		\"TensorDuplicator_6_out1_stream_0_\": " << stream_max_size[1027] << ",\n";
    report_file << "		\"TensorDuplicator_6_out1_stream_1_\": " << stream_max_size[1028] << ",\n";
    report_file << "		\"BandwidthAdjustDecreaseChannels_12_out0_stream_0_\": " << stream_max_size[1029] << ",\n";
    report_file << "		\"BandwidthAdjustDecreaseChannels_12_out0_stream_1_\": " << stream_max_size[1030] << ",\n";
    report_file << "		\"BandwidthAdjustIncreaseChannels_17_out0_stream_0_\": " << stream_max_size[1031] << ",\n";
    report_file << "		\"BandwidthAdjustIncreaseChannels_17_out0_stream_1_\": " << stream_max_size[1032] << ",\n";
    report_file << "		\"BandwidthAdjustDecreaseStreams_6_out0_stream_0_\": " << stream_max_size[1033] << ",\n";
    report_file << "		\"StreamingConv_22_out0_stream_0_\": " << stream_max_size[1034] << ",\n";
    report_file << "		\"BandwidthAdjustDecreaseChannels_13_out0_stream_0_\": " << stream_max_size[1035] << ",\n";
    report_file << "		\"StreamingLineBuffer_32_out0_stream_0_\": " << stream_max_size[1036] << ",\n";
    report_file << "		\"StreamingLineBuffer_32_out0_stream_1_\": " << stream_max_size[1037] << ",\n";
    report_file << "		\"StreamingLineBuffer_32_out0_stream_2_\": " << stream_max_size[1038] << ",\n";
    report_file << "		\"StreamingLineBuffer_32_out0_stream_3_\": " << stream_max_size[1039] << ",\n";
    report_file << "		\"StreamingLineBuffer_32_out0_stream_4_\": " << stream_max_size[1040] << ",\n";
    report_file << "		\"StreamingLineBuffer_32_out0_stream_5_\": " << stream_max_size[1041] << ",\n";
    report_file << "		\"StreamingLineBuffer_32_out0_stream_6_\": " << stream_max_size[1042] << ",\n";
    report_file << "		\"StreamingLineBuffer_32_out0_stream_7_\": " << stream_max_size[1043] << ",\n";
    report_file << "		\"StreamingLineBuffer_32_out0_stream_8_\": " << stream_max_size[1044] << ",\n";
    report_file << "		\"StreamingLineBuffer_32_out0_stream_prepad_0_\": " << stream_max_size[1045] << ",\n";
    report_file << "		\"StreamingLineBuffer_32_out0_stream_prepad_1_\": " << stream_max_size[1046] << ",\n";
    report_file << "		\"StreamingLineBuffer_32_out0_stream_prepad_2_\": " << stream_max_size[1047] << ",\n";
    report_file << "		\"StreamingLineBuffer_32_out0_stream_prepad_3_\": " << stream_max_size[1048] << ",\n";
    report_file << "		\"StreamingLineBuffer_32_out0_stream_prepad_4_\": " << stream_max_size[1049] << ",\n";
    report_file << "		\"StreamingLineBuffer_32_out0_stream_prepad_5_\": " << stream_max_size[1050] << ",\n";
    report_file << "		\"StreamingLineBuffer_32_out0_stream_prepad_6_\": " << stream_max_size[1051] << ",\n";
    report_file << "		\"StreamingLineBuffer_32_out0_stream_prepad_7_\": " << stream_max_size[1052] << ",\n";
    report_file << "		\"StreamingLineBuffer_32_out0_stream_prepad_8_\": " << stream_max_size[1053] << ",\n";
    report_file << "		\"StreamingLineBuffer_32_buffer_stream_0_\": " << stream_max_size[1054] << ",\n";
    report_file << "		\"StreamingLineBuffer_32_buffer_stream_1_\": " << stream_max_size[1055] << ",\n";
    report_file << "		\"StreamingLineBuffer_32_buffer_stream_2_\": " << stream_max_size[1056] << ",\n";
    report_file << "		\"StreamingLineBuffer_32_buffer_stream_3_\": " << stream_max_size[1057] << ",\n";
    report_file << "		\"StreamingLineBuffer_32_buffer_stream_4_\": " << stream_max_size[1058] << ",\n";
    report_file << "		\"StreamingLineBuffer_32_buffer_stream_5_\": " << stream_max_size[1059] << ",\n";
    report_file << "		\"StreamingLineBuffer_32_buffer_stream_6_\": " << stream_max_size[1060] << ",\n";
    report_file << "		\"StreamingLineBuffer_32_buffer_stream_7_\": " << stream_max_size[1061] << ",\n";
    report_file << "		\"StreamingDepthwiseConv_11_out0_stream_0_\": " << stream_max_size[1062] << ",\n";
    report_file << "		\"BandwidthAdjustIncreaseChannels_18_out0_stream_0_\": " << stream_max_size[1063] << ",\n";
    report_file << "		\"BandwidthAdjustIncreaseStreams_8_out0_stream_0_\": " << stream_max_size[1064] << ",\n";
    report_file << "		\"BandwidthAdjustIncreaseStreams_8_out0_stream_1_\": " << stream_max_size[1065] << ",\n";
    report_file << "		\"StreamingLineBuffer_33_out0_stream_0_\": " << stream_max_size[1066] << ",\n";
    report_file << "		\"StreamingLineBuffer_33_out0_stream_1_\": " << stream_max_size[1067] << ",\n";
    report_file << "		\"StreamingConv_23_out0_stream_0_\": " << stream_max_size[1068] << ",\n";
    report_file << "		\"StreamingConv_23_out0_stream_1_\": " << stream_max_size[1069] << ",\n";
    report_file << "		\"StreamingAdd_6_out0_stream_0_\": " << stream_max_size[1070] << ",\n";
    report_file << "		\"StreamingAdd_6_out0_stream_1_\": " << stream_max_size[1071] << ",\n";
    report_file << "		\"TensorDuplicator_7_out0_stream_0_\": " << stream_max_size[1072] << ",\n";
    report_file << "		\"TensorDuplicator_7_out0_stream_1_\": " << stream_max_size[1073] << ",\n";
    report_file << "		\"TensorDuplicator_7_out1_stream_0_\": " << stream_max_size[1074] << ",\n";
    report_file << "		\"TensorDuplicator_7_out1_stream_1_\": " << stream_max_size[1075] << ",\n";
    report_file << "		\"BandwidthAdjustDecreaseChannels_14_out0_stream_0_\": " << stream_max_size[1076] << ",\n";
    report_file << "		\"BandwidthAdjustDecreaseChannels_14_out0_stream_1_\": " << stream_max_size[1077] << ",\n";
    report_file << "		\"BandwidthAdjustIncreaseChannels_19_out0_stream_0_\": " << stream_max_size[1078] << ",\n";
    report_file << "		\"BandwidthAdjustIncreaseChannels_19_out0_stream_1_\": " << stream_max_size[1079] << ",\n";
    report_file << "		\"BandwidthAdjustDecreaseStreams_7_out0_stream_0_\": " << stream_max_size[1080] << ",\n";
    report_file << "		\"StreamingConv_24_out0_stream_0_\": " << stream_max_size[1081] << ",\n";
    report_file << "		\"BandwidthAdjustDecreaseChannels_15_out0_stream_0_\": " << stream_max_size[1082] << ",\n";
    report_file << "		\"StreamingLineBuffer_34_out0_stream_0_\": " << stream_max_size[1083] << ",\n";
    report_file << "		\"StreamingLineBuffer_34_out0_stream_1_\": " << stream_max_size[1084] << ",\n";
    report_file << "		\"StreamingLineBuffer_34_out0_stream_2_\": " << stream_max_size[1085] << ",\n";
    report_file << "		\"StreamingLineBuffer_34_out0_stream_3_\": " << stream_max_size[1086] << ",\n";
    report_file << "		\"StreamingLineBuffer_34_out0_stream_4_\": " << stream_max_size[1087] << ",\n";
    report_file << "		\"StreamingLineBuffer_34_out0_stream_5_\": " << stream_max_size[1088] << ",\n";
    report_file << "		\"StreamingLineBuffer_34_out0_stream_6_\": " << stream_max_size[1089] << ",\n";
    report_file << "		\"StreamingLineBuffer_34_out0_stream_7_\": " << stream_max_size[1090] << ",\n";
    report_file << "		\"StreamingLineBuffer_34_out0_stream_8_\": " << stream_max_size[1091] << ",\n";
    report_file << "		\"StreamingLineBuffer_34_out0_stream_prepad_0_\": " << stream_max_size[1092] << ",\n";
    report_file << "		\"StreamingLineBuffer_34_out0_stream_prepad_1_\": " << stream_max_size[1093] << ",\n";
    report_file << "		\"StreamingLineBuffer_34_out0_stream_prepad_2_\": " << stream_max_size[1094] << ",\n";
    report_file << "		\"StreamingLineBuffer_34_out0_stream_prepad_3_\": " << stream_max_size[1095] << ",\n";
    report_file << "		\"StreamingLineBuffer_34_out0_stream_prepad_4_\": " << stream_max_size[1096] << ",\n";
    report_file << "		\"StreamingLineBuffer_34_out0_stream_prepad_5_\": " << stream_max_size[1097] << ",\n";
    report_file << "		\"StreamingLineBuffer_34_out0_stream_prepad_6_\": " << stream_max_size[1098] << ",\n";
    report_file << "		\"StreamingLineBuffer_34_out0_stream_prepad_7_\": " << stream_max_size[1099] << ",\n";
    report_file << "		\"StreamingLineBuffer_34_out0_stream_prepad_8_\": " << stream_max_size[1100] << ",\n";
    report_file << "		\"StreamingLineBuffer_34_buffer_stream_0_\": " << stream_max_size[1101] << ",\n";
    report_file << "		\"StreamingLineBuffer_34_buffer_stream_1_\": " << stream_max_size[1102] << ",\n";
    report_file << "		\"StreamingLineBuffer_34_buffer_stream_2_\": " << stream_max_size[1103] << ",\n";
    report_file << "		\"StreamingLineBuffer_34_buffer_stream_3_\": " << stream_max_size[1104] << ",\n";
    report_file << "		\"StreamingLineBuffer_34_buffer_stream_4_\": " << stream_max_size[1105] << ",\n";
    report_file << "		\"StreamingLineBuffer_34_buffer_stream_5_\": " << stream_max_size[1106] << ",\n";
    report_file << "		\"StreamingLineBuffer_34_buffer_stream_6_\": " << stream_max_size[1107] << ",\n";
    report_file << "		\"StreamingLineBuffer_34_buffer_stream_7_\": " << stream_max_size[1108] << ",\n";
    report_file << "		\"StreamingDepthwiseConv_12_out0_stream_0_\": " << stream_max_size[1109] << ",\n";
    report_file << "		\"BandwidthAdjustIncreaseChannels_20_out0_stream_0_\": " << stream_max_size[1110] << ",\n";
    report_file << "		\"BandwidthAdjustIncreaseStreams_9_out0_stream_0_\": " << stream_max_size[1111] << ",\n";
    report_file << "		\"BandwidthAdjustIncreaseStreams_9_out0_stream_1_\": " << stream_max_size[1112] << ",\n";
    report_file << "		\"StreamingLineBuffer_35_out0_stream_0_\": " << stream_max_size[1113] << ",\n";
    report_file << "		\"StreamingLineBuffer_35_out0_stream_1_\": " << stream_max_size[1114] << ",\n";
    report_file << "		\"StreamingConv_25_out0_stream_0_\": " << stream_max_size[1115] << ",\n";
    report_file << "		\"StreamingConv_25_out0_stream_1_\": " << stream_max_size[1116] << ",\n";
    report_file << "		\"StreamingAdd_7_out0_stream_0_\": " << stream_max_size[1117] << ",\n";
    report_file << "		\"StreamingAdd_7_out0_stream_1_\": " << stream_max_size[1118] << ",\n";
    report_file << "		\"BandwidthAdjustDecreaseChannels_16_out0_stream_0_\": " << stream_max_size[1119] << ",\n";
    report_file << "		\"BandwidthAdjustDecreaseChannels_16_out0_stream_1_\": " << stream_max_size[1120] << ",\n";
    report_file << "		\"BandwidthAdjustIncreaseChannels_21_out0_stream_0_\": " << stream_max_size[1121] << ",\n";
    report_file << "		\"BandwidthAdjustIncreaseChannels_21_out0_stream_1_\": " << stream_max_size[1122] << ",\n";
    report_file << "		\"BandwidthAdjustDecreaseStreams_8_out0_stream_0_\": " << stream_max_size[1123] << ",\n";
    report_file << "		\"StreamingConv_26_out0_stream_0_\": " << stream_max_size[1124] << ",\n";
    report_file << "		\"BandwidthAdjustDecreaseChannels_17_out0_stream_0_\": " << stream_max_size[1125] << ",\n";
    report_file << "		\"StreamingLineBuffer_36_out0_stream_0_\": " << stream_max_size[1126] << ",\n";
    report_file << "		\"StreamingLineBuffer_36_out0_stream_1_\": " << stream_max_size[1127] << ",\n";
    report_file << "		\"StreamingLineBuffer_36_out0_stream_2_\": " << stream_max_size[1128] << ",\n";
    report_file << "		\"StreamingLineBuffer_36_out0_stream_3_\": " << stream_max_size[1129] << ",\n";
    report_file << "		\"StreamingLineBuffer_36_out0_stream_4_\": " << stream_max_size[1130] << ",\n";
    report_file << "		\"StreamingLineBuffer_36_out0_stream_5_\": " << stream_max_size[1131] << ",\n";
    report_file << "		\"StreamingLineBuffer_36_out0_stream_6_\": " << stream_max_size[1132] << ",\n";
    report_file << "		\"StreamingLineBuffer_36_out0_stream_7_\": " << stream_max_size[1133] << ",\n";
    report_file << "		\"StreamingLineBuffer_36_out0_stream_8_\": " << stream_max_size[1134] << ",\n";
    report_file << "		\"StreamingLineBuffer_36_out0_stream_prepad_0_\": " << stream_max_size[1135] << ",\n";
    report_file << "		\"StreamingLineBuffer_36_out0_stream_prepad_1_\": " << stream_max_size[1136] << ",\n";
    report_file << "		\"StreamingLineBuffer_36_out0_stream_prepad_2_\": " << stream_max_size[1137] << ",\n";
    report_file << "		\"StreamingLineBuffer_36_out0_stream_prepad_3_\": " << stream_max_size[1138] << ",\n";
    report_file << "		\"StreamingLineBuffer_36_out0_stream_prepad_4_\": " << stream_max_size[1139] << ",\n";
    report_file << "		\"StreamingLineBuffer_36_out0_stream_prepad_5_\": " << stream_max_size[1140] << ",\n";
    report_file << "		\"StreamingLineBuffer_36_out0_stream_prepad_6_\": " << stream_max_size[1141] << ",\n";
    report_file << "		\"StreamingLineBuffer_36_out0_stream_prepad_7_\": " << stream_max_size[1142] << ",\n";
    report_file << "		\"StreamingLineBuffer_36_out0_stream_prepad_8_\": " << stream_max_size[1143] << ",\n";
    report_file << "		\"StreamingLineBuffer_36_buffer_stream_0_\": " << stream_max_size[1144] << ",\n";
    report_file << "		\"StreamingLineBuffer_36_buffer_stream_1_\": " << stream_max_size[1145] << ",\n";
    report_file << "		\"StreamingLineBuffer_36_buffer_stream_2_\": " << stream_max_size[1146] << ",\n";
    report_file << "		\"StreamingLineBuffer_36_buffer_stream_3_\": " << stream_max_size[1147] << ",\n";
    report_file << "		\"StreamingLineBuffer_36_buffer_stream_4_\": " << stream_max_size[1148] << ",\n";
    report_file << "		\"StreamingLineBuffer_36_buffer_stream_5_\": " << stream_max_size[1149] << ",\n";
    report_file << "		\"StreamingLineBuffer_36_buffer_stream_6_\": " << stream_max_size[1150] << ",\n";
    report_file << "		\"StreamingLineBuffer_36_buffer_stream_7_\": " << stream_max_size[1151] << ",\n";
    report_file << "		\"StreamingDepthwiseConv_13_out0_stream_0_\": " << stream_max_size[1152] << ",\n";
    report_file << "		\"BandwidthAdjustIncreaseChannels_22_out0_stream_0_\": " << stream_max_size[1153] << ",\n";
    report_file << "		\"StreamingConv_27_out0_stream_0_\": " << stream_max_size[1154] << ",\n";
    report_file << "		\"TensorDuplicator_8_out0_stream_0_\": " << stream_max_size[1155] << ",\n";
    report_file << "		\"TensorDuplicator_8_out1_stream_0_\": " << stream_max_size[1156] << ",\n";
    report_file << "		\"BandwidthAdjustDecreaseChannels_18_out0_stream_0_\": " << stream_max_size[1157] << ",\n";
    report_file << "		\"BandwidthAdjustDecreaseChannels_19_out0_stream_0_\": " << stream_max_size[1158] << ",\n";
    report_file << "		\"BandwidthAdjustIncreaseChannels_23_out0_stream_0_\": " << stream_max_size[1159] << ",\n";
    report_file << "		\"StreamingConv_28_out0_stream_0_\": " << stream_max_size[1160] << ",\n";
    report_file << "		\"BandwidthAdjustDecreaseChannels_20_out0_stream_0_\": " << stream_max_size[1161] << ",\n";
    report_file << "		\"StreamingLineBuffer_37_out0_stream_0_\": " << stream_max_size[1162] << ",\n";
    report_file << "		\"StreamingLineBuffer_37_out0_stream_1_\": " << stream_max_size[1163] << ",\n";
    report_file << "		\"StreamingLineBuffer_37_out0_stream_2_\": " << stream_max_size[1164] << ",\n";
    report_file << "		\"StreamingLineBuffer_37_out0_stream_3_\": " << stream_max_size[1165] << ",\n";
    report_file << "		\"StreamingLineBuffer_37_out0_stream_4_\": " << stream_max_size[1166] << ",\n";
    report_file << "		\"StreamingLineBuffer_37_out0_stream_5_\": " << stream_max_size[1167] << ",\n";
    report_file << "		\"StreamingLineBuffer_37_out0_stream_6_\": " << stream_max_size[1168] << ",\n";
    report_file << "		\"StreamingLineBuffer_37_out0_stream_7_\": " << stream_max_size[1169] << ",\n";
    report_file << "		\"StreamingLineBuffer_37_out0_stream_8_\": " << stream_max_size[1170] << ",\n";
    report_file << "		\"StreamingLineBuffer_37_out0_stream_prepad_0_\": " << stream_max_size[1171] << ",\n";
    report_file << "		\"StreamingLineBuffer_37_out0_stream_prepad_1_\": " << stream_max_size[1172] << ",\n";
    report_file << "		\"StreamingLineBuffer_37_out0_stream_prepad_2_\": " << stream_max_size[1173] << ",\n";
    report_file << "		\"StreamingLineBuffer_37_out0_stream_prepad_3_\": " << stream_max_size[1174] << ",\n";
    report_file << "		\"StreamingLineBuffer_37_out0_stream_prepad_4_\": " << stream_max_size[1175] << ",\n";
    report_file << "		\"StreamingLineBuffer_37_out0_stream_prepad_5_\": " << stream_max_size[1176] << ",\n";
    report_file << "		\"StreamingLineBuffer_37_out0_stream_prepad_6_\": " << stream_max_size[1177] << ",\n";
    report_file << "		\"StreamingLineBuffer_37_out0_stream_prepad_7_\": " << stream_max_size[1178] << ",\n";
    report_file << "		\"StreamingLineBuffer_37_out0_stream_prepad_8_\": " << stream_max_size[1179] << ",\n";
    report_file << "		\"StreamingLineBuffer_37_buffer_stream_0_\": " << stream_max_size[1180] << ",\n";
    report_file << "		\"StreamingLineBuffer_37_buffer_stream_1_\": " << stream_max_size[1181] << ",\n";
    report_file << "		\"StreamingLineBuffer_37_buffer_stream_2_\": " << stream_max_size[1182] << ",\n";
    report_file << "		\"StreamingLineBuffer_37_buffer_stream_3_\": " << stream_max_size[1183] << ",\n";
    report_file << "		\"StreamingLineBuffer_37_buffer_stream_4_\": " << stream_max_size[1184] << ",\n";
    report_file << "		\"StreamingLineBuffer_37_buffer_stream_5_\": " << stream_max_size[1185] << ",\n";
    report_file << "		\"StreamingLineBuffer_37_buffer_stream_6_\": " << stream_max_size[1186] << ",\n";
    report_file << "		\"StreamingLineBuffer_37_buffer_stream_7_\": " << stream_max_size[1187] << ",\n";
    report_file << "		\"StreamingDepthwiseConv_14_out0_stream_0_\": " << stream_max_size[1188] << ",\n";
    report_file << "		\"BandwidthAdjustIncreaseChannels_24_out0_stream_0_\": " << stream_max_size[1189] << ",\n";
    report_file << "		\"StreamingConv_29_out0_stream_0_\": " << stream_max_size[1190] << ",\n";
    report_file << "		\"StreamingAdd_8_out0_stream_0_\": " << stream_max_size[1191] << ",\n";
    report_file << "		\"BandwidthAdjustIncreaseChannels_25_out0_stream_0_\": " << stream_max_size[1192] << ",\n";
    report_file << "		\"TensorDuplicator_9_out0_stream_0_\": " << stream_max_size[1193] << ",\n";
    report_file << "		\"TensorDuplicator_9_out1_stream_0_\": " << stream_max_size[1194] << ",\n";
    report_file << "		\"BandwidthAdjustIncreaseChannels_26_out0_stream_0_\": " << stream_max_size[1195] << ",\n";
    report_file << "		\"BandwidthAdjustDecreaseChannels_21_out0_stream_0_\": " << stream_max_size[1196] << ",\n";
    report_file << "		\"StreamingConv_30_out0_stream_0_\": " << stream_max_size[1197] << ",\n";
    report_file << "		\"BandwidthAdjustDecreaseChannels_22_out0_stream_0_\": " << stream_max_size[1198] << ",\n";
    report_file << "		\"StreamingLineBuffer_38_out0_stream_0_\": " << stream_max_size[1199] << ",\n";
    report_file << "		\"StreamingLineBuffer_38_out0_stream_1_\": " << stream_max_size[1200] << ",\n";
    report_file << "		\"StreamingLineBuffer_38_out0_stream_2_\": " << stream_max_size[1201] << ",\n";
    report_file << "		\"StreamingLineBuffer_38_out0_stream_3_\": " << stream_max_size[1202] << ",\n";
    report_file << "		\"StreamingLineBuffer_38_out0_stream_4_\": " << stream_max_size[1203] << ",\n";
    report_file << "		\"StreamingLineBuffer_38_out0_stream_5_\": " << stream_max_size[1204] << ",\n";
    report_file << "		\"StreamingLineBuffer_38_out0_stream_6_\": " << stream_max_size[1205] << ",\n";
    report_file << "		\"StreamingLineBuffer_38_out0_stream_7_\": " << stream_max_size[1206] << ",\n";
    report_file << "		\"StreamingLineBuffer_38_out0_stream_8_\": " << stream_max_size[1207] << ",\n";
    report_file << "		\"StreamingLineBuffer_38_out0_stream_prepad_0_\": " << stream_max_size[1208] << ",\n";
    report_file << "		\"StreamingLineBuffer_38_out0_stream_prepad_1_\": " << stream_max_size[1209] << ",\n";
    report_file << "		\"StreamingLineBuffer_38_out0_stream_prepad_2_\": " << stream_max_size[1210] << ",\n";
    report_file << "		\"StreamingLineBuffer_38_out0_stream_prepad_3_\": " << stream_max_size[1211] << ",\n";
    report_file << "		\"StreamingLineBuffer_38_out0_stream_prepad_4_\": " << stream_max_size[1212] << ",\n";
    report_file << "		\"StreamingLineBuffer_38_out0_stream_prepad_5_\": " << stream_max_size[1213] << ",\n";
    report_file << "		\"StreamingLineBuffer_38_out0_stream_prepad_6_\": " << stream_max_size[1214] << ",\n";
    report_file << "		\"StreamingLineBuffer_38_out0_stream_prepad_7_\": " << stream_max_size[1215] << ",\n";
    report_file << "		\"StreamingLineBuffer_38_out0_stream_prepad_8_\": " << stream_max_size[1216] << ",\n";
    report_file << "		\"StreamingLineBuffer_38_buffer_stream_0_\": " << stream_max_size[1217] << ",\n";
    report_file << "		\"StreamingLineBuffer_38_buffer_stream_1_\": " << stream_max_size[1218] << ",\n";
    report_file << "		\"StreamingLineBuffer_38_buffer_stream_2_\": " << stream_max_size[1219] << ",\n";
    report_file << "		\"StreamingLineBuffer_38_buffer_stream_3_\": " << stream_max_size[1220] << ",\n";
    report_file << "		\"StreamingLineBuffer_38_buffer_stream_4_\": " << stream_max_size[1221] << ",\n";
    report_file << "		\"StreamingLineBuffer_38_buffer_stream_5_\": " << stream_max_size[1222] << ",\n";
    report_file << "		\"StreamingLineBuffer_38_buffer_stream_6_\": " << stream_max_size[1223] << ",\n";
    report_file << "		\"StreamingLineBuffer_38_buffer_stream_7_\": " << stream_max_size[1224] << ",\n";
    report_file << "		\"StreamingDepthwiseConv_15_out0_stream_0_\": " << stream_max_size[1225] << ",\n";
    report_file << "		\"BandwidthAdjustIncreaseChannels_27_out0_stream_0_\": " << stream_max_size[1226] << ",\n";
    report_file << "		\"StreamingConv_31_out0_stream_0_\": " << stream_max_size[1227] << ",\n";
    report_file << "		\"StreamingAdd_9_out0_stream_0_\": " << stream_max_size[1228] << ",\n";
    report_file << "		\"BandwidthAdjustIncreaseChannels_28_out0_stream_0_\": " << stream_max_size[1229] << ",\n";
    report_file << "		\"StreamingConv_32_out0_stream_0_\": " << stream_max_size[1230] << ",\n";
    report_file << "		\"BandwidthAdjustDecreaseChannels_23_out0_stream_0_\": " << stream_max_size[1231] << ",\n";
    report_file << "		\"StreamingLineBuffer_39_out0_stream_0_\": " << stream_max_size[1232] << ",\n";
    report_file << "		\"StreamingLineBuffer_39_out0_stream_1_\": " << stream_max_size[1233] << ",\n";
    report_file << "		\"StreamingLineBuffer_39_out0_stream_2_\": " << stream_max_size[1234] << ",\n";
    report_file << "		\"StreamingLineBuffer_39_out0_stream_3_\": " << stream_max_size[1235] << ",\n";
    report_file << "		\"StreamingLineBuffer_39_out0_stream_4_\": " << stream_max_size[1236] << ",\n";
    report_file << "		\"StreamingLineBuffer_39_out0_stream_5_\": " << stream_max_size[1237] << ",\n";
    report_file << "		\"StreamingLineBuffer_39_out0_stream_6_\": " << stream_max_size[1238] << ",\n";
    report_file << "		\"StreamingLineBuffer_39_out0_stream_7_\": " << stream_max_size[1239] << ",\n";
    report_file << "		\"StreamingLineBuffer_39_out0_stream_8_\": " << stream_max_size[1240] << ",\n";
    report_file << "		\"StreamingLineBuffer_39_out0_stream_prepad_0_\": " << stream_max_size[1241] << ",\n";
    report_file << "		\"StreamingLineBuffer_39_out0_stream_prepad_1_\": " << stream_max_size[1242] << ",\n";
    report_file << "		\"StreamingLineBuffer_39_out0_stream_prepad_2_\": " << stream_max_size[1243] << ",\n";
    report_file << "		\"StreamingLineBuffer_39_out0_stream_prepad_3_\": " << stream_max_size[1244] << ",\n";
    report_file << "		\"StreamingLineBuffer_39_out0_stream_prepad_4_\": " << stream_max_size[1245] << ",\n";
    report_file << "		\"StreamingLineBuffer_39_out0_stream_prepad_5_\": " << stream_max_size[1246] << ",\n";
    report_file << "		\"StreamingLineBuffer_39_out0_stream_prepad_6_\": " << stream_max_size[1247] << ",\n";
    report_file << "		\"StreamingLineBuffer_39_out0_stream_prepad_7_\": " << stream_max_size[1248] << ",\n";
    report_file << "		\"StreamingLineBuffer_39_out0_stream_prepad_8_\": " << stream_max_size[1249] << ",\n";
    report_file << "		\"StreamingLineBuffer_39_buffer_stream_0_\": " << stream_max_size[1250] << ",\n";
    report_file << "		\"StreamingLineBuffer_39_buffer_stream_1_\": " << stream_max_size[1251] << ",\n";
    report_file << "		\"StreamingLineBuffer_39_buffer_stream_2_\": " << stream_max_size[1252] << ",\n";
    report_file << "		\"StreamingLineBuffer_39_buffer_stream_3_\": " << stream_max_size[1253] << ",\n";
    report_file << "		\"StreamingLineBuffer_39_buffer_stream_4_\": " << stream_max_size[1254] << ",\n";
    report_file << "		\"StreamingLineBuffer_39_buffer_stream_5_\": " << stream_max_size[1255] << ",\n";
    report_file << "		\"StreamingLineBuffer_39_buffer_stream_6_\": " << stream_max_size[1256] << ",\n";
    report_file << "		\"StreamingLineBuffer_39_buffer_stream_7_\": " << stream_max_size[1257] << ",\n";
    report_file << "		\"StreamingDepthwiseConv_16_out0_stream_0_\": " << stream_max_size[1258] << ",\n";
    report_file << "		\"BandwidthAdjustIncreaseChannels_29_out0_stream_0_\": " << stream_max_size[1259] << ",\n";
    report_file << "		\"StreamingConv_33_out0_stream_0_\": " << stream_max_size[1260] << ",\n";
    report_file << "		\"BandwidthAdjustIncreaseChannels_30_out0_stream_0_\": " << stream_max_size[1261] << ",\n";
    report_file << "		\"StreamingConv_34_out0_stream_0_\": " << stream_max_size[1262] << ",\n";
    report_file << "		\"BandwidthAdjustDecreaseChannels_24_out0_stream_0_\": " << stream_max_size[1263] << ",\n";
    report_file << "		\"StreamingGlobalAveragePool_0_out0_stream_0_\": " << stream_max_size[1264] << ",\n";
    report_file << "		\"BandwidthAdjustIncreaseChannels_31_out0_stream_0_\": " << stream_max_size[1265] << ",\n";
    report_file << "		\"StreamingConv_35_out0_stream_0_\": " << stream_max_size[1266] << "\n";
    report_file << "	},\n";
    report_file << "	\"Simulation cycles\": " << clock_cycle << ",\n";
    report_file << "	\"II\": " << actual_II << ",\n";
    report_file << "	\"Simulation time (ms)\": " << duration << "\n";
    report_file << "}\n";
    report_file.close();
}
