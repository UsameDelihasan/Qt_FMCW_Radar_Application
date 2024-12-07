# Qt_Radar_Program

# Radar Chirp Signal and FM Modulation

This repository demonstrates the relationship between **FM modulation** and **chirp signals**, and how radar systems utilize these concepts for range detection.

## 1. FM Modulation Basics
In **Frequency Modulation (FM)**, the frequency of the carrier signal is modulated based on the message signal \( m(t) \). The FM signal is represented as:

\[
s(t) = A_c \cos\left(2\pi f_c t + 2\pi k_f \int m(\tau) d\tau \right)
\]

Where:
- \( A_c \): Carrier amplitude,
- \( f_c \): Carrier frequency,
- \( k_f \): Frequency modulation coefficient (\( Hz/V \)),
- \( m(t) \): Message signal.

The **modulation index** (\( \beta \)) for FM is defined as:

\[
\beta = \frac{\Delta f}{f_m}
\]

Where:
- \( \Delta f = k_f \cdot A_m \): Maximum frequency deviation,
- \( f_m \): Maximum frequency of the message signal,
- \( A_m \): Maximum amplitude of the message signal.

---

## 2. Chirp Signal for Radar
In radar systems, a **chirp signal** is a special case of FM modulation where the message signal is linear in time, \( m(t) = t \). The resulting chirp signal is:

\[
s(t) = A_c \cos\left(2\pi f_c t + \pi S t^2 \right)
\]

Where:
- \( S = \frac{\Delta f}{T_{\text{chirp}}} \): Chirp slope (frequency change rate),
- \( T_{\text{chirp}} \): Duration of the chirp signal,
- \( \Delta f \): Total frequency bandwidth of the chirp.

---

## 3. Key Differences Between FM and Chirp
| Concept            | FM Modulation                                    | Chirp Signal                                  |
|--------------------|--------------------------------------------------|----------------------------------------------|
| Frequency Control  | Depends on message amplitude (\( A_m \))         | Depends on time (\( t \))                    |
| Frequency Deviation| \( \Delta f = k_f \cdot A_m \)                   | \( \Delta f = S \cdot T_{\text{chirp}} \)    |
| Slope (\( S \))    | Not explicitly used                              | \( S = \frac{\Delta f}{T_{\text{chirp}}} \)  |

---

## 4. Practical Applications
- **FM Modulation** is widely used in telecommunications (e.g., FM radio).
- **Chirp Signals** are specifically used in radar systems for range detection and resolution improvement.

For further details, check out the MATLAB and Python implementations in this repository!



![image](https://github.com/user-attachments/assets/7f12d7e6-b18e-4089-ac79-79e5d6a78097)
