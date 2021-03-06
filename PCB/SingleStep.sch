EESchema Schematic File Version 2
LIBS:power
LIBS:device
LIBS:transistors
LIBS:conn
LIBS:linear
LIBS:regul
LIBS:74xx
LIBS:cmos4000
LIBS:adc-dac
LIBS:memory
LIBS:xilinx
LIBS:microcontrollers
LIBS:dsp
LIBS:microchip
LIBS:analog_switches
LIBS:motorola
LIBS:texas
LIBS:intel
LIBS:audio
LIBS:interface
LIBS:digital-audio
LIBS:philips
LIBS:display
LIBS:cypress
LIBS:siliconi
LIBS:opto
LIBS:atmel
LIBS:contrib
LIBS:valves
LIBS:SingleStep-cache
EELAYER 25 0
EELAYER END
$Descr A4 11693 8268
encoding utf-8
Sheet 1 1
Title ""
Date "29 jun 2014"
Rev ""
Comp ""
Comment1 ""
Comment2 ""
Comment3 ""
Comment4 ""
$EndDescr
$Comp
L ATTINY24A-P IC1
U 1 1 538CD6FA
P 4650 3550
F 0 "IC1" H 3900 4300 60  0000 C CNN
F 1 "ATTINY24A-P" H 5200 2800 60  0000 C CNN
F 2 "Housings_SOIC:SOIC-14_3.9x8.7mm_Pitch1.27mm" H 3950 2800 60  0001 C CNN
F 3 "" H 4650 3550 60  0000 C CNN
	1    4650 3550
	1    0    0    -1  
$EndComp
$Comp
L CONN_01X08 P1
U 1 1 538CD788
P 2400 5100
F 0 "P1" V 2350 5100 60  0000 C CNN
F 1 "INPUT" V 2450 5100 60  0000 C CNN
F 2 "Connectors_JST:JST_XH_S08B-XH-A_08x2.50mm_Angled" H 2400 5100 60  0001 C CNN
F 3 "" H 2400 5100 60  0000 C CNN
	1    2400 5100
	-1   0    0    -1  
$EndComp
$Comp
L CONN_01X08 P2
U 1 1 538CD7A0
P 7650 5100
F 0 "P2" V 7600 5100 60  0000 C CNN
F 1 "OUTPUT" V 7700 5100 60  0000 C CNN
F 2 "Connectors_JST:JST_XH_S08B-XH-A_08x2.50mm_Angled" H 7650 5100 60  0001 C CNN
F 3 "" H 7650 5100 60  0000 C CNN
	1    7650 5100
	1    0    0    1   
$EndComp
$Comp
L LED D1
U 1 1 538CDC38
P 6700 3850
F 0 "D1" H 6750 3900 60  0001 C CNN
F 1 "LED" H 6700 3850 60  0001 C CNN
F 2 "LEDs:LED_D5.0mm" H 6700 3850 60  0000 C CNN
F 3 "~" H 6700 3850 60  0000 C CNN
F 4 "D" H 6700 3950 50  0000 C CNN "Reference"
F 5 "LED" H 6700 3750 50  0000 C CNN "Value"
	1    6700 3850
	-1   0    0    1   
$EndComp
$Comp
L R R1
U 1 1 538CDC62
P 6100 3850
F 0 "R1" H 6150 3900 60  0001 C CNN
F 1 "R" H 6100 3850 60  0001 C CNN
F 2 "Resistors_SMD:R_0603" V 6030 3850 30  0000 C CNN
F 3 "~" H 6100 3850 30  0000 C CNN
F 4 "R" V 6180 3850 40  0000 C CNN "Reference"
F 5 "R" V 6107 3851 40  0000 C CNN "Value"
	1    6100 3850
	0    -1   -1   0   
$EndComp
$Comp
L C C2
U 1 1 538CDDB4
P 5200 1850
F 0 "C2" H 5250 1900 60  0001 C CNN
F 1 "C" H 5200 1850 60  0001 C CNN
F 2 "Capacitors_SMD:C_0603" H 5238 1700 30  0000 C CNN
F 3 "~" H 5200 1850 60  0000 C CNN
F 4 "C" H 5200 1950 40  0000 L CNN "Reference"
F 5 "C" H 5206 1765 40  0000 L CNN "Value"
	1    5200 1850
	-1   0    0    1   
$EndComp
$Comp
L C C3
U 1 1 538CDDC9
P 7350 1900
F 0 "C3" H 7400 1950 60  0001 C CNN
F 1 "C" H 7350 1900 60  0001 C CNN
F 2 "Capacitors_SMD:C_0603" H 7388 1750 30  0000 C CNN
F 3 "~" H 7350 1900 60  0000 C CNN
F 4 "C" H 7350 2000 40  0000 L CNN "Reference"
F 5 "C" H 7356 1815 40  0000 L CNN "Value"
	1    7350 1900
	1    0    0    -1  
$EndComp
$Comp
L CP1 +C1
U 1 1 538CDDF3
P 3500 3400
F 0 "+C1" H 3550 3450 60  0001 C CNN
F 1 "CP1" H 3500 3400 60  0001 C CNN
F 2 "Capacitors_Tantalum_SMD:CP_Tantalum_Case-B_EIA-3528-21_Reflow" H 3500 3400 60  0000 C CNN
F 3 "~" H 3500 3400 60  0000 C CNN
	1    3500 3400
	1    0    0    -1  
$EndComp
NoConn ~ 5700 4050
$Comp
L R R2
U 1 1 53AFFA5B
P 6250 2650
F 0 "R2" V 6330 2650 40  0000 C CNN
F 1 "R" V 6257 2651 40  0000 C CNN
F 2 "Resistors_SMD:R_0603" V 6180 2650 30  0000 C CNN
F 3 "~" H 6250 2650 30  0000 C CNN
	1    6250 2650
	0    1    1    0   
$EndComp
$Comp
L R R3
U 1 1 53AFFA6A
P 6250 2250
F 0 "R3" V 6330 2250 40  0000 C CNN
F 1 "R" V 6257 2251 40  0000 C CNN
F 2 "Resistors_SMD:R_0603" V 6180 2250 30  0000 C CNN
F 3 "~" H 6250 2250 30  0000 C CNN
	1    6250 2250
	0    -1   -1   0   
$EndComp
$Comp
L R R4
U 1 1 53AFFA79
P 6250 2450
F 0 "R4" V 6330 2450 40  0000 C CNN
F 1 "R" V 6257 2451 40  0000 C CNN
F 2 "Resistors_SMD:R_0603" V 6180 2450 30  0000 C CNN
F 3 "~" H 6250 2450 30  0000 C CNN
	1    6250 2450
	0    -1   -1   0   
$EndComp
Text Label 5200 5450 0    60   ~ 0
Upstream MISO
Text Label 6900 5250 0    60   ~ 0
MISO
Text Label 5250 5150 0    60   ~ 0
RST
Text Label 5000 5050 0    60   ~ 0
CLK
Text Label 5300 4950 0    60   ~ 0
SS
Text Label 2850 4850 0    60   ~ 0
GND
Text Label 2800 4750 0    60   ~ 0
Vin
Text Label 5300 5250 0    60   ~ 0
MOSI
$Comp
L LED_RABG LED2
U 1 1 58BE9102
P 5600 2450
F 0 "LED2" H 5600 1985 50  0000 C CNN
F 1 "BGAR" H 5600 2076 50  0000 C CNN
F 2 "LEDs:LED_D5.0mm-4" H 5550 2400 50  0001 C CNN
F 3 "" H 5550 2400 50  0000 C CNN
	1    5600 2450
	-1   0    0    1   
$EndComp
$Comp
L CONN_01X03 P3
U 1 1 58BE95A4
P 6400 1900
F 0 "P3" H 6478 1941 50  0000 L CNN
F 1 "Light" H 6478 1850 50  0000 L CNN
F 2 "Connectors_JST:JST_XH_S03B-XH-A_03x2.50mm_Angled" H 6400 1900 50  0001 C CNN
F 3 "" H 6400 1900 50  0000 C CNN
	1    6400 1900
	1    0    0    1   
$EndComp
$Comp
L CONN_01X03 P4
U 1 1 58BE9674
P 7800 1950
F 0 "P4" H 7877 1991 50  0000 L CNN
F 1 "IR" H 7877 1900 50  0000 L CNN
F 2 "Connectors_JST:JST_XH_S03B-XH-A_03x2.50mm_Angled" H 7800 1950 50  0001 C CNN
F 3 "" H 7800 1950 50  0000 C CNN
	1    7800 1950
	1    0    0    1   
$EndComp
$Comp
L MMBT3906 Q1
U 1 1 58BEAE45
P 6600 5900
F 0 "Q1" V 6836 5900 50  0000 C CNN
F 1 "MMBT3906" V 6927 5900 50  0000 C CNN
F 2 "TO_SOT_Packages_SMD:SOT-23" V 7018 5900 50  0000 C CIN
F 3 "" H 6600 5900 50  0000 L CNN
	1    6600 5900
	0    1    1    0   
$EndComp
$Comp
L R R5
U 1 1 58BEB0EF
P 7200 5600
F 0 "R5" V 6993 5600 50  0000 C CNN
F 1 "R" V 7084 5600 50  0000 C CNN
F 2 "Resistors_SMD:R_0603" V 7130 5600 50  0001 C CNN
F 3 "" H 7200 5600 50  0000 C CNN
	1    7200 5600
	0    1    1    0   
$EndComp
$Comp
L LM7805CT U1
U 1 1 58BEB0F6
P 2500 3900
F 0 "U1" H 2500 4215 50  0000 C CNN
F 1 "LM7805" H 2500 4124 50  0000 C CNN
F 2 "TO_SOT_Packages_THT:TO-220_Horizontal" H 2500 3900 50  0001 C CNN
F 3 "" H 2500 3900 50  0000 C CNN
	1    2500 3900
	1    0    0    -1  
$EndComp
Wire Wire Line
	3300 2950 3600 2950
Wire Wire Line
	3050 1900 6200 1900
Wire Wire Line
	6200 3650 6200 2000
Wire Wire Line
	5700 3150 7600 3150
Wire Wire Line
	7600 3150 7600 2050
Wire Wire Line
	6250 3850 6500 3850
Wire Wire Line
	5700 3850 5950 3850
Wire Wire Line
	7000 1850 7600 1850
Wire Wire Line
	7100 4850 7100 1950
Wire Wire Line
	7100 1950 7600 1950
Connection ~ 7100 4850
Wire Wire Line
	7350 1700 7200 1700
Wire Wire Line
	7200 1700 7200 1850
Connection ~ 7200 1850
Wire Wire Line
	7350 2100 7200 2100
Wire Wire Line
	7200 2100 7200 1950
Connection ~ 7200 1950
Wire Wire Line
	5200 1650 4950 1650
Wire Wire Line
	4950 1650 4950 1800
Connection ~ 4950 1800
Wire Wire Line
	5200 2050 4950 2050
Wire Wire Line
	4950 2050 4950 1900
Connection ~ 4950 1900
Wire Wire Line
	5700 3350 7250 3350
Wire Wire Line
	5700 3950 6050 3950
Wire Wire Line
	3050 1900 3050 4850
Connection ~ 3050 4850
Wire Wire Line
	3600 4850 3600 4150
Connection ~ 3600 4850
Wire Wire Line
	5700 3650 6200 3650
Wire Wire Line
	6700 3250 5700 3250
Wire Wire Line
	6600 3050 5700 3050
Wire Wire Line
	6600 2250 6600 3050
Wire Wire Line
	6500 2950 5700 2950
Wire Wire Line
	4700 1400 4700 2450
Connection ~ 4700 1800
Wire Wire Line
	3500 3200 3300 3200
Connection ~ 3300 3200
Wire Wire Line
	3500 3550 3500 4500
Wire Wire Line
	3500 4500 3600 4500
Connection ~ 3600 4500
Wire Wire Line
	2600 5450 7450 5450
Wire Wire Line
	6400 5250 7450 5250
Wire Wire Line
	7000 5150 7450 5150
Wire Wire Line
	7000 1400 7000 5150
Wire Wire Line
	2600 5150 5700 5150
Wire Wire Line
	5700 5150 5700 4150
Wire Wire Line
	6900 3850 7100 3850
Connection ~ 7100 3850
Wire Wire Line
	2600 4850 7450 4850
Wire Wire Line
	5950 2100 7100 2100
Connection ~ 7100 2100
Connection ~ 5950 1900
Wire Wire Line
	3300 1800 6200 1800
Wire Wire Line
	2600 4750 7450 4750
Wire Wire Line
	4700 1400 7000 1400
Connection ~ 7000 1850
Wire Wire Line
	2600 4950 7450 4950
Wire Wire Line
	6050 3950 6050 4950
Connection ~ 6050 4950
Wire Wire Line
	2600 5050 7450 5050
Wire Wire Line
	7250 3350 7250 5050
Connection ~ 7250 5050
Wire Wire Line
	7350 1700 7350 1750
Wire Wire Line
	7350 2100 7350 2050
Wire Wire Line
	5200 1650 5200 1700
Wire Wire Line
	5200 2000 5200 2050
Wire Wire Line
	3500 3200 3500 3250
Wire Wire Line
	6500 2450 6500 2950
Wire Wire Line
	4700 2450 5300 2450
Wire Wire Line
	5900 2650 6100 2650
Wire Wire Line
	5900 2450 6100 2450
Wire Wire Line
	6600 2250 6400 2250
Wire Wire Line
	6100 2250 5900 2250
Wire Wire Line
	6400 2450 6500 2450
Wire Wire Line
	6400 2650 6700 2650
Wire Wire Line
	6700 2650 6700 3250
Wire Wire Line
	3300 5350 2600 5350
Wire Wire Line
	7450 5350 6600 5350
Wire Wire Line
	6600 5350 6600 5700
Connection ~ 6600 5600
Wire Wire Line
	6300 3550 6300 5250
Wire Wire Line
	6300 3550 5700 3550
Wire Wire Line
	6300 5250 2600 5250
Wire Wire Line
	6400 6000 6400 3450
Connection ~ 6400 5250
Wire Wire Line
	6400 3450 5700 3450
Wire Wire Line
	6850 5450 6850 6000
Wire Wire Line
	6850 6000 6800 6000
Connection ~ 6850 5450
Wire Wire Line
	2500 4150 3050 4150
Connection ~ 3050 4150
Wire Wire Line
	3300 3850 2900 3850
Wire Wire Line
	2700 4750 2700 4350
Wire Wire Line
	2700 4350 2100 4350
Wire Wire Line
	2100 4350 2100 3850
Connection ~ 2700 4750
Connection ~ 3300 3850
Wire Wire Line
	6600 5600 7050 5600
Wire Wire Line
	7350 5600 7350 4850
Connection ~ 7350 4850
Wire Wire Line
	3300 5350 3300 1800
Wire Wire Line
	5950 1900 5950 2100
$EndSCHEMATC
