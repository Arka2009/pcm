#ifndef __PCM_C_API_DEF_H
#define __PCM_C_API_DEF_H

// #include "cpucounters.h"

/* C wrappers */
#ifdef __cplusplus
extern "C" {
#endif

#include <stdint.h>

/* Static parameters of the host */
typedef struct __host_params2 {
    uint64_t nominal_frequency;
    uint32_t max_ipc;
    uint32_t num_lprocs;
    uint32_t lprocs_per_core;
} host_params2_t;

int init_pcm(void** pcm, host_params2_t *hp2);
void* get_state();
void del_state(void *);
double get_ipc(const void* before, const void* after);
double get_L3_hit_ratio(const void* before, const void* after);
double get_L3_occupancy(const void* now);
double get_L2_hit_ratio(const void* before, const void* after); /* Doesn't work on Taurus for some reasons */
double get_avg_frequency(const void* before, const void* after);
double get_MBytes_txn_MC(const void* before, const void* after);
double get_exec_usage(const void* before, const void* after);
int32_t get_thermal_headroom(const void* current);

#ifdef __cplusplus
}
#endif
#endif