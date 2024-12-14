
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
[Circuit Simulation](https://www.falstad.com/circuit/circuitjs.html?ctz=CQAgjCBMB0DMkFYwBYAcqAMBOBlaZwFMBaAdimjFVjAyWSoDZINVlGQFZORluESYMACgASiGKRIyEFg6SEHOSAxRwsZMgyqYCCntUZoCYQBcJYRqrQXIqXvdURiyaFlLbLyLBj7bkkBJGzMikPgEsQij2tKoAJoQAZgCGAK4ANqZmFlbgmrYx+arEEEYYkFhY1AjYipUIqIxg3MTB0mG+UhhRNrEgCSkZWeIldiDwBTkq01o8hirGwgDmk5bFYGNgWIGGwgBOElIyyiW5yk7aGMIA7jnW9qeq5zd3eTKPshxXt6P2jO8bezPH6A8BjX6fFTCADG40Cygma2mAhKhjgtEQWGQXFQzQQoXcC08yzh4FyiO20yuABUJP8ycVMJDHNBtJsieVYP9IIxGLAsfjUFhYAg9K1WRhYOVqLB+QgsageXgFpUsC8ISd6c8RiLAt55FprOc1GxtPpzWiTD8Jgj4V8SUjHbktjsoQdlB6OEiLpcrnFSZ7IYEBmlMi9A0jnrDI17nbknIJVAhWZZRVwKihZUUJSIVsoY+BKbsAPIMyFImy7FbERG5GuBF1U7LEZQMeT0tvTUrQZg+fCyyW4LG+BZ8xjUUjjjRIfHC8BmkNDdX0pHEDtmq7VjsTNcydgyXYHD6dlscTs+q6lo5B6QOJulm0cCaVqE63DjLkSQ0fr5qAJm3QLQWEwVmvJEwKLKFYWvZQwPjcY4ETThKFVBhpAaPsmg5EQDgLGDfyQS4YSgW9YPQSFrGgDxfRoy4wBILAKFCLRcFFNhmi2PRdGEK9yLI+wX2+cZ31BXUoFmISkAbfIpPE3ZbjE6Qkw2OSoVuKwYg4DSwUcfZeF6FTZKEV1Qm0HiQG0ywLNYCQJnkzgVOMhyG3tFZFCcXJ3MLV0rnELzlC8wTeCTKlgOELRGKMsZLPZYIvzcBBSBFDBGCwLZ-lYA9WTwWJaJonZzM0B4rKKukD1fKByLASdKpiMZ5lmAwqUWBT31OYS7TU-SYhU0r2s3YKnHyb9qt-XzBpAJlvzsmYQvmIwTAOMT2r6qydBYIiDjsIEn3fY0ujMiKOvAXqDIbUcgjgGhsXQXEwBqZh+yJHK3Vq8Aau21SLyuLbyKUt6pXK8czNA8jAYBz97MU2ZPv+q4thaMT8HeT7keRZtGzRj40acS7JV5VhRvlHAkvwUcMzsCp-maAIAnneIklDLJzBKSlVtyUqIAgVw+ACPlsTodBSEgUhBGcVwsx5XVUr5r0F0ZpcQQ5s1jzW9UKx3Cs1aPTG2EORRxj1i89NZvUbAUM8X1y9Ukc-bHIfV8k7aRLldOtd99VeT2hOPE4K3pH2xJPIPgVs98sdt+11Js0FGGFnSoQADwsNLbJaSka2sMEQAABVSABnAALYgAAcMnSAAdfPEgAe3SdIa+uQg9mEZOa3j+AxXuvR4AE7OAFka+hABrKvRAAMQASQAESr0xkiWKu9kIEvCGSUxCDidIAE8q-zwgADs4nzquwFPquMAv1uJFICA+UOLSz2zgBBA+N4Pg-kmv+ULK9GxUt4C-fuVcEgAFsa5xAyOvGuLdk6WEYowLiLALJ9xUg3a4pdkj53ztfPgjFiCoHIGgcgBC9wv1ASXdIABLRIVDm7X3rJFEhVA9Ac2zgAZQAI6pGSMvKu1xkgADdCBV0SHsGuoCq7Pz2JAqhB8a7XxCCdDgwseqMRkCpakC8QHr2SHPGuUiZGpDkQog4RktIx1-KZIiNcoDqK7IgUUFloDUE0DgbAcgrDgzKJ4LsIBX7v0-sIWxUhAFOEcXoVAbh3BcDQNiPgQhCQ+O6OAVJABRA+wiG6rxAYQDe0JTAwOCZVMJYI0zITsCKQEXJErYkYskiA50AAyjdMHYNEVQzI9DbHsFKRscpPMBSkHQMlScdAOQpO4FzfOpg97zyWCI-OyQKHUNodCdeVCa4H2KQwPpETeDGGaLdaQdgkqVBFBM7mqTIBHzmQvRZyzKE0Koes0wmztlAA)


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
| 1        | 100pF         | C5             |
| 1        | 330pF         | C6             |
| 1        | 4.7nF         | C7             |

* [Resistors](https://www.amazon.com/dp/B016NXK6QK)

| quantity | resistance | location(s) |
|----------|------------|-------------|
| 1        | 1kΩ        | R1          |
| 1        | 100kΩ      | R2          |
| 1        | 51kΩ       | R3          |
| 1        | 22kΩ       | R4          |
| 1        | 220kΩ      | R5          |
| 1        | 4.7kΩ      | R6          |
| 1        | 470kΩ      | R7          |
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
$f = \Large \frac{1}{2 \pi \sqrt{L \times C}}$

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

We need to choose values for R2 and C5 that fulfill the following inequality, where $\tau = R \times C$, in order to demodulate the signal without distorting it.  
$\Large \frac{1}{f_{carrier}} \normalsize < \tau < \Large \frac{1}{f_{data}}$

The carrier frequency is still 134.4kHz but we need to determine the data signal frequency.
According to the [FDX-B protocol](https://www.priority1design.com.au/fdx-b_animal_identification_protocol.html), 
the frequency of the data signal is a function of the carrier frequency and the data that is being transmitted.
One bit of data is transferred for every 32 carrier cycles and a bit is identifiable by a state transition at the start and end of a bit.  
$4.2kHz = \Large \frac{134.4kHz}{32}$  
i.e. 4200 kb/s

Additionally, a "0" bit is identified by a state transition in the middle of a bit period.
That means that our data signal can change as fast as every 16 carrier cycles and results in a maximum data signal frequency of 8.4kHz.  
$8.4kHz = \Large \frac{134.4kHz}{16}$  
i.e. 8400 baud

Now we can plug those values into our inequality and determine a value for $\tau$.  
$\Large \frac{1}{134.4kHz} \normalsize < \tau < \Large \frac{1}{8.4kHz}$

There are many valid values for $\tau$.
In our case, we'll use a value that is a 10<sub>th</sub> of the data signal's period.  
$\tau = 0.1 \times \Large \frac{1}{8.4kHz} \normalsize = 11.9 \mu s$

Using a 100kΩ resistor and a 100pF capacitor gives us a value that is reasonably close to our chosen $\tau$.  
$10\mu s = 100k\Omega \times 100pF$

![Oscilloscope view of envelope detector](https://github.com/decrazyo/fdxb/blob/main/img/envelope-detector.png)

There is still a lot of high frequency noise from the carrier present in the signal after the envelope detector.
To take care of that we can use the low pass filter formed by R3 and C6 to cut off frequencies higher than that of our data signal.
We can use the formula for an RC filter to calculate a cutoff point at, or slightly above, the data signal frequency of 8.4kHz.  
$f = \Large \frac{1}{2 \pi \times R \times C}$

A 51kΩ resistor and a 330pF capacitor will work well for this.  
$9.46kHz = \Large \frac{1}{2 \pi \times 51k\Omega \times 330pF}$

![Oscilloscope view of low pass filter](https://github.com/decrazyo/fdxb/blob/main/img/low-pass-filter.png)

We should have a fairly clean data signal now that the filtering is done, with a clear distinction between the low and high states.
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
[How My DIY RFID Reader Became a Lifesaver - SecretCon 2024](https://www.youtube.com/watch?v=yirEXUiZuOM)  
[125 kHz RFID tag reader](https://www.serasidis.gr/circuits/RFID_reader/125kHz_RFID_reader.htm)  
[EM4100 RFID Reader Mod](https://github.com/s60sc/ESP32_RFID_Reader)  
[Coil Inductance Calculator](https://www.66pacific.com/calculators/coil-inductance-calculator.aspx)


## License
GPLv3
