# Microblaze Performance Evaluation
Final project for the course *Integrated Electronic Systems (MUIT UGR)*

This project aims to study the performance of a **Microblaze**, a Xilinx RISC processor, in four key aspects using **Vivado** and **Vitis** tools:
1. **Area** (resources used).
2. **Performance** (benchmarking in Vitis).
3. **Maximum frequency** (by analyzing critical paths in Vivado).
4. **Power consumption**.

The study is carried out by configuring the **Microblaze** with three different presets: **area**, **performance**, and **frequency**, each one focused on optimizing one of the mentioned characteristics.

For the study conducted in Vitis, use the provided cpp file (it is recommended to use the empty C/C++ project template and the hardware platform XSA generated in the Vivado project).  
The debugger, together with the MDM module (instantiated in Vivado), was used to determine the contents of the internal timer variables.

## Requirements

- **Vivado**: To synthesize the design and obtain metrics of **maximum frequency**, **area**, and **power consumption**.
- **Vitis**: To run performance tests on the Microblaze processor.

## Installation

```bash
git clone https://github.com/Enrique-AZC/Introduccion-y-estudio-de-Microblaze
cd Introduccion-y-estudio-de-Microblaze
