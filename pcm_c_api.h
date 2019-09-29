#ifndef __PCM_C_API_DEF_H
#define __PCM_C_API_DEF_H

// #include "cpucounters.h"

/* C wrappers */
#ifdef __cplusplus
extern "C" {
#endif

#include <stdint.h>

void init_pcm(void** pcm);
void* get_state();
double get_ipc(const void* before, const void* after);
double get_L3_hit_ratio(const void* before, const void* after);
double get_L2_hit_ratio(const void* before, const void* after);
double get_bytes_read_MC(const void* before, const void* after);
double get_exec_usage(const void* before, const void* after);
double get_local_memory_bw(const void* before, const void* after);

#ifdef __cplusplus
}
#endif
#endif