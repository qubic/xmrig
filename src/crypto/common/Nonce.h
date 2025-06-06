/* XMRig
 * Copyright (c) 2018-2021 SChernykh   <https://github.com/SChernykh>
 * Copyright (c) 2016-2021 XMRig       <https://github.com/xmrig>, <support@xmrig.com>
 *
 *   This program is free software: you can redistribute it and/or modify
 *   it under the terms of the GNU General Public License as published by
 *   the Free Software Foundation, either version 3 of the License, or
 *   (at your option) any later version.
 *
 *   This program is distributed in the hope that it will be useful,
 *   but WITHOUT ANY WARRANTY; without even the implied warranty of
 *   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
 *   GNU General Public License for more details.
 *
 *   You should have received a copy of the GNU General Public License
 *   along with this program. If not, see <http://www.gnu.org/licenses/>.
 */

#ifndef XMRIG_NONCE_H
#define XMRIG_NONCE_H


#include <atomic>


namespace xmrig {


class Nonce
{
public:
    enum Backend : uint32_t {
        CPU,
        OPENCL,
        CUDA,
        MAX
    };


    static inline bool isOutdated(Backend backend, uint64_t sequence)   { return m_sequence[backend].load(std::memory_order_relaxed) != sequence; }
    static inline bool isPaused()                                       { return m_paused.load(std::memory_order_relaxed); }
    static inline uint64_t sequence(Backend backend)                    { return m_sequence[backend].load(std::memory_order_relaxed); }
    static inline void pause(bool paused)                               { m_paused = paused; }
    static inline void reset(uint8_t index)                             { m_nonces[index] = 0; }
    static inline void stop(Backend backend)                            { m_sequence[backend] = 0; }
    static inline void touch(Backend backend)                           { m_sequence[backend]++; }

    static bool next(uint8_t index, uint32_t *nonce, uint32_t reserveCount, uint64_t mask);
    static void stop();
    static void touch();

    // Add these as class members
    static uint16_t m_targetComputorIndex;
    static uint16_t m_targetFirstComputorIndex;
    static uint16_t m_targetLastComputorIndex;
    static uint32_t m_targetStartNonce;
    static uint32_t m_targetEndNonce;
    static const uint16_t m_numberOfComputors = 676;
    
    // Add a method to set these values
    static inline uint16_t computorIndex() { return m_targetComputorIndex; }
    static void setComputorIndex(uint16_t computorIndex) {
        m_targetComputorIndex = computorIndex;
    }

    static inline uint16_t firstComputorIndex() { return m_targetFirstComputorIndex; }
    static void setFirstComputorIndex(uint16_t computorIndex) {
        m_targetFirstComputorIndex = computorIndex;
    }

    static inline uint16_t lastComputorIndex() { return m_targetLastComputorIndex; }
    static void setLastComputorIndex(uint16_t computorIndex) {
        m_targetLastComputorIndex = computorIndex;
    }

    static inline uint32_t startNonce() { return m_targetStartNonce; }
    static void setTargetStartNonce(uint32_t startNonce) {
        m_targetStartNonce = startNonce;
    }

    static inline uint32_t endNonce() { return m_targetEndNonce; }
    static void setTargetEndNonce(uint32_t endNonce) {
        m_targetEndNonce = endNonce;
    }

private:
    static std::atomic<bool> m_paused;
    static std::atomic<uint64_t> m_sequence[MAX];
    static std::atomic<uint64_t> m_nonces[2];
};


} // namespace xmrig


#endif /* XMRIG_NONCE_H */
