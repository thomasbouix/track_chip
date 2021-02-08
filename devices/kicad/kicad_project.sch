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
P 6700 4700
F 0 "U4" H 7278 4546 50  0000 L CNN
F 1 "bmp180" H 7278 4455 50  0000 L CNN
F 2 "track_chip:bmp180" H 7000 4900 50  0001 C CNN
F 3 "" H 7000 4900 50  0001 C CNN
	1    6700 4700
	1    0    0    -1  
$EndComp
$Comp
L kicad_project-rescue:brkws01-track_chip U1
U 1 1 60101594
P 7350 2850
F 0 "U1" V 7904 2978 50  0000 L CNN
F 1 "brkws01-track_chip" V 7995 2978 50  0000 L CNN
F 2 "" H 7350 2850 50  0001 C CNN
F 3 "" H 7350 2850 50  0001 C CNN
	1    7350 2850
	0    1    1    0   
$EndComp
$Comp
L track_chip:Earth #PWR0101
U 1 1 6017D946
P 5200 2600
F 0 "#PWR0101" H 5200 2350 50  0001 C CNN
F 1 "Earth" H 5200 2450 50  0001 C CNN
F 2 "" H 5200 2600 50  0001 C CNN
F 3 "~" H 5200 2600 50  0001 C CNN
	1    5200 2600
	1    0    0    -1  
$EndComp
$Comp
L track_chip:ADA746 U3
U 1 1 6017EC9D
P 3500 4250
F 0 "U3" H 3867 3185 50  0000 C CNN
F 1 "ADA746" H 3867 3276 50  0000 C CNN
F 2 "" H 3500 4350 50  0001 C CNN
F 3 "" H 3500 4350 50  0001 C CNN
	1    3500 4250
	-1   0    0    1   
$EndComp
$Comp
L track_chip:+3.3V #PWR0102
U 1 1 6017D55A
P 4600 2600
F 0 "#PWR0102" H 4600 2450 50  0001 C CNN
F 1 "+3.3V" H 4615 2773 50  0000 C CNN
F 2 "" H 4600 2600 50  0001 C CNN
F 3 "" H 4600 2600 50  0001 C CNN
	1    4600 2600
	-1   0    0    1   
$EndComp
NoConn ~ 7350 2750
NoConn ~ 7250 2750
NoConn ~ 7150 2750
NoConn ~ 7050 2750
NoConn ~ 6950 2750
NoConn ~ 6850 2750
NoConn ~ 6750 2750
NoConn ~ 6650 2750
NoConn ~ 6850 4150
NoConn ~ 6950 4150
NoConn ~ 7050 4150
NoConn ~ 7150 4150
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
NoConn ~ 3600 4150
NoConn ~ 3600 3950
NoConn ~ 3600 3450
NoConn ~ 6350 3350
NoConn ~ 6350 3450
NoConn ~ 5500 3850
Text GLabel 3600 3550 2    50   Input ~ 0
VIN
Text GLabel 3600 3650 2    50   Input ~ 0
GND
Text GLabel 3600 4050 2    50   Input ~ 0
VIN
Text GLabel 3600 3750 2    50   Input ~ 0
RX2
Text GLabel 3600 3850 2    50   Input ~ 0
TX2
Text GLabel 3600 4250 2    50   Input ~ 0
VIN
Text GLabel 4450 2500 0    50   Input ~ 0
VIN
Text GLabel 5050 2500 0    50   Input ~ 0
GND
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
NoConn ~ 6350 3650
Text GLabel 6600 4700 0    50   Input ~ 0
VIN
Text GLabel 6600 4800 0    50   Input ~ 0
VIN
Text GLabel 6600 4900 0    50   Input ~ 0
GND
Text GLabel 6600 5000 0    50   Input ~ 0
SCL
Text GLabel 6600 5100 0    50   Input ~ 0
SDA
Text GLabel 6350 3750 0    50   Input ~ 0
VIN
Text GLabel 6350 3850 0    50   Input ~ 0
GND
Text GLabel 6350 3150 0    50   Input ~ 0
TX0
Text GLabel 6350 3250 0    50   Input ~ 0
RX0
Wire Wire Line
	4450 2500 4600 2500
Wire Wire Line
	4600 2500 4600 2600
Wire Wire Line
	5200 2600 5200 2500
Wire Wire Line
	5200 2500 5050 2500
$EndSCHEMATC
