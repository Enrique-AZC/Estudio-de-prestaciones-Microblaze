# MicroBlaze System-on-Chip (SoC) Implementation

## Abstract
This project implements and validates a **custom System-on-Chip (SoC) architecture** based on the **Xilinx MicroBlaze soft processor core**, synthesized on a reconfigurable FPGA device.  
The design integrates the MicroBlaze CPU, memory subsystems, standard peripherals, and custom hardware accelerators. The workflow covers all stages: hardware description, toolchain configuration, simulation, synthesis, deployment on FPGA hardware, and software validation.  

The project provides a **complete reference implementation** for students and researchers working with FPGA-based soft processors, embedded system prototyping, and hardware/software co-design.

---

## MicroBlaze Architecture Overview
MicroBlaze is a **32-bit Harvard RISC soft-core processor** that can be instantiated in Xilinx FPGAs.  
Key characteristics:  
- **Instruction Set Architecture (ISA):** 32-bit RISC, configurable optional instructions (barrel shifter, multiplier, divider, FPU).  
- **Pipeline:** 3-stage or 5-stage configurable pipeline.  
- **Endianness:** Little Endian.  
- **Memory Architecture:** Harvard architecture with separate instruction/data paths, supports local memory (BRAM) and external interfaces.  
- **Interrupts:** Supports hardware interrupts, external interrupt controller (XIntc).  
- **Interfaces:** AXI4, AXI4-Lite, or legacy PLB/OPB depending on Vivado version.  

The flexibility of MicroBlaze makes it suitable for a wide range of **embedded applications**, from bare-metal to RTOS-based designs.

---

## System Architecture
The implemented SoC includes the following components:

1. **MicroBlaze CPU Core**
   - Configurable pipeline depth and optional instruction set extensions.
   - Connected to AXI interconnect for memory and peripherals.

2. **On-Chip Memory**
   - BRAM-based local memory (Instruction + Data).
   - External DDR controller (optional).

3. **Standard Peripherals**
   - UART Lite for serial communication.
   - GPIO modules for LED/switch interaction.
   - Timer modules for system tick and performance monitoring.

4. **Custom Hardware Accelerators** (optional, for co-design experiments)
   - Connected as AXI peripherals.
   - Invoked via software drivers in C.

5. **Interrupt System**
   - Centralized interrupt controller.
   - Configurable priority and vectoring.

6. **Clocking & Reset**
   - Processor clock derived from FPGA PLL/MMCM.
   - AXI interconnect synchronized with CPU domain.

---

## Toolchain & Workflow
### Hardware Design Flow
1. **Vivado Block Design**  
   - Instantiate MicroBlaze from IP catalog.  
   - Configure memory size, peripheral mapping, and pipeline.  
   - Connect AXI interconnects.  
   - Validate design and generate HDL wrapper.  

2. **Synthesis & Implementation**  
   - Map design to target FPGA (e.g., Xilinx Artix-7, Zynq-7000).  
   - Optimize timing closure for desired CPU frequency.  

3. **Bitstream Generation**  
   - Export `.bit` file for FPGA programming.  
   - Export hardware description (XSA) to SDK/Vitis.  

### Software Development Flow
1. **Toolchain**  
   - Xilinx Vitis or SDK (depending on version).  
   - Cross-compiler: `mb-gcc` (MicroBlaze GNU Toolchain).  

2. **Bare-Metal Application**  
   - Written in C.  
   - Uses BSP (Board Support Package) auto-generated from hardware design.  
   - Includes drivers for UART, GPIO, timers, and custom accelerators.  

3. **RTOS Integration (optional)**  
   - FreeRTOS port for MicroBlaze.  
   - Task scheduling, semaphore synchronization, and tick timer setup.  

4. **Deployment**  
   - Program FPGA with `.bit` file.  
   - Load ELF binary into MicroBlaze memory.  
   - Debug via UART or JTAG interface.  

---

## Validation & Testing
Validation consists of both **functional verification** (simulation) and **hardware testing** (on FPGA board).

1. **Simulation**  
   - Behavioral simulation of HDL design in Vivado Simulator.  
   - Testbenches validate instruction fetch, data access, and peripheral response.  

2. **Hardware Testing**  
   - UART test (echo characters sent from PC).  
   - GPIO test (LED blink controlled by software).  
   - Timer test (periodic interrupt handling).  
   - Custom accelerator test (software function call invokes hardware unit).  

3. **Performance Measurement**  
   - CPU frequency: up to 200 MHz (depending on FPGA).  
   - Memory throughput measured using `Xil_TestMem32()`.  
   - Interrupt latency benchmarked using cycle counter.  

---


---

## Requirements
- **Hardware:**  
  - FPGA development board (e.g., Digilent Arty A7, Nexys A7, or ZedBoard).  
  - JTAG cable for programming and debugging.  

- **Software:**  
  - Xilinx Vivado Design Suite (2019.2+).  
  - Xilinx SDK or Vitis IDE.  
  - MicroBlaze GNU Compiler Toolchain (`mb-gcc`).  

---

## Future Extensions
- Implement **cache-enabled MicroBlaze** to evaluate performance improvements.  
- Add **Ethernet MAC** for networking support.  
- Run **FreeRTOS with multiple tasks** to test multitasking.  
- Integrate **AXI DMA** for high-speed data transfer between CPU and accelerators.  
- Explore **hardware/software partitioning** strategies for compute-intensive algorithms.  

---

## Academic Relevance
This project is relevant for courses and research in:  
- **Embedded Systems Design** (soft processors on FPGA).  
- **Computer Architecture** (configurable pipelines, custom instructions).  
- **Hardware/Software Co-Design** (accelerators + software drivers).  
- **Digital Systems Validation** (simulation + FPGA prototyping).  

It provides a hands-on approach for understanding how **soft processors** are integrated and validated in FPGA-based SoCs.

---

**Author:** Enrique Alcalá-Zamora Castro 
**Institution:** Signal Processing Research Team - University of Granada

