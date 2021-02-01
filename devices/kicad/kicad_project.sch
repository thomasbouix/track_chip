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
Text Label 5500 4450 0    50   ~ 0
GND
Text Label 6600 4700 2    50   ~ 0
VIN
Text Label 6600 4800 2    50   ~ 0
VIN
Text Label 6600 4900 2    50   ~ 0
GND
$Comp
L track_chip:bmp180 U?
U 1 1 600DBC2E
P 6700 4700
F 0 "U?" H 7278 4546 50  0000 L CNN
F 1 "bmp180" H 7278 4455 50  0000 L CNN
F 2 "" H 7000 4900 50  0001 C CNN
F 3 "" H 7000 4900 50  0001 C CNN
	1    6700 4700
	1    0    0    -1  
$EndComp
Text Label 6600 5000 2    50   ~ 0
SCL
Text Label 6600 5100 2    50   ~ 0
SDA
Text Label 5500 3550 0    50   ~ 0
SDA
Text Label 5500 3250 0    50   ~ 0
SCL
$Comp
L track_chip:brkws01 U?
U 1 1 60101594
P 7350 2850
F 0 "U?" V 7904 2978 50  0000 L CNN
F 1 "brkws01" V 7995 2978 50  0000 L CNN
F 2 "" H 7350 2850 50  0001 C CNN
F 3 "" H 7350 2850 50  0001 C CNN
	1    7350 2850
	0    1    1    0   
$EndComp
Text Label 6350 3150 2    50   ~ 0
TX0
Text Label 5500 3350 0    50   ~ 0
TX0
Text Label 5500 3450 0    50   ~ 0
RX0
Text Label 6350 3250 2    50   ~ 0
RX0
Text Label 6350 3750 2    50   ~ 0
VIN
Text Label 6350 3850 2    50   ~ 0
GND
$Comp
L track_chip:Earth #PWR?
U 1 1 6017D946
P 5200 2500
F 0 "#PWR?" H 5200 2250 50  0001 C CNN
F 1 "Earth" H 5200 2350 50  0001 C CNN
F 2 "" H 5200 2500 50  0001 C CNN
F 3 "~" H 5200 2500 50  0001 C CNN
	1    5200 2500
	1    0    0    -1  
$EndComp
Text Label 5200 2500 0    50   ~ 0
GND
Text Label 4600 2600 0    50   ~ 0
VIN
$Comp
L track_chip:ADA746 U?
U 1 1 6017EC9D
P 3500 4250
F 0 "U?" H 3867 3185 50  0000 C CNN
F 1 "ADA746" H 3867 3276 50  0000 C CNN
F 2 "" H 3500 4350 50  0001 C CNN
F 3 "" H 3500 4350 50  0001 C CNN
	1    3500 4250
	-1   0    0    1   
$EndComp
$Comp
L track_chip:+3.3V #PWR?
U 1 1 6017D55A
P 4600 2600
F 0 "#PWR?" H 4600 2450 50  0001 C CNN
F 1 "+3.3V" H 4615 2773 50  0000 C CNN
F 2 "" H 4600 2600 50  0001 C CNN
F 3 "" H 4600 2600 50  0001 C CNN
	1    4600 2600
	1    0    0    -1  
$EndComp
Text Label 3600 3550 0    50   ~ 0
VIN
Text Label 3600 3650 0    50   ~ 0
GND
Text Label 3600 3750 0    50   ~ 0
RX2
Text Label 3600 3850 0    50   ~ 0
TX2
Text Label 3600 4250 0    50   ~ 0
VIN
Text Label 3600 4050 0    50   ~ 0
VIN
Text Label 5500 3950 0    50   ~ 0
TX2
Text Label 5500 4050 0    50   ~ 0
RX2
$EndSCHEMATC
