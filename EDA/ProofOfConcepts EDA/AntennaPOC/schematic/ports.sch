EESchema Schematic File Version 4
EELAYER 30 0
EELAYER END
$Descr A4 11693 8268
encoding utf-8
Sheet 3 3
Title ""
Date ""
Rev ""
Comp ""
Comment1 ""
Comment2 ""
Comment3 ""
Comment4 ""
$EndDescr
Wire Wire Line
	5600 1800 4600 1800
Wire Wire Line
	4600 1700 5900 1700
$Comp
L power:GND #PWR?
U 1 1 62120404
P 5800 2200
AR Path="/62120404" Ref="#PWR?"  Part="1" 
AR Path="/61F95051/62120404" Ref="#PWR0125"  Part="1" 
F 0 "#PWR0125" H 5800 1950 50  0001 C CNN
F 1 "GND" H 5805 2027 50  0000 C CNN
F 2 "" H 5800 2200 50  0001 C CNN
F 3 "" H 5800 2200 50  0001 C CNN
	1    5800 2200
	1    0    0    -1  
$EndComp
Wire Wire Line
	5600 2100 5600 2150
Wire Wire Line
	5600 2150 5800 2150
Wire Wire Line
	5800 2150 5800 2200
Wire Wire Line
	5800 2150 5900 2150
Wire Wire Line
	5900 2150 5900 2000
Connection ~ 5800 2150
Text Notes 5400 1200 0    50   ~ 0
Uninstall after programming\n\n!3.3v only! UART mapping:\nD+   TXD\nD-    RXD
Text HLabel 6650 3000 2    50   Input ~ 0
TXD
Text HLabel 6650 2900 2    50   Input ~ 0
RXD
Wire Wire Line
	6350 2900 6650 2900
Wire Wire Line
	6650 3000 6350 3000
Text HLabel 6650 3250 2    50   Input ~ 0
GND
Wire Wire Line
	3700 3250 3700 3000
Wire Wire Line
	4000 3000 4000 3250
Connection ~ 4000 3250
Wire Wire Line
	4000 3250 3700 3250
Text HLabel 6650 2600 2    50   Input ~ 0
VUSB
Wire Wire Line
	6450 2600 6450 1500
Wire Wire Line
	6450 1500 4600 1500
Wire Wire Line
	6650 2600 6450 2600
Wire Wire Line
	4000 3250 4300 3250
Wire Wire Line
	3900 4000 4300 4000
Wire Wire Line
	4300 4000 4300 3250
Connection ~ 4300 3250
Wire Wire Line
	4300 3250 6650 3250
Wire Wire Line
	3900 4100 4650 4100
Wire Wire Line
	4650 4100 4650 3450
Text HLabel 6650 3450 2    50   Input ~ 0
VBAT
Wire Wire Line
	4650 3450 6650 3450
Text HLabel 6650 3750 2    50   Input ~ 0
PWR_SW_P
Text HLabel 6650 3950 2    50   Input ~ 0
PWR_SW_N
Wire Wire Line
	6650 3950 5100 3950
Wire Wire Line
	5100 3950 5100 5250
Wire Wire Line
	5100 5250 4000 5250
Wire Wire Line
	4000 5250 4000 5100
Wire Wire Line
	4000 4500 4000 4250
Wire Wire Line
	4000 4250 4950 4250
Wire Wire Line
	4950 4250 4950 3750
Wire Wire Line
	4950 3750 6650 3750
Text HLabel 6650 4200 2    50   Input ~ 0
PELTIER_P
Text HLabel 6650 4400 2    50   Input ~ 0
PELTIER_N
Wire Wire Line
	4200 5800 5350 5800
Wire Wire Line
	5350 5800 5350 4200
Wire Wire Line
	5350 4200 6650 4200
Wire Wire Line
	6650 4400 5550 4400
Wire Wire Line
	5550 4400 5550 5900
Wire Wire Line
	5550 5900 4200 5900
$EndSCHEMATC
