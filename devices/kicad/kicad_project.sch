EESchema Schematic File Version 4
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
L track_chip:esp32_NodeMCU U?
U 1 1 600DACF0
P 4500 3150
F 0 "U?" H 4950 3415 50  0000 C CNN
F 1 "esp32_NodeMCU" H 4950 3324 50  0000 C CNN
F 2 "" H 4950 3300 50  0001 C CNN
F 3 "" H 4950 3300 50  0001 C CNN
	1    4500 3150
	1    0    0    -1  
$EndComp
$Comp
L power:Earth #PWR?
U 1 1 600DC354
P 6650 2300
F 0 "#PWR?" H 6650 2050 50  0001 C CNN
F 1 "Earth" H 6650 2150 50  0001 C CNN
F 2 "" H 6650 2300 50  0001 C CNN
F 3 "~" H 6650 2300 50  0001 C CNN
	1    6650 2300
	1    0    0    -1  
$EndComp
$Comp
L power:+3.3V #PWR?
U 1 1 600DC827
P 5800 2350
F 0 "#PWR?" H 5800 2200 50  0001 C CNN
F 1 "+3.3V" H 5815 2523 50  0000 C CNN
F 2 "" H 5800 2350 50  0001 C CNN
F 3 "" H 5800 2350 50  0001 C CNN
	1    5800 2350
	1    0    0    -1  
$EndComp
Text Label 6650 2300 0    50   ~ 0
GND
Text Label 5500 4450 0    50   ~ 0
GND
Text Label 5800 2350 0    50   ~ 0
VIN
Text Label 6600 3650 2    50   ~ 0
VIN
Text Label 6600 3750 2    50   ~ 0
VIN
Text Label 6600 3850 2    50   ~ 0
GND
$Comp
L track_chip:bmp180 U?
U 1 1 600DBC2E
P 6700 3650
F 0 "U?" H 7278 3496 50  0000 L CNN
F 1 "bmp180" H 7278 3405 50  0000 L CNN
F 2 "" H 7000 3850 50  0001 C CNN
F 3 "" H 7000 3850 50  0001 C CNN
	1    6700 3650
	1    0    0    -1  
$EndComp
Text Label 6600 3950 2    50   ~ 0
SCL
Text Label 6600 4050 2    50   ~ 0
SDA
Text Label 5500 3550 0    50   ~ 0
SDA
Text Label 5500 3250 0    50   ~ 0
SCL
$EndSCHEMATC
