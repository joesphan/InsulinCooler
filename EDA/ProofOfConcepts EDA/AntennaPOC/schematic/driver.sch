EESchema Schematic File Version 4
EELAYER 30 0
EELAYER END
$Descr A4 11693 8268
encoding utf-8
Sheet 6 6
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
	5000 4800 6800 4800
Wire Wire Line
	6800 4800 6800 4600
$Comp
L power:GND #PWR?
U 1 1 621CE95A
P 5000 4900
AR Path="/621CE95A" Ref="#PWR?"  Part="1" 
AR Path="/6200D680/621CE95A" Ref="#PWR0119"  Part="1" 
F 0 "#PWR0119" H 5000 4650 50  0001 C CNN
F 1 "GND" H 5005 4727 50  0000 C CNN
F 2 "" H 5000 4900 50  0001 C CNN
F 3 "" H 5000 4900 50  0001 C CNN
	1    5000 4900
	1    0    0    -1  
$EndComp
Wire Wire Line
	5000 4900 5000 4800
Connection ~ 5000 4800
$Comp
L schematic-rescue:BUK9K52-60E-1KicadLib U?
U 2 1 621CE96D
P 5000 4250
AR Path="/621CE96D" Ref="U?"  Part="2" 
AR Path="/6200D680/621CE96D" Ref="U3"  Part="2" 
F 0 "U3" H 5104 4271 50  0000 L CNN
F 1 "BUK9K52-60E" H 5104 4180 50  0000 L CNN
F 2 "1KicadLib:LFPAK56D" H 5000 4250 50  0001 C CNN
F 3 "" H 5000 4250 50  0001 C CNN
	2    5000 4250
	1    0    0    -1  
$EndComp
Wire Wire Line
	5000 4600 5000 4800
Wire Wire Line
	5000 3950 5000 3900
$Comp
L schematic-rescue:BUK9K52-60E-1KicadLib U?
U 2 1 621CE975
P 6800 4250
AR Path="/621CE975" Ref="U?"  Part="2" 
AR Path="/6200D680/621CE975" Ref="U4"  Part="2" 
F 0 "U4" H 6905 4271 50  0000 L CNN
F 1 "BUK9K52-60E" H 6905 4180 50  0000 L CNN
F 2 "1KicadLib:LFPAK56D" H 6800 4250 50  0001 C CNN
F 3 "" H 6800 4250 50  0001 C CNN
	2    6800 4250
	-1   0    0    -1  
$EndComp
$Comp
L schematic-rescue:BUK9K52-60E-1KicadLib U?
U 1 1 621CE97B
P 6800 3550
AR Path="/621CE97B" Ref="U?"  Part="1" 
AR Path="/6200D680/621CE97B" Ref="U4"  Part="1" 
F 0 "U4" H 6905 3571 50  0000 L CNN
F 1 "BUK9K52-60E" H 6905 3480 50  0000 L CNN
F 2 "1KicadLib:LFPAK56D" H 6800 3550 50  0001 C CNN
F 3 "" H 6800 3550 50  0001 C CNN
	1    6800 3550
	-1   0    0    -1  
$EndComp
Wire Wire Line
	6800 3950 6800 3900
$Comp
L Driver_FET:IRS2103 U?
U 1 1 621CE983
P 3150 3750
AR Path="/621CE983" Ref="U?"  Part="1" 
AR Path="/6200D680/621CE983" Ref="U2"  Part="1" 
F 0 "U2" H 3150 4431 50  0000 C CNN
F 1 "IRS2103" H 3150 4340 50  0000 C CNN
F 2 "Package_SO:SOIC-8_3.9x4.9mm_P1.27mm" H 3150 3750 50  0001 C CIN
F 3 "https://www.infineon.com/dgdl/irs2103.pdf?fileId=5546d462533600a4015356762b71279f" H 3150 3750 50  0001 C CNN
	1    3150 3750
	1    0    0    -1  
$EndComp
$Comp
L schematic-rescue:BUK9K52-60E-1KicadLib U?
U 1 1 621CE98E
P 5000 3550
AR Path="/621CE98E" Ref="U?"  Part="1" 
AR Path="/6200D680/621CE98E" Ref="U3"  Part="1" 
F 0 "U3" H 5104 3571 50  0000 L CNN
F 1 "BUK9K52-60E" H 5104 3480 50  0000 L CNN
F 2 "1KicadLib:LFPAK56D" H 5000 3550 50  0001 C CNN
F 3 "" H 5000 3550 50  0001 C CNN
	1    5000 3550
	1    0    0    -1  
$EndComp
$Comp
L Device:R R?
U 1 1 621CE994
P 4350 3550
AR Path="/621CE994" Ref="R?"  Part="1" 
AR Path="/6200D680/621CE994" Ref="R2"  Part="1" 
F 0 "R2" V 4143 3550 50  0000 C CNN
F 1 "10k" V 4234 3550 50  0000 C CNN
F 2 "Resistor_SMD:R_0805_2012Metric_Pad1.20x1.40mm_HandSolder" V 4280 3550 50  0001 C CNN
F 3 "~" H 4350 3550 50  0001 C CNN
	1    4350 3550
	0    1    1    0   
$EndComp
$Comp
L Device:R R?
U 1 1 621CE99A
P 4350 4250
AR Path="/621CE99A" Ref="R?"  Part="1" 
AR Path="/6200D680/621CE99A" Ref="R3"  Part="1" 
F 0 "R3" V 4143 4250 50  0000 C CNN
F 1 "10k" V 4234 4250 50  0000 C CNN
F 2 "Resistor_SMD:R_0805_2012Metric_Pad1.20x1.40mm_HandSolder" V 4280 4250 50  0001 C CNN
F 3 "~" H 4350 4250 50  0001 C CNN
	1    4350 4250
	0    1    1    0   
$EndComp
Wire Wire Line
	4500 3550 4650 3550
Wire Wire Line
	4500 4250 4650 4250
$Comp
L Device:C C?
U 1 1 621CE9A2
P 3700 3750
AR Path="/621CE9A2" Ref="C?"  Part="1" 
AR Path="/6200D680/621CE9A2" Ref="C12"  Part="1" 
F 0 "C12" H 3815 3796 50  0000 L CNN
F 1 "10uF" H 3815 3705 50  0000 L CNN
F 2 "Capacitor_SMD:C_0805_2012Metric_Pad1.18x1.45mm_HandSolder" H 3738 3600 50  0001 C CNN
F 3 "~" H 3700 3750 50  0001 C CNN
	1    3700 3750
	1    0    0    -1  
$EndComp
Wire Wire Line
	3450 3550 4200 3550
Wire Wire Line
	3450 4050 3550 4050
Wire Wire Line
	3550 4050 3550 4250
Wire Wire Line
	3550 4250 4200 4250
Wire Wire Line
	3700 3950 3700 3900
Wire Wire Line
	3700 3950 3450 3950
$Comp
L Device:D D?
U 1 1 621CE9B2
P 3450 2850
AR Path="/621CE9B2" Ref="D?"  Part="1" 
AR Path="/6200D680/621CE9B2" Ref="D1"  Part="1" 
F 0 "D1" H 3450 2633 50  0000 C CNN
F 1 "1N5819" H 3450 2724 50  0000 C CNN
F 2 "Diode_THT:D_DO-41_SOD81_P10.16mm_Horizontal" H 3450 2850 50  0001 C CNN
F 3 "~" H 3450 2850 50  0001 C CNN
	1    3450 2850
	-1   0    0    1   
$EndComp
Wire Wire Line
	3600 2850 3700 2850
Wire Wire Line
	3700 2850 3700 3450
Wire Wire Line
	3300 2850 3150 2850
Wire Wire Line
	3150 2850 3150 3150
$Comp
L Device:C C?
U 1 1 621CE9BD
P 2500 4300
AR Path="/621CE9BD" Ref="C?"  Part="1" 
AR Path="/6200D680/621CE9BD" Ref="C11"  Part="1" 
F 0 "C11" H 2615 4346 50  0000 L CNN
F 1 "10uF" H 2615 4255 50  0000 L CNN
F 2 "Capacitor_SMD:C_0805_2012Metric_Pad1.18x1.45mm_HandSolder" H 2538 4150 50  0001 C CNN
F 3 "~" H 2500 4300 50  0001 C CNN
	1    2500 4300
	1    0    0    -1  
$EndComp
Wire Wire Line
	2500 4150 2500 3150
Wire Wire Line
	2500 3150 3150 3150
Connection ~ 3150 3150
Wire Wire Line
	3150 3150 3150 3250
Wire Wire Line
	3150 4250 3150 4600
Wire Wire Line
	3150 4600 3050 4600
Wire Wire Line
	2500 4600 2500 4450
Connection ~ 3150 2850
$Comp
L Driver_FET:IRS2103 U?
U 1 1 621CE9D2
P 8650 3750
AR Path="/621CE9D2" Ref="U?"  Part="1" 
AR Path="/6200D680/621CE9D2" Ref="U5"  Part="1" 
F 0 "U5" H 8650 4431 50  0000 C CNN
F 1 "IRS2103" H 8650 4340 50  0000 C CNN
F 2 "Package_SO:SOIC-8_3.9x4.9mm_P1.27mm" H 8650 3750 50  0001 C CIN
F 3 "https://www.infineon.com/dgdl/irs2103.pdf?fileId=5546d462533600a4015356762b71279f" H 8650 3750 50  0001 C CNN
	1    8650 3750
	-1   0    0    -1  
$EndComp
$Comp
L Device:R R?
U 1 1 621CE9D8
P 7450 3550
AR Path="/621CE9D8" Ref="R?"  Part="1" 
AR Path="/6200D680/621CE9D8" Ref="R4"  Part="1" 
F 0 "R4" V 7243 3550 50  0000 C CNN
F 1 "10k" V 7334 3550 50  0000 C CNN
F 2 "Resistor_SMD:R_0805_2012Metric_Pad1.20x1.40mm_HandSolder" V 7380 3550 50  0001 C CNN
F 3 "~" H 7450 3550 50  0001 C CNN
	1    7450 3550
	0    -1   1    0   
$EndComp
$Comp
L Device:R R?
U 1 1 621CE9DE
P 7450 4250
AR Path="/621CE9DE" Ref="R?"  Part="1" 
AR Path="/6200D680/621CE9DE" Ref="R5"  Part="1" 
F 0 "R5" V 7243 4250 50  0000 C CNN
F 1 "10k" V 7334 4250 50  0000 C CNN
F 2 "Resistor_SMD:R_0805_2012Metric_Pad1.20x1.40mm_HandSolder" V 7380 4250 50  0001 C CNN
F 3 "~" H 7450 4250 50  0001 C CNN
	1    7450 4250
	0    -1   1    0   
$EndComp
Wire Wire Line
	7300 3550 7150 3550
Wire Wire Line
	7300 4250 7150 4250
$Comp
L Device:C C?
U 1 1 621CE9E6
P 8100 3750
AR Path="/621CE9E6" Ref="C?"  Part="1" 
AR Path="/6200D680/621CE9E6" Ref="C13"  Part="1" 
F 0 "C13" H 8215 3796 50  0000 L CNN
F 1 "10uF" H 8215 3705 50  0000 L CNN
F 2 "Capacitor_SMD:C_0805_2012Metric_Pad1.18x1.45mm_HandSolder" H 8138 3600 50  0001 C CNN
F 3 "~" H 8100 3750 50  0001 C CNN
	1    8100 3750
	-1   0    0    -1  
$EndComp
Wire Wire Line
	8350 3550 7600 3550
Wire Wire Line
	8350 4050 8250 4050
Wire Wire Line
	8250 4050 8250 4250
Wire Wire Line
	8250 4250 7600 4250
Wire Wire Line
	8100 3950 8350 3950
$Comp
L Device:D D?
U 1 1 621CE9F6
P 8350 2850
AR Path="/621CE9F6" Ref="D?"  Part="1" 
AR Path="/6200D680/621CE9F6" Ref="D2"  Part="1" 
F 0 "D2" H 8350 2633 50  0000 C CNN
F 1 "1N5819" H 8350 2724 50  0000 C CNN
F 2 "Diode_THT:D_DO-41_SOD81_P10.16mm_Horizontal" H 8350 2850 50  0001 C CNN
F 3 "~" H 8350 2850 50  0001 C CNN
	1    8350 2850
	1    0    0    1   
$EndComp
Wire Wire Line
	8200 2850 8100 2850
Wire Wire Line
	8100 2850 8100 3450
Wire Wire Line
	8500 2850 8650 2850
Wire Wire Line
	8650 2850 8650 3150
$Comp
L Device:C C?
U 1 1 621CEA01
P 9300 4300
AR Path="/621CEA01" Ref="C?"  Part="1" 
AR Path="/6200D680/621CEA01" Ref="C14"  Part="1" 
F 0 "C14" H 9415 4346 50  0000 L CNN
F 1 "10uF" H 9415 4255 50  0000 L CNN
F 2 "Capacitor_SMD:C_0805_2012Metric_Pad1.18x1.45mm_HandSolder" H 9338 4150 50  0001 C CNN
F 3 "~" H 9300 4300 50  0001 C CNN
	1    9300 4300
	-1   0    0    -1  
$EndComp
Wire Wire Line
	9300 4150 9300 3150
Wire Wire Line
	9300 3150 8650 3150
Connection ~ 8650 3150
Wire Wire Line
	8650 3150 8650 3250
Wire Wire Line
	8650 4250 8650 4600
Wire Wire Line
	8650 4600 8750 4600
Wire Wire Line
	9300 4600 9300 4450
Connection ~ 8650 2850
$Comp
L power:GND #PWR?
U 1 1 621CEA16
P 3050 4600
AR Path="/621CEA16" Ref="#PWR?"  Part="1" 
AR Path="/6200D680/621CEA16" Ref="#PWR0120"  Part="1" 
F 0 "#PWR0120" H 3050 4350 50  0001 C CNN
F 1 "GND" H 3055 4427 50  0000 C CNN
F 2 "" H 3050 4600 50  0001 C CNN
F 3 "" H 3050 4600 50  0001 C CNN
	1    3050 4600
	1    0    0    -1  
$EndComp
Connection ~ 3050 4600
Wire Wire Line
	3050 4600 2500 4600
Wire Wire Line
	2850 3850 2200 3850
Wire Wire Line
	2200 3850 2200 3750
Wire Wire Line
	2200 3750 2850 3750
Wire Wire Line
	8950 3850 9600 3850
Wire Wire Line
	9600 3850 9600 3750
Wire Wire Line
	9600 3750 8950 3750
$Comp
L power:GND #PWR?
U 1 1 621CEA26
P 8750 4600
AR Path="/621CEA26" Ref="#PWR?"  Part="1" 
AR Path="/6200D680/621CEA26" Ref="#PWR0121"  Part="1" 
F 0 "#PWR0121" H 8750 4350 50  0001 C CNN
F 1 "GND" H 8755 4427 50  0000 C CNN
F 2 "" H 8750 4600 50  0001 C CNN
F 3 "" H 8750 4600 50  0001 C CNN
	1    8750 4600
	1    0    0    -1  
$EndComp
Connection ~ 8750 4600
Wire Wire Line
	8750 4600 9300 4600
Text HLabel 4550 6050 0    50   Input ~ 0
DRIVER_P
Text HLabel 4550 6250 0    50   Input ~ 0
DRIVER_N
Text HLabel 6300 5600 2    50   Input ~ 0
PELTIER_P
Text HLabel 6300 5500 2    50   Input ~ 0
PELTIER_N
Text HLabel 4550 5850 0    50   Input ~ 0
VCC_UNREGULATED
Text GLabel 2200 3800 0    50   Input ~ 0
DRIVER_P
$Comp
L power:VCC #PWR0122
U 1 1 621DA48C
P 6100 2250
F 0 "#PWR0122" H 6100 2100 50  0001 C CNN
F 1 "VCC" H 6115 2423 50  0000 C CNN
F 2 "" H 6100 2250 50  0001 C CNN
F 3 "" H 6100 2250 50  0001 C CNN
	1    6100 2250
	1    0    0    -1  
$EndComp
Wire Wire Line
	3150 2250 5000 2250
Wire Wire Line
	3150 2250 3150 2850
Connection ~ 6100 2250
Wire Wire Line
	6100 2250 6800 2250
Wire Wire Line
	8650 2250 8650 2850
Wire Wire Line
	5000 2250 5000 3250
Connection ~ 5000 2250
Wire Wire Line
	5000 2250 6100 2250
Wire Wire Line
	6800 2250 6800 3250
Connection ~ 6800 2250
Wire Wire Line
	6800 2250 8650 2250
Wire Wire Line
	3450 3450 3700 3450
Connection ~ 3700 3450
Wire Wire Line
	3700 3450 3700 3600
Wire Wire Line
	3700 3950 5000 3950
Connection ~ 3700 3950
Connection ~ 5000 3950
Wire Wire Line
	5000 3950 5700 3950
Wire Wire Line
	5700 3950 5700 5600
Wire Wire Line
	5700 5600 6300 5600
Wire Wire Line
	8100 3900 8100 3950
Wire Wire Line
	8350 3450 8100 3450
Connection ~ 8100 3450
Wire Wire Line
	8100 3450 8100 3600
Wire Wire Line
	8100 3950 6800 3950
Connection ~ 8100 3950
Connection ~ 6800 3950
Wire Wire Line
	6800 3950 5800 3950
Wire Wire Line
	5800 3950 5800 5500
Wire Wire Line
	5800 5500 6300 5500
Text GLabel 9600 3800 2    50   Input ~ 0
DRIVER_N
Text GLabel 4800 6250 2    50   Input ~ 0
DRIVER_N
Text GLabel 4800 6050 2    50   Input ~ 0
DRIVER_P
Wire Wire Line
	4550 6050 4800 6050
Wire Wire Line
	4550 6250 4800 6250
$Comp
L power:VCC #PWR0123
U 1 1 62207693
P 4850 5750
F 0 "#PWR0123" H 4850 5600 50  0001 C CNN
F 1 "VCC" H 4865 5923 50  0000 C CNN
F 2 "" H 4850 5750 50  0001 C CNN
F 3 "" H 4850 5750 50  0001 C CNN
	1    4850 5750
	1    0    0    -1  
$EndComp
Wire Wire Line
	4550 5850 4850 5850
Wire Wire Line
	4850 5850 4850 5750
$Comp
L power:GND #PWR?
U 1 1 622134A9
P 4750 6550
AR Path="/622134A9" Ref="#PWR?"  Part="1" 
AR Path="/6200D680/622134A9" Ref="#PWR0124"  Part="1" 
F 0 "#PWR0124" H 4750 6300 50  0001 C CNN
F 1 "GND" H 4755 6377 50  0000 C CNN
F 2 "" H 4750 6550 50  0001 C CNN
F 3 "" H 4750 6550 50  0001 C CNN
	1    4750 6550
	1    0    0    -1  
$EndComp
Text HLabel 4550 6450 0    50   Input ~ 0
GND
Wire Wire Line
	4550 6450 4750 6450
Wire Wire Line
	4750 6450 4750 6550
$EndSCHEMATC