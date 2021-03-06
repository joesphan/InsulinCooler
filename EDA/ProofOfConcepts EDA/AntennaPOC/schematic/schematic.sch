EESchema Schematic File Version 4
EELAYER 30 0
EELAYER END
$Descr USLetter 11000 8500
encoding utf-8
Sheet 1 3
Title ""
Date ""
Rev ""
Comp ""
Comment1 ""
Comment2 ""
Comment3 ""
Comment4 ""
$EndDescr
$Sheet
S 7350 1650 1300 2000
U 61F58C1A
F0 "MCU" 50
F1 "MCU.sch" 50
F2 "3V3" I L 7350 1800 50 
F3 "GND" I R 8650 3600 50 
F4 "RXD" I L 7350 2250 50 
F5 "TXD" I L 7350 2150 50 
F6 "DRIVER_N" I L 7350 2500 50 
F7 "DRIVER_P" I L 7350 2400 50 
F8 "TEMP_SENSE_1_P" I L 7350 2700 50 
F9 "TEMP_SENSE_2_N" I L 7350 3000 50 
F10 "TEMP_SENSE_3_N" I L 7350 3200 50 
F11 "TEMP_SENSE_1_N" I L 7350 2800 50 
F12 "TEMP_SENSE_2_P" I L 7350 2900 50 
F13 "TEMP_SENSE_3_P" I L 7350 3100 50 
$EndSheet
$Sheet
S 2550 1350 750  1400
U 61F95051
F0 "ports" 50
F1 "ports.sch" 50
F2 "TXD" I R 3300 2200 50 
F3 "RXD" I R 3300 2300 50 
F4 "GND" I L 2550 2700 50 
F5 "VUSB" I R 3300 1450 50 
F6 "VBAT" I R 3300 1700 50 
F7 "PWR_SW_P" I R 3300 1900 50 
F8 "PWR_SW_N" I R 3300 2000 50 
F9 "PELTIER_P" I R 3300 2500 50 
F10 "PELTIER_N" I R 3300 2650 50 
$EndSheet
Wire Wire Line
	4300 1450 3300 1450
Wire Wire Line
	4300 1700 3300 1700
Wire Wire Line
	3300 1900 4300 1900
Wire Wire Line
	4300 2000 3300 2000
Wire Wire Line
	3900 3550 3650 3550
Wire Wire Line
	3650 3550 3650 2500
Wire Wire Line
	3650 2500 3300 2500
Wire Wire Line
	3900 3700 3500 3700
Wire Wire Line
	3500 3700 3500 2650
Wire Wire Line
	3500 2650 3300 2650
Wire Wire Line
	6100 2100 6600 2100
Wire Wire Line
	6600 2100 6600 3300
Wire Wire Line
	6600 3300 6350 3300
$Comp
L power:GND #PWR0126
U 1 1 622C0D7B
P 4150 2450
F 0 "#PWR0126" H 4150 2200 50  0001 C CNN
F 1 "GND" H 4155 2277 50  0000 C CNN
F 2 "" H 4150 2450 50  0001 C CNN
F 3 "" H 4150 2450 50  0001 C CNN
	1    4150 2450
	1    0    0    -1  
$EndComp
$Comp
L power:GND #PWR0129
U 1 1 622C30CD
P 2350 2700
F 0 "#PWR0129" H 2350 2450 50  0001 C CNN
F 1 "GND" H 2355 2527 50  0000 C CNN
F 2 "" H 2350 2700 50  0001 C CNN
F 3 "" H 2350 2700 50  0001 C CNN
	1    2350 2700
	1    0    0    -1  
$EndComp
Wire Wire Line
	2550 2700 2350 2700
Wire Wire Line
	4150 2450 4300 2450
$Comp
L power:GND #PWR0138
U 1 1 622C37FC
P 3750 4500
F 0 "#PWR0138" H 3750 4250 50  0001 C CNN
F 1 "GND" H 3755 4327 50  0000 C CNN
F 2 "" H 3750 4500 50  0001 C CNN
F 3 "" H 3750 4500 50  0001 C CNN
	1    3750 4500
	1    0    0    -1  
$EndComp
Wire Wire Line
	3900 4500 3750 4500
$Comp
L power:GND #PWR0139
U 1 1 622C3DD1
P 8750 3600
F 0 "#PWR0139" H 8750 3350 50  0001 C CNN
F 1 "GND" H 8755 3427 50  0000 C CNN
F 2 "" H 8750 3600 50  0001 C CNN
F 3 "" H 8750 3600 50  0001 C CNN
	1    8750 3600
	-1   0    0    -1  
$EndComp
Wire Wire Line
	8650 3600 8750 3600
Wire Wire Line
	7350 2500 6900 2500
Wire Wire Line
	6900 2500 6900 3650
Wire Wire Line
	6900 3650 6350 3650
Wire Wire Line
	6350 3550 6850 3550
Wire Wire Line
	6850 3550 6850 2400
Wire Wire Line
	6850 2400 7350 2400
Wire Wire Line
	7350 2250 6750 2250
Wire Wire Line
	6750 2250 6750 2750
Wire Wire Line
	6750 2750 3750 2750
Wire Wire Line
	3750 2750 3750 2300
Wire Wire Line
	3750 2300 3300 2300
Wire Wire Line
	3300 2200 3800 2200
Wire Wire Line
	3800 2200 3800 2700
Wire Wire Line
	3800 2700 6700 2700
Wire Wire Line
	6700 2700 6700 2150
Wire Wire Line
	6700 2150 7350 2150
Wire Wire Line
	7350 4800 7300 4800
Wire Wire Line
	7300 4800 7300 3200
Wire Wire Line
	7300 3200 7350 3200
Wire Wire Line
	7350 3100 7250 3100
Wire Wire Line
	7250 3100 7250 4900
Wire Wire Line
	7250 4900 7350 4900
Wire Wire Line
	7350 5050 7200 5050
Wire Wire Line
	7200 5050 7200 3000
Wire Wire Line
	7200 3000 7350 3000
Wire Wire Line
	7350 2900 7150 2900
Wire Wire Line
	7150 2900 7150 5150
Wire Wire Line
	7150 5150 7350 5150
Wire Wire Line
	7350 5300 7100 5300
Wire Wire Line
	7100 5300 7100 2800
Wire Wire Line
	7100 2800 7350 2800
Wire Wire Line
	7350 2700 7050 2700
Wire Wire Line
	7050 2700 7050 5400
Wire Wire Line
	7050 5400 7350 5400
$Comp
L power:+3V3 #PWR0140
U 1 1 622D5851
P 6200 1800
F 0 "#PWR0140" H 6200 1650 50  0001 C CNN
F 1 "+3V3" H 6215 1973 50  0000 C CNN
F 2 "" H 6200 1800 50  0001 C CNN
F 3 "" H 6200 1800 50  0001 C CNN
	1    6200 1800
	1    0    0    -1  
$EndComp
Wire Wire Line
	6200 1800 6100 1800
$Comp
L power:+3V3 #PWR0141
U 1 1 622D6478
P 7150 1800
F 0 "#PWR0141" H 7150 1650 50  0001 C CNN
F 1 "+3V3" H 7165 1973 50  0000 C CNN
F 2 "" H 7150 1800 50  0001 C CNN
F 3 "" H 7150 1800 50  0001 C CNN
	1    7150 1800
	1    0    0    -1  
$EndComp
Wire Wire Line
	7150 1800 7350 1800
$Comp
L power:+3V3 #PWR0142
U 1 1 622D92B4
P 9300 4800
F 0 "#PWR0142" H 9300 4650 50  0001 C CNN
F 1 "+3V3" H 9315 4973 50  0000 C CNN
F 2 "" H 9300 4800 50  0001 C CNN
F 3 "" H 9300 4800 50  0001 C CNN
	1    9300 4800
	1    0    0    -1  
$EndComp
$Comp
L power:GND #PWR0143
U 1 1 622DA41E
P 9300 4900
F 0 "#PWR0143" H 9300 4650 50  0001 C CNN
F 1 "GND" H 9305 4727 50  0000 C CNN
F 2 "" H 9300 4900 50  0001 C CNN
F 3 "" H 9300 4900 50  0001 C CNN
	1    9300 4900
	-1   0    0    -1  
$EndComp
Wire Wire Line
	9200 4900 9300 4900
Wire Wire Line
	9300 4800 9200 4800
$EndSCHEMATC
