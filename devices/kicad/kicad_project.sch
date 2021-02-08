EESchema Schematic File Version 4
LIBS:kicad_project-cache
EELAYER 30 0
EELAYER END
$Descr A4 11693 8268
encoding utf-8
Sheet 1 1
Title ""
Date ""
Rev ""
Comp ""
Comment1 ""
Comment2 ""
Comment3 ""
Comment4 ""
$EndDescr
$Comp
L kicad_project-rescue:esp32_NodeMCU-track_chip U2
U 1 1 600DACF0
P 4500 3150
F 0 "U2" H 4950 3415 50  0000 C CNN
F 1 "esp32_NodeMCU-track_chip" H 4950 3324 50  0000 C CNN
F 2 "track_chip:esp32" H 4950 3300 50  0001 C CNN
F 3 "" H 4950 3300 50  0001 C CNN
	1    4500 3150
	1    0    0    -1  
$EndComp
$Comp
L kicad_project-rescue:bmp180-track_chip U4
U 1 1 600DBC2E
P 6850 3100
F 0 "U4" H 7428 2946 50  0000 L CNN
F 1 "bmp180" H 7428 2855 50  0000 L CNN
F 2 "track_chip:bmp180" H 7150 3300 50  0001 C CNN
F 3 "" H 7150 3300 50  0001 C CNN
	1    6850 3100
	1    0    0    -1  
$EndComp
NoConn ~ 5500 4550
NoConn ~ 5500 4350
NoConn ~ 5500 4250
NoConn ~ 5500 4150
NoConn ~ 5500 3750
NoConn ~ 5500 3650
NoConn ~ 4400 3150
NoConn ~ 4400 3250
NoConn ~ 4400 3350
NoConn ~ 4400 3450
NoConn ~ 4400 3550
NoConn ~ 4400 3650
NoConn ~ 4400 3750
NoConn ~ 4400 3850
NoConn ~ 4400 3950
NoConn ~ 4400 4050
NoConn ~ 4400 4150
NoConn ~ 4400 4250
NoConn ~ 4400 4350
NoConn ~ 4400 4450
NoConn ~ 4400 4550
NoConn ~ 5500 3850
Text GLabel 5500 3250 2    50   Input ~ 0
SCL
Text GLabel 5500 3350 2    50   Input ~ 0
TX0
Text GLabel 5500 3450 2    50   Input ~ 0
RX0
Text GLabel 5500 3550 2    50   Input ~ 0
SDA
Text GLabel 5500 3950 2    50   Input ~ 0
TX2
Text GLabel 5500 4050 2    50   Input ~ 0
RX2
Text GLabel 5500 4450 2    50   Input ~ 0
GND
NoConn ~ 5500 3150
Text GLabel 6750 3100 0    50   Input ~ 0
VIN
Text GLabel 6750 3200 0    50   Input ~ 0
VIN
Text GLabel 6750 3300 0    50   Input ~ 0
GND
Text GLabel 6750 3400 0    50   Input ~ 0
SCL
Text GLabel 6750 3500 0    50   Input ~ 0
SDA
$Comp
L track_chip:GPS_PA6H U3
U 1 1 60213494
P 6750 3750
F 0 "U3" H 7092 2735 50  0000 C CNN
F 1 "GPS_PA6H" H 7092 2826 50  0000 C CNN
F 2 "track_chip:GPS_PA6H" H 6750 3750 50  0001 C CNN
F 3 "" H 6750 3750 50  0001 C CNN
	1    6750 3750
	1    0    0    -1  
$EndComp
NoConn ~ 6650 4550
NoConn ~ 6650 4050
NoConn ~ 6650 3850
Text GLabel 6650 4450 0    50   Input ~ 0
VIN
Text GLabel 6650 4350 0    50   Input ~ 0
GND
Text GLabel 6650 4150 0    50   Input ~ 0
TX0
Text GLabel 6650 4250 0    50   Input ~ 0
RX0
NoConn ~ 6650 3750
NoConn ~ 6650 3950
$Comp
L track_chip:SIM800L U1
U 1 1 60218FF3
P 3250 3900
F 0 "U1" H 3978 3701 50  0000 L CNN
F 1 "SIM800L" H 3978 3610 50  0000 L CNN
F 2 "track_chip:SIM800L" H 3250 3900 50  0001 C CNN
F 3 "" H 3250 3900 50  0001 C CNN
	1    3250 3900
	1    0    0    -1  
$EndComp
Text GLabel 3150 4300 0    50   Input ~ 0
TX0
Text GLabel 3150 4200 0    50   Input ~ 0
RX0
NoConn ~ 3150 4100
NoConn ~ 3150 3900
$Comp
L track_chip:polulu U5
U 1 1 6021A9B1
P 3250 3100
F 0 "U5" H 3928 3001 50  0000 L CNN
F 1 "polulu" H 3928 2910 50  0000 L CNN
F 2 "track_chip:polulu" H 3250 3100 50  0001 C CNN
F 3 "" H 3250 3100 50  0001 C CNN
	1    3250 3100
	1    0    0    -1  
$EndComp
Text GLabel 3150 3200 0    50   Input ~ 0
VIN
Text GLabel 3150 3300 0    50   Input ~ 0
GND
NoConn ~ 3150 3100
$Comp
L Device:D D2
U 1 1 6021D78B
P 2500 4000
F 0 "D2" H 2500 3784 50  0000 C CNN
F 1 "D" H 2500 3875 50  0000 C CNN
F 2 "" H 2500 4000 50  0001 C CNN
F 3 "~" H 2500 4000 50  0001 C CNN
	1    2500 4000
	-1   0    0    1   
$EndComp
$Comp
L Device:C C1
U 1 1 6021E3B7
P 2650 4350
F 0 "C1" H 2765 4396 50  0000 L CNN
F 1 "C" H 2765 4305 50  0000 L CNN
F 2 "" H 2688 4200 50  0001 C CNN
F 3 "~" H 2650 4350 50  0001 C CNN
	1    2650 4350
	1    0    0    -1  
$EndComp
Wire Wire Line
	2650 4000 2650 4200
$Comp
L track_chip:Earth #PWR0103
U 1 1 6021F058
P 2650 4750
F 0 "#PWR0103" H 2650 4500 50  0001 C CNN
F 1 "Earth" H 2650 4600 50  0001 C CNN
F 2 "" H 2650 4750 50  0001 C CNN
F 3 "~" H 2650 4750 50  0001 C CNN
	1    2650 4750
	1    0    0    -1  
$EndComp
Wire Wire Line
	2650 4500 2650 4600
Wire Wire Line
	2650 4000 3150 4000
Connection ~ 2650 4000
Wire Wire Line
	3150 4400 3150 4600
Wire Wire Line
	3150 4600 2650 4600
Connection ~ 2650 4600
Wire Wire Line
	2650 4600 2650 4750
Text GLabel 2650 4600 0    50   Input ~ 0
GND
$Comp
L track_chip:batterie U6
U 1 1 60221E39
P 3550 2450
F 0 "U6" V 4013 2072 50  0000 R CNN
F 1 "batterie" V 3922 2072 50  0000 R CNN
F 2 "" H 3550 2450 50  0001 C CNN
F 3 "" H 3550 2450 50  0001 C CNN
	1    3550 2450
	-1   0    0    1   
$EndComp
Text GLabel 3750 2450 2    50   Input ~ 0
VIN
Text GLabel 3900 2350 2    50   Input ~ 0
GND
Wire Wire Line
	3650 2450 3750 2450
Wire Wire Line
	3900 2350 3650 2350
Wire Wire Line
	3150 3400 2350 3400
Wire Wire Line
	2350 3400 2350 4000
$EndSCHEMATC
