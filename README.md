
# Arduino FDX-B Reader
DIY ISO 11784/11785 FDX-B RFID Reader
<!-- ![Reader built on breadboard](https://github.com/decrazyo/fdxb/blob/master/img/breadboard.jpg) -->
![Reader built on breadboard](https://github.com/decrazyo/fdxb/blob/main/img/breadboard.jpg)
The goal of this project is to create hardware/software capable of reading RFID tags implanted in animals.
Only tags that use the [FDX-B protocol](https://www.priority1design.com.au/fdx-b_animal_identification_protocol.html) are supported since they appear to be the most common.
Support for [HDX protocol](https://www.priority1design.com.au/hdx_animal_identification_protocol.html) based tags would require a significant hardware redesign that I'm unwilling to do at the moment.
The [EM4100 protocol](https://www.priority1design.com.au/em4100_protocol.html), that is commonly used by RFID fobs/cards, could be supported with minor changes but that's outside the scope of this project.


## Hardware
![Schematic](https://github.com/decrazyo/fdxb/blob/main/img/schematic.svg)
[Open Source Hardware Project](https://oshwlab.com/decrazyo/fdx-b-reader)  
[Circuit Simulation](https://www.falstad.com/circuit/circuitjs.html?ctz=CQAgjCBMB0DMkFYwBYAcqAMBOBlaZwFMBaAdnGmVizBoDZslktUtYQkOQqOSwwAUACUQxSJGQgsdUYhnSQGKOFjJkGJTARRo2pRl0CALqLANuqU5EtpF4UcmhYWpVxjCo6YDHhnEDCMhgkGCkyAikXgh0rtreSgAmhABmAIYArgA2Rsam5iiSxMGWBXZFitAaweIsYPhYkWqQdIUBQSFhEVExpHEaIElpWTkiRdYg8FaWRTL63Ep6dgECAOZT4OZjJViQSwIATrISUn5mSgpK8RgCAO55SrYz57O39+BqbxevWyAt6193H7Ff4vADGE12CkmZzsCD4+icYAQCE8kF6kQkyFIEAMVVWEI2SmhOz2ABVRH8YcRMCcQJZcT4ShUNBp1CFYHQdmgMMhmh5RAz3HhcBgGBh0HRUM06OwDM4sN9gQpiH8vqNYLhuMr1A8LspUDqdNotEtDIDJlDIS81jDbfkSfoDrSFAoYQ9SCzrgkCS75DJdoMMtlXr7CbTruCYa78uZLnwII5aChPMg6HgPLAwsz3Pjo89wA7FAIAPJhvMWPZrYjQzbE3aOkzEBRBPx-Ft2HGULCpugRKUYQK4EJ+XG0aTd1jWSUyrGSeIDFJBnKAymbNv9a5VtuTFWSVOSR2HJ7cMyiZuny4sktQY4KcR7+lF0sWmSTWyO9Wa2Achz9b+zZReX6E0TQRBB8XvMNINoesi3BSC72ON0JjgeFuGgFoPAQDU0VIfBWCwbNBEOKN-VvACkCveDyKgdBw3Qj1PSYlkwBIQiYF7VheWYdlVFITwjWvaxLDvOj3yLO4cPAcYpIkR07iQXZSkUqB1AkiZNTkjhglU+TfnFDZ9JKcZrkONQSh0lT+FgrENGvBgShkBzREmPSrMsnSL3xaJLnMHyC1g64RH8hR-PEh4FiWCpwPUQirPGZzgU7Ec4FgFBsSoZgZw8LFmXTZiCvra9zLybhHj+D9aJKSIqukx8Iq4OZlkkzUZg0q11JK6yyumLy1kNUoBpqyrDRpQ1XLsNTFjAp0pLakq2s0SBPSdYTaSkvVxCvWL2vAHSus8ipTmgTwwm-TMwl5BpZkqdMi0ONbQn9OitMvK8HpetS1tgHk7ElOy1m+37vp-PTZK+z7HVodhqy-A1ZDo-ADw4XIihJJG3gxy4ju-KhluYMxcG7QiDBleBu05e9pA0JT+kDYZUZgnq3i6+xiEceVOYnTmYcFOo8KQVAkUlTB3Bked6eDQEYUNY922uaXzDxlmvKPJmMbEaIJnht7TNMEkFrkZnde+KT-0x0HFXMc3jw5elTc1LKWYBZ3TiViqHd2dtYa9l2fe1wozctu5EoS0glJMgQAA99YgasYYaFyHmkkAAAV0gAZwAC2IAAHLJMgAHQz5IAHtMkyUubkIfZo5c8OIW0IoUQhGwU4AWVL0EAGti6EAAxABJAARYujFSFZi-2Qhc8IVIjEIBJMgAT2LjPCAAOwSDPi7AXfi4wA+67ICAZVkcg6BkOddgAQQ3heN431I64QQjL-eC-COvkAb-b4ukgALalwSFkeepda4xzMG-Y0p5JTcBTpXG4edUgZwznXKghFqTkDQE3eG38b4ANzpkAAlskYhNdj7kw4OQIoqAL7Jx0gAZQAI7pFSNPYuNxUgADdCDF2SPsUuADi4332CA4hG9S51zTHOU84cLJfxTqSCe-956pDHqXERYj0gSKkYcKyTkDIXm4IxOypcoCKMuIgZEIBSCVBiBIFAHgWj9hJpUKoHYf7303k-AQ5jxDwKscibQqBoBQOxIgHA4ogjYWzO4ewEAACiG9eGV1nv-QgC9QRGHAX42igTpLBIYqwS+3gsQGmxKoOJEAlIgAADJV2Qag-hxDsgUPMamApwQikwFIDsJE1gnoYHgHQ6pEwEkZyMGvceKw+EZ1SIQkhZDQTz2IaXDeeSghdOsdoRwRN+D4BQAOYmOAxlzigFvaZE85kLKIaQ4hKyjBrI2UAA)


### Tools
* [Oscilloscope](https://www.amazon.com/dp/B07SL8KQPZ)
* Multimeter (optional)
* LCR meter (optional)


### Materials
* [Arduino](https://www.amazon.com/dp/B07KCH534K) compatible microcontroller [M1]
* [LM358P](https://www.amazon.com/dp/B07WQWPLSP) dual op-amp [U1]
* [PN2222A](https://www.amazon.com/dp/B088DMF2YZ) NPN transistor [Q1]
* [PN2907A](https://www.amazon.com/dp/B088DMF2YZ) PNP transistor [Q2]
* [1N4148](https://www.amazon.com/dp/B08SBTS2KZ) fast switching diode [D1]
* [RFID antenna coil](https://www.priority1design.com.au/rfid_coil_antenna.html) or wind your own with [Enamel copper wire (magnet wire)](https://www.amazon.com/dp/B00L5IUUOW) [L1]
* [Capacitors](https://www.amazon.com/dp/B071P44QBH)

| quantity | capacitance   | location(s)    |
|----------|---------------|----------------|
| 4        | depends on L1 | C1, C2, C3, C4 |
| 1        | 10pF          | C5             |
| 1        | 330pF         | C6             |
| 1        | 4.7nF         | C7             |

* [Resistors](https://www.amazon.com/dp/B016NXK6QK)

| quantity | resistance | location(s) |
|----------|------------|-------------|
| 1        | 1kΩ        | R1          |
| 2        | 470kΩ      | R2, R7      |
| 1        | 51kΩ       | R3          |
| 1        | 22kΩ       | R4          |
| 1        | 220kΩ      | R5          |
| 1        | 4.7kΩ      | R6          |
| 1        | 10kΩ       | R8          |
| 1        | 6.8kΩ      | R9          |


### Design
First we want to generate the 134.2kHz carrier frequency for the reader.
We can do that by using any of the Arduino's PWM-capable timers to generate a square wave.
Arduino timers can only achieve a frequency of 134.4kHz which is close enough for our purposes.
The example sketch uses Timer1 to output the square wave on PB1 (Arduino Nano pin 9).

The square wave from the Arduino controls the push-pull amplifier formed by R1, Q1, and Q2.
The push-pull amplifier then drives the LC resonator formed by the antenna L1 and its associated tuning capacitors C1, C2, C3, and C4.

The LC resonator will need to be tuned to resonate at the carrier frequency.
The resonance frequency of an LC resonator can be calculated with the following formula
([online calculator](https://www.omnicalculator.com/physics/resonant-frequency-lc)).  
$F = \Large \frac{1}{2 \pi \sqrt{L \times C}}$

For example, if we have a 2.8mH antenna coil that we want to resonate at 134.4kHz then the total capacitance of $C1 + C2 + C3 + C4$ should be 500.8pF.  
$134.40kHz = \Large \frac{1}{2 \pi \sqrt{2.8mH \times 500.8pF}}$

The closest capacitance that we can easily achieve is $500pF = 220pF + 220pF + 30pF + 30pF$, which is close enough.  
$134.51kHz = \Large \frac{1}{2 \pi \sqrt{2.8mH \times 500pF}}$

Tags will be easier to read with a properly tuned LC resonator.
Tuning can be judged by measuring the peek-to-peek voltage of the LC resonator.
A peek-to-peek voltage 3 to 4 times higher than the supply voltage should be achievable.

![Oscilloscope view of antenna](https://github.com/decrazyo/fdxb/blob/main/img/antenna.png)

With that, we have a device that can supply power to a tag, act as a clock signal, and provide a communication channel.
If a tag enters the EM field of the antenna coil then the tag will power up and start modulating its data into the carrier.

![Oscilloscope view of antenna near tag](https://github.com/decrazyo/fdxb/blob/main/img/antenna-near-tag.png)


Next we need to extract the transmitted data from the carrier.
That can be done by passing the signal through series of filters, starting with the envelope detector formed by D1, R2, and C5.
The optimal frequency for our envelope detector can be calculated from the carrier frequency and the frequency of the data signal with the following formula.  
$F_{o} = \sqrt{F_{c} \times F_{d}}$

The carrier frequency is still 134.4kHz and according to the the 
[FDX-B protocol](https://www.priority1design.com.au/fdx-b_animal_identification_protocol.html), 
the frequency of the data signal is a function of the carrier frequency and the data that is being transmitted.
One bit of data is transferred for every 32 carrier cycles and a bit is identifiable by a state transition at the start and end of a bit.  
$4.2kHz = \Large \frac{134.4kHz}{32}$  
i.e. 4200 kb/s

Additionally, a "0" bit is identified by a state transition in the middle of a bit period.
That means that our data signal can change as fast as every 16 carrier cycles and results in a maximum data signal frequency of 8.4kHz.  
$8.4kHz = \Large \frac{134.4kHz}{16}$  
i.e. 8400 baud

Now we can calculate that the optimal envelope detector should operate at 33.6kHz.  
$33.60kHz = \sqrt{134.4kHz \times 8.4kHz}$

The actual frequency of our envelope detector can be calculated with the following formula for an RC filter.  
$F = \Large \frac{1}{2 \pi \times R \times C}$

We can get close to the optimal frequency with a 470kΩ resistor and a 10pH capacitor.  
$33.86kHz = \Large \frac{1}{2 \pi \times 470k\Omega \times 10pH}$

![Oscilloscope view of envelope detector](https://github.com/decrazyo/fdxb/blob/main/img/envelope-detector.png)


Next we can use the low pass filter formed by R3 and C6 to cut off frequencies higher than that of our data signal, such as the carrier frequency.
We can use the formula for an RC filter again to calculate a cutoff point at, or slightly above, the data signal frequency of 8.4kHz.
A 51kΩ resistor and a 330pH capacitor will work well for this.  
$9.46kHz = \Large \frac{1}{2 \pi \times 51k\Omega \times 330pH}$

![Oscilloscope view of low pass filter](https://github.com/decrazyo/fdxb/blob/main/img/low-pass-filter.png)


We should have a fairly clean data signal now that the filtering done.
All that's left to do is amplify the signal to the logic level of the Arduino.
For that, we can use an LM358 dual op-amp with both op-amps in inverting configurations and operating in series.

By first passing the signal through a series capacitor, we can make the signal osculate around the set point of the op-amps.
For that reason we will use the voltage divider formed by R8 and R9 to set the non-inverting inputs of the op-amps to a voltage near the midpoint of their output voltage.

We will configure the first op-amp to have a gain of 10 to avoid distorting the data signal.

![Oscilloscope view of amp stage 1](https://github.com/decrazyo/fdxb/blob/main/img/amp-stage-1.png)

The second op-amp is arbitrary configured with an further gain of 100.

![Oscilloscope view of amp stage 2](https://github.com/decrazyo/fdxb/blob/main/img/amp-stage-2.png)

That gives us a digital signal which is suitable for parsing by an Arduino.


## See Also
[125 kHz RFID tag reader](https://www.serasidis.gr/circuits/RFID_reader/125kHz_RFID_reader.htm)  
[EM4100 RFID Reader Mod](https://github.com/s60sc/ESP32_RFID_Reader)  
[Coil Inductance Calculator](https://www.66pacific.com/calculators/coil-inductance-calculator.aspx)


## License
GPLv3
