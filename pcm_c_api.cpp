#include <iostream>
#include <cstdlib>
#include <cstdint>
#include "cpucounters.h"
#include "pcm_c_api.h"

int init_pcm(void** pcm, host_params2_t *hp2) {
    PCM *m = PCM::getInstance();
    if (m->program() != PCM::Success) {
        std::cerr<<"Could not initialize PCM"<<std::endl;
        return -1;
    }
    *pcm = static_cast<void*>(m);
    hp2->nominal_frequency = m->getNominalFrequency();
    hp2->max_ipc           = m->getMaxIPC();
    hp2->num_lprocs        = m->getNumCores();
    hp2->lprocs_per_core   = m->getThreadsPerCore();
    return 0;
}

int32_t get_thermal_headroom(const void* current) {
    const SystemCounterState *state2 = static_cast<const SystemCounterState*>(current);
    int32 r = getThermalHeadroom(*state2,*state2);
    return r;
}

void del_state(void *state) {
    const SystemCounterState *state2 = static_cast<const SystemCounterState*>(state);
    delete state2;
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

double get_L3_occupancy(const void* now) {
    const SystemCounterState *now_sstate = static_cast<const SystemCounterState*>(now);
    double l3o = getL3CacheOccupancy(*now_sstate);
    return l3o;
}

double get_avg_frequency(const void* before, const void* after) {
    const SystemCounterState *before_sstate = static_cast<const SystemCounterState*>(before);
    const SystemCounterState *after_sstate = static_cast<const SystemCounterState*>(after);
    double r = (getAverageFrequency(*before_sstate,*after_sstate))/1000000000.0;
    return r;
}

double get_L2_hit_ratio(const void* before, const void* after) {
    const SystemCounterState *before_sstate = static_cast<const SystemCounterState*>(before);
    const SystemCounterState *after_sstate = static_cast<const SystemCounterState*>(after);
    double r = getL2CacheHitRatio(*before_sstate,*after_sstate);
    return r;
}

double get_bytes_txn_MC(const void* before, const void* after) {
    const SystemCounterState *before_sstate = static_cast<const SystemCounterState*>(before);
    const SystemCounterState *after_sstate = static_cast<const SystemCounterState*>(after);
    double r1 = getBytesReadFromMC(*before_sstate,*after_sstate);
    double r2 = getBytesReadFromMC(*before_sstate,*after_sstate);
    return r1+r2;
}


double get_exec_usage(const void* before, const void* after) {
    const SystemCounterState *before_sstate = static_cast<const SystemCounterState*>(before);
    const SystemCounterState *after_sstate = static_cast<const SystemCounterState*>(after);
    double r = getExecUsage(*before_sstate,*after_sstate);
    return r;
}