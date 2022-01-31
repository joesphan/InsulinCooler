EESchema Schematic File Version 4
EELAYER 30 0
EELAYER END
$Descr A4 11693 8268
encoding utf-8
Sheet 3 6
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
L 1KicadLib:USB_C_PWR_ONLY J?
U 1 1 621203F0
P 4050 2050
AR Path="/621203F0" Ref="J?"  Part="1" 
AR Path="/61F95051/621203F0" Ref="J2"  Part="1" 
F 0 "J2" H 4157 2917 50  0000 C CNN
F 1 "USB_C_Receptacle_USB2.0" H 4157 2826 50  0000 C CNN
F 2 "1KicadLib:USB4125-GF-A" H 4200 2050 50  0001 C CNN
F 3 "https://www.usb.org/sites/default/files/documents/usb_type-c.zip" H 4200 2050 50  0001 C CNN
	1    4050 2050
	1    0    0    -1  
$EndComp
$Comp
L Device:R R?
U 1 1 621203F6
P 5600 1950
AR Path="/621203F6" Ref="R?"  Part="1" 
AR Path="/61F95051/621203F6" Ref="R8"  Part="1" 
F 0 "R8" H 5670 1996 50  0000 L CNN
F 1 "5.1k" H 5670 1905 50  0000 L CNN
F 2 "Capacitor_SMD:C_0805_2012Metric_Pad1.18x1.45mm_HandSolder" V 5530 1950 50  0001 C CNN
F 3 "~" H 5600 1950 50  0001 C CNN
	1    5600 1950
	1    0    0    -1  
$EndComp
$Comp
L Device:R R?
U 1 1 621203FC
P 5900 1850
AR Path="/621203FC" Ref="R?"  Part="1" 
AR Path="/61F95051/621203FC" Ref="R9"  Part="1" 
F 0 "R9" H 5970 1896 50  0000 L CNN
F 1 "5.1k" H 5970 1805 50  0000 L CNN
F 2 "Capacitor_SMD:C_0805_2012Metric_Pad1.18x1.45mm_HandSolder" V 5830 1850 50  0001 C CNN
F 3 "~" H 5900 1850 50  0001 C CNN
	1    5900 1850
	1    0    0    -1  
$EndComp
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
$Comp
L Connector:Conn_01x02_Male J?
U 1 1 6214127D
P 3700 4000
AR Path="/6214127D" Ref="J?"  Part="1" 
AR Path="/61F95051/6214127D" Ref="J1"  Part="1" 
F 0 "J1" H 3808 4181 50  0000 C CNN
F 1 "Battery Connector" H 3808 4090 50  0000 C CNN
F 2 "Connector_PinHeader_2.54mm:PinHeader_1x02_P2.54mm_Vertical" H 3700 4000 50  0001 C CNN
F 3 "~" H 3700 4000 50  0001 C CNN
	1    3700 4000
	1    0    0    -1  
$EndComp
Wire Wire Line
	4000 3250 4300 3250
Wire Wire Line
	3900 4000 4300 4000
Wire Wire Line
	4300 4000 4300 3250
Connection ~ 4300 3250
Wire Wire Line
	4300 3250 6500 3250
Wire Wire Line
	3900 4100 4650 4100
Wire Wire Line
	4650 4100 4650 3450
Text HLabel 6650 3450 2    50   Input ~ 0
VBAT
Wire Wire Line
	4650 3450 6650 3450
$Comp
L Switch:SW_DIP_x01 SW?
U 1 1 6216F998
P 4000 4800
AR Path="/6216F998" Ref="SW?"  Part="1" 
AR Path="/61F95051/6216F998" Ref="SW1"  Part="1" 
F 0 "SW1" H 4000 5067 50  0000 C CNN
F 1 "SW_DIP_x01" H 4000 4976 50  0000 C CNN
F 2 "Connector_PinHeader_2.54mm:PinHeader_1x02_P2.54mm_Vertical" H 4000 4800 50  0001 C CNN
F 3 "~" H 4000 4800 50  0001 C CNN
	1    4000 4800
	0    -1   -1   0   
$EndComp
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
$Comp
L Connector:Conn_01x02_Female J?
U 1 1 6217A931
P 4000 5900
AR Path="/6217A931" Ref="J?"  Part="1" 
AR Path="/61F95051/6217A931" Ref="J3"  Part="1" 
F 0 "J3" H 4028 5876 50  0000 L CNN
F 1 "Peltier Connection" H 4028 5785 50  0000 L CNN
F 2 "Connector_PinHeader_2.54mm:PinHeader_1x02_P2.54mm_Vertical" H 4000 5900 50  0001 C CNN
F 3 "~" H 4000 5900 50  0001 C CNN
	1    4000 5900
	-1   0    0    1   
$EndComp
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
$Comp
L Connector:Conn_01x03_Male J?
U 1 1 622E4833
P 6150 3000
AR Path="/622E4833" Ref="J?"  Part="1" 
AR Path="/61F95051/622E4833" Ref="J4"  Part="1" 
F 0 "J4" H 6178 2976 50  0000 L CNN
F 1 "Serial" H 6178 2885 50  0000 L CNN
F 2 "Connector_PinHeader_2.54mm:PinHeader_1x03_P2.54mm_Vertical" H 6150 3000 50  0001 C CNN
F 3 "~" H 6150 3000 50  0001 C CNN
	1    6150 3000
	1    0    0    -1  
$EndComp
Wire Wire Line
	6350 3100 6500 3100
Wire Wire Line
	6500 3100 6500 3250
Connection ~ 6500 3250
Wire Wire Line
	6500 3250 6650 3250
$EndSCHEMATC
