#include <iostream>
#include <cstdlib>
#include "cpucounters.h"
#include "pcm_c_api.h"

void init_pcm(void** pcm) {
    PCM *m = PCM::getInstance();
    if (m->program() != PCM::Success) {
        std::cerr<<"Could not initialize PCM";
        exit(EXIT_FAILURE);
    }
    *pcm = static_cast<void*>(m);
}

void* get_state() {
    SystemCounterState *scs = new SystemCounterState;
    *scs = getSystemCounterState();
    void* scsv = static_cast<void*>(scs);
    return scsv;
}

double get_ipc(const void* before, const void* after) {
    const SystemCounterState *before_sstate = static_cast<const SystemCounterState*>(before);
    const SystemCounterState *after_sstate = static_cast<const SystemCounterState*>(after);
    double r = getIPC(*before_sstate,*after_sstate);
    return r;
}

double get_L3_hit_ratio(const void* before, const void* after) {
    const SystemCounterState *before_sstate = static_cast<const SystemCounterState*>(before);
    const SystemCounterState *after_sstate = static_cast<const SystemCounterState*>(after);
    double r = getL3CacheHitRatio(*before_sstate,*after_sstate);
    return r;
}

double get_L2_hit_ratio(const void* before, const void* after) {
    const SystemCounterState *before_sstate = static_cast<const SystemCounterState*>(before);
    const SystemCounterState *after_sstate = static_cast<const SystemCounterState*>(after);
    double r = getL2CacheHitRatio(*before_sstate,*after_sstate);
    return r;
}

double get_local_memory_bw(const void* before, const void* after) {
    const SystemCounterState *before_sstate = static_cast<const SystemCounterState*>(before);
    const SystemCounterState *after_sstate = static_cast<const SystemCounterState*>(after);
    double r = getLocalMemoryBW(*before_sstate,*after_sstate);
    return r;
}

double get_bytes_read_MC(const void* before, const void* after) {
    const SystemCounterState *before_sstate = static_cast<const SystemCounterState*>(before);
    const SystemCounterState *after_sstate = static_cast<const SystemCounterState*>(after);
    double r = getBytesReadFromMC(*before_sstate,*after_sstate);
    return r;
}

double get_exec_usage(const void* before, const void* after) {
    const SystemCounterState *before_sstate = static_cast<const SystemCounterState*>(before);
    const SystemCounterState *after_sstate = static_cast<const SystemCounterState*>(after);
    double r = getExecUsage(*before_sstate,*after_sstate);
    return r;
}