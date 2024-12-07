

# Qt_Radar_Program

This program shows the relationship between range resolution and bandwidth in FMCW target detection. Narrower bandwidth makes it harder to distinguish close targets, while higher bandwidth improves accuracy.

The received signal is a delayed version of the transmitted signal:

`r(t) = cos(2π(f_c * (t - τ) + (S * (t - τ)^2) / 2))`

The mixing process involves multiplying the transmitted and received signals to produce the intermediate frequency (IF) signal:

`m(t) = s(t) * r(t)`



Where:
- `f_c` is the carrier frequency,
- `S` is the chirp slope, and
- `τ = 2R / c` is the round-trip delay.

### Formulas used in code

1. **Range Resolution**  
   `ΔR = c / (2 * B)`

2. **Chirp Signal**  
   `s(t) = cos(2π(f_c * t + (S * t^2) / 2))`

3. **Received Signal**  
   `r(t) = cos(2π(f_c * (t - τ) + (S * (t - τ)^2) / 2))`

4. **Mixing Process**  
   `m(t) = s(t) * r(t)`

5. **Round-Trip Delay**  
   `τ = 2R / c`

6. **FFT for Range Detection**  
   `R = (c * f) / (2 * S)`





![image](https://github.com/user-attachments/assets/7f12d7e6-b18e-4089-ac79-79e5d6a78097)
