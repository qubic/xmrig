# Qubic XMRig mod
This is a modified XMRig version as a reference implementation to be used with the Qubic Monero POC.

Use the source to build it for your target system. The below referenced binaries point to the **non** modified version. Do not use them.

To make use of the customized features, your stratum server needs also to be customized.
The Job JSON which is delegated from the Stratum server must contain additional fields.

1. `computorIndex` => the index you want to produce solutions for
2. `start_nonce` => `uint64`; start to scan for
3. `end_nonce` => `uint64`; end to scan to

The `start` and `end` is needed that not all of your miners start to scan the same space. You may generate those spaces randomly or specific for your miners. For a 7950X you may  use a size around `155480000`;


Example of a complete JSON returned by the customized Stratum server:
```json
{
    ...
    {
        "id": "1745433817138",
        "job": {
            "blob": "1010D2E9A4C006F0B455B2DFABF2A42C8A4F4A194FC8579F2403EC355E58A90B8CDB2B4E5E5D41000000006D641DF083E9055A502ED446D80FE41D371233E659328AF01420D8D3334A9E5019",
            "computorIndex": 675,
            "end_nonce": 2434634175,
            "height": 3396494,
            "job_id": "1745433817138",
            "seed_hash": "8977D87B02B4033F577AD402A0CC41120784818322B19E9E6D4D537A3CAE29D7",
            "start_nonce": 2279154176,
            "target": "780D7F02F3220000"
        }
    },
    "status": "OK"
}
```
> the `job_id` may be the `taskIndex` from Qubic for easy identification. [Link to complete Qubic task Struct](https://github.com/qubic/outsourced-computing/blob/main/monero-poc/README.md#the-principle)

> the `-user` param may be the Qubic Address or a pool specific identifier

> the current implementation is fine tuned to run on 32-threads (7950X) if you have more than this, you should run multiple instances


# Original XMRig Readme

[![Github All Releases](https://img.shields.io/github/downloads/xmrig/xmrig/total.svg)](https://github.com/xmrig/xmrig/releases)
[![GitHub release](https://img.shields.io/github/release/xmrig/xmrig/all.svg)](https://github.com/xmrig/xmrig/releases)
[![GitHub Release Date](https://img.shields.io/github/release-date/xmrig/xmrig.svg)](https://github.com/xmrig/xmrig/releases)
[![GitHub license](https://img.shields.io/github/license/xmrig/xmrig.svg)](https://github.com/xmrig/xmrig/blob/master/LICENSE)
[![GitHub stars](https://img.shields.io/github/stars/xmrig/xmrig.svg)](https://github.com/xmrig/xmrig/stargazers)
[![GitHub forks](https://img.shields.io/github/forks/xmrig/xmrig.svg)](https://github.com/xmrig/xmrig/network)

XMRig is a high performance, open source, cross platform RandomX, KawPow, CryptoNight and [GhostRider](https://github.com/xmrig/xmrig/tree/master/src/crypto/ghostrider#readme) unified CPU/GPU miner and [RandomX benchmark](https://xmrig.com/benchmark). Official binaries are available for Windows, Linux, macOS and FreeBSD.

## Mining backends
- **CPU** (x86/x64/ARMv7/ARMv8)
- **OpenCL** for AMD GPUs.
- **CUDA** for NVIDIA GPUs via external [CUDA plugin](https://github.com/xmrig/xmrig-cuda).

## Download
* **[Binary releases](https://github.com/xmrig/xmrig/releases)**
* **[Build from source](https://xmrig.com/docs/miner/build)**

## Usage
The preferred way to configure the miner is the [JSON config file](https://xmrig.com/docs/miner/config) as it is more flexible and human friendly. The [command line interface](https://xmrig.com/docs/miner/command-line-options) does not cover all features, such as mining profiles for different algorithms. Important options can be changed during runtime without miner restart by editing the config file or executing [API](https://xmrig.com/docs/miner/api) calls.

* **[Wizard](https://xmrig.com/wizard)** helps you create initial configuration for the miner.
* **[Workers](http://workers.xmrig.info)** helps manage your miners via HTTP API.

## Donations
* Default donation 1% (1 minute in 100 minutes) can be increased via option `donate-level` or disabled in source code.
* XMR: `48edfHu7V9Z84YzzMa6fUueoELZ9ZRXq9VetWzYGzKt52XU5xvqgzYnDK9URnRoJMk1j8nLwEVsaSWJ4fhdUyZijBGUicoD`

## Developers
* **[xmrig](https://github.com/xmrig)**
* **[sech1](https://github.com/SChernykh)**

## Contacts
* support@xmrig.com
* [reddit](https://www.reddit.com/user/XMRig/)
* [twitter](https://twitter.com/xmrig_dev)
